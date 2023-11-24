#ifndef __TENS_0NE_D_H__
#define __TENS_0NE_D_H__

#include <cstdio>
#include <cstdlib>

#include <stdexcept>

//#include "tensor.h"
//#include "cudatensor.h"
//#include "/home/fanasina/progr_/ptens0neD/dimension/dimension.h"
//#include "/home/fanasina/progr_/ptens0neD/permutation/permutation.h"
//#include "/home/fanasina/progr_/ptens0neD/tensor/tensCuda/tensCuda.h"

#include "dimension/dimension.h"
#include "permutation/permutation.h"
#include "tensor/tensCuda/tensCuda.h"

template<typename T>
struct Tensor {
    struct dimension Dim;
    T* elements;
    Tensor(struct dimension dm = dimension(1)) {
        Dim = dm;
        //elements = new T[Dim.size];
        elements = (T*)malloc(Dim.size * sizeof(T));
    }
    void initTensor() {
        //delete[]elements;
        //elements = new T[Dim.size];
        if (elements != NULL)
            free(elements);
        elements = (T*)malloc(Dim.size * sizeof(T));
    }
    void initVal(T val); // { for (int i = 0; i < Dim.size; i++) elements[i] = val + 0.001f * i; }
    void print();
    Tensor& operator=(const Tensor& M);
    Tensor& operator*=(const T& val);
    template<typename Ty>
    friend Tensor<Ty>& operator*(const Tensor<Ty>& M0, const Tensor<Ty>& M1);

    // M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l
    // M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)   
    template<typename Ty>
    friend void tensorContractnProd(Tensor<Ty>& M, const Tensor<Ty>& M0, const Tensor<Ty>& M1, int nestingDepth);

    // M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xn = y0,x{n-1}=y1, x{n-l}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l
    // M[x0,x1,x3..xl x{l+1}..xn] X M[xn,x{n-1},..x{l+1}xl y{l+1}..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)  
    template<typename Ty>
    friend void tensorContractnReverseProd(Tensor<Ty>& M, const Tensor<Ty>& M0, const Tensor<Ty>& M1, int nestingDepth);

    template<typename Ty>
    friend void cudaTensorContractNestProd(Tensor<Ty>& M, const Tensor<Ty>& M0, const Tensor<Ty>& M1, int nestingDepth, bool strict);

    /*template<typename Ty>
    friend void cudaTensorContractnProd(Tensor<Ty>& M, const Tensor<Ty>& M0, const Tensor<Ty>& M1, int nestingDepth);
*/

    template<typename Ty>
    friend void tensorProd(Tensor<Ty>& M, const Tensor<Ty>& M0, const Tensor<Ty>& M1);

    template<typename Ty>
    friend void cudaTensorProd(Tensor<Ty>& M, const Tensor<Ty>& M0, const Tensor<Ty>& M1);

    template<typename Ty>
    friend void cudaTensorProdEnd(Tensor<Ty>& M, const Tensor<Ty>& M0, const Tensor<Ty>& M1);

    template<typename Ty>
    friend void permuteTensor(Tensor<Ty>& M, const Tensor<Ty>& M0, permutation p);
    template<typename Ty>
    friend void permuteTensorDef(Tensor<Ty>& M, const Tensor<Ty>& M0, permutation p);
    template<typename Tp>
    friend bool scanPermuteMatchContractTensorfromSrcToDst(int* perm, const Tensor<Tp>& Msecond, const Tensor<Tp>& Mfirst, int contractNest);

    //template<typename Ty>
    //friend void cudapermuteTensor(Tensor<Ty>& M, const Tensor<Ty>& M0, permutation p);

};

template<typename T>
void transform(Tensor<T>& Dst, const Tensor<T>& Src, int* perm, int sz);


template<typename T>
Tensor<T>& operator*(const Tensor<T>& M0, const Tensor<T>& M1);


void subArray(int* dst, int* src, int debDst, int finDst, int debSrc);

void concatArray(int* dst, int* src0, int* src1, int debDst, int debSrc0, int finSrc0, int debSrc1, int finSrc1);

void reverseArray(int* arr, int sz);

template<typename T>
void tensorProd(Tensor<T>& M, const Tensor<T>& M1, const Tensor<T>& M0);

bool checkMatchProdTensor(const dimension& d0, const dimension& d1, int nestingDepth);

void extractDimNestingDepth(dimension& dM, const dimension& d0, const dimension& d1, int nestingDepth);

// M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xn = y0,x{n-1}=y1, x{n-l}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l

//M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]
template<typename T>
void tensorContractnProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1, int nestingDepth);

// M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xn = y0,x{n-1}=y1, x{n-l}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l

//M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]
template<typename T>
void tensorContractnReverseProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1, int nestingDepth);

#endif

