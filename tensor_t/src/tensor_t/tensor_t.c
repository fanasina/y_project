#include "tensor_t/tensor_t.h"

void subArray(size_t* dst, size_t* src, size_t debDst, size_t finDst, size_t debSrc) {
    for (size_t i = debDst; i < finDst; i++) {
        dst[i] = src[i + debSrc];
    }
}

void concatArray(size_t* dst, size_t* src0, size_t* src1, size_t debDst, size_t debSrc0, size_t finSrc0, size_t debSrc1, size_t finSrc1) {
    size_t i = debDst;
    for (size_t j = debSrc0; j < finSrc0; j++) {
        dst[i++] = src0[j];
    }
    for (size_t j = debSrc1; j < finSrc1; j++) {
        dst[i++] = src1[j];
    }
}

void printArraySzt(size_t *a, size_t sz,char *msg){
  printf("======== %s ======= size: %ld\n",msg,sz);
  for(size_t i=0; i< sz; ++i)
    printf("[%ld : %ld ] ",i,a[i]);
  printf("\n");
}

int checkContractProdTensorDim(dimension *d0, dimension *d1, ssize_t contractionNumber){
  if((d0->size-contractionNumber <0)||(d1->size-contractionNumber <0)) return 0;
  if(endian){
    ssize_t beginCommonM0=d0->size-contractionNumber;
    for(ssize_t i=0; i<contractionNumber; ++i){
      if(d0->perm[beginCommonM0+i] != d1->perm[i]) return 0;
    }
  }else{
    ssize_t beginCommonM1=d1->size-contractionNumber;
    for(ssize_t i=0; i<contractionNumber; ++i){
      if(d0->perm[i] != d1->perm[beginCommonM1+i]) return 0;
    }
   }
  return 1;
}
/*
bool isLessEqThan(long int a, long int b) { return a <= b; }
bool isLessThan(long int a, long int b) { return a < b; }
bool isGreatEqThan(long int a, long int b) { return a >= b; }
bool isGreatThan(long int a, long int b) { return a > b; }
long int incr(long int i) { return i + 1; }
long int decr(long int i) { return i - 1; }
*/

#define FREE_COORD_\
  free(coord0);\
  free(coord1);\
  free(coord);\

#define FREE_t \
    free( tsub0 );\
    free( tsub1 );\
    free( tDk1 );\
    free( tDk0 );

#define FREE_dM_S_\
  free_dimension(dM0);\
  free_dimension(dM1);\
  free_dimension(dM);\
  free_dimension(dSub0);\
  free_dimension(dSub1);\



#define GEN_FUNC_TENSOR(type)\
  tensor_##type* CREATE_TENSOR_##type(dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    updateRankDim(dim);\
    r_tens->dim = dim;\
    r_tens->x = malloc(sizeof(type)*dim->rank);\
    return r_tens;\
  }\
\
void _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(tensor_##type **M, dimension *dd){\
    if(*M){ \
      if(!is_equal_dim((*M)->dim, dd)){\
        free_tensor_##type(*M);\
        (*M)=CREATE_TENSOR_##type(dd);\
      }else free_dimension(dd); /* because it is not used */\
    }else{\
      (*M)=CREATE_TENSOR_##type(dd);\
    }\
  }\
tensor_##type* init_tensor_head_##type(tensor_##type *troot ,dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    updateRankDim(dim);\
    r_tens->dim = dim;\
    r_tens->x = troot->x;\
    return r_tens;\
  }\
\
 tensor_##type* init_tensor_tail_##type(tensor_##type *troot ,dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    updateRankDim(dim);\
    r_tens->dim = dim;\
    r_tens->x = troot->x + ((troot->dim)->rank - dim->rank);\
    return r_tens;\
  }\
\
\
tensor_##type* init_copy_tensor_head_##type(tensor_##type *troot ,dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    updateRankDim(dim);\
    r_tens->dim = dim;\
    /*r_tens->x = troot->x;*/\
    for(size_t i=0; i<dim->rank;++i)\
      r_tens->x[i]=troot->x[i];\
    return r_tens;\
  }\
\
 tensor_##type* init_copy_tensor_tail_##type(tensor_##type *troot ,dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    updateRankDim(dim);\
    r_tens->dim = dim;\
    /*r_tens->x = troot->x + ((troot->dim)->rank - dim->rank);*/\
    r_tens->x = malloc(sizeof(type)*dim->rank);\
    size_t dRank=(troot->dim)->rank - dim->rank;\
    for(size_t i=0; i<dim->rank;++i)\
      r_tens->x[i]=troot->x[i+dRank];\
    return r_tens;\
  }\
\
\
 tensor_##type* CREATE_TENSOR_FROM_CPY_DIM_##type(dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    r_tens->dim = init_copy_dim(dim->perm,dim->size);\
    r_tens->x = malloc(sizeof(type)*dim->rank);\
    return r_tens;\
  }\
\
tensor_##type* CLONE_TENSOR_##type(tensor_##type *tens){\
  if(tens){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    r_tens->dim = clone_dim(tens->dim);\
    r_tens->x = malloc(sizeof(type) * (tens->dim)->rank);\
    for(size_t i=0; i<(tens->dim)->rank;++i)\
      r_tens->x[i]=tens->x[i];\
    return r_tens;\
  }\
  return NULL;\
}\
\
int copy_tensor_##type(tensor_##type * dst, tensor_##type * src){\
  if(dst!=NULL && src!=NULL){ \
    int diff = dst->dim->rank - src->dim->rank;\
    if(diff == 0) \
      for(size_t i=0; i<(src->dim)->rank;++i)\
        dst->x[i]=src->x[i];\
    return diff;\
    \
  }\
  return -1;\
}\
\
  void free_tensor_##type(tensor_##type *  tens){\
    if(tens){\
      free_dimension(tens->dim);\
      free(tens->x);\
      free(tens);\
    }\
  }\
  void init_random_x_##type(tensor_##type *M, type minR, type maxR,  int randomRange){\
    /*static bool initRandomFirst = true;\
    if(initRandomFirst){ srand(time(NULL)); initRandomFirst = false;}*/\
    int randVal;\
    for(size_t i =0; i<(M->dim)->rank;++i){\
      randVal = xrand() % randomRange;\
      M->x[i]=minR + (maxR-minR)*randVal  / randomRange ;\
    \
    }\
  }\
  tensor_##type * sub_minus_tensor_head_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim){\
    dimension *rdim= rootens->dim;\
    dimension *dS_t = sub_minus_dim_tail(rdim,rdim->size - minuSubdim);\
    if(rankInDim < dS_t->rank){\
      dimension *dS_h = sub_minus_dim_head(rdim,minuSubdim);\
      tensor_##type *ret_ens = malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_h;\
      ret_ens->x = malloc(sizeof(type)*dS_h->rank);\
      if(endian){\
        for(size_t i=0; i<dS_h->rank; ++i){\
            ret_ens->x[i]=rootens->x[i*dS_t->rank + rankInDim];\
          \
        }\
      }else{\
        for(size_t i=0; i<dS_h->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_h->rank * rankInDim];\
        }\
      }\
      return ret_ens;\
    }\
    return NULL;\
  }\
  \
  tensor_##type * sub_minus_tensor_tail_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim){\
    dimension *rdim= rootens->dim;\
    dimension *dS_h = sub_minus_dim_head(rdim,rdim->size - minuSubdim);\
    if(rankInDim < dS_h->rank){\
      dimension *dS_t = sub_minus_dim_tail(rdim,minuSubdim);\
      tensor_##type *ret_ens = malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_t;\
        ret_ens->x = malloc(sizeof(type)*dS_t->rank);\
      if(endian==false){\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i*dS_h->rank + rankInDim];\
        }\
      }else{\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_t->rank * rankInDim];\
        }\
      \
      }\
      return ret_ens;\
    }\
    return NULL;\
  }\
  \
  tensor_##type * sub_tensor_head_##type(tensor_##type *rootens, size_t subdim, size_t rankInDim){\
    dimension *rdim= rootens->dim;\
    dimension *dS_t = sub_dim_tail(rdim,rdim->size - subdim);\
    if(rankInDim < dS_t->rank){\
      dimension *dS_h = sub_dim_head(rdim,subdim);\
      tensor_##type *ret_ens = malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_h;\
        ret_ens->x = malloc(sizeof(type)*dS_h->rank);\
      if(endian){\
        for(size_t i=0; i<dS_h->rank; ++i){\
          ret_ens->x[i]=rootens->x[i*dS_t->rank + rankInDim];\
        }\
      }else{\
        for(size_t i=0; i<dS_h->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_h->rank * rankInDim];\
        }\
      \
      }\
      return ret_ens;\
    }\
    return NULL;\
  }\
  tensor_##type * sub_tensor_tail_##type(tensor_##type *rootens, size_t subdim, size_t rankInDim){ \
    dimension *rdim= rootens->dim;\
    dimension *dS_h = sub_dim_head(rdim,rdim->size - subdim);\
    if(rankInDim < dS_h->rank){\
      dimension *dS_t = sub_dim_tail(rdim,subdim);\
      tensor_##type *ret_ens = malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_t;\
        ret_ens->x = malloc(sizeof(type)*dS_t->rank);\
      if(endian==false){\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i*dS_h->rank + rankInDim];\
        }\
      }else{\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_t->rank * rankInDim];\
        }\
      \
      }\
      return ret_ens;\
    }\
    return NULL;\
  }\
  \
  tensor_##type * sub_copy_minus_tensor_head_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim){\
    dimension *rdim= rootens->dim;\
    dimension *dS_t = sub_copy_minus_dim_tail(rdim,rdim->size - minuSubdim);\
    if(rankInDim < dS_t->rank){\
      dimension *dS_h = sub_copy_minus_dim_head(rdim,minuSubdim);\
      tensor_##type *ret_ens = CREATE_TENSOR_##type(dS_h);\
      /*malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_h;\
      ret_ens->x = malloc(sizeof(type)*dS_h->rank);*/\
      if(endian){\
        /*ret_ens->x = malloc(sizeof(type)*dS_h->rank);\
        */for(size_t i=0; i<dS_h->rank; ++i){\
            ret_ens->x[i]=rootens->x[i*dS_t->rank + rankInDim];\
          /*printf("%ld: [i:%ld] | %ld : [%ld ]\n",dS_t->rank, i,dS_h->rank,i*dS_h->rank + rankInDim);*/\
          \
        }\
      }else{\
        /*ret_ens->x = (rootens->x)+rankInDim*dS_h->rank;*/\
        for(size_t i=0; i<dS_h->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_h->rank * rankInDim];\
        }\
      }\
      free_dimension(dS_t);\
      return ret_ens;\
    }\
    free_dimension(dS_t);\
    return NULL;\
  }\
  \
  tensor_##type * sub_copy_minus_tensor_tail_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim){\
    dimension *rdim= rootens->dim;\
    dimension *dS_h = sub_copy_minus_dim_head(rdim,rdim->size - minuSubdim);\
    if(rankInDim < dS_h->rank){\
      dimension *dS_t = sub_copy_minus_dim_tail(rdim,minuSubdim);\
      tensor_##type *ret_ens = CREATE_TENSOR_##type(dS_t);\
      /*tensor_##type *ret_ens = malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_t;\
      ret_ens->x = malloc(sizeof(type)*dS_t->rank);\
      */if(endian==false){\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i*dS_h->rank + rankInDim];\
        }\
      }else{\
        /*ret_ens->x = (rootens->x)+rankInDim*dS_t->rank;*/\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_t->rank * rankInDim];\
        }\
      \
      }\
      free_dimension(dS_h);\
      return ret_ens;\
    }\
    free_dimension(dS_h);\
    return NULL;\
  }\
  \
  tensor_##type * sub_copy_tensor_head_##type(tensor_##type *rootens, size_t sub_copydim, size_t rankInDim){\
    /*return sub_copy_minus_tensor_head_##type(rootens,rootens->dim->size - sub_copydim, rankInDim);*/\
    dimension *rdim= rootens->dim;\
    dimension *dS_t = sub_copy_dim_tail(rdim,rdim->size - sub_copydim);\
    if(rankInDim < dS_t->rank){\
      dimension *dS_h = sub_copy_dim_head(rdim,sub_copydim);\
      tensor_##type *ret_ens = CREATE_TENSOR_##type(dS_h);\
      /*tensor_##type *ret_ens = malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_h;\
      ret_ens->x = malloc(sizeof(type)*dS_h->rank);\
      */if(endian){\
        for(size_t i=0; i<dS_h->rank; ++i){\
          ret_ens->x[i]=rootens->x[i*dS_t->rank + rankInDim];\
          /*printf("%ld: [i:%ld] | %ld : [%ld ]\n",dS_t->rank, i,dS_h->rank,i*dS_h->rank + rankInDim);*/\
        }\
      }else{\
        /*ret_ens->x = (rootens->x)+rankInDim*dS_h->rank;*/\
        for(size_t i=0; i<dS_h->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_h->rank * rankInDim];\
          /*printf("%ld: [i:%ld] | %ld : [%ld ]\n",dS_t->rank, i,dS_h->rank,i*dS_h->rank + rankInDim);*/\
        }\
      \
      }\
      free_dimension(dS_t);\
      return ret_ens;\
    }\
    free_dimension(dS_t);\
    return NULL;\
  }\
  tensor_##type * sub_copy_tensor_tail_##type(tensor_##type *rootens, size_t sub_copydim, size_t rankInDim){ \
    /*return sub_copy_minus_tensor_tail_##type(rootens,rootens->dim->size - sub_copydim, rankInDim);*/\
    dimension *rdim= rootens->dim;\
    dimension *dS_h = sub_copy_dim_head(rdim,rdim->size - sub_copydim);\
    if(rankInDim < dS_h->rank){\
      dimension *dS_t = sub_copy_dim_tail(rdim,sub_copydim);\
      tensor_##type *ret_ens = CREATE_TENSOR_##type(dS_t);\
      /*tensor_##type *ret_ens = malloc(sizeof(tensor_##type));\
      ret_ens->dim = dS_t;\
      ret_ens->x = malloc(sizeof(type)*dS_t->rank);\
      */if(endian==false){\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i*dS_h->rank + rankInDim];\
          /*printf("%ld: [i:%ld] | %ld : [%ld ]\n",dS_t->rank, i,dS_h->rank,i*dS_h->rank + rankInDim);*/\
        }\
      }else{\
        /*ret_ens->x = (rootens->x)+rankInDim*dS_t->rank;*/\
        for(size_t i=0; i<dS_t->rank; ++i){\
          ret_ens->x[i]=rootens->x[i + dS_t->rank * rankInDim];\
          /*printf("%ld: [i:%ld] | %ld : [%ld ]\n",dS_t->rank, i,dS_h->rank,i*dS_h->rank + rankInDim);*/\
        }\
      \
      }\
      free_dimension(dS_h);\
      return ret_ens;\
    }\
    free_dimension(dS_h);\
    return NULL;\
  }\
  \
