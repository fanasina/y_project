#include "neuron_t/neuron_t.h"

//#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

#define ABSMAX(X, Y) ((((X) > (Y)) || ((-X) > (Y))  ) ? (X) : (Y))

#define PR_LINE printf("===================================================== \n");

config_layers *create_config_layers(size_t nb_layers, size_t *sz_layers, size_t **array_dim_in_layers){
  config_layers *pconf=malloc(sizeof(config_layers));
   pconf->nb_layers=nb_layers;
   pconf->sz_layers=malloc(nb_layers * sizeof(size_t));
   pconf->array_dim_in_layers=malloc(nb_layers*sizeof(size_t*));
   for(size_t i=0; i<nb_layers; ++i){
    pconf->sz_layers[i]=sz_layers[i];
    pconf->array_dim_in_layers[i]=malloc(sz_layers[i]*sizeof(size_t));
    for(size_t j=0; j<sz_layers[i];++j)
      pconf->array_dim_in_layers[i][j]=array_dim_in_layers[i][j];
   }
   return pconf;
}
config_layers *create_config_layers_from_OneD(size_t nb_layers, size_t *array_dim_in_layers){
   config_layers *pconf=malloc(sizeof(config_layers));
   pconf->nb_layers=nb_layers;
   pconf->sz_layers=malloc(nb_layers * sizeof(size_t));
   pconf->array_dim_in_layers=malloc(nb_layers*sizeof(size_t*));
   for(size_t i=0; i<nb_layers; ++i){
    pconf->sz_layers[i]=1;
    pconf->array_dim_in_layers[i]=malloc(sizeof(size_t));
    pconf->array_dim_in_layers[i][0]=array_dim_in_layers[i];
   }
   return pconf;
}

void free_config_layers(config_layers *pconf){
  for(size_t i=0; i<pconf->nb_layers;++i) free(pconf->array_dim_in_layers[i]);
  free(pconf->array_dim_in_layers);
  free(pconf->sz_layers);
  free(pconf);
} 

bool randomizeInitWeight=true;

#define GEN_NEURONS_F_(type)\
  \
