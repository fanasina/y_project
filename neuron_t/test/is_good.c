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
#include "neuron_t/nneuron_t_file.h"

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
  setup_networks_OneD_TYPE_FLOAT(&bn, (size_t[]){3,5,2},3,false,0,1,5000);
  init_in_out_all_networks_OneD_TYPE_FLOAT(bn,(float[]){1.2,0.5,1.3},3,(float[]){0.1,0.8},2);

  
  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 2, 3, 0.7);

  print_neurons_msg_TYPE_FLOAT(bn,"bn init");

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


  print_neurons_msg_TYPE_FLOAT(bn,"bn after ");

  LOG(" error : %f\n", error_out_TYPE_FLOAT(bn));

  free_neurons_TYPE_FLOAT(bn);
}

#if 0
TEST(data_set_from_file){
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("data.txt",1);

  print_data_set_msg_TYPE_FLOAT(ds,"data");

  free_data_set_TYPE_FLOAT(ds);

}
#endif 

#define epsilon 0.0001

bool cond(float e, size_t nbreps){
  if (nbreps > 20000) return true;
  if ((e<epsilon) && (e>-epsilon)) return true;
  return false;
}

TEST(learning_first){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
  print_data_set_msg_TYPE_FLOAT(ds,"data");
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  setup_networks_OneD_TYPE_FLOAT(&bn, (size_t[]){2,4,1},3,false,0,1,5000); /* 2 input , 1 target; 1 hidden layer with 5 neurons */

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 1 ,  0.1);


  size_t reps = learning_online_neurons_TYPE_FLOAT(bn,ds,cond);
  
 
  //char msg[256];
  for(size_t i=0; i<ds->size; ++i){
    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
    //print_predict_by_network_neurons_TYPE_FLOAT(bn,ds->input[i]);
    /*sprintf(msg, "data set [%ld]",i);
    init_copy_in_out_networks_from_tensors_TYPE_FLOAT(bn, ds->input[i],ds->target[i]);\
      tmp=bn->next_layer;\
      while(tmp){\
        calc_out_neurons_TYPE_FLOAT(tmp);\
        tmp = tmp->next_layer;\
      }
    print_neurons_msg_TYPE_FLOAT(bn, msg);
    */
  }
  
  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;
}



TEST(learning_second_PRINT){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
//  print_data_set_msg_TYPE_FLOAT(ds,"data");
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  setup_networks_OneD_TYPE_FLOAT(&bn, (size_t[]){2,4,1},3,false,0,1,5000); /* 2 input , 1 target; 1 hidden layer with 5 neurons */

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 3 ,  0.1);


  size_t reps = learning_online2_neurons_TYPE_FLOAT(bn,ds,cond);
  
 
  char msg[256];
  for(size_t i=0; i<ds->size; ++i){
    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
    //print_predict_by_network_neurons_TYPE_FLOAT(bn,ds->input[i]);
    /*sprintf(msg, "data set [%ld]",i);
    init_copy_in_out_networks_from_tensors_TYPE_FLOAT(bn, ds->input[i],ds->target[i]);\
      tmp=bn->next_layer;\
      while(tmp){\
        calc_out_neurons_TYPE_FLOAT(tmp);\
        tmp = tmp->next_layer;\
      }
    print_neurons_msg_TYPE_FLOAT(bn, msg);
  */
  }
 

  PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, bn, input, " bn input");
  PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, bn, output, " bn output");
  PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, bn, bias, " bn bias");

  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;
}

TEST(learning_withconfig2){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
//  print_data_set_msg_TYPE_FLOAT(ds,"data");
  config_layers *pconf = create_config_layers_from_OneD(3,(size_t[]){2,4,1}); /* 2 input , 1 target; 1 hidden layer with 5 neurons */
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  //setup_networks_alloutputs_config_GLOBAL_rdm01_TYPE_FLOAT(setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf);bn,pconf);
     setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf,false,0,1,5000);

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 1 ,  0.1);


  size_t reps = learning_online2_neurons_TYPE_FLOAT(bn,ds,cond);
  
 
  char msg[256];
  for(size_t i=0; i<ds->size; ++i){
    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
    
  }
 


  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;
}


TEST(learning_cloneuroneset){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
//  print_data_set_msg_TYPE_FLOAT(ds,"data");
  config_layers *pconf = create_config_layers_from_OneD(3,(size_t[]){2,4,1}); /* 2 input , 1 target; 1 hidden layer with 5 neurons */
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  //setup_networks_alloutputs_config_GLOBAL_rdm01_TYPE_FLOAT(setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf);bn,pconf);
     setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf,false,0,1,5000);

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 1 ,  0.1);

  //print_neurons_msg_TYPE_FLOAT(bn,"before create clones");

  cloneuronset_TYPE_FLOAT *clnrnst = create_cloneuronset_from_base_conf_TYPE_FLOAT(bn, pconf, 3);

