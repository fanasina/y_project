#include "tensor_t/cl_tensor_t.h"


#define MAX_SOURCE_SIZE (0x100000)



#define SETUP_cl_KERNEL_(type,file_cl_src,func_cl_name)\
  /* Load the kernel source code into the array source_str*/ \
    FILE *fp; \
    char *source_str; \
    size_t source_size; \
 \
    /*fp = fopen("../src/kernel_ProdTensor.cl", "r");*/ \
    fp = fopen(file_cl_src, "r"); \
    if (!fp) { \
        perror(file_cl_src);\
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
    size_t returned_size = 0;\
	  size_t max_workgroup_size = 0;\
	  ret = clGetDeviceInfo(device_id, CL_DEVICE_MAX_WORK_GROUP_SIZE, sizeof(size_t), &max_workgroup_size, &returned_size);\
    checkError(ret,__func__,"Error: Failed to retrieve device info!");\
    printf(" ===========================================================++> return size: %ld\n max group sz: %ld\n", returned_size, max_workgroup_size);\
\
/*int gpu = 1;\
    ret = clGetDeviceIDs( platform_id, gpu ? CL_DEVICE_TYPE_GPU : CL_DEVICE_TYPE_CPU, 1, \
            &device_id, &ret_num_devices); */\
 \
    /*/ Create an OpenCL context */ \
    cl_context context = clCreateContext( NULL, 1, &device_id, NULL, NULL, &ret); \
 \
    /*/ Create a command queue */ \
    /*cl_command_queue command_queue = clCreateCommandQueue(context, device_id, 0, &ret);*/ \
    cl_command_queue command_queue = clCreateCommandQueueWithProperties(context, device_id, NULL, &ret); /* NULL =default properties = in order */ \
 \
    checkError(ret,__func__,"Error: Failed to create command queue with properties ");\
 \
    /*/ Create memory buffers on the device for each vector */ \
    cl_mem M0_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, \
            M0->dim->rank * sizeof(type), NULL, &ret); \
    cl_mem M1_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY, \
            M1->dim->rank * sizeof(type), NULL, &ret); \
    cl_mem M_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, \
            M->dim->rank * sizeof(type), NULL, &ret); \
  if (!M0_mem_obj || !M1_mem_obj || !M_mem_obj)   {\
       printf("Error: Failed to creat buffer! %d\n", ret);\
       exit(1);\
   }\
 \
    /*/ Copy the lists A and B to their respective memory buffers */ \
    ret = clEnqueueWriteBuffer(command_queue, M0_mem_obj, CL_TRUE, 0, \
            M0->dim->rank * sizeof(type), M0->x, 0, NULL, NULL); \
    ret |= clEnqueueWriteBuffer(command_queue, M1_mem_obj, CL_TRUE, 0, \
            M1->dim->rank * sizeof(type), M1->x, 0, NULL, NULL); \
 \
    checkError(ret,__func__,"Error: Failed to read buffers! ");\
    /*/ Create a program from the kernel source */ \
    cl_program program = clCreateProgramWithSource(context, 1, \
            (const char **)&source_str, (const size_t *)&source_size, &ret); \
 \
    if (!program) {\
       printf("Error: Failed to create compute program!\n");\
       return ;\
    }\
    /*/ Build the program */ \
    ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL); \
    if(ret != CL_SUCCESS){\
      size_t len; \
      clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, 0, NULL, &len);\
      char *log = malloc(sizeof(char)*len);\
      clGetProgramBuildInfo(program, device_id, CL_PROGRAM_BUILD_LOG, len, log, NULL);\
      printf("Error: Failed to build program executable!\n  %s \n",log);\
    }\
    /*/ Create the OpenCL kernel */ \
    /*char func_cl_name[250]; sprintf(func_cl_name,"prodTensorLin_%s", #type);*/ \
    printf("cl_func_type = %s\n",func_cl_name);  \
    cl_kernel kernel = clCreateKernel(program, func_cl_name, &ret); \
 

    /*/ Set the arguments of the kernel  */ \
    /*ret = clSetKernelArg(kernel, 0, sizeof(size_t), (void *)&(M1->dim->rank)); \
    ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&M0_mem_obj); \
    ret = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&M1_mem_obj); \
    ret = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&M_mem_obj); \
 */