void do_not_update_learnig_rate_##type(neurons_##type *N){}\
\
void time_based_update_learning_rate_##type(neurons_##type *nr){\
  nr->learning_rate=(nr->learning_rate)/(1+(nr->decay_rate)*(nr->iteration_step));\
}\
\
type power_##type(type b, size_t p){\
  type ret_pow=1;\
  for(size_t i=0;i<p;++i) ret_pow *=b;\
  return ret_pow;\
}\
void step_based_update_learning_rate_##type(neurons_##type *nr){\
  nr->learning_rate=(nr->initial_learning_rate)*power_##type((nr->decay_rate),(1+(nr->iteration_step))/(nr->drop_rate));\
}\
\
void setup_learning_rate_params_neurons_##type(neurons_##type *base,type initial_learning_rate, type decay_rate, size_t drop_rate, void (*update_learning_rate)(neurons_##type *)){\
  while(base){\
    base->initial_learning_rate = initial_learning_rate;\
    base->learning_rate = initial_learning_rate;\
    base->decay_rate = decay_rate;\
    base->drop_rate = drop_rate;\
    base->update_learning_rate = update_learning_rate;\
    base = base->next_layer;\
  }\
}\
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
  (nr->update_learning_rate)(nr);\
  /*printf("leraning rt :%f , step : %ld\n",nr->learning_rate,nr->iteration_step);\
  */++(nr->iteration_step);\
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
\
type  func_only_weight_in_##type(type w0, type w1, type scalar){\
  return w0 - scalar * w1;\
}\
void only_update_weight_neurons_##type(neurons_##type *nr){\
  if(nr->nb_calc_thread < 2){\
    for(size_t i = 0; i<(nr->weight_in)->dim->rank; ++i){\
    /*(nr->weight_in)->x[i]= (nr->weight_in)->x[i] - nr->learning_rate *tmp_e_w->x[i] ;\
    */(nr->weight_in)->x[i]= (nr->weight_in)->x[i] - nr->learning_rate * (nr->weight_out)->x[i] ;\
    }\
  }else{\
    update_6tensor_func_##type(nr->weight_in, nr->weight_out, \
    func_only_weight_in_##type,\
    nr->learning_rate,\
    nr->nb_calc_thread);\
  }\
}\
\
void update_weight_neurons_##type(neurons_##type *nr){\
  nr->TensorProduct(&(nr->weight_out), nr->input, nr->delta_out, nr->nb_prod_thread);\
  /*tensor_##type *tmp_e_w=NULL;\
  nr->TensorProduct(&(tmp_e_w), nr->input, nr->delta_out, nr->nb_prod_thread);\
  *//*print_tensor_msg_##type(nr->input," nr input  update wei");*/\
  /*print_tensor_msg_##type(nr->delta_out," nr delta_out  update wei");*/\
  /*print_tensor_msg_##type(tmp_e_w," tmp_e_w  update wei");*/\
  \
  only_update_weight_neurons_##type(nr);\
  /*for(size_t i = 0; i<(nr->weight_in)->dim->rank; ++i){\
    *//*(nr->weight_in)->x[i]= (nr->weight_in)->x[i] - nr->learning_rate *tmp_e_w->x[i] ;\
    */\
    /*(nr->weight_in)->x[i]= (nr->weight_in)->x[i] - nr->learning_rate * (nr->weight_out)->x[i] ;\
  }\
  *//*print_tensor_msg_##type(nr->weight_in," weight_in  updated ");*/\
  /*free_tensor_##type(tmp_e_w);\
  */\
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
void setup_networks_alloutputs_##type(neurons_##type **base_nr, size_t **array_dim_in_layers, size_t *sz_layers, size_t nb_layers, bool randomize, type minR, type maxR, int randomRange){\
  neurons_##type *tmp_l=NULL, *ttmp_l=NULL;\
  for(size_t l=0; l<nb_layers; ++l){\
    tmp_l = malloc(sizeof(neurons_##type)); \
    if(l==0){\
      *base_nr = tmp_l ;\
    }else{\
      ttmp_l->next_layer = tmp_l ;\
    }\
    tmp_l->id_layer= l;\
    tmp_l->iteration_step= 0;\
    tmp_l->input = NULL; \
    tmp_l->net = NULL; \
    tmp_l->output = NULL; \
    tmp_l->target = NULL; \
    tmp_l->weight_in = NULL; \
    tmp_l->weight_out = NULL; \
    tmp_l->delta_out = NULL; \
    tmp_l->bias = NULL;  \
    tmp_l->update_learning_rate = do_not_update_learnig_rate_##type;  \
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
          if(randomize) init_random_x_##type(ttmp_l->weight_in,minR,maxR,randomRange);\
          else\
          for(size_t i=0;i<((ttmp_l->weight_in)->dim)->rank;++i) (ttmp_l->weight_in)->x[i]=(minR+maxR)/2;\
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
        if(randomize) init_random_x_##type(tmp_l->weight_in,minR,maxR,randomRange);\
        else\
        for(size_t i=0;i<((tmp_l->weight_in)->dim)->rank;++i) (tmp_l->weight_in)->x[i]=(minR+maxR)/2;\
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
\
void setup_networks_alloutputs_GLOBAL_rdm01_##type(neurons_##type **base_nr, size_t **array_dim_in_layers, size_t *sz_layers, size_t nb_layers){\
  neurons_##type *tmp_l=NULL, *ttmp_l=NULL;\
  for(size_t l=0; l<nb_layers; ++l){\
    tmp_l = malloc(sizeof(neurons_##type)); \
    if(l==0){\
      *base_nr = tmp_l ;\
    }else{\
      ttmp_l->next_layer = tmp_l ;\
    }\
    tmp_l->id_layer= l;\
    tmp_l->iteration_step= 0;\
    tmp_l->input = NULL; \
    tmp_l->net = NULL; \
    tmp_l->output = NULL; \
    tmp_l->target = NULL; \
    tmp_l->weight_in = NULL; \
    tmp_l->weight_out = NULL; \
    tmp_l->delta_out = NULL; \
    tmp_l->bias = NULL;  \
    tmp_l->update_learning_rate = do_not_update_learnig_rate_##type;  \
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
          if(randomizeInitWeight) init_random_x_##type(ttmp_l->weight_in,0,1,5000);\
          else\
          for(size_t i=0;i<((ttmp_l->weight_in)->dim)->rank;++i) (ttmp_l->weight_in)->x[i]=0.5;\
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
        if(randomizeInitWeight) init_random_x_##type(tmp_l->weight_in,0,1,5000);\
        else\
        for(size_t i=0;i<((tmp_l->weight_in)->dim)->rank;++i) (tmp_l->weight_in)->x[i]=0.5;\
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
\
void setup_networks_layers_without_weights_##type(neurons_##type **base_nr, size_t **array_dim_in_layers, size_t *sz_layers, size_t nb_layers){\
  neurons_##type *tmp_l=NULL, *ttmp_l=NULL;\
  for(size_t l=0; l<nb_layers; ++l){\
    tmp_l = malloc(sizeof(neurons_##type)); \
    if(l==0){\
      *base_nr = tmp_l ;\
    }else{\
      ttmp_l->next_layer = tmp_l ;\
    }\
    tmp_l->id_layer= l;\
    tmp_l->iteration_step= 0;\
    tmp_l->input = NULL; \
    tmp_l->net = NULL; \
    tmp_l->output = NULL; \
    tmp_l->target = NULL; \
    tmp_l->weight_in = NULL; \
    tmp_l->weight_out = NULL; \
    tmp_l->delta_out = NULL; \
    tmp_l->bias = NULL;  \
    tmp_l->update_learning_rate = do_not_update_learnig_rate_##type;  \
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
          /*dimension *d_w_in;  \
          add_dimension(&d_w_in, (ttmp_l->input)->dim, ((ttmp_l->output)->dim)); \
          ttmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
          for(size_t i=0;i<((ttmp_l->weight_in)->dim)->rank;++i) (ttmp_l->weight_in)->x[i]=0.01;\
          *//*init_random_x_##type(ttmp_l->weight_in,0,1,5000);\
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
        /*dimension *d_w_in;  \
        add_dimension(&d_w_in, (tmp_l->input)->dim, ((tmp_l->output)->dim)); \
        tmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
        for(size_t i=0;i<((tmp_l->weight_in)->dim)->rank;++i) (tmp_l->weight_in)->x[i]=0.01;\
        *//*init_random_x_##type(tmp_l->weight_in,0,1,5000);\
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
\
void setup_weights_neurons_##type(neurons_##type *base, bool randomize, type minR, type maxR,  int randomRange){\
  neurons_##type *tmp_l=base->next_layer;\
  while(tmp_l){\
    dimension *d_w_in;  \
    add_dimension(&d_w_in, (tmp_l->input)->dim, ((tmp_l->output)->dim)); \
    tmp_l->weight_in = CREATE_TENSOR_##type(d_w_in);\
    if(randomize){\
        init_random_x_##type(tmp_l->weight_in,minR, maxR, randomRange);\
    }else{\
        for(size_t i=0;i<((tmp_l->weight_in)->dim)->rank;++i) (tmp_l->weight_in)->x[i]=maxR;\
    }\
    tmp_l = tmp_l->next_layer;\
  }\
  \
}\
\
void setup_networks_alloutputs_config_##type(neurons_##type **base_nr, config_layers *lconf, bool randomize, type minR, type maxR,  int randomRange){\
  setup_networks_alloutputs_##type(base_nr, lconf->array_dim_in_layers, lconf->sz_layers, lconf->nb_layers, randomize, minR, maxR, randomRange);\
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
    temp->initial_learning_rate=learning_rate;\
    temp->learning_rate=learning_rate;\
    temp=temp->next_layer;\
  }\
}\
\
\
void setup_networks_OneD_##type(neurons_##type **base_nr, size_t *array_dim_in_layers, size_t nb_layers, bool randomize, type minR, type maxR,  int randomRange){\
  size_t *sz_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) sz_layers[i]=1;\
  size_t **tarray_dim_in_layers=malloc(nb_layers*sizeof(size_t));\
  for(size_t i=0; i<nb_layers;++i) {\
    tarray_dim_in_layers[i]=malloc(sizeof(size_t));\
    tarray_dim_in_layers[i][0]=array_dim_in_layers[i];\
  }\
  setup_networks_alloutputs_##type(base_nr, tarray_dim_in_layers, sz_layers, nb_layers, randomize, minR, maxR, randomRange);\
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
    for(size_t i=0;i<(input->dim)->rank;++i) (nr->output)->x[i]=input->x[i];\
    /*nr->output = input ;*/\
  }\
  neurons_##type *tmp=nr;\
  while(tmp->next_layer) tmp=tmp->next_layer;\
  \
  if(is_equal_dim((tmp->target)->dim, target->dim)){\
    for(size_t i=0; i< (target->dim)->rank; ++i) {\
      (tmp->target)->x[i] = target->x[i]; \
      /*tmp->target = target;*/ \
    }\
  }\
}\
void setup_networks_layers_without_weights_from_config_##type(neurons_##type **base, config_layers *pconf){\
  setup_networks_layers_without_weights_##type(base, pconf->array_dim_in_layers, pconf->sz_layers, pconf->nb_layers);\
}\
void unlink_all_weigth_in_neurons_##type(neurons_##type *nr){\
  while(nr){\
    nr->weight_in=NULL;\
    nr=nr->next_layer;\
  }\
}\
void free_cloneuronset_##type(cloneuronset_##type *clnrnst){\
  for(size_t i=0; i < clnrnst->nb_clone; ++i) {\
    unlink_all_weigth_in_neurons_##type(clnrnst->cloneurons[i]);\
    free_neurons_##type(clnrnst->cloneurons[i]);\
  }\
  free(clnrnst->cloneurons);\
  free_config_layers(clnrnst->conf);\
  free(clnrnst);\
}\
void link_cloneuronset_weight_in_funcs_params_from_base_##type(cloneuronset_##type *clnrnst){\
  neurons_##type **tmp_c=malloc(clnrnst->nb_clone * sizeof(neurons_##type *));\
  for(size_t c=0; c<clnrnst->nb_clone; ++c){\
    tmp_c[c]=clnrnst->cloneurons[c];\
  }\
  neurons_##type *tmp_b=clnrnst->base;\
  while(tmp_b){\
    for(size_t c=0; c<clnrnst->nb_clone; ++c){\
      tmp_c[c]->weight_in = tmp_b->weight_in;\
      tmp_c[c]->L = tmp_b->L;\
      tmp_c[c]->dL = tmp_b->dL;\
      tmp_c[c]->f_act = tmp_b->f_act;\
      tmp_c[c]->d_f_act = tmp_b->d_f_act;\
      tmp_c[c]->TensorContraction = tmp_b->TensorContraction;\
      tmp_c[c]->TensorProduct = tmp_b->TensorProduct;\
      tmp_c[c]->initial_learning_rate = tmp_b->initial_learning_rate;\
      tmp_c[c]->learning_rate = tmp_b->learning_rate;\
      tmp_c[c]->decay_rate= tmp_b->decay_rate;\
      tmp_c[c]->drop_rate= tmp_b->drop_rate;\
      tmp_c[c]->update_learning_rate = tmp_b->update_learning_rate ;\
      tmp_c[c]->nb_prod_thread = tmp_b->nb_prod_thread;\
      tmp_c[c]->nb_calc_thread = tmp_b->nb_calc_thread;\
      tmp_c[c]->id_layer = tmp_b->id_layer;\
    }\
    for(size_t c=0; c<clnrnst->nb_clone; ++c){\
      tmp_c[c]=tmp_c[c]->next_layer;\
    }\
    tmp_b=tmp_b->next_layer;\
    \
  }\
  free(tmp_c);\
}\
cloneuronset_##type * create_cloneuronset_from_base_conf_##type(neurons_##type *base, config_layers *conf, size_t nb_clone){\
  cloneuronset_##type *clnrnst = malloc(sizeof(cloneuronset_##type));\
  clnrnst->nb_clone = nb_clone;\
  clnrnst->conf=conf;\
  clnrnst->base=base;\
  clnrnst->cloneurons = malloc(nb_clone*sizeof(neurons_##type*));\
  for(size_t c=0; c<nb_clone; ++c){\
    setup_networks_layers_without_weights_from_config_##type(&(clnrnst->cloneurons[c]), conf);\
  }\
  link_cloneuronset_weight_in_funcs_params_from_base_##type(clnrnst);\
  return clnrnst;\
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
    if(nr->next_layer == NULL) printf("next layer of %s = NULL\n",msg);\
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
    nbreps += (dataset->size);\
  }while(!condition(error_out_##type(base), nbreps));\
    \
  \
  printf(" ### reps : %ld \n",nbreps);\
  return nbreps;\
}\
size_t learning_online2_neurons_##type(neurons_##type *base, data_set_##type *dataset, bool (*condition)(type,size_t)){\
  neurons_##type *tmp=NULL, *ttmp;\
  size_t nbreps=0;\
  type err=0;\
  bool ending=false;\
  do{\
    for(size_t i=0; i<dataset->size && !ending; ++i){\
      init_copy_in_out_networks_from_tensors_##type(base, dataset->input[i],dataset->target[i]);\
      tmp=base->next_layer;\
      while(tmp){\
        calc_out_neurons_##type(tmp);\
        ttmp = tmp;\
        tmp = tmp->next_layer;\
      }\
      while(ttmp != base){\
        calc_delta_neurons_##type(ttmp);\
        /*update_weight_neurons_##type(ttmp);\
        */ttmp = ttmp->prev_layer;\
      }\
        tmp = ttmp->next_layer;\
      while(tmp){\
        update_weight_neurons_##type(tmp);\
        tmp = tmp->next_layer;\
      }\
      err = ABSMAX(err,error_out_##type(base));\
      ending = condition(err, ++nbreps);\
    }\
\
  }while(!ending);\
    \
  \
  printf(" ### reps : %ld, err:%f \n",nbreps,err);\
  return nbreps;\
}\
\
void calculate_output_by_network_neurons_##type(neurons_##type *base, tensor_##type *input, tensor_##type **output_link){\
  for(size_t i=0; i<(input->dim)->rank; ++i) (base->output)->x[i]=input->x[i];\
  neurons_##type * tmp=base->next_layer;\
  while(tmp){\
    calc_out_neurons_##type(tmp);\
    if(tmp->next_layer==NULL){\
      /*print_tensor_msg_##type(tmp->output,"retult");*/\
      *output_link = tmp->output;\
    }\
    tmp = tmp->next_layer;\
  }\
\
}\
void print_predict_by_network_neurons_##type(neurons_##type *base, tensor_##type *input){\
    for(size_t i=0; i<(input->dim)->rank; ++i) (base->output)->x[i]=input->x[i];\
      neurons_##type * tmp=base->next_layer;\
      while(tmp){\
        calc_out_neurons_##type(tmp);\
        if(tmp->next_layer==NULL){\
          print_tensor_msg_##type(tmp->output,"retult");\
          \
        }\
        tmp = tmp->next_layer;\
      }\
\
  print_tensor_msg_##type(input,"from input:");\
  \
}\
\
void print_predict_by_network_with_error_neurons_##type(neurons_##type *base, tensor_##type *input, tensor_##type *target){\
  init_copy_in_out_networks_from_tensors_##type(base, input, target);\
      neurons_##type * tmp=base->next_layer;\
      while(tmp){\
        calc_out_neurons_##type(tmp);\
        if(tmp->next_layer==NULL){\
          print_tensor_msg_##type(tmp->output,"retult");\
          \
        }\
        tmp = tmp->next_layer;\
      }\
\
\
  printf(" error : %f\n", error_out_##type(base));\
  print_tensor_msg_##type(input,"from input:");\
  \
}\
\
void update_cloneuronesets_weight_in_base_##type(cloneuronset_##type * clnrnst){\
  type sumDw=0;\
  size_t nb_clone=clnrnst->nb_clone;\
  neurons_##type **tmp_c=malloc(nb_clone*sizeof(neurons_##type *));\
  for(size_t c=0; c<nb_clone; ++c)\
    tmp_c[c] = (clnrnst->cloneurons[c])->next_layer;\
  neurons_##type *tmp=(clnrnst->base)->next_layer;\
  while(tmp){\
    for(size_t i=0; i<((tmp->weight_in)->dim)->rank; ++i){\
      sumDw=0;\
      for(size_t c=0; c<nb_clone; ++c){\
        sumDw += ((tmp_c[c])->weight_out)->x[i];\
         \
        \
      }\
      (tmp->weight_in)->x[i] = (tmp->weight_in)->x[i] - ( (tmp->learning_rate) * sumDw) / nb_clone ;\
    }\
    for(size_t c=0; c<nb_clone; ++c){\
      tmp_c[c]=(tmp_c[c])->next_layer;\
    }\
    tmp=tmp->next_layer;\
  }\
  /*while(tmp->next_layer){\
    for(size_t c=0; c<nb_clone; ++c){\
      tmp_c[c]=(tmp_c[c])->next_layer;\
    }\
    tmp=tmp->next_layer;\
  }\
  while(tmp != clnrnst->base){\
    for(size_t i=0; i<((tmp->weight_in)->dim)->rank; ++i){\
      sumDw=0;\
      for(size_t c=0; c<nb_clone; ++c){\
    (tmp_c[c])->TensorProduct(&((tmp_c[c])->weight_out), (tmp_c[c])->input, (tmp_c[c])->delta_out, (tmp_c[c])->nb_prod_thread);\
        sumDw += ((tmp_c[c])->weight_out)->x[i];\
         \
        \
      }\
      (tmp->weight_in)->x[i] = (tmp->weight_in)->x[i] - ( (tmp->learning_rate) * sumDw) / nb_clone ;\
    }\
    for(size_t c=0; c<nb_clone; ++c){\
      tmp_c[c]=(tmp_c[c])->prev_layer;\
    }\
    tmp=tmp->prev_layer;\
  }*/\
  free(tmp_c);\
}\
\
void copy_weight_in_neurons_##type(neurons_##type *dst_nrns, neurons_##type *src_nrns){\
  neurons_##type *tmp_src = src_nrns;\
  neurons_##type *tmp_dst = dst_nrns;\
  while(tmp_src){\
    copy_tensor_##type(tmp_dst->weight_in,tmp_src->weight_in);\
    tmp_src = tmp_src->next_layer;\
    tmp_dst = tmp_dst->next_layer;\
  }\
}\
\
type clon_error_batch_##type(cloneuronset_##type * clnrnst){\
  \
  type err=0;\
  size_t nb_clone=clnrnst->nb_clone;\
  neurons_##type **tmp_c=malloc(nb_clone*sizeof(neurons_##type *));\
  for(size_t c=0; c<nb_clone; ++c)\
    tmp_c[c] = (clnrnst->cloneurons[c]);\
  neurons_##type *tmp=(clnrnst->base);\
  while(tmp->next_layer){\
    for(size_t c=0; c<nb_clone; ++c)\
      tmp_c[c]=(tmp_c[c])->next_layer;\
    tmp=tmp->next_layer;\
  }\
  err=0;\
      for(size_t i=0; i<((tmp->target)->dim)->rank; ++i){\
        for(size_t c=0; c<nb_clone; ++c){\
          err += (tmp_c[c])->L(((tmp_c[c])->target)->x[i],((tmp_c[c])->output)->x[i]);\
        }\
      }\
  free(tmp_c);\
  \
  return err / (nb_clone * ((tmp->target)->dim)->rank);\
}\
\
struct arg_learnCloneuronset_##type{\
  size_t id_th;\
  sem_t *semaphore_datas;\
  sem_t *semaphore_learn;\
  size_t *id_datas;\
  bool *ending;\
  neurons_##type *base_c;\
  data_set_##type *dataset;\
};\
void* run_learnCloneuronset_thread_##type(void *arg){\
  struct arg_learnCloneuronset_##type *arg_t = arg;\
  size_t id_th = arg_t->id_th;\
  sem_t *semaphore_datas = arg_t->semaphore_datas;\
  sem_t *semaphore_learn = arg_t->semaphore_learn;\
  size_t *id_datas = arg_t->id_datas;\
  bool *ending = arg_t->ending;\
  neurons_##type *base_c = arg_t->base_c;\
  data_set_##type *dataset = arg_t->dataset;\
  neurons_##type *tmp, *ttmp;\
  while(!(*ending)){\
    sem_wait(semaphore_datas);\
    /*if((*ending)) break;\
    */init_copy_in_out_networks_from_tensors_##type(base_c, dataset->input[id_datas[id_th]],dataset->target[id_datas[id_th]]);\
    /*printf(" id_datas [%ld] = %ld\n",id_th,id_datas[id_th]);\
    */tmp=base_c->next_layer;\
      while(tmp){\
        calc_out_neurons_##type(tmp);\
        ttmp = tmp;\
        tmp = tmp->next_layer;\
      }\
      while(ttmp != base_c){\
        calc_delta_neurons_##type(ttmp);\
        ttmp->TensorProduct(&(ttmp->weight_out), ttmp->input, ttmp->delta_out, ttmp->nb_prod_thread);\
       /*only_update_weight_neurons_##type(ttmp);\
        *//*update_weight_neurons_##type(ttmp);\
        */\
        ttmp = ttmp->prev_layer;\
      }\
    sem_post(semaphore_learn);\
  }\
  sem_post(semaphore_learn);\
  return 0;\
}\
\
size_t learning_cloneuronset_##type(cloneuronset_##type *clnrnst, data_set_##type *dataset,  bool (*condition)(type, size_t)){\
  size_t nbreps=0;\
  size_t curData=0;\
  type err=0;\
  bool *ending=malloc(sizeof(bool));\
  *ending=false;\
  size_t nb_clone = clnrnst->nb_clone;\
  sem_t *semaphore_datas=malloc(sizeof(sem_t));\
  sem_t *semaphore_learn=malloc(sizeof(sem_t));\
  sem_init(semaphore_datas,0,0);\
  sem_init(semaphore_learn,0,0);\
  size_t *id_datas = malloc(nb_clone * sizeof(size_t));\
    \
  pthread_t *thrd = malloc(nb_clone * sizeof(pthread_t));\
  struct arg_learnCloneuronset_##type **arg_th = malloc( nb_clone * sizeof(struct arg_learnCloneuronset_##type *));\
