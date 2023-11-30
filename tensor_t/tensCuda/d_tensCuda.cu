/*#include <cuda.h>
#include <cuda_runtime.h>

#include "cuda.h"
#include "cuda_runtime.h"
*/

#include "d_tensCuda.h"
//#include "index.h"
#include <stdio.h>

////////////////////////////////////////////////////////

//1D grid of 1D blocks
__device__
int d_getGlobalIdx_1D_1D() {
    return blockIdx.x * blockDim.x + threadIdx.x;
}
//1D grid of 2D blocks
__device__
int d_getGlobalIdx_1D_2D() {
    return blockIdx.x * blockDim.x * blockDim.y
        + threadIdx.y * blockDim.x + threadIdx.x;
}
//1D grid of 3D blocks
__device__
int d_getGlobalIdx_1D_3D() {
    return blockIdx.x * blockDim.x * blockDim.y * blockDim.z
        + threadIdx.z * blockDim.y * blockDim.x
        + threadIdx.y * blockDim.x + threadIdx.x;
}
//2D grid of 1D blocks
__device__ int d_getGlobalIdx_2D_1D() {
    int blockId
        = blockIdx.y * gridDim.x + blockIdx.x;
    int threadId = blockId * blockDim.x + threadIdx.x;
    return threadId;
}
//2D grid of 2D blocks
__device__
int d_getGlobalIdx_2D_2D() {
    int blockId = blockIdx.x + blockIdx.y * gridDim.x;
    int threadId = blockId * (blockDim.x * blockDim.y)
        + (threadIdx.y * blockDim.x) + threadIdx.x;
    return threadId;
}
//2D grid of 3D blocks
__device__
int d_getGlobalIdx_2D_3D() {
    int blockId = blockIdx.x + blockIdx.y * gridDim.x;
    int threadId = blockId * (blockDim.x * blockDim.y * blockDim.z)
        + (threadIdx.z * (blockDim.x * blockDim.y))
        + (threadIdx.y * blockDim.x) + threadIdx.x;
    return threadId;
}
//3D grid of 1D blocks
__device__
int d_getGlobalIdx_3D_1D() {
    int blockId = blockIdx.x + blockIdx.y * gridDim.x
        + gridDim.x * gridDim.y * blockIdx.z;
    int threadId = blockId * blockDim.x + threadIdx.x;
    return threadId;
}
//3D grid of 2D blocks
__device__
int d_getGlobalIdx_3D_2D() {
    int blockId = blockIdx.x + blockIdx.y * gridDim.x
        + gridDim.x * gridDim.y * blockIdx.z;
    int threadId = blockId * (blockDim.x * blockDim.y)
        + (threadIdx.y * blockDim.x) + threadIdx.x;
    return threadId;
}
//3D grid of 3D blocks
__device__
int d_getGlobalIdx_3D_3D() {
    int blockId = blockIdx.x + blockIdx.y * gridDim.x
        + gridDim.x * gridDim.y * blockIdx.z;
    int threadId = blockId * (blockDim.x * blockDim.y * blockDim.z)
        + (threadIdx.z * (blockDim.x * blockDim.y))
        + (threadIdx.y * blockDim.x) + threadIdx.x;
    return threadId;
}


///////////////////////////////////////////////////////////////////////////


__device__ void d_LinearToCoordEnd(int* ret, size_t lin, int* dim, int rank, size_t size) {
    size_t sm = lin;
    size_t pp = size;
    for (int i = rank - 1;i > 0; --i) {
        pp /= dim[i];
        ret[i] = sm / pp;
        sm %= pp;
    }
    ret[0] = sm;
}

__device__ size_t d_CoordToLinearEnd(int* coo, int* dim, int rank) {
    size_t pp = 1;
    size_t sm = 0;
    for (int i = 0; i < rank; ++i) {
        sm += (coo[i] * pp);
        pp *= dim[i];
    }
    return sm;
}

__device__ size_t d_CoordToLinear(int* coo, int* dim, int rank) {
    size_t pp = 1;
    size_t sm = 0;
    for (int i = rank - 1; i >= 0; --i) {
        sm += (coo[i] * pp);
        pp *= dim[i];
    }
    return sm;
}



