#ifndef __NEURON_T_C__H
#define __NEURON_T_C__H

#include <stdlib.h>

//#include "tools_t/tools_t.h"
#include "tensor_t/tensor_t.h"

#define GEN_NEURON_(type)\
\
struct neurons_##type {/* layer */\
  size_t id_layer;\
  size_t nb_thread;\
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
  void (*TensorContraction_##type)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread);/* nbthread is ignored if not required ! */\
  void (*TensorProduct_##type)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread);/* nbthread is ignored if not required ! */\
  type (*dL)(type t, type o);\
};\
typedef struct neurons_##type neurons_##type;\
\
struct func_act_##type {\
  type (*func_act)(type x); /* function activation */\
  type (*deriv_func_act)(type x); /* derivate func act */\
};\
/*void calc_net_neurons_##type(neurons_##type *nr);*/\
void calc_out_neurons_##type(neurons_##type *nr, type (*f)(type x) );\
void calc_delta_neurons_##type(neurons_##type *nr, type (*df)(type x));\
void update_weight_neurons_##type(neurons_##type *nr);\
void setup_networks_##type(neurons_##type **base_nr, size_t **tab_in_layers, size_t *tab_sz_layers, size_t nb_layers);\
void init_in_out_all_networks_##type(neurons_##type *nr, tensor_##type *in, tensor_##type *out);\
\
void setup_networks_OneD_##type(neurons_##type **base_nr, size_t *tab_in_layers, size_t nb_layers);\
void init_in_out_all_networks_OneD_##type(neurons_##type *nr, type *in, size_t sz_in, type *out, size_t sz_out);\
void print_neurons_msg_##type(neurons_##type *nr, char * msg);\

GEN_NEURON_(TYPE_FLOAT)
GEN_NEURON_(TYPE_DOUBLE)


#endif /*__NEURON_T_C__H*/
