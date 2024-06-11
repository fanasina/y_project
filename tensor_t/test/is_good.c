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

#define VALGRIND_ 1

TEST(rank){
  endian =true;
  dimension *D=create_dim(4);
  D->perm[0]=2;
  D->perm[1]=3;
  D->perm[2]=5;
  D->perm[3]=6;

  updateRankDim(D);
  tensor_TYPE_FLOAT *tf = CREATE_TENSOR_TYPE_FLOAT(D);
  EXPECT_EQ(tf->dim->rank, 180);

  free_tensor_TYPE_FLOAT(tf);
}

void print_tensor_float(tensor_TYPE_FLOAT *M, char *msg){
  if(M==NULL) {
    LOG("empty tensor | %s ===============\n",msg);
    return;
  }
  LOG("================= %s ===============\n",msg);

#if VALGRIND_
  /*for(size_t i=0; i<M->dim->rank;++i)
      LOG("[%ld]: %f ",i,M->x[i]);
  */
  print_tensor_msg_TYPE_FLOAT(M,msg);
#endif
    LOG("%s","\n");
}


void print_tensor_double(tensor_TYPE_DOUBLE *M, char *msg){
  LOG("================= %s ===============\n",msg);
#if VALGRIND_
  /*
  for(size_t i=0; i<M->dim->rank;++i)
      LOG("[%ld]: %lf ",i,M->x[i]);
  */
  print_tensor_msg_TYPE_DOUBLE(M,msg);
#endif
    LOG("%s","\n");
}

TEST(tensorMinusSubhead_ ){
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=5;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;

  //endian=false;
  size_t rnkId = 1;
  tensor_TYPE_FLOAT *s2h = sub_copy_minus_tensor_head_TYPE_FLOAT(M0,1,rnkId);

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

  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(s2h);
}

TEST(tensorMinusSubtail ){
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=5;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;

  tensor_TYPE_FLOAT *s1t = sub_copy_minus_tensor_tail_TYPE_FLOAT(M0,1,5);

  print_tensor_float(M0, "M0 for sub");
  print_tensor_float(s1t, "sub s2t of M0 from 5");

  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(s1t);
}


TEST(tensorMinusSubtail ){
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
  tensor_TYPE_FLOAT *s2t = sub_copy_minus_tensor_tail_TYPE_FLOAT(M0,1,rnkId);



  print_tensor_float(M0, "M0 for sub");
  print_tensor_float(s2t, "sub s2t of M0 from 3");

  for(size_t i1=0; i1<d0->perm[1];++i1){
    for(size_t i2=0; i2<d0->perm[2];++i2){
      printf("EXPECT_EQ_TYPE_FLOAT c0[%ld](%ld,%ld,%ld) : s[%ld](%ld,%ld) \n",LineFromCoord((size_t[]){rnkId,i1,i2},M0->dim),rnkId,i1,i2,LineFromCoord((size_t[]){i1,i2},s2t->dim),i1,i2);
      EXPECT_EQ_TYPE_FLOAT(M0->x[LineFromCoord((size_t[]){rnkId,i1,i2},M0->dim)],s2t->x[LineFromCoord((size_t[]){i1,i2},s2t->dim)]);
    }  
  }

  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(s2t);
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

  //endian=false;
  size_t rnkId = 1;
  tensor_TYPE_FLOAT *s2h = sub_copy_tensor_head_TYPE_FLOAT(M0,2,rnkId);

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
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(s2h);
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


  tensor_TYPE_FLOAT *s1t = sub_copy_tensor_tail_TYPE_FLOAT(M0,2,5);

  print_tensor_float(M0, "M0 for sub");
  print_tensor_float(s1t, "sub s2t of M0 from 5");
  
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(s1t);

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
  tensor_TYPE_FLOAT *s2t = sub_copy_tensor_tail_TYPE_FLOAT(M0,2,rnkId);



  print_tensor_float(M0, "M0 for sub");
  print_tensor_float(s2t, "sub s2t of M0 from 3");

  for(size_t i1=0; i1<d0->perm[1];++i1){
    for(size_t i2=0; i2<d0->perm[2];++i2){
      printf("EXPECT_EQ_TYPE_FLOAT c0[%ld](%ld,%ld,%ld) : s[%ld](%ld,%ld) \n",LineFromCoord((size_t[]){rnkId,i1,i2},M0->dim),rnkId,i1,i2,LineFromCoord((size_t[]){i1,i2},s2t->dim),i1,i2);
      EXPECT_EQ_TYPE_FLOAT(M0->x[LineFromCoord((size_t[]){rnkId,i1,i2},M0->dim)],s2t->x[LineFromCoord((size_t[]){i1,i2},s2t->dim)]);
    }  
  }

  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(s2t);
}

