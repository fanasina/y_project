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
void _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(tensor_##type **M, dimension *dd);\
tensor_##type* CLONE_TENSOR_##type(tensor_##type *tens);\
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
void fprint_tensor_##type(char *file_name, tensor_##type *T);\
size_t sprint_tensor_##type(char **tensorContent,tensor_##type *T, bool withIndex);\
void split_tensor_##type(tensor_##type *Troot, tensor_##type **Tpart1, tensor_##type **Tpart2, size_t pivotSplit, size_t rangeInPivot);\
void split_copy_tensor_##type(tensor_##type *Troot, tensor_##type **Tpart1, tensor_##type **Tpart2, size_t pivotSplit, size_t rangeInPivot);\
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
void parseInputOutput_withDim_to_tensors_##type(tensor_##type **Tpart1, tensor_##type **Tpart2, char *input, size_t pivotSplit);\
void parse_file_InputOutput_withDim_to_tensors_##type(tensor_##type **Tpart1, tensor_##type **Tpart2, char *file_name_input, size_t pivotSplit);\
tensor_##type ** fromInput_to_array_tensor_##type(tensor_##type *tens);\
struct array_chainlist_##type{\
  size_t index;\
  type x;\
  struct array_chainlist_##type *next;\
};\
typedef struct array_chainlist_##type array_chainlist_##type;\
void append_array_chainlist_##type(array_chainlist_##type **list_a, type x);\
tensor_##type * create_tensor_from_list_array_##type( array_chainlist_##type *l_a, dimension *part_dim);\
void free_array_chainlist_##type(array_chainlist_##type *l_a);\
tensor_##type * transpose_notOpt_tensor_##type(tensor_##type *org);\
tensor_##type * permute_notOpt_tensor_##type(tensor_##type *org, dimension *dperm);\
void update_1tensor_func_##type(tensor_##type *M0, \
    type (*func)(type), size_t nbthread);\
void update_2tensor_func_##type(tensor_##type *M0, tensor_##type *M1, \
    type (*func)(type), size_t nbthread);\
void update_3tensor_func_##type(tensor_##type *M0, tensor_##type *M1, tensor_##type *M2, \
    type (*func)(type, type), size_t nbthread);\
void update_4tensor_func_##type(tensor_##type *M0, tensor_##type *M1, tensor_##type *M2, \
    type (*func)(type, type,  type(*f1)(type)),\
    type(*f1)(type),\
    size_t nbthread);\
void update_5tensor_func_##type(tensor_##type *M0, tensor_##type *M1, tensor_##type *M2, tensor_##type *M3 , \
    type (*func) (type, type, type, type(*f1)(type), type (*f2)(type,type)), \
    type(*f1)(type), \
    type (*f2)(type,type), \
    size_t nbthread);\
void update_6tensor_func_##type(tensor_##type *M0, tensor_##type *M1,  \
    type (*func)(type, type, type),\
    type scalar,\
    size_t nbthread);\


GENERATE_TENSOR_TYPE(TYPE_FLOAT);
GENERATE_TENSOR_TYPE(TYPE_DOUBLE);


#endif /* __TENSOR_T__H__ */
