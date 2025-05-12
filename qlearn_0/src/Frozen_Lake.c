
#include "Frozen_Lake.h"

char * action_name ="DLRU";
char * content_name ="ESCBF";

struct qlearning_params * create_qlearning_params(
  double learning_rate,
  double discount_factor,
  double exploration_factor
){
  struct qlearning_params * q_param = malloc(sizeof(struct qlearning_params));
  q_param->learning_rate = learning_rate;
  q_param->discount_factor = discount_factor;
  q_param->exploration_factor = exploration_factor;

return q_param;
}
struct game_params * create_game_params (
  size_t limit_game_number,
  dimension *dim,
  size_t limit_FOX_number,
  size_t limit_BLOCK_number,
  size_t limit_CARROT_number,
  size_t limit_EPISODES_number,
  size_t limit_MOVE_number
){
  struct game_params * gm_param = malloc(sizeof(struct game_params));
  gm_param->limit_game_number = limit_game_number;
  gm_param->dim = dim;
  gm_param->limit_FOX_number = limit_FOX_number;
  gm_param->limit_BLOCK_number = limit_BLOCK_number;
  gm_param->limit_CARROT_number = limit_CARROT_number;
  gm_param->limit_EPISODES_number = limit_EPISODES_number;
  gm_param->limit_MOVE_number = limit_MOVE_number;
  
  gm_param->add_move = malloc(ACTION_COUNT * sizeof(long int));
/*
  gm_param->add_move[DOWN] = signedLineFromCoord((long int []){0,-1}, dim);
  gm_param->add_move[LEFT] = signedLineFromCoord((long int []){-1,0}, dim);
  gm_param->add_move[RIGHT] = signedLineFromCoord((long int []){1,0}, dim);
  gm_param->add_move[UP] = signedLineFromCoord((long int []){0,1}, dim);
*/
  gm_param->add_move[DOWN] = dim->perm[0];
  gm_param->add_move[LEFT] = -1;
  gm_param->add_move[RIGHT] = 1;
  gm_param->add_move[UP] = -1*dim->perm[0];
  return gm_param;
}

struct cell * create_game_cells(dimension *dim){
  struct cell * cells = malloc((dim)->rank * sizeof(struct cell));
  for(long int i=0; i<(dim)->rank; ++i) 
    (cells[i]).Q = malloc(ACTION_COUNT * sizeof(double));

  return cells;
}

struct delay_params * create_delay_params (
  size_t delay_episodes,
  size_t delay_game
){
  struct delay_params *delay = malloc(sizeof(struct delay_params));
  delay->delay_between_episodes = delay_episodes;
  delay->delay_between_games = delay_game;
  return delay;
}

void reset_game_status(struct game_status * status){
  status->rabbitOldRankPosition = status->startRankPosition ;
  status->rabbitRankPosition = status->startRankPosition ;
  status->endGame = false;
  status->count_MOVES = 0;

  status->final_reward = 0;

}

struct game_status * create_game_status(){
  struct game_status *gm_stat = malloc(sizeof(struct game_status));
  reset_game_status(gm_stat);
  return gm_stat;
}

#define GENERATE_RANDOM_PLACES(CONTENT) \
  int CONTENT##_Number = xrand() % (params->limit_##CONTENT##_number) + 1;\
  for(int i=0; i< CONTENT##_Number; ++i) { \
    do{\
      random = xrand() % (dim->rank);\
    }while((gm->cells[random]).content != EMPTY);\
    (gm->cells[random]).content = CONTENT;\
  }

long int generate_game(struct game *gm){
  struct game_params *params = gm->params;
  struct game_status *status = gm->status;
  dimension *dim = params->dim;
  for(long int i=0; i<(params->dim)->rank; ++i){
    (gm->cells[i]).rankPosition = i;
    (gm->cells[i]).content = EMPTY; //0
    for(long int j=0; j < ACTION_COUNT; ++j)
      (gm->cells[i]).Q[j] = 0;
  }
  //srand(time(NULL));
  int random;
  GENERATE_RANDOM_PLACES(FOX)
  GENERATE_RANDOM_PLACES(CARROT)
  GENERATE_RANDOM_PLACES(BLOCK)
  do{
      random = xrand() % (dim->rank);
  }while((gm->cells[random]).content != EMPTY);
  (gm->cells[random]).content = START;
  
  (status)->startRankPosition = random;
  (status)->rabbitOldRankPosition = random;
  (status)->rabbitRankPosition = random;

  return (status->startRankPosition);
}