#define EXEC_cl_KERNEL(type)\
    /*/ Execute the OpenCL kernel on the list */ \
    size_t global_item_size = M->dim->rank; /*/ Process the entire lists */ \
    size_t local_item_size = 1;  /*64;*/ /*/ Divide work items into groups of 64 */ \
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, \
            &global_item_size, &local_item_size, 0, NULL, NULL); \
 \
    checkError(ret,__func__,"Error: Failed to execute! ");\

#define EXEC_cl_2d_KERNEL(type, global_W_sz0, global_W_sz1, local_W_sz0, local_W_sz1)\
    /*/ Execute the OpenCL kernel on the list */ \
    size_t global_item_size[2]={global_W_sz0, global_W_sz1};/*/ Process the entire lists */ \
    size_t local_item_size[2]={local_W_sz0, local_W_sz1};   /* Divide work items into groups of 64 */ \
    ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, \
            global_item_size, local_item_size, 0, NULL, NULL); \
 \
    checkError(ret,__func__,"Error: Failed to execute! ");\




#define READ_BUF_N_CLEANUP(type)    \
      /*/ Read the memory buffer Mx on the device to the local variable M->x */ \
    ret = clEnqueueReadBuffer(command_queue, M_mem_obj, CL_TRUE, 0, \
            M->dim->rank * sizeof(type), M->x, 0, NULL, NULL); \
 \
    checkError(ret,__func__,"Error: Failed to read buffer! ");\
    /*/ Clean up */ \
    ret = clFlush(command_queue); \
    ret |= clFinish(command_queue); \
    ret |= clReleaseKernel(kernel); \
    ret |= clReleaseProgram(program); \
    ret |= clReleaseMemObject(M0_mem_obj); \
    ret |= clReleaseMemObject(M1_mem_obj); \
    ret |= clReleaseMemObject(M_mem_obj); \
    ret |= clReleaseCommandQueue(command_queue); \
    ret |= clReleaseContext(context); \
    checkError(ret,__func__,"Error: Failed to clean up! ");\

#define GEN_cl_FUNC_TENSOR(type)\
\
\
void cl_tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    (*MM)=CREATE_TENSOR_##type(dd);  \
    tensor_##type *M = *MM; \
    char *file_cl_src = "../src/kernel_ProdTensor.cl"; \
    char *func_cl_nameEndian = "prodTensorLin_" #type; \
    char *func_cl_nameNotEndian = "prodTensorLinNotEndian_" #type; \
    char *func_cl_name; \
    size_t MeDimRank;\
  if(endian){\
    func_cl_name = func_cl_nameEndian;\
    MeDimRank = M1->dim->rank;\
    \
  }else{\
    func_cl_name = func_cl_nameNotEndian;\
    MeDimRank = M0->dim->rank;\
    \
  }\
  SETUP_cl_KERNEL_(type,file_cl_src,func_cl_name);\
    /*/ Set the arguments of the kernel  */ \
    ret = clSetKernelArg(kernel, 0, sizeof(size_t), (void *)&MeDimRank); \
    ret |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&M0_mem_obj); \
    ret |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&M1_mem_obj); \
    ret |= clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&M_mem_obj); \
    checkError(ret,__func__,"Error: Failed to set kernel arguments! ");\
  EXEC_cl_KERNEL(type);\
  READ_BUF_N_CLEANUP(type)\
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
    char *file_cl_src = "../src/kernel_ProdContractnTensor.cl"; \
    /*char *func_cl_name = "prodContractnTensorLin_" #type;*/ \
    char *func_cl_nameEndian = "prodContractnTensorLin_" #type; \
    char *func_cl_nameNotEndian = "prodContractnTensorLinNotEndian_" #type; \
    char *func_cl_name; \
    size_t dSubRank;\
  if(endian){\
    func_cl_name = func_cl_nameEndian;\
    dSubRank = dSub1->rank;\
    \
  }else{\
    func_cl_name = func_cl_nameNotEndian;\
    dSubRank = dSub0->rank;\
    \
  }\
  SETUP_cl_KERNEL_(type,file_cl_src,func_cl_name);\
  \
    /*/ Set the arguments of the kernel  */ \
    ret = clSetKernelArg(kernel, 0, sizeof(size_t), (void *)&dSubRank); \
    ret |= clSetKernelArg(kernel, 1, sizeof(size_t), (void *)&(dM->rank)); \
    ret |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&M0_mem_obj); \
    ret |= clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&M1_mem_obj); \
    ret |= clSetKernelArg(kernel, 4, sizeof(cl_mem), (void *)&M_mem_obj); \
    checkError(ret,__func__,"Error: Failed to set kernel arguments! ");\
 \
  EXEC_cl_KERNEL(type);\
  READ_BUF_N_CLEANUP(type)\
