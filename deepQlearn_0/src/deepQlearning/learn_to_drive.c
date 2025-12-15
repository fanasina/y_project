#include "learn_to_drive.h"

char *action_name[8] = {"LEFT", "CENTER", "RIGHT"};

#define UPPER_THRESHOLD 10
#define DIVIDER__  1
#define USE_THRESHOLD 0

float reLU(float x){
#if CHECK_NAN
  if(x!=x){// nan
    printf("nan relu ");
  }
#endif
#if USE_THRESHOLD
  if(x>UPPER_THRESHOLD) return UPPER_THRESHOLD;
#endif
  if(x>0) return x/DIVIDER__;
  return 0;
}

float d_reLU(float x){
#if USE_THRESHOLD
  if (x>UPPER_THRESHOLD) return 0;
#endif
  if (x>0) return 1/DIVIDER__;
  return 0;
}

float L2(float t, float o){
  return (o - t) * (o - t)/2;
}

float D_L2(float t, float o){
  return (o - t);
}

void copy_weight_in_networks_from_main_to_target(struct networks_qlearning * networks){
  //copy_weight_in_neurons_TYPE_FLOAT(networks->target_net, networks->main_net);
   COPY_NN_ATTRIBUTE_IN_ALL_LAYERS(TYPE_FLOAT,weight_in, networks->target_net, networks->main_net);
}
void copy_weight_in_networks_from_main_to_best(struct networks_qlearning * networks){
  //copy_weight_in_neurons_TYPE_FLOAT(networks->best_net, networks->main_net);
   COPY_NN_ATTRIBUTE_IN_ALL_LAYERS(TYPE_FLOAT,weight_in, networks->best_net, networks->main_net);
}

float id(float x){ return x;}

float constOne(float x){return 1;}

void tensorProdTHR_TYPE_FLOAT(tensor_TYPE_FLOAT **MM, tensor_TYPE_FLOAT *M0, tensor_TYPE_FLOAT *M1, size_t nbthread){
  return tensorProd_TYPE_FLOAT(MM,M0,M1);
}


void tensorContractnProdTHR_TYPE_FLOAT(tensor_TYPE_FLOAT **MM, tensor_TYPE_FLOAT *M0, tensor_TYPE_FLOAT *M1, size_t contractionNumber, size_t nbthread) {
  return tensorContractnProd_TYPE_FLOAT(MM,M0,M1,contractionNumber);
}

