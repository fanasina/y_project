#include "tensor_t/cl_tensor_t.h"


#define MAX_SOURCE_SIZE (0x100000)


#define CL_GEN_FUNC_TENSOR(type)\
  tensor_##type* CREATE_CL_TENSOR_##type(dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    updateRankDim(dim);\
    r_tens->dim = dim;\
    r_tens->x = malloc(sizeof(type)*dim->rank);\
    return r_tens;\
  }\
\
\
void cl_tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    (*MM)=CREATE_TENSOR_##type(dd);  \
    tensor_##type *M = *MM; \
    size_t m_idx;\
    for(size_t i=0; i<M0->dim->rank; ++i){\
      for(size_t j=0; j<M1->dim->rank; ++j){\
          m_idx= i*M1->dim->rank + j ;\
          M->x[m_idx]=M0->x[i]*M1->x[j];\
          /*printf("[%ld|%ld:(%ld,%ld)]",x_idx++,m_idx,i,j);*/\
      }\
    }\
}  \
\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
void cl_tensorContractnProd_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber) {\
\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
    dimension *dM;\
    min_dimension(&dM, dM0, dM1);\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
    updateRankDim(dd);\
    *MM = CREATE_TENSOR_##type(dd);\
    tensor_##type *M= *MM;\
\
 \
/* Load the kernel source code into the array source_str*/ \
    FILE *fp; \
    char *source_str; \
    size_t source_size; \
 \
    fp = fopen("/media/fanasina/corsair480/progr_/ytest/y_PROJECT/tensor_t/src/tensor_t/kernel_ProdContractnTensor.cl", "r"); \
    if (!fp) { \
        perror("kernel_ProdContractnTensor.cl");\
        fprintf(stderr, "Failed to load kernel. \n"); \
        exit(1); \
    } \
    source_str = (char*)malloc(MAX_SOURCE_SIZE); \
    source_size = fread( source_str, 1, MAX_SOURCE_SIZE, fp); \
    fclose( fp ); \
 \
    /*/ Get platform and device information */ \
    cl_platform_id platform_id = NULL; \
    cl_device_id device_id = NULL; \
    cl_uint ret_num_devices; \
    cl_uint ret_num_platforms; \
    cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms); \
    ret = clGetDeviceIDs( platform_id, CL_DEVICE_TYPE_DEFAULT, 1, \
            &device_id, &ret_num_devices); \
 \
    /*/ Create an OpenCL context */ \
    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret); \
 \
    /*/ Create a command queue */ \
    cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret); \
 \
 \
    /*/ Create memory buffers on the device for each vector */ \
    cl_mem M0_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, \
            M0->dim->rank * sizeof(type), NULL, &ret); \
    cl_mem M1_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, \
            M1->dim->rank * sizeof(type), NULL, &ret); \
    cl_mem M_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, \
            M->dim->rank * sizeof(type), NULL, &ret); \
 \
    /*/ Copy the lists A and B to their respective memory buffers */ \
    ret = clEnqueueWriteBuffer(command_queue, M0_mem_obj, CL_TRUE, 0, \
            M0->dim->rank * sizeof(type), M0->x, 0, NULL, NULL); \
    ret = clEnqueueWriteBuffer(command_queue, M1_mem_obj, CL_TRUE, 0, \
            M1->dim->rank * sizeof(type), M1->x, 0, NULL, NULL); \
 \
    /*/ Create a program from the kernel source */ \
    cl_program program = clCreateProgramWithSource(context, 1, \
            (const char **)&source_str, (const size_t *)&source_size, &ret); \
 \
    printf("log 0\n");\
    /*/ Build the program */ \
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL); \
    size_t len; clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, NULL, NULL, &len);\
    char *log = malloc(sizeof(char)*len);\
  clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, len, log, NULL);\
  printf("log: %s \n",log);\
 \
    /*/ Create the OpenCL kernel */ \
    char func_cl_name[250]; sprintf(func_cl_name,"prodContractnTensorLin_%s", #type); \
    printf("cl_func_type = %s\n",func_cl_name);  \
    cl_kernel kernel = clCreateKernel(program, func_cl_name, &ret); \
 \
    /*/ Set the arguments of the kernel  */ \
    ret = clSetKernelArg(kernel, 0, sizeof(size_t), (void *)&(dSub1->rank)); \
    ret = clSetKernelArg(kernel, 1, sizeof(size_t), (void *)&(dM->rank)); \
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&M0_mem_obj); \
    ret = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&M1_mem_obj); \
    ret = clSetKernelArg(kernel, 4, sizeof(cl_mem), (void *)&M_mem_obj); \
 \
    /*/ Execute the OpenCL kernel on the list */ \
    size_t global_item_size = M->dim->rank; /*/ Process the entire lists */ \
    size_t local_item_size = 1;  /*64;*/ /*/ Divide work items into groups of 64 */ \
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, \
            &global_item_size, &local_item_size, 0, NULL, NULL); \
 \
    /*/ Read the memory buffer Mx on the device to the local variable M->x */ \
    ret = clEnqueueReadBuffer(command_queue, M_mem_obj, CL_TRUE, 0, \
            M->dim->rank * sizeof(type), M->x, 0, NULL, NULL); \
 \
    /*/ Clean up */ \
    ret = clFlush(command_queue); \
    ret = clFinish(command_queue); \
    ret = clReleaseKernel(kernel); \
    ret = clReleaseProgram(program); \
    ret = clReleaseMemObject(M0_mem_obj); \
    ret = clReleaseMemObject(M1_mem_obj); \
    ret = clReleaseMemObject(M_mem_obj); \
    ret = clReleaseCommandQueue(command_queue); \
    ret = clReleaseContext(context); \
} \


CL_GEN_FUNC_TENSOR(TYPE_FLOAT);
CL_GEN_FUNC_TENSOR(TYPE_DOUBLE);