void print_tensor_msg_##type(tensor_##type *T,char *msg) {\
  /*size_t j=0 ,k=0*/;\
  size_t *coord = malloc(sizeof(long int)*(T->dim)->size); \
  char *val=NULL;\
  /*char *dimsg=malloc(512);\
  sprintf(dimsg,"(%s)->dim",msg);\
  printDebug_dimension(T->dim,dimsg);\
  */printf("%s\n",msg);\
  long int begin , end /*, beginIter , endIter*/ ;\
  long int (*iter)(long int) ;\
  bool (*cond)(long int, long int) ; \
  if (endian ) {\
        begin = (T->dim->size) - 1; end = 0;\
        iter = decr; cond = isGreatEqThan; \
        /*printf("endian(=true): the bigest index varies first, e.g:  [x0,x1,x2,...,xn] xn is the bigest index \n");*/\
  }else{\
        begin = 0 ; end = (T->dim->size) - 1; \
        iter = incr; cond = isLessEqThan; \
        /*printf("endian(=false): the lowest index varies first, e.g:  [x0,x1,x2,...,xn] x0 is the lowest index \n");*/\
  }\
  for(long int i=0;i<(T->dim)->rank;++i){\
    vCoordFromLin(coord,i,T->dim);\
    if(coord[begin]==0){\
      for(long int j=begin; cond(j,end); j= iter(j) ){\
        if(coord[j]==0) printf("(");\
        else break;\
      }\
    }\
    /*printf(" [");\
    for(size_t k=0; k<(T->dim)->size;++k) printf(" %ld",coord[k]);\
    */val=type##_TO_STR(T->x[i]);\
    printf(" |#%ld]: %s, ",i,val);\
    /*printf(" %s, ",val);*/\
    free(val); val=NULL;\
    /*if(T->x[i] != T->x[i]){\
      printf("\nALERT NAN\n");\
      char c;\
      scanf("%c",&c);\
    }*/\
    if(coord[begin]==(T->dim)->perm[begin]-1){\
      size_t count=0;\
      for(long int j=begin; cond(j,end); j = iter(j)){\
        if(coord[j]==(T->dim)->perm[j]-1) {\
          printf(")"); ++count;\
        }\
        else break;\
      }\
      if(count == (T->dim)->size-1) printf("\n ");\
    }\
  }\
  \
  free(coord);\
  printf("\n");\
  /*free(dimsg);*/\
}\
\
\
void fprint_tensor_##type(char *file_name, tensor_##type *T) {\
  /*size_t j=0,k=0;*/\
  size_t *coord = malloc(sizeof(long int)*(T->dim)->size); \
  char *val=NULL;\
  FILE *fileWrite = fopen(file_name, "w");\
  if(fileWrite == NULL) {\
    printf("error while opening %s\n",file_name);\
    exit(1);\
  }\
  long int begin , end /*, beginIter, endIter*/ ;\
  long int (*iter)(long int) ;\
  bool (*cond)(long int, long int) ; \
  if (endian ) {\
        begin = (T->dim->size) - 1; end = 0;\
        iter = decr; cond = isGreatEqThan; \
        /*fprintf(fileWrite,"endian(=true): the bigest index varies first, e.g:  [x0,x1,x2,...,xn] xn is the bigest index \n");*/\
  }else{\
        begin = 0 ; end = (T->dim->size) - 1; \
        iter = incr; cond = isLessEqThan; \
        /*fprintf(fileWrite,"endian(=false): the lowest index varies first, e.g:  [x0,x1,x2,...,xn] x0 is the lowest index \n");*/\
  }\
    fprintf(fileWrite,"[");\
  for(size_t i=0; i<(T->dim)->size; ++i)\
    fprintf(fileWrite," %ld,", (T->dim)->perm[i]);\
  fprintf(fileWrite,"] \n");\
\
  for(long int i=0;i<(T->dim)->rank;++i){\
    vCoordFromLin(coord,i,T->dim);\
    if(coord[begin]==0){\
      for(long int j=begin; cond(j,end); j= iter(j) ){\
        if(coord[j]==0) fprintf(fileWrite,"(");\
        else break;\
      }\
    }\
    if(T->x[i] != T->x[i]){\
      printf("\nALERT NAN\n");\
      ;\
      return;\
    }\
/*fprintf(fileWrite," [");\
    for(size_t k=0; k<(T->dim)->size;++k) fprintf(fileWrite," %ld,",coord[k]);\
    */val=type##_TO_STR(T->x[i]);\
    fprintf(fileWrite," %s, ",val);\
    free(val); val=NULL;\
    if(coord[begin]==(T->dim)->perm[begin]-1){\
      size_t count=0;\
      for(long int j=begin; cond(j,end); j = iter(j)){\
        if(coord[j]==(T->dim)->perm[j]-1) {\
          fprintf(fileWrite,")"); ++count;\
        }\
        else break;\
      }\
      if(count == (T->dim)->size-1) fprintf(fileWrite,"\n ");\
    }\
  }\
  \
  free(coord);\
  fprintf(fileWrite,"\n");\
  fclose(fileWrite);\
}\
\
size_t sprint_tensor_##type(char **tensorContent,tensor_##type *T, bool withIndex) {\
  if(*tensorContent != NULL) {\
    free(*tensorContent);\
    *tensorContent = NULL;  \
  }\
  size_t sz = ((T->dim)->rank)*(32+ withIndex * 5*(T->dim)->size + 129 );\
  /*printf("malloc %ld char\n",sz);*/\
  *tensorContent = malloc(sz )  ;\
  size_t cur=0;\
  size_t *coord = malloc(sizeof(long int)*(T->dim)->size); \
  char *val=NULL;\
  long int begin , end /*, beginIter, endIter*/ ;\
  long int (*iter)(long int) ;\
  bool (*cond)(long int, long int) ; \
  if (endian ) {\
        begin = (T->dim->size) - 1; end = 0;\
        iter = decr; cond = isGreatEqThan; \
        val=malloc(128);\
        sprintf(val,"endian(=true): the bigest index varies first, e.g:  [x0,x1,x2,...,xn] xn is the bigest index \n");\
        for(size_t c=0;c<strlen(val);++c)\
          (*tensorContent)[cur++]=val[c];\
        free(val); val = NULL;\
  }else{\
        begin = 0 ; end = (T->dim->size) - 1; \
        iter = incr; cond = isLessEqThan; \
        val=malloc(128);\
        sprintf(val,"endian(=false): the lowest index varies first, e.g:  [x0,x1,x2,...,xn] x0 is the lowest index \n");\
        for(size_t c=0;c<strlen(val);++c)\
          (*tensorContent)[cur++]=val[c];\
        free(val); val = NULL;\
  }\
  for(long int i=0;i<(T->dim)->rank;++i){\
    vCoordFromLin(coord,i,T->dim);\
    if(coord[begin]==0){\
      for(long int j=begin; cond(j,end); j= iter(j) ){\
        if(coord[j]==0) /*printf("(")*/(*tensorContent)[cur++]='(';\
        else break;\
      }\
    }\
  if(withIndex){\
    (*tensorContent)[cur++]=' ';\
   (*tensorContent)[cur++]='[';\
    (*tensorContent)[cur++]='{';\
    for(size_t k=0; k<(T->dim)->size;++k) {\
      /*printf(" %ld,",coord[k]);*/\
      val=TYPE_SIZE_T_TO_STR(coord[k]);\
      for(size_t c=0;c<strlen(val);++c){\
        (*tensorContent)[cur++]=' ';\
        (*tensorContent)[cur++]=val[c];\
      }\
      free(val); val = NULL;\
      (*tensorContent)[cur++]=',';\
    }\
    (*tensorContent)[cur++]='}';\
    (*tensorContent)[cur++]='#';\
       val=TYPE_SIZE_T_TO_STR(i);\
    for(size_t c=0;c<strlen(val);++c)\
      (*tensorContent)[cur++]=val[c];\
    free(val); val = NULL;\
    (*tensorContent)[cur++]=']';\
    (*tensorContent)[cur++]=' ';\
  }\
     if(T->x[i] != T->x[i]){\
      /*char *nanStr="ALERT NAN";\
      for(size_t c=0;c<strlen(nanStr);++c)\
        (*tensorContent)[cur++]=nanStr[c];*/\
      printf(" ALERT NAN ");\
      ;\
      /*return strlen(nanStr)*/;\
    }\
    val=type##_TO_STR(T->x[i]);\
    /*printf(" {%ld} %s [",i,val);*/\
    (*tensorContent)[cur++]=' ';\
    for(size_t c=0;c<strlen(val);++c)\
      (*tensorContent)[cur++]=val[c];\
    free(val); val = NULL;\
    (*tensorContent)[cur++]=',';\
    if(coord[begin]==(T->dim)->perm[begin]-1){\
      size_t count=0;\
      for(long int j=begin; cond(j,end); j = iter(j)){\
        if(coord[j]==(T->dim)->perm[j]-1) {/*printf(")"); */ (*tensorContent)[cur++]=')'; ++count;}\
        else break;\
      }\
      if(count == (T->dim)->size-1) {(*tensorContent)[cur++]='\n'; (*tensorContent)[cur++]=' ';}\
    }\
  }\
  \
  free(coord);\
  /*printf("\n");*/(*tensorContent)[cur++]='\n';\
  (*tensorContent)[cur++]='\0';\
  return cur;\
}\
  \
  \