__device__ void d_LinearToCoord(int* ret, size_t lin, int* dim, int rank, size_t size) {
    size_t sm = lin;
    size_t pp = size;
    for (int i = 0; i < rank - 1; ++i) {
        pp /= dim[i];
        ret[i] = sm / pp;
        sm %= pp;
    }
    ret[rank - 1] = sm;
}
/*__device__ void d_LinearToSplitSubrankLimSz(size_t& part0, size_t& part1, size_t lin, int* dim, int rank, int rankA, size_t size, size_t sizeA) {
    size_t sm = lin;
    size_t pp = size;
    size_t s = 0;
    size_t p = sizeA;
    int ret;// = new int[rank];
    for (int i = 0; i < rank; ++i) {
        pp /= dim[i];
        ret = sm / pp;
        p /= dim[i];
        s += ret * p;

        sm %= pp;
        if (i == rankA - 1) {
            part0 = s;
            s = 0;
            p = size / sizeA;
        }

    }
    part1 = s;

}*/
__device__ void d_LinearToSplitSubrankLimSz(size_t& part0, size_t& part1, size_t lin, int* dim, int rank, int rankA, size_t size, size_t sizeA) {
    size_t sm = lin;
    size_t pp = size;
    size_t s = 0;
    size_t p = sizeA;
    int ret;// = new int[rank];
    int i;
    for (i = 0; i < rankA; ++i) {
        pp /= dim[i];
        ret = sm / pp;
        p /= dim[i];
        s += ret * p;

        sm %= pp;

    }
    part0 = s;
    s = 0;
    p = size / sizeA;//sizeB
    for (; i < rank; ++i) {
        pp /= dim[i];
        ret = sm / pp;
        p /= dim[i];
        s += ret * p;

        sm %= pp;

    }

    part1 = s;

}
__device__ void d_LinearToSplitSubrankLimSzEnd(size_t& part0, size_t& part1, size_t lin, int* dim, int rank, int rankA, size_t size, size_t sizeA) {
    size_t sm = lin;
    size_t pp = size;
    size_t s = 0;
    size_t p = sizeA;
    int ret;// = new int[rank];
    for (int i = rank - 1; i >= 0; --i) {
        pp /= dim[i];
        ret = sm / pp;
        p /= dim[i];
        s += ret * p;

        sm %= pp;
        if (i == rankA) {
            part1 = s;
            s = 0;
            p = size / sizeA;
        }

    }
    part0 = s;

}


__device__ void d_subArray(int* dst, int* src, int debDst, int finDst, int debSrc) {
    for (int i = debDst; i < finDst; i++) {
        dst[i] = src[i + debSrc];
    }
}

template<typename T>
__global__ void d_prodTensor(T* C, int* dimC, int rankC, size_t size, T* A, int* dimA, int rankA, size_t sizeA, T* B, int* dimB, int rankB) {
    size_t lin0, lin1;

    size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < size) {
        d_LinearToSplitSubrankLimSz(lin0, lin1, i, dimC, rankC, rankA, size, sizeA);

        C[i] = A[lin0] * B[lin1];

    }
}

template __global__  void d_prodTensor<float>(float* C, int* dimC, int rankC, size_t size, float* A, int* dimA, int rankA, size_t sizeA, float* B, int* dimB, int rankB);

template<typename T>
__global__ void d_prodTensorEnd(T* C, int* dimC, int rankC, size_t size, T* A, int* dimA, int rankA, size_t sizeA, T* B, int* dimB, int rankB) {
    size_t lin0, lin1;

    size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    if (i < size) {
        d_LinearToSplitSubrankLimSzEnd(lin0, lin1, i, dimC, rankC, rankA, size, sizeA);

        C[i] = A[lin0] * B[lin1];

    }
}

template __global__  void d_prodTensorEnd<float>(float* C, int* dimC, int rankC, size_t size, float* A, int* dimA, int rankA, size_t sizeA, float* B, int* dimB, int rankB);

__device__ void d_minReverse(int* dim, int& rank, const int* dim0, int rank0, const int* dim1, int rank1, bool& rev) {
    if (rank0 > rank1) {
        rank = rank1;
        for (int i = 0; i < rank1; ++i) dim[i] = dim1[i];
        rev = true;
    }
    else if (rank0 < rank1) {
        rank = rank0;
        for (int i = 0; i < rank1; ++i) dim[i] = dim0[i];
        rev = false;
    }
    else {// rank0 == rank1
        rank = rank0;
        for (int i = 0; i < rank0; i++) {
            if (dim[i] > dim1[rank1 - 1 - i]) dim[i] = dim1[rank1 - 1 - i];
            else dim[i] = dim0[i];
        }
        rev = false;
    }
}

