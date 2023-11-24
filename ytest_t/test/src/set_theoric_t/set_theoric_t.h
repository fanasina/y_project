#ifndef __SET_THEORIC_T_C__H
#define __SET_THEORIC_T_C__H

#include <stdlib.h>

#include "tools_t/tools_t.h"

#define GENERATE_UNSIGNED_SET_THEORIC(type)                       \
  struct SET_THEORIC_##type{                                      \
    type id;                                                      \
    type *set;                                                    \
  };                                                              \
  typedef struct SET_THEORIC_##type SET_THEORIC_##type;           \
  SET_THEORIC_##type * CREATE_SET_THEORIC_##type(size_t id/*TYPE_##type*/);    \
  bool IS_SET_THEORIC_##type(SET_THEORIC_##type *st);             \

GENERATE_UNSIGNED_SET_THEORIC(TYPE_U_CHAR)
GENERATE_UNSIGNED_SET_THEORIC(TYPE_U_INT)
GENERATE_UNSIGNED_SET_THEORIC(TYPE_U_L_INT)
GENERATE_UNSIGNED_SET_THEORIC(TYPE_SIZE_T)



#endif /*__SET_THEORIC_T_C__H*/
