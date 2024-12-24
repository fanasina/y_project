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
#include "y_socket/y_socket.h"

#define VALGRIND_ 1

TEST(first){
  
  LOG("hey%s\n"," you");
  
}


int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