\
} \
\
\
void cl2d_tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t div0Wsz, size_t div1Wsz) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    (*MM)=CREATE_TENSOR_##type(dd);  \
    tensor_##type *M = *MM; \
    char *file_cl_src = "../src/kernel_2d_ProdTensor.cl"; \
    /*char *func_cl_name = "prodTensor2dLin_" #type;*/ \
    char *func_cl_nameEndian = "prodTensor2dLin_" #type; \
    char *func_cl_nameNotEndian = "prodTensor2dLinNotEndian_" #type; \
    char *func_cl_name; \
    size_t MeDimRank;\
  if(endian){\
    func_cl_name = func_cl_nameEndian;\
    MeDimRank = M1->dim->rank;\
    \
  }else{\
    func_cl_name = func_cl_nameNotEndian;\
    MeDimRank = M0->dim->rank;\
    \
  }\
  SETUP_cl_KERNEL_(type,file_cl_src,func_cl_name);\
    /*/ Set the arguments of the kernel  */ \
    ret = clSetKernelArg(kernel, 0, sizeof(size_t), (void *)&(MeDimRank)); \
    ret |= clSetKernelArg(kernel, 1, sizeof(cl_mem), (void *)&M0_mem_obj); \
    ret |= clSetKernelArg(kernel, 2, sizeof(cl_mem), (void *)&M1_mem_obj); \
    ret |= clSetKernelArg(kernel, 3, sizeof(cl_mem), (void *)&M_mem_obj); \
    checkError(ret,__func__,"Error: Failed to set kernel arguments! ");\
  EXEC_cl_2d_KERNEL(type,M0->dim->rank,M1->dim->rank,div0Wsz,div1Wsz);\
  \
  READ_BUF_N_CLEANUP(type)\
}  \
\

