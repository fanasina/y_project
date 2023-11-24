#include "permutation_t/permutation_t.h"

#define GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(type)\
  bool IS_PERMUTATION_SET_THEORIC_##type(const PERMUTATION_##type *p){\
    if(p == NULL) return false;\
    size_t size = p->size;\
    type j;\
    size_t *count_array_i = calloc(size, sizeof(size_t));\
    if(count_array_i == NULL){\
      printf("can't alloc count_array_i\n"); return false;}\
    for(size_t i = 0; i < size; ++i){\
      j = p->perm[i];\
      if((COMPARE_N_##type(&j, (type*)&size) >= 0) || count_array_i[j]){\
        free(count_array_i); return false; }\
      ++count_array_i[j];}\
    free(count_array_i);\
    return true; }\

GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_U_CHAR)
GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_U_INT)
GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_U_L_INT)
GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_SIZE_T)


#define GENERATE_PERMUTATION_FUNCTIONS(type)\
  PERMUTATION_##type * CREATE_PERMUTATION_##type(size_t size){\
    if (size == 0) return NULL;\
    PERMUTATION_##type *p = malloc(sizeof(PERMUTATION_##type));\
    p->size = size;\
    p->perm = malloc(size * sizeof(type));\
    return p; }\
\
  PERMUTATION_TYPE_SIZE_T * TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(const PERMUTATION_##type *p ){\
    if (p == NULL) return NULL;\
    PERMUTATION_TYPE_SIZE_T *t_p = malloc(sizeof(PERMUTATION_TYPE_SIZE_T));\
    size_t size = p->size;\
    t_p->size = size;\
    t_p->perm = malloc(size * sizeof(TYPE_SIZE_T));\
    type *sorted_perm = malloc(size * sizeof(type));\
    COPY_ARRAY_##type(sorted_perm,(const type*)p->perm, size);\
    qsort(sorted_perm, size, sizeof(type), COMPARE_N_##type);\
    size_t *rec_index_visited = malloc(size * sizeof(size_t));\
    size_t cur_rec = 0; bool found_rec;\
    for(size_t i = 0; i < size; ++i){\
      for(size_t j = 0; j < size; ++j){\
        if(COMPARE_N_##type(&(p->perm[j]), &(sorted_perm[i])) == 0){\
          found_rec = false;\
          for(size_t k = 0; k < cur_rec; ++k){\
            if(rec_index_visited[k] == j){\
              found_rec == true; break; } } \
          if(found_rec == false){\
            /*t_p->perm[i] = j;*/\
            t_p->perm[j] = i;\
            rec_index_visited[cur_rec++] = j; \
            break; }\
        }\
      }\
    }\
    free(rec_index_visited);\
    free(sorted_perm);\
    return t_p; \
  }\
\
  bool IS_PERMUTATION_##type(const PERMUTATION_##type *p){\
    if(p == NULL) return false;\
    PERMUTATION_TYPE_SIZE_T *t_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(p);\
    bool ret = IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T(t_p);\
    free(t_p);\
    return ret; }\



GENERATE_PERMUTATION_FUNCTIONS(TYPE_CHAR)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_U_CHAR)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_INT)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_U_INT)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_L_INT)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_U_L_INT)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_SIZE_T)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_FLOAT)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_DOUBLE)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_L_DOUBLE)
GENERATE_PERMUTATION_FUNCTIONS(TYPE_STRING)






/* why TRANSLATE ?
 * 2,7,4,1 is a permutation of 1,2,4,7
 *it is equivalent of 1,3,2,0 in set_theoric(4)=0,1,2,3
 this function calculate the permutation equivalent in set_theoric
 2,4,2,5 is translate to 0,1,0,2
 * */


/* if need optimization in translate
#define GENERATE_UNSIGNED_SIZE_WITH_TYPED(type_unsigned, type)\
  PERMUTATION_##type_unsigned * TRANSLATE_TO_SET_THEORIC_##type_unsigned_##type(PERMUTATION_##type *p ){\
    if (p == NULL) return NULL;\
    PERMUTATION_##type_unsigned *t_p = malloc(sizeof(PERMUTATION_##type_unsigned));\
    type_unsigned size = p->size;\
    t_p->perm = malloc(size * sizeof(type_unsigned));\
    type *sorted_perm = malloc(size * sizeof(type));\
    COPY_ARRAY_##type(sorted_perm, p->perm, size);\
    qsort(sorted_perm, size, sizeof(type), COMPARE_N_##type);\
    type_unsigned *rec_index_visited = malloc(size * sizeof(type_unsigned));\
    type_unsigned cur_rec = 0; bool found_rec;\
    for(type_unsigned i = 0; i < size; ++i){\
      for(type_unsigned j = 0; j < size; ++j){\
        if(COMPARE_N_##type(&(p->perm[j]), &(sorted_perm[i])) == 0){\
          found_rec = false;\
          for(type_unsigned k = 0; k < cur_rec; ++k){\
            if(rec_index_visited[k] == j){\
              found_rec == true; break; } } \
          if(found_rec == false){\
            t_p->perm[i] = j;\
            rec_index_visited[cur++] = j; \
            break; } } } } \
    free(rec_index_visited);\
    free(sorted_perm);\
    return t_p; }\

*/
