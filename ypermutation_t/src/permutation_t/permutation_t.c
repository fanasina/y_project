#include "permutation_t/permutation_t.h"

#define GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(type)\
  bool IS_PERMUTATION_SET_THEORIC_##type(const PERMUTATION_##type *p){\
    if(p == NULL) return false;\
    size_t size = p->size;\
    type j;\
    size_t *count_array_i = calloc(size, sizeof(size_t));\
    if(count_array_i == NULL){\
      printf("can't alloc count_array_i\n"); \
      return false;\
    }\
    for(size_t i = 0; i < size; ++i){\
      j = p->perm[i];\
      if((COMPARE_N_##type(&j, (type*)&size) >= 0) || count_array_i[j]){\
        free(count_array_i); \
        return false;\
      }\
      ++count_array_i[j];\
    }\
    free(count_array_i);\
    return true; \
  }\


GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_U_CHAR)
GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_U_INT)
GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_U_L_INT)
GENERATE_PERMUTATION_FUNCTIONS_UNSIGNED(TYPE_SIZE_T)

int sign(long int a){
  if (a<0) return -1;
  return 1;
}

#define GENERATE_PERMUTATION_FUNCTIONS(type)\
  PERMUTATION_##type * CREATE_PERMUTATION_##type(size_t size){\
    if (size == 0) return NULL;\
    PERMUTATION_##type *p = malloc(sizeof(PERMUTATION_##type));\
    p->size = size;\
    p->perm = malloc(size * sizeof(type));\
    return p;\
  }\
  PERMUTATION_##type * INIT_PERMUTATION_##type(type *perm, size_t size){\
    if (size == 0) return NULL;\
    PERMUTATION_##type *p = CREATE_PERMUTATION_##type(size);\
    p->perm = perm ; /*malloc(size*sizeof(type));\
    for(size_t i=0;i<size;++i) p->perm[i] = perm[i];*/\
    return p;\
  }\
  PERMUTATION_##type * INIT_COPY_PERMUTATION_##type(type *perm, size_t size){\
    if (size == 0) return NULL;\
    PERMUTATION_##type *p = CREATE_PERMUTATION_##type(size);\
    p->perm = malloc(size*sizeof(type));\
    for(size_t i=0;i<size;++i) p->perm[i] = perm[i];\
    return p;\
  }\
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
    for(size_t i=0; i< size; ++i)\
      PRINT_DEBUG_("sorted_perm[%ld] : %s \n",i, type##_TO_STR(sorted_perm[i]));\
    for(size_t j = 0; j < size; ++j){\
      for(size_t i = 0; i < size; ++i){\
        if(COMPARE_N_##type(&(p->perm[j]), &(sorted_perm[i])) == 0){\
          t_p->perm[j]=i; break;\
        }\
      }\
    }\
    free(sorted_perm);\
    return t_p; \
  }\
\
  bool IS_PERMUTATION_##type(const PERMUTATION_##type *p){\
    if(p == NULL) return false;\
    PERMUTATION_TYPE_SIZE_T *t_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(p);\
    bool ret = IS_PERMUTATION_SET_THEORIC_TYPE_SIZE_T(t_p);\
    free(t_p);\
    return ret; \
  }\
  \
  int signature_##type(const PERMUTATION_##type *p){\
    PERMUTATION_TYPE_SIZE_T *t_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(p);\
    int ss = 1;\
    for (size_t i = 0; i < t_p->size; ++i) {\
      for (size_t j = i + 1; j < t_p->size; ++j) {\
       ss *= sign((long int)(t_p->perm[j]) - (long int)(t_p->perm[i]));/* sign(j - i);*/\
      }\
    }\
    return ss;\
  }\
  \
 \