TEST(randomInit){
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=5;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_FLOAT(M0,2.7,5.4,50001);

  print_tensor_float(M0, "M0 random");
  free_tensor_TYPE_FLOAT(M0);
}
TEST(printT_init_false){
  endian=false;
  dimension *d0=create_dim(3);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=4;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  //init_random_x_TYPE_FLOAT(M0,2,5,50);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;


//  print_tensor_float(M0, "M0 ");
  print_tensor_msg_TYPE_FLOAT(M0, "M0 ");
  free_tensor_TYPE_FLOAT(M0);
  
}


TEST(printT_Init_true){
  endian=true;
  dimension *d0=create_dim(3);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=4;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  //init_random_x_TYPE_FLOAT(M0,2,5,50);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;


//  print_tensor_float(M0, "M0 ");
  print_tensor_msg_TYPE_FLOAT(M0, "M0 ");
  free_tensor_TYPE_FLOAT(M0);
  
}

TEST(sprinttens){
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=2;


  updateRankDim(d0);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_DOUBLE(M0,2.7,5.4,50001);

  //print_tensor_double(M0, "test print M0");
  char *tensCont = NULL;
  size_t nbChar = sprint_tensor_TYPE_DOUBLE(&tensCont, M0, false);

  LOG(" avec Sprint_tensor sans index, M0 est : \n%s \n, il y a %ld charactères\n",tensCont, nbChar);
  
  nbChar = sprint_tensor_TYPE_DOUBLE(&tensCont, M0, true);

  LOG(" avec Sprint_tensor avec index, M0 est : \n%s \n, il y a %ld charactères\n",tensCont, nbChar);

  endian=false;
 
  nbChar = sprint_tensor_TYPE_DOUBLE(&tensCont, M0, true);

  LOG(" avec Sprint_tensor avec index et endian=false, M0 est : \n%s \n, il y a %ld charactères\n",tensCont, nbChar);


  free(tensCont);
  free_tensor_TYPE_DOUBLE(M0);
}


#if 1

TEST(Split_randomInit){
  dimension *d0=create_dim(3);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=4;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_FLOAT(M0,2.7,5.4,50001);

  print_tensor_float(M0, "M0 random");
  print_tensor_msg_TYPE_FLOAT(M0, "M0 random");

  tensor_TYPE_FLOAT *Tpart1=NULL, *Tpart2=NULL;

  //split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 1, 2);
  //split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 2, 3);
  split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 1, 1);

  print_tensor_float(Tpart1, " Tpart1 1");
  //print_tensor_msg_TYPE_FLOAT(Tpart1, " Tpart1 1");
  print_tensor_float(Tpart2, "Tpart2 ..");
  //print_tensor_msg_TYPE_FLOAT(Tpart2, "Tpart2 ..");

//  printDebug_dimension(Tpart1->dim,"dim part1 "); 
//  printDebug_dimension(Tpart2->dim,"dim part2 "); 
//  printDebug_dimension(M0->dim,"dim root "); 

  free_tensor_TYPE_FLOAT(M0);
  free_dimension(Tpart1->dim);
  free_dimension(Tpart2->dim);
  free(Tpart1);
  free(Tpart2);
}
#endif

