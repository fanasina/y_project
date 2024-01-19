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

#define GEN_FUNC_TENSOR(type)\
  tensor_##type* CREATE_TENSOR_##type(dimension *dim){\
    tensor_##type *r_tens=malloc(sizeof(tensor_##type));\
    updateRankDim(dim);\
    r_tens->dim = dim;\
    r_tens->x = malloc(sizeof(type)*dim->rank);\
    return r_tens;\
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
}  \
\
void tensorProd_##type(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1) {  \
    dimension *dd;  \
    add_dimension(&dd, M0->dim, M1->dim); \
    (*MM)=CREATE_TENSOR_##type(dd);  \
    tensor_##type *M = *MM; \
    size_t m_idx;\
    for(size_t i=0; i<M0->dim->rank; ++i){\
      for(size_t j=0; j<M1->dim->rank; ++j){\
          m_idx= i*M1->dim->rank + j ;\
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
void tensorContractnProd_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t nestingDepth) {\
   /* if (!checkMatchProdtensor(M0->dim, M1->dim, nestingDepth)) {\
        prsize_tf("Deep = %d\n", nestingDepth);\
    }*/\
\
    size_t len0 = M0->dim->size - nestingDepth;\
    size_t len1 = M1->dim->size - nestingDepth;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *nestingDepth);\
    size_t* tDk0 = malloc(sizeof(size_t) *nestingDepth);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, nestingDepth);\
    subArray(tDk1, M1->dim->perm, 0, nestingDepth, 0);\
    subArray(tDk0, M0->dim->perm, 0, nestingDepth, len0);\
    /*printArraySzt(tsub0,len0,"tsub0");\
    printArraySzt(tsub1,len1,"tsub1");\
    printArraySzt(tDk0,nestingDepth,"tDk0");\
    printArraySzt(tDk1,nestingDepth,"tDk1");*/\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, nestingDepth);\
    dimension *dM0 = init_dim(tDk0, nestingDepth);\
  /*printDebug_dimension(dSub0,"dSub0");\
  printDebug_dimension(dSub1,"dSub1");\
  printDebug_dimension(dM0,"dM0");\
  printDebug_dimension(dM1,"dM1");*/\
    dimension *dM;\
    min_dimension(&dM, dM0, dM1);\
  /*printDebug_dimension(dM,"dM");*/\
    \
    dimension *dd;\
    add_dimension(&dd, dSub0, dSub1);\
  /*printDebug_dimension(dd,"dd");*/\
    updateRankDim(dd);\
    *MM = CREATE_TENSOR_##type(dd);\
    tensor_##type *M= *MM;\
\
    /*size_t* coord;\
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
    Koord = malloc(sizeof(size_t)* nestingDepth);*/\
\
    size_t a0_id, a1_id, n0_id, n1_id;\
    for (size_t i = 0; i < M->dim->rank; i++) {\
        a0_id=i/dSub1->rank;\
        a1_id=i%dSub1->rank;\
        /*vCoordFromLin(coord, i, M->dim);\
        subArray(coord0, coord, 0, len0, 0);\
        subArray(coord1, coord, 0, len1, len0);\
        printf("i:%ld=>  c0: %ld vs %ld \n",i,LineFromCoord(coord0,dSub0),a0_id);\
        printf("i:%ld=>  c1: %ld vs %ld \n",i,LineFromCoord(coord1,dSub1),a1_id);*/\
        M->x[i] = 0;\
        for (size_t k = 0; k < dM->rank; k++) {\
            n0_id= a0_id*dM->rank + k;\
            n1_id= a1_id + dSub1->rank * k;\
            M->x[i] += M0->x[n0_id] * M1->x[n1_id];\
            /*vCoordFromLin(Koord, k, dM);\
            concatArray(coordM0, coord0, Koord, 0, 0, len0, 0, nestingDepth);\
            concatArray(coordM1, Koord, coord1, 0, 0, nestingDepth, 0, len1);\
            lin0 = LineFromCoord(coordM0, M0->dim);\
            lin1 = LineFromCoord(coordM1, M1->dim);\
            printf("k:%ld, lin0:%ld, vs n0: %ld\n",k,lin0,n0_id);\
            printf("k:%ld, lin1:%ld, vs n1: %ld\n",k,lin1,n1_id);*/\
            /*M->x[i] += M0->x[lin0] * M1->x[lin1];*/\
          /*printf("M[%ld]:%f += M0[%ld]:%f * M1[%ld]:%f | \n",i,M->x[i],n0_id,M0->x[n0_id],n1_id,M1->x[n1_id]);*/\
          /*printf("k:%ld |i:%ld |lin0:%ld | lin1:%ld | ",k,i,lin0,lin1);*/\
        }\
      /*printf("\n");*/\
    }\
}\
void tensorContractnProdNotOpt_##type(tensor_##type** MM, tensor_##type *M0, tensor_##type *M1, size_t nestingDepth) {\
   /* if (!checkMatchProdtensor(M0->dim, M1->dim, nestingDepth)) {\
        prsize_tf("Deep = %d\n", nestingDepth);\
    }*/\
