#include "learn_to_drive.h"


float reLU(float x){
  if(x>0) return x;
  return 0;
}

float d_reLU(float x){
  if (x>0) return 1;
  return 0;
}

float L2(float t, float o){
  return (o - t) * (o - t)/2;
}

float D_L2(float t, float o){
  return (o - t);
}

void copy_weight_in_networks_from_main_to_target(struct networks_qlearning * networks){
  copy_weight_in_neurons_TYPE_FLOAT(networks->target_net, networks->main_net);
}
void copy_weight_in_networks_from_main_to_best(struct networks_qlearning * networks){
  copy_weight_in_neurons_TYPE_FLOAT(networks->best_net, networks->main_net);
}

struct networks_qlearning * create_nework_qlearning(
  struct config_layers * config,
  bool randomize, float minR, float maxR,  int randomRange
){
  struct networks_qlearning *qnets = malloc(sizeof(struct networks_qlearning));
  qnets->config = config;

  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->main_net), config, 
    random, minR, maxR, randomRange);  
  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->target_net), config, 
    false, minR, maxR, randomRange);  
  copy_weight_in_networks_from_main_to_target(qnets);
  
  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->best_net), config, 
    false, minR, maxR, randomRange);  
  copy_weight_in_networks_from_main_to_best(qnets);

  return qnets; 

}

struct status_qlearning * create_status_qlearning (){
  struct status_qlearning * status_ql = malloc(sizeof(struct status_qlearning));
  
  status_ql->list_main_cumul = create_var_list_TYPE_L_INT();
  status_ql->list_target_cumul = create_var_list_TYPE_L_INT();
  status_ql->progress_best_cumul = create_var_list_TYPE_L_INT();
  
  status_ql->nb_training_after_updated_weight_in_target = 0;

  return status_ql;
}

struct delay_params * create_delay_params (
  size_t delay_between_episodes,
  size_t delay_between_games
){
  struct delay_params * delay = malloc(sizeof(struct delay_params));
  delay->delay_between_episodes = delay_between_episodes;
  delay->delay_between_games = delay_between_games;

  return delay;
}

struct qlearning_params * create_qlearning_params  (
  double learning_rate,
  double discount_factor,
  double exploration_factor,
  long int nb_training_before_update_weight_in_target
){
  struct qlearning_params * qparams = malloc(sizeof(struct qlearning_params));

  qparams->learning_rate = learning_rate ;
  qparams->discount_factor = discount_factor ;
  qparams->exploration_factor = exploration_factor ;
  
  qparams->nb_training_before_update_weight_in_target = nb_training_before_update_weight_in_target;

  return qparams;
}

struct RL_agent * create_RL_agent (
  struct networks_qlearning * networks,
  struct vehicle * car,
  struct status_qlearning * status,
  struct delay_params * delay,
  struct qlearning_params *qlearnParams
){
  struct RL_agent * rlagent = malloc(sizeof(struct RL_agent));

  rlagent->networks = networks ;
  rlagent->car = car ;
  rlagent->status = status ;
  rlagent->delay = delay ;
  rlagent->qlearnParams = qlearnParams ;

  return rlagent;
}

void free_networks_qlearning (struct networks_qlearning * networks){
  free_neurons_TYPE_FLOAT(networks->main_net);
  free_neurons_TYPE_FLOAT(networks->target_net);
  free_neurons_TYPE_FLOAT(networks->best_net);
  free_config_layers(networks->config);
  free(networks);
}
void free_status_qlearning(struct status_qlearning *status_ql){
  free_all_var_list_TYPE_L_INT(status_ql->list_main_cumul);
  free_all_var_list_TYPE_L_INT(status_ql->list_target_cumul);
  free_all_var_list_TYPE_L_INT(status_ql->progress_best_cumul);
  free(status_ql);
}
void free_delay_params (struct delay_params *dly_p){
  free(dly_p);
}
void free_qlearning_params(struct qlearning_params *q_params){
  free(q_params);
}
void free_RL_agent(struct RL_agent *rlAgent){
  free(rlAgent->qlearnParams);
  free(rlAgent->delay);
  free_status_qlearning(rlAgent->status);
  free_networks_qlearning(rlAgent->networks);
  free_vehicle(rlAgent->car);

  free(rlAgent);
}

void train_qlearning(struct RL_agent * rlAgent, 
  int action /*  */, 
  tensor_TYPE_FLOAT * new_state /*input*/, 
  tensor_TYPE_FLOAT * state /*input*/, 
  long reward){
  tensor_TYPE_FLOAT * action_value = NULL;
  tensor_TYPE_FLOAT * next_action_value = NULL;
  neurons_TYPE_FLOAT * net_main = rlAgent->networks->main_net;
  neurons_TYPE_FLOAT * net_target = rlAgent->networks->target_net;
  calculate_output_by_network_neurons_TYPE_FLOAT(net_main, state, &action_value);
  calculate_output_by_network_neurons_TYPE_FLOAT(net_target, state, &next_action_value);
  tensor_TYPE_FLOAT * experimental_values = CREATE_TENSOR_FROM_CPY_DIM_TYPE_FLOAT(action_value->dim);
  
  struct game_status * car_status = rlAgent->car->status;
  if( copy_tensor_TYPE_FLOAT(experimental_values, action_value) == 0 /* done */){
    if(car_status->done){

    }
  }
  
}
