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
  LOG("================= %s ===============\n",msg);
  for(size_t i=0; i<M->dim->rank;++i)
      LOG("[%ld]: %f ",i,M->x[i]);
  
    LOG("%s","\n");
  /*
  size_t x_index=0 ;
  for(size_t i=0; i<M->dim->size;++i){
    for(size_t j=0; j<M->dim->perm[i]; ++j){
      LOG("[%3ld:(%ld,%ld)]: %f ",x_index,i,j,M->x[x_index]);
      ++x_index;
    }
    LOG("%s","\n");
  } */
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

  size_t x_idx=0, m_idx;
  for(size_t i=0; i<M->dim->rank; ++i){
     EXPECT_EQ_TYPE_FLOAT(Mn->x[i],M->x[i]); 
  } 

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

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
