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

TEST(circle_path_vehicle_00){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);

  copy_coordinate(path->lower_bound_block[0], (float[]){0,300});
  copy_coordinate(path->upper_bound_block[0], (float[]){400,700});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){1000,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){1000,50});
  copy_coordinate(path->upper_bound_block[2], (float[]){1400,500});
  copy_coordinate(path->lower_bound_block[3], (float[]){1400,200});
  copy_coordinate(path->upper_bound_block[3], (float[]){1800,700});
  copy_coordinate(path->lower_bound_block[4], (float[]){1100,700});
  copy_coordinate(path->upper_bound_block[4], (float[]){1700,1000});
  copy_coordinate(path->lower_bound_block[5], (float[]){800,600});
  copy_coordinate(path->upper_bound_block[5], (float[]){1100,975});
  copy_coordinate(path->lower_bound_block[6], (float[]){100,700});
  copy_coordinate(path->upper_bound_block[6], (float[]){800,975});
 
  update_bounds_limits_blocks(path);

  struct vehicle *vhcl = create_vehicle(path);

  print_vehicle_n_path(vhcl, 20,40);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
/*  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
*/
  free_vehicle(vhcl);


}



TEST(circle_path_vehicle_50){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);
#if 1
  copy_coordinate(path->lower_bound_block[6], (float[]){0,30});
  copy_coordinate(path->upper_bound_block[6], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[5], (float[]){150,0});
  copy_coordinate(path->upper_bound_block[5], (float[]){250,80});
  copy_coordinate(path->lower_bound_block[4], (float[]){250,20});
  copy_coordinate(path->upper_bound_block[4], (float[]){360,120});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,80});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[2], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[1], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[1], (float[]){760,350});
  copy_coordinate(path->lower_bound_block[0], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[0], (float[]){410,300});


#else 
    copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[1], (float[]){150,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,170});
  copy_coordinate(path->lower_bound_block[4], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[4], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[5], (float[]){760,350});
  copy_coordinate(path->lower_bound_block[6], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[6], (float[]){410,300});


copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){100,250});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){250,80});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,0});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,140});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,140});
  copy_coordinate(path->lower_bound_block[4], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[4], (float[]){720,300});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[5], (float[]){720,350});
  copy_coordinate(path->lower_bound_block[6], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[6], (float[]){410,300});
 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *vhcl = create_vehicle(path);

  print_vehicle_n_path(vhcl, 10,10);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
/*  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step_vehicle(vhcl, CENTER);
  Sleep(200);
  print_vehicle_n_path(vhcl, 0.2,0.4);
*/
  free_vehicle(vhcl);


}

TEST(reward_list){
  struct status_qlearning * l_reward = create_status_qlearning();

  free_status_qlearning(l_reward);
}


float f(float x){
  return 1/(1+exp((double)(-x)));
}

float df(float x){
  return exp(-x)/ ((1+exp(-x)) * (1+exp(-x)));
}
#if 1
TEST(first_learn_vehicle_rev50_8){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);



#if 0
  copy_coordinate(path->lower_bound_block[6], (float[]){0,30});
  copy_coordinate(path->upper_bound_block[6], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[5], (float[]){150,0});
  copy_coordinate(path->upper_bound_block[5], (float[]){250,80});
  copy_coordinate(path->lower_bound_block[4], (float[]){250,20});
  copy_coordinate(path->upper_bound_block[4], (float[]){360,120});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,80});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[2], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[1], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[1], (float[]){760,350});
  copy_coordinate(path->lower_bound_block[0], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[0], (float[]){410,300});

#else

  copy_coordinate(path->lower_bound_block[4], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[4], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[5], (float[]){150,40});
  copy_coordinate(path->upper_bound_block[5], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[6], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[6], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[0], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[0], (float[]){600,150});
  copy_coordinate(path->lower_bound_block[1], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[1], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){260,300});
  copy_coordinate(path->upper_bound_block[2], (float[]){760,360});
  copy_coordinate(path->lower_bound_block[3], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[3], (float[]){410,300});


 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  //config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,14,14,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = -0.5, maxR = 0.5;  
  int randomRange = 500;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.001; // 0.00001 /*0.001*/;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );

//EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->main_net, weight_in, ".ff_main_20240717_01h42m16s_5300.txt");
//EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->target_net, weight_in, ".ff_target_20240717_01h42m16s_5300.txt");

struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    500/*size_t delay_between_episodes*/,
    50/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.99, // 0.0001 /* 0.99*/  /*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
/*   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, f_act, f );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, f_act , f );
*/
  struct print_params *pprint = create_print_params(
    12/*float scale_x*/,12 /*float scale_y*/,  
    dly/*struct delay_params * dly_p*/
  );

  struct RL_agent *rlAgent = create_RL_agent (
    nnetworks /*struct networks_qlearning * networks*/,
    car /*struct vehicle *  car*/,
    qlstatus /*struct status_qlearning * status*/,
    pprint /*struct print_params * pprint*/,
    qlparams/*struct qlearning_params *qlearnParams*/
  );
char c;
scanf("%c",&c);
  learn_to_drive(rlAgent);

  free_RL_agent(rlAgent);




}
#endif



#if 1
TEST(first_learn_vehicle_50__9){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);

#if 1
    copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[1], (float[]){150,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,170});
  copy_coordinate(path->lower_bound_block[4], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[4], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[5], (float[]){760,350});
  copy_coordinate(path->lower_bound_block[6], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[6], (float[]){410,300});



/*

  copy_coordinate(path->lower_bound_block[4], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[4], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[3], (float[]){150,40});
  copy_coordinate(path->upper_bound_block[3], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[1], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[1], (float[]){600,150});
  copy_coordinate(path->lower_bound_block[0], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[0], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[6], (float[]){260,300});
  copy_coordinate(path->upper_bound_block[6], (float[]){760,360});
  copy_coordinate(path->lower_bound_block[5], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[5], (float[]){410,300});


  copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){100,250});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){250,80});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,0});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,140});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,140});
  copy_coordinate(path->lower_bound_block[4], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[4], (float[]){720,300});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[5], (float[]){720,350});
  copy_coordinate(path->lower_bound_block[6], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[6], (float[]){410,300});
 



  copy_coordinate(path->lower_bound_block[0], (float[]){0,300});
  copy_coordinate(path->upper_bound_block[0], (float[]){400,700});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){1000,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){1000,50});
  copy_coordinate(path->upper_bound_block[2], (float[]){1400,500});
  copy_coordinate(path->lower_bound_block[3], (float[]){1400,200});
  copy_coordinate(path->upper_bound_block[3], (float[]){1800,700});
  copy_coordinate(path->lower_bound_block[4], (float[]){1100,700});
  copy_coordinate(path->upper_bound_block[4], (float[]){1700,1000});
  copy_coordinate(path->lower_bound_block[5], (float[]){800,600});
  copy_coordinate(path->upper_bound_block[5], (float[]){1100,975});
  copy_coordinate(path->lower_bound_block[6], (float[]){100,700});
  copy_coordinate(path->upper_bound_block[6], (float[]){800,975});
 */

#else 

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
 
 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  //config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,14,14,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = -0.5, maxR = 0.5;  
  int randomRange = 500;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.00001 /* 0.001*/;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );
/*
EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->main_net, weight_in, ".ff_main_20240717_01h42m16s_5300.txt");
EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->target_net, weight_in, ".ff_target_20240717_01h42m16s_5300.txt");
*/

EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->main_net, weight_in, ".ff_main_20240717_09h11m09s_1700.txt");
EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->target_net, weight_in, ".ff_target_20240717_09h11m09s_1700.txt");

struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    500/*size_t delay_between_episodes*/,
    50/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.0001/*0.99*/  /*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
/*   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, f_act, f );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, f_act , f );
*/
  struct print_params *pprint = create_print_params(
    12/*float scale_x*/,12 /*float scale_y*/,  
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



#if 1
TEST(first_learn_vehicle_50__10){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);

#if 1

  copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){100,250});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){250,80});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,0});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,140});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,140});
  copy_coordinate(path->lower_bound_block[4], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[4], (float[]){720,300});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[5], (float[]){720,350});
  copy_coordinate(path->lower_bound_block[6], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[6], (float[]){410,300});
 


