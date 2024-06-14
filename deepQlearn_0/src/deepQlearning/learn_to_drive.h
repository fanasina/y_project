#ifndef __LEARNING_VEHICLE__C_H____
#define __LEARNING_VEHICLE__C_H____

//#include <pthread.h>

#include "neuron_t/neuron_t.h"

#include "list_t/list_t.h"


#include "vehicle.h"

//float reLU(float x);

//float d_reLU(float x);


struct qlearning_params {
  double gamma;
  double learning_rate;
  double factor_update_learning_rate;
  double minimum_threshold_learning_rate;
  double discount_factor;
  double exploration_factor;
  double factor_update_exploration_factor;
  double minimum_threshold_exploration_factor;
  long int nb_training_before_update_weight_in_target;
};


struct status_qlearning {
  struct main_list_TYPE_L_INT * list_main_cumul;
  struct main_list_TYPE_L_INT * list_target_cumul;
  struct main_list_TYPE_L_INT * progress_best_cumul;
  long int nb_training_after_updated_weight_in_target;
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
  struct status_qlearning * status;
  struct delay_params * delay;
  struct qlearning_params *qlearnParams;

};

struct networks_qlearning * create_nework_qlearning(
  struct config_layers * config,
  bool randomize, float minR, float maxR,  int randomRange
);
struct status_qlearning * create_status_qlearning ();
struct delay_params * create_delay_params (
  size_t delay_between_episodes,
  size_t delay_between_games
);

struct qlearning_params * create_qlearning_params (
  double gamma,
  double learning_rate,
  double discount_factor,
  double exploration_factor,
  long int nb_training_before_update_weight_in_target
);

struct RL_agent * create_RL_agent (
  struct networks_qlearning * networks,
  struct vehicle * car,
  struct status_qlearning * status,
  struct delay_params * delay,
  struct qlearning_params *qlearnParams
);

void free_networks_qlearning (struct networks_qlearning * networks);
void free_status_qlearning(struct status_qlearning *status_ql);
void free_delay_params (struct delay_params *dly_p);
void free_qlearning_params(struct qlearning_params *q_params);
void free_RL_agent(struct RL_agent *rlAgent);

void copy_weight_in_networks_from_main_to_target(struct networks_qlearning * networks);
void copy_weight_in_networks_from_main_to_best(struct networks_qlearning * networks);

void train_qlearning(struct RL_agent * rlAgent,
  int action ,
  tensor_TYPE_FLOAT * new_state /*input*/,
  tensor_TYPE_FLOAT * state /*input*/,
  long reward);

#endif /* __LEARNING_VEHICLE__C_H____ */