//  size_t reps = learning_online2_neurons_TYPE_FLOAT(bn,ds,cond);
  size_t reps = learning_cloneuronset_TYPE_FLOAT(clnrnst, ds,cond);
  
 
  char msg[256];
  for(size_t i=0; i<ds->size; ++i){
    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
    
  }
 

  free_cloneuronset_TYPE_FLOAT(clnrnst);

  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;

}


TEST(learning_cloneuroneset_LEARN_RATE){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
//  print_data_set_msg_TYPE_FLOAT(ds,"data");
  config_layers *pconf = create_config_layers_from_OneD(3,(size_t[]){2,4,1}); /* 2 input , 1 target; 1 hidden layer with 5 neurons */
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  //setup_networks_alloutputs_config_GLOBAL_rdm01_TYPE_FLOAT(setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf);bn,pconf);
     setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf,false,0,1,5000);

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 1 ,  0.4);
  float initRate=0.6;
  float decayRate=0.85; /* halving*/
  size_t dropRate = 100;
//  setup_learning_rate_params_neurons_TYPE_FLOAT(bn, initRate, decayRate, dropRate, time_based_update_learning_rate_TYPE_FLOAT);
  setup_learning_rate_params_neurons_TYPE_FLOAT(bn, initRate, decayRate, dropRate, step_based_update_learning_rate_TYPE_FLOAT);

  //print_neurons_msg_TYPE_FLOAT(bn,"before create clones");

  cloneuronset_TYPE_FLOAT *clnrnst = create_cloneuronset_from_base_conf_TYPE_FLOAT(bn, pconf, 3);

//  size_t reps = learning_online2_neurons_TYPE_FLOAT(bn,ds,cond);
  size_t reps = learning_cloneuronset_TYPE_FLOAT(clnrnst, ds,cond);
  
 
  char msg[256];
  for(size_t i=0; i<ds->size; ++i){
    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
    
  }
 

  free_cloneuronset_TYPE_FLOAT(clnrnst);

  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;

}

TEST(copy_weight_in_neurons){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
//  print_data_set_msg_TYPE_FLOAT(ds,"data");
  config_layers *pconf = create_config_layers_from_OneD(3,(size_t[]){2,4,1}); /* 2 input , 1 target; 1 hidden layer with 5 neurons */
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  neurons_TYPE_FLOAT *cpyn=NULL;
  //setup_networks_alloutputs_config_GLOBAL_rdm01_TYPE_FLOAT(setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf);bn,pconf);
     setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf,false,0,1,5000);
     setup_networks_alloutputs_config_TYPE_FLOAT(&cpyn, pconf,false,0,1,5000);

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 1 ,  0.1);


  size_t reps = learning_online2_neurons_TYPE_FLOAT(bn,ds,cond);
  
  setup_all_layers_functions_TYPE_FLOAT(cpyn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(cpyn, 5, 1 ,  0.1);


  copy_weight_in_neurons_TYPE_FLOAT(cpyn, bn);
 
  char msg[256];
  tensor_TYPE_FLOAT * linked_tens = NULL;
  for(size_t i=0; i<ds->size; ++i){
//    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
 //   print_predict_by_network_with_error_neurons_TYPE_FLOAT(cpyn,ds->input[i],ds->target[i]);
    calculate_output_by_network_neurons_TYPE_FLOAT(bn,ds->input[i],&linked_tens);
    sprintf(msg," output base %ld ",i);
    print_tensor_msg_TYPE_FLOAT(linked_tens,msg);
    calculate_output_by_network_neurons_TYPE_FLOAT(cpyn,ds->input[i],&linked_tens);
    sprintf(msg," output copy %ld ",i);
    print_tensor_msg_TYPE_FLOAT(linked_tens,msg);
  }

  EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, bn, weight_in, ".ff_bn_weight_in.txt")
 


  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 
  free_neurons_TYPE_FLOAT(cpyn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;
}


TEST(Extract_weight_in_neurons){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
//  print_data_set_msg_TYPE_FLOAT(ds,"data");
  config_layers *pconf = create_config_layers_from_OneD(3,(size_t[]){2,4,1}); /* 2 input , 1 target; 1 hidden layer with 5 neurons */
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  neurons_TYPE_FLOAT *cpyn=NULL;
  //setup_networks_alloutputs_config_GLOBAL_rdm01_TYPE_FLOAT(setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf);bn,pconf);
     setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf,false,0,1,5000);
     setup_networks_alloutputs_config_TYPE_FLOAT(&cpyn, pconf,false,0,1,5000);

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 1 ,  0.1);


  size_t reps = 1;// learning_online2_neurons_TYPE_FLOAT(bn,ds,cond);
  EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, bn, weight_in, ".ff_bn_weight_in__toExtract.txt")
  
  setup_all_layers_functions_TYPE_FLOAT(cpyn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(cpyn, 5, 1 ,  0.1);

  EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, cpyn, weight_in, ".ff_bn_weight_in__toExtract.txt")
