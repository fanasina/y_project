#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

// for sleep !
/*
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif
*/

#include "ftest/ftest.h"
#include "ftest/ftest_array.h"
#include "fmock/fmock.h"


//#include "permutation_t/permutation_t.h"
#include "neuron_t/neuron_t.h"

#include "vehicle.h"
#include "learn_to_drive.h"

TEST(create_coordenate){
  coordinate * coord = create_coordinate(3);
  coord->x[0]=0;
  coord->x[1]=1.2;
  coord->x[0]=0.8;

  free_coordinate(coord);
}

TEST(create_blocks){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * zn = create_blocks(nb_block, dim);

  for(size_t i=0; i<nb_block; ++i){
    for(size_t j=0; j<dim; ++j){
      zn->lower_bound_block[i]->x[j] = 0;
      zn->upper_bound_block[i]->x[j] = (i+1)*(j+1);
    }
  }

  
  for(size_t i=0; i<nb_block; ++i){
    LOG("%s"," || (");
    for(size_t j=0; j<dim; ++j)
      LOG(" %f ", zn->lower_bound_block[i]->x[j]);
    LOG("%s",")\\ (");
    for(size_t j=0; j<dim; ++j)
      LOG(" %f ", zn->upper_bound_block[i]->x[j]);
    LOG("%s",")");
 
 }
    LOG("\n");
  
  free_blocks(zn);

}

TEST(is_in_blocks){
  size_t nb_block = 3;
  size_t dim= 2;
  struct blocks * zn = create_blocks(nb_block, dim);
  
  copy_coordinate(zn->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(zn->upper_bound_block[0], (float[]){2,2});
  copy_coordinate(zn->lower_bound_block[1], (float[]){2,0});
  copy_coordinate(zn->upper_bound_block[1], (float[]){4,4});
  copy_coordinate(zn->lower_bound_block[2], (float[]){0,4});
  copy_coordinate(zn->upper_bound_block[2], (float[]){6,7});
  
  coordinate *coord = create_coordinate(2);

  copy_coordinate(coord, (float[]){1,1});
  EXPECT_TRUE(is_in_blocks(zn, coord));
  
  copy_coordinate(coord, (float[]){1,5});
  EXPECT_TRUE(is_in_blocks(zn, coord));
  
  copy_coordinate(coord, (float[]){3,3});
  EXPECT_TRUE(is_in_blocks(zn, coord));
  
  copy_coordinate(coord, (float[]){1,3});
  EXPECT_FALSE(is_in_blocks(zn, coord));

  print2D_blocks(zn,0.4,0.6, '.');


  free_blocks(zn);
  free_coordinate(coord);


}


TEST(print_blocks_withPoint){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * zn = create_blocks(nb_block, dim);

/*   
  copy_coordinate(zn->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(zn->upper_bound_block[0], (float[]){8,2});
  copy_coordinate(zn->lower_bound_block[1], (float[]){8,0});
  copy_coordinate(zn->upper_bound_block[1], (float[]){12,4});
  copy_coordinate(zn->lower_bound_block[2], (float[]){0,4});
  copy_coordinate(zn->upper_bound_block[2], (float[]){14,7});
  copy_coordinate(zn->lower_bound_block[3], (float[]){15,2});
  copy_coordinate(zn->upper_bound_block[3], (float[]){18,7});
 */ 

  copy_coordinate(zn->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(zn->upper_bound_block[0], (float[]){2,7});
  copy_coordinate(zn->lower_bound_block[1], (float[]){2,0});
  copy_coordinate(zn->upper_bound_block[1], (float[]){4,2});
  copy_coordinate(zn->lower_bound_block[2], (float[]){4,1});
  copy_coordinate(zn->upper_bound_block[2], (float[]){8,3});
  copy_coordinate(zn->lower_bound_block[3], (float[]){8,0});
  copy_coordinate(zn->upper_bound_block[3], (float[]){16,2});
  copy_coordinate(zn->lower_bound_block[4], (float[]){16,0});
  copy_coordinate(zn->upper_bound_block[4], (float[]){18,7});
  copy_coordinate(zn->lower_bound_block[5], (float[]){6,7});
  copy_coordinate(zn->upper_bound_block[5], (float[]){18,9});
  copy_coordinate(zn->lower_bound_block[6], (float[]){2,6});
  copy_coordinate(zn->upper_bound_block[6], (float[]){6,8});


  coordinate *coord = create_coordinate(2);

  copy_coordinate(coord, (float[]){1,1});
  EXPECT_TRUE(is_in_blocks(zn, coord));
  
  print2D_blocks_withPoint(zn,0.24,0.48, '#',coord);
  //print2D_blocks(zn,0.14,0.28, '#');
  
  copy_coordinate(coord, (float[]){1,5});
  EXPECT_TRUE(is_in_blocks(zn, coord));
//  print2D_blocks_withPoint(zn,0.24,0.48, '#',coord);
  
  copy_coordinate(coord, (float[]){2,3});
  EXPECT_TRUE(is_in_blocks(zn, coord));
//  print2D_blocks_withPoint(zn,0.24,0.48, '#',coord);
  
  copy_coordinate(coord, (float[]){7,5});
  EXPECT_FALSE(is_in_blocks(zn, coord));



  free_blocks(zn);
  free_coordinate(coord);


}

#if 0

TEST(first_vehicle){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);

  copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){2,7});
  copy_coordinate(path->lower_bound_block[1], (float[]){2,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){4,2});
  copy_coordinate(path->lower_bound_block[2], (float[]){4,0.5});
  copy_coordinate(path->upper_bound_block[2], (float[]){8,3});
  copy_coordinate(path->lower_bound_block[3], (float[]){8,0});
  copy_coordinate(path->upper_bound_block[3], (float[]){16,2});
  copy_coordinate(path->lower_bound_block[4], (float[]){16,0});
  copy_coordinate(path->upper_bound_block[4], (float[]){18,7});
  copy_coordinate(path->lower_bound_block[5], (float[]){6,7});
  copy_coordinate(path->upper_bound_block[5], (float[]){18,9});
  copy_coordinate(path->lower_bound_block[6], (float[]){2,6});
  copy_coordinate(path->upper_bound_block[6], (float[]){6,8});
 
  update_bounds_limits_blocks(path);

  struct vehicle *vhcl = create_vehicle(path);

  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  free_vehicle(vhcl);


}