\
  for(size_t i = 0; i < nb_clone; ++i){\
    arg_th[i]=malloc(sizeof(struct arg_learnCloneuronset_##type));\
    arg_th[i]->id_th=i;\
    arg_th[i]->semaphore_datas=semaphore_datas;\
    arg_th[i]->semaphore_learn=semaphore_learn;\
    arg_th[i]->ending=ending;\
    arg_th[i]->base_c = clnrnst->cloneurons[i] ;\
    arg_th[i]->dataset = dataset ;\
    arg_th[i]->id_datas= id_datas ;\
    \
    pthread_create(&thrd[i], NULL, run_learnCloneuronset_thread_##type, (void*)arg_th[i]);\
    \
  }\
\
  \
  while(!(*ending)){\
    for(size_t c=0; c<nb_clone; ++c){\
      id_datas[c]=curData;\
      curData = (curData + 1) % (dataset->size);\
      \
    }\
    for(size_t c=0; c<nb_clone; ++c){\
      sem_post(semaphore_datas);\
    }\
    /* ============ ============= ============ */\
    \
    for(size_t c=0; c<nb_clone; ++c){\
      sem_wait(semaphore_learn);\
    }\
    \
    /*neurons_##type *tmp = (clnrnst->cloneurons[0])->next_layer;\
    while(tmp){\
      only_update_weight_neurons_##type(tmp);\
      tmp=tmp->next_layer;\
    }*/\
    update_cloneuronesets_weight_in_base_##type(clnrnst);\
    err = ABSMAX(err,clon_error_batch_##type(clnrnst));\
    \
    /*err = ABSMAX(err,error_out_##type(clnrnst->cloneurons[0]));\
    */nbreps += nb_clone;\
    *ending = condition(err, nbreps) ;\
  }\
  \
  printf("reps batch learning : %ld\n",nbreps);\
    for(size_t c=0; c<nb_clone; ++c){\
      sem_post(semaphore_datas);\
    }\
  \
  \
  for(size_t i=0; i< nb_clone; ++i){\
    pthread_join(thrd[i], NULL);\
    free(arg_th[i]);\
  }\
\
  free(thrd);\
  free(arg_th);\
  sem_destroy(semaphore_datas);\
  sem_destroy(semaphore_learn);\
  free(semaphore_datas);\
  free(semaphore_learn);\
  free(ending);\
  free(id_datas);\
  return nbreps;\
}  \
\

 
  
  
GEN_NEURONS_F_(TYPE_FLOAT)
GEN_NEURONS_F_(TYPE_DOUBLE)