void split_tensor_##type(tensor_##type *Troot, tensor_##type **Tpart1, tensor_##type **Tpart2, size_t pivotSplit, size_t rangeInPivot){\
  size_t sz = (Troot->dim)->size;\
  if(pivotSplit < sz){\
    if( rangeInPivot < (Troot->dim)->perm[pivotSplit]){\
      dimension *dpart1, *dpart2;\
      split_dim_part(Troot->dim, &dpart1, &dpart2, pivotSplit, rangeInPivot);\
      *Tpart1 = init_tensor_head_##type(Troot, dpart1);\
      *Tpart2 = init_tensor_tail_##type(Troot, dpart2);\
    }\
  }\
}  \
void split_copy_tensor_##type(tensor_##type *Troot, tensor_##type **Tpart1, tensor_##type **Tpart2, size_t pivotSplit, size_t rangeInPivot){\
  size_t sz = (Troot->dim)->size;\
  if(pivotSplit < sz){\
    if( rangeInPivot < (Troot->dim)->perm[pivotSplit]){\
      dimension *dpart1, *dpart2;\
      split_dim_part(Troot->dim, &dpart1, &dpart2, pivotSplit, rangeInPivot);\
      *Tpart1 = init_copy_tensor_head_##type(Troot, dpart1);\
      *Tpart2 = init_copy_tensor_tail_##type(Troot, dpart2);\
    }\
  }\
}\
\
void tensorProdNotOpt_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1) {  \
  dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);  \
  tensor_##type *M = *MM; \
    size_t* coord;  \
    coord = malloc(sizeof(size_t)*(dd->size));  \
    size_t* coord0 , lin0;  \
    coord0 = malloc(sizeof(size_t)* M0->dim->size);  \
    size_t* coord1 , lin1;  \
    coord1 = malloc(sizeof(size_t)* M1->dim->size);  \
    for (size_t i = 0; i < dd->rank; i++) {  \
        vCoordFromLin(coord, i, M->dim);  \
        subArray(coord0, coord, 0, M0->dim->size, 0);  \
        subArray(coord1, coord, 0, M1->dim->size, M0->dim->size);  \
          \
        lin0=LineFromCoord(coord0, M0->dim);  \
        lin1=LineFromCoord(coord1, M1->dim);  \
  \
        M->x[i] = M0->x[lin0] * M1->x[lin1];  \
  /*printf(" M->x[%ld] = M0->x[%ld] * M1->x[%ld] ::: %f = %f * %f \n",i,lin0,lin1, M->x[i] , M0->x[lin0] , M1->x[lin1]);*/\
    }  \
    FREE_COORD_ ; \
}  \
\
\
void tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);  \
    tensor_##type *M = *MM; \
    size_t m_idx;\
    for(size_t i=0; i<M0->dim->rank; ++i){\
      for(size_t j=0; j<M1->dim->rank; ++j){\
          if(endian)\
            m_idx= i*M1->dim->rank + j ;\
          else\
            m_idx= i+M0->dim->rank * j ;\
          M->x[m_idx]=M0->x[i]*M1->x[j];\
          /*printf("[%ld|%ld:(%ld,%ld)]",x_idx++,m_idx,i,j);*/\
      }\
    }\
}  \
\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
void tensorContractnProd_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber) {\
   /* if (!checkMatchProdtensor(M0->dim, M1->dim, contractionNumber)) {\
        prsize_tf("Deep = %d\n", contractionNumber);\
    }*/\
    if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
        printDebug_dimension(M0->dim, "M0 dim");\
        printDebug_dimension(M1->dim, "M1 dim");\
        getchar();\
    }\
\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    /*printArraySzt(tsub0,len0,"tsub0");\
    printArraySzt(tsub1,len1,"tsub1");\
    printArraySzt(tDk0,contractionNumber,"tDk0");\
    printArraySzt(tDk1,contractionNumber,"tDk1");*/\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
  /*printDebug_dimension(dSub0,"dSub0");\
  printDebug_dimension(dSub1,"dSub1");\
  printDebug_dimension(dM0,"dM0");\
  printDebug_dimension(dM1,"dM1");*/\
    dimension *dM;\
    min_copy_dimension(&dM, dM0, dM1);\
  /*printDebug_dimension(dM,"dM");*/\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
  /*printDebug_dimension(dd,"dd");*/\
    updateRankDim(dd);\
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);\
    tensor_##type *M= *MM;\
\
   \
\
    size_t a0_id, a1_id, n0_id, n1_id;\
    for (size_t i = 0; i < M->dim->rank; i++) {\
        if(endian){\
          a0_id=i/dSub1->rank;\
          a1_id=i%dSub1->rank;\
        }\
        else{\
          a0_id=i%dSub0->rank;\
          a1_id=i/dSub0->rank;\
        }\
        M->x[i] = 0;\
        for (size_t k = 0; k < dM->rank; k++) {\
          if(endian){\
            n0_id= a0_id*dM->rank + k;\
            n1_id= a1_id + dSub1->rank * k;\
          }\
          else{\
            n0_id= a0_id + dSub0->rank * k;\
            n1_id= a1_id*dM->rank + k;\
          }\
            M->x[i] += M0->x[n0_id] * M1->x[n1_id];\
            \
        }\
    }\
    FREE_dM_S_ \
}\
\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
void tensorContractnProdOpt0_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber) {\
   /* if (!checkMatchProdtensor(M0->dim, M1->dim, contractionNumber)) {\
        prsize_tf("Deep = %d\n", contractionNumber);\
    }*/\
    if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
        printDebug_dimension(M0->dim, "M0 dim");\
        printDebug_dimension(M1->dim, "M1 dim");\
        getchar();\
    }\
\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    /*printArraySzt(tsub0,len0,"tsub0");\
    printArraySzt(tsub1,len1,"tsub1");\
    printArraySzt(tDk0,contractionNumber,"tDk0");\
    printArraySzt(tDk1,contractionNumber,"tDk1");*/\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
  /*printDebug_dimension(dSub0,"dSub0");\
  printDebug_dimension(dSub1,"dSub1");\
  printDebug_dimension(dM0,"dM0");\
  printDebug_dimension(dM1,"dM1");*/\
    dimension *dM;\
    min_copy_dimension(&dM, dM0, dM1);\
  /*printDebug_dimension(dM,"dM");*/\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
  /*printDebug_dimension(dd,"dd");*/\
    updateRankDim(dd);\
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);\
    tensor_##type *M= *MM;\
\
   \
\
    size_t a0_id, a1_id, n0_id, n1_id;\
    for (size_t i = 0; i < M->dim->rank; i++) {\
        if(endian){\
          a0_id=i/dSub1->rank;\
          a1_id=i%dSub1->rank;\
          n0_id=a0_id*dM->rank ;\
          n1_id= a1_id ;\
        }\
        else{\
          a0_id=i%dSub0->rank;\
          a1_id=i/dSub0->rank;\
          n1_id= a1_id*dM->rank ;\
          n0_id= a0_id ;\
        }\
        M->x[i] = 0;\
        for (size_t k = 0; k < dM->rank; k++) {\
          if(endian){\
            /*n0_id= a0_id*dM->rank + k;*/\
            /*n1_id= a1_id + dSub1->rank * k;*/\
            /*M->x[i] += M0->x[begin0++] * M1->x[n1_id];*/\
            M->x[i] += M0->x[n0_id++] * M1->x[n1_id];\
            n1_id +=dSub1->rank ;\
          }\
          else{\
            /*n0_id= a0_id + dSub0->rank * k;*/\
            /*n1_id= a1_id*dM->rank + k;*/\
            /*M->x[i] += M0->x[n0_id] * M1->x[begin1++];*/\
            M->x[i] += M0->x[n0_id] * M1->x[n1_id++];\
            n0_id += dSub0->rank ;\
          }\
            \
        }\
    }\
    FREE_dM_S_ \
}\
\
struct arg_Prod_##type{\
  type *M0x;\
  type *M1x;\
  type *Mx;\
  size_t beginRange;\
  size_t endRange;\
  size_t MRank;\
};\
void* runProd_thread_##type(void *arg){\
  struct arg_Prod_##type *arg_t = arg;\
  size_t a0_id, a1_id;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        if(endian){\
          a0_id=i / arg_t->MRank;\
          a1_id=i % arg_t->MRank;\
        }\
        else{\
          a0_id=i % arg_t->MRank;\
          a1_id=i / arg_t->MRank;\
        }\
        arg_t->Mx[i] = arg_t->M0x[a0_id] * arg_t->M1x[a1_id];\
   }\
  return 0;\
}\
\
\
void tensorProdThread_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);  \
    tensor_##type *M = *MM; \
    \
    \
  pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
  struct arg_Prod_##type **arg_th = malloc( nbthread * sizeof(struct arg_Prod_##type *));\
