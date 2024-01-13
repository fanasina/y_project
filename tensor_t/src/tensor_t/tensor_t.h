#ifndef __TENSOR_T__H__
#define __TENSOR_T__H__

#include "dimension_t/dimension_t.h"

#define GENERATE_TENSOR_TYPE(type) \
struct tensor_##type{\
  dimension dim;\
  type *x;\
};\
typedef struct tensor_##type tensor_##type;\
struct tensor_##type CREATE_TENSOR_##type(struct dimension_t dim); \




#endif /* __TENSOR_T__H__ */
