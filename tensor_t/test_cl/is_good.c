#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for sleep !
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif

#include "ftest/ftest.h"
#include "ftest/ftest_array.h"
#include "fmock/fmock.h"


//#include "permutation_t/permutation_t.h"
#include "tensor_t/tensor_t.h"
#include "tensor_t/cl_tensor_t.h"
//#include "tools_t/tools_t.h"

#define VALGRIND 1

TEST(rank){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);
  tensor_TYPE_FLOAT *tf = CREATE_TENSOR_TYPE_FLOAT(D);
  EXPECT_EQ(tf->dim->rank, 180);

  free_dimension(D);
}

void print_tensor_float(tensor_TYPE_FLOAT *M, char *msg){
  LOG("================= %s ===============\n",msg);
#if VALGRIND
  for(size_t i=0; i<M->dim->rank;++i)
      LOG("[%ld]: %f ",i,M->x[i]);
    LOG("%s","\n");
#endif  
}


void print_tensor_double(tensor_TYPE_DOUBLE *M, char *msg){
  LOG("================= %s ===============\n",msg);
#if VALGRIND
  for(size_t i=0; i<M->dim->rank;++i)
      LOG("[%ld]: %lf ",i,M->x[i]);
  
    LOG("%s","\n");
#endif  
}

  extern long int PRECISION_TYPE_FLOAT ;
TEST(tensorProd ){
  PRECISION_TYPE_FLOAT = 10;

  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=2;
  
  d1->perm[0]=2;
  d1->perm[1]=3;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  print_tensor_float(M0,"M0");
  print_tensor_float(M1,"M1");


  tensor_TYPE_FLOAT *M; 
  tensor_TYPE_FLOAT *Mn; 

  tensorProd_TYPE_FLOAT(&M,M0,M1);
  tensorProdNotOpt_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  print_tensor_float(M,"M");

  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  print_tensor_float(Mn,"Mn");

  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}

TEST(tensorContractnProd_TYPE_FLOAT ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=2;

  d1->perm[0]=2;
  d1->perm[1]=3;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  print_tensor_float(M0,"M0");
  print_tensor_float(M1,"M1");

  tensor_TYPE_FLOAT *M;
  tensor_TYPE_FLOAT *MnO;

  tensorContractnProd_TYPE_FLOAT(&M, M0,M1,1);
  tensorContractnProdNotOpt_TYPE_FLOAT(&MnO, M0,M1,1);


  print_tensor_float(M,"M");
  print_tensor_float(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //  EXPECT_EQ_TYPE_FLOAT(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,MnO->x,MnO->dim->rank);


  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(MnO);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}

TEST(tensorContractnProd_TYPE_FLOAT2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);

  d0->perm[0]=35;
  d0->perm[1]=32; //3;
  d0->perm[2]=23;

  d1->perm[0]=32;
  d1->perm[1]=23;//3;
  d1->perm[2]=44;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

//  print_tensor_float(M0,"M0");
//  print_tensor_float(M1,"M1");

  tensor_TYPE_FLOAT *M;
  tensor_TYPE_FLOAT *MnO;

  tensorContractnProd_TYPE_FLOAT(&M, M0,M1,2);
//  print_tensor_float(M,"M");
  tensorContractnProdNotOpt_TYPE_FLOAT(&MnO, M0,M1,2);


//  print_tensor_float(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_FLOAT(M->x[i],MnO->x[i]);
    
  //EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(MnO);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}

  extern long int  PRECISION_TYPE_DOUBLE;

TEST(cl_tensorContractnProd_TYPE_FLOAT2 ){
  PRECISION_TYPE_DOUBLE=1000;

  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
  
  d0->perm[0]=35;
  d0->perm[1]=32; //3;
  d0->perm[2]=23;

  d1->perm[0]=32;
  d1->perm[1]=23;//3;
  d1->perm[2]=44;

  updateRankDim(d0);
  updateRankDim(d1);

  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

//  print_tensor_float(M0,"M0");
//  print_tensor_float(M1,"M1");

  tensor_TYPE_FLOAT *M;
  tensor_TYPE_FLOAT *MnO;

  tensorContractnProdNotOpt_TYPE_FLOAT(&M, M0,M1,2);
//  print_tensor_float(M,"M");
  cl_tensorContractnProd_TYPE_FLOAT(&MnO, M0,M1,2);


//  print_tensor_float(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_FLOAT(M->x[i],MnO->x[i]);
    
  //EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(MnO);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);

}

TEST(cl_tensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);

  d0->perm[0]=125;
  d0->perm[1]=52; //3;
  d0->perm[2]=63;

  d1->perm[0]=52;
  d1->perm[1]=63;//3;
  d1->perm[2]=54;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  //print_tensor_double(M0,"M0");
  //print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M;
  tensor_TYPE_DOUBLE *MnO;

  tensorContractnProdNotOpt_TYPE_DOUBLE(&M, M0,M1,2);
  //tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2);
  //print_tensor_double(M,"M");
  cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);


  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}


