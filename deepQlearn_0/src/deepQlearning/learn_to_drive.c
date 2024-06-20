#include "learn_to_drive.h"

char *action_name[8] = {"LEFT", "CENTER", "RIGHT"};

float reLU(float x){
  if(x>0) return x;
  return 0;
}

float d_reLU(float x){
  if (x>0) return 1;
  return 0;
}

float L2(float t, float o){
  return (o - t) * (o - t)/2;
}

float D_L2(float t, float o){
  return (o - t);
}

void copy_weight_in_networks_from_main_to_target(struct networks_qlearning * networks){
  copy_weight_in_neurons_TYPE_FLOAT(networks->target_net, networks->main_net);
}
void copy_weight_in_networks_from_main_to_best(struct networks_qlearning * networks){
  copy_weight_in_neurons_TYPE_FLOAT(networks->best_net, networks->main_net);
}

struct networks_qlearning * create_nework_qlearning(
  struct config_layers * config,
  bool randomize, float minR, float maxR,  int randomRange,
  size_t nb_prod_thread,
  size_t nb_calc_thread,
  float learning_rate
){
  struct networks_qlearning *qnets = malloc(sizeof(struct networks_qlearning));
  qnets->config = config;

  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->main_net), config, random, minR, maxR, randomRange);  
  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->target_net), config, false, minR, maxR, randomRange);  
  copy_weight_in_networks_from_main_to_target(qnets);
  
  setup_networks_alloutputs_config_TYPE_FLOAT(&(qnets->best_net), config, false, minR, maxR, randomRange);  
  copy_weight_in_networks_from_main_to_best(qnets);

  
  setup_all_layers_functions_TYPE_FLOAT(qnets->main_net, tensorContractnProdThread_TYPE_FLOAT, tensorProdThread_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  setup_all_layers_params_TYPE_FLOAT(qnets->main_net, nb_prod_thread, nb_calc_thread, learning_rate);
  setup_all_layers_functions_TYPE_FLOAT(qnets->target_net, tensorContractnProdThread_TYPE_FLOAT, tensorProdThread_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  setup_all_layers_params_TYPE_FLOAT(qnets->target_net, nb_prod_thread, nb_calc_thread, learning_rate);
  setup_all_layers_functions_TYPE_FLOAT(qnets->best_net, tensorContractnProdThread_TYPE_FLOAT, tensorProdThread_TYPE_FLOAT, D_L2, L2, reLU, d_reLU);
  setup_all_layers_params_TYPE_FLOAT(qnets->best_net, nb_prod_thread, nb_calc_thread, learning_rate);


  return qnets; 

}

struct status_qlearning * create_status_qlearning (){
  struct status_qlearning * status_ql = malloc(sizeof(struct status_qlearning));
  
  status_ql->list_main_cumul = create_var_list_TYPE_L_INT();
  status_ql->list_target_cumul = create_var_list_TYPE_L_INT();
  status_ql->progress_best_cumul = create_var_list_TYPE_L_INT();
 
  //push_back_list_TYPE_L_INT(status_ql->list_main_cumul, 0);
  //push_back_list_TYPE_L_INT(status_ql->list_target_cumul, 0);
  push_back_list_TYPE_L_INT(status_ql->progress_best_cumul, -10000);

  status_ql->nb_training_after_updated_weight_in_target = 0;

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
  pthread_mutex_init(&(pprint->mut_printed), NULL);

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

  qparams->gamma = gamma;
  qparams->learning_rate = learning_rate ;
  qparams->discount_factor = discount_factor ;
  qparams->exploration_factor = exploration_factor ;
  
  qparams->nb_training_before_update_weight_in_target = nb_training_before_update_weight_in_target;
  qparams->number_episodes = number_episodes;

  qparams->factor_update_learning_rate = 0.995;
  qparams->minimum_threshold_learning_rate = 0.0001 ;
  qparams->factor_update_exploration_factor = 0.995;
  qparams->minimum_threshold_exploration_factor = 0.01;


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

  return rlagent;
}

void free_networks_qlearning (struct networks_qlearning * networks){
  free_neurons_TYPE_FLOAT(networks->main_net);
  free_neurons_TYPE_FLOAT(networks->target_net);
  free_neurons_TYPE_FLOAT(networks->best_net);
  free_config_layers(networks->config);
  free(networks);
}
void free_status_qlearning(struct status_qlearning *status_ql){
  free_all_var_list_TYPE_L_INT(status_ql->list_main_cumul);
  free_all_var_list_TYPE_L_INT(status_ql->list_target_cumul);
  free_all_var_list_TYPE_L_INT(status_ql->progress_best_cumul);
  free(status_ql);
}
void free_delay_params (struct delay_params *dly_p){
  free(dly_p);
}

void free_print_params (struct print_params *pprint){
  pthread_mutex_destroy(&(pprint->mut_printed));
  free_delay_params(pprint->delay);
  free(pprint);

}

void free_qlearning_params(struct qlearning_params *q_params){
  free(q_params);
}
void free_RL_agent(struct RL_agent *rlAgent){
  free(rlAgent->qlearnParams);
  free_print_params(rlAgent->pprint);
  free_status_qlearning(rlAgent->status);
  free_networks_qlearning(rlAgent->networks);
  free_vehicle(rlAgent->car);

  free(rlAgent);
}

void train_qlearning(struct RL_agent * rlAgent, 
  int action  //, long reward
  ){
  tensor_TYPE_FLOAT * action_value = NULL;
  tensor_TYPE_FLOAT * next_action_value = NULL;
  neurons_TYPE_FLOAT * net_main = rlAgent->networks->main_net;
  neurons_TYPE_FLOAT * net_target = rlAgent->networks->target_net;
  tensor_TYPE_FLOAT * new_state = rlAgent->car->sensor /*input*/;
  tensor_TYPE_FLOAT * state = rlAgent->car->old_sensor  /*input*/;
  calculate_output_by_network_neurons_TYPE_FLOAT(net_main, state, &action_value);
  calculate_output_by_network_neurons_TYPE_FLOAT(net_target, new_state, &next_action_value);
  tensor_TYPE_FLOAT * experimental_values = CREATE_TENSOR_FROM_CPY_DIM_TYPE_FLOAT(action_value->dim);
  
  struct game_status * car_status = rlAgent->car->status;
  struct qlearning_params * qlParams = rlAgent->qlearnParams;
  copy_tensor_TYPE_FLOAT(experimental_values, action_value) ;
  // experimental_values === Q-tab learning
  if(car_status->done){
    experimental_values->x[action] = -100;    
  }else {
    experimental_values->x[action] = car_status->reward + rlAgent->qlearnParams->gamma * MAX_ARRAY_TYPE_FLOAT(next_action_value->x, next_action_value->dim->rank) ;    
  }
  float new_value = ( (net_main->learning_rate < qlParams->minimum_threshold_learning_rate /*0.0001*/) ? net_main->learning_rate :(net_main->learning_rate ) * qlParams->factor_update_learning_rate   /*0.995*/ );
  UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, net_main, learning_rate, new_value);

  qlParams->exploration_factor = (qlParams->exploration_factor < qlParams->minimum_threshold_exploration_factor) ? qlParams->exploration_factor : qlParams->exploration_factor * qlParams->factor_update_exploration_factor ;


}

