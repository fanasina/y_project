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

struct reward_lists * create_reward_lists (){
  struct reward_lists * rwrd_l = malloc(sizeof(struct reward_lists));
  
  rwrd_l->list_main_cumul = create_var_list_TYPE_L_INT();
  rwrd_l->list_target_cumul = create_var_list_TYPE_L_INT();
  rwrd_l->progress_best_cumul = create_var_list_TYPE_L_INT();

  return rwrd_l;
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
  double exploration_factor
){
  struct qlearning_params * qparams = malloc(sizeof(struct qlearning_params));

  qparams->learning_rate = learning_rate ;
  qparams->discount_factor = discount_factor ;
  qparams->exploration_factor = exploration_factor ;

  return qparams;
}

struct RL_agent * create_RL_agent (
  struct networks_qlearning * networks,
  struct vehicle * car,
  struct reward_lists * rewards,
  struct delay_params * delay,
  struct qlearning_params *qlearnParams
){
  struct RL_agent * rlagent = malloc(sizeof(struct RL_agent));

  rlagent->networks = networks ;
  rlagent->car = car ;
  rlagent->rewards = rewards ;
  rlagent->delay = delay ;
  rlagent->qlearnParams = qlearnParams ;

  return rlagent;
}

void free_networks_qlearning (struct networks_qlearning * networks){

}
void free_reward_lists(struct reward_lists *rwd_l){

}
void free_delay_params (struct delay_params *dly_p){

}
void free_qlearning_params(struct qlearning_params *q_params){

}
void free_RL_agent(struct RL_agent *rlAgent){

}

