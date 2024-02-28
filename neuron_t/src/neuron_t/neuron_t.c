#include "neuron_t/neuron_t.h"


#define PR_LINE printf("===================================================== \n");


#define GEN_NEURONS_F_(type)\
  \
void calc_net_neurons_##type(neurons_##type *nr){\
  size_t contractNB= ((nr->weight_in)->dim)->size - ((nr->input)->dim)->size ;\
  /*print_tensor_msg_##type((nr->weight_in)," weight_in  calc");*/\
  /*print_tensor_msg_##type((nr->input)," input  calc");*/\
  nr->TensorContraction(&(nr->net), nr->input, nr->weight_in, contractNB, nr->nb_prod_thread  );\
  /*print_tensor_msg_##type((nr->net)," net  calc");*/\
}\
\
void calc_out_neurons_##type(neurons_##type *nr){\
  calc_net_neurons_##type(nr);\
  if(nr->nb_calc_thread <2){\
    for(size_t i = 0; i<(nr->net)->dim->rank; ++i)\
      (nr->output)->x[i]=(nr->f_act)((nr->net)->x[i]);\
  }else\
    update_2tensor_func_##type(nr->output,nr->net,nr->f_act,nr->nb_calc_thread);\
  /*print_tensor_msg_##type((nr->output)," output calc");\
  */\
}\
type funcalc_delta_target_##type (type net, type target, type output, type(*df1_df_act)(type), type (*df2_dL)(type,type)){\
  return df1_df_act(net)*df2_dL(target,output);\
}\
type funcalc_delta_hidden_out_##type (type net, type temp, type(*df_act)(type)){\
  return df_act(net)* temp;\
}\
void calc_delta_neurons_##type(neurons_##type *nr){\
  if(nr->next_layer == NULL){\
    if(nr->nb_calc_thread < 2){\
      for(size_t i = 0; i<(nr->net)->dim->rank; ++i)\
        (nr->delta_out)->x[i]=(nr->d_f_act)((nr->net)->x[i])*(nr->dL)((nr->target)->x[i],(nr->output)->x[i]);\
      /*print_tensor_msg_##type(nr->delta_out," nr delta_out calc 1 core target delta_out");\
      */\
    }else{\
      update_5tensor_func_##type(nr->delta_out, nr->net, nr->target, nr->output,\
        funcalc_delta_target_##type , \
        nr->d_f_act , \
        nr->dL, \
        nr->nb_calc_thread);\
      /*print_tensor_msg_##type(nr->delta_out," nr delta_out calc parallel target delta_out");\
      */\
    }\
    /*print_tensor_msg_##type(nr->delta_out," nr delta_out  calc delta_out last layer");*/\
  }else{\
    tensor_##type *temp_w_d=NULL;\
    size_t cntrctnb=(((nr->next_layer)->weight_in)->dim)->size-(((nr->next_layer)->delta_out)->dim)->size ;\
    /*print_tensor_msg_##type((nr->next_layer)->weight_in," nxt weight_in  calc delta_out");*/\
    /*print_tensor_msg_##type((nr->next_layer)->delta_out," nxt delta_out  calc delta_out");*/\
    nr->TensorContraction(&temp_w_d, ((nr->next_layer)->weight_in), (nr->next_layer)->delta_out,cntrctnb,nr->nb_prod_thread);\
    /*print_tensor_msg_##type(temp_w_d," nxt tmp  calc delta_out");*/\
    /*decrement_dim_var(temp_w_d->dim);*/\
    \
    if(nr->nb_calc_thread < 2){\
      for(size_t i = 0; i<(nr->net)->dim->rank; ++i)\
        (nr->delta_out)->x[i]=(nr->d_f_act)((nr->net)->x[i]) * temp_w_d->x[i] ;\
      /*print_tensor_msg_##type(nr->delta_out," nr delta_out calc 1 core hidden delta_out");\
     */\
    }else{\
      update_4tensor_func_##type(nr->delta_out, nr->net, temp_w_d,\
        funcalc_delta_hidden_out_##type , \
        nr->d_f_act , \
        nr->nb_calc_thread);\
      /*print_tensor_msg_##type(nr->delta_out," nr delta_out calc parallel hidden delta_out");\
    */\
    }\
    free_tensor_##type(temp_w_d);\
  }\
}\
void update_weight_neurons_##type(neurons_##type *nr){\
  tensor_##type *tmp_e_w=NULL;\
  nr->TensorProduct(&(tmp_e_w), nr->input, nr->delta_out, nr->nb_prod_thread);\
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
void setup_networks_alloutputs_##type(neurons_##type **base_nr, size_t **array_dim_in_layers, size_t *sz_layers, size_t nb_layers){\
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
      dimension *dim=init_copy_dim(array_dim_in_layers[l-1],sz_layers[l-1]);\
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
          for(size_t i=0;i<((ttmp_l->weight_in)->dim)->rank;++i) (ttmp_l->weight_in)->x[i]=0.01;\
          /*init_random_x_##type(ttmp_l->weight_in,0,1,5000);\
          */\
      }\
      if(l==nb_layers-1) {\
        dimension *dim_out=init_copy_dim(array_dim_in_layers[l],sz_layers[l]);\
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
        for(size_t i=0;i<((tmp_l->weight_in)->dim)->rank;++i) (tmp_l->weight_in)->x[i]=0.01;\
        /*init_random_x_##type(tmp_l->weight_in,0,1,5000);\
        */\
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
void setup_networks_alloutputs_config_##type(neurons_##type **base_nr, config_layers *lconf){\
  setup_networks_alloutputs_##type(base_nr, lconf->array_dim_in_layers, lconf->sz_layers, lconf->nb_layers);\
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
  size_t nb_prod_thread,\
  size_t nb_calc_thread,\
  type learning_rate){\
  \
   neurons_##type *temp = base;\
  while(temp){\
    temp->nb_prod_thread=nb_prod_thread;\
    temp->nb_calc_thread=nb_calc_thread;\
    temp->learning_rate=learning_rate;\
    temp=temp->next_layer;\
  }\
}\
\
\
void setup_networks_OneD_##type(neurons_##type **base_nr, size_t *array_dim_in_layers, size_t nb_layers){\
  size_t *sz_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) sz_layers[i]=1;\
  size_t **tarray_dim_in_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) {\
    tarray_dim_in_layers[i]=malloc(sizeof(size_t));\
    tarray_dim_in_layers[i][0]=array_dim_in_layers[i];\
  }\
  setup_networks_alloutputs_##type(base_nr, tarray_dim_in_layers, sz_layers, nb_layers);\
  \
  for(size_t i=0; i<nb_layers;++i) {\
    free(tarray_dim_in_layers[i]);\
  }\
  free(tarray_dim_in_layers);\
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
void init_copy_in_out_networks_from_tensors_##type(neurons_##type *nr, tensor_##type *input, tensor_##type *target){\
  if(((nr->output)->dim)->rank == (input->dim)->rank){\
    for(size_t i=0;i<(input->dim)->rank;++i) (nr->output)->x[i]=input->x[i];\
  }\
  neurons_##type *tmp=nr;\
  while(tmp->next_layer) tmp=tmp->next_layer;\
  \
  if(((tmp->target)->dim)->rank == (target->dim)->rank){\
    for(size_t i=0; i< (target->dim)->rank; ++i) {\
      (tmp->target)->x[i] = target->x[i]; \
    }\
  }\
}\
\
void init_in_out_networks_from_tensors_##type(neurons_##type *nr, tensor_##type *input, tensor_##type *target, neurons_##type *base){\
  if(is_equal_dim((base->output)->dim , input->dim)){\
    nr->output = input ;\
  }\
  neurons_##type *tmp=nr;\
  while(tmp->next_layer) tmp=tmp->next_layer;\
  \
  if(is_equal_dim((base->target)->dim, target->dim)){\
      tmp->target = target; \
  }\
}\
neurons_##type * clone_neurons_base_from_input_target_tensors_##type(neurons_##type *base_nr, tensor_##type *input, tensor_##type *target){\
  neurons_##type *nr = malloc(sizeof(neurons_##type));\
  neurons_##type *tmpnr = nr, *tmpbs=base_nr, *prevLayer = NULL;\
  while(tmpbs){\
    tmpnr->id_layer = tmpbs->id_layer;\
    tmpnr->nb_prod_thread = tmpbs->nb_prod_thread;\
    tmpnr->learning_rate = tmpbs->learning_rate;\
    tmpnr->input  = CLONE_TENSOR_##type(tmpbs->input); \
    tmpnr->net  = CLONE_TENSOR_##type(tmpbs->net); \
    tmpnr->weight_in  = CLONE_TENSOR_##type(tmpbs->weight_in); \
    tmpnr->bias  = CLONE_TENSOR_##type(tmpbs->bias); \
    tmpnr->weight_out  = CLONE_TENSOR_##type(tmpbs->weight_out); \
    tmpnr->delta_out  = CLONE_TENSOR_##type(tmpbs->delta_out); \
    tmpnr->prev_layer = prevLayer;\
    if(prevLayer)  {\
      prevLayer->next_layer = tmpnr;\
      tmpnr->output  = CLONE_TENSOR_##type(tmpbs->output); \
    }else{\
      tmpnr->output = NULL;\
    }\
    tmpnr->target  = NULL;\
    prevLayer = tmpnr;\
    tmpnr->TensorContraction = tmpbs->TensorContraction;\
    tmpnr->TensorProduct = tmpbs->TensorProduct;\
    tmpnr->dL = tmpbs->dL;\
    tmpnr->L = tmpbs->L;\
    tmpnr->f_act = tmpbs->f_act;\
    tmpnr->d_f_act = tmpbs->d_f_act;\
    if(tmpbs->next_layer) tmpnr->next_layer = malloc(sizeof(neurons_##type));\
    else tmpnr->next_layer =NULL;\
    tmpbs=tmpbs->next_layer;\
    tmpnr=tmpnr->next_layer;\
  }\
  return nr;\
}\
\
void print_neurons_msg_##type(neurons_##type *nr, char *msg){\
  char *val=NULL;\
  while(nr){\
    val=type##_TO_STR(nr->learning_rate);\
    printf("%s, layer %ld nb_prod_thread:%ld nb_calc_thread:%ld, learning_rate:%s\n",msg,nr->id_layer,nr->nb_prod_thread,nr->nb_calc_thread, val); \
    free(val); val=NULL;\
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
void free_data_set_##type(data_set_##type *ds){\
  if(ds){\
    for(size_t i=0;i<ds->size;++i){\
      free_tensor_##type(ds->input[i]);\
      free_tensor_##type(ds->target[i]);\
    }\
    free(ds->input);\
    free(ds->target);\
    free(ds);\
  }\
  \
}\
data_set_##type * fill_data_set_from_file_##type(char * file_input, size_t pivotSplit){\
  data_set_##type * ds=malloc(sizeof(data_set_##type));\
  tensor_##type *input, *target;\
  parse_file_InputOutput_withDim_to_tensors_##type(&input,&target,file_input,pivotSplit);\
  ds->size=(input->dim)->perm[0];\
  ds->input=fromInput_to_array_tensor_##type(input);\
  ds->target=fromInput_to_array_tensor_##type(target);\
  free_tensor_##type(input);\
  free_tensor_##type(target);\
  return ds;\
}\
void print_data_set_msg_##type(data_set_##type *ds, char *msg){\
  printf("data_set : %s\n",msg);\
  char mmsg[256];\
  for(size_t i=0; i<ds->size; ++i){\
    sprintf(mmsg," (%s) - >input[%ld] ",msg,i);\
    print_tensor_msg_##type(ds->input[i],mmsg);\
  }\
  for(size_t i=0; i<ds->size; ++i){\
    sprintf(mmsg," (%s) - >target[%ld] ",msg,i);\
    print_tensor_msg_##type(ds->target[i],mmsg);\
  }\
}\
size_t learning_online_neurons_##type(neurons_##type *base, data_set_##type *dataset, bool (*condition)(type,size_t)){\
  neurons_##type *tmp=NULL, *ttmp;\
  size_t nbreps=0;\
  do{\
    for(size_t i=0; i<dataset->size; ++i){\
      init_copy_in_out_networks_from_tensors_##type(base, dataset->input[i],dataset->target[i]);\
      tmp=base->next_layer;\
      while(tmp){\
        calc_out_neurons_##type(tmp);\
        ttmp = tmp;\
        tmp = tmp->next_layer;\
      }\
      while(ttmp != base){\
        calc_delta_neurons_##type(ttmp);\
        update_weight_neurons_##type(ttmp);\
        ttmp = ttmp->prev_layer;\
      }\
    }\
\
  }while(!condition(error_out_##type(base), nbreps++));\
    \
  \
  printf(" ### reps : %ld \n",nbreps);\
  return nbreps;\
}\
size_t learning_set_cloneurons_##type(set_cloneurons_##type *clon, data_set_##type *dataset, neurons_##type *base, bool (*condition)(type, size_t)){\
  size_t nbreps=0;\
  type err=0;\
  do{\
    \
  }while(!condition(err,nbreps++));\
  return nbreps;\
}\
  
  
  
GEN_NEURONS_F_(TYPE_FLOAT)
GEN_NEURONS_F_(TYPE_DOUBLE)