#if 1

TEST(Split_randomInit){
  //endian=false;
  dimension *d0=create_dim(3);

  d0->perm[0]=4;
  d0->perm[1]=3;
  d0->perm[2]=5;
  

  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_FLOAT(M0,2.7,5.4,50001);

  print_tensor_float(M0, "M0 random");

  tensor_TYPE_FLOAT *Tpart1=NULL, *Tpart2=NULL;

  //split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 2, 4);
  split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 0, 1);
  //split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 2, 1);

  print_tensor_float(Tpart1, " Tpart1 1");
  print_tensor_float(Tpart2, "Tpart2 ..");

  printDebug_dimension(Tpart1->dim,"dim part1 "); 
  printDebug_dimension(Tpart2->dim,"dim part2 "); 
  printDebug_dimension(M0->dim,"dim root "); 

  free_tensor_TYPE_FLOAT(M0);
  free_dimension(Tpart1->dim);
  free_dimension(Tpart2->dim);
  free(Tpart1);
  free(Tpart2);
}
#endif


#if 1

TEST(SplitOne_randomInit){
  dimension *d0=create_dim(1);

  d0->perm[0]=4;


  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_FLOAT(M0,2.7,5.4,50001);

  print_tensor_float(M0, "M0 random");

  tensor_TYPE_FLOAT *Tpart1=NULL, *Tpart2=NULL;

  if(endian){
    split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 0, 1);
  }else{
    split_tensor_TYPE_FLOAT(M0,&Tpart1,&Tpart2, 0, 3);
  }

  print_tensor_float(Tpart1, " Tpart1 1");
  print_tensor_float(Tpart2, "Tpart2 ..");

  printDebug_dimension(Tpart1->dim,"dim part1 ");
  printDebug_dimension(Tpart2->dim,"dim part2 ");
  printDebug_dimension(M0->dim,"dim root ");

  for(size_t i=0;i<(Tpart1->dim)->rank;++i) Tpart1->x[i]=0;
  print_tensor_float(Tpart1, "Tpart1 0");
  print_tensor_float(M0, "M0 Tpart1 0");

  free_tensor_TYPE_FLOAT(M0);
  free_dimension(Tpart1->dim);
  free_dimension(Tpart2->dim);
  free(Tpart1);
  free(Tpart2);
}
#endif

TEST(tensorProd ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=2;
  d1->perm[1]=3;//3;

#else


  d0->perm[0]=35;
  d0->perm[1]=32; //3;
  d0->perm[2]=23;

  d1->perm[0]=32;
  d1->perm[1]=23;//3;
#endif

  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  print_tensor_float(M0,"M0");
  print_tensor_float(M1,"M1");


  tensor_TYPE_FLOAT *M=NULL; 
  tensor_TYPE_FLOAT *Mn=NULL; 

  tensorProd_TYPE_FLOAT(&M,M0,M1);
  tensorProdNotOpt_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  print_tensor_float(M,"M");

  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  print_tensor_float(Mn,"Mn");
  
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
}

