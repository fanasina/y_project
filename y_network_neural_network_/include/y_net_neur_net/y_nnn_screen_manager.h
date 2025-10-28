/* file: y_network_neural_network/include/y_net_neur_net/y_nnn_screenmanager.h */
#ifndef Y_NETWORK_NEURAL_NETWORK__SCREEN_MANAGER__H_C
#define Y_NETWORK_NEURAL_NETWORK__SCREEN_MANAGER__H_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


#include <ctype.h>
#include <dirent.h>


#include "list_t/list_t.h"

GENERATE_LIST_ALL(pid_t)


//#include "y_socket_t/y_list_var_tool.h"

pid_t max_pidof_to_list_pid_t(char *target, struct main_list_pid_t *m_pid_t);

int sprintbashpid(pid_t pid, char *content, size_t size_content);


#endif /* Y_NETWORK_NEURAL_NETWORK__SCREEN_MANAGER__H_C */
