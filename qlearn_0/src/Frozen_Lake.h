#ifndef __RABBIT_LEARN__H_C_
#define __RABBIT_LEARN__H_C_

#include <time.h>
#include <unistd.h>

#include "tools_t/tools_t.h"
#include "dimension_t/dimension_t.h"
#include "list_t/list_t.h"

#define ACTION_COUNT 4
/* Down(0), Left(1), Right(2), Up(3) */
enum Action { DOWN, LEFT, RIGHT, UP };
//enum MoveAction { MOVE_DOWN = -2, MOVE_LEFT = -1, MOVE_RIGHT = 1, MOVE_UP = 2 };

#define CONTENT_COUNT 5 
/* Empty(0), Start(1), Carrot(2), Block(3), Fox(4) */
enum Content { EMPTY, START, CARROT, BLOCK, FOX };

enum Reward { REWARD_MOVES_OUT=-10, REWARD_OUT=-1, REWARD_EMPTY=-1, REWARD_CARROT=10, REWARD_BLOCK=-1, REWARD_FOX=-10 };

struct game_params {
  size_t limit_game_number;
  dimension *dim;
  long int *add_move;
  size_t limit_FOX_number;
  size_t limit_BLOCK_number;
  size_t limit_CARROT_number;
  size_t limit_EPISODES_number;
  size_t limit_MOVE_number;
};

struct delay_params {
  size_t delay_between_episodes;
  size_t delay_between_games;
};

struct game_status {
  long int startRankPosition;
  long int rabbitRankPosition;
  long int rabbitOldRankPosition;
  bool endGame;
  long int reward;
  long int final_reward;
  size_t count_MOVES;
};

struct qlearning_params {
  double learning_rate;
  double discount_factor;
  double exploration_factor;
};

struct cell {
  long int rankPosition;
  int content;
  double *Q;
};

struct game {
  struct game_params *params;
  struct delay_params *delay;
  struct qlearning_params *qlearnParams;
  struct cell *cells;
  struct game_status *status;
};

struct qlearning_params * create_qlearning_params(
  double learning_rate,
  double discount_factor,
  double exploration_factor
);

struct game_params * create_game_params (
  size_t limit_game_number,
  dimension *dim,
  size_t limit_FOX_number,
  size_t limit_BLOCK_number,
  size_t limit_CARROT_number,
  size_t limit_EPISODES_number,
  size_t limit_MOVE_number
);

struct delay_params * create_delay_params (
  size_t delay_episodes,
  size_t delay_game
);

struct game_status * create_game_status();

struct game * create_game(
  struct game_params *params,
  struct qlearning_params *qlearnParams,
  struct delay_params *delay
);

void reset_game(struct game *gm);
long int generate_game(struct game *gm);

void move_game(struct game *gm, enum Action action);

//void free_qlearning_params(struct qlearning_params * qlearn_params);
//void free_game_params(struct game_params *game_prms);
//void free_cells(struct cell * cells);
//void free_game_status(struct game_status *status);
void free_game(struct game *gm);


void mainQlearning_game(struct game *gm);



#endif /* __RABBIT_LEARN__H_C_  */