TEST(tensorContractnProd_TYPE_FLOAT ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=2;
  d1->perm[1]=3;//3;
  d1->perm[2]=8;

#else


  d0->perm[0]=35;
  d0->perm[1]=32; //3;
  d0->perm[2]=23;

  d1->perm[0]=32;
  d1->perm[1]=23;//3;
  d1->perm[2]=44;
#endif


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

  tensor_TYPE_FLOAT *M=NULL;
  tensor_TYPE_FLOAT *MnO=NULL;

  tensorContractnProd_TYPE_FLOAT(&M, M0,M1,2);
  tensorContractnProdNotOpt_TYPE_FLOAT(&MnO, M0,M1,2);


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
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=2;
  d1->perm[1]=3;//3;
  d1->perm[2]=8;

#else


  d0->perm[0]=35;
  d0->perm[1]=32; //3;
  d0->perm[2]=23;

  d1->perm[0]=32;
  d1->perm[1]=23;//3;
  d1->perm[2]=44;
#endif

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

  tensor_TYPE_FLOAT *M=NULL;
  tensor_TYPE_FLOAT *MnO=NULL;

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
TEST(tensorContractnProd_TYPE_DOUBLE_2_1 ){
  dimension *d0=create_dim(2);
  dimension *d1=create_dim(1);
#if VALGRIND_
  d0->perm[0]=4;
  d0->perm[1]=2; //3;

  d1->perm[0]=2;

#else

  d0->perm[0]=125;
  d0->perm[1]=52; //3;

  d1->perm[0]=52;
#endif

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  print_tensor_double(M0,"M0");
  print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M=NULL;
  tensor_TYPE_DOUBLE *MnO=NULL;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,1);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  tensorContractnProdNotOpt_TYPE_DOUBLE(&MnO, M0,M1,1);

  print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}


TEST(tensorContractnProd_TYPE_DOUBLE_2_2 ){
  dimension *d0=create_dim(2);
  dimension *d1=create_dim(2);
#if VALGRIND_
  d0->perm[0]=4;
  d0->perm[1]=2; //3;

  d1->perm[0]=2;
  d1->perm[1]=1;

#else

  d0->perm[0]=125;
  d0->perm[1]=52; //3;

  d1->perm[0]=52;
  d1->perm[1]=1;
#endif

  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  print_tensor_double(M0,"M0");
  print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M=NULL;
  tensor_TYPE_DOUBLE *MnO=NULL;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,1);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  tensorContractnProdNotOpt_TYPE_DOUBLE(&MnO, M0,M1,1);

  print_tensor_double(MnO,"MnO");
 
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
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=2;
  d1->perm[1]=3;//3;
  d1->perm[2]=8;

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

  tensor_TYPE_DOUBLE *M=NULL;
  tensor_TYPE_DOUBLE *MnO=NULL;

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


TEST(VStensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=2;
  d1->perm[1]=3;//3;
  d1->perm[2]=8;

#else

  d0->perm[0]=125;
  d0->perm[1]=52; //3;
  d0->perm[2]=63;

  d1->perm[0]=52;
  d1->perm[1]=63;//3;
  d1->perm[2]=154;
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

  tensor_TYPE_DOUBLE *M=NULL;
  tensor_TYPE_DOUBLE *MnO=NULL;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}
TEST(Pthread_tensorContractnPro2d_TYPE_DOUBLE2 ){
 
  endian = false; 
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=2;
  d1->perm[1]=3;//3;
  d1->perm[2]=8;

#else

  d0->perm[0]=125;
  d0->perm[1]=52; //3;
  d0->perm[2]=63;

  d1->perm[0]=52;
  d1->perm[1]=63;//3;
  d1->perm[2]=154;
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

  tensor_TYPE_DOUBLE *M=NULL;
  tensor_TYPE_DOUBLE *MnO=NULL;

  size_t nbthread = 5;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  tensorContractnPro2dThread_TYPE_DOUBLE(&MnO, M0,M1,2,nbthread);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}
TEST(contract_dim1){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(1);
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=3;

#else

  d0->perm[0]=125;
  d0->perm[1]=52; //3;
  d0->perm[2]=63;

  d1->perm[0]=63;
#endif


  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_DOUBLE *M0 = CREATE_TENSOR_TYPE_DOUBLE(d0);
  tensor_TYPE_DOUBLE *M1 = CREATE_TENSOR_TYPE_DOUBLE(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;

  print_tensor_double(M0,"M0");
  print_tensor_double(M1,"M1");

  tensor_TYPE_DOUBLE *M=NULL;
  tensor_TYPE_DOUBLE *MnO=NULL;

  size_t nbthread = 5;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,1);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,1);
  tensorContractnProdThread_TYPE_DOUBLE(&MnO, M0,M1,1,nbthread);

  print_tensor_double(MnO,"MnO");

