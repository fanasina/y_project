#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for sleep !
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif

#include "ftest/ftest.h"
#include "ftest/ftest_array.h"
#include "fmock/fmock.h"

#include "y_net_neur_net/y_nnn_manager.h"
#include "y_net_neur_net/y_nnn_screen_manager.h"


TEST(pidof_bash){
  struct arg_bash *arg= create_arg_bash();
  launch_new_bash((void*)arg);

    char buf[256];
  int len_buf = sprintf(buf," main Hello, voici le terminal avec new_bash_pid=%d et getpid=%d, old_bash_pid=%d\n\n",arg->new_bash_pid, getpid(), arg->new_bash_pid);

  char str[80];
  int len_str=_xy_goto(str,0,0);
  char index_str[8];
  int len_index_str;
  for(int i=0;i<200;++i){
    write(1,":",1);
    write(arg->fd_new_bash_pid, str, len_str);
    len_index_str=sprintf(index_str, "%d", i);
    write(arg->fd_new_bash_pid, index_str, len_index_str);
    write(arg->fd_new_bash_pid, buf, len_buf);
    usleep(40000);
  }
  write(1,"\n",1);

  free_arg_bash(arg);

}

TEST(wait_bash){
  struct arg_bash *arg= create_arg_bash();
  launch_wait_bash((void*)arg);

    char buf[256];
  int len_buf = sprintf(buf," main Hello, voici le terminal avec new_bash_pid=%d et getpid=%d, old_bash_pid=%d\n\n",arg->new_bash_pid, getpid(), arg->new_bash_pid);

  char str[80];
  int len_str=_xy_goto(str,0,0);
  char index_str[8];
  int len_index_str;
  for(int i=0;i<200;++i){
    write(1,":",1);
    write(arg->fd_current_bash_pid, str, len_str);
    len_index_str=sprintf(index_str, "%d", i);
    write(arg->fd_current_bash_pid, index_str, len_index_str);
    write(arg->fd_current_bash_pid, buf, len_buf);
    usleep(40000);
  }
  write(1,"\n",1);

  free_arg_bash(arg);

}


TEST(new_and_wait_bash){
  struct arg_bash *arg= create_arg_bash();
  run_newbash((void*)arg);
  pthread_t th;
  pthread_create(&th, NULL, wait_newbash, ((void*)arg));

    char buf[256];
  int len_buf = sprintf(buf," main Hello, voici le terminal avec new_bash_pid=%d et getpid=%d, old_bash_pid=%d\n\n",arg->new_bash_pid, getpid(), arg->new_bash_pid);

//  char str[80];
//  int len_str=_xy_goto(str,0,0);
  char index_str[18];
  int len_index_str;
  for(int i=0;i<700;++i){
    if(i%70)write(1,":",1);
    else write(1,"\r",1);
      len_index_str=sprintf(index_str, "%d ", i);
    if(arg->fd_new_bash_pid>0){
      write(arg->fd_new_bash_pid, GOTO_TOP_LEFT, LEN_GOTO_TOP_LEFT);
      write(arg->fd_new_bash_pid, index_str, len_index_str);
      write(arg->fd_new_bash_pid, buf, len_buf);
    }
    if(arg->fd_current_bash_pid>0){
      write(arg->fd_current_bash_pid, GOTO_TOP_LEFT, LEN_GOTO_TOP_LEFT);
      write(arg->fd_current_bash_pid, index_str, len_index_str);
      write(arg->fd_current_bash_pid, buf, len_buf);

    }
    usleep(40000);
  }
  write(1,"\n",1);

  pthread_join(th, NULL);

  free_arg_bash(arg);

}


TEST(sleep_wait_bash){
  struct arg_bash *arg= create_arg_bash();
  launch_sleep_wait_bash((void*)arg);

    char buf[256];
  int len_buf = sprintf(buf," main Hello, voici le terminal avec new_bash_pid=%d et getpid=%d, old_bash_pid=%d\n\n",arg->new_bash_pid, getpid(), arg->new_bash_pid);

  char str[80];
  int len_str=_xy_goto(str,0,0);
  char index_str[8];
  int len_index_str;
  for(int i=0;i<200;++i){
    write(1,":",1);
    write(arg->fd_current_bash_pid, str, len_str);
    len_index_str=sprintf(index_str, "%d", i);
    write(arg->fd_current_bash_pid, index_str, len_index_str);
    write(arg->fd_current_bash_pid, buf, len_buf);
    usleep(40000);
  }
  write(1,"\n",1);

  free_arg_bash(arg);

}

