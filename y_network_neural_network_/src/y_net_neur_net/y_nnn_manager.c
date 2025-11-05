/* file: y_network_neural_network/src/y_net_neur_net/y_nnn_manager.c */

#include "y_net_neur_net/y_nnn_manager.h"

void y_nnn_manager_handle_input(char * buf, int len_buf, void *arg){
  //struct arg_bash *bash_arg=(struct arg_bash*)arg;
  
  if(arg && (len_buf>0)){
    
    printf("debug: %s #%d (%d)\n",buf,len_buf,((struct arg_bash*)arg)->old_bash_pid);
    if(strncmp(buf,"newbash",7)==0){
      run_newbash(arg);
    }else if(strncmp(buf,"waitbash",8)==0){
      launch_sleep_wait_bash(arg);
    }else if(strncmp(buf,"killbash",8)==0){
      kill_all_bash(arg);
    }else{
      printf("debug: %s is not handle\n",buf);
    }
  }
  
}