TEST(tensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND

  d0->perm[0]=12;
  d0->perm[1]=5; //3;
  d0->perm[2]=6;

  d1->perm[0]=5;
  d1->perm[1]=6;//3;
  d1->perm[2]=14;

#else
  d0->perm[0]=125;
  d0->perm[1]=52; //3;
  d0->perm[2]=63;

  d1->perm[0]=52;
  d1->perm[1]=63;//3;
  d1->perm[2]=54;
#endif
  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  //print_tensor_double(M0,"M0");
  //print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M;
  tensor_TYPE_DOUBLE *MnO;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  tensorContractnProdNotOpt_TYPE_DOUBLE(&MnO, M0,M1,2);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}

TEST(TensorProdCL){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

 
  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=2;
  
  d1->perm[0]=2;
  d1->perm[1]=3;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  print_tensor_float(M0,"M0");
  print_tensor_float(M1,"M1");



  tensor_TYPE_FLOAT *M; 
  tensor_TYPE_FLOAT *Mn; 

  tensorProd_TYPE_FLOAT(&M,M0,M1);
  cl_tensorProd_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  print_tensor_float(M,"M");
  
  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);


  print_tensor_float(Mn,"Mn");
  
  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}


TEST(VS_thrd_tensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND

  d0->perm[0]=12;
  d0->perm[1]=4; //3;
  d0->perm[2]=6;

  d1->perm[0]=4;
  d1->perm[1]=6;//3;
  d1->perm[2]=16;

#else  

  d0->perm[0]=512;
  d0->perm[1]=48; //3;
  d0->perm[2]=64;

  d1->perm[0]=48;
  d1->perm[1]=64;//3;
  d1->perm[2]=240;
#endif

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  //print_tensor_double(M0,"M0");
  //print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M;
  tensor_TYPE_DOUBLE *MnO;

  size_t nbth=10;

  //tensorContractnProdNotOpt_TYPE_DOUBLE(&M, M0,M1,2);
  //tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  tensorContractnProdThread_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  tensorContractnProdThread_TYPE_DOUBLE(&MnO, M0,M1,2,nbth);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);


  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);


}



TEST(VS_thrd_tensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND

  d0->perm[0]=12;
  d0->perm[1]=4; //3;
  d0->perm[2]=6;

  d1->perm[0]=4;
  d1->perm[1]=6;//3;
  d1->perm[2]=16;

#else  

  d0->perm[0]=512;
  d0->perm[1]=48; //3;
  d0->perm[2]=64;

  d1->perm[0]=48;
  d1->perm[1]=64;//3;
  d1->perm[2]=240;
#endif



  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  //print_tensor_double(M0,"M0");
  //print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M;
  tensor_TYPE_DOUBLE *MnO;

  size_t nbth=15;

  //tensorContractnProdNotOpt_TYPE_DOUBLE(&M, M0,M1,2);
  //tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  tensorContractnProdThread_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  tensorContractnProdThread_TYPE_DOUBLE(&MnO, M0,M1,2,nbth);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);


  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);


}







TEST(VS_thrd_tensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND

  d0->perm[0]=12;
  d0->perm[1]=4; //3;
  d0->perm[2]=6;

  d1->perm[0]=4;
  d1->perm[1]=6;//3;
  d1->perm[2]=16;

#else  

  d0->perm[0]=512;
  d0->perm[1]=48; //3;
  d0->perm[2]=64;

  d1->perm[0]=48;
  d1->perm[1]=64;//3;
  d1->perm[2]=240;
#endif



  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  //print_tensor_double(M0,"M0");
  //print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M;
  tensor_TYPE_DOUBLE *MnO;

  size_t nbth=10;

  //tensorContractnProdNotOpt_TYPE_DOUBLE(&M, M0,M1,2);
  //tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  tensorContractnProdThread_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  tensorContractnProdThread_TYPE_DOUBLE(&MnO, M0,M1,2,nbth);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);


  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);


}









TEST(VScltensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);

#if VALGRIND

  d0->perm[0]=12;
  d0->perm[1]=4; //3;
  d0->perm[2]=6;

  d1->perm[0]=4;
  d1->perm[1]=6;//3;
  d1->perm[2]=16;

#else  

  d0->perm[0]=512;
  d0->perm[1]=48; //3;
  d0->perm[2]=64;

  d1->perm[0]=48;
  d1->perm[1]=64;//3;
  d1->perm[2]=240;