struct networks_qlearning * create_network_qlearning(
  struct config_layers * config,
  bool randomize, float minR, float maxR,  int randomRange,
  size_t nb_prod_thread,
  size_t nb_calc_thread,
  float learning_rate
){
  struct networks_qlearning *qnets = malloc(sizeof(struct networks_qlearning));
  qnets->config = config;

  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->main_net), config, randomize, minR, maxR, randomRange);  
  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->target_net), config, false, minR, maxR, randomRange);  
  copy_weight_in_networks_from_main_to_target(qnets);
  
  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->best_net), config, false, minR, maxR, randomRange);  
  copy_weight_in_networks_from_main_to_best(qnets);

  setup_all_layers_functions_TYPE_FLOAT(qnets->main_net, tensorContractnProdThread_TYPE_FLOAT, tensorProdThread_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  //setup_all_layers_functions_TYPE_FLOAT(qnets->main_net, tensorContractnProdTHR_TYPE_FLOAT, tensorProdTHR_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  setup_all_layers_params_TYPE_FLOAT(qnets->main_net, nb_prod_thread, nb_calc_thread, learning_rate);
  setup_all_layers_functions_TYPE_FLOAT(qnets->target_net, tensorContractnProdThread_TYPE_FLOAT, tensorProdThread_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  //setup_all_layers_functions_TYPE_FLOAT(qnets->target_net, tensorContractnProdTHR_TYPE_FLOAT, tensorProdTHR_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  setup_all_layers_params_TYPE_FLOAT(qnets->target_net, nb_prod_thread, nb_calc_thread, learning_rate);
  setup_all_layers_functions_TYPE_FLOAT(qnets->best_net, tensorContractnProdThread_TYPE_FLOAT, tensorProdThread_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  //setup_all_layers_functions_TYPE_FLOAT(qnets->best_net, tensorContractnProdTHR_TYPE_FLOAT, tensorProdTHR_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  setup_all_layers_params_TYPE_FLOAT(qnets->best_net, nb_prod_thread, nb_calc_thread, learning_rate);

// ne pas mettre fonction d'activation à la sortie , i.e: fonction identité : f(x) = x:
  neurons_TYPE_FLOAT *tmpMain = qnets->main_net;
  neurons_TYPE_FLOAT *tmpTarget = qnets->target_net;
  neurons_TYPE_FLOAT *tmpBest = qnets->best_net;
  while(tmpMain){
    if(tmpMain->next_layer == NULL){
      tmpMain->f_act = id_TYPE_FLOAT;//id;
      tmpMain->d_f_act = d_id_TYPE_FLOAT; //constOne;
      tmpTarget->f_act = id_TYPE_FLOAT;//id;
      tmpTarget->d_f_act = d_id_TYPE_FLOAT;//constOne;
      tmpBest->f_act = id_TYPE_FLOAT;//id;
      tmpBest->d_f_act = d_id_TYPE_FLOAT;// constOne;
    }
    tmpMain = tmpMain->next_layer;
    tmpTarget= tmpTarget->next_layer;
    tmpBest = tmpBest->next_layer;
  }

	qnets->thread_learn = NULL;
  
	for(int i=0;i<COUNT_ACTION;++i){
		qnets->nb_successive_action[i]=0;
	}

  return qnets; 

}

struct status_qlearning * create_status_qlearning (){
  struct status_qlearning * status_ql = malloc(sizeof(struct status_qlearning));
  
  status_ql->list_main_cumul = create_var_list_TYPE_L_INT();
  status_ql->list_target_cumul = create_var_list_TYPE_L_INT();
  status_ql->progress_best_cumul = create_var_list_TYPE_L_INT();

	status_ql->ending = 0;
	status_ql->mut_ending=malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(status_ql->mut_ending, NULL);

  //push_back_list_TYPE_L_INT(status_ql->list_main_cumul, 0);
  //push_back_list_TYPE_L_INT(status_ql->list_target_cumul, 0);
  push_back_list_TYPE_L_INT(status_ql->progress_best_cumul, -10000);

  status_ql->nb_training_after_updated_weight_in_target = 0;

  status_ql->nb_episodes = 0;
  status_ql->index_episode= 0;
  status_ql->action=1;

//  status_ql->last_action=-1;
//  status_ql->count_last_action=0;
  
  return status_ql;
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

struct print_params * create_print_params(float scale_x, float scale_y,  struct delay_params * delay){
  struct print_params * pprint = malloc(sizeof(struct print_params));
  pprint->printed = true;
  pprint->scale_x = scale_x;
  pprint->scale_y = scale_y;
  pprint->delay = delay;
  pprint->string_space = malloc(LOG_LENTH+1);
  pthread_mutex_init(&(pprint->mut_printed), NULL);
  pprint->go_on = 1;

  int i;
  for( i=0; i<LOG_LENTH; ++i)  
    pprint->string_space[i]=' ';
  pprint->string_space[i]='\0';

  return pprint;
}

struct qlearning_params * create_qlearning_params  (
  float gamma,
  float learning_rate,
  float discount_factor,
  float exploration_factor,
  long int nb_training_before_update_weight_in_target,
  size_t number_episodes
){
  struct qlearning_params * qparams = malloc(sizeof(struct qlearning_params));

  qparams->gamma = gamma; /* taux d'actualisation (discount rate): default : 0.95  */
  qparams->learning_rate = learning_rate ; /* default : 0.001 */
  qparams->discount_factor = discount_factor ; /* */
  qparams->exploration_factor = exploration_factor ;
  
  qparams->nb_training_before_update_weight_in_target = nb_training_before_update_weight_in_target;
  qparams->number_episodes = number_episodes;

  qparams->factor_update_learning_rate = 0.995;
  qparams->minimum_threshold_learning_rate = 0.00001 ;
  qparams->factor_update_exploration_factor = 0.995 /*0.995*/;
  qparams->minimum_threshold_exploration_factor = 0.0001;

//  qparams->threshold_number_same_action = 500;
  qparams->caller_func_name=NULL;

  return qparams;
}

struct RL_agent * create_RL_agent (
  struct networks_qlearning * networks,
  struct vehicle * car,
  struct status_qlearning * status,
  struct print_params * pprint, 
  struct qlearning_params *qlearnParams
){
  struct RL_agent * rlagent = malloc(sizeof(struct RL_agent));

  rlagent->networks = networks ;
  rlagent->car = car ;
  rlagent->status = status ;
  rlagent->pprint = pprint ;
  rlagent->qlearnParams = qlearnParams ;

	rlagent->networks->thread_learn=malloc(sizeof(pthread_t));
	pthread_create(rlagent->networks->thread_learn, NULL, learn_to_drive, (void*)rlagent);
		
  return rlagent;
}

void free_networks_qlearning (struct networks_qlearning * networks){
  free_neurons_TYPE_FLOAT(networks->main_net);
  free_neurons_TYPE_FLOAT(networks->target_net);
  free_neurons_TYPE_FLOAT(networks->best_net);
  free_config_layers(networks->config);
	if(networks->thread_learn){
		pthread_join(*(networks->thread_learn), NULL);
		free(networks->thread_learn);
	}
  free(networks);
}
void free_status_qlearning(struct status_qlearning *status_ql){
  free_all_var_list_TYPE_L_INT(status_ql->list_main_cumul);
  free_all_var_list_TYPE_L_INT(status_ql->list_target_cumul);
  free_all_var_list_TYPE_L_INT(status_ql->progress_best_cumul);
	pthread_mutex_destroy(status_ql->mut_ending);
	free(status_ql->mut_ending);
  free(status_ql);
}
void free_delay_params (struct delay_params *dly_p){
  free(dly_p);
}

int check_go_on_print_params(struct print_params *pprint){
  int ret=0;
  pthread_mutex_lock(&(pprint->mut_printed));
  ret=pprint->go_on;
  pthread_mutex_unlock(&(pprint->mut_printed));

  return ret;
}

void free_print_params (struct print_params *pprint){
  free(pprint->string_space);
  pthread_mutex_destroy(&(pprint->mut_printed));
  free_delay_params(pprint->delay);
  free(pprint);

}

void free_qlearning_params(struct qlearning_params *q_params){
  if(q_params->caller_func_name!=NULL) {
    free(q_params->caller_func_name);
  }
  free(q_params);
}
void free_RL_agent(struct RL_agent *rlAgent){
  free_qlearning_params(rlAgent->qlearnParams);
  free_print_params(rlAgent->pprint);
  free_status_qlearning(rlAgent->status);
  free_networks_qlearning(rlAgent->networks);
  free_vehicle(rlAgent->car);

  free(rlAgent);
}

#define ACCEPTABLE_REWARD 1000

#define UPDATE_PARAMS 1
#define UPDATE_EXPLOR_FAC 1

void train_qlearning(struct RL_agent * rlAgent, 
  int action  //, long reward
  ){
  tensor_TYPE_FLOAT * action_value = NULL;
  tensor_TYPE_FLOAT * next_action_value = NULL;
  neurons_TYPE_FLOAT * net_main = rlAgent->networks->main_net;
  neurons_TYPE_FLOAT * net_target = rlAgent->networks->target_net;
  tensor_TYPE_FLOAT * new_state = rlAgent->car->sensor /*input*/;
  tensor_TYPE_FLOAT * state = rlAgent->car->old_sensor  /*input*/;
  neurons_TYPE_FLOAT *ttmp = calculate_output_by_network_neurons_TYPE_FLOAT(net_main, state, &action_value);
  calculate_output_by_network_neurons_TYPE_FLOAT(net_target, new_state, &next_action_value);
  tensor_TYPE_FLOAT * experimental_values = CREATE_TENSOR_FROM_CPY_DIM_TYPE_FLOAT(action_value->dim);
  
     // print_neurons_msg_TYPE_FLOAT(net_main, " net_main "); getchar();
  struct game_status * car_status = rlAgent->car->status;
#if UPDATE_PARAMS
  struct qlearning_params * qlParams = rlAgent->qlearnParams;
#endif
  copy_tensor_TYPE_FLOAT(experimental_values, action_value) ;
  //copy_tensor_TYPE_FLOAT(experimental_values, next_action_value) ;
  // experimental_values === Q-tab learning
  if(car_status->done){
    experimental_values->x[action] = -100;    
  }else {
    experimental_values->x[action] = car_status->reward + rlAgent->qlearnParams->gamma * MAX_ARRAY_TYPE_FLOAT(next_action_value->x, next_action_value->dim->rank) ;    
  }
// ***
      copy_tensor_TYPE_FLOAT(ttmp->target, experimental_values);
      while(ttmp != net_main){
        calc_delta_neurons_TYPE_FLOAT(ttmp);
        //update_weight_neurons_TYPE_FLOAT(ttmp);
        ttmp = ttmp->prev_layer;
      }
      ttmp=net_main->next_layer; 
      while(ttmp){
        update_weight_neurons_TYPE_FLOAT(ttmp);
        ttmp = ttmp->next_layer;
      }
// ***
#if UPDATE_PARAMS
	if((car_status->cumulative_reward > ACCEPTABLE_REWARD) || (rlAgent->status->nb_episodes % 100 == 0) ){ 
  	float new_value = ( (net_main->learning_rate < qlParams->minimum_threshold_learning_rate /*0.0001*/) ? net_main->learning_rate :(net_main->learning_rate ) * qlParams->factor_update_learning_rate   /*0.995*/ );
  	UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, net_main, learning_rate, new_value);
    qlParams->learning_rate = new_value;
#if UPDATE_EXPLOR_FAC
  	qlParams->exploration_factor = (qlParams->exploration_factor < qlParams->minimum_threshold_exploration_factor) ? qlParams->exploration_factor : qlParams->exploration_factor * qlParams->factor_update_exploration_factor ;
#endif
	}
#endif
//  free_tensor_TYPE_FLOAT(action_value);
//  free_tensor_TYPE_FLOAT(next_action_value);
  free_tensor_TYPE_FLOAT(experimental_values);

}
#define SUCCESSIVE_ACTION_CHECK 1

#define MAX_SUCCESSIVE_ACTION 1000
int select_action(struct RL_agent * rlAgent){
  //static size_t explore = 0;
  int action;
  tensor_TYPE_FLOAT * action_value = NULL;
  //calculate_output_by_network_neurons_TYPE_FLOAT(rlAgent->networks->main_net, rlAgent->car->old_sensor, &action_value);
  calculate_output_by_network_neurons_TYPE_FLOAT(rlAgent->networks->main_net, rlAgent->car->sensor, &action_value);
  //long int NUMBER_EPISODE2 = (rlAgent->qlearnParams->number_episodes)*100;
  //int randRange = 10000;
  //NUMBER_EPISODE2 = NUMBER_EPISODE2 * NUMBER_EPISODE2;
  //static bool init = true ;
  //if(init){
    //srand(time(NULL));
    //init =false;
  //}
  //int random = xrand() % randRange;
  float proba_explor =  (float) (xrand() % ((1<<17) -1))/ ((1<<17) -1); //frand(); //(float)(random ) / randRange;
  if(proba_explor > rlAgent->qlearnParams->exploration_factor ){
    action = ARG_MAX_ARRAY_TYPE_FLOAT( action_value->x, action_value->dim->rank  );
    //printf(" STRATEGY : action : %d , factor : %f nb_episodes : %ld \n",action,rlAgent->qlearnParams->exploration_factor, rlAgent->status->nb_episodes);
#if SUCCESSIVE_ACTION_CHECK
  if(rlAgent->networks->nb_successive_action[action]>MAX_SUCCESSIVE_ACTION){
			rlAgent->networks->nb_successive_action[action]=0;
			int recAction=action;
			while(action==recAction){
    		action = xrand() % action_value->dim->rank ; 
				//printf("debug: action=%d recAction=%d\n",action, recAction);
			}
      struct qlearning_params * qlParams = rlAgent->qlearnParams;
		  write(1,"#",1);
      qlParams->exploration_factor = (qlParams->exploration_factor < 1 ) ? (qlParams->exploration_factor / qlParams->factor_update_exploration_factor)*5 :  qlParams->exploration_factor  ;
		}
#endif
		////else write(1,".",1);
    //if(action == ARG_MIN_ARRAY_TYPE_FLOAT( action_value->x, action_value->dim->rank  )) 
      //action = xrand() % action_value->dim->rank ; 
  }
  else{
    action = xrand() % action_value->dim->rank ; 
   // explore++;
    //printf(" EXPLORE :%ld, action : %d , factor : %f nb_episodes : %ld \n",explore,action,rlAgent->qlearnParams->exploration_factor, rlAgent->status->nb_episodes);
    //printf(" EXPLORE : action : %d , factor : %f nb_episodes : %ld \n",action,rlAgent->qlearnParams->exploration_factor, rlAgent->status->nb_episodes);
		////write(1,"*",1);
  }
#if SUCCESSIVE_ACTION_CHECK
	for(int a=0;a<COUNT_ACTION;++a){
		if(a!=action)
			rlAgent->networks->nb_successive_action[a]=0;
	}
	(rlAgent->networks->nb_successive_action[action])++;
#endif 
  /*
    if(rlAgent->status->last_action == action){
      ++(rlAgent->status->count_last_action);
      if(rlAgent->status->count_last_action > rlAgent->qlearnParams->threshold_number_same_action  ){
        while(rlAgent->status->last_action == action) 
          action = xrand() % action_value->dim->rank ;
        
        rlAgent->status->last_action = action;
        rlAgent->status->count_last_action = 0;
      }
    }
    else{
      rlAgent->status->last_action = action;
      rlAgent->status->count_last_action = 0;
    }
    */
  rlAgent->status->action = action;
  return action;
}

int is_ending(struct status_qlearning *qlStatus){
	int ret;
  pthread_mutex_lock(qlStatus->mut_ending);
	ret = qlStatus->ending;
  pthread_mutex_unlock(qlStatus->mut_ending);
	return ret;
}

void* runPrint(void *arg){
  struct RL_agent *rlAgent = (struct RL_agent*)arg;
  struct status_qlearning *qlStatus = rlAgent->status;
  struct print_params * pprint = rlAgent->pprint;
  struct vehicle *car = rlAgent->car;
  size_t count_print = 0;
  while(!is_ending(qlStatus)){
if(/*(qlStatus->nb_episodes %125 == 0)  &&*/  pprint->printed){
          //pthread_mutex_lock(&(pprint->mut_printed));
          pthread_mutex_lock(&(car->mut_coord));
          print_vehicle_n_path(car, pprint->scale_x, pprint->scale_y);
          pthread_mutex_unlock(&(car->mut_coord));
          //pthread_mutex_unlock(&(pprint->mut_printed));
          printf("%s ",pprint->string_space);
          printf("ep: %ld\n",qlStatus->index_episode);
          neurons_TYPE_FLOAT * net_main = rlAgent->networks->main_net;
          neurons_TYPE_FLOAT * net_target = rlAgent->networks->target_net;
          for(size_t i=0; i<net_main->output->dim->rank; ++i) {
            printf("{sensro[%s]:%f "" vs oldsens[%s]: %f}\n",action_name[i%COUNT_ACTION],net_target->output->x[i], 
            action_name[i%COUNT_ACTION],net_main->output->x[i]);
            
          }
          printf("\n< %5.2f > ( %s  ) \n", car->direction, action_name[qlStatus->action % COUNT_ACTION]);
          //print_weight_in_neurons_TYPE_FLOAT(net_main, "net_main_wei");
          //PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_main, weight_in, "net_main_we_in");
          ///PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_main, output, "net_main_out");
          //PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_target, output, "net_target_out");
          //PRINT_ATTRIBUTE_TENS_IN_ALL_LAYERS(TYPE_FLOAT, net_main, input, "net_main_input");
          printf(" action : %d , factor : %f nb_episodes : %ld \n",qlStatus->action,rlAgent->qlearnParams->exploration_factor, rlAgent->status->nb_episodes);
        
          FOR_LIST_FORM_BEGIN(TYPE_L_INT, qlStatus->progress_best_cumul){
             printf(" | %ld |,",(qlStatus->progress_best_cumul)->current_list->value);
          }
          printf("[%ld] %s ", rlAgent->car->status->cumulative_reward, pprint->string_space);

        }
          Sleep(pprint->delay->delay_between_games);
          ++count_print;
          if(count_print > 20){
            count_print = 0;
            clear_screen();
          }
  }
	return NULL;
}

char *fileNameDateScore(char * pre, char* post,size_t score){
  char *filename=malloc(256);
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(filename,"%s%d%02d%02d_%02dh%02dm%02ds_%ld%s",pre, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,score,post);

  return filename;
}

//const char* target_symlink = ".ff_target_.symlink";
//const char* main_symlink = ".ff_main_.symlink";
const char* dest_folder=".ff_learnDir";

void* learn_to_drive(void * lrnarg){
	struct RL_agent *rlAgent = (struct RL_agent *)lrnarg;
  printf("debug: start learn_to_drive\n");
  int action;
  struct vehicle * car = rlAgent->car;
  struct game_status * car_status = car->status;
  struct qlearning_params * qlParams = rlAgent->qlearnParams;
  struct status_qlearning * qlStatus = rlAgent->status;
  //struct print_params * pprint = rlAgent->pprint;
  char msg[100];

	if(mkdir(dest_folder, 0700)==-1){
		if(errno != EEXIST){
			perror(" create folder dst\n");
		}
	}
	else{
		printf("debug: %s successfully created\n",dest_folder);
	}

	////pthread_t threadPrint;
  ////pthread_create(&threadPrint, NULL, runPrint, (void*)rlAgent);
  
 // while(true){
    for(size_t index_episode = 0; 
      (!is_ending(qlStatus)) 
      //|| (car_status->cumulative_reward > 2 * ACCEPTABLE_REWARD) 
      //|| (index_episode < qlParams->number_episodes) 
      ; 
      ++index_episode){
      reset(car);
      qlStatus->nb_training_after_updated_weight_in_target = 0;
      qlStatus->index_episode = index_episode;
      while(!is_ending(qlStatus) /*true*/){
        ++(qlStatus->nb_episodes);
        ++(qlStatus->nb_training_after_updated_weight_in_target);
        action = select_action(rlAgent);
        sprintf(msg," dir:%.0f : %s, ", car->direction ,action_name[action]);
        add_string_log_M(car_status,msg);
        step_vehicle(car, action);
        train_qlearning(rlAgent, action);
                //done in step ... copy_tensor_TYPE_FLOAT(car->old_sensor, car->sensor);
        if( qlStatus->nb_training_after_updated_weight_in_target > qlParams->nb_training_before_update_weight_in_target ){
          qlStatus->nb_training_after_updated_weight_in_target = 0;
          copy_weight_in_networks_from_main_to_target(rlAgent->networks);
        }
        if(car_status->done == true){
          //push_back_list_TYPE_L_INT(qlStatus->list_main_cumul, car_status->cumulative_reward);
          // printf(" cumul : %ld ", car_status->cumulative_reward);
          if(car_status->cumulative_reward > qlStatus->progress_best_cumul->end_list->value){
          	int len_cumul=0;
						char cumulSTR[128];
						len_cumul=sprintf(cumulSTR, " %ld ", car_status->cumulative_reward);
            char *mainfuncCaller=malloc(128);
            char *targetfuncCaller=malloc(128);
            char *mainSymlinkCaller=malloc(256);
            char *targetSymlinkCaller=malloc(256);
            if(qlParams->caller_func_name){
              sprintf(mainfuncCaller,".ff_learnDir/.ff_main_%s",qlParams->caller_func_name);
              sprintf(targetfuncCaller,".ff_learnDir/.ff_target_%s",qlParams->caller_func_name);
              sprintf(mainSymlinkCaller,".ff_main_%s.symlink",qlParams->caller_func_name);
              sprintf(targetSymlinkCaller,".ff_target_%s.symlink",qlParams->caller_func_name);
            }else{
              strcpy(mainfuncCaller,".ff_learnDir/.ff_main_");
              strcpy(targetfuncCaller,".ff_learnDir/.ff_target_");
              strcpy(mainSymlinkCaller,".ff_main_.symlink");
              strcpy(targetSymlinkCaller,".ff_target_.symlink");

            }
            push_back_list_TYPE_L_INT(qlStatus->progress_best_cumul, car_status->cumulative_reward);
            //char *file = fileNameDateScore(".ff_learnDir/.ff_main_",".txt",car_status->cumulative_reward);
            char *file = fileNameDateScore(mainfuncCaller,"",car_status->cumulative_reward);
            EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, rlAgent->networks->main_net ,weight_in, file);
              
           
            //unlink(main_symlink);
            unlink(mainSymlinkCaller);
            //if(symlink(file, main_symlink)==-1)
            if(symlink(file, mainSymlinkCaller)==-1)
            {
              //fprintf(stderr,"debug: symlink %s with %s.\n",main_symlink, file);
              fprintf(stderr,"debug: symlink %s with %s.\n",mainSymlinkCaller, file);
              //fprintf(stderr,"debug: symlink %s with %s. explain:%s \n",main_symlink, file, explain_symlink(file, main_symlink) );
            }
            else write(1,":",1);
            write(1,cumulSTR,len_cumul);
            free(file);
            //file = fileNameDateScore(".ff_learnDir/.ff_target_",".txt",car_status->cumulative_reward);
            file = fileNameDateScore(targetfuncCaller,"",car_status->cumulative_reward);
            EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, rlAgent->networks->target_net ,weight_in, file);
            //unlink(target_symlink);
            //if(symlink(file, target_symlink)==-1)
            unlink(targetSymlinkCaller);
            if(symlink(file, targetSymlinkCaller)==-1)
            {
              //fprintf(stderr,"debug: symlink %s with %s\n",target_symlink,file );
              fprintf(stderr,"debug: symlink %s with %s\n",targetSymlinkCaller,file );
              //fprintf(stderr,"debug: symlink %s with %s explain:%s\n",target_symlink,file,explain_symlink(file, target_symlink) );
            }
            else write(1,"-",1);
            free(file);
            free(mainfuncCaller);
            free(targetfuncCaller);
            free(mainSymlinkCaller);
            free(targetSymlinkCaller);
          }
          break;
        }
      }

      //if(pprint->printed){
      //  Sleep(pprint->delay->delay_between_episodes);
      //}
    }
// UPDATE IF ENDING AND BETTER REWARD

          if(car_status->cumulative_reward > qlStatus->progress_best_cumul->end_list->value)
          {
          	int len_cumul=0;
						char cumulSTR[128];
						len_cumul=sprintf(cumulSTR, " %ld ", car_status->cumulative_reward);
            char *funcCaller_extension=malloc(128);
            char *mainSymlinkCaller=malloc(256);
            char *targetSymlinkCaller=malloc(256);
            if(qlParams->caller_func_name){
              sprintf(funcCaller_extension,"%s.txt",qlParams->caller_func_name);
              sprintf(mainSymlinkCaller,".ff_main_%s.symlink",qlParams->caller_func_name);
              sprintf(targetSymlinkCaller,".ff_target_%s.symlink",qlParams->caller_func_name);
            }else{
              sprintf(funcCaller_extension,".%s","txt");
              strcpy(mainSymlinkCaller,".ff_main_.symlink");
              strcpy(targetSymlinkCaller,".ff_target_.symlink");

            }
            push_back_list_TYPE_L_INT(qlStatus->progress_best_cumul, car_status->cumulative_reward);
            //char *file = fileNameDateScore(".ff_learnDir/.ff_main_",".txt",car_status->cumulative_reward);
            char *file = fileNameDateScore(".ff_learnDir/.ff_main_",funcCaller_extension,car_status->cumulative_reward);
            EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, rlAgent->networks->main_net ,weight_in, file);
              
           
            //unlink(main_symlink);
            unlink(mainSymlinkCaller);
            //if(symlink(file, main_symlink)==-1)
            if(symlink(file, mainSymlinkCaller)==-1)
            {
              //fprintf(stderr,"debug: symlink %s with %s.\n",main_symlink, file);
              fprintf(stderr,"debug: symlink %s with %s.\n",mainSymlinkCaller, file);
              //fprintf(stderr,"debug: symlink %s with %s. explain:%s \n",main_symlink, file, explain_symlink(file, main_symlink) );
            }
            else write(1,":",1);
            write(1,cumulSTR,len_cumul);
            free(file);
            //file = fileNameDateScore(".ff_learnDir/.ff_target_",".txt",car_status->cumulative_reward);
            file = fileNameDateScore(".ff_learnDir/.ff_target_",funcCaller_extension,car_status->cumulative_reward);
            EXPORT_TO_FILE_TENSOR_ATTRIBUTE_IN_NNEURONS(TYPE_FLOAT, rlAgent->networks->target_net ,weight_in, file);
            //unlink(target_symlink);
            //if(symlink(file, target_symlink)==-1)
            unlink(targetSymlinkCaller);
            if(symlink(file, targetSymlinkCaller)==-1)
            {
              //fprintf(stderr,"debug: symlink %s with %s\n",target_symlink,file );
              fprintf(stderr,"debug: symlink %s with %s\n",targetSymlinkCaller,file );
              //fprintf(stderr,"debug: symlink %s with %s explain:%s\n",target_symlink,file,explain_symlink(file, target_symlink) );
            }
            else write(1,"-",1);
            free(file);
            free(funcCaller_extension);
            free(mainSymlinkCaller);
            free(targetSymlinkCaller);
          }

// END UPDATE


			pthread_mutex_lock(qlStatus->mut_ending);
			qlStatus->ending = 1;
			pthread_mutex_unlock(qlStatus->mut_ending);
//  }

  ////pthread_join(threadPrint, NULL);
	printf("debug: end learn\n");
	return NULL;
}