printDebug_dimension(M0->dim," M0 dimension  ");
printDebug_dimension(M1->dim," M1 dimension  ");
printDebug_dimension(M->dim," M dimension  ");


  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}

TEST(Pthread_tensorContractnProd_TYPE_DOUBLE2 ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(3);
#if VALGRIND_
  d0->perm[0]=5;
  d0->perm[1]=2; //3;
  d0->perm[2]=3;

  d1->perm[0]=2;
  d1->perm[1]=3;//3;
  d1->perm[2]=8;

#else

  d0->perm[0]=125;
  d0->perm[1]=52; //3;
  d0->perm[2]=63;

  d1->perm[0]=52;
  d1->perm[1]=63;//3;
  d1->perm[2]=154;
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

  tensor_TYPE_DOUBLE *M=NULL;
  tensor_TYPE_DOUBLE *MnO=NULL;

  size_t nbthread = 5;

  tensorContractnProd_TYPE_DOUBLE(&M, M0,M1,2);
  //print_tensor_double(M,"M");
  //cl_tensorContractnProd_TYPE_DOUBLE(&MnO, M0,M1,2);
  tensorContractnProdThread_TYPE_DOUBLE(&MnO, M0,M1,2,nbthread);

  //print_tensor_double(MnO,"MnO");
 
  // for(size_t i=0;i<M->dim->rank;++i)
  //    EXPECT_EQ_TYPE_DOUBLE(M->x[i],MnO->x[i]);
    
  EXPECT_ARRAY_EQ_TYPE_DOUBLE(M->x,M->dim->rank,MnO->x,MnO->dim->rank);

  free_tensor_TYPE_DOUBLE(M);
  free_tensor_TYPE_DOUBLE(MnO);
  free_tensor_TYPE_DOUBLE(M0);
  free_tensor_TYPE_DOUBLE(M1);

}
TEST(tensorProd_vs ){
  
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);


#if VALGRIND_
  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=2;
  
  d1->perm[0]=2;
  d1->perm[1]=3;

#else

  d0->perm[0]=212;
  d0->perm[1]=13;
  d0->perm[2]=22;
  
  d1->perm[0]=121;
  d1->perm[1]=43;
#endif


  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;


  tensor_TYPE_FLOAT *M=NULL; 
  tensor_TYPE_FLOAT *Mn=NULL; 

  tensorProd_TYPE_FLOAT(&M,M0,M1);
  //tensorProdNotOpt_TYPE_FLOAT(&Mn,M0,M1);
  tensorProd_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);


  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}
TEST(tensorProd_vsThread ){
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

#if VALGRIND_
  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=2;
  
  d1->perm[0]=2;
  d1->perm[1]=3;

#else

  d0->perm[0]=212;
  d0->perm[1]=13;
  d0->perm[2]=22;
  
  d1->perm[0]=121;
  d1->perm[1]=43;
#endif




  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.1 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;



  tensor_TYPE_FLOAT *M=NULL; 
  tensor_TYPE_FLOAT *Mn=NULL; 

  size_t nbthread = 5;

  tensorProdThread_TYPE_FLOAT(&M,M0,M1,nbthread);
  //tensorProdNotOpt_TYPE_FLOAT(&Mn,M0,M1);
  tensorProd_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);

  //EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}

