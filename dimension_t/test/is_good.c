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


//#include "permutation_t/permutation_t.h"
#include "dimension_t/dimension_t.h"

TEST(dimension0){

  dimension *D = create_dim(5);

  EXPECT_EQ(D->size,5);

}


int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