\
    size_t len0 = M0->dim->size - nestingDepth;\
    size_t len1 = M1->dim->size - nestingDepth;\
\
    size_t* tsub0 = malloc(sizeof(size_t) *len0);\
    size_t* tsub1 = malloc(sizeof(size_t) *len1);\
    size_t* tDk1 = malloc(sizeof(size_t) *nestingDepth);\
    size_t* tDk0 = malloc(sizeof(size_t) *nestingDepth);\
    subArray(tsub0, M0->dim->perm, 0, len0, 0);\
    subArray(tsub1, M1->dim->perm, 0, len1, nestingDepth);\
    subArray(tDk1, M1->dim->perm, 0, nestingDepth, 0);\
    subArray(tDk0, M0->dim->perm, 0, nestingDepth, len0);\
    /*printArraySzt(tsub0,len0,"tsub0");\
    printArraySzt(tsub1,len1,"tsub1");\
    printArraySzt(tDk0,nestingDepth,"tDk0");\
    printArraySzt(tDk1,nestingDepth,"tDk1");*/\
    dimension *dSub0 = init_dim(tsub0, len0);\
    dimension *dSub1 = init_dim(tsub1, len1);\
    dimension *dM1 = init_dim(tDk1, nestingDepth);\
    dimension *dM0 = init_dim(tDk0, nestingDepth);\
  /*printDebug_dimension(dSub0,"dSub0");\
  printDebug_dimension(dSub1,"dSub1");\
  printDebug_dimension(dM0,"dM0");\
  printDebug_dimension(dM1,"dM1");*/\
    dimension *dM;\
    min_dimension(&dM, dM0, dM1);\
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
    Koord = malloc(sizeof(size_t)* nestingDepth);\
\
    for (size_t i = 0; i < M->dim->rank; i++) {\
        vCoordFromLin(coord, i, M->dim);\
        subArray(coord0, coord, 0, len0, 0);\
        subArray(coord1, coord, 0, len1, len0);\
        M->x[i] = 0;\
        for (size_t k = 0; k < dM->rank; k++) {\
            vCoordFromLin(Koord, k, dM);\
            concatArray(coordM0, coord0, Koord, 0, 0, len0, 0, nestingDepth);\
            concatArray(coordM1, Koord, coord1, 0, 0, nestingDepth, 0, len1);\
            lin0 = LineFromCoord(coordM0, M0->dim);\
            lin1 = LineFromCoord(coordM1, M1->dim);\
            M->x[i] += M0->x[lin0] * M1->x[lin1];\
          /*printf("M[%ld]:%f += M0[%ld]:%f * M1[%ld]:%f | ",i,M->x[i],lin0,M0->x[lin0],lin1,M1->x[lin1]);*/\
          /*printf("k:%ld |i:%ld |lin0:%ld | lin1:%ld | ",k,i,lin0,lin1);*/\
        }\
      /*printf("\n");*/\
    }\
}\
\

GEN_FUNC_TENSOR(TYPE_FLOAT);
GEN_FUNC_TENSOR(TYPE_DOUBLE);
