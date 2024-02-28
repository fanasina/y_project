#ifndef __NEURON_T_C__H
#define __NEURON_T_C__H

#include <stdlib.h>
#include <pthread.h>

//#include "tools_t/tools_t.h"
#include "tensor_t/tensor_t.h"

struct config_layers{
   size_t nb_layers;
   size_t *sz_layers;
   size_t **array_dim_in_layers;
};
typedef struct config_layers config_layers; 

#define GEN_NEURON_(type)\
\
struct neurons_##type {/* layer */\
  size_t id_layer;\
  size_t nb_prod_thread;\
  size_t nb_calc_thread;\
  type learning_rate;\
  tensor_##type *input; \
  tensor_##type *net; /* output tensor_prodContract */\
  tensor_##type *output; \
  tensor_##type *target; \
  tensor_##type *weight_in; /* weight link in */\
  tensor_##type *bias; /* bias */\
  tensor_##type *weight_out; /* weight link out */\
  tensor_##type *delta_out; /* delta */\
  struct neurons_##type *prev_layer;\
  struct neurons_##type *next_layer;\
  void (*TensorContraction)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread);/* nbthread is ignored if not required ! */\
  void (*TensorProduct)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread);/* nbthread is ignored if not required ! */\
  type (*dL)(type t, type o);\
  type (*L)(type t, type o);\
  type (*f_act)(type x);\
  type (*d_f_act)(type x);\
};\
typedef struct neurons_##type neurons_##type;\
\
struct func_act_##type {\
  type (*func_act)(type x); /* function activation */\
  type (*deriv_func_act)(type x); /* derivate func act */\
};\
\
/*void calc_net_neurons_##type(neurons_##type *nr);*/\
void calc_out_neurons_##type(neurons_##type *nr);\
void calc_delta_neurons_##type(neurons_##type *nr);\
void update_weight_neurons_##type(neurons_##type *nr);\
/*void setup_networks_##type(neurons_##type **base_nr, size_t **array_dim_in_layers, size_t *tab_sz_layers, size_t nb_layers);*/\
void init_copy_in_out_networks_from_tensors_##type(neurons_##type *nr, tensor_##type *input, tensor_##type *target);\
void init_in_out_networks_from_tensors_##type(neurons_##type *nr, tensor_##type *input, tensor_##type *target, neurons_##type *base);\
void init_in_out_all_networks_##type(neurons_##type *nr, tensor_##type *in, tensor_##type *out);\
void setup_networks_alloutputs_##type(neurons_##type **base_nr, size_t **array_dim_in_layers, size_t *sz_layers, size_t nb_layers);\
void setup_networks_alloutputs_config_##type(neurons_##type **base_nr, config_layers *lconf);\
void setup_networks_OneD_##type(neurons_##type **base_nr, size_t *array_dim_in_layers, size_t nb_layers);\
void init_in_out_all_networks_OneD_##type(neurons_##type *nr, type *in, size_t sz_in, type *out, size_t sz_out);\
void print_neurons_msg_##type(neurons_##type *nr, char * msg);\
\
void free_neurons_##type(neurons_##type *base);\
\
void setup_all_layers_functions_##type(neurons_##type *base, \
  void (*TensorContraction)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread),/* nbthread is ignored if not required ! */\
  void (*TensorProduct)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread),/* nbthread is ignored if not required ! */\
  type (*dL)(type t, type o),\
  type (*L)(type t, type o),\
  type (*f_act)(type x),\
  type (*d_f_act)(type x)\
);\
void setup_all_layers_params_##type(neurons_##type *base,\
  size_t nb_prod_thread,\
  size_t nb_calc_thread,\
  type learning_rate);\
type error_out_##type(neurons_##type *base);\
struct data_set_##type{\
  size_t size;\
  tensor_##type **input;\
  tensor_##type **target;\
};\
typedef struct data_set_##type data_set_##type;\
void free_data_set_##type(data_set_##type *ds);\
data_set_##type*  fill_data_set_from_file_##type(char * file_input, size_t pivotSplit);\
void print_data_set_msg_##type(data_set_##type *ds, char *msg);\
\
size_t learning_online_neurons_##type(neurons_##type *base, data_set_##type *dataset, bool (*condition)(type, size_t));\
\
struct set_cloneurons_##type{\
  size_t nb_clone;\
  config_layers *conf;\
  neurons_##type *base;\
  neurons_##type **cloneurons;\
};\
typedef struct set_cloneurons_##type set_cloneurons_##type;\
size_t learning_set_cloneurons_##type(set_cloneurons_##type *clon, data_set_##type *dataset, neurons_##type *base, bool (*condition)(type, size_t));\

GEN_NEURON_(TYPE_FLOAT)
GEN_NEURON_(TYPE_DOUBLE)


#endif /*__NEURON_T_C__H*/
