#ifndef __PERMUTATION_T_C_H__
#define __PERMUTATION_T_C_H__

#include "tools_t/tools_t.h"
#include "set_theoric_t/set_theoric_t.h"

/* struct of permutation, not necessarly set_theoric
 *
 * */



#define GENERATE_PERMUTATION(type)\
  struct PERMUTATION_##type{\
    size_t size;\
    size_t rank;\
    type * perm; \
  };\
\
  typedef struct PERMUTATION_##type PERMUTATION_##type;\
  PERMUTATION_##type * CREATE_PERMUTATION_##type(size_t size);\
  PERMUTATION_##type * INIT_PERMUTATION_##type(type *perm, size_t size);\
  PERMUTATION_##type * INIT_COPY_PERMUTATION_##type(type *perm, size_t size);\
  void free_permut_##type(PERMUTATION_##type * permut);\
  PERMUTATION_TYPE_SIZE_T * TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(const PERMUTATION_##type *p );\
  bool IS_PERMUTATION_##type(const PERMUTATION_##type *p );\
size_t TabToPlaceAlgo_##type(const PERMUTATION_##type *p);\
size_t TabToPlaceOpt1_##type(const PERMUTATION_##type *p);\
size_t TabToPlaceNotab_##type(const PERMUTATION_##type *p);\
PERMUTATION_TYPE_SIZE_T * PlaceToTab_##type(PERMUTATION_##type *p, size_t pl);\

GENERATE_PERMUTATION(TYPE_SIZE_T)
GENERATE_PERMUTATION(TYPE_CHAR)
GENERATE_PERMUTATION(TYPE_U_CHAR)
GENERATE_PERMUTATION(TYPE_INT)
GENERATE_PERMUTATION(TYPE_U_INT)
GENERATE_PERMUTATION(TYPE_L_INT)
GENERATE_PERMUTATION(TYPE_U_L_INT)
GENERATE_PERMUTATION(TYPE_FLOAT)
GENERATE_PERMUTATION(TYPE_DOUBLE)
GENERATE_PERMUTATION(TYPE_L_DOUBLE)
GENERATE_PERMUTATION(TYPE_STRING)

#define GENERATE_FUNCTIONS_UNSIGNED(type)\
  bool IS_PERMUTATION_SET_THEORIC_##type(const PERMUTATION_##type *p);\

GENERATE_FUNCTIONS_UNSIGNED(TYPE_U_CHAR)
GENERATE_FUNCTIONS_UNSIGNED(TYPE_U_INT)
GENERATE_FUNCTIONS_UNSIGNED(TYPE_U_L_INT)
GENERATE_FUNCTIONS_UNSIGNED(TYPE_SIZE_T)



#endif /*__PERMUTATION_T_C_H__*/