struct game * create_game(
  struct game_params *params,
  struct qlearning_params *qlearnParams,
  struct delay_params * delay
){
  struct game *gm = malloc(sizeof(struct game));
  gm->params = params;
  gm->qlearnParams = qlearnParams;
  gm->cells = create_game_cells(params->dim);
  gm->delay = delay; // create_delay_params(10000000, 2000000);
  gm->status = create_game_status();


  generate_game(gm);

  return gm; 
}


//void free_qlearning_params(struct qlearning_params * qlearn_params);
//void free_game_params(struct game_params *game_prms);
//void free_cells(struct cell * cells);
//void free_game_status(struct game_status *status);
void free_game(struct game *gm){
  for(long int i = 0; i < ((gm->params)->dim)->rank; ++i){
    free((gm->cells[i]).Q);
  }
  free(gm->cells);
  free_dimension((gm->params)->dim);
  free((gm->params)->add_move);
  free(gm->params);
  free(gm->qlearnParams);
  free(gm->delay);
  free(gm->status);
  free(gm);
}

long int function_add_move(struct game *gm, enum Action action){
  struct game_status * status = gm->status;
  dimension *dim = (gm->params)->dim;

  if(action == UP && (status->rabbitRankPosition / dim->perm[0]) == 0){
    return dim->rank * -1;
  }
  if(action == DOWN && (status->rabbitRankPosition / dim->perm[0]) == dim->perm[1]-1){
    return dim->rank ;
  }
  if(action == LEFT && (status->rabbitRankPosition % dim->perm[0]) == 0){
    return dim->rank * -1;
  }
  if(action == RIGHT && (status->rabbitRankPosition % dim->perm[0]) == dim->perm[1]-1){
    return dim->rank;
  }

  return (gm->params)->add_move[action];
  
}

void move_game(struct game *gm, enum Action action){
  struct game_params *params = gm->params;
  struct game_status *status = gm->status;
  struct cell * cells = gm->cells;
  
  ++(status->count_MOVES);
  long int newRankPosition = status->rabbitRankPosition + function_add_move(gm, action);

  if (newRankPosition < 0 || newRankPosition >= (params->dim)->rank) {
    status->reward = REWARD_OUT;
  }
  else if (status->count_MOVES > params->limit_MOVE_number) {
    status->rabbitRankPosition = newRankPosition;              
    status->endGame =  true;
    status->reward = REWARD_MOVES_OUT;
  }
  else if (cells[newRankPosition].content == BLOCK)   {
    status->reward = REWARD_BLOCK;
  }
  else if (cells[newRankPosition].content == FOX){ 
    status->rabbitRankPosition = newRankPosition;              
    status->endGame =  true;
    status->reward = REWARD_FOX; 
  }
  else if (cells[newRankPosition].content == CARROT) {               
    status->rabbitRankPosition = newRankPosition;              
    status->endGame = true;     
    status->reward = REWARD_CARROT; 
  }
  else { 
    status->rabbitRankPosition = newRankPosition;              
    status->reward = REWARD_EMPTY;                           
  }
}


void printLine(char c, int l, bool prec) {
    //printf("\033[00m");
    printf("\033[%d;0%dm", 0, 1); // noir // vide
    if (prec) printf("%*c\n", 10, ' ');
    for (int i = 0; i < l; i++)  printf("%c", c);
    printf("%*c||\n", 10, ' ');
}
void printLinec(char c, int l) {
    printLine(c, l, true);
}

void code2dCoul(dimension *color, enum Content content) {
  if( color && color->size > 1 ){
    if (content) {
        color->perm[0] = content + 31;  color->perm[1] = 1;
    }
    else {
        color->perm[0] = 0; color->perm[1] = 1;
    }
  }
}

#if 0
void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}
#endif