__device__ void d_reverseArray(int* arr, int sz) {
    int* tmp;
    //tmp  = (int*)malloc(sz * sizeof(int));

    tmp = new int[sz];
    if (tmp == NULL) {
        size_t limit = 0;
        cudaDeviceGetLimit(&limit, cudaLimitStackSize);
        printf("cudaLimitStackSize: %u | %d (%d) %d | \n", (unsigned)limit, blockIdx.x, blockDim.x, threadIdx.x);
        cudaDeviceGetLimit(&limit, cudaLimitPrintfFifoSize);
        printf("cudaLimitPrintfFifoSize: %u | %d (%d) %d | \n", (unsigned)limit, blockIdx.x, blockDim.x, threadIdx.x);
        cudaDeviceGetLimit(&limit, cudaLimitMallocHeapSize);
        printf("cudaLimitMallocHeapSize: %u | %d (%d) %d | \n", (unsigned)limit, blockIdx.x, blockDim.x, threadIdx.x);

        printf("error Allocation in    tmp  = (int*)malloc(sz * sizeof(int)); |  |   ");
    }int i = 0;
    for (; i < sz / 2; i++) {
        tmp[i] = arr[i];
        arr[i] = arr[sz - 1 - i];
    }
    for (; i < sz; i++) {
        arr[i] = tmp[sz - 1 - i];
    }
    //free(tmp);
    delete[]tmp;
}

__device__ int d_min(int a, int b) {
    if (a < b) return a;
    return b;
}

__device__ void d_concatArray(int* dst, int* src0, int* src1, int debDst, int debSrc0, int finSrc0, int debSrc1, int finSrc1) {
    int i = debDst;
    for (int j = debSrc0; j < finSrc0; j++) {
        dst[i++] = src0[j];
    }
    for (int j = debSrc1; j < finSrc1; j++) {
        dst[i++] = src1[j];
    }
}



__device__ void d_ConcatLinearToSplitSubrankLimSz(size_t& part0, size_t& part1, size_t lin, int* dim, int rank, int rankA, int rankB, size_t size, size_t sizeA, size_t sizeB, int* dM, int dMrank, size_t dMsize, int ind) {
    size_t sm = lin;
    size_t pp = size;
    size_t s = 0;
    size_t p = sizeA;
    //size_t sz_dA = sizeA / dMsize;
    int rankdA = rankA - dMrank;

    int ret;
    int i;
    for (i = 0; i < rankdA; ++i) {
        pp /= dim[i];
        ret = sm / pp;
        p /= dim[i];
        s += ret * p;
        sm %= pp;
    }
    size_t s1 = 0;

    size_t pb = sizeB / dMsize;
    for (; i < rank; ++i) {
        pp /= dim[i];
        ret = sm / pp;
        pb /= dim[i];
        s1 += ret * pb;
        sm %= pp;
    }

    size_t smd = ind;
    size_t ppb = dMsize;
    //size_t pb = size / sz_dA;
    pb = sizeB;
    p = dMsize;
    for (int j = 0;j < dMrank;j++) {
        ppb /= dM[j];
        ret = smd / ppb;
        p /= dM[j];
        s += ret * p;
        pb /= dM[j];
        s1 += ret * pb;
        smd %= ppb;
    }
    //pp = size / sz_dA;
    part0 = s;
    part1 = s1;
}

__device__ void d_SplitLineardToSubrank(size_t& part0, size_t& part1, size_t lin, int* dim, int rank, int rankA, int rankB, size_t size, size_t sizeA, size_t sizeB, int* dM, int dMrank, size_t dMsize) {
    size_t sm = lin;
    size_t pp = size;
    size_t s = 0;
    size_t p = sizeA;
    //size_t sz_dA = sizeA / dMsize;
    int rankdA = rankA - dMrank;

    int ret;
    int i;
    for (i = 0; i < rankdA; ++i) {
        pp /= dim[i];
        ret = sm / pp;
        p /= dim[i];
        s += ret * p;
        sm %= pp;
    }
    size_t s1 = 0;

    size_t pb = sizeB / dMsize;
    for (; i < rank; ++i) {
        pp /= dim[i];
        ret = sm / pp;
        pb /= dim[i];
        s1 += ret * pb;
        sm %= pp;
    }
    part0 = s;
    part1 = s1;
}