int select_action(struct RL_agent * rlAgent){
  int action;
  tensor_TYPE_FLOAT * action_value = NULL;
  calculate_output_by_network_neurons_TYPE_FLOAT(rlAgent->networks->main_net, rlAgent->car->old_sensor, &action_value);
  long int NUMBER_EPISODE2 = (rlAgent->qlearnParams->number_episodes);
  NUMBER_EPISODE2 = NUMBER_EPISODE2 * NUMBER_EPISODE2;
  srand(time(NULL));
  int random = rand() % NUMBER_EPISODE2;
  float proba_explor = (float)random / NUMBER_EPISODE2;
  if(proba_explor <= rlAgent->qlearnParams->exploration_factor ){
    action = rand() % action_value->dim->rank ; 
  }
  else{
    action = ARG_MAX_ARRAY_TYPE_FLOAT( action_value->x, action_value->dim->rank  );
  }
  return action;
}

void learn_to_drive(struct RL_agent * rlAgent){
  int action;
  struct vehicle * car = rlAgent->car;
  struct game_status * car_status = car->status;
  struct qlearning_params * qlParams = rlAgent->qlearnParams;
  struct status_qlearning * qlStatus = rlAgent->status;
  struct print_params * pprint = rlAgent->pprint;
  char msg[100];

  while(true){
    for(size_t index_episode = 0; index_episode < qlParams->number_episodes; ++index_episode){
      reset(car);
      qlStatus->nb_training_after_updated_weight_in_target = 0;
      while(true){
        ++(qlStatus->nb_training_after_updated_weight_in_target);
        action = select_action(rlAgent);
        sprintf(msg," dir:%.0f : %s, ", car->direction ,action_name[action]);
        add_string_log_M(car_status,msg);
        step_vehicle(car, action);
        train_qlearning(rlAgent, action);
        if(pprint->printed){
          pthread_mutex_lock(&(pprint->mut_printed));
          print_vehicle_n_path(car, pprint->scale_x, pprint->scale_y);
          pthread_mutex_unlock(&(pprint->mut_printed));
          printf("%s ",pprint->string_space);
          printf("ep: %ld ",index_episode);
          neurons_TYPE_FLOAT * net_main = rlAgent->networks->main_net;
          for(size_t i=0; i<net_main->output->dim->rank; ++i) printf("{sensro[%s]:%f }",action_name[i%COUNT_ACTION],net_main->output->x[i]);
          Sleep(pprint->delay->delay_between_games);
        }
        //done in step ... copy_tensor_TYPE_FLOAT(car->old_sensor, car->sensor);
        if( qlStatus->nb_training_after_updated_weight_in_target > qlParams->nb_training_before_update_weight_in_target ){
          qlStatus->nb_training_after_updated_weight_in_target = 0;
          copy_weight_in_networks_from_main_to_target(rlAgent->networks);
        }
        if(car_status->done == true){
          //push_back_list_TYPE_L_INT(qlStatus->list_main_cumul, car_status->cumulative_reward);
          printf(" cumul : %ld ", car_status->cumulative_reward);
          if(car_status->cumulative_reward > qlStatus->progress_best_cumul->end_list->value){
            push_back_list_TYPE_L_INT(qlStatus->progress_best_cumul, car_status->cumulative_reward);
            FOR_LIST_FORM_BEGIN(TYPE_L_INT, qlStatus->progress_best_cumul){
              printf(" | %ld |,",(qlStatus->progress_best_cumul)->current_list->value);
            }
            printf("%s ",pprint->string_space);
          }
          break;
        }
      }

      if(pprint->printed){
        Sleep(pprint->delay->delay_between_episodes);
      }
    }
  }
}