\
  for(size_t i = 0; i < nbthread; ++i){\
    arg_th[i]=malloc(sizeof(struct arg_Prod_##type));\
    arg_th[i]->M0x=M0->x;\
    arg_th[i]->M1x=M1->x;\
    arg_th[i]->Mx=M->x;\
    arg_th[i]->beginRange = i*(M->dim->rank)/nbthread ;\
    arg_th[i]->endRange = (i+1)*(M->dim->rank)/nbthread ;\
    /*if(i < nbthread - 1 ) arg_th[i]->endRange = (i+1)*(M->dim->rank)/nbthread ;\
    else arg_th[i]->endRange = M->dim->rank ;\
    */if(endian){\
      arg_th[i]->MRank = M1->dim->rank;\
    }\
    else{\
      arg_th[i]->MRank = M0->dim->rank;\
    }\
    pthread_create(&thrd[i], NULL, runProd_thread_##type, (void*)arg_th[i]);\
  }\
\
  for(size_t i=0; i< nbthread; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
}  \
\
struct arg_Pro2d_##type{\
  type *M0x;\
  type *M1x;\
  type *Mx;\
  size_t beginRange;\
  size_t endRange;\
  size_t M0Rank;\
  size_t M1Rank;\
};\
void* runProd_thread2d_##type(void *arg){\
  struct arg_Pro2d_##type *arg_t = arg;\
  size_t k;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
      for (size_t j = 0; j < arg_t->M1Rank; j++) {\
        if(endian){\
          k = i * arg_t->M1Rank + j;\
        }\
        else{\
          k =i + arg_t->M0Rank * j ;\
        }\
        arg_t->Mx[k] = arg_t->M0x[i] * arg_t->M1x[j];\
      }\
   }\
  return 0;\
}\
\
void tensorProdThrea2d_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);  \
    tensor_##type *M = *MM; \
    \
    \
  pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
  struct arg_Pro2d_##type **arg_th = malloc( nbthread * sizeof(struct arg_Pro2d_##type *));\
\
  for(size_t i = 0; i < nbthread; ++i){\
    arg_th[i]=malloc(sizeof(struct arg_Pro2d_##type));\
    arg_th[i]->M0x=M0->x;\
    arg_th[i]->M1x=M1->x;\
    arg_th[i]->Mx=M->x;\
    arg_th[i]->beginRange = i*(M0->dim->rank)/nbthread ;\
    arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
    /*if(i < nbthread - 1 ) arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
    else arg_th[i]->endRange = M0->dim->rank ;\
    */arg_th[i]->M1Rank = M1->dim->rank;\
      arg_th[i]->M0Rank = M0->dim->rank;\
    pthread_create(&thrd[i], NULL, runProd_thread2d_##type, (void*)arg_th[i]);\
  }\
\
  for(size_t i=0; i< nbthread; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
}  \
\
struct arg_ProdContract_##type{\
  type *M0x;\
  type *M1x;\
  type *Mx;\
  size_t beginRange;\
  size_t endRange;\
  size_t dSubRank;\
  size_t dMRank;\
};\
void* runProdContract_thread_##type(void *arg){\
  struct arg_ProdContract_##type *arg_t = arg;\
  size_t a0_id, a1_id, n0_id, n1_id;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        if(endian){\
          a0_id=i/ arg_t->dSubRank;\
          a1_id=i% arg_t->dSubRank;\
        }\
        else{\
          a0_id=i% arg_t->dSubRank;\
          a1_id=i/ arg_t->dSubRank;\
        }\
        arg_t->Mx[i] = 0;\
        for (size_t k = 0; k < arg_t->dMRank; k++) {\
          if(endian){\
            n0_id= a0_id * arg_t->dMRank + k;\
            n1_id= a1_id + arg_t->dSubRank * k;\
          }\
          else{\
            n0_id= a0_id + arg_t->dSubRank * k;\
            n1_id= a1_id * arg_t->dMRank + k;\
          }\
            arg_t->Mx[i] += arg_t->M0x[n0_id] * arg_t->M1x[n1_id];\
        }\
    }\
  return 0;\
}\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
\
void tensorContractnProdThread_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread) {\
    if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
        printDebug_dimension(M0->dim, "M0 dim");\
        printDebug_dimension(M1->dim, "M1 dim");\
        getchar();\
    }\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
    dimension *dM;\
    min_copy_dimension(&dM, dM0, dM1);\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
    updateRankDim(dd);\
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);\
    tensor_##type *M= *MM;\
\
\
    \
  pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
  struct arg_ProdContract_##type **arg_th = malloc( nbthread * sizeof(struct arg_ProdContract_##type *));\
\
  for(size_t i = 0; i < nbthread; ++i){\
    arg_th[i]=malloc(sizeof(struct arg_ProdContract_##type));\
    arg_th[i]->M0x=M0->x;\
    arg_th[i]->M1x=M1->x;\
    arg_th[i]->Mx=M->x;\
    arg_th[i]->beginRange = i*(M->dim->rank)/nbthread ;\
    if(i < nbthread - 1 ) arg_th[i]->endRange = (i+1)*(M->dim->rank)/nbthread ;\
    else arg_th[i]->endRange = M->dim->rank ;\
    if(endian){\
      arg_th[i]->dSubRank = dSub1->rank;\
    }\
    else{\
      arg_th[i]->dSubRank = dSub0->rank;\
    }\
    arg_th[i]->dMRank = dM->rank;\
    pthread_create(&thrd[i], NULL, runProdContract_thread_##type, (void*)arg_th[i]);\
  }\
\
  for(size_t i=0; i< nbthread; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
  FREE_dM_S_ ; \
}\
\
\
void* runProdContractOpt0_thread_##type(void *arg){\
  struct arg_ProdContract_##type *arg_t = arg;\
  size_t a0_id, a1_id, n0_id, n1_id;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        if(endian){\
          a0_id=i/ arg_t->dSubRank;\
          a1_id=i% arg_t->dSubRank;\
            n0_id= a0_id * arg_t->dMRank ;\
            n1_id= a1_id ;\
        }\
        else{\
          a0_id=i% arg_t->dSubRank;\
          a1_id=i/ arg_t->dSubRank;\
            n0_id= a0_id ;\
            n1_id= a1_id * arg_t->dMRank ;\
        }\
        arg_t->Mx[i] = 0;\
        for (size_t k = 0; k < arg_t->dMRank; k++) {\
          if(endian){\
            arg_t->Mx[i] += arg_t->M0x[n0_id++] * arg_t->M1x[n1_id];\
            n1_id += arg_t->dSubRank ;\
          }\
          else{\
            arg_t->Mx[i] += arg_t->M0x[n0_id] * arg_t->M1x[n1_id];\
            n0_id += arg_t->dSubRank ;\
          }\
        }\
    }\
  return 0;\
}\
\
\
void tensorContractnProdThreadOpt0_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread) {\
    if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
        printDebug_dimension(M0->dim, "M0 dim");\
        printDebug_dimension(M1->dim, "M1 dim");\
        getchar();\
    }\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
    dimension *dM;\
    min_copy_dimension(&dM, dM0, dM1);\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
    updateRankDim(dd);\
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);\
    tensor_##type *M= *MM;\
\
\
    \
  pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
  struct arg_ProdContract_##type **arg_th = malloc( nbthread * sizeof(struct arg_ProdContract_##type *));\
\
  for(size_t i = 0; i < nbthread; ++i){\
    arg_th[i]=malloc(sizeof(struct arg_ProdContract_##type));\
    arg_th[i]->M0x=M0->x;\
    arg_th[i]->M1x=M1->x;\
    arg_th[i]->Mx=M->x;\
    arg_th[i]->beginRange = i*(M->dim->rank)/nbthread ;\
    if(i < nbthread - 1 ) arg_th[i]->endRange = (i+1)*(M->dim->rank)/nbthread ;\
    else arg_th[i]->endRange = M->dim->rank ;\
    if(endian){\
      arg_th[i]->dSubRank = dSub1->rank;\
    }\
    else{\
      arg_th[i]->dSubRank = dSub0->rank;\
    }\
    arg_th[i]->dMRank = dM->rank;\
    pthread_create(&thrd[i], NULL, runProdContractOpt0_thread_##type, (void*)arg_th[i]);\
  }\
\
  for(size_t i=0; i< nbthread; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
  FREE_dM_S_ ; \
}\
\
struct arg_Pro2dContract_##type{\
  type *M0x;\
  type *M1x;\
  type *Mx;\
  size_t beginRange;\
  size_t endRange;\
  size_t dMRank;\
  size_t dSub0Rank;\
  size_t dSub1Rank;\
};\
\
void* runPro2dContract_thread_##type(void *arg){\
  struct arg_Pro2dContract_##type *arg_t = arg;\
  size_t n0_id, n1_id, l;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
      for (size_t j = 0; j < arg_t->dSub1Rank; j++) {\
        if(endian)\
          l = j + arg_t->dSub1Rank * i;\
        else\
          l = j * arg_t->dSub0Rank + i;\
        arg_t->Mx[l] = 0;\
        for (size_t k = 0; k < arg_t->dMRank; k++) {\
          if(endian){\
            n0_id= i * arg_t->dMRank + k;\
            n1_id= j + arg_t->dSub1Rank * k;\
          }\
          else{\
            n0_id= i + arg_t->dSub0Rank * k;\
            n1_id= j * arg_t->dMRank + k;\
          }\
            arg_t->Mx[l] += arg_t->M0x[n0_id] * arg_t->M1x[n1_id];\
        }\
      }\
    }\
  return 0;\
}\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
void tensorContractnPro2dThread_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread) {\
    /*if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
    }*/\
    if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
        printDebug_dimension(M0->dim, "M0 dim");\
        printDebug_dimension(M1->dim, "M1 dim");\
        getchar();\
    }\
\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
    dimension *dM;\
    min_copy_dimension(&dM, dM0, dM1);\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
    updateRankDim(dd);\
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);\
    tensor_##type *M= *MM;\
\
\
    \
  pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
  struct arg_Pro2dContract_##type **arg_th = malloc( nbthread * sizeof(struct arg_Pro2dContract_##type *));\
