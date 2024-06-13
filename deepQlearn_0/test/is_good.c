#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <math.h>

// for sleep !
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif

#include "ftest/ftest.h"
#include "ftest/ftest_array.h"
#include "fmock/fmock.h"


//#include "permutation_t/permutation_t.h"
#include "neuron_t/neuron_t.h"

#include "vehicle.h"
#include "learn_to_drive.h"

TEST(create_coordenate){
  struct coordinate * coord = create_coordinate(3);
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
  
  struct coordinate *coord = create_coordinate(2);

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


  struct coordinate *coord = create_coordinate(2);

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
  
  step(vhcl, CENTER);
  sleep(2);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step(vhcl, CENTER);
  sleep(2);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  step(vhcl, CENTER);
  sleep(2);
  print_vehicle_n_path(vhcl, 0.2,0.4);
  
  step(vhcl, CENTER);
  sleep(2);
  print_vehicle_n_path(vhcl, 0.2,0.4);

  free_vehicle(vhcl);


}

TEST(reward_list){
  struct status_qlearning * l_reward = create_status_qlearning();

  free_status_qlearning(l_reward);
}

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

return 0;
}
