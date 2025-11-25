/* file: y_network_neural_network/src/y_net_neur_net/y_nnn_manager.c */

#include "y_net_neur_net/y_nnn_manager.h"

struct arg_run_qlearn_bprint * create_arg_run_qlearn_bprint(
  struct arg_bash *bash_arg,
  struct RL_agent *rlAgent
){
  struct arg_run_qlearn_bprint *r_arg=malloc(sizeof(struct arg_run_qlearn_bprint));
  r_arg->bash_arg = bash_arg;
  r_arg->rlAgent = rlAgent;

  return r_arg;
}

void free_arg_run_qlearn_bprint(struct arg_run_qlearn_bprint *arg){
  free_RL_agent(arg->rlAgent);
  free_arg_bash(arg->bash_arg);
  free(arg);
}

void* run_sleep_wait_bash_and_print(void *arg);

void y_nnn_manager_handle_input(char * buf, int len_buf, void *arg){
  struct arg_run_qlearn_bprint *run_arg=(struct arg_run_qlearn_bprint*)arg;
  struct arg_bash *bash_arg=run_arg->bash_arg;
  struct RL_agent *rlAgent = run_arg->rlAgent;
  
  if(arg && (len_buf>0)){
    
    printf("debug: %s #%d (%d)\n",buf,len_buf,(bash_arg)->old_bash_pid);
    if(strncmp(buf,"newbash",7)==0){
      run_newbash(bash_arg);
    }else if(strncmp(buf,"waitbash",8)==0){
      launch_sleep_wait_bash(bash_arg);
    }else if(strncmp(buf,"killbash",8)==0){
      kill_all_bash(bash_arg);
    }else if((strncmp(buf,"kill",4)==0) ||  (strncmp(buf,"stoplearn",9)==0)){
      kill_all_bash(bash_arg);

			pthread_mutex_lock(rlAgent->status->mut_ending);
      rlAgent->status->ending=1;
      pthread_mutex_unlock(rlAgent->status->mut_ending);

			pthread_join(*(rlAgent->networks->thread_learn), NULL);
			// have to free here to not call pthread_join again when free networks 
			free(rlAgent->networks->thread_learn);
			// set NULL to avoid free again and call join!
			rlAgent->networks->thread_learn = NULL;

    }else if(strncmp(buf,"stopprint",9)==0){
      pthread_mutex_lock(bash_arg->mut_bash_var);
      bash_arg->go_on=0;
      pthread_mutex_unlock(bash_arg->mut_bash_var);
			if(bash_arg->thread_run_newbash)
				pthread_join(*(bash_arg->thread_run_newbash),NULL);
      if(bash_arg->thread_run_waitbash)
      	pthread_join(*(bash_arg->thread_run_waitbash),NULL);

			
    }else if(strncmp(buf,"goonprint",9)==0){
      pthread_mutex_lock(bash_arg->mut_bash_var);
      bash_arg->go_on=1;
      pthread_mutex_unlock(bash_arg->mut_bash_var);
		}else if(strncmp(buf,"startprintnewbash",17)==0){
      run_newbash(bash_arg);
			if(bash_arg->thread_run_newbash==NULL)
				bash_arg->thread_run_newbash=malloc(sizeof(pthread_t));
      pthread_create(bash_arg->thread_run_newbash, NULL, runBashPrint, arg);
      //pthread_t thread_run;
      //pthread_create(&thread_run, NULL, runBashPrint, arg);
      //Sleep(2);
      
    }else if(strncmp(buf,"startprintwaitbash",18)==0){
      if(bash_arg->thread_run_waitbash==NULL)
				bash_arg->thread_run_waitbash=malloc(sizeof(pthread_t));
      pthread_create(bash_arg->thread_run_waitbash, NULL, run_sleep_wait_bash_and_print, arg);
      //pthread_t thread_run;
      //pthread_create(&thread_run, NULL, run_sleep_wait_bash_and_print, arg);

    }else if(strncmp(buf,"stopprintbash",13)==0){
      pthread_mutex_lock(bash_arg->mut_bash_var);
      bash_arg->go_on=0;
      pthread_mutex_unlock(bash_arg->mut_bash_var);
    }else{
      printf("debug: %s is not handle\n",buf);
    }
  }
  
}


void* run_sleep_wait_bash_and_print(void *arg){
  struct arg_run_qlearn_bprint *arg_run=(struct arg_run_qlearn_bprint*)arg;
  //struct RL_agent *rlAgent = arg_run->rlAgent;
  struct arg_bash *bash_arg = arg_run->bash_arg;
  wait_sleep_newbash(bash_arg);
  return runBashPrint(arg);
}

