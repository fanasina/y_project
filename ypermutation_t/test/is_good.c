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

  PRINTF("test size_permutation2\n");
  free_permut_TYPE_CHAR(p);
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

  for(int i = 0; i < translate_p->size; ++i) PRINTF(" ([%d] %ld) ,",i,translate_p->perm[i]);
  PRINTF("\n");
  for(int i = 0; i < p->size; ++i) PRINTF(" (%d: %f) ,",i,p->perm[i]);
  PRINTF("\n");
  
  free_permut_TYPE_FLOAT(p);
//  sleep(n);

}

TEST(not_permutation_)
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
  
  EXPECT_FALSE(IS_PERMUTATION_TYPE_FLOAT(p));

  
  free_permut_TYPE_FLOAT(p);
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
  p->perm[2]=0.1101;
  p->perm[3]=0.02;
  p->perm[4]=0.2;
  p->perm[5]=0.1;
  
  EXPECT_TRUE(IS_PERMUTATION_TYPE_FLOAT(p));


  free_permut_TYPE_FLOAT(p);
//  sleep(n);

}


TEST(float_equal){
  PRINTF("another size_permutation2 float\n");
  ASSERT_TRUE(true);
  float a = 1.00001f;
  float b = 1.00001001f;
  ASSERT_EQ_TYPE_FLOAT(a,b);
  b=1.0000010001f;
  ASSERT_EQ_TYPE_FLOAT(1.000001000,b);
}
TEST(double_equal){
  PRINTF("another size_permutation2 double\n");
  ASSERT_TRUE(true);
  double a = 1.00000001;
  double b = 1.00000001;
  ASSERT_EQ_TYPE_DOUBLE(a,b);
  b=1.00000001000000001;
  ASSERT_EQ_TYPE_DOUBLE(a,b);
  ASSERT_EQ_TYPE_DOUBLE(1.0000000100000002,b);
}


TEST(){
  int a = 5;
  long b = 5;
  ASSERT_EQ(a,b);
}

TEST(expect){
 // SKIP();
  SKIP("%s\n","on skip eq string");
  EXPECT_EQ_TYPE_STRING("hello","hello");
  float f1 = 1.00019999, f2=1.00019999;
  EXPECT_EQ_TYPE_FLOAT(f1,f2);

}


TEST(){

  PERMUTATION_TYPE_CHAR *p_char = CREATE_PERMUTATION_TYPE_CHAR(7);
  p_char->perm[0]='B';
  p_char->perm[1]='A';
  p_char->perm[2]='Y';
  p_char->perm[3]='C';
  p_char->perm[4]='D';
  p_char->perm[5]='Z';
  p_char->perm[6]='\0';
  
  PERMUTATION_TYPE_SIZE_T *tr_p_char = TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR(p_char);

  for(int i = 0; i < tr_p_char->size; ++i) PRINTF(" [%d ]%ld ,",i,tr_p_char->perm[i]);
  PRINTF("p_char == %s\n",p_char->perm);
  free_permut_TYPE_CHAR(p_char);
  free_permut_TYPE_SIZE_T(tr_p_char);
}

