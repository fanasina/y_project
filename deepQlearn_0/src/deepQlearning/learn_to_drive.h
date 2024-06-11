#ifndef __LEARNING_VEHICLE__C_H____
#define __LEARNING_VEHICLE__C_H____

//#include <pthread.h>

#include "neuron_t/neuron_t.h"

#include "list_t/list_t.h"


#include "vehicle.h"

//float reLU(float x);

//float d_reLU(float x);


struct qlearning_params {
  double learning_rate;
  double discount_factor;
  double exploration_factor;
};


struct reward_lists {
  struct main_list_TYPE_L_INT * list_main_cumul;
  struct main_list_TYPE_L_INT * list_target_cumul;
  struct main_list_TYPE_L_INT * progress_best_cumul;
};

struct delay_params {
  size_t delay_between_episodes;
  size_t delay_between_games;
};

struct networks_qlearning {
  config_layers *config;
  neurons_TYPE_FLOAT *main_net;
  neurons_TYPE_FLOAT *target_net;
  neurons_TYPE_FLOAT *best_net;
};

struct RL_agent {
  struct networks_qlearning * networks;
  struct vehicle * car;
  struct reward_lists * rewards;
  struct delay_params * delay;
  struct qlearning_params *qlearnParams;

};

struct networks_qlearning * create_nework_qlearning(
  struct config_layers * config,
  bool randomize, float minR, float maxR,  int randomRange
);
struct reward_lists * create_reward_lists ();
struct delay_params * create_delay_params (
  size_t delay_between_episodes,
  size_t delay_between_games
);

struct qlearning_params (
  double learning_rate,
  double discount_factor,
  double exploration_factor
);

struct RL_agent * create_RL_agent (
  struct networks_qlearning * networks,
  struct vehicle * car,
  struct reward_lists * rewards,
  struct delay_params * delay,
  struct qlearning_params *qlearnParams
);

void free_networks_qlearning (struct networks_qlearning * networks);
void free_reward_lists(struct reward_lists *rwd_l);
void free_delay_params (struct delay_params *dly_p);
void free_qlearning_params(struct qlearning_params *q_params);
void free_RL_agent(struct RL_agent *rlAgent);

void copy_weight_in_networks_from_main_to_target(struct networks_qlearning * networks);
void copy_weight_in_networks_from_main_to_best(struct networks_qlearning * networks);


#endif /* __LEARNING_VEHICLE__C_H____ */
