#include "neuron_t/neuron_t.h"


#define PR_LINE printf("===================================================== \n");


#define GEN_NEURONS_F_(type)\
  \
void calc_net_neurons_##type(neurons_##type *nr){\
  size_t contractNB= ((nr->weight_in)->dim)->size - ((nr->input)->dim)->size ;\
  /*print_tensor_msg_##type((nr->weight_in)," weight_in  calc");*/\
  /*print_tensor_msg_##type((nr->input)," input  calc");*/\
  nr->TensorContraction(&(nr->net), nr->input, nr->weight_in, contractNB, nr->nb_thread  );\
  /*print_tensor_msg_##type((nr->net)," net  calc");*/\
}\
\
void calc_out_neurons_##type(neurons_##type *nr){\
  calc_net_neurons_##type(nr);\
  for(size_t i = 0; i<(nr->net)->dim->rank; ++i){\
    (nr->output)->x[i]=(nr->f_act)((nr->net)->x[i]);\
  }\
}\
void calc_delta_neurons_##type(neurons_##type *nr){\
  if(nr->next_layer == NULL){\
    for(size_t i = 0; i<(nr->net)->dim->rank; ++i){\
      (nr->delta_out)->x[i]=(nr->d_f_act)((nr->net)->x[i])*(nr->dL)((nr->target)->x[i],(nr->output)->x[i]);\
    }\
    /*print_tensor_msg_##type(nr->delta_out," nr delta_out  calc delta_out last layer");*/\
  }else{\
    tensor_##type *temp_w_d;\
    size_t cntrctnb=(((nr->next_layer)->weight_in)->dim)->size-(((nr->next_layer)->delta_out)->dim)->size ;\
    /*print_tensor_msg_##type((nr->next_layer)->weight_in," nxt weight_in  calc delta_out");*/\
    /*print_tensor_msg_##type((nr->next_layer)->delta_out," nxt delta_out  calc delta_out");*/\
    nr->TensorContraction(&temp_w_d, ((nr->next_layer)->weight_in), (nr->next_layer)->delta_out,cntrctnb,nr->nb_thread);\
    /*print_tensor_msg_##type(temp_w_d," nxt tmp  calc delta_out");*/\
    \
    for(size_t i = 0; i<(nr->net)->dim->rank; ++i){\
      (nr->delta_out)->x[i]=(nr->d_f_act)((nr->net)->x[i]) * temp_w_d->x[i] ;\
    }\
    /*print_tensor_msg_##type(nr->delta_out," nr delta_out  calc delta_out");*/\
    free_tensor_##type(temp_w_d);\
  }\
}\
void update_weight_neurons_##type(neurons_##type *nr){\
  tensor_##type *tmp_e_w;\
  nr->TensorProduct(&(tmp_e_w), nr->input, nr->delta_out, nr->nb_thread);\
  /*print_tensor_msg_##type(nr->input," nr input  update wei");*/\
  /*print_tensor_msg_##type(nr->delta_out," nr delta_out  update wei");*/\
  /*print_tensor_msg_##type(tmp_e_w," tmp_e_w  update wei");*/\
  \
  for(size_t i = 0; i<(nr->weight_in)->dim->rank; ++i){\
    (nr->weight_in)->x[i]= (nr->weight_in)->x[i] - nr->learning_rate *tmp_e_w->x[i] ;\
  }\
  /*print_tensor_msg_##type(nr->weight_in," weight_in  updated ");*/\
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
\
\
void setup_networks_alloutputs_##type(neurons_##type **base_nr, size_t **tab_in_layers, size_t *sz_layers, size_t nb_layers){\
  neurons_##type *tmp_l=NULL, *ttmp_l=NULL;\
  for(size_t l=0; l<nb_layers; ++l){\
    tmp_l = malloc(sizeof(neurons_##type)); \
    if(l==0){\
      *base_nr = tmp_l ;\
    }else{\
      ttmp_l->next_layer = tmp_l ;\
    }\
    tmp_l->id_layer= l;\
    tmp_l->input = NULL; \
    tmp_l->net = NULL; \
    tmp_l->output = NULL; \
    tmp_l->target = NULL; \
    tmp_l->weight_in = NULL; \
    tmp_l->weight_out = NULL; \
    tmp_l->delta_out = NULL; \
    tmp_l->bias = NULL;  \
    tmp_l->prev_layer = ttmp_l;\
    tmp_l->next_layer = NULL;\
    \
    if(ttmp_l != NULL){\
      dimension *dim=init_copy_dim(tab_in_layers[l-1],sz_layers[l-1]);\
      increment_dim_var(dim);\
      tmp_l->input = CREATE_TENSOR_##type(dim);\
      for(size_t i=0;i<((tmp_l->input)->dim)->rank;++i) (tmp_l->input)->x[i]=(type)l;\
      \
      link_layers_##type(ttmp_l,tmp_l);\
      if(l>1 ){\
          dimension *dim_out = (ttmp_l->output)->dim;\
          for(size_t i=0;i<dim_out->rank; ++i) (ttmp_l->output)->x[i]=(type)(l-1);\
          ttmp_l->net = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out);\
          for(size_t i=0;i<dim_out->rank; ++i) (ttmp_l->net)->x[i]=(type)(l-1);\
          ttmp_l->delta_out = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out); \
          for(size_t i=0;i< dim_out->rank; ++i) (ttmp_l->delta_out)->x[i]=(type)(l-1);\
          dimension *d_w_in;  \
          add_dimension(&d_w_in, (ttmp_l->input)->dim, ((ttmp_l->output)->dim)); \
          ttmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
          init_random_x_##type(ttmp_l->weight_in,0,1,5000);\
      }\
      if(l==nb_layers-1) {\
        dimension *dim_out=init_copy_dim(tab_in_layers[l],sz_layers[l]);\
        tmp_l->output = CREATE_TENSOR_##type(dim_out);\
        for(size_t i=0;i<((tmp_l->output)->dim)->rank;++i) (tmp_l->output)->x[i]=(type)l;\
        tmp_l->target = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out);\
        for(size_t i=0;i<((tmp_l->target)->dim)->rank;++i) (tmp_l->target)->x[i]=(type)(l);\
        tmp_l->net = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out);\
        for(size_t i=0;i<((tmp_l->net)->dim)->rank;++i) (tmp_l->net)->x[i]=(type)(l);\
        tmp_l->delta_out = CREATE_TENSOR_FROM_CPY_DIM_##type(dim_out); \
        for(size_t i=0;i<((tmp_l->delta_out)->dim)->rank;++i) (tmp_l->delta_out)->x[i]=(type)(l);\
        dimension *d_w_in;  \
        add_dimension(&d_w_in, (tmp_l->input)->dim, ((tmp_l->output)->dim)); \
        tmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
        init_random_x_##type(tmp_l->weight_in,0,1,5000);\
        \
      }\
     \
    }\