void print_game_dim2(struct game *gm) {
  struct cell *cells = gm->cells;
  dimension *dim = ((gm->params)->dim);
  
  if(dim->size == 2){
    dimension *coul = create_dim(2);
    long int *coord = malloc(2*sizeof(long int));
    int mult = dim->perm[0] * 14;
    char sep = '-';
    //gotoxy(0, 10);
    gotoxy(0, 0);
		
		printLinec('=',mult);
    for (long int j = 0; j < dim->perm[1]; j++) {
        for (long int i = 0; i < dim->perm[0]; i++) {
            long int cur = i + j * dim->perm[0];
            code2dCoul(coul, cells[cur].content);
            printf("\033[%ld;0%ldm", coul->perm[0], coul->perm[0]);
            //printf("s:%2d,(%d,%d),%2c|", cells[cur].rankPosition, cells[cur].pos.x, cells[cur].pos.y, cont_name[cells[cur].c]);
            printf("s:%2ld,(%ld,%ld),%2c|", cur, i , j , content_name[cells[cur].content]);
        }
				printf("%*c||", 10, ' ');
        printLinec(sep, mult);
        for (long int k = 0; k < ACTION_COUNT; k++) {
            for (long int i = 0; i < dim->perm[0]; i++) {
                long int cur = i + j * dim->perm[0];
                code2dCoul(coul, cells[cur].content);
                printf("\033[%ld;%ldm", coul->perm[0], coul->perm[1]);
                if ( (gm->status)->rabbitRankPosition == cur  ){ /*lapin_pos.x == i && lapin_pos.y == j */ 
                    //printf("\033[47;01m");
                    printf("\033[106m");
                }else{
                    printf("\033[49m");
								}
                printf("%2c: %8.4f |", action_name[k], cells[cur].Q[k]);
            }
            printf("%*c||\n", 10, ' ');
        }
        printLine(sep, mult, false);
    }
    free_dimension(coul);
    free(coord);
  }
}


void mainQlearning_game(struct game *gm){
  struct main_list_TYPE_L_INT * list_final_rewards = create_var_list_TYPE_L_INT();
  
  struct game_params *params = gm->params;
  struct game_status *status = gm->status;
  struct qlearning_params * qlearnParams = gm->qlearnParams;
  struct cell * cells = gm->cells;
  enum Action action;
  int random;
  long int NUMBER_EPISODE2 = (params->limit_EPISODES_number) * (params->limit_EPISODES_number);
  double proba_explor;
  srand(time(NULL));

  for(long int k=0 ; k < params->limit_game_number; ++k){
      generate_game(gm);
    for(long int episode = 0; episode < params->limit_EPISODES_number; ++episode){
      reset_game_status(status);

      while(!(status->endGame)){
        random = xrand() % NUMBER_EPISODE2;
        proba_explor = (double)random / NUMBER_EPISODE2;
        if( proba_explor < qlearnParams->exploration_factor * (1. / ((episode / 10 ) + 1))){ 
          action = xrand() % ACTION_COUNT;
          printf("exploration action ");
        }
        else{
          action = ARG_MAX_ARRAY_TYPE_DOUBLE( cells[status->rabbitRankPosition].Q, ACTION_COUNT  );
          printf("greedy action ");
        }
        
        status->rabbitOldRankPosition = status->rabbitRankPosition;
        move_game(gm, action);

  printf("ik=%ld, episode = %ld , action = %d rbPos = %ld, rwds = %ld, final_rwrd=%ld\n",k,episode,action, status->rabbitRankPosition,status->reward, status->final_reward);
        // update Q array on the action of the state
         cells[status->rabbitOldRankPosition].Q[action] =  cells[status->rabbitOldRankPosition].Q[action] + (qlearnParams->learning_rate * (status->reward + qlearnParams->discount_factor * MAX_ARRAY_TYPE_DOUBLE(cells[status->rabbitRankPosition].Q, ACTION_COUNT) -         cells[status->rabbitOldRankPosition].Q[action]));
         //cells[status->rabbitRankPosition].Q[action] =  cells[status->rabbitRankPosition].Q[action] + (qlearnParams->learning_rate * (status->reward + qlearnParams->discount_factor * MAX_ARRAY_TYPE_DOUBLE(cells[status->rabbitRankPosition].Q, ACTION_COUNT) -         cells[status->rabbitRankPosition].Q[action]));
        //cells[status->rabbitRankPosition].Q[action] =  (1 - qlearnParams->learning_rate) * cells[status->rabbitRankPosition].Q[action] + (qlearnParams->learning_rate * (status->reward + qlearnParams->discount_factor * MAX_ARRAY_TYPE_DOUBLE(cells[status->rabbitRankPosition].Q, ACTION_COUNT )));
         
        status->final_reward += status->reward;

        print_game_dim2(gm);
     		
			 //	getchar();	
        usleep((gm->delay)->delay_between_episodes);
        
      }
      push_back_list_TYPE_L_INT(list_final_rewards, status->final_reward);
    }
    
    FOR_LIST_FORM_BEGIN(TYPE_L_INT, list_final_rewards){
      printf(" %ld ",(list_final_rewards->current_list)->value);
    }
    remove_all_list_in_TYPE_L_INT(list_final_rewards);
    usleep((gm->delay)->delay_between_games);
  }
  free(list_final_rewards);
}
