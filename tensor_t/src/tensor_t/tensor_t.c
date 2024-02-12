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
  tensor_##type* CREATE_TENSOR_FROM_CPY_DIM_##type(dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    r_tens->dim = init_copy_dim(dim->perm,dim->size);\
    r_tens->x = malloc(sizeof(type)*dim->rank);\
    return r_tens;\
  }\
\
  void free_tensor_##type(tensor_##type *  tens){\
    if(tens){\
      free_dimension(tens->dim);\
      free(tens->x);\
      free(tens);\
    }\
  }\
/*  tensor_##type * sub_minus_tensor_head_##type(tensor_##type *rootens, size_t minuSubdim, size_t rankInDim){\
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
*/  \
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
void tensorProdNotOpt_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1) {  \
  dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    (*MM)=CREATE_TENSOR_##type(dd);  \
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
    (*MM)=CREATE_TENSOR_##type(dd);  \
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
    *MM = CREATE_TENSOR_##type(dd);\
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
        arg_t->Mx[i] += arg_t->M0x[a0_id] * arg_t->M1x[a1_id];\
   }\
}\
\
void tensorProdThread_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    (*MM)=CREATE_TENSOR_##type(dd);  \
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
}\
\
void tensorProdThrea2d_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    (*MM)=CREATE_TENSOR_##type(dd);  \
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
}\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
void tensorContractnProdThread_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread) {\
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
    *MM = CREATE_TENSOR_##type(dd);\
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
}\
/* M[x0,x1,x3..xn] X M[y0,y1,y3..ym] = M[z0,z1...zp] (deep = l > 0) /exists 1<= l<...<l=n /  xl = y0,x{l+1}=y1, x{n}=yl  et zi=xi i<n-l et zj=y{j-(n-l)} j>=n-l alor p=n+m-2l\
 M[x0,x1,x3..xl x{l+1}...xn] X M[xn,x{n-1},x{n-2}...xl y{l+1} ..ym] = M[x0,x1..xly{l+1}...y{n+m-2l}] (deep = l > 0)\
M[[i][j]]=sum_{[k]}M0[[i][k]]*M[[k][j]]*/\
\
void tensorContractnPro2dThread_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread) {\
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
    *MM = CREATE_TENSOR_##type(dd);\
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
void tensorContractnProdNotOpt_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber) {\
   /* if (!checkMatchProdtensor(M0->dim, M1->dim, contractionNumber)) {\
        prsize_tf("Deep = %d\n", contractionNumber);\
    }*/\
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
    *MM = CREATE_TENSOR_##type(dd);\
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

GEN_FUNC_TENSOR(TYPE_FLOAT);
GEN_FUNC_TENSOR(TYPE_DOUBLE);
