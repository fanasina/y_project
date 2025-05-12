#include "ftest/ftest.h"
#include "fmock/fmock.h"


#include "Frozen_Lake.h"


TEST(igameRabbit ){
  size_t array[] = {4,4} ;
  dimension *dim = init_copy_dim(array,2);
  struct game_params * params = create_game_params(1,dim,3,3,1,200,200);
  struct qlearning_params * qlearnParams = create_qlearning_params(0.85,0.99,1);
  struct delay_params * delay_game = create_delay_params(100000, 20000);
  struct game * gm = create_game(params, qlearnParams, delay_game);

  printDebug_dimension(gm->params->dim,"dimension game");
  mainQlearning_game(gm);

  free_game(gm);
}



/*
TEST(ARG_MAX_ARRAY){

  double Q[6] = {0.5,-2.3,-9,3,21,-65};
  size_t mx = ARG_MAX_ARRAY_TYPE_DOUBLE(Q, 6) ;
  size_t mn = ARG_MIN_ARRAY_TYPE_DOUBLE(Q, 6) ;
  printf("mx = %ld, Q[%ld ] = %lf \n", mx,mx,Q[mx]);
  printf("mn = %ld, Q[%ld ] = %lf \n", mn,mn,Q[mn]);

  double a =-5;
  double b=4; 

  printf(" %lf vs %lf : %d \n ",a,b,COMPARE_N_TYPE_DOUBLE(&a,&b));
  printf(" %lf vs %lf : %d \n ",b,a,COMPARE_N_TYPE_DOUBLE(&b,&a));

}
*/

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