TEST(tensorProd_vsThread2d ){
  //endian =true;
  dimension *d0=create_dim(3);
  dimension *d1=create_dim(2);

#if VALGRIND_
  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=2;
  
  d1->perm[0]=2;
  d1->perm[1]=3;

#else

  d0->perm[0]=212;
  d0->perm[1]=13;
  d0->perm[2]=22;
  
  d1->perm[0]=121;
  d1->perm[1]=43;
#endif




  updateRankDim(d0);
  updateRankDim(d1);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_TYPE_FLOAT(d1);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);
  LOG("M1->dim->rank = %ld\n",M1->dim->rank);
  for(size_t i=0; i<M0->dim->rank;++i) M0->x[i]=i*0.01 +1;
  for(size_t i=0; i<M1->dim->rank;++i) M1->x[i]=i*0.003 + 2;


  tensor_TYPE_FLOAT *M=NULL; 
  tensor_TYPE_FLOAT *Mn=NULL; 

  size_t nbthread = 5;

  tensorProdThrea2d_TYPE_FLOAT(&M,M0,M1,nbthread);
  //tensorProdNotOpt_TYPE_FLOAT(&Mn,M0,M1);
  tensorProd_TYPE_FLOAT(&Mn,M0,M1);
  LOG("M->dim->rank = %ld\n",M->dim->rank);
  LOG("Mn->dim->rank = %ld\n",Mn->dim->rank);


  EXPECT_ARRAY_EQ_TYPE_FLOAT(M->x,M->dim->rank,Mn->x,Mn->dim->rank);

  free_tensor_TYPE_FLOAT(M);
  free_tensor_TYPE_FLOAT(Mn);
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}

TEST(parseInput_withDim_to_tensor){
  endian=true;
  char *input="[2,3]"\
               "((1.21,10,0.23)"\
               "(.56,124,22.5)) ";

  tensor_TYPE_FLOAT *t=parseInput_withDim_to_tensor_TYPE_FLOAT(input);

  print_tensor_msg_TYPE_FLOAT(t," tensor from input" );

  free_tensor_TYPE_FLOAT(t);
}

TEST(parseInput_unknownpart_to_tensor){
  //endian=true;
  endian=true;
  char *input="[*,3]"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "(.56,124,22.5)) ";

  tensor_TYPE_FLOAT *t=parseInput_withDim_to_tensor_TYPE_FLOAT(input);

  print_tensor_msg_TYPE_FLOAT(t," tensor from input" );

  free_tensor_TYPE_FLOAT(t);
}

TEST(parseInput_unknownpart_to_tensorendfalse){
  endian=false;
  char *input="[3,_]"\
               "((1.21,10,0.23,21)"\
               "((1.21,10,0.23,.1)"\
               "(.56,124,22.5,1.44))";

  tensor_TYPE_FLOAT *t=parseInput_withDim_to_tensor_TYPE_FLOAT(input);

  print_tensor_msg_TYPE_FLOAT(t," tensor from input" );

  free_tensor_TYPE_FLOAT(t);
}