\
  for(size_t i = 0; i < nbthread; ++i) {\
    arg_th[i] = malloc(sizeof(struct arg_Pro2dContract_##type));\
    arg_th[i]->M0x=M0->x;\
    arg_th[i]->M1x=M1->x;\
    arg_th[i]->Mx=M->x;\
    arg_th[i]->beginRange = i*(dSub0->rank)/nbthread ;\
    arg_th[i]->endRange = (i+1)*(dSub0->rank)/nbthread ;\
    arg_th[i]->dSub1Rank = dSub1->rank;\
    arg_th[i]->dSub0Rank = dSub0->rank;\
    arg_th[i]->dMRank = dM->rank;\
    pthread_create(&thrd[i], NULL, runPro2dContract_thread_##type, (void*)arg_th[i]);\
  }\
\
  for(size_t i=0; i< nbthread; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
  FREE_dM_S_ ; \
}\
\
void* runPro2dContractOpt0_thread_##type(void *arg){\
  struct arg_Pro2dContract_##type *arg_t = arg;\
  size_t n0_id, n1_id, l;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
      for (size_t j = 0; j < arg_t->dSub1Rank; j++) {\
        if(endian){\
          l = j + arg_t->dSub1Rank * i;\
            n0_id= i * arg_t->dMRank ;\
            n1_id= j ;\
        }else{\
          l = j * arg_t->dSub0Rank + i;\
            n0_id= i ;\
            n1_id= j * arg_t->dMRank ;\
        }\
        arg_t->Mx[l] = 0;\
        for (size_t k = 0; k < arg_t->dMRank; k++) {\
          if(endian){\
            /*n0_id= i * arg_t->dMRank + k;\
            n1_id= j + arg_t->dSub1Rank * k;*/\
            arg_t->Mx[l] += arg_t->M0x[n0_id++] * arg_t->M1x[n1_id];\
            n1_id += arg_t->dSub1Rank ;\
          }\
          else{\
            /*n0_id= i + arg_t->dSub0Rank * k;\
            n1_id= j * arg_t->dMRank + k;*/\
            arg_t->Mx[l] += arg_t->M0x[n0_id] * arg_t->M1x[n1_id];\
            n0_id += arg_t->dSub0Rank ;\
          }\
        }\
      }\
    }\
  return 0;\
}\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
void tensorContractnPro2dThreadOpt0_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread) {\
    /*if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
    }*/\
    if(checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)==0){\
      printf("checkContractProdTensorDim %ld contractionNumber\n", contractionNumber);\
        printDebug_dimension(M0->dim, "M0 dim");\
        printDebug_dimension(M1->dim, "M1 dim");\
        getchar();\
    }\
\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
    dimension *dM;\
    min_copy_dimension(&dM, dM0, dM1);\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
    updateRankDim(dd);\
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);\
    tensor_##type *M= *MM;\
\
\
    \
  pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
  struct arg_Pro2dContract_##type **arg_th = malloc( nbthread * sizeof(struct arg_Pro2dContract_##type *));\
\
  for(size_t i = 0; i < nbthread; ++i) {\
    arg_th[i] = malloc(sizeof(struct arg_Pro2dContract_##type));\
    arg_th[i]->M0x=M0->x;\
    arg_th[i]->M1x=M1->x;\
    arg_th[i]->Mx=M->x;\
    arg_th[i]->beginRange = i*(dSub0->rank)/nbthread ;\
    arg_th[i]->endRange = (i+1)*(dSub0->rank)/nbthread ;\
    arg_th[i]->dSub1Rank = dSub1->rank;\
    arg_th[i]->dSub0Rank = dSub0->rank;\
    arg_th[i]->dMRank = dM->rank;\
    pthread_create(&thrd[i], NULL, runPro2dContractOpt0_thread_##type, (void*)arg_th[i]);\
  }\
\
  for(size_t i=0; i< nbthread; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
  FREE_dM_S_ ; \
}\
void tensorContractnProdNotOpt_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber) {\
    if (!checkContractProdTensorDim(M0->dim, M1->dim, contractionNumber)) {\
        printf("error Deep = %ld\n", contractionNumber);\
        printDebug_dimension(M0->dim, "M0 dim");\
        printDebug_dimension(M1->dim, "M1 dim");\
        getchar();\
    }\
    size_t len0 = M0->dim->size - contractionNumber;\
    size_t len1 = M1->dim->size - contractionNumber;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *contractionNumber);\
    size_t* tDk0 = malloc(sizeof(size_t) *contractionNumber);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, contractionNumber);\
    subArray(tDk1, M1->dim->perm, 0, contractionNumber, 0);\
    subArray(tDk0, M0->dim->perm, 0, contractionNumber, len0);\
    /*printArraySzt(tsub0,len0,"tsub0");\
    printArraySzt(tsub1,len1,"tsub1");\
    printArraySzt(tDk0,contractionNumber,"tDk0");\
    printArraySzt(tDk1,contractionNumber,"tDk1");*/\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, contractionNumber);\
    dimension *dM0 = init_dim(tDk0, contractionNumber);\
  /*printDebug_dimension(dSub0,"dSub0");\
  printDebug_dimension(dSub1,"dSub1");\
  printDebug_dimension(dM0,"dM0");\
  printDebug_dimension(dM1,"dM1");*/\
    dimension *dM;\
    min_copy_dimension(&dM, dM0, dM1);\
  /*printDebug_dimension(dM,"dM");*/\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
  /*printDebug_dimension(dd,"dd");*/\
    updateRankDim(dd);\
    _RECREATE_TENSOR_IF_NOT_THE_SAME_DIM_OR_NULL_##type(MM,dd);\
    tensor_##type *M= *MM;\
\
    size_t* coord;\
    coord = malloc(sizeof(size_t)* M->dim->size);\
\
    size_t* coord0 , lin0;\
    coord0 = malloc(sizeof(size_t)* len0);\
    size_t* coord1, lin1;\
    coord1 = malloc(sizeof(size_t)* len1);\
\
    size_t* coordM0 ;\
    coordM0 = malloc(sizeof(size_t)* M0->dim->size);\
    size_t* coordM1 ;\
    coordM1 = malloc(sizeof(size_t)* M1->dim->size);\
\
    size_t* Koord ;\
    Koord = malloc(sizeof(size_t)* contractionNumber);\
\
    for (size_t i = 0; i < M->dim->rank; i++) {\
        vCoordFromLin(coord, i, M->dim);\
        subArray(coord0, coord, 0, len0, 0);\
        subArray(coord1, coord, 0, len1, len0);\
        M->x[i] = 0;\
        for (size_t k = 0; k < dM->rank; k++) {\
            vCoordFromLin(Koord, k, dM);\
            concatArray(coordM0, coord0, Koord, 0, 0, len0, 0, contractionNumber);\
            concatArray(coordM1, Koord, coord1, 0, 0, contractionNumber, 0, len1);\
            lin0 = LineFromCoord(coordM0, M0->dim);\
            lin1 = LineFromCoord(coordM1, M1->dim);\
            M->x[i] += M0->x[lin0] * M1->x[lin1];\
          /*printf("M[%ld]:%f += M0[%ld]:%f * M1[%ld]:%f | ",i,M->x[i],lin0,M0->x[lin0],lin1,M1->x[lin1]);*/\
          /*printf("k:%ld |i:%ld |lin0:%ld | lin1:%ld | ",k,i,lin0,lin1);*/\
        }\
      /*printf("\n");*/\
    }\
    FREE_COORD_ ; \
    free(coordM0);\
    free(coordM1);\
    free(Koord); \
    FREE_dM_S_ ; \
}\
\
/* dot product = of 2 tensors same dimensions M0, M1, dim0, dim1 == contract (dim0 size) product of M0' M1' of dim0' and dim1' / dim0->perm = [1, dim0-> perm] and  dim1'->perm = [dim1->perm, 1] */ \
type scalarProduct_dep_contractProd_##type(tensor_##type *M0, tensor_##type *M1, size_t nbthreads ,void (*tensorContractVar)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread )){\
  type ret = 0;\
  if(is_equal_dim(M0->dim, M1->dim)){/* */\
    dimension * d0 = create_dim(M0->dim->size + 1);\
    dimension * d1 = create_dim(M1->dim->size + 1);\
    size_t i;\
    d0->perm[0] = 1;\
    for(i=0; i<M0->dim->size; ++i) d0->perm[i+1] = M0->dim->perm[i];\
    for(i=0; i<M1->dim->size; ++i) d1->perm[i] = M1->dim->perm[i];\
    d1->perm[i] = 1;\
    tensor_##type *M_0=CREATE_TENSOR_##type(d0);\
    tensor_##type *M_1=CREATE_TENSOR_##type(d1);\
    copy_tensor_##type(M_0,M0);\
    copy_tensor_##type(M_1,M1);\
    tensor_##type *M_=NULL;\
    tensorContractVar(&M_,M_0,M_1,M0->dim->size,nbthreads);\
    ret = M_->x[0];\
    free_tensor_##type(M_0);\
    free_tensor_##type(M_1);\
    free_tensor_##type(M_);\
  }\
  return ret;\
}\
\
type scalarProduct_0_##type(tensor_##type *M0, tensor_##type *M1){\
  return scalarProduct_dep_contractProd_##type(M0,M1,4,tensorContractnProdThread_##type);\
\
}\
\
/*format_file: [dim]((x,x,a)(a,x,a)) | example:[2,3,4](((a0,b0,c0,d0)(a1,b1,c1,d1)(a2,b2,c2,d2))((e0,f0,g0,h0)(e1,f1,g1,h1)(e2,f2,g2,h2)))*/\
tensor_##type * parseInput_withDim_to_tensor_##type(char *input){\
  tensor_##type *tens ;\
  size_t len = strlen(input);\
  list_perm_in_dim *l_p=NULL;\
  size_t ss;\
  char *ttmp=input;\
  char *ppEnd="[";\
  bool size_unknown=false; \
  for(size_t i=0; i<len ; ++i){\
    if(input[i]==']') break;\
    if((input[i]=='*') ||(input[i]=='_')){ size_unknown =true; break;}\
  }\
  while(ppEnd && (ppEnd[0] !=']') ){\
    ss = strtoul(ttmp, &ppEnd, 10);\
    while(ttmp == ppEnd && ppEnd[0] !=']'){\
      ttmp++;\
      ss = strtoul(ttmp, &ppEnd, 10);\
    }\
    if(ppEnd !=ttmp )\
      append_in_list_perm(&l_p,ss);\
      /*printf("ss: %ld\n",ss);*/\
    ttmp=ppEnd;\
  }\
  dimension *dim=create_dim_from_list_perm(l_p);\
  /*printf("ppEnd = %s\n",ppEnd);*/\
\
  ttmp++; ppEnd++;\
