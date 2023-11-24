
#include "set_theoric_t/set_theoric_t.h"

#define GENERATE_SET_THEORIC(type)                                      \
  SET_THEORIC_##type * CREATE_SET_THEORIC_##type(size_t id){            \
    if(id == 0) return NULL;                                            \
    SET_THEORIC_##type *ret_set = malloc(sizeof(SET_THEORIC_##type));   \
    ret_set->id = id;                                                   \
    ret_set->set = malloc(id*sizeof(type));                             \
    for(type i = 0; i < id; ++i) ret_set->set[i]=i;                     \
  return ret_set;                                                       \
  }                                                                     \
                                                                        \
  bool IS_SET_THEORIC_##type(SET_THEORIC_##type *st){                   \
    for(type i = 0; i < st->id; ++i){                                   \
      if(st->set[i] != i) return false;                                 \
    return true;                                                        \
    }                                                                   \
  }                                                                     \

GENERATE_SET_THEORIC(TYPE_U_CHAR)
GENERATE_SET_THEORIC(TYPE_U_INT)
GENERATE_SET_THEORIC(TYPE_U_L_INT)
GENERATE_SET_THEORIC(TYPE_SIZE_T)