TEST(transpose_parseInput_unknownpart_to_tensor){
  endian=true;
  char *input="[*,3]"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "(.56,124,22.5)) ";

  tensor_TYPE_FLOAT *t=parseInput_withDim_to_tensor_TYPE_FLOAT(input);

  print_tensor_msg_TYPE_FLOAT(t," tensor from input" );


  tensor_TYPE_FLOAT *transpose = transpose_notOpt_tensor_TYPE_FLOAT(t);
  print_tensor_msg_TYPE_FLOAT(transpose," transpose from input" );

  free_tensor_TYPE_FLOAT(t);
  free_tensor_TYPE_FLOAT(transpose);
}
TEST(permute_parseInput_unknownpart_to_tensor){
  endian=true;
  char *input="[*,3]"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "((1.21,10,0.23)"\
               "(.56,124,22.5)) ";

  tensor_TYPE_FLOAT *t=parseInput_withDim_to_tensor_TYPE_FLOAT(input);

  print_tensor_msg_TYPE_FLOAT(t," tensor from input" );

  dimension *dperm=create_reverse_dim((t->dim)->size);
  tensor_TYPE_FLOAT *transpose = permute_notOpt_tensor_TYPE_FLOAT(t, dperm);
  print_tensor_msg_TYPE_FLOAT(transpose," permute from input" );

  free_dimension(dperm);
  free_tensor_TYPE_FLOAT(t);
  free_tensor_TYPE_FLOAT(transpose);
}
TEST(parseInputOutput_unknownpart_to_tensor){
  endian=true;
  char *input="[*,3,2]"\
               "((0,0,0),(1,2)"\
               "((0,0,0,1,2)"\
               "((0,0,0,1,2)"\
               "((0,0,0,1,2)"\
               "((0,0,0,1,2)"\
               "(0,0,0,2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}

TEST(parseInputOutput_knownpart_to_tensor){
  endian=true;
  char *input="[6,3,2]"\
               "((0,0,0),(1,2)"\
               "((0,0,0,1,2)"\
               "((0,0,0,1,2)"\
               "((0,0,0,1,2)"\
               "((0,0,0,1,2)"\
               "(0,0,0,2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}

TEST(parseInputOutput_unknownpart2dimInput_to_tensor){
  endian=true;
  char *input="[*,2,3,2]"\
               "((0,0,0)(8,8,8),(1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "(0,0,0),(8,8,8),2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}

TEST(parseInputOutput_knownpart2dimInput_to_tensor){
  endian=true;
  char *input="[6,2,3,2]"\
               "((0,0,0)(8,8,8),(1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "((0,0,0),(8,8,8),1,2)"\
               "(0,0,0),(8,8,8),2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}


TEST(parseInputOutput_unknownpart1dimInput_2output_to_tensor){
  endian=true;
  char *input="[*,3,3,2]"\
               "((0,0,0)(8,8)(8,8),(1,2)"\
               "((0,0,0),(8,8)(8,8),1,2)"\
               "((0,0,0),(8,8,(8,8),1,2)"\
               "((0,0,0),(8,8,8)8,1,2)"\
               "((0,0,0),(8,8,8)8,1,2)"\
               "(0,0,0),(8,8,8)8,2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 2);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}


TEST(parseInputOutput_knownpart1dimInput_2output_to_tensor){
  endian=true;
  char *input="[6,3,3,2]"\
               "((0,0,0)(8,8)(8,8),(1,2)"\
               "((0,0,0),(8,8)(8,8),1,2)"\
               "((0,0,0),(8,8,(8,8),1,2)"\
               "((0,0,0),(8,8,8)8,1,2)"\
               "((0,0,0),(8,8,8)8,1,2)"\
               "(0,0,0),(8,8,8)8,2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 2);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}


TEST(parseInputOutput_unknownpart1dimInput_1output_to_tensor){
  endian=true;
  char *input="[*,8,1]"\
               "((0,0,0)(8,8)(8,8),(1,2)"\
               "((0,0,0),(8,8)(8,8),1,2)"\
               "((0,0,0),(8,8,(8,8),1,2)"\
               "((0,0,0),(8,8,8)8,1,2)"\
               "((0,0,0),(8,8,8)8,1,2)"\
               "(0,0,0),(8,8,8)8,2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}


TEST(parseInputOutput_knownpart1dimInput_1output_to_tensor){
  endian=true;
  char *input="[6,8,1]"\
               "((0,0,0)(8,8)(8,8),(1,2)"\
               "((0,0,0),(8,8)(8,8),1,2)"\
               "((0,0,0),(8,8,(8,8),1,2)"\
               "((0,0,0),(8,8,8)8,1,7)"\
               "((0,0,0),(8,8,8)8,1,5)"\
               "(0,0,0),(8,8,8)8,2,4)) ";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parseInputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , input, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from input" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from input" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}

TEST(parseInputOutput_file_knownpart1dimInput_1output_to_tensor){
  endian=true;
  char *inputfile="input.txt";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parse_file_InputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , inputfile, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from inputfile" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from inputfile" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}



TEST(parseInputOutput_file_knownpart1dimInput_1output_to_tensor){
  endian=true;
  char *inputfile="unkinput.txt";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parse_file_InputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , inputfile, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from inputfile" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from inputfile" );



  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}



TEST(array_from_parseInputOutput_file_knownpart1dimInput_1output_to_tensor){
  endian=true;
  char *inputfile="unkinput.txt";

  tensor_TYPE_FLOAT *t0=NULL,*t1=NULL;
  parse_file_InputOutput_withDim_to_tensors_TYPE_FLOAT(&t0,&t1 , inputfile, 1);

  print_tensor_msg_TYPE_FLOAT(t0," t0 from inputfile" );
  print_tensor_msg_TYPE_FLOAT(t1," t1 from inputfile" );

  tensor_TYPE_FLOAT **arrt0 =  fromInput_to_array_tensor_TYPE_FLOAT(t0);
  tensor_TYPE_FLOAT **arrt1 =  fromInput_to_array_tensor_TYPE_FLOAT(t1);


  size_t sz0=(t0->dim)->perm[0];
  size_t sz1=(t1->dim)->perm[0];
  char msg[256];

  for(size_t i=0; i< sz0; ++i){
    sprintf(msg," array t0 [%ld ] ",i);
    print_tensor_msg_TYPE_FLOAT(arrt0[i],msg);
  }
  for(size_t i=0; i< sz1; ++i){
    sprintf(msg," array t1 [%ld ] ",i);
    print_tensor_msg_TYPE_FLOAT(arrt1[i],msg);
  }

  for(size_t i=0; i< sz0; ++i) free_tensor_TYPE_FLOAT(arrt0[i]);
  for(size_t i=0; i< sz1; ++i) free_tensor_TYPE_FLOAT(arrt1[i]);
  
  free(arrt0);
  free(arrt1);

  free_tensor_TYPE_FLOAT(t0);
  free_tensor_TYPE_FLOAT(t1);
}

float func2(float x){
  return x*x+1;
}

TEST(print_tensor){
  dimension *d0=create_dim(3);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=4;


  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_FLOAT(M0,2.7,5.4,50001);

  print_tensor_float(M0, "init M0 random");
  
  update_1tensor_func_TYPE_FLOAT(M0, func2, 5); 

  print_tensor_float(M0, "x*x+1 M0 random");
  free_tensor_TYPE_FLOAT(M0);
}

TEST(rec_in_file_tensor){
  dimension *d0=create_dim(3);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=4;


  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_FLOAT(M0,2.7,5.4,50001);

  print_tensor_float(M0, "init M0 random");
  
  update_1tensor_func_TYPE_FLOAT(M0, func2, 5); 

  fprint_tensor_TYPE_FLOAT(".ffrec_randomTens.txt",M0);
  free_tensor_TYPE_FLOAT(M0);
}

TEST(copy_tensor){
  dimension *d0=create_dim(3);

  d0->perm[0]=2;
  d0->perm[1]=3;
  d0->perm[2]=4;


  updateRankDim(d0);


  tensor_TYPE_FLOAT *M0 = CREATE_TENSOR_TYPE_FLOAT(d0);
  tensor_TYPE_FLOAT *M1 = CREATE_TENSOR_FROM_CPY_DIM_TYPE_FLOAT(d0);

  LOG("M0->dim->rank = %ld\n",M0->dim->rank);

  init_random_x_TYPE_FLOAT(M0,2.7,5.4,50001);
  init_random_x_TYPE_FLOAT(M1,2.7,5.4,50001);

  print_tensor_float(M0, "init M0 random");

  copy_tensor_TYPE_FLOAT(M1, M0);
  print_tensor_float(M1, "M1 copy of M0");
  
  free_tensor_TYPE_FLOAT(M0);
  free_tensor_TYPE_FLOAT(M1);
}






int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