/*

  copy_coordinate(path->lower_bound_block[4], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[4], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[3], (float[]){150,40});
  copy_coordinate(path->upper_bound_block[3], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[1], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[1], (float[]){600,150});
  copy_coordinate(path->lower_bound_block[0], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[0], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[6], (float[]){260,300});
  copy_coordinate(path->upper_bound_block[6], (float[]){760,360});
  copy_coordinate(path->lower_bound_block[5], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[5], (float[]){410,300});




copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[1], (float[]){150,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,170});
  copy_coordinate(path->lower_bound_block[4], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[4], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[5], (float[]){760,350});
  copy_coordinate(path->lower_bound_block[6], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[6], (float[]){410,300});



  copy_coordinate(path->lower_bound_block[0], (float[]){0,300});
  copy_coordinate(path->upper_bound_block[0], (float[]){400,700});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){1000,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){1000,50});
  copy_coordinate(path->upper_bound_block[2], (float[]){1400,500});
  copy_coordinate(path->lower_bound_block[3], (float[]){1400,200});
  copy_coordinate(path->upper_bound_block[3], (float[]){1800,700});
  copy_coordinate(path->lower_bound_block[4], (float[]){1100,700});
  copy_coordinate(path->upper_bound_block[4], (float[]){1700,1000});
  copy_coordinate(path->lower_bound_block[5], (float[]){800,600});
  copy_coordinate(path->upper_bound_block[5], (float[]){1100,975});
  copy_coordinate(path->lower_bound_block[6], (float[]){100,700});
  copy_coordinate(path->upper_bound_block[6], (float[]){800,975});
 */

#else 

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
 
 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  //config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,14,14,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = -0.5, maxR = 0.5;  
  int randomRange = 500;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.00001 /* 0.001*/;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );
/*
EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->main_net, weight_in, ".ff_main_20240717_01h42m16s_5300.txt");
EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->target_net, weight_in, ".ff_target_20240717_01h42m16s_5300.txt");
*/

EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->main_net, weight_in, ".ff_main_20240717_09h11m09s_1700.txt");
EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->target_net, weight_in, ".ff_target_20240717_09h11m09s_1700.txt");

struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    500/*size_t delay_between_episodes*/,
    50/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.0001/*0.99*/  /*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
/*   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, f_act, f );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, f_act , f );
*/
  struct print_params *pprint = create_print_params(
    12/*float scale_x*/,12 /*float scale_y*/,  
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



#if 1
TEST(first_learn_vehicle_50__11){
  size_t nb_block = 10;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);

#if 1

  copy_coordinate(path->lower_bound_block[9], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[9], (float[]){100,250});
  copy_coordinate(path->lower_bound_block[0], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){250,80});
  copy_coordinate(path->lower_bound_block[1], (float[]){250,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){360,140});
  copy_coordinate(path->lower_bound_block[2], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[2], (float[]){600,140});
  copy_coordinate(path->lower_bound_block[3], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[3], (float[]){720,300});
  copy_coordinate(path->lower_bound_block[4], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[4], (float[]){720,350});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,150});
  copy_coordinate(path->upper_bound_block[5], (float[]){410,300});
  copy_coordinate(path->lower_bound_block[6], (float[]){120,150});
  copy_coordinate(path->upper_bound_block[6], (float[]){300,210});
  copy_coordinate(path->lower_bound_block[7], (float[]){120,210});
  copy_coordinate(path->upper_bound_block[7], (float[]){270,350});
  copy_coordinate(path->lower_bound_block[8], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[8], (float[]){120,350});
 