__device__ void d_UnionConcatLinearSplitedSubrank(size_t& part0, size_t& part1, size_t p0, size_t p1, size_t size, size_t sizeB, int* dM, int dMrank, size_t dMsize, int ind) {
    size_t s = p0;
    size_t s1 = p1;
    int ret;
    size_t smd = ind;
    size_t ppb = dMsize;
    //size_t pb = size / sz_dA;
    size_t pb = sizeB;
    size_t p = dMsize;
    for (int j = 0;j < dMrank;j++) {
        ppb /= dM[j];
        ret = smd / ppb;
        p /= dM[j];
        s += ret * p;
        pb /= dM[j];
        s1 += ret * pb;
        smd %= ppb;
    }
    //pp = size / sz_dA;
    part0 = s;
    part1 = s1;
}

template<typename T>
__global__ void d_TensorContractnReverseProd(T* C, int* dimC, int rankC, size_t sizeC, T* A, int rankA, size_t sizeA, T* B, int rankB, size_t sizeB, int* dM, int dMrank, size_t dMsize) {

    size_t p0, p1;
    size_t lin0, lin1;


    //size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    size_t i = d_getGlobalIdx_1D_1D();

    if (i < sizeC) {

        d_SplitLineardToSubrank(p0, p1, i, dimC, rankC, rankA, rankB, sizeC, sizeA, sizeB, dM, dMrank, dMsize);

        C[i] = 0;
        for (size_t k = 0; k < dMsize; k++) {

            d_UnionConcatLinearSplitedSubrank(lin0, lin1, p0, p1, sizeC, sizeB, dM, dMrank, dMsize, k);

            //d_ConcatLinearToSplitSubrankLimSz(lin0, lin1, i, dimC, rankC, rankA, rankB, sizeC, sizeA, sizeB, dM, dMrank, dMsize, k);

            C[i] += A[lin0] * B[lin1];
        }
    }

}

template
__global__ void  d_TensorContractnReverseProd<float>(float* C, int* dimC, int rankC, size_t size, float* A, int rankA, size_t sizeA, float* B, int rankB, size_t sizeB, int* dM, int dMrank, size_t dMsize);

__device__ void d_LinearTransformCoord(size_t& dst, size_t src, int* inversePerm, size_t sizeA, int rankDst, int rankSrc, int* dDst, int* dSrc) {
    size_t sm = src;
    size_t pp = sizeA;
    size_t s = 0;
    size_t p = 1;
    int ret;// = new int[rank];
    int i, j;
    for (i = 0; i < rankSrc; ++i) {
        pp /= dSrc[i];
        ret = sm / pp;
        p = 1;
        for (j = inversePerm[i] + 1; j < rankDst;j++) {
            p *= dDst[j];
        }
        s += ret * p;

        sm %= pp;

    }
    dst = s;
    if (s > sizeA) printf("I have a problem in LinearTransformCoord: s:%ld siez:%ld \n", s, sizeA);

}

template<typename T>
__global__ void d_PermLinearTransformCoord(T* C, int* dimC, int rankC, size_t sizeC, T* A, int* dimA, int rankA, size_t sizeA, int* invPerm) {

    //size_t i = threadIdx.x + blockIdx.x * blockDim.x;
    size_t i = d_getGlobalIdx_1D_1D();

    if (i < sizeC) {
        //printf("<i:%*ld ", 3, i);

        size_t img = 0;
        //printf("<i:%*ld, img:%*ld\n", 3, i, 3, img);
        d_LinearTransformCoord(img, i, invPerm, sizeA, rankC, rankA, dimC, dimA);
        //img = d_LinearTransformCoord(i, invPerm, sizeC, dimC, dimA, rankC);

        if (img < sizeC)
            C[img] = A[i];
        else {
            printf("something wrong in device: i:%ld , s:%ld\n", i, img);
        }
    }

}

template
__global__ void  d_PermLinearTransformCoord<float>(float* C, int* dimC, int rankC, size_t size, float* A, int* dimA, int rankA, size_t sizeA, int* invPerm);