void checkError(cl_int error, const char *func_name, char *msg) {
    if (error != CL_SUCCESS) {
      printf("%s\n",msg);
        switch (error) {
            case CL_DEVICE_NOT_FOUND:                 printf(" Error in %s:  Device not found.\n",func_name); break;
            case CL_DEVICE_NOT_AVAILABLE:             printf(" Error in %s:  Device not available\n",func_name); break;
            case CL_COMPILER_NOT_AVAILABLE:           printf(" Error in %s:  Compiler not available\n",func_name); break;
            case CL_MEM_OBJECT_ALLOCATION_FAILURE:    printf(" Error in %s:  Memory object allocation failure\n",func_name); break;
            case CL_OUT_OF_RESOURCES:                 printf(" Error in %s:  Out of resources\n",func_name); break;
            case CL_OUT_OF_HOST_MEMORY:               printf(" Error in %s:  Out of host memory\n",func_name); break;
            case CL_PROFILING_INFO_NOT_AVAILABLE:     printf(" Error in %s:  Profiling information not available\n",func_name); break;
            case CL_MEM_COPY_OVERLAP:                 printf(" Error in %s:  Memory copy overlap\n",func_name); break;
            case CL_IMAGE_FORMAT_MISMATCH:            printf(" Error in %s:  Image format mismatch\n",func_name); break;
            case CL_IMAGE_FORMAT_NOT_SUPPORTED:       printf(" Error in %s:  Image format not supported\n",func_name); break;
            case CL_BUILD_PROGRAM_FAILURE:            printf(" Error in %s:  Program build failure\n",func_name); break;
            case CL_MAP_FAILURE:                      printf(" Error in %s:  Map failure\n",func_name); break;
            case CL_INVALID_VALUE:                    printf(" Error in %s:  Invalid value\n",func_name); break;
            case CL_INVALID_DEVICE_TYPE:              printf(" Error in %s:  Invalid device type\n",func_name); break;
            case CL_INVALID_PLATFORM:                 printf(" Error in %s:  Invalid platform\n",func_name); break;
            case CL_INVALID_DEVICE:                   printf(" Error in %s:  Invalid device\n",func_name); break;
            case CL_INVALID_CONTEXT:                  printf(" Error in %s:  Invalid context\n",func_name); break;
            case CL_INVALID_QUEUE_PROPERTIES:         printf(" Error in %s:  Invalid queue properties\n",func_name); break;
            case CL_INVALID_COMMAND_QUEUE:            printf(" Error in %s:  Invalid command queue\n",func_name); break;
            case CL_INVALID_HOST_PTR:                 printf(" Error in %s:  Invalid host pointer\n",func_name); break;
            case CL_INVALID_MEM_OBJECT:               printf(" Error in %s:  Invalid memory object\n",func_name); break;
            case CL_INVALID_IMAGE_FORMAT_DESCRIPTOR:  printf(" Error in %s:  Invalid image format descriptor\n",func_name); break;
            case CL_INVALID_IMAGE_SIZE:               printf(" Error in %s:  Invalid image size\n",func_name); break;
            case CL_INVALID_SAMPLER:                  printf(" Error in %s:  Invalid sampler\n",func_name); break;
            case CL_INVALID_BINARY:                   printf(" Error in %s:  Invalid binary\n",func_name); break;
            case CL_INVALID_BUILD_OPTIONS:            printf(" Error in %s:  Invalid build options\n",func_name); break;
            case CL_INVALID_PROGRAM:                  printf(" Error in %s:  Invalid program\n",func_name); break;
            case CL_INVALID_PROGRAM_EXECUTABLE:       printf(" Error in %s:  Invalid program executable\n",func_name); break;
            case CL_INVALID_KERNEL_NAME:              printf(" Error in %s:  Invalid kernel name\n",func_name); break;
            case CL_INVALID_KERNEL_DEFINITION:        printf(" Error in %s:  Invalid kernel definition\n",func_name); break;
            case CL_INVALID_KERNEL:                   printf(" Error in %s:  Invalid kernel\n",func_name); break;
            case CL_INVALID_ARG_INDEX:                printf(" Error in %s:  Invalid argument index\n",func_name); break;
            case CL_INVALID_ARG_VALUE:                printf(" Error in %s:  Invalid argument value\n",func_name); break;
            case CL_INVALID_ARG_SIZE:                 printf(" Error in %s:  Invalid argument size\n",func_name); break;
            case CL_INVALID_KERNEL_ARGS:              printf(" Error in %s:  Invalid kernel arguments\n",func_name); break;
            case CL_INVALID_WORK_DIMENSION:           printf(" Error in %s:  Invalid work dimensionsension\n",func_name); break;
            case CL_INVALID_WORK_GROUP_SIZE:          printf(" Error in %s:  Invalid work group size\n",func_name); break;
            case CL_INVALID_WORK_ITEM_SIZE:           printf(" Error in %s:  Invalid work item size\n",func_name); break;
            case CL_INVALID_GLOBAL_OFFSET:            printf(" Error in %s:  Invalid global offset\n",func_name); break;
            case CL_INVALID_EVENT_WAIT_LIST:          printf(" Error in %s:  Invalid event wait list\n",func_name); break;
            case CL_INVALID_EVENT:                    printf(" Error in %s:  Invalid event\n",func_name); break;
            case CL_INVALID_OPERATION:                printf(" Error in %s:  Invalid operation\n",func_name); break;
            case CL_INVALID_GL_OBJECT:                printf(" Error in %s:  Invalid OpenGL object\n",func_name); break;
            case CL_INVALID_BUFFER_SIZE:              printf(" Error in %s:  Invalid buffer size\n",func_name); break;
            case CL_INVALID_MIP_LEVEL:                printf(" Error in %s:  Invalid mip-map level\n",func_name); break;
           default:                                  printf(" Error in %s:  Unknown with code %d\n",func_name, error);
        }
        exit(1);
    }
}

GEN_cl_FUNC_TENSOR(TYPE_FLOAT);
GEN_cl_FUNC_TENSOR(TYPE_DOUBLE);


