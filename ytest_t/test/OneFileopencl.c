#include <stdio.h>
#include <stdlib.h>

#ifdef __APPLE__
#include <OpenCL/cl.h>
#else
#include <CL/cl.h>
#endif

#include "ftest/ftest.h"


#define VECTOR_SIZE 1024

const char *saxpy_kernel = 
"__kernel                                 \n"
"void saxpy_kernel(float alpha,           \n"
"                  __global float *A,     \n"
"                  __global float *B,     \n"
"                  __global float *C)     \n"
"{                                        \n"
" // Get the index of the work-item       \n"
" int index = get_global_id(0);           \n"
" C[index] = alpha * A[index] + B[index]; \n"
"}                                        \n";

TEST(openCL_one){
  int i;
  // Alocate space for vectors A, B, C
  float alpha = 3.0;
  float *A = (float*)malloc(sizeof(float)*VECTOR_SIZE);
  float *B = (float*)malloc(sizeof(float)*VECTOR_SIZE);
  float *C = (float*)malloc(sizeof(float)*VECTOR_SIZE);

  for(i = 0; i<VECTOR_SIZE; ++i){
    A[i]=i;
    B[i]=VECTOR_SIZE - i;
    C[i]=0;
  }

  // Get platform and device information
  cl_platform_id * platforms = NULL;
  cl_uint num_platforms;
  // Set up the Platform
  cl_int clStatus = clGetPlatformIDs(0,NULL,&num_platforms);
  platforms = (cl_platform_id*)malloc(sizeof(cl_platform_id)*num_platforms);
  clStatus = clGetPlatformIDs(num_platforms,platforms,NULL);

  for(i=0; i< num_platforms; ++i){
    printf("--- %d/%d : %d\n",i,num_platforms,platforms[i]);
  }
  // Get the devices list and chose the device you want to run on
  cl_device_id *device_list=NULL;
  cl_uint num_devices;

  clStatus = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_GPU, 0, NULL, &num_devices);
  device_list = (cl_device_id*)malloc(sizeof(cl_device_id)*num_devices);
  clStatus = clGetDeviceIDs(platforms[0], CL_DEVICE_TYPE_GPU, num_devices,device_list,NULL);

  // Create one OpenCL context for each device in the platform
  cl_context context;
  context = clCreateContext(NULL, num_devices, device_list, NULL, NULL, &clStatus);

  for(i=0; i< num_devices; ++i){
    printf("--- %d/%d : %d\n",i,num_devices,device_list[i]);
  }
  // Create a command queue
  cl_command_queue command_queue = clCreateCommandQueue(context, device_list[0], 0, &clStatus);

  // Create memory buffers on the device for each vector
  cl_mem A_clmem = clCreateBuffer(context,CL_MEM_READ_ONLY, VECTOR_SIZE*sizeof(float),NULL,&clStatus);
  cl_mem B_clmem = clCreateBuffer(context,CL_MEM_READ_ONLY, VECTOR_SIZE*sizeof(float),NULL,&clStatus);
  cl_mem C_clmem = clCreateBuffer(context,CL_MEM_WRITE_ONLY, VECTOR_SIZE*sizeof(float),NULL,&clStatus);

  // COpy the buffer A, B to the device
  clStatus = clEnqueueWriteBuffer(command_queue, A_clmem, CL_TRUE, 0, VECTOR_SIZE*sizeof(float),A,0,NULL,NULL);
  clStatus = clEnqueueWriteBuffer(command_queue, B_clmem, CL_TRUE, 0, VECTOR_SIZE*sizeof(float),B,0,NULL,NULL);
  
  // Create a program from the kernel source
  cl_program program = clCreateProgramWithSource(context,1,(const char **)&saxpy_kernel,NULL,&clStatus);

  // Buil the program
  clStatus = clBuildProgram(program, 1, device_list, NULL, NULL, NULL);


  // Create the OpenCL kernel
  cl_kernel kernel = clCreateKernel(program, "saxpy_kernel",&clStatus);

  // Set the arguments of the kernel
  clStatus = clSetKernelArg(kernel, 0, sizeof(float), (void*)&alpha);
  clStatus = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&A_clmem);
  clStatus = clSetKernelArg(kernel, 2, sizeof(cl_mem), (void*)&B_clmem);
  clStatus = clSetKernelArg(kernel, 3, sizeof(cl_mem), (void*)&C_clmem);

  // Execute the OpenCL kernel on the list
  size_t global_size = VECTOR_SIZE; // Process the entire lists
  size_t local_size = 64;           // Process one item at a time
  clStatus = clEnqueueNDRangeKernel(command_queue, kernel, 1, NULL, &global_size, &local_size, 0, NULL, NULL);

  // Read the cl memory C_clmem on device to the host variable C
  clStatus = clEnqueueReadBuffer(command_queue, C_clmem, CL_TRUE, 0, VECTOR_SIZE*sizeof(float),C,0,NULL,NULL);

  // Clean up and wait for all the commands to complete
  clStatus = clFlush(command_queue);
  clStatus = clFinish(command_queue);

  // Display the result to the screen
  for (i=0; i<VECTOR_SIZE; ++i){
//    EXPECT_EQ_TYPE_FLOAT(alpha*A[i]+B[i],C[i]);
//    printf("%d: %f * %f + %f = %f \n",i,alpha, A[i],B[i],C[i]);
  }
  // Finally release all OpenCL allocated objects and host buffers.
  clStatus = clReleaseKernel(kernel);
  clStatus = clReleaseProgram(program);

  clStatus = clReleaseMemObject(A_clmem);
  clStatus = clReleaseMemObject(B_clmem);
  clStatus = clReleaseMemObject(C_clmem);

  clStatus = clReleaseCommandQueue(command_queue);
  clStatus = clReleaseContext(context);

  free(A);
  free(B);
  free(C);
  free(platforms);
  free(device_list);


}
int main(int argc, char **argv){


  run_all_tests_args(argc, argv);

  return 0;
}