\
  if(size_unknown == false){\
    tens = CREATE_TENSOR_##type(dim);\
  \
    size_t i=0;\
    type x;\
    while(ppEnd && (ppEnd[0] !='\0') && i<dim->rank){\
      x = strto_##type(ttmp, &ppEnd);\
      while(ttmp == ppEnd && ppEnd[0] !='\0'){\
        ttmp++;\
        x = strto_##type(ttmp, &ppEnd);\
      }\
      if(ppEnd[0]!='\0')\
        (tens)->x[i] = x;\
        /*printf("d: %lf\n",d);*/\
      ttmp=ppEnd;\
      ++i;\
    }\
  }\
  else{\
    array_chainlist_##type *l_a=NULL;\
    type x;\
    while(ppEnd && (ppEnd[0] !='\0')){\
      x = strto_##type(ttmp, &ppEnd);\
      while(ttmp == ppEnd && ppEnd[0] !='\0'){\
        ttmp++;\
        x = strto_##type(ttmp, &ppEnd);\
      }\
      /*if(ppEnd[0]!='\0')*/ \
      if(ppEnd != ttmp)\
        append_array_chainlist_##type(&l_a, x);\
      /*printf("-- x: %f\n",x);*/\
      ttmp=ppEnd;\
    }\
    \
    tens = create_tensor_from_list_array_##type(l_a,dim);\
    free_dimension(dim);\
    free_array_chainlist_##type(l_a);\
  }\
  free_list_perm_in_dim(l_p);\
  return tens;\
}\
\
\
/*format_file: [*,dim1,dim2]((x,x,a)(x,a))... | example:[2,(2,3),4](((a0,b0,c0,)((a1,b1,c1))((a2,b2,c2,d2))((e0,f0,g0)(e1,f1,g1)(e2,f2,g2,h2))) ==[2,2,3][2,4]*/\
void parseInputOutput_withDim_to_tensors_##type(tensor_##type **Tpart1, tensor_##type **Tpart2, char *input, size_t pivotSplit){\
  /*tensor_##type *tens ;*/\
  size_t len = strlen(input);\
  list_perm_in_dim *l_p=NULL;\
  size_t ss;\
  char *ttmp=input;\
  char *ppEnd="[";\
  bool size_unknown=false; \
  for(size_t i=0; i<len ; ++i){\
    if(input[i]==']') break;\
    if((input[i]=='*') ||(input[i]=='_')){ size_unknown =true; break;}\
  }\
  while(ppEnd && (ppEnd[0] !=']') ){\
    ss = strtoul(ttmp, &ppEnd, 10);\
    while(ttmp == ppEnd && ppEnd[0] !=']'){\
      ttmp++;\
      ss = strtoul(ttmp, &ppEnd, 10);\
    }\
    if(ppEnd !=ttmp )\
      append_in_list_perm(&l_p,ss);\
      /*printf("ss: %ld\n",ss);*/\
    ttmp=ppEnd;\
  }\
  dimension *dim=create_dim_from_list_perm(l_p);\
  /*printf("ppEnd = %s\n",ppEnd);*/\
\
  ttmp++; ppEnd++;\
