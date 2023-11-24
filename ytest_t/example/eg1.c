#include "ftest/ftest.h"

TEST(foo){
  PRINTF("first test\n");
  int a=1;
  EXPECT_TRUE(1==a);
}

TEST(foo){ /* same name*/
  sleep(2);
  float a=0.001, b=0.0005;
  PRINTF("after sleeping 2 seconds, we test if %f ?= 2*%f\n",a,b);
  EXPECT_EQ_TYPE_FLOAT(a,2*b);
}

TEST(foo){
  sleep(1);
  double a=0.001, b=0.0001;
  LOG("after 1 sec, \n");
  EXPECT_LT_TYPE_DOUBLE(b,a);
  ASSERT_GE_TYPE_DOUBLE(a,b);
  ASSERT_LE_TYPE_DOUBLE(a,b);
  LOG("this line will not print");
}

TEST(){
  EXPECT_TRUE(2==1);
  LOG("this line will print: the precedent expect failed\n");
}
TEST(){
  sleep(1);
  EXPECT_FALSE(2==1);
}

TEST(an_other_test){
  LOG("FINAL, no test, only sleep\n");
  sleep(2);
}

int main(int argc, char **argv){
  run_all_tests_args(argc,argv);
  return 0;
}