void wait_valid_pid_bash(struct arg_bash *bash_arg){
  pthread_mutex_lock(bash_arg->mut_bash_var);
    while(
      (bash_arg->fd_new_bash_pid == -1) &&
      (bash_arg->fd_current_bash_pid == -1)
      ){
      printf("debug: wait new bash!\n");
      pthread_cond_wait(bash_arg->cond_bash_var, bash_arg->mut_bash_var);
    }
    pthread_mutex_unlock(bash_arg->mut_bash_var);

}

void* runBashPrint(void *arg){
  struct arg_run_qlearn_bprint *arg_run=(struct arg_run_qlearn_bprint*)arg;
  struct RL_agent *rlAgent = arg_run->rlAgent;
  struct arg_bash *bash_arg = arg_run->bash_arg;
	bash_arg->run_bash=1;
  struct status_qlearning *qlStatus = rlAgent->status;
  struct print_params * pprint = rlAgent->pprint;
  struct vehicle *car = rlAgent->car;
  size_t count_print = 0;
  char buf[SIZE_LOCAL_BUF];
  int len_buf;
  
  wait_valid_pid_bash(bash_arg);

  printf("debug: start runBashPrint in episode: %ld\n",qlStatus->index_episode);
  while( check_go_on_bash(bash_arg) && (new_bash_exist(bash_arg)) && check_go_on_print_params(pprint) && !is_ending(qlStatus)){
    if(/*(qlStatus->nb_episodes %125 == 0)  &&*/  pprint->printed){
          //pthread_mutex_lock(&(pprint->mut_printed));
          pthread_mutex_lock(&(car->mut_coord));
          bash_print_vehicle_n_path(car, pprint->scale_x, pprint->scale_y,bash_arg);
          pthread_mutex_unlock(&(car->mut_coord));

          //pthread_mutex_unlock(&(pprint->mut_printed));
          ////printf("%s ",pprint->string_space);
          len_buf=sprintf(buf,"%s ",pprint->string_space);
          BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)
#if 1
          ////printf("ep: %ld ",qlStatus->index_episode);
          len_buf=sprintf(buf,"ep: %ld\n",qlStatus->index_episode);
          BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)
          neurons_TYPE_FLOAT * net_main = rlAgent->networks->main_net;
          neurons_TYPE_FLOAT * net_target = rlAgent->networks->target_net;
          for(size_t i=0; (i<net_main->output->dim->rank) && (new_bash_exist(bash_arg)); ++i) {
            ////printf("{sensro[%s]:%f "" vs oldsens[%s]: %f}\n",action_name[i%COUNT_ACTION],net_target->output->x[i],
            len_buf = sprintf(buf,"{sensro[%s]:%f "" vs oldsens[%s]: %f}\n",action_name[i%COUNT_ACTION],net_target->output->x[i],action_name[i%COUNT_ACTION],net_main->output->x[i]);
            BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)

          }
          ////printf("\n< %5.2f > ( %s  ) \n", car->direction, action_name[qlStatus->action % COUNT_ACTION]);
          len_buf=sprintf(buf,"\n< %5.2f > ( %s  ) \n", car->direction, action_name[qlStatus->action % COUNT_ACTION]);
          BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)
          //print_weight_in_neurons_TYPE_FLOAT(net_main, "net_main_wei");
          //PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_main, weight_in, "net_main_we_in");
          ///PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_main, output, "net_main_out");
          //PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_target, output, "net_target_out");
          //PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_main, input, "net_main_input");
          ////printf(" action : %d , factor : %f nb_episodes : %ld \n",qlStatus->action,rlAgent->qlearnParams->exploration_factor, rlAgent->status->nb_episodes);
          len_buf=sprintf(buf," action : %d , factor : %f nb_episodes : %ld \n",qlStatus->action,rlAgent->qlearnParams->exploration_factor, rlAgent->status->nb_episodes);
          BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)

          FOR_LIST_FORM_BEGIN(TYPE_L_INT, qlStatus->progress_best_cumul){
            ////printf(" | %ld |,",(qlStatus->progress_best_cumul)->current_list->value);
            len_buf=sprintf(buf," | %ld |,",(qlStatus->progress_best_cumul)->current_list->value);
            BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)
          }
          ////printf("[%ld] %s ", rlAgent->car->status->cumulative_reward, pprint->string_space);
          len_buf=sprintf(buf,"[%ld] %s ", rlAgent->car->status->cumulative_reward, pprint->string_space);
          BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)
#endif
    }
          Sleep(pprint->delay->delay_between_games);
          ++count_print;
          if(count_print > 20){
            count_print = 0;
            ////clear_screen();
						len_buf=sprintf(buf,"\e[2J\e[H");
          	BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)
          }
  }
  printf("debug: end runBashPrint\n");
	bash_arg->run_bash=0;
  return NULL;
}

// 0 if filename it exists
int file_exists(char *filename){
  return access(filename, F_OK);
}