/*complexité sz*sz/2 */\
size_t TabToPlaceAlgo_##type(const PERMUTATION_##type *p){\
  size_t sz = p->size;\
  PERMUTATION_TYPE_SIZE_T *t_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(p);\
  size_t *tb= t_p->perm;\
  size_t pl;\
  size_t* tPlace = calloc(sz,sizeof(size_t));\
  for (long int i = sz - 1; i >= 0; i--) {\
    pl = 0;\
    for (size_t j = i + 1; j < sz; j++) {\
      if (tb[j] < tb[i]) {\
        pl++;\
      }\
      if (pl == tb[i]) break;\
    }\
    tPlace[tb[i]] = pl;\
  }\
  size_t q = 0;\
  for (size_t i = 0; i < sz;i++) {\
    q = (i + 1) * q + tPlace[i];\
  }\
  return q;\
}\
/*complexité sz*sz/2 */\
size_t TabToPlaceOpt1_##type(const PERMUTATION_##type *p){\
  size_t sz = p->size;\
  PERMUTATION_TYPE_SIZE_T *t_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(p);\
  size_t *tb= t_p->perm;\
  size_t mx;\
  size_t* tPlace = malloc(sz*sizeof(size_t));\
  for (long int i = sz - 1; i >= 0; i--) {\
    if (i == sz - 1) {\
      mx = tb[i];\
      tPlace[mx] = 0;\
    }\
    else if (mx > tb[i]) {\
      size_t pli = 0; /* si c est le plus à droite 0 si pas de superieur à lui, on incremente si on trouve plus petit*/\
      for (long int j = sz - 1; j > i; j--) {\
        if (tb[i] > tb[j]) {\
          pli++;\
        }\
        else if (tb[i] == tb[j]) {\
          PRINT_DEBUG_("%s\n","something wrong here, tb[i]==tb[j]");\
        }\
      }\
      tPlace[tb[i]] = pli;\
    }\
    else if (mx < tb[i]) {\
      mx = tb[i];\
      tPlace[mx] = sz - 1 - i;\
    }\
    else {\
      PRINT_DEBUG_("%s\n","something wrong here, tb[i]==mx");\
\
    }\
  }\
  size_t q = 0;\
  for (long int i = 0; i < sz; i++) {\
    q = (i + 1) * q + tPlace[i];\
  }\
  return q;\
}\
/* complexité sz*(sz+1)*/\
size_t TabToPlaceNotab_##type(const PERMUTATION_##type *p){\
  size_t sz = p->size;\
  PERMUTATION_TYPE_SIZE_T *t_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(p);\
  size_t *tb= t_p->perm;\
  size_t mx = sz - 1;\
  size_t q = 0;\
  size_t pl;\
  for (long int i = 0; i < sz; i++) {\
    size_t j;\
    for (j = 0; j < sz;j++) {\
      if (tb[j] == i) break;\
    }\
    pl = 0;\
    j++;\
    for (;j < sz;j++) {\
      if (tb[j] < i) {\
        pl++;\
      }\
      if (pl == i) break;\
    }\
    q = (i + 1) * q + pl;\
  }\
  return q;\
}\
/*complexité sz*sz/2 */\
PERMUTATION_TYPE_SIZE_T * PlaceToTab_##type(PERMUTATION_##type *p, size_t pl){\
  size_t sz = p->size;\
  /*PERMUTATION_TYPE_SIZE_T *t_p = CREATE_PERMUTATION_TYPE_SIZE_T(sz);*/\
  PERMUTATION_TYPE_SIZE_T *t_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(p);\
  type *save_perm = malloc(sz*sizeof(type));\
  long int *tb= t_p->perm;\
  size_t a = pl;\
  size_t pltbi;\
  for (long int i = 0;i < sz;i++) {\
    save_perm[tb[i]]=p->perm[i];/*to save initial order (rank 0) of p->perm */\
    /*PRINT_DEBUG_("%ld => %s \n",tb[i],type##_TO_STR(p->perm[i]));*/\
    tb[i]=0;\
  }\
\
  for (long int i = sz - 1; i >= 0; i--) {\
    pltbi = a % (i + 1);\
    a /= (i + 1);\
    if (i == sz - 1) {\
      tb[sz - 1 - pltbi] = i;\
    }\
    else {\
      long int lt = 0, j = sz - 1;\
      while (lt < pltbi && j >= 0) {\
        if (tb[j--] < i) {\
          lt++;\
        }\
      }\
      while (tb[j] > i) {\
        j--;\
      }\
      tb[j] = i;\
    }\
  }\
  \
  for (long int i = 0;i < sz;i++) p->perm[i] = save_perm[tb[i]];\
  return t_p;\
}\
\





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
 2,4,7,5 is translate to 0,1,3,2
 PERMUTATION_TYPE_SIZE_T * TRANSLATE_TO_SET_THEORIC_SIZE_T_##type(const PERMUTATION_##type *p );
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
