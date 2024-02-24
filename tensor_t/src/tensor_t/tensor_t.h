#ifndef __TENSOR_T__H__
#define __TENSOR_T__H__

#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#include "dimension_t/dimension_t.h"

void subArray(size_t* dst, size_t* src, size_t debDst, size_t finDst, size_t debSrc);

#define GENERATE_TENSOR_TYPE(type) \
struct tensor_##type{\
  dimension *dim;\
  type *x;\
};\
typedef struct tensor_##type tensor_##type;\
tensor_##type * CREATE_TENSOR_##type(dimension *dim); \
tensor_##type* CREATE_TENSOR_FROM_CPY_DIM_##type(dimension *dim);\
void free_tensor_##type(tensor_##type *  tens); \
tensor_##type * sub_minus_tensor_head_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim); \
tensor_##type * sub_minus_tensor_tail_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim); \
tensor_##type * sub_tensor_head_##type(tensor_##type *rootens, size_t subdim, size_t rankInDim); \
tensor_##type * sub_tensor_tail_##type(tensor_##type *rootens, size_t subdim, size_t rankInDim); \
tensor_##type * sub_copy_minus_tensor_head_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim); \
tensor_##type * sub_copy_minus_tensor_tail_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim); \
tensor_##type * sub_copy_tensor_head_##type(tensor_##type *rootens, size_t sub_copydim, size_t rankInDim); \
tensor_##type * sub_copy_tensor_tail_##type(tensor_##type *rootens, size_t sub_copydim, size_t rankInDim); \
void print_tensor_msg_##type(tensor_##type *T, char *msg);\
size_t sprint_tensor_##type(char **tensorContent,tensor_##type *T, bool withIndex);\
void split_tensor_##type(tensor_##type *Troot, tensor_##type **Tpart1, tensor_##type **Tpart2, size_t pivotSplit, size_t rangeInPivot);\
void tensorProdNotOpt_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1); \
void tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1); \
void tensorContractnProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber); \
void tensorProdThread_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1,size_t nbthread); \
void tensorProdThrea2d_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1,size_t nbthread); \
void tensorContractnProdThread_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread); \
void tensorContractnPro2dThread_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread); \
void tensorContractnProdNotOpt_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber); \
void init_random_x_##type(tensor_##type *M, type minR, type maxR,  int randomRange);\
tensor_##type * parseInput_withDim_to_tensor_##type(char *input);\
struct array_chainlist_##type{\
  size_t index;\
  type x;\
  struct array_chainlist_##type *next;\
};\
typedef struct array_chainlist_##type array_chainlist_##type;\
void append_array_chainlist_##type(array_chainlist_##type **list_a, type x);\
tensor_##type * create_tensor_from_list_array_##type( array_chainlist_##type *l_a, dimension *part_dim);\
void free_array_chainlist_##type(array_chainlist_##type *l_a);\



GENERATE_TENSOR_TYPE(TYPE_FLOAT);
GENERATE_TENSOR_TYPE(TYPE_DOUBLE);


#endif /* __TENSOR_T__H__ */