#endif

TEST(circle_path_vehicle){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);

  copy_coordinate(path->lower_bound_block[0], (float[]){0,3});
  copy_coordinate(path->upper_bound_block[0], (float[]){4,7});
  copy_coordinate(path->lower_bound_block[1], (float[]){1,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){10,3});
  copy_coordinate(path->lower_bound_block[2], (float[]){10,0.5});
  copy_coordinate(path->upper_bound_block[2], (float[]){14,5});
  copy_coordinate(path->lower_bound_block[3], (float[]){14,2});
  copy_coordinate(path->upper_bound_block[3], (float[]){18,7});
  copy_coordinate(path->lower_bound_block[4], (float[]){11,7});
  copy_coordinate(path->upper_bound_block[4], (float[]){17,10});
  copy_coordinate(path->lower_bound_block[5], (float[]){8,6});
  copy_coordinate(path->upper_bound_block[5], (float[]){11,9.75});
  copy_coordinate(path->lower_bound_block[6], (float[]){1,7});
  copy_coordinate(path->upper_bound_block[6], (float[]){8,9.75});
 
  update_bounds_limits_blocks(path);

  struct vehicle *vhcl = create_vehicle(path);

  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  free_vehicle(vhcl);


}

TEST(reward_list){
  struct status_qlearning * l_reward = create_status_qlearning();

  free_status_qlearning(l_reward);
}

#if 1
TEST(first_learn_vehicle){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);



#if 1
  copy_coordinate(path->lower_bound_block[0], (float[]){0,3});
  copy_coordinate(path->upper_bound_block[0], (float[]){4,7});
  copy_coordinate(path->lower_bound_block[1], (float[]){1,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){10,3});
  copy_coordinate(path->lower_bound_block[2], (float[]){10,0.5});
  copy_coordinate(path->upper_bound_block[2], (float[]){14,5});
  copy_coordinate(path->lower_bound_block[3], (float[]){14,2});
  copy_coordinate(path->upper_bound_block[3], (float[]){18,7});
  copy_coordinate(path->lower_bound_block[4], (float[]){11,7});
  copy_coordinate(path->upper_bound_block[4], (float[]){17,10});
  copy_coordinate(path->lower_bound_block[5], (float[]){8,6});
  copy_coordinate(path->upper_bound_block[5], (float[]){11,9.75});
  copy_coordinate(path->lower_bound_block[6], (float[]){1,7});
  copy_coordinate(path->upper_bound_block[6], (float[]){8,9.75});
 
#else 


  copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){2,7});
  copy_coordinate(path->lower_bound_block[1], (float[]){2,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){4,2});
  copy_coordinate(path->lower_bound_block[2], (float[]){4,0.5});
  copy_coordinate(path->upper_bound_block[2], (float[]){8,3});
  copy_coordinate(path->lower_bound_block[3], (float[]){8,0});
  copy_coordinate(path->upper_bound_block[3], (float[]){16,2});
  copy_coordinate(path->lower_bound_block[4], (float[]){16,0});
  copy_coordinate(path->upper_bound_block[4], (float[]){18,7});
  copy_coordinate(path->lower_bound_block[5], (float[]){6,7});
  copy_coordinate(path->upper_bound_block[5], (float[]){18,9});
  copy_coordinate(path->lower_bound_block[6], (float[]){2,6});
  copy_coordinate(path->upper_bound_block[6], (float[]){6,8});
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = 0, maxR = 1;  
  int randomRange = 500;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.001;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );

  struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    200/*size_t delay_between_episodes*/,
    20/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.99/*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
  struct print_params *pprint = create_print_params(
    0.2/*float scale_x*/,0.4 /*float scale_y*/,  
    dly/*struct delay_params * dly_p*/
  );

  struct RL_agent *rlAgent = create_RL_agent (
    nnetworks /*struct networks_qlearning * networks*/,
    car /*struct vehicle *  car*/,
    qlstatus /*struct status_qlearning * status*/,
    pprint /*struct print_params * pprint*/,
    qlparams/*struct qlearning_params *qlearnParams*/
  );

  learn_to_drive(rlAgent);

  free_RL_agent(rlAgent);




}
#endif


int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

return 0;
}
