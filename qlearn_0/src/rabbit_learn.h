#ifndef __RABBIT_LEARN__H_C_
#define __RABBIT_LEARN__H_C_

#include "dimension_t/dimension_t.h"
#include "list_t/list_t.h"

struct game_params {
  size_t num_episods;
  dimension *dim;
  size_t max_fox_number;
  size_t max_block_number;
  size_t max_carrot_number;
};

struct qlearning_params {
  double learning_rate;
  double discount_factor;
  double exploration_factor;

};

struct cell {
  long int rankPosition;
  int state;
  double *Q;
};

struct action {
  int value;
  int addMove;
};

struct states * create_states(dimension *dim);
void free_states(struct states *etat);


#endif /* __RABBIT_LEARN__H_C_  */