TEST(new_or_wait_bash){
  struct arg_bash *arg= create_arg_bash();
  pthread_t th;
  pthread_create(&th, NULL, wait_sleep_newbash, ((void*)arg));
  usleep(5000000);
  run_newbash((void*)arg);

    char buf[256];
  int len_buf = sprintf(buf," main Hello, voici le terminal avec new_bash_pid=%d et getpid=%d, old_bash_pid=%d\n\n",arg->new_bash_pid, getpid(), arg->new_bash_pid);

//  char str[80];
//  int len_str=_xy_goto(str,0,0);
  char index_str[18];
  int len_index_str;
  for(int i=0;i<700;++i){
    if(i%70)write(1,":",1);
    else write(1,"\r",1);
      len_index_str=sprintf(index_str, "%d ", i);
    if(arg->fd_new_bash_pid>0){
      write(arg->fd_new_bash_pid, GOTO_TOP_LEFT, LEN_GOTO_TOP_LEFT);
      write(arg->fd_new_bash_pid, index_str, len_index_str);
      write(arg->fd_new_bash_pid, buf, len_buf);
    }
    if(arg->fd_current_bash_pid>0){
      write(arg->fd_current_bash_pid, GOTO_TOP_LEFT, LEN_GOTO_TOP_LEFT);
      write(arg->fd_current_bash_pid, index_str, len_index_str);
      write(arg->fd_current_bash_pid, buf, len_buf);

    }
    usleep(40000);
  }
  write(1,"\n",1);

  pthread_join(th, NULL);

  free_arg_bash(arg);

}


void *func_bash(void* b_arg){
  struct arg_bash *bash_arg = (struct arg_bash*)b_arg;

  while(check_go_on_bash(bash_arg)){ 

    pthread_mutex_lock(bash_arg->mut_bash_var);
    while(
      (bash_arg->fd_new_bash_pid == -1) &&
      (bash_arg->fd_current_bash_pid == -1)
      ){
      printf("debug: wait new bash!\n");
      pthread_cond_wait(bash_arg->cond_bash_var, bash_arg->mut_bash_var);
    }
    pthread_mutex_unlock(bash_arg->mut_bash_var); 
    char buf[256];
    int len_buf = sprintf(buf," main Hello, voici le terminal avec new_bash_pid=%d et getpid=%d, old_bash_pid=%d\n\n",bash_arg->new_bash_pid, getpid(), bash_arg->new_bash_pid);

   
    char index_str[18];
    int len_index_str;
    for(int i=0;i<200;++i){
      //if(i%70)write(1,":",1);
      //else write(1,"\r",1);
        len_index_str=sprintf(index_str, "%d ", i);
      if(bash_arg->fd_new_bash_pid>0){
        write(bash_arg->fd_new_bash_pid, GOTO_TOP_LEFT, LEN_GOTO_TOP_LEFT);
        write(bash_arg->fd_new_bash_pid, index_str, len_index_str);
        write(bash_arg->fd_new_bash_pid, buf, len_buf);
      }
      if(bash_arg->fd_current_bash_pid>0){
        write(bash_arg->fd_current_bash_pid, GOTO_TOP_LEFT, LEN_GOTO_TOP_LEFT);
        write(bash_arg->fd_current_bash_pid, index_str, len_index_str);
        write(bash_arg->fd_current_bash_pid, buf, len_buf);

      }
      usleep(40000);
    }
    //write(1,"\n",1);
  }
  
  return NULL;
}

TEST(try_y_socket_manager){
  struct arg_bash *bash_arg= create_arg_bash();
  struct arg_var_ * var = create_arg_var_(y_nnn_manager_handle_input, bash_arg);
  struct y_socket_t *argS=y_socket_create("1600", 2, 3, var);

  pthread_t pollTh;
  pthread_create(&pollTh, NULL, y_socket_poll_fds, (void*)argS);

  pthread_t bashprinth;
  pthread_create(&bashprinth, NULL, func_bash, (void*)bash_arg);

  wait_var_set_up_value_not_equal(var, 0);
  
  
  pthread_join(pollTh, NULL);

  set_go_on_bash(bash_arg, 0);
  pthread_join(bashprinth, NULL);

  y_socket_free(argS);
  free_arg_var_(var);
  free_arg_bash(bash_arg);

}

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