#endif


  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  //print_tensor_double(M0,"M0");
  //print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M;
  tensor_TYPE_DOUBLE *MnO;

  size_t nbth = 10;

  tensorContractnProdThread_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  //print_tensor_double(M,"M");
  cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  //tensorContractnProdNotOpt_TYPE_DOUBLE(&MnO, M0,M1,2);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);


}

TEST(VScl2dtensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND

  d0->perm[0]=12;
  d0->perm[1]=4; //3;
  d0->perm[2]=6;

  d1->perm[0]=4;
  d1->perm[1]=6;//3;
  d1->perm[2]=16;

#else  

  d0->perm[0]=512;
  d0->perm[1]=48; //3;
  d0->perm[2]=64;

  d1->perm[0]=48;
  d1->perm[1]=64;//3;
  d1->perm[2]=240;
#endif


  d0->perm[0]=512;
  d0->perm[1]=48; //3;
  d0->perm[2]=64;

  d1->perm[0]=48;
  d1->perm[1]=64;//3;
  d1->perm[2]=240;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  //print_tensor_double(M0,"M0");
  //print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M;
  tensor_TYPE_DOUBLE *MnO;

  size_t nbth = 10;

  tensorContractnProdThread_TYPE_DOUBLE(&M, M0,M1,2,nbth);
  //print_tensor_double(M,"M");
  cl2d_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2,16,16);
  //cl2d_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2,8,8);
  //tensorContractnProdNotOpt_TYPE_DOUBLE(&MnO, M0,M1,2);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}


TEST(tensorProd_vs2d ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

  d0->perm[0]=24;
  d0->perm[1]=32;
  d0->perm[2]=2;

  d1->perm[0]=64;
  d1->perm[1]=16;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  /*print_tensor_float(M0,"M0");
  print_tensor_float(M1,"M1");*/


  tensor_TYPE_FLOAT *M;
  tensor_TYPE_FLOAT *Mn;

  cl_tensorProd_TYPE_FLOAT(&M,M0,M1);
  tensorProd_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  //print_tensor_float(M,"M");

  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);

  //print_tensor_float(Mn,"Mn");
}



TEST(tensorProd_vs2d ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

  d0->perm[0]=24;
  d0->perm[1]=32;
  d0->perm[2]=2;

  d1->perm[0]=64;
  d1->perm[1]=24;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  /*print_tensor_float(M0,"M0");
  print_tensor_float(M1,"M1");*/


  tensor_TYPE_FLOAT *M;
  tensor_TYPE_FLOAT *Mn;

  tensorProd_TYPE_FLOAT(&M,M0,M1);
  //cl2d_tensorProd_TYPE_FLOAT(&Mn,M0,M1,24,24);
  //cl2d_tensorProd_TYPE_FLOAT(&Mn,M0,M1,32,32);
  cl2d_tensorProd_TYPE_FLOAT(&Mn,M0,M1,64,16);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  //print_tensor_float(M,"M");

  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  //print_tensor_float(Mn,"Mn");
  
  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}

TEST(tensorProd_vs2d_Endian ){
  endian=false;
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

  d0->perm[0]=24;
  d0->perm[1]=32;
  d0->perm[2]=2;

  d1->perm[0]=64;
  d1->perm[1]=16;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  /*print_tensor_float(M0,"M0");
  print_tensor_float(M1,"M1");*/


  tensor_TYPE_FLOAT *M;
  tensor_TYPE_FLOAT *Mn;

  cl_tensorProd_TYPE_FLOAT(&M,M0,M1);
  tensorProd_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  //print_tensor_float(M,"M");

  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  //print_tensor_float(Mn,"Mn");
  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}




TEST(tensorProd_vs2d_Endian ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

  d0->perm[0]=24;
  d0->perm[1]=32;
  d0->perm[2]=2;

  d1->perm[0]=64;
  d1->perm[1]=24;

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;



  tensor_TYPE_FLOAT *M;
  tensor_TYPE_FLOAT *Mn;

  tensorProd_TYPE_FLOAT(&M,M0,M1);
  //cl2d_tensorProd_TYPE_FLOAT(&Mn,M0,M1,24,24);
  //cl2d_tensorProd_TYPE_FLOAT(&Mn,M0,M1,32,32);
  cl2d_tensorProd_TYPE_FLOAT(&Mn,M0,M1,64,16);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  //print_tensor_float(M,"M");

  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  //print_tensor_float(Mn,"Mn");
  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}


int main(int argc, char **argv){
  
  run_all_tests_args(argc, argv);

  return 0;
}
