#ifndef __CL_TENSOR_T__H__
#define __CL_TENSOR_T__H__

#include <stdio.h>
#include <stdlib.h>

#define CL_TARGET_OPENCL_VERSION 300

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include "tensor_t/tensor_t.h"


#define CL_GENERATE_TENSOR_TYPE(type) \
void cl_tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1); \
void cl_tensorContractnProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber); \
void cl2d_tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t div0Wsz, size_t div1Wsz); \
void cl2d_tensorContractnProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t div0Wsz, size_t div1Wsz); \

CL_GENERATE_TENSOR_TYPE(TYPE_FLOAT);
CL_GENERATE_TENSOR_TYPE(TYPE_DOUBLE);


#endif /* __CL_TENSOR_T__H__ */