/*

  copy_coordinate(path->lower_bound_block[4], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[4], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[3], (float[]){150,40});
  copy_coordinate(path->upper_bound_block[3], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[1], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[1], (float[]){600,150});
  copy_coordinate(path->lower_bound_block[0], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[0], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[6], (float[]){260,300});
  copy_coordinate(path->upper_bound_block[6], (float[]){760,360});
  copy_coordinate(path->lower_bound_block[5], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[5], (float[]){410,300});




copy_coordinate(path->lower_bound_block[0], (float[]){0,0});
  copy_coordinate(path->upper_bound_block[0], (float[]){150,250});
  copy_coordinate(path->lower_bound_block[1], (float[]){150,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){250,150});
  copy_coordinate(path->lower_bound_block[2], (float[]){250,80});
  copy_coordinate(path->upper_bound_block[2], (float[]){360,200});
  copy_coordinate(path->lower_bound_block[3], (float[]){360,70});
  copy_coordinate(path->upper_bound_block[3], (float[]){600,170});
  copy_coordinate(path->lower_bound_block[4], (float[]){600,90});
  copy_coordinate(path->upper_bound_block[4], (float[]){760,300});
  copy_coordinate(path->lower_bound_block[5], (float[]){300,300});
  copy_coordinate(path->upper_bound_block[5], (float[]){760,350});
  copy_coordinate(path->lower_bound_block[6], (float[]){0,250});
  copy_coordinate(path->upper_bound_block[6], (float[]){410,300});



  copy_coordinate(path->lower_bound_block[0], (float[]){0,300});
  copy_coordinate(path->upper_bound_block[0], (float[]){400,700});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){1000,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){1000,50});
  copy_coordinate(path->upper_bound_block[2], (float[]){1400,500});
  copy_coordinate(path->lower_bound_block[3], (float[]){1400,200});
  copy_coordinate(path->upper_bound_block[3], (float[]){1800,700});
  copy_coordinate(path->lower_bound_block[4], (float[]){1100,700});
  copy_coordinate(path->upper_bound_block[4], (float[]){1700,1000});
  copy_coordinate(path->lower_bound_block[5], (float[]){800,600});
  copy_coordinate(path->upper_bound_block[5], (float[]){1100,975});
  copy_coordinate(path->lower_bound_block[6], (float[]){100,700});
  copy_coordinate(path->upper_bound_block[6], (float[]){800,975});
 */

#else 

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
 
 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  //config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,14,14,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = -0.5, maxR = 0.5;  
  int randomRange = 500;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.00001 /* 0.001*/;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );

//print_vehicle_n_path(car, 12, 12);

EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->main_net, weight_in, ".ff_main_20240717_09h11m09s_1700.txt");
EXTRACT_FILE_TO_TENSOR_ATTRIBUTE_NNEURONS(TYPE_FLOAT, nnetworks->target_net, weight_in, ".ff_target_20240717_09h11m09s_1700.txt");

struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    500/*size_t delay_between_episodes*/,
    50/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.0001/*0.99*/  /*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
/*   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, f_act, f );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, f_act , f );
*/
  struct print_params *pprint = create_print_params(
    12/*float scale_x*/,12 /*float scale_y*/,  
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






#if 1
TEST(first_learn_vehicle){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);



#if 1

  copy_coordinate(path->lower_bound_block[0], (float[]){0,300});
  copy_coordinate(path->upper_bound_block[0], (float[]){400,700});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){1000,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){1000,50});
  copy_coordinate(path->upper_bound_block[2], (float[]){1400,500});
  copy_coordinate(path->lower_bound_block[3], (float[]){1400,200});
  copy_coordinate(path->upper_bound_block[3], (float[]){1800,700});
  copy_coordinate(path->lower_bound_block[4], (float[]){1100,700});
  copy_coordinate(path->upper_bound_block[4], (float[]){1700,1000});
  copy_coordinate(path->lower_bound_block[5], (float[]){800,600});
  copy_coordinate(path->upper_bound_block[5], (float[]){1100,975});
  copy_coordinate(path->lower_bound_block[6], (float[]){100,700});
  copy_coordinate(path->upper_bound_block[6], (float[]){800,975});
 

