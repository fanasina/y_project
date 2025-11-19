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
#include <pthread.h>

#include "list_t/list_t.h"

#include "vehicle.h"

GENERATE_LIST_ALL(pid_t)

#define SIZE_LOCAL_BUF 300

#define GOTO_TOP_LEFT "\x1B[0;0f"
#define LEN_GOTO_TOP_LEFT 6

#define BASH_WRITE_IF_EXIST(bash,buf,len_buf) \
  do{\
    if(bash_arg->fd_new_bash_pid>0){\
      write(bash_arg->fd_new_bash_pid, buf, len_buf);\
    }\
    if(bash_arg->fd_current_bash_pid>0){\
      write(bash_arg->fd_current_bash_pid, buf, len_buf);\
    }\
  } while(0);

//#include "y_socket_t/y_list_var_tool.h"

pid_t pidof(char *target, struct main_list_pid_t *m_pid_t);

//int sprintbashpid(pid_t pid, char *content, size_t size_content);

int  _xy_goto(char *str, int x, int y);

struct arg_bash{
  pid_t old_bash_pid;
  pid_t new_bash_pid;
  pid_t current_bash_pid;

  int fd_old_bash_pid;
  int fd_new_bash_pid;
  int fd_current_bash_pid;
 
  pthread_t *thread_launch;
  pthread_t *thread_run_newbash;
  pthread_t *thread_run_waitbash;

  pthread_mutex_t *mut_bash_var;
  pthread_cond_t *cond_bash_var;
  int go_on;
};

struct arg_bash *create_arg_bash();
void free_arg_bash(struct arg_bash *arg);

//int open_duplicate_bash_most_recent();

//int open_duplicate_bash(pid_t pid);

//void close_duplicate_bash(int fd);

int write_duplicate_bash(int fd, char *content, size_t size_content);

int new_bash_exist(struct arg_bash *bash_arg);

void* run_newbash(void *arg);
void* wait_newbash(void *arg);
void* wait_sleep_newbash(void* argg);
void kill_all_bash(struct arg_bash *arg);
int check_go_on_bash(struct arg_bash *arg);
void set_go_on_bash(struct arg_bash *arg, int go_on);

/* pthread call of 3 previous functions */
void* launch_new_bash(void *arg);
void* launch_wait_bash(void *arg);
void* launch_sleep_wait_bash(void *arg);

void bash_print_vehicle_n_path(struct vehicle *v, float scale_x, float scale_y, struct arg_bash *bash_arg);
void bash_print2D_blocks_indexOne_withPoint(struct blocks *blk, float scale_x, float scale_y, coordinate *coordPoint, struct arg_bash *bash_arg);


#endif /* Y_NETWORK_NEURAL_NETWORK__SCREEN_MANAGER__H_C */