TEST(){

  PERMUTATION_TYPE_CHAR *p_char = CREATE_PERMUTATION_TYPE_CHAR(6);
 /* 
  p_char->perm[0]='B';
  p_char->perm[1]='A';
  p_char->perm[2]='Y';
  p_char->perm[3]='C';
  p_char->perm[4]='D';
  p_char->perm[5]='Z';
*/
  p_char->perm[0]='6';
  p_char->perm[1]='1';
  p_char->perm[2]='2';
  p_char->perm[3]='3';
  p_char->perm[4]='4';
  p_char->perm[5]='5';

  PRINTF("init :%s \n",p_char->perm);
  PERMUTATION_TYPE_SIZE_T *tab_45 = TRANSLATE_TO_SET_THEORIC_SIZE_T_TYPE_CHAR(p_char);
  for(size_t i=0; i<p_char->size; ++i) PRINTF(" %ld: %ld \n",i, tab_45->perm[i]);

 //
  size_t pl = TabToPlaceAlgo_TYPE_CHAR(p_char);
  //size_t pl = TabToPlaceOpt1_TYPE_CHAR(p_char);
  PRINTF("sa place est :%ld \n", pl);
  long int rank=450-1;
  /* in the article the rank is between 1 to n! , here the rank is between 0 to n! -1 */
   tab_45 = PlaceToTab_TYPE_CHAR(p_char, rank);

   char * expect_res="652413";
   /*EXPECT_EQ_TYPE_STRING("652413", expect_res);*/ /* the base is 1,2,3,4,5,6 */
   EXPECT_EQ_TYPE_STRING(expect_res, p_char->perm); /* the base is 1,2,3,4,5,6 */

    /*
     * for(size_t i=0; i<p_char->size; ++i) PRINTF(" %ld: %ld \n",i, tab_45->perm[i]);
    PRINTF("ret %ld :%s \n",rank,p_char->perm);
 
  for(long int j=0; j<6; ++j){
    tab_45 = PlaceToTab_TYPE_CHAR(p_char, j);

    for(size_t i=0; i<p_char->size; ++i) PRINTF(" %ld: %ld \n",i, tab_45->perm[i]);
    PRINTF("ret %ld :%s \n",j,p_char->perm);
  }
    */

  free_permut_TYPE_CHAR(p_char);

}

TEST(overflowPlacePerm){
  PERMUTATION_TYPE_CHAR *p_char = CREATE_PERMUTATION_TYPE_CHAR(3);
 p_char->perm[0]='3';
  p_char->perm[1]='1';
  p_char->perm[2]='2';
  p_char->perm[3]='\0';
  
  long int rank=1;
  PERMUTATION_TYPE_SIZE_T *tab_45 = PlaceToTab_TYPE_CHAR(p_char, rank);
  for(size_t i=0; i<p_char->size; ++i) PRINTF(" %ld: %ld \n",i, tab_45->perm[i]);
    PRINTF("ret %ld :%s \n",rank,p_char->perm);
  free_permut_TYPE_CHAR(p_char);
}

#if 0
TEST(lessThan){
  long int a=1,b=2;
  EXPECT_LT(a,b);
  EXPECT_LT(b,a);

}

#if 0
TEST(sleep){sleep(2);}
TEST(sleep){sleep(2);}
TEST(sleep){sleep(2);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}

TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}

TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}
TEST(sleep){sleep(1);}

#endif

MOCK_FUNC(int, f_mock, (), ())
  
EXPECT_MOCK_CALL(int,f_mock, (),false, 2)  {
  EXPECT_EQ_IN_MOCKF(21,21,f_mock);
  EXPECT_EQ(1,3);
  EXPECT_EQ(4,4);
  EXPECT_EQ_IN_MOCKF(23,24,f_mock); return 12;}
EXPECT_MOCK_CALL(int,f_mock, (),1, 1)  { EXPECT_EQ_IN_MOCKF(23,21,f_mock);return 10;}

EXPECT_MOCK_CALL(int,f_mock, (),1==2||2<1, 1)  {return 18;}
EXPECT_MOCK_CALL(int,f_mock, (),1, INFINITY)  {return -18;}

TEST(mockf1){
  INIT_CALLER_MOCK(f_mock);

  for(int i = 0; i<8; ++i){
    
   LOG("call f_mock:%d: ret:%d\n",i,f_mock());
   // int val=f_mock();
    //PRINTF("call f_mock:%d: ret:%d\n",i,val);
  }

}

MOCK_FUNC(int, f2_mock,(int a,int b),(a,b))

STR_PRINT_CUR_VAR(f2_mock, (int a,int b),(a,b)){
  char *ret=malloc(150);
  //char ret[150];
  sprintf(ret,"(int)a: %d, (int)b: %d",a,b);
  return ret;
}


EXPECT_MOCK_CALL(int, f2_mock, (int a,int b), (a<b), 3){
  return a+b;
}

EXPECT_MOCK_CALL(int, f2_mock, (int a,int b), ((a<b)&&(b<100)), 1){
  return a*b;
}

