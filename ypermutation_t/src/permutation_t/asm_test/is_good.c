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
#include "fmock/fmock.h"


#include "permutation_t/permutation_t.h"




TEST(size_permutation)
{
  PERMUTATION_TYPE_CHAR *p = CREATE_PERMUTATION_TYPE_CHAR(3);
  
  PRINTF(" size = %lu \n",p->size);
  EXPECT_EQ(p->size, 3);

}


TEST(permutation_t_float_trans)
{
  int n =6;
  PERMUTATION_TYPE_FLOAT *p = CREATE_PERMUTATION_TYPE_FLOAT(n);

  PRINTF(" size = %lu \n",p->size);
  EXPECT_EQ(p->size, n);

  p->perm[0]=0.001;
  p->perm[1]=0.01;
  p->perm[2]=0.00101;
  p->perm[3]=0.02;
  p->perm[4]=0.1;
  p->perm[5]=0.1;


  PERMUTATION_TYPE_SIZE_T *translate_p = TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_FLOAT(p);
  
  size_t expect[]={0,2,1,3,4,4};

  for(size_t i= 0; i<translate_p->size; ++i){
    EXPECT_EQ(translate_p->perm[i], expect[i]);
  }

  for(int i = 0; i < translate_p->size; ++i) PRINTF(" ([%d] %ld) ,",i,translate_p->perm[i]);
  PRINTF("\n");
  for(int i = 0; i < p->size; ++i) PRINTF(" (%d: %f) ,",i,p->perm[i]);
  PRINTF("\n");
  
 
//  sleep(n);

}

TEST(not_permutation_)
{
  int n =8;
  PERMUTATION_TYPE_FLOAT *p = CREATE_PERMUTATION_TYPE_FLOAT(n);

  PRINTF(" size = %lu \n",p->size);
  EXPECT_EQ(p->size, n);

  p->perm[0]=0.001;
  p->perm[1]=0.01;
  p->perm[2]=0.00101;
  p->perm[3]=0.02;
  p->perm[4]=0.1;
  p->perm[5]=0.1;
  
  EXPECT_FALSE(IS_PERMUTATION_TYPE_FLOAT(p));


//  sleep(n);

}



TEST(is_permutation_)
{
  int n =6;
  PERMUTATION_TYPE_FLOAT *p = CREATE_PERMUTATION_TYPE_FLOAT(n);

  PRINTF(" size = %lu \n",p->size);
  EXPECT_EQ(p->size, n);

  p->perm[0]=0.001;
  p->perm[1]=0.01;
  p->perm[2]=0.00101;
  p->perm[3]=0.02;
  p->perm[4]=0.2;
  p->perm[5]=0.1;
  
  EXPECT_TRUE(IS_PERMUTATION_TYPE_FLOAT(p));


//  sleep(n);

}





TEST(){

  PERMUTATION_TYPE_CHAR *p_char = CREATE_PERMUTATION_TYPE_CHAR(6);
  p_char->perm[0]='B';
  p_char->perm[1]='A';
  p_char->perm[2]='Y';
  p_char->perm[3]='C';
  p_char->perm[4]='B';
  p_char->perm[5]='Z';
  
  PERMUTATION_TYPE_SIZE_T *tr_p_char = TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR(p_char);

  for(int i = 0; i < tr_p_char->size; ++i) PRINTF(" [%d ]%ld ,",i,tr_p_char->perm[i]);
  PRINTF("p_char == %s\n",p_char->perm);
}

#if 0


#endif

int main(int argc, char **argv){
  
  //run_all_tests();
  //run_all_tests_parallel(4);

  run_all_tests_args(argc, argv);

  //purge_tests();
  //run_some_tests(8, 1, 2, 2, 3, 3, 0, 4, 1);
  //run_some_tests(8, 5, 7, 1, 1, 1, 1, 1, 1);
  //run_some_tests_one_by_one(3, 1, 2, 2);
  //run_all_tests_exept(2, 1, 3);
  return 0;
}