#else 

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
 
 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  //config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,14,14,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = -0.5, maxR = 0.5;  
  int randomRange = 5000;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.1;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );

  struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    100/*size_t delay_between_episodes*/,
    10/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.85  /*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
/*   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, f_act, f );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, f_act , f );
*/
  struct print_params *pprint = create_print_params(
    20/*float scale_x*/,40 /*float scale_y*/,  
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



#if 1
TEST(first_learn_vehicle){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);



#if 1

  copy_coordinate(path->lower_bound_block[0], (float[]){0,300});
  copy_coordinate(path->upper_bound_block[0], (float[]){400,700});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){1000,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){1000,50});
  copy_coordinate(path->upper_bound_block[2], (float[]){1400,500});
  copy_coordinate(path->lower_bound_block[3], (float[]){1400,200});
  copy_coordinate(path->upper_bound_block[3], (float[]){1800,700});
  copy_coordinate(path->lower_bound_block[4], (float[]){1100,700});
  copy_coordinate(path->upper_bound_block[4], (float[]){1700,1000});
  copy_coordinate(path->lower_bound_block[5], (float[]){800,600});
  copy_coordinate(path->upper_bound_block[5], (float[]){1100,975});
  copy_coordinate(path->lower_bound_block[6], (float[]){100,700});
  copy_coordinate(path->upper_bound_block[6], (float[]){800,975});
 

#else 

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
 
 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  //config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,14,14,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = -0.5, maxR = 0.5;  
  int randomRange = 5000;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.1;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );

  struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    100/*size_t delay_between_episodes*/,
    10/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.85  /*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
/*   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, f_act, f );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, f_act , f );
*/
  struct print_params *pprint = create_print_params(
    20/*float scale_x*/,40 /*float scale_y*/,  
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




#if 0
TEST(first_learn_vehicle){
  size_t nb_block = 7;
  size_t dim= 2;
  struct blocks * path = create_blocks(nb_block, dim);



#if 1

  copy_coordinate(path->lower_bound_block[0], (float[]){0,300});
  copy_coordinate(path->upper_bound_block[0], (float[]){400,700});
  copy_coordinate(path->lower_bound_block[1], (float[]){100,0});
  copy_coordinate(path->upper_bound_block[1], (float[]){1000,300});
  copy_coordinate(path->lower_bound_block[2], (float[]){1000,50});
  copy_coordinate(path->upper_bound_block[2], (float[]){1400,500});
  copy_coordinate(path->lower_bound_block[3], (float[]){1400,200});
  copy_coordinate(path->upper_bound_block[3], (float[]){1800,700});
  copy_coordinate(path->lower_bound_block[4], (float[]){1100,700});
  copy_coordinate(path->upper_bound_block[4], (float[]){1700,1000});
  copy_coordinate(path->lower_bound_block[5], (float[]){800,600});
  copy_coordinate(path->upper_bound_block[5], (float[]){1100,975});
  copy_coordinate(path->lower_bound_block[6], (float[]){100,700});
  copy_coordinate(path->upper_bound_block[6], (float[]){800,975});
 

#else 

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
 
 
#endif

  update_bounds_limits_blocks(path);

  struct vehicle *car = create_vehicle(path);

  config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,24,24,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  //config_layers *pconf = create_config_layers_from_OneD(4,(size_t[]){3,14,14,3}); /* 3 input , 3 target; 2 hidden layer with 24 neurons each */
  
  bool randomize=true; 
  float minR = -0.5, maxR = 0.5;  
  int randomRange = 5000;
  size_t nb_prod_thread = 2;
  size_t nb_calc_thread = 4;
  float learning_rate = 0.1;  
  struct networks_qlearning *nnetworks = create_nework_qlearning(
    pconf,
    randomize, minR, maxR,  randomRange,
    nb_prod_thread, nb_calc_thread,
    learning_rate
  );

  struct status_qlearning *qlstatus = create_status_qlearning ();
  struct delay_params *dly = create_delay_params (
    100/*size_t delay_between_episodes*/,
    10/*size_t delay_between_games*/
  );
  
  struct qlearning_params *qlparams = create_qlearning_params (
    0.95/*float gamma*/,
    learning_rate,
    0 /* (not used!)float discount_factor*/,
    0.85  /*float exploration_factor*/,
    20/*long int nb_training_before_update_weight_in_target*/,
    10000/*size_t number_episodes*/
  );
/*   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->main_net, f_act, f );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, d_f_act , df );
   UPDATE_ATTRIBUTE_NEURONE_IN_ALL_LAYERS(TYPE_FLOAT, nnetworks->target_net, f_act , f );
*/
  struct print_params *pprint = create_print_params(
    20/*float scale_x*/,40 /*float scale_y*/,  
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