//  copy_weight_in_neurons_TYPE_FLOAT(cpyn, bn);
 
  char msg[256];
  tensor_TYPE_FLOAT * linked_tens = NULL;
  for(size_t i=0; i<ds->size; ++i){
//    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
 //   print_predict_by_network_with_error_neurons_TYPE_FLOAT(cpyn,ds->input[i],ds->target[i]);
    calculate_output_by_network_neurons_TYPE_FLOAT(bn,ds->input[i],&linked_tens);
    sprintf(msg," output base %ld ",i);
    print_tensor_msg_TYPE_FLOAT(linked_tens,msg);
    calculate_output_by_network_neurons_TYPE_FLOAT(cpyn,ds->input[i],&linked_tens);
    sprintf(msg," output copy %ld ",i);
    print_tensor_msg_TYPE_FLOAT(linked_tens,msg);
  }

 
  EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, cpyn, weight_in, ".ff_bn_weight_in__exportedCPYfromExtract.txt")


  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 
  free_neurons_TYPE_FLOAT(cpyn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;
}




TEST(Extract_EXPORT_weight_in_neurons){
   bool rec_randomizeInitWeight = randomizeInitWeight;
   randomizeInitWeight =false;
  
  data_set_TYPE_FLOAT *ds= fill_data_set_from_file_TYPE_FLOAT("xor.txt",1);
//  print_data_set_msg_TYPE_FLOAT(ds,"data");
  //config_layers *pconf = create_config_layers_from_OneD(3,(size_t[]){2,4,1}); /* 2 input , 1 target; 1 hidden layer with 5 neurons */
  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3});
  neurons_TYPE_FLOAT *bn=NULL, *tmp ;
  neurons_TYPE_FLOAT *cpyn=NULL;
  //setup_networks_alloutputs_config_GLOBAL_rdm01_TYPE_FLOAT(setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf);bn,pconf);
     setup_networks_alloutputs_config_TYPE_FLOAT(&bn,pconf,false,0,1,5000);
     setup_networks_alloutputs_config_TYPE_FLOAT(&cpyn, pconf,false,0,1,5000);
  
  EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, bn, weight_in, ".ff_target_20240717_01h43m41s_13300.txt")

  setup_all_layers_functions_TYPE_FLOAT(bn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(bn, 5, 1 ,  0.1);


  size_t reps = 1;// learning_online2_neurons_TYPE_FLOAT(bn,ds,cond);
  EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, bn, weight_in, ".ff_bn_weight_in__toCMP.txt")
  
  setup_all_layers_functions_TYPE_FLOAT(cpyn,
    tensorContractnProdThread_TYPE_FLOAT,
    tensorProdThread_TYPE_FLOAT,
    DL,
    L,
    f,
    df);

  setup_all_layers_params_TYPE_FLOAT(cpyn, 5, 1 ,  0.1);

//  EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, cpyn, weight_in, ".ff_bn_weight_in__toExtract.txt")
//  copy_weight_in_neurons_TYPE_FLOAT(cpyn, bn);
 
  char msg[256];
  tensor_TYPE_FLOAT * linked_tens = NULL;
  for(size_t i=0; i<ds->size; ++i){
//    print_predict_by_network_with_error_neurons_TYPE_FLOAT(bn,ds->input[i],ds->target[i]);
 //   print_predict_by_network_with_error_neurons_TYPE_FLOAT(cpyn,ds->input[i],ds->target[i]);
    calculate_output_by_network_neurons_TYPE_FLOAT(bn,ds->input[i],&linked_tens);
    sprintf(msg," output base %ld ",i);
    print_tensor_msg_TYPE_FLOAT(linked_tens,msg);
    calculate_output_by_network_neurons_TYPE_FLOAT(cpyn,ds->input[i],&linked_tens);
    sprintf(msg," output copy %ld ",i);
    print_tensor_msg_TYPE_FLOAT(linked_tens,msg);
  }

 
//  EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, cpyn, weight_in, ".ff_bn_weight_in__exportedCPYfromExtract.txt")


  free_data_set_TYPE_FLOAT(ds);
  free_neurons_TYPE_FLOAT(bn); 
  free_neurons_TYPE_FLOAT(cpyn); 

  LOG("reps = %ld\n",reps);
  randomizeInitWeight = rec_randomizeInitWeight;
}






int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
