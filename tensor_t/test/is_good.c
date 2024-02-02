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

TEST(rank){
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);
  tensor_TYPE_FLOAT *tf = CREATE_TENSOR_TYPE_FLOAT(D);
  EXPECT_EQ(tf->dim->rank, 180);

}

void print_tensor_float(tensor_TYPE_FLOAT *M, char *msg){
  if(M==NULL) {
    LOG("empty tensor | %s ===============\n",msg);
    return;
  }
  LOG("================= %s ===============\n",msg);
  for(size_t i=0; i<M->dim->rank;++i)
      LOG("[%ld]: %f ",i,M->x[i]);
  
    LOG("%s","\n");
}


void print_tensor_double(tensor_TYPE_DOUBLE *M, char *msg){
  LOG("================= %s ===============\n",msg);
  for(size_t i=0; i<M->dim->rank;++i)
      LOG("[%ld]: %lf ",i,M->x[i]);
  
    LOG("%s","\n");
}

TEST(tensorSubhead_ ){
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=5;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;

  endian=false;
  size_t rnkId = 1;
  tensor_TYPE_FLOAT *s2h = sub_tensor_head_TYPE_FLOAT(M0,1,rnkId);

  print_tensor_float(M0, "M0 for sub");
  print_tensor_float(s2h, "sub s2h of M0");

  printDebug_dimension(M0->dim," M0 dimension  ");
  printDebug_dimension(s2h->dim," s2h dimension  ");
 //EXPECT_ARRAY_EQ_TYPE_FLOAT(M0->x,s2h->dim->rank,s2h->x,s2h->dim->rank);
 
  for(size_t i1=0; i1<d0->perm[1];++i1){
    for(size_t i0=0; i0<d0->perm[0];++i0){
      printf("EXPECT_EQ_TYPE_FLOAT c0[%ld](%ld,%ld,%ld) : s[%ld](%ld,%ld) \n",LineFromCoord((size_t[]){i0,i1,rnkId},M0->dim),rnkId,i0,i1,LineFromCoord((size_t[]){i0,i1},s2h->dim),i0,i1);
      EXPECT_EQ_TYPE_FLOAT(M0->x[LineFromCoord((size_t[]){i0,i1,rnkId},M0->dim)],s2h->x[LineFromCoord((size_t[]){i0,i1},s2h->dim)]);
    }  
  }
}


TEST(tensorSubtail ){
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=5;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;


  tensor_TYPE_FLOAT *s1t = sub_tensor_tail_TYPE_FLOAT(M0,1,5);

  print_tensor_float(M0, "M0 for sub");
  print_tensor_float(s1t, "sub s2t of M0 from 5");

}


TEST(tensorSubtail ){
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=5;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;

  //endian=false;
  size_t rnkId=3;
  tensor_TYPE_FLOAT *s2t = sub_tensor_tail_TYPE_FLOAT(M0,1,rnkId);



  print_tensor_float(M0, "M0 for sub");
  print_tensor_float(s2t, "sub s2t of M0 from 3");

  for(size_t i1=0; i1<d0->perm[1];++i1){
    for(size_t i2=0; i2<d0->perm[2];++i2){
      printf("EXPECT_EQ_TYPE_FLOAT c0[%ld](%ld,%ld,%ld) : s[%ld](%ld,%ld) \n",LineFromCoord((size_t[]){rnkId,i1,i2},M0->dim),rnkId,i1,i2,LineFromCoord((size_t[]){i1,i2},s2t->dim),i1,i2);
      EXPECT_EQ_TYPE_FLOAT(M0->x[LineFromCoord((size_t[]){rnkId,i1,i2},M0->dim)],s2t->x[LineFromCoord((size_t[]){i1,i2},s2t->dim)]);
    }  
  }

}

TEST(tensorProd ){
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


}

TEST(tensorContractnProd_TYPE_DOUBLE2 ){
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

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  tensorContractnProdNotOpt_TYPE_DOUBLE(&MnO, M0,M1,2);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);


}


TEST(VStensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);

  d0->perm[0]=125;
  d0->perm[1]=52; //3;
  d0->perm[2]=63;

  d1->perm[0]=52;
  d1->perm[1]=63;//3;
  d1->perm[2]=154;

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
  //tensor_TYPE_DOUBLE *MnO;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  //tensorContractnProdNotOpt_TYPE_DOUBLE(&MnO, M0,M1,2);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  //EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);


}

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
