#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

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

float L(float t, float o){
  return (o - t) * (o - t)/2;
}
float DL(float t, float o){
  return (o - t);
}

float f(float x){
  return 1/(1+exp((double)(-x)));
}

float df(float x){
  return exp(-x)/ ((1+exp(-x)) * (1+exp(-x)));
}


TEST(init_One){
  //endian=false;
  neurons_TYPE_FLOAT *bn=NULL, *tmp=NULL, *ttmp=NULL;
  setup_networks_OneD_TYPE_FLOAT(&bn, (size_t[]){3,5,2},3);
  init_in_out_all_networks_OneD_TYPE_FLOAT(bn,(float[]){1.2,0.5,1.3},3,(float[]){0.1,0.8},2);

  
  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 2, 0.7);

  //print_neurons_msg_TYPE_FLOAT(bn,"bn");

  tmp=bn->next_layer;
  while(tmp){
    calc_out_neurons_TYPE_FLOAT(tmp);
    ttmp = tmp;
    tmp = tmp->next_layer;
  }


  while(ttmp != bn){
    calc_delta_neurons_TYPE_FLOAT(ttmp);
    update_weight_neurons_TYPE_FLOAT(ttmp);
    ttmp = ttmp->prev_layer;
  }


  print_neurons_msg_TYPE_FLOAT(bn,"bn");

  LOG(" error : %f\n", error_out_TYPE_FLOAT(bn));

  free_neurons_TYPE_FLOAT(bn);
}



int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
