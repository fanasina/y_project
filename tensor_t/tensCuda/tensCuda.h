#ifndef __TENS_CUDA_H__
#define __TENS_CUDA_H__

#include <cstdio>
#include <cstdlib>

#include <stdexcept>

//#include "/home/fanasina/progr_/ptens0neD/tensor/tens0neD/tens0neD.h"
#include "tensor/tens0neD/tens0neD.h"

//#include "/home/fanasina/progr_/ptens0neD/tensor/tensCuda/d_tensCuda.h"
#include "tensor/tensCuda/d_tensCuda.h"
//#include "dimension/dimension.h"

template<typename T>
struct Tensor;

template<typename T>
void cudaTensorContractNestProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1, int nestingDepth, bool strict = true);

template<typename T>
void cudaTensorProd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1);
template<typename T>
void cudaTensorProdEnd(Tensor<T>& M, const Tensor<T>& M0, const Tensor<T>& M1);
template<typename T>
void cudapermuteTensor(Tensor<T>& M, const Tensor<T>& M0, permutation p);


#endif

