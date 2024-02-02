#ifndef __TENSOR_T__H__
#define __TENSOR_T__H__

#include "dimension_t/dimension_t.h"

void subArray(size_t* dst, size_t* src, size_t debDst, size_t finDst, size_t debSrc);

#define GENERATE_TENSOR_TYPE(type) \
struct tensor_##type{\
  dimension *dim;\
  type *x;\
};\
typedef struct tensor_##type tensor_##type;\
tensor_##type * CREATE_TENSOR_##type(dimension *dim); \
tensor_##type * sub_minus_tensor_head_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim); \
tensor_##type * sub_minus_tensor_tail_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim); \
tensor_##type * sub_tensor_head_##type(tensor_##type *rootens, size_t subdim, size_t rankInDim); \
tensor_##type * sub_tensor_tail_##type(tensor_##type *rootens, size_t subdim, size_t rankInDim); \
void tensorProdNotOpt_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1); \
void tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1); \
void tensorContractnProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber); \
void tensorContractnProdNotOpt_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber); \


GENERATE_TENSOR_TYPE(TYPE_FLOAT);
GENERATE_TENSOR_TYPE(TYPE_DOUBLE);


#endif /* __TENSOR_T__H__ */
