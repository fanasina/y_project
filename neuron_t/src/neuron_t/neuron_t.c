#include "neuron_t/neuron_t.h"


#define PR_LINE printf("===================================================== \n");


#define GEN_NEURONS_F_(type)\
  \
void calc_net_neurons_##type(neurons_##type *nr){\
  size_t contractNB= ((nr->input)->dim)->size - ((nr->net)->dim)->size ;\
  nr->TensorContraction_##type(&(nr->net), nr->weight_in,nr->input, contractNB, nr->nb_thread  );\
}\
\
void calc_out_neurons_##type(neurons_##type *nr, type (*f)(type x) ){\
  calc_net_neurons_##type(nr);\
  for(size_t i = 0; i<(nr->net)->dim->rank; ++i){\
    (nr->output)->x[i]=f((nr->net)->x[i]);\
  }\
}\
void calc_delta_neurons_##type(neurons_##type *nr, type (*df)(type x)){\
  if(nr->next_layer == NULL){\
    for(size_t i = 0; i<(nr->net)->dim->rank; ++i){\
      (nr->delta_out)->x[i]=df((nr->net)->x[i])*(nr->dL)((nr->target)->x[i],(nr->output)->x[i]);\
    }\
  }else{\
    tensor_##type *temp_w_d;\
    size_t cntrctnb=(((nr->next_layer)->weight_in)->dim)->size-(((nr->next_layer)->delta_out)->dim)->size ;\
    nr->TensorContraction_##type(&temp_w_d, ((nr->next_layer)->weight_in), (nr->next_layer)->delta_out,cntrctnb,nr->nb_thread);\
    \
    for(size_t i = 0; i<(nr->net)->dim->rank; ++i){\
      (nr->delta_out)->x[i]=df((nr->net)->x[i]) * temp_w_d->x[i] ;\
    }\
    free_tensor_##type(temp_w_d);\
  }\
}\
void update_weight_neurons_##type(neurons_##type *nr){\
  tensor_##type *tmp_e_w;\
  nr->TensorProduct_##type(&(tmp_e_w), nr->delta_out, nr->input, nr->nb_thread);\
  \
  for(size_t i = 0; i<(nr->weight_in)->dim->rank; ++i){\
    (nr->weight_in)->x[i]= (nr->weight_in)->x[i] - nr->learning_rate *tmp_e_w->x[i] ;\
  }\
  free_tensor_##type(tmp_e_w);\
}\
void init_in_out_all_networks_##type(neurons_##type *nr, tensor_##type *in, tensor_##type *out){\
  if(((nr->input)->dim)->rank == (in->dim)->rank)\
    for(size_t i=0; i<((in)->dim)->rank; ++i) {\
      (nr->input)->x[i] = in->x[i]; \
    }\
  neurons_##type *tmp=nr;\
  while(tmp->next_layer) tmp=tmp->next_layer;\
  if(((tmp->target)->dim)->rank == (out->dim)->rank)\
    for(size_t i=0; i<((out)->dim)->rank; ++i) {\
      (tmp->target)->x[i] = out->x[i]; \
    }\
  \
}\
void link_layers_##type(neurons_##type *nPrev, neurons_##type *nNext ){\
  nPrev->next_layer = nNext;\
  nNext->prev_layer = nPrev;\
  size_t pivot, partPiv;\
  if(endian){\
    pivot=0; partPiv = 1;\
    split_tensor_##type(nNext->input, &(nPrev->output), &(nNext->bias), pivot, partPiv);\
  }else{\
    pivot = ((nNext->input)->dim)->size - 1;\
    partPiv = ((nNext->input)->dim)->perm[pivot] - 1 ;\
    \
    split_tensor_##type(nNext->input, &(nNext->bias), &(nPrev->output), pivot, partPiv);\
  }\
  for(size_t i=0;i<((nNext->bias)->dim)->rank;++i) (nNext->bias)->x[i]=1;\
}\
\
void setup_networks_all_dim_inputs_##type(neurons_##type **base_nr, dimension **dim_in_layers,  size_t nb_layers){\
  neurons_##type *tmp_l, *ttmp_l=NULL;\
  for(size_t l=0; l<nb_layers; ++l){\
    if(l==0){\
      *base_nr=malloc(sizeof(neurons_##type)); \
      tmp_l = *base_nr;\
    }else{\
      ttmp_l->next_layer = malloc(sizeof(neurons_##type));\
      tmp_l = ttmp_l->next_layer;\
    }\
    /*dimension *dim=init_copy_dim(tab_in_layers[l],sz_layers[l]);\
    tensor_##type *input=CREATE_TENSOR_##type(dim);*/\
    tensor_##type *input=CREATE_TENSOR_##type(dim_in_layers[l]);\
    tmp_l->input = input;\
    \
    tmp_l->net = NULL; /* output tensor_prodContract */\
    tmp_l->output = NULL; \
    tmp_l->target = NULL; \
    tmp_l->weight_in = NULL; /* weight link in */\
    tmp_l->bias = NULL;  /* bias */\
    tmp_l->weight_out = NULL; /* weight link out */\
    tmp_l->prev_layer = ttmp_l;\
    tmp_l->next_layer = NULL;\
    \
    if(ttmp_l != NULL){\
      link_layers_##type(ttmp_l,tmp_l);\
      dimension *dim_out = (ttmp_l->output)->dim;\
      ttmp_l->net = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out);\
      if(l == nb_layers - 1) ttmp_l->target = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out);\
      ttmp_l->delta_out = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out); /* NULL; */ /* delta */\
      dimension *d_w_in;  \
      add_dimension(&d_w_in, (ttmp_l->input)->dim, ((ttmp_l->output)->dim)); \
      ttmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
      init_random_x_##type(ttmp_l->weight_in,0,1,5000);\
    }\
\
    ttmp_l = tmp_l;\
\
  }\
}\
\
\
void setup_networks_allinputs_##type(neurons_##type **base_nr, size_t **tab_in_layers, size_t *sz_layers, size_t nb_layers){\
  neurons_##type *tmp_l, *ttmp_l=NULL;\
  for(size_t l=0; l<nb_layers-1; ++l){\
    if(l==0){\
      *base_nr=malloc(sizeof(neurons_##type)); \
      tmp_l = *base_nr;\
    }else{\
      ttmp_l->next_layer = malloc(sizeof(neurons_##type));\
      tmp_l = ttmp_l->next_layer;\
    }\
    dimension *dim=init_copy_dim(tab_in_layers[l],sz_layers[l]);\
    tensor_##type *input=CREATE_TENSOR_##type(dim);\
    tmp_l->input = input;\
    \
    tmp_l->net = NULL; /* output tensor_prodContract */\
    tmp_l->output = NULL; \
    tmp_l->target = NULL; \
    tmp_l->weight_in = NULL; /* weight link in */\
    tmp_l->bias = NULL;  /* bias */\
    tmp_l->weight_out = NULL; /* weight link out */\
    tmp_l->prev_layer = ttmp_l;\
    tmp_l->next_layer = NULL;\
    \
    if(ttmp_l != NULL){\
      link_layers_##type(ttmp_l,tmp_l);\
      dimension *dim_out = (ttmp_l->output)->dim;\
      ttmp_l->net = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out);\
      ttmp_l->delta_out = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out); /* NULL; */ /* delta */\
      dimension *d_w_in;  \
      add_dimension(&d_w_in, (ttmp_l->input)->dim, ((ttmp_l->output)->dim)); \
      ttmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
      init_random_x_##type(ttmp_l->weight_in,0,1,5000);\
    }\
\
    ttmp_l = tmp_l;\
    \
    if(l == nb_layers - 2) {\
      dimension *dim=init_copy_dim(tab_in_layers[l+1],sz_layers[l+1]);\
      tensor_##type *input=CREATE_TENSOR_##type(dim);\
      tmp_l->output= CREATE_TENSOR_FROM_CPY_DIM_##type(dim);\
      tmp_l->net = CREATE_TENSOR_FROM_CPY_DIM_##type(dim);\
      tmp_l->target = CREATE_TENSOR_FROM_CPY_DIM_##type(dim);\
      dimension *d_w_in;  \
      add_dimension(&d_w_in, (tmp_l->input)->dim, ((tmp_l->output)->dim)); \
      tmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
      init_random_x_##type(tmp_l->weight_in,0,1,5000);\
    }\
 \
\
  }\
}\
\
void setup_networks_OneD_##type(neurons_##type **base_nr, size_t *tab_in_layers, size_t nb_layers){\
  size_t *sz_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) sz_layers[i]=1;\
  size_t **ttab_in_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) {\
    ttab_in_layers[i]=malloc(sizeof(size_t));\
    ttab_in_layers[i][0]=tab_in_layers[i];\
  }\
  setup_networks_allinputs_##type(base_nr, ttab_in_layers, sz_layers, nb_layers);\
  \
  for(size_t i=0; i<nb_layers;++i) {\
    free(ttab_in_layers[i]);\
  }\
  free(ttab_in_layers);\
  free(sz_layers);\
}\
void init_in_out_all_networks_OneD_##type(neurons_##type *nr, type *in, size_t sz_in, type *out, size_t sz_out){\
  if(((nr->input)->dim)->rank == sz_in){\
    for(size_t i=0;i<sz_in;++i) (nr->input)->x[i]=in[i];\
  }\
  neurons_##type *tmp=nr;\
  while(tmp->next_layer) tmp=tmp->next_layer;\
  \
  if(((tmp->target)->dim)->rank == sz_out){\
    for(size_t i=0; i< sz_out; ++i) {\
      (tmp->target)->x[i] = out[i]; \
    }\
  }\
}\
void print_neurons_msg_##type(neurons_##type *nr, char *msg){\
  size_t l=0;\
  while(nr){\
    printf("%s, layer %ld\n",msg,l++); \
    PR_LINE;\
    if(nr->input) print_tensor_msg_##type(nr->input," input "); else printf(" input NULL\n");\
    PR_LINE;\
    if(nr->output) print_tensor_msg_##type(nr->input," input "); else printf(" output NULL\n");\
    PR_LINE;\
    if(nr->net) print_tensor_msg_##type(nr->net," net "); else printf(" net NULL\n");\
    PR_LINE;\
    if(nr->weight_in) print_tensor_msg_##type(nr->weight_in," weight_in "); else printf(" weight_in NULL\n");\
    PR_LINE;\
    if(nr->weight_out) print_tensor_msg_##type(nr->weight_out," weight_out "); else printf(" weight_out NULL\n");\
    PR_LINE;\
    if(nr->delta_out) print_tensor_msg_##type(nr->delta_out," delta_out "); else printf(" delta_out NULL\n");\
    PR_LINE;\
    if(nr->target) print_tensor_msg_##type(nr->target," target "); else printf(" target NULL\n");\
    PR_LINE;\
\
    nr=nr->next_layer;\
  }\
}\

GEN_NEURONS_F_(TYPE_FLOAT)
GEN_NEURONS_F_(TYPE_DOUBLE)
