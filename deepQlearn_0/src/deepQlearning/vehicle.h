#ifndef __VEHICLE__C_H__
#define __VEHICLE__C_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <time.h>
#include <unistd.h>

#include <sys/ioctl.h>


#include <math.h>

#include "tools_t/tools_t.h"
#include "dimension_t/dimension_t.h"
#include "tensor_t/tensor_t.h"

#define LOG_LENTH 128

#define LEFT 0
#define CENTER 1
#define RIGHT 2

#define SUBDIVISION 10


struct game_status {
  long state;
  long reward;
  long cumulative_reward;
  bool done;
  char log[LOG_LENTH];
  int cur_log;
};

//struct coordinate {
//  size_t dimension_size;
//  float *x;
//};

typedef tensor_TYPE_FLOAT coordinate;

/*
  +-----------------------+ <-- upper_bound_block (coordinate (6,5) for example) 
  |                       |
  |                       |
  |  BLOCK                |
  |                       |
  |                       |
  +-----------------------+ 
  ^ 
  |
  lower_bound_block (coordinate ( 0,0 ) for example

*/
struct blocks {
  size_t nb_blocks;
  size_t dimension_size; /* rank */
  coordinate **lower_bound_block; 
  coordinate **upper_bound_block;
  coordinate **bounds_all_blocks;
  bool all_updated;
  dimension *dim;
  bool *marker;
  //float step: // size of subdivision of the lowest large
};


//struct sensors {
//  size_t nb_values;
//  float *value;
//  tensor_TYPE_FLOAT * sensor;
//};
typedef tensor_TYPE_FLOAT sensors;

struct vehicle {
  coordinate *coord;
  float direction;
  float speed;
  sensors *sensor;
  struct blocks *path;
  struct game_status *status;
};

struct game_status * greate_game_status();
coordinate * create_coordinate(size_t dim_size);
struct blocks * create_blocks(size_t nb_blocks, size_t dim_size);

sensors * create_sensors(size_t nb_values);
struct vehicle * create_vehicle( 
  struct blocks *path
);

void free_game_status(struct game_status *status);
void free_coordinate(coordinate *coord);
void free_blocks(struct blocks *blk);

void free_sensors(sensors *snsr);

void free_vehicle(struct vehicle * vhcl);

void update_bounds_limits_blocks(struct blocks * blk);

int is_in_blocks(struct blocks *blk, coordinate *coord);

void copy_coordinate(coordinate *coord, float *x);

void move_vehicle(struct vehicle *v);
void read_sensor(struct vehicle *v);
void step(struct vehicle *v, int action);

void reset(struct vehicle *v);

void print2D_blocks_indexOne_withPoint(struct blocks *blk, float scale_x, float scale_y, coordinate *coordPoint);
void print_vehicle_n_path(struct vehicle *v, float scale_x, float scale_y);

float distance2_coordinate(coordinate *c0, coordinate *c1);

void print2D_blocks(struct blocks *blk, float scale_x, float scale_y, char pad);
void print2D_blocks_withPoint(struct blocks *blk, float scale_x, float scale_y, char pad, coordinate *coordPoint);

#endif /* __VEHICLE__C_H__  */