WILL_MOCK_CALL(int, f2_mock, (int a,int b), (a!=b), 6){
  return a/b;
}
EXPECT_MOCK_CALL(int, f2_mock, (int a,int b), (a==b), 1){
  return a/b;
}



MOCK_FUNC(int, f3_mock,(int a,int b),(a,b))

EXPECT_MOCK_CALL(int, f3_mock, (int a,int b), (a<b), 2){
  return a+b;
}

EXPECT_MOCK_CALL(int, f2_mock, (int a,int b), ((a<b)&&(b<100)), 1){
  return a*b;
}

WILL_MOCK_CALL(int, f2_mock, (int a,int b), (a!=b), 6){
  return a/b;
}
EXPECT_MOCK_CALL(int, f2_mock, (int a,int b), (a==b), 1){
  return a/b;
}




EXPECT_MOCK_CALL(int, f2_mock, (int a,int b), (1), INFINITY){
  return a*b;
}

TEST(f2mock_test){
  INIT_CALLER_MOCK(f2_mock);
  //LOG("--------------------------- > call f2_mock:%d: %d\n",0,f2_mock(1,4));
  
  
  for(int i=0; i<8; ++i){

    if(i<2) {
      //int val = f2_mock(i,4);
      //LOG("call f2_mock:%d: %d\n",i,val);
      LOG("call f2_mock:%d: %d\n",i,f2_mock(i,4));

    }
    else if(i<4) LOG("call:%d: %d\n",i,f2_mock(i,3));
    else LOG("call:%d:%d\n",i,f2_mock(i,i*i));
  }
  
}


TEST(f3_mock_test){
  INIT_CALLER_MOCK(f3_mock);
  
  
  for(int i=0; i<7; ++i){

    if(i<1) {
     LOG("call f3_mock:%d: %d\n",i,f3_mock(1,i));

    }
    else LOG("call:%d:%d\n",i,f3_mock(i,i*i));
  }
  for(int i=COLOR_SZ-1; i>=0; --i)
    LOG("%s colors_fld\n",colors_f[i]);

}

MOCK_FUNC(int, f4_mock,(int a,int b),(a,b))
STR_PRINT_CUR_VAR(f4_mock, (int a,int b),(a,b)){
  char *ret=malloc(150);
  //char ret[150];
  sprintf(ret,"(int)a: %d, (int)b: %d",a,b);
  return ret;
}

TEST(f4_mock_test){
  //EXPECT_EQ(1,f4_mock(1,1));
  PRINTF("f4 no excepted create ret: %d\n",f4_mock(1,1));
  PRINTF("second call f4 : %d\n",f4_mock(2,0));

}

MOCK_FUNC(int, f5_mock,(int a,int b, int c),(a,b,c))

TEST(f5__mock){
  LOG("f5 ???:%d\n",f5_mock(1,2,3));
  LOG("f5 !!!:%d\n",f5_mock(2,5,3));
}

MOCK_FUNC(int, f6_mock,(int a,int b, int c),(a,b,c))
STR_PRINT_CUR_VAR(f6_mock,(int a,int b, int c),(a,b,c)){
  char *ret=malloc(150);
  sprintf(ret,"(%d,%d,%d)",a,b,c);
  return ret;
}

EXPECT_MOCK_CALL(int, f6_mock,(int a, int b, int c),((a<b)&&(b<c)),1){
  return a+b+c;
}

TEST(f6__mock){
  LOG("f6 6?:%d\n",f6_mock(1,2,3));
  LOG("f6 0?:%d\n",f6_mock(2,5,4));
}


MOCK_FUNC(int, f7_mock,(int a,int b),(a,b))
STR_PRINT_CUR_VAR(f7_mock, (int a,int b),(a,b)){
  char *ret=malloc(150);
  //char ret[150];
  sprintf(ret,"(int)a: %d, (int)b: %d",a,b);
  return ret;
}

EXPECT_MOCK_CALL(int, f7_mock,(int a, int b),(a>b),2){
  return a*b;
}


TEST(f7_mock_test){
  int v0=f7_mock(1,1);
  PRINTF("f7  ret: %d\n",v0);
  int v1=f7_mock(2,0);
  PRINTF("second call f7 : %d\n",v1);

}

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