\
  if(size_unknown == false){\
    /*dimension *dim1 = create_dim(dim->size-1);\
    dimension *ddim1 = create_dim(dim->size-2);\
    dimension *ddim2 = create_dim(dim->size-2);\
    dimension *dim2 = create_dim(2);\
    */dimension *dim1 = create_dim(dim->size-pivotSplit);\
    dimension *ddim1 = create_dim(dim->size-pivotSplit-1);\
    dimension *ddim2 = create_dim(pivotSplit);\
    dimension *dim2 = create_dim(pivotSplit+1);\
    for(size_t i=0;i<dim1->size;++i) dim1->perm[i] = dim->perm[i];\
    for(size_t i=0;i<ddim1->size;++i) ddim1->perm[i] = dim->perm[i+1];\
    for(size_t i=0;i<ddim2->size;++i) ddim2->perm[i] = dim->perm[ dim->size - pivotSplit + i];\
    dim2->perm[0] = dim->perm[0];\
    for(size_t i=1;i<dim2->size;++i) dim2->perm[i] = ddim2->perm[i-1];\
    /*dim2->perm[1] = dim->perm[dim->size - 1];*/\
    updateRankDim(dim1);\
    updateRankDim(ddim1);\
    updateRankDim(ddim2);\
    updateRankDim(dim2);\
    *Tpart1 = CREATE_TENSOR_##type(dim1);\
    *Tpart2 = CREATE_TENSOR_##type(dim2);\
  \
    size_t i1=0,i=0,j=0,i2=0;\
    bool filled1=false,filled2=false;\
    type x;\
    while(ppEnd && (ppEnd[0] !='\0') && j<dim2->rank){\
      x = strto_##type(ttmp, &ppEnd);\
      while(ttmp == ppEnd && ppEnd[0] !='\0'){\
        ttmp++;\
        x = strto_##type(ttmp, &ppEnd);\
      }\
      if(ppEnd[0]!='\0'){\
        if(!filled1){\
          ++i1;\
          (*Tpart1)->x[i++] = x;\
          /*printf("++ x: %f, i1:%ld , rkn1: %ld\n",x,i1,ddim1->rank);\
          */if(i1 == ddim1->rank){\
            filled1=true;\
            i1=0;\
            filled2=false;\
          }\
        }else{\
          if(!filled2){\
            ++i2;\
            (*Tpart2)->x[j++] = x;\
            /*printf("-----++ x: %f, i2:%ld , rknr: %ld\n",x,i2,ddim2->rank);\
            */if(i2 == ddim2->rank){\
              filled2=true;\
              i2=0;\
              filled1=false;\
            }\
          }\
          \
        }\
        /*printf("d: %lf\n",d);*/\
      }\
      ttmp=ppEnd;\
    }\
    free_dimension(ddim1);\
    free_dimension(ddim2);\
  }\
  else{\
    /*dimension *ddim1 = create_dim(dim->size-1);\
    dimension *ddim2 = create_dim(1);\
    for(size_t i=0;i<ddim1->size;++i) ddim1->perm[i] = dim->perm[i];\
    ddim2->perm[0] = dim->perm[dim->size - 1];\
    */dimension *ddim1 = create_dim(dim->size-pivotSplit);\
    dimension *ddim2 = create_dim(pivotSplit);\
    for(size_t i=0;i<ddim1->size;++i) ddim1->perm[i] = dim->perm[i];\
    for(size_t i=0;i<ddim2->size;++i) ddim2->perm[i] = dim->perm[dim->size - pivotSplit + i];\
    updateRankDim(ddim1);\
    updateRankDim(ddim2);\
    array_chainlist_##type *l_a1=NULL;\
    array_chainlist_##type *l_a2=NULL;\
    size_t i1=0, /*i=0,j=0, */ i2=0;\
    bool filled1=false,filled2=false;\
    type x;\
    while(ppEnd && (ppEnd[0] !='\0')){\
      x = strto_##type(ttmp, &ppEnd);\
      while(ttmp == ppEnd && ppEnd[0] !='\0'){\
        ttmp++;\
        x = strto_##type(ttmp, &ppEnd);\
      }\
      /*if(ppEnd[0]!='\0')*/ \
      if(ppEnd != ttmp){\
        if(!filled1){\
          ++i1;\
          append_array_chainlist_##type(&l_a1, x);\
          /*printf("++ x: %f, i1:%ld\n",x,i1);*/\
          /*(*Tpart1)->x[i++] = x;*/\
          if(i1 == ddim1->rank){\
            filled1=true;\
            i1=0;\
            filled2=false;\
          }\
        }else{\
          if(!filled2){\
            ++i2;\
            /*(*Tpart2)->x[j++] = x;*/\
            append_array_chainlist_##type(&l_a2, x);\
            /*printf("++ x: %f, i2:%ld\n",x,i2);*/\
            if(i2 == ddim2->rank){\
              filled2 = true;\
              i2=0;\
              filled1 = false;\
            }\
          }\
          \
        }\
        /*printf("d: %lf\n",d);*/\
      }\
      /*printf("-- x: %f\n",x);*/\
      ttmp=ppEnd;\
    }\
    \
    *Tpart1 = create_tensor_from_list_array_##type(l_a1,ddim1);\
    *Tpart2 = create_tensor_from_list_array_##type(l_a2,ddim2);\
    free_array_chainlist_##type(l_a1);\
    free_array_chainlist_##type(l_a2);\
    free_dimension(ddim1);\
    free_dimension(ddim2);\
  }\
  free_dimension(dim);\
  free_list_perm_in_dim(l_p);\
}\
\
\
/*format_file: [*,dim1,dim2]((x,x,a)(x,a))... | example:[2,(2,3),4](((a0,b0,c0,)((a1,b1,c1))((a2,b2,c2,d2))((e0,f0,g0)(e1,f1,g1)(e2,f2,g2,h2))) == with pivot 1 => [2,2,3][2,4]*/\
void parse_file_InputOutput_withDim_to_tensors_##type(tensor_##type **Tpart1, tensor_##type **Tpart2, char *file_name_input, size_t pivotSplit){\
  size_t block_size=2;\
  size_t block_count=4;\
  char *input=malloc(block_size*block_count + 1);\
  char *iinput=malloc(block_size*block_count + 256);\
  FILE *f_input;\
  f_input=fopen(file_name_input,"r");\
  if ( f_input == NULL ) {\
    fprintf( stderr, "Cannot open file: %s for reading\n",file_name_input );\
    exit( -1 );\
  }\
  bool size_unknown=false, broken=false; \
  bool Done=false;\
  int retfread = 0, curIn=0;\
  while(!Done){\
    retfread = fread(input, block_size, block_count, f_input) ;\
    Done = (retfread != block_count);\
    /*input[retfread*block_size]='\0';\
    */for(curIn=0; curIn<retfread*block_size; ++curIn) iinput[curIn]=input[curIn];\
    while(!Done && ( ((iinput[curIn-1] >='0') && (iinput[curIn-1] <='9'))||(iinput[curIn-1] =='.')||(iinput[curIn-1] =='E')||(iinput[curIn-1] =='e'))){\
      retfread = fread(input, 1, 1, f_input) ;\
      Done = (retfread != 1);\
      iinput[curIn++]=input[0];\
    }\
    iinput[curIn]='\0';\
    size_t len = strlen(iinput);\
    for(size_t i=0; i<len ; ++i){\
      if(iinput[i]==']') {broken = true; break;}\
      if((iinput[i]=='*') ||(iinput[i]=='_')){ \
        broken=true;  size_unknown =true;\
        break;\
      }\
    }\
    Done = broken;\
  }\
  rewind(f_input);\
  list_perm_in_dim *l_p=NULL;\
  dimension *dim=NULL;\
  size_t ss;\
  char *ttmp;\
  char *ppEnd="[";\
  bool bracketsDown=false;\
        size_t i1=0,i=0,j=0,i2=0;\
        bool filled1=false,filled2=false;\
        array_chainlist_##type *l_a1=NULL;\
        array_chainlist_##type *l_a2=NULL;\
        bool initDim=false;\
        dimension *dim1 =NULL ;\
        dimension *ddim1=NULL;\
        dimension *ddim2=NULL;\
        dimension *dim2=NULL ;\
  Done=false;\
  while(!Done){\
    retfread = fread(input, block_size, block_count, f_input) ;\
    Done = (retfread != block_count);\
    /*input[retfread*block_size]='\0';\
    */for(curIn=0; curIn<retfread*block_size; ++curIn) iinput[curIn]=input[curIn];\
    while(!Done && (((iinput[curIn-1] >='0') && (iinput[curIn-1] <='9'))||(iinput[curIn-1] =='.')||(iinput[curIn-1] =='E')||(iinput[curIn-1] =='e'))){\
      retfread = fread(input, 1, 1, f_input) ;\
      Done = (retfread != 1);\
      iinput[curIn++] = *input;\
    }\
    iinput[curIn]='\0';\
    ttmp=iinput;\
    if( !bracketsDown){\
    while(strlen(ttmp) && strlen(ppEnd) && (*ppEnd !=']')  ){\
      ss = strtoul(ttmp, &ppEnd, 10);\
      while(ttmp == ppEnd && ppEnd[0] !=']'){\
        ttmp++;\
        ss = strtoul(ttmp, &ppEnd, 10);\
      }\
      if(ppEnd !=ttmp )\
        append_in_list_perm(&l_p,ss);\
      ttmp=ppEnd;\
    }\
    if( *ppEnd ==']'){\
      dim=create_dim_from_list_perm(l_p);\
      bracketsDown = true;\
      ttmp++; ppEnd++;\
    }\
    \
    }\
    if(bracketsDown){\
  \
      if(size_unknown == false){\
        \
        if(!initDim){\
          dim1 = create_dim(dim->size-pivotSplit);\
          ddim1 = create_dim(dim->size-pivotSplit-1);\
          ddim2 = create_dim(pivotSplit);\
          dim2 = create_dim(pivotSplit+1);\
          for(size_t i=0;i<dim1->size;++i) dim1->perm[i] = dim->perm[i];\
          for(size_t i=0;i<ddim1->size;++i) ddim1->perm[i] = dim->perm[i+1];\
          for(size_t i=0;i<ddim2->size;++i) ddim2->perm[i] = dim->perm[ dim->size - pivotSplit + i];\
          dim2->perm[0] = dim->perm[0];\
          for(size_t i=1;i<dim2->size;++i) dim2->perm[i] = ddim2->perm[i-1];\
          updateRankDim(dim1);\
          updateRankDim(ddim1);\
          updateRankDim(ddim2);\
          updateRankDim(dim2);\
          *Tpart1 = CREATE_TENSOR_##type(dim1);\
          *Tpart2 = CREATE_TENSOR_##type(dim2);\
            initDim=true;\
        }\
      \
        type x;\
        while(strlen(ttmp) && j<dim2->rank){ \
          x = strto_##type(ttmp, &ppEnd);\
          while(ttmp == ppEnd && strlen(ttmp)){\
            ttmp++;\
            x = strto_##type(ttmp, &ppEnd);\
          }\
          if(ttmp != ppEnd){\
            if(!filled1){\
              ++i1;\
              (*Tpart1)->x[i++] = x;\
              if(i1 == ddim1->rank){\
                filled1=true;\
                i1=0;\
                filled2=false;\
              }\
            }else{\
              if(!filled2){\
                ++i2;\
                (*Tpart2)->x[j++] = x;\
                if(i2 == ddim2->rank){\
                  filled2=true;\
                  i2=0;\
                  filled1=false;\
                }\
              }\
              \
            }\
          }\
          ttmp=ppEnd;\
        }\
        if(Done){\
          free_dimension(ddim1);\
          free_dimension(ddim2);\
        }\
      }\
      else{\
        \
        if(!initDim){\
          ddim1 = create_dim(dim->size-pivotSplit);\
          ddim2 = create_dim(pivotSplit);\
          for(size_t i=0;i<ddim1->size;++i) ddim1->perm[i] = dim->perm[i];\
          for(size_t i=0;i<ddim2->size;++i) ddim2->perm[i] = dim->perm[dim->size - pivotSplit + i];\
          updateRankDim(ddim1);\
          updateRankDim(ddim2);\
          initDim=true;\
        }\
        type x= 0;\
        while(ttmp && strlen(ttmp) ){ \
          x = strto_##type(ttmp, &ppEnd);\
           while(ttmp == ppEnd && strlen(ttmp)){\
            ttmp++;\
            x = strto_##type(ttmp, &ppEnd);\
          }\
          if(ppEnd != ttmp){\
            if(!filled1){\
              ++i1;\
              append_array_chainlist_##type(&l_a1, x);\
              if(i1 == ddim1->rank){\
                filled1=true;\
                i1=0;\
                filled2=false;\
              }\
            }else{\
              if(!filled2){\
                ++i2;\
                append_array_chainlist_##type(&l_a2, x);\
                if(i2 == ddim2->rank){\
                  filled2 = true;\
                  i2=0;\
                  filled1 = false;\
                }\
              }\
              \
            }\
          }\
          ttmp=ppEnd;\
        }\
        \
        if(Done){\
          *Tpart1 = create_tensor_from_list_array_##type(l_a1,ddim1);\
          *Tpart2 = create_tensor_from_list_array_##type(l_a2,ddim2);\
          free_array_chainlist_##type(l_a1);\
          free_array_chainlist_##type(l_a2);\
          free_dimension(ddim1);\
          free_dimension(ddim2);\
        \
        }\
      }\
    }\
  }\
    free_dimension(dim);\
    free_list_perm_in_dim(l_p);\
    free(input);\
    free(iinput);\
    fclose(f_input);\
}\
\
tensor_##type ** fromInput_to_array_tensor_##type(tensor_##type *tens){\
  tensor_##type **re_tens=malloc((tens->dim)->perm[0]*sizeof(tensor_##type *));\
  dimension *dim=create_dim((tens->dim)->size - 1);\
  for(size_t i=0; i<dim->size; ++i) dim->perm[i]=(tens->dim)->perm[i+1];\
  updateRankDim(dim);\
  for(size_t i=0; i < (tens->dim)->perm[0];++i){\
    re_tens[i]=CREATE_TENSOR_FROM_CPY_DIM_##type(dim);\
    for(size_t j=0; j<dim->rank; ++j) (re_tens[i])->x[j] = tens->x[i*(dim->rank) + j ] ;\
  }\
  free_dimension(dim);\
  return re_tens;\
}\
\
void append_array_chainlist_##type(array_chainlist_##type **list_a, type x){\
    array_chainlist_##type *lis=malloc(sizeof(array_chainlist_##type));\
    lis->x=x;\
    lis->next=NULL;\
  if(*list_a == NULL){\
    lis->index=0;\
    *list_a = lis;\
  }\
  else{\
    array_chainlist_##type *tmp =*list_a;\
    while(tmp->next) tmp=tmp->next;\
    lis->index = tmp->index +1;\
    tmp->next=lis;\
  }\
}\
\
tensor_##type * create_tensor_from_list_array_##type( array_chainlist_##type *l_a, dimension *part_dim){\
  if(l_a){\
    array_chainlist_##type *tmp =l_a;\
    while(tmp->next) tmp=tmp->next;\
    size_t miss_part_d=(tmp->index + 1)/part_dim->rank;\
    dimension *dim=create_dim(part_dim->size + 1);\
    if(endian){\
      dim->perm[0]=miss_part_d;\
      for(size_t i=0; i<part_dim->size;++i) dim->perm[i+1]=part_dim->perm[i];\
    }else{\
      size_t i=0;\
      for(i=0; i<part_dim->size;++i) dim->perm[i]=part_dim->perm[i];\
      dim->perm[i]=miss_part_d;\
      \
    }\
    updateRankDim(dim);\
    tensor_##type *tens= CREATE_TENSOR_##type(dim);\
    tmp=l_a;\
    while(tmp){\
      (tens)->x[tmp->index]=tmp->x;\
      tmp=tmp->next;\
    }\
    return tens;\
  }\
  return NULL;\
}\
\
void free_array_chainlist_##type(array_chainlist_##type *l_a){\
  array_chainlist_##type *tmp=l_a, *ttmp;\
  while(tmp){\
    ttmp = tmp;\
    tmp = ttmp->next;\
    free(ttmp);\
  }\
}\
\
tensor_##type * transpose_notOpt_tensor_##type(tensor_##type *org){\
  size_t dimsz = (org->dim)->size; \
  dimension *dim_tr=create_dim(dimsz);\
  for(size_t i=0; i<dimsz; ++i) dim_tr->perm[i]=(org->dim)->perm[(dimsz-1)-i];\
  updateRankDim(dim_tr);\
  printDebug_dimension(dim_tr,"dim_tr");\
  tensor_##type *tens_tr = CREATE_TENSOR_##type(dim_tr);\
  size_t *coord = malloc((dimsz)*sizeof(size_t));\
  size_t *coord_tr = malloc((dimsz)*sizeof(size_t));\
  for(size_t i=0; i<dim_tr->rank; ++i){\
    vCoordFromLin(coord,i,org->dim);\
    for(size_t j=0; j<dimsz;++j)  coord_tr[j]=coord[dimsz-1-j]; \
    tens_tr->x[LineFromCoord(coord_tr, dim_tr)] = org->x[i];\
  }\
  free(coord);\
  free(coord_tr);\
  return tens_tr;\
}\
\
tensor_##type * permute_notOpt_tensor_##type(tensor_##type *org, dimension *dperm){\
  size_t dimsz = (org->dim)->size; \
  dimension *dim_tr=create_dim(dimsz);\
  for(size_t i=0; i<dimsz; ++i) dim_tr->perm[i]=(org->dim)->perm[(dimsz-1)-i];\
  updateRankDim(dim_tr);\
  printDebug_dimension(dim_tr,"dim_tr");\
  tensor_##type *tens_tr = CREATE_TENSOR_##type(dim_tr);\
  size_t *coord = malloc((dimsz)*sizeof(size_t));\
  size_t *coord_tr = malloc((dimsz)*sizeof(size_t));\
  for(size_t i=0; i<dim_tr->rank; ++i){\
    vCoordFromLin(coord,i,org->dim);\
    for(size_t j=0; j<dimsz;++j)  coord_tr[j]=coord[dperm->perm[j]]; \
    tens_tr->x[LineFromCoord(coord_tr, dim_tr)] = org->x[i];\
  }\
  free(coord);\
  free(coord_tr);\
  return tens_tr;\
}\
struct arg_1Update_##type{\
  type *M0x;\
  size_t beginRange;\
  size_t endRange;\
  type (*func)(type);\
};\
void* run1UpdatCalcfunc_thread_##type(void *arg){\
  struct arg_1Update_##type *arg_t = arg;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        arg_t->M0x[i] = arg_t->func(arg_t->M0x[i]);\
   }\
  return 0;\
}\
\
void update_1tensor_func_##type(tensor_##type *M0, type (*func)(type), size_t nbthread){\
    \
  pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
  struct arg_1Update_##type **arg_th = malloc( nbthread * sizeof(struct arg_1Update_##type *));\
