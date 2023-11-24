#include <cstdio>
#include <cstdlib>

#include <stdexcept>

#include <vector>
#include <algorithm>


//#include "/home/fanasina/progr_/ptens0neD/tensor/tens0neD/tens0neD.h"

//#include "/home/fanasina/progr_/ptens0neD/tensor/tensCuda/tensCuda.h"
#include "tensor/tensCuda/tensCuda.h"




template<typename T>
void cudaTensorProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1) {
    add(M.Dim, M0.Dim, M1.Dim);
    M.initTensor();

    int* d_imM, * d_imM0, * d_imM1;
    cudaError_t  errCu = cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&d_imM1, M1.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM1, M1.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(d_imM1, M1.Dim.dim, M1.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM1, M1.Dim.dim, M1.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    T* e, * e0, * e1;
    errCu = cudaMalloc((void**)&e, M.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e, M.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&e1, M1.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e1, M1.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(e1, M1.elements, M1.Dim.size * sizeof(T), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(e1, M1.elements, M1.Dim.size * sizeof(T), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    int BLOCKSIZE = 256;//1024;
    int DIMBLOCKS = (M.Dim.size + BLOCKSIZE - 1) / BLOCKSIZE;
    //int DIMBLOCKS = (M.Dim.size) / BLOCKSIZE;

    d_prodTensor<T> << < DIMBLOCKS, BLOCKSIZE >> > (e, d_imM, M.Dim.rank, M.Dim.size, e0, d_imM0, M0.Dim.rank, M0.Dim.size, e1, d_imM1, M1.Dim.rank);

    errCu = cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaFree(e);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(e0);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(e1);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e1) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM0);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM1);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM1) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
}


//template void cudaTensorProd<double>(Tensor<double>& M, const Tensor<double>& M1, const Tensor<double>& M0);
template void cudaTensorProd<float>(Tensor<float>& M, const Tensor<float>& M1, const Tensor<float>& M0);


template<typename T>
void cudaTensorProdEnd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1) {
    add(M.Dim, M0.Dim, M1.Dim);
    M.initTensor();

    int* d_imM, * d_imM0, * d_imM1;
    cudaError_t errCu = cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&d_imM1, M1.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM1, M1.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(d_imM1, M1.Dim.dim, M1.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM1, M1.Dim.dim, M1.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    T* e, * e0, * e1;
    errCu = cudaMalloc((void**)&e, M.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e, M.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&e1, M1.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e1, M1.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(e1, M1.elements, M1.Dim.size * sizeof(T), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(e1, M1.elements, M1.Dim.size * sizeof(T), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    size_t BLOCKSIZE = 1024;
    size_t DIMBLOCKS = (M.Dim.size + BLOCKSIZE - 1) / BLOCKSIZE;

    d_prodTensorEnd<T> << < DIMBLOCKS, BLOCKSIZE >> > (e, d_imM, M.Dim.rank, M.Dim.size, e0, d_imM0, M0.Dim.rank, M0.Dim.size, e1, d_imM1, M1.Dim.rank);

    cudaDeviceSynchronize();

    errCu = cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaFree(e);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(e0);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(e1);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e1) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM0);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM1);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM1) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
}


//template void cudaTensorProd<double>(Tensor<double>& M, const Tensor<double>& M1, const Tensor<double>& M0);
template void cudaTensorProdEnd<float>(Tensor<float>& M, const Tensor<float>& M1, const Tensor<float>& M0);


