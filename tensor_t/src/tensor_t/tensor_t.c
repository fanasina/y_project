#include "tensor_t/tensor_t.h"

#define GEN_FUNC_TENSOR(type)\
  struct tensor_##type CREATE_TENSOR_##type(struct dimension_t dim){\
    struct tensor_##type r_tens=malloc(sizeof(tensor_t##type));\
    r_tens->x=malloc(sizeof(type)*dim->size);\
    return r_tens;\
  }



