/* file: y_network_neural_network/include/y_net_neur_net/y_nnn_manager.h */
#ifndef Y_NETWORK_NEURAL_NETWORK__MANAGER__H_C
#define Y_NETWORK_NEURAL_NETWORK__MANAGER__H_C

#include <pthread.h>
#include <string.h>

#include "learn_to_drive.h"

#include "y_net_neur_net/y_nnn_screen_manager.h"

#include "y_socket_t/y_socket_t.h"

void y_nnn_manager_handle_input(char * buf, int len_buf, void *arg);

struct arg_run_qlearn_bprint{
  struct arg_bash *bash_arg;
  struct RL_agent *rlAgent;
};

struct arg_run_qlearn_bprint * create_arg_run_qlearn_bprint(
  struct arg_bash *bash_arg,
  struct RL_agent *rlAgent
);

void free_arg_run_qlearn_bprint(struct arg_run_qlearn_bprint *arg);

void* runBashPrint(void *arg);

#endif /* Y_NETWORK_NEURAL_NETWORK__MANAGER__H_C */