template<typename T>
void cudapermuteTensor(Tensor<T>& M, const Tensor<T>& M0, permutation p) {
    if (p.size == M0.Dim.rank) {
        M.Dim.rank = M0.Dim.rank;
        M.Dim.size = M0.Dim.size;
        M.Dim.initDim();
        M.initTensor();

        p.permute(M.Dim.dim, M0.Dim.dim);


        cudaEvent_t start, stop;
        cudaEventCreate(&start);
        cudaEventCreate(&stop);

        cudaEventRecord(start);


        int* d_imM, * d_imM0;
        cudaError_t errCu = cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int));
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }

        errCu = cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int));
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }

        errCu = cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }

        errCu = cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }


        T* e, * e0;
        errCu = cudaMalloc((void**)&e, M.Dim.size * sizeof(T));
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMalloc((void**)&e, M.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }
        errCu = cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T));
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }


        errCu = cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }


        size_t BLOCKSIZE = 256; //1024;//512;
        size_t DIMBLOCKS = (M.Dim.size + BLOCKSIZE - 1) / BLOCKSIZE;
        dim3 blckSZ, gridSZ;
        blckSZ.x = BLOCKSIZE;
        gridSZ.x = DIMBLOCKS;

        int* invP, * d_invP;
        invP = (int*)malloc(M.Dim.rank * sizeof(int));
        inverseArray(invP, p.perm, M.Dim.rank);
        errCu = cudaMalloc((void**)&d_invP, M.Dim.rank * sizeof(int));
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMalloc((void**)&d_invP, M.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }

        errCu = cudaMemcpy(d_invP, invP, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMemcpy(d_invP, invP, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }
        //printf("size: %ld\n", M.Dim.size);

        //d_prodTensorEnd<T> << < DIMBLOCKS, BLOCKSIZE >> > (e, d_imM, M.Dim.rank, M.Dim.size, e0, d_imM0, M0.Dim.rank, e1, d_imM1, M1.Dim.rank);
        //d_TensorContractnReverseProd<T> << < DIMBLOCKS, BLOCKSIZE >> > (e, d_imM, M.Dim.rank, M.Dim.size, d_imdM, dM.rank, dM.size, e0, d_imM0, M0.Dim.rank, e1, d_imM1, M1.Dim.rank, nestingDepth);
        //d_TensorContractnReverseProd<T> << < gridSZ, blckSZ, 0, 0 >> > (e, d_imM, M.Dim.rank, M.Dim.size, d_imdM, dM.rank, dM.size, e0, d_imM0, M0.Dim.rank, e1, d_imM1, M1.Dim.rank, nestingDepth);
        d_PermLinearTransformCoord<T> << < gridSZ, blckSZ, 0, 0 >> > (e, d_imM, M.Dim.rank, M.Dim.size, e0, d_imM0, M0.Dim.rank, M0.Dim.size, d_invP);
        //d_PermLinearTransformCoord<T> << < gridSZ, blckSZ, 0, 0 >> > (e, d_imM, M.Dim.rank, M.Dim.size, e0, d_imM0, M0.Dim.rank, M0.Dim.size, p.perm);
        //cudaDeviceSynchronize();


        errCu = cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }

        errCu = cudaFree(e);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaFree(e) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }
        errCu = cudaFree(e0);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaFree(e0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }

        errCu = cudaFree(d_imM);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaFree(d_imM) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }
        errCu = cudaFree(d_imM0);
        if (cudaSuccess != errCu) {
            printf("device fnc failed cudaFree(d_imM0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
            exit(errCu);
        }

        cudaEventRecord(stop);
        cudaEventSynchronize(stop);
        float milliseconds = 0;
        cudaEventElapsedTime(&milliseconds, start, stop);
        printf("ellaps time cuda permute tensor: %f ms\n", milliseconds);

    }
}

template
void cudapermuteTensor(Tensor<float>& M, const Tensor<float>& M0, permutation p);