\
    ttmp_l = tmp_l;\
    \
 \
\
  }\
}\
\
void setup_all_layers_functions_##type(neurons_##type *base, \
  void (*TensorContraction)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t contractionNumber, size_t nbthread),/* nbthread is ignored if not required ! */\
  void (*TensorProduct)(tensor_##type **MM, tensor_##type *M0, tensor_##type *M1, size_t nbthread),/* nbthread is ignored if not required ! */\
  type (*dL)(type t, type o),\
  type (*L)(type t, type o),\
  type (*f_act)(type x),\
  type (*d_f_act)(type x)\
){\
  neurons_##type *temp = base;\
  while(temp){\
    temp->TensorContraction = TensorContraction;\
    temp->TensorProduct= TensorProduct;\
    temp->L=L;\
    temp->dL=dL;\
    temp->f_act=f_act;\
    temp->d_f_act=d_f_act;\
    temp=temp->next_layer;\
  }\
}\
  \
void setup_all_layers_params_##type(neurons_##type *base,\
  size_t nb_thread,\
  type learning_rate){\
  \
   neurons_##type *temp = base;\
  while(temp){\
    temp->nb_thread=nb_thread;\
    temp->learning_rate=learning_rate;\
    temp=temp->next_layer;\
  }\
}\
\
\
void setup_networks_OneD_##type(neurons_##type **base_nr, size_t *tab_in_layers, size_t nb_layers){\
  size_t *sz_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) sz_layers[i]=1;\
  size_t **ttab_in_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) {\
    ttab_in_layers[i]=malloc(sizeof(size_t));\
    ttab_in_layers[i][0]=tab_in_layers[i];\
  }\
  setup_networks_alloutputs_##type(base_nr, ttab_in_layers, sz_layers, nb_layers);\
  \
  for(size_t i=0; i<nb_layers;++i) {\
    free(ttab_in_layers[i]);\
  }\
  free(ttab_in_layers);\
  free(sz_layers);\
}\
void init_in_out_all_networks_OneD_##type(neurons_##type *nr, type *in, size_t sz_in, type *out, size_t sz_out){\
  if(((nr->output)->dim)->rank == sz_in){\
    for(size_t i=0;i<sz_in;++i) (nr->output)->x[i]=in[i];\
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
  while(nr){\
    printf("%s, layer %ld\n",msg,nr->id_layer); \
    PR_LINE;\
    if(nr->input) print_tensor_msg_##type(nr->input," input "); else printf(" input NULL\n");\
    PR_LINE;\
    if(nr->bias) print_tensor_msg_##type(nr->bias," bias "); else printf(" bias NULL\n");\
    PR_LINE;\
    if(nr->output) print_tensor_msg_##type(nr->output," output "); else printf(" output NULL\n");\
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
\
void free_neurons_##type(neurons_##type *base){\
  neurons_##type *temp = base, *ttemp;\
  while(temp){\
    if(temp->input) free_tensor_##type(temp->input);\
    if(temp->output) {\
      if(temp->next_layer == NULL) free((temp->output)->x);\
      free_dimension((temp->output)->dim);free(temp->output);\
    }\
    if(temp->bias) {free_dimension((temp->bias)->dim);free(temp->bias);}\
    if(temp->net) free_tensor_##type(temp->net);\
    if(temp->weight_in) free_tensor_##type(temp->weight_in);\
    if(temp->weight_out) free_tensor_##type(temp->weight_out);\
    if(temp->delta_out) free_tensor_##type(temp->delta_out);\
    if(temp->target) free_tensor_##type(temp->target);\
    ttemp = temp;\
    temp = ttemp->next_layer;\
    free(ttemp);\
  }\
}\
type error_out_##type(neurons_##type *base){\
  while(base->next_layer) base=base->next_layer;\
  type sum=0;\
  for(size_t i=0; i< ((base->target)->dim)->rank; ++i) sum += base->L((base->target)->x[i], (base->output)->x[i]);\
  return sum / (((base->target)->dim)->rank);\
}\


GEN_NEURONS_F_(TYPE_FLOAT)
GEN_NEURONS_F_(TYPE_DOUBLE)