\
  for(size_t i = 0; i < nbthread; ++i){\
    arg_th[i]=malloc(sizeof(struct arg_1Update_##type));\
    arg_th[i]->M0x=M0->x;\
    arg_th[i]->func=func;\
    arg_th[i]->beginRange = i*(M0->dim->rank)/nbthread ;\
    arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
    \
    pthread_create(&thrd[i], NULL, run1UpdatCalcfunc_thread_##type, (void*)arg_th[i]);\
  }\
\
  for(size_t i=0; i< nbthread; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
}  \
\
struct arg_2Update_##type{\
  type *M0x;\
  type *M1x;\
  size_t beginRange;\
  size_t endRange;\
  type (*func)(type);\
};\
void* run2UpdatCalcfunc_thread_##type(void *arg){\
  struct arg_2Update_##type *arg_t = arg;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        arg_t->M0x[i] = arg_t->func(arg_t->M1x[i]);\
   }\
  return 0;\
}\
\
void update_2tensor_func_##type(tensor_##type *M0, tensor_##type *M1, type (*func)(type), size_t nbthread){\
  if ( is_equal_dim(M0->dim,M1->dim)){ \
    pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
    struct arg_2Update_##type **arg_th = malloc( nbthread * sizeof(struct arg_2Update_##type *));\
  \
    for(size_t i = 0; i < nbthread; ++i){\
      arg_th[i]=malloc(sizeof(struct arg_2Update_##type));\
      arg_th[i]->M0x=M0->x;\
      arg_th[i]->M1x=M1->x;\
      arg_th[i]->func=func;\
      arg_th[i]->beginRange = i*(M0->dim->rank)/nbthread ;\
      arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
      \
      pthread_create(&thrd[i], NULL, run2UpdatCalcfunc_thread_##type, (void*)arg_th[i]);\
    }\
  \
    for(size_t i=0; i< nbthread; ++i){\
      pthread_join(thrd[i], NULL);\
      free(arg_th[i]);\
    }\
  \
    free(thrd);\
    free(arg_th);\
  }\
}  \
\
struct arg_3Update_##type{\
  type *M0x;\
  type *M1x;\
  type *M2x;\
  size_t beginRange;\
  size_t endRange;\
  type (*func)(type, type);\
};\
void* run3UpdatCalcfunc_thread_##type(void *arg){\
  struct arg_3Update_##type *arg_t = arg;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        arg_t->M0x[i] = arg_t->func(arg_t->M1x[i], arg_t->M2x[i]);\
   }\
  return 0;\
}\
\
void update_3tensor_func_##type(tensor_##type *M0, tensor_##type *M1, tensor_##type *M2, type (*func)(type,type), size_t nbthread){\
  if ( is_equal_dim(M0->dim,M1->dim) && (is_equal_dim(M0->dim, M2->dim))){  \
    pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
    struct arg_3Update_##type **arg_th = malloc( nbthread * sizeof(struct arg_3Update_##type *));\
  \
    for(size_t i = 0; i < nbthread; ++i){\
      arg_th[i]=malloc(sizeof(struct arg_3Update_##type));\
      arg_th[i]->M0x=M0->x;\
      arg_th[i]->M1x=M1->x;\
      arg_th[i]->M2x=M2->x;\
      arg_th[i]->func=func;\
      arg_th[i]->beginRange = i*(M0->dim->rank)/nbthread ;\
      arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
      \
      pthread_create(&thrd[i], NULL, run3UpdatCalcfunc_thread_##type, (void*)arg_th[i]);\
    }\
  \
    for(size_t i=0; i< nbthread; ++i){\
      pthread_join(thrd[i], NULL);\
      free(arg_th[i]);\
    }\
  \
    free(thrd);\
    free(arg_th);\
  }\
}  \
\
\
struct arg_4Update_##type{\
  type *M0x;\
  type *M1x;\
  type *M2x;\
  size_t beginRange;\
  size_t endRange;\
  type (*func)(type, type,  type(*f1)(type));\
  type(*f1)(type);\
};\
void* run4UpdatCalcfunc_thread_##type(void *arg){\
  struct arg_4Update_##type *arg_t = arg;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        arg_t->M0x[i] = arg_t->func(arg_t->M1x[i], arg_t->M2x[i], arg_t->f1);\
   }\
  return 0;\
}\
\
void update_4tensor_func_##type(tensor_##type *M0, tensor_##type *M1, tensor_##type *M2, \
    type (*func)(type, type,  type(*f1)(type)),\
    type(*f1)(type),\
    size_t nbthread){\
  /*printf(" rankM0=%ld , rank M2:%ld ; iseq :%d \n",(M0->dim)->rank,(M2->dim)->rank,is_equal_dim(M0->dim,M2->dim) );\
*/\
   /* printDebug_dimension(M0->dim," dim M0 in update4 ");  \
    printDebug_dimension(M2->dim," dim M2 in update4 ");  \
  */if ( is_equal_dim(M0->dim, M1->dim) /*&& (is_equal_dim(M0->dim, M2->dim))*/){  \
    /*printDebug_dimension(M0->dim," dim M0 in update4 ");  \
    */pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
    struct arg_4Update_##type **arg_th = malloc( nbthread * sizeof(struct arg_4Update_##type *));\
  \
    for(size_t i = 0; i < nbthread; ++i){\
      arg_th[i]=malloc(sizeof(struct arg_4Update_##type));\
      arg_th[i]->M0x=M0->x;\
      arg_th[i]->M1x=M1->x;\
      arg_th[i]->M2x=M2->x;\
      arg_th[i]->func=func;\
      arg_th[i]->f1=f1;\
      arg_th[i]->beginRange = i*(M0->dim->rank)/nbthread ;\
      arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
      \
      pthread_create(&thrd[i], NULL, run4UpdatCalcfunc_thread_##type, (void*)arg_th[i]);\
    }\
  \
    for(size_t i=0; i< nbthread; ++i){\
      pthread_join(thrd[i], NULL);\
      free(arg_th[i]);\
    }\
  \
    free(thrd);\
    free(arg_th);\
  }\
}  \
\
struct arg_5Update_##type{\
  type *M0x;\
  type *M1x;\
  type *M2x;\
  type *M3x;\
  size_t beginRange;\
  size_t endRange;\
  type (*func)(type, type, type, type(*f1)(type), type (*f2)(type,type) );\
  type(*f1)(type);\
  type (*f2)(type,type);\
};\
void* run5UpdatCalcfunc_thread_##type(void *arg){\
  struct arg_5Update_##type *arg_t = arg;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        arg_t->M0x[i] = arg_t->func(arg_t->M1x[i], arg_t->M2x[i], arg_t->M3x[i], arg_t->f1, arg_t->f2);\
   }\
  return 0;\
}\
\
void update_5tensor_func_##type(tensor_##type *M0, tensor_##type *M1, tensor_##type *M2, tensor_##type *M3 , \
    type (*func) (type, type, type, type(*f1)(type), type (*f2)(type,type)), \
    type(*f1)(type), \
    type (*f2)(type,type), \
    size_t nbthread){\
  if ( is_equal_dim(M0->dim,M1->dim) && (is_equal_dim(M0->dim, M2->dim))&& (is_equal_dim(M0->dim, M3->dim))){  \
    pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
    struct arg_5Update_##type **arg_th = malloc( nbthread * sizeof(struct arg_5Update_##type *));\
    /*printDebug_dimension(M0->dim," dim M0 in update5 "); */ \
    for(size_t i = 0; i < nbthread; ++i){\
      arg_th[i]=malloc(sizeof(struct arg_5Update_##type));\
      arg_th[i]->M0x=M0->x;\
      arg_th[i]->M1x=M1->x;\
      arg_th[i]->M2x=M2->x;\
      arg_th[i]->M3x=M3->x;\
      arg_th[i]->func=func;\
      arg_th[i]->f1=f1;\
      arg_th[i]->f2=f2;\
      arg_th[i]->beginRange = i*(M0->dim->rank)/nbthread ;\
      arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
      \
      pthread_create(&thrd[i], NULL, run5UpdatCalcfunc_thread_##type, (void*)arg_th[i]);\
    }\
  \
    for(size_t i=0; i< nbthread; ++i){\
      pthread_join(thrd[i], NULL);\
      free(arg_th[i]);\
    }\
  \
    free(thrd);\
    free(arg_th);\
  }\
}  \
\
\
struct arg_6Update_##type{\
  type *M0x;\
  type *M1x;\
  size_t beginRange;\
  size_t endRange;\
  type (*func)(type, type, type);\
  type scalar;\
};\
void* run6UpdatCalcfunc_thread_##type(void *arg){\
  struct arg_6Update_##type *arg_t = arg;\
    for (size_t i = arg_t->beginRange; i < arg_t->endRange; i++) {\
        arg_t->M0x[i] = arg_t->func(arg_t->M0x[i], arg_t->M1x[i], arg_t->scalar);\
   }\
  return 0;\
}\
\
void update_6tensor_func_##type(tensor_##type *M0, tensor_##type *M1, \
    type (*func)(type, type, type),\
    type scalar,\
    size_t nbthread){\
  /*printf(" rankM0=%ld , rank M2:%ld ; iseq :%d \n",(M0->dim)->rank,(M2->dim)->rank,is_equal_dim(M0->dim,M2->dim) );\
*/\
   /* printDebug_dimension(M0->dim," dim M0 in update6 ");  \
    printDebug_dimension(M2->dim," dim M2 in update6 ");  \
  */if ( is_equal_dim(M0->dim, M1->dim) /*&& (is_equal_dim(M0->dim, M2->dim))*/){  \
    /*printDebug_dimension(M0->dim," dim M0 in update6 ");  \
    */pthread_t *thrd = malloc(nbthread * sizeof(pthread_t));\
    struct arg_6Update_##type **arg_th = malloc( nbthread * sizeof(struct arg_6Update_##type *));\
  \
    for(size_t i = 0; i < nbthread; ++i){\
      arg_th[i]=malloc(sizeof(struct arg_6Update_##type));\
      arg_th[i]->M0x=M0->x;\
      arg_th[i]->M1x=M1->x;\
      arg_th[i]->func=func;\
      arg_th[i]->scalar=scalar;\
      arg_th[i]->beginRange = i*(M0->dim->rank)/nbthread ;\
      arg_th[i]->endRange = (i+1)*(M0->dim->rank)/nbthread ;\
      \
      pthread_create(&thrd[i], NULL, run6UpdatCalcfunc_thread_##type, (void*)arg_th[i]);\
    }\
  \
    for(size_t i=0; i< nbthread; ++i){\
      pthread_join(thrd[i], NULL);\
      free(arg_th[i]);\
    }\
  \
    free(thrd);\
    free(arg_th);\
  }\
}  \
\


GEN_FUNC_TENSOR(TYPE_FLOAT);
GEN_FUNC_TENSOR(TYPE_DOUBLE);
GEN_FUNC_TENSOR(TYPE_L_DOUBLE);