// strict match contract ! if no strict, we take the minimum
template<typename T>
void cudaTensorContractNestProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M11, int nestingDepth, bool strict) {


    int perm[M11.Dim.rank];
    struct Tensor<T> M1;
    if (scanPermuteMatchContractTensorfromSrcToDst(perm, M11, M0, nestingDepth)) {
        for (int i = 0; i < M11.Dim.rank; i++) printf(" %d[%d] ", i, perm[i]); printf(": last perm \n");
        struct permutation p(M11.Dim.rank, perm);
        permuteTensor(M1, M11, p);
        M1.Dim.print();

    }
    else {
        printf("Failed in Deep = %d\n", nestingDepth);
        //throw std::check_ProdTensor(" Failed imbrication order in Multiplication matrix ");

        throw std::invalid_argument(" Failed imbrication order in Multiplication matrix ");
        exit(1);
    }


    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);

    int len0 = M0.Dim.rank - nestingDepth;
    int len1 = M1.Dim.rank - nestingDepth;

    int* tsub0 = new int[len0];
    int* tsub1 = new int[len1];
    int* tDk1 = new int[nestingDepth];
    int* tDk0 = new int[nestingDepth];
    subArray(tsub0, M0.Dim.dim, 0, len0, 0);
    subArray(tsub1, M1.Dim.dim, 0, len1, nestingDepth);
    subArray(tDk1, M1.Dim.dim, 0, nestingDepth, 0);
    subArray(tDk0, M0.Dim.dim, 0, nestingDepth, len0);

    dimension dSub0(len0, tsub0);
    dimension dSub1(len1, tsub1);
    dimension dM1(nestingDepth, tDk1);
    dimension dM0(nestingDepth, tDk0);
    dimension dM(dM0);
    //bool rev;
    //minReverse(dM, dM0, dM1, rev);
    //if (rev) reverseArray(dM.dim, dM.rank);
    //max(dM, dM0, dM1);

    add(M.Dim, dSub0, dSub1);
    M.initTensor();



    int* d_imM, * d_imM0, * d_imM1, * d_imdM;
    cudaError_t errCu = cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM, M.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&d_imdM, dM.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imdM, dM.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM0, M0.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&d_imM1, M1.Dim.rank * sizeof(int));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&d_imM1, M1.Dim.rank * sizeof(int)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM, M.Dim.dim, M.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(d_imdM, dM.dim, dM.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imdM, dM.dim, dM.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM0, M0.Dim.dim, M0.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(d_imM1, M1.Dim.dim, M1.Dim.rank * sizeof(int), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(d_imM1, M1.Dim.dim, M1.Dim.rank * sizeof(int), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    T* e, * e0, * e1;
    errCu = cudaMalloc((void**)&e, M.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e, M.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e0, M0.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMalloc((void**)&e1, M1.Dim.size * sizeof(T));
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMalloc((void**)&e1, M1.Dim.size * sizeof(T)) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(e0, M0.elements, M0.Dim.size * sizeof(T), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaMemcpy(e1, M1.elements, M1.Dim.size * sizeof(T), cudaMemcpyHostToDevice);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(e1, M1.elements, M1.Dim.size * sizeof(T), cudaMemcpyHostToDevice) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    size_t BLOCKSIZE = 256; //1024;//512;
    size_t DIMBLOCKS = (M.Dim.size + BLOCKSIZE - 1) / BLOCKSIZE;
    dim3 blckSZ, gridSZ;
    blckSZ.x = BLOCKSIZE;
    gridSZ.x = DIMBLOCKS;


    //d_prodTensorEnd<T> << < DIMBLOCKS, BLOCKSIZE >> > (e, d_imM, M.Dim.rank, M.Dim.size, e0, d_imM0, M0.Dim.rank, e1, d_imM1, M1.Dim.rank);
    //d_TensorContractnReverseProd<T> << < DIMBLOCKS, BLOCKSIZE >> > (e, d_imM, M.Dim.rank, M.Dim.size, d_imdM, dM.rank, dM.size, e0, d_imM0, M0.Dim.rank, e1, d_imM1, M1.Dim.rank, nestingDepth);
    //d_TensorContractnReverseProd<T> << < gridSZ, blckSZ, 0, 0 >> > (e, d_imM, M.Dim.rank, M.Dim.size, d_imdM, dM.rank, dM.size, e0, d_imM0, M0.Dim.rank, e1, d_imM1, M1.Dim.rank, nestingDepth);
    d_TensorContractnReverseProd<T> << < gridSZ, blckSZ, 0, 0 >> > (e, d_imM, M.Dim.rank, M.Dim.size, e0, M0.Dim.rank, M0.Dim.size, e1, M1.Dim.rank, M1.Dim.size, d_imdM, dM.rank, dM.size);

    //cudaDeviceSynchronize();


    errCu = cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaMemcpy(M.elements, e, M.Dim.size * sizeof(T), cudaMemcpyDeviceToHost) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }

    errCu = cudaFree(e);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(e0);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(e1);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(e1) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM0);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM0) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    errCu = cudaFree(d_imM1);
    if (cudaSuccess != errCu) {
        printf("device fnc failed cudaFree(d_imM1) \n ErrorCuda: %d : %s\n", errCu, cudaGetErrorString(errCu));
        exit(errCu);
    }
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);
    float milliseconds = 0;
    cudaEventElapsedTime(&milliseconds, start, stop);
    printf("ellaps time cuda prod contract prod: %f ms\n", milliseconds);


}

template
void cudaTensorContractNestProd<float>(Tensor<float>& M, const Tensor<float>& M0, const Tensor<float>& M1, int nestingDepth, bool strict);
//template void cudaTensorContractnReverseProd<double>(Tensor<double>& M, const Tensor<double>& M0, const Tensor<double>& M1, int nestingDepth);

