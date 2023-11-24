#ifndef __D_CUDA_TENSOR_H__
#define __D_CUDA_TENSOR_H__

#include "cuda.h"
#include "cuda_runtime.h"

//#include "cuda_device_runtime_api.h"

//#include "/home/fanasina/progr_/ptens0neD/tensor/tensCuda/d_tensCuda.h"
#include "tensor/tensCuda/d_tensCuda.h"


//#1D grid of 1D blocks
__device__ int d_getGlobalIdx_1D_1D();
//#1D grid of 2D blocks
__device__ int d_getGlobalIdx_1D_2D();
//#1D grid of 3D blocks
__device__ int d_getGlobalIdx_1D_3D();
//#1D grid of 1D blocks
__device__ int d_getGlobalIdx_2D_1D();
//#1D grid of 2D blocks
__device__ int d_getGlobalIdx_2D_2D();
//2D grid of 3D blocks
__device__ int d_getGlobalIdx_2D_3D();
//#1D grid of 1D blocks
__device__ int d_getGlobalIdx_3D_1D();
//#1D grid of 2D blocks
__device__ int d_getGlobalIdx_3D_2D();
//#1D grid of 3D blocks
__device__ int d_getGlobalIdx_3D_3D();



extern  cudaError_t cudaDeviceGetLimit(size_t* pValue, enum cudaLimit limit);


__device__ void d_LinearToCoordEnd(int* ret, size_t lin, int* dim, int rank, size_t size);

__device__ size_t d_CoordToLinearEnd(int* coo, int* dim, int rank);

__device__ size_t d_CoordToLinear(int* coo, int* dim, int rank);


__device__ void d_LinearToCoord(int* ret, size_t lin, int* dim, int rank, size_t size);

__device__ void d_subArray(int* dst, int* src, int debDst, int finDst, int debSrc);

__device__ void d_minReverse(int* dim, int& rank, const int* dim0, int rank0, const int* dim1, int rank1, bool& rev);

__device__ void d_reverseArray(int* arr, int sz);

__device__ int d_min(int a, int b);

__device__ void d_concatArray(int* dst, int* src0, int* src1, int debDst, int debSrc0, int finSrc0, int debSrc1, int finSrc1);


template<typename T>
__global__ void d_prodTensor(T* C, int* dimC, int rankC, size_t size, T* A, int* dimA, int rankA, size_t sizeA, T* B, int* dimB, int rankB);

template<typename T>
__global__ void d_prodTensorEnd(T* C, int* dimC, int rankC, size_t size, T* A, int* dimA, int rankA, size_t sizeA, T* B, int* dimB, int rankB);

template<typename T>
__global__ void d_TensorContractnReverseProd(T* C, int* dimC, int rankC, size_t size, T* A, int rankA, size_t sizeA, T* B, int rankB, size_t sizeB, int* dM, int dMrank, size_t dMsize);

template<typename T>
__global__ void d_PermLinearTransformCoord(T* C, int* dimC, int rankC, size_t sizeC, T* A, int* dimA, int rankA, size_t sizeA, int* invPerm);

#endif