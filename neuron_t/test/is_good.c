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
#include "neuron_t/neuron_t.h"

#define VALGRIND_ 1

TEST(init_One){

  neurons_TYPE_FLOAT *bn=NULL;
  setup_networks_OneD_TYPE_FLOAT(&bn, (size_t[]){3,4,2},3);
  print_neurons_msg_TYPE_FLOAT(bn,"bn");
  init_in_out_all_networks_OneD_TYPE_FLOAT(bn,(float[]){1.2,0.5,1.3},3,(float[]){0.1,0.8},2);


}

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
