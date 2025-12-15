#ifndef __LEARNING_VEHICLE__C_H____
#define __LEARNING_VEHICLE__C_H____

#include <stdlib.h>
#include <pthread.h>
 /* for Sleep : milliseconds */
#ifdef WINDOWS
#include <windows.h>
//#ifdef LINUX
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif
#include <errno.h>
#include <sys/stat.h>

#include "neuron_t/neuron_t.h"
#include "neuron_t/nneuron_t_file.h"

#include "list_t/list_t.h"


#include "vehicle.h"

#ifndef CHECK_NAN
#define CHECK_NAN 0
#endif

//float reLU(float x);

//float d_reLU(float x);

// to debug symlink error!: have to instal libexplain-dev (apt install), 
// and add -lexplain in cflag (or in compile flag)
//#include <libexplain/symlink.h>

//#define target_symlink ".ff_target_.symlink"
//#define main_symlink ".ff_main_.symlink"

extern char *action_name[8];

struct qlearning_params {
  float gamma;
  float learning_rate;
  float factor_update_learning_rate;
 // float epsilon;
  float minimum_threshold_learning_rate;
  float discount_factor;
  float exploration_factor;
  float factor_update_exploration_factor;
  float minimum_threshold_exploration_factor;
  long int nb_training_before_update_weight_in_target;
  size_t number_episodes;
//  size_t threshold_number_same_action;
  char *caller_func_name;
};


struct status_qlearning {
  struct main_list_TYPE_L_INT * list_main_cumul;
  struct main_list_TYPE_L_INT * list_target_cumul;
  struct main_list_TYPE_L_INT * progress_best_cumul;
  long int nb_training_after_updated_weight_in_target;
  size_t nb_episodes;
  size_t index_episode;
  int action;
  int ending;
	pthread_mutex_t *mut_ending;
//  size_t count_last_action;
};

struct delay_params {
  size_t delay_between_episodes;
  size_t delay_between_games;
};

struct print_params {
  bool printed;
  pthread_mutex_t mut_printed;
  float scale_x; 
  float scale_y;
  struct delay_params *delay;
  char *string_space;//[LOG_LENTH];
  int go_on;
};

int check_go_on_print_params(struct print_params *pprint);

struct networks_qlearning {
  config_layers *config;
  neurons_TYPE_FLOAT *main_net;
  neurons_TYPE_FLOAT *target_net;
  neurons_TYPE_FLOAT *best_net;
	pthread_t *thread_learn;
	ssize_t nb_successive_action[COUNT_ACTION];
};

struct RL_agent {
  struct networks_qlearning * networks;
  struct vehicle * car;
  struct status_qlearning * status;
  struct print_params * pprint;
  struct qlearning_params *qlearnParams;

};

struct networks_qlearning * create_network_qlearning(
  struct config_layers * config,
  bool randomize, float minR, float maxR,  int randomRange,
  size_t nb_prod_thread,
  size_t nb_calc_thread,
  float learning_rate
);
struct status_qlearning * create_status_qlearning ();
struct delay_params * create_delay_params (
  size_t delay_between_episodes,
  size_t delay_between_games
);
struct print_params * create_print_params(
  float scale_x, float scale_y,  
  struct delay_params * dly_p
);

struct qlearning_params * create_qlearning_params (
  float gamma,
  float learning_rate,
  float discount_factor,
  float exploration_factor,
  long int nb_training_before_update_weight_in_target,
  size_t number_episodes
);

struct RL_agent * create_RL_agent (
  struct networks_qlearning * networks,
  struct vehicle * car,
  struct status_qlearning * status,
  struct print_params * pprint,
  struct qlearning_params *qlearnParams
);

void free_networks_qlearning (struct networks_qlearning * networks);
void free_status_qlearning(struct status_qlearning *status_ql);
void free_print_params (struct print_params *pprint);
void free_delay_params (struct delay_params *dly_p);
void free_qlearning_params(struct qlearning_params *q_params);
void free_RL_agent(struct RL_agent *rlAgent);

void copy_weight_in_networks_from_main_to_target(struct networks_qlearning * networks);
void copy_weight_in_networks_from_main_to_best(struct networks_qlearning * networks);

void train_qlearning(struct RL_agent * rlAgent,
  int action); 
//  tensor_TYPE_FLOAT * new_state /*input*/,
//  tensor_TYPE_FLOAT * state /*input*/,
//  long reward;

//void* learn_to_drive(struct RL_agent * rlAgent);
void* learn_to_drive(void * rlAgent);
int is_ending(struct status_qlearning *qlStatus);

///char *fileNameDateScore(char * pre, char* post,size_t score);
///int select_action(struct RL_agent * rlAgent);

#endif /* __LEARNING_VEHICLE__C_H____ */
