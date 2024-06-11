#include "vehicle.h"

#define NB_ACTION 3
#define NB_SENSORS 3

//#define LEFT 0
//#define CENTER 1
//#define RIGHT 2

#define LIMIT_DISTANCE ((float)1)/50

#define REWARD_STOP -1000
#define REWARD_CONTINUE 100
#define THRESHOLD_REWARD 10000


struct game_status * create_game_status(){
  struct game_status * status = malloc(sizeof(struct game_status));
  status->state = 0;
  status->reward = 0;
  status->cumulative_reward = 0;
  status->done = false;
}

struct coordinate * create_coordinate(size_t dim_size){
  struct coordinate * ret_coord = malloc(sizeof(struct coordinate));
  ret_coord->dimension_size = dim_size;
  ret_coord->x = malloc(dim_size * sizeof(float));

  return ret_coord;
}
struct blocks * create_blocks(size_t nb_blocks, size_t dim_size){
  struct blocks * ret_blocks = malloc(sizeof(struct blocks));
  ret_blocks->nb_blocks = nb_blocks;
  ret_blocks->dimension_size = dim_size;
  ret_blocks->lower_bound_block = malloc(nb_blocks * sizeof(struct coordinate *));
  ret_blocks->upper_bound_block = malloc(nb_blocks * sizeof(struct coordinate *));
  ret_blocks->bounds_all_blocks = NULL;
  ret_blocks->all_updated = false;
  ret_blocks->marker = malloc(nb_blocks * sizeof(bool));
  
  for(size_t i=0; i<nb_blocks; ++i){
    ret_blocks->lower_bound_block[i] = create_coordinate(dim_size);
    ret_blocks->upper_bound_block[i] = create_coordinate(dim_size);
    ret_blocks->marker[i] = false;
  } 

  return ret_blocks;
}

struct sensors * create_sensors(size_t nb_values){
  struct sensors * ret_sensors = malloc(sizeof(struct sensors));
  ret_sensors->nb_values = nb_values;
  ret_sensors->value = malloc(nb_values * sizeof(float));

  return ret_sensors;
}

struct vehicle * create_vehicle(struct blocks *path){
  struct vehicle * ret_vehicle = malloc(sizeof(struct vehicle));
  
  ret_vehicle->coord = create_coordinate(2);
  ret_vehicle->sensor = create_sensors(NB_SENSORS);
  ret_vehicle->path = path;
  
  ret_vehicle->status = create_game_status();
 
  reset(ret_vehicle);
   
  return ret_vehicle; 

}

void free_game_status(struct game_status *status){
  free(status);
}

void free_coordinate(struct coordinate *coord){
  free(coord->x);
  free(coord);
}

void free_blocks(struct blocks *blk){
  for(size_t i=0; i<blk->nb_blocks; ++i){
    free_coordinate(blk->lower_bound_block[i]);
    free_coordinate(blk->upper_bound_block[i]);
  }
  free(blk->lower_bound_block);
  free(blk->upper_bound_block);
  if(blk->bounds_all_blocks != NULL){
    free_coordinate(blk->bounds_all_blocks[0]);
    free_coordinate(blk->bounds_all_blocks[1]);
    free(blk->bounds_all_blocks);
  }
  free(blk->marker);
  free(blk);
}

void free_sensors(struct sensors *snsr){
  free(snsr->value);
  free(snsr);
}

void free_vehicle(struct vehicle * vhcl){
  free_coordinate(vhcl->coord);
  free_blocks(vhcl->path);
  free_sensors(vhcl->sensor);
  free_game_status(vhcl->status);

  free(vhcl);
}


float scalar_product(struct coordinate *coord1, struct coordinate *coord2){
  size_t dimension_size = coord1->dimension_size;
  if(coord1->dimension_size > coord2->dimension_size )
    dimension_size = coord2->dimension_size;

  float scalar = 0;
  for(size_t i=0; i<dimension_size; ++i){
    scalar += (coord1->x[i] * coord2->x[i]);
  }

  return scalar;
}

float vector_norm2(struct coordinate * coord){
  float scalar  = scalar_product(coord, coord);
  return (float)sqrt(scalar);
}

bool is_in_block_index(struct blocks *blk, size_t index, struct coordinate *coord){
  if(blk->dimension_size != coord->dimension_size) return false;
  for(size_t j=0; j<blk->dimension_size; ++j){
    if( ((blk->lower_bound_block[index])->x[j] > coord->x[j] ) ||
        ((blk->upper_bound_block[index])->x[j] < coord->x[j] )   ){
      return false;
    }
  }
  return true;
  
}


int is_in_blocks(struct blocks *blk, struct coordinate *coord){
  if(blk->dimension_size != coord->dimension_size) return 0;
  size_t count_in = 0;
  for(size_t i=0; i<blk->nb_blocks; ++i){
    count_in = 0;
    for(size_t j=0; j<blk->dimension_size; ++j){
      if( ((blk->lower_bound_block[i])->x[j] <= coord->x[j] ) &&
          ((blk->upper_bound_block[i])->x[j] >= coord->x[j] )   ){
        ++count_in;
      }      
    }
    if(count_in == blk->dimension_size ) 
      return (i+1);
  }
  return 0;
}

void printCoordinate(struct coordinate *coord, char *msg){
  for(size_t i=0; i<coord->dimension_size; ++i){
    printf(" %f,", coord->x[i]);
  }
  printf("{%s} [ %ld ]\n", msg, coord->dimension_size);
}

void copy_coordinate(struct coordinate *coord, float *x){
  for(size_t i=0; i<coord->dimension_size; ++i){
    coord->x[i] = x[i];
  }
}

struct coordinate ** bounds_limits_blocks(struct blocks *blk){ /* min x , max y */
  
  struct coordinate **bounds_coord = malloc(2 * sizeof(struct coordinate*)) ;
  bounds_coord[0] = create_coordinate(blk->dimension_size);
  bounds_coord[1] = create_coordinate(blk->dimension_size);

  copy_coordinate(bounds_coord[0], blk->lower_bound_block[0]->x);
  copy_coordinate(bounds_coord[1], blk->upper_bound_block[1]->x);

  for(size_t i=1; i<blk->nb_blocks; ++i){
    for(size_t j=0; j<blk->dimension_size; ++j){
      bounds_coord[0]->x[j] = MIN(bounds_coord[0]->x[j], blk->lower_bound_block[i]->x[j]);
      bounds_coord[0]->x[j] = MIN(bounds_coord[0]->x[j], blk->upper_bound_block[i]->x[j]);
      bounds_coord[1]->x[j] = MAX(bounds_coord[1]->x[j], blk->lower_bound_block[i]->x[j]);
      bounds_coord[1]->x[j] = MAX(bounds_coord[1]->x[j], blk->upper_bound_block[i]->x[j]);
    }

  }
  

  return bounds_coord;

}

void update_bounds_limits_blocks(struct blocks * blk){
  if(blk->all_updated == false){
    blk->all_updated = true;

    if(blk->bounds_all_blocks != NULL){
      free_coordinate(blk->bounds_all_blocks[0]);
      free_coordinate(blk->bounds_all_blocks[1]);
      free(blk->bounds_all_blocks);
    }
    blk->bounds_all_blocks = bounds_limits_blocks(blk);
  }
}

void print2D_blocks(struct blocks *blk, float scale_x, float scale_y, char pad){
  if(blk->dimension_size == 2){
    //struct coordinate ** bounds_coord = bounds_limits_blocks(blk);
    update_bounds_limits_blocks(blk);
    struct coordinate ** bounds_coord = blk->bounds_all_blocks;

    for(int i=0; i<(bounds_coord[0]->dimension_size); ++i){
      printf(" x[%d]: %f <= %f \n",i, bounds_coord[0]->x[i],bounds_coord[1]->x[i]);
    }

    struct coordinate * coord = create_coordinate(2);
//    int offset_space = 0; 
//    int offset = 2;
    //for(coord->x[1] = bounds_coord[0]->x[1]; coord->x[1] < bounds_coord[1]->x[1]; coord->x[1]+=scale_y )
    for(coord->x[1] = bounds_coord[1]->x[1]; coord->x[1] > bounds_coord[0]->x[1]; coord->x[1]-=scale_y )
    //for(coord->x[1] = bounds_coord[1]->x[1]; coord->x[1] > 0; coord->x[1]-=scale_y )
    {
//      printf("%*c",offset_space,' ');
//      offset_space += offset;
      for(coord->x[0] = bounds_coord[0]->x[0]; coord->x[0] < bounds_coord[1]->x[0]; coord->x[0]+=scale_x )
      //for(coord->x[0] = 0; coord->x[0] < bounds_coord[1]->x[0]; coord->x[0]+=scale_x )
      {
        /*if(is_in_blocks(blk, coord))
          printf("%c",pad);
          */
        int in = is_in_blocks(blk,coord);
        if(in)
          printf("%d",in);
        else
          printf(" ");
      }
      printf("\n");
    }
    free_coordinate(coord);
    
//    free_coordinate(bounds_coord[0]);
//    free_coordinate(bounds_coord[1]);
//    free(bounds_coord);

  }

}


struct blocks * block_neighbord_Point(struct coordinate *coord, float *radius ){
  struct blocks * blk = create_blocks(1, coord->dimension_size);
  for(size_t i=0; i<blk->dimension_size; ++i){
    blk->lower_bound_block[0]->x[i] = coord->x[i]-radius[i] ;
    blk->upper_bound_block[0]->x[i] = coord->x[i]+radius[i] ;
  }

  return blk;
}

void print2D_blocks_withPoint(struct blocks *blk, float scale_x, float scale_y, char pad, struct coordinate *coordPoint){
  if(blk->dimension_size == 2){
    //struct coordinate ** bounds_coord = bounds_limits_blocks(blk);
    update_bounds_limits_blocks(blk);
    struct coordinate ** bounds_coord = blk->bounds_all_blocks;
    
    struct coordinate * coord = create_coordinate(2);
    
    float *radius = malloc(2 * sizeof(float));
    //radius[0] = MIN(scale_x, scale_y);
    //radius[1] = radius[0];
    radius[0]=scale_x;
    radius[1]=scale_y;

    struct blocks * blk_point = block_neighbord_Point(coordPoint, radius);
    //for(coord->x[1] = bounds_coord[0]->x[1]; coord->x[1] < bounds_coord[1]->x[1]; coord->x[1]+=scale_y )
    for(coord->x[1] = bounds_coord[1]->x[1]; coord->x[1] > bounds_coord[0]->x[1]; coord->x[1]-=scale_y ){
      for(coord->x[0] = bounds_coord[0]->x[0]; coord->x[0] < bounds_coord[1]->x[0]; coord->x[0]+=scale_x ){
        if(is_in_blocks(blk_point, coord))
          printf("\033[0;31m"); // red
        if(is_in_blocks(blk, coord))
          printf("%c",pad);
        /*int in = is_in_blocks(blk,coord);
        if(in)
          printf("%d",in);
        */
        else 
          printf(" ");
        //printf("\033[37;01m"); // white gras
        printf("\033[0;37m"); // white
        //printf("\033[0;30m"); // black
      }
      printf("\n");
    }


    free_coordinate(coord);

    free_blocks(blk_point);
    free(radius);
  }
}

void print2D_blocks_indexOne_withPoint(struct blocks *blk, float scale_x, float scale_y, struct coordinate *coordPoint){
  if(blk->dimension_size == 2){
    update_bounds_limits_blocks(blk);
    struct coordinate ** bounds_coord = blk->bounds_all_blocks;
    
    struct coordinate * coord = create_coordinate(2);
    
    float *radius = malloc(2 * sizeof(float));
    radius[0]=scale_x;
    radius[1]=scale_y;

    struct blocks * blk_point = block_neighbord_Point(coordPoint, radius);
    for(coord->x[1] = bounds_coord[1]->x[1]; coord->x[1] > bounds_coord[0]->x[1]; coord->x[1]-=scale_y ){
      for(coord->x[0] = bounds_coord[0]->x[0]; coord->x[0] < bounds_coord[1]->x[0]; coord->x[0]+=scale_x ){
        if(is_in_blocks(blk_point, coord))
          printf("\033[0;31m"); // red
        int in = is_in_blocks(blk,coord);
        if(in)
          printf("%d",in);
        else 
          printf(" ");
        printf("\033[0;37m"); // white
      }
      printf("\n");
    }


    free_coordinate(coord);

    free_blocks(blk_point);
    free(radius);
  }

}

void goto_xy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}


static struct winsize w;

void init_win(){
  ioctl(1, TIOCGWINSZ, &w);
}

void print_vehicle_n_path(struct vehicle *v, float scale_x, float scale_y){
  static bool first = true;
  if(first){
    first = false;
    init_win();
    char pad[w.ws_col+1];
    int i=0;
    for(i=0; i<w.ws_col+1; ++i) pad[i]=' ';
    pad[i]='\0';
    for(i=0; i<w.ws_row / 2 ; ++i) printf("%s\n",pad);;

  }
    //goto_xy(0,w.ws_row - lines);
  goto_xy(0,0);
    //printf("lines : %d , row : %d : diff: %d\n",lines, w.ws_row , w.ws_row - lines);
  print2D_blocks_indexOne_withPoint(v->path, scale_x, scale_y,  v->coord);
  //printf("lines print : %d\n",lines);
  printf("\nlog : %s \n",v->status->log);
}

void move_vehicle(struct vehicle *v){
  v->coord->x[0] += v->speed * cos(v->direction * M_PI / 180);
  v->coord->x[1] += v->speed * sin(v->direction * M_PI / 180);
}

float distance2_coordinate(struct coordinate *c0, struct coordinate *c1){
  if(c0->dimension_size != c1->dimension_size) return 0;
  float d=0, tmp;
  for(size_t i=0; i<c0->dimension_size; ++i){
     tmp = (c0->x[i] - c1->x[i]);
     d += tmp * tmp;
  }
  return sqrt(d);
}

#define SENSOR_VALUE_CALCULATE(position, deviation)\
  direction_radian = (v->direction + deviation) * M_PI / 180;\
  while( is_in_blocks(v->path, diStep_sensor )){\
    diStep_sensor->x[0] += step_sensor * cos(direction_radian);\
    diStep_sensor->x[1] += step_sensor * sin(direction_radian);\
  }\
  v->sensor->value[position] = (MIN(49,(distance2_coordinate(diStep_sensor, v->coord)))) / 50;\
  
  //v->sensor->value[position] = (MIN(49,(int)(distance2_coordinate(diStep_sensor, v->coord)/10))) / 50;\

void read_sensor(struct vehicle *v){
  float step_sensor = ((float)1)/SUBDIVISION;
  struct coordinate * diStep_sensor = create_coordinate(2);
  copy_coordinate(diStep_sensor, v->coord->x);
  
  // count the number of step until we go out of the path = distance
  // center sensor
  float direction_radian ;
  SENSOR_VALUE_CALCULATE(CENTER,0);

  copy_coordinate(diStep_sensor, v->coord->x);
  // right sensor 
  SENSOR_VALUE_CALCULATE(RIGHT,45);
  
  copy_coordinate(diStep_sensor, v->coord->x);
  // left sensor
  SENSOR_VALUE_CALCULATE(LEFT, -45);
 
  free_coordinate(diStep_sensor);

}

#define ADD_CHAR_LOG(status, c)\
  do{\
    if(status->cur_log >= LOG_LENTH){\
      status->cur_log = 0;\
    }\
    status->log[(status->cur_log)++]=c;\
  }while(0);  \
  \


#define ADD_CHAR_LOG_ENDED(status, c)\
  do{\
    if(status->cur_log >= LOG_LENTH){\
      status->cur_log = 0;\
    }\
    status->log[(status->cur_log)++]=c;\
    status->log[(status->cur_log)]='\0';\
  }while(0);  \
  \

void add_string_log_M(struct game_status *status, char *str ){
  size_t i;
  for(i=0; i < strlen(str) - 1; ++i){
    ADD_CHAR_LOG(status, str[i]);
  }
  ADD_CHAR_LOG_ENDED(status, str[i]);
}


void add_string_log(struct game_status *status, char *str ){
  size_t i;
  for(i=0; i < strlen(str) - 1; ++i){
    if(status->cur_log >= LOG_LENTH){
      status->cur_log = 0;
    }
    status->log[(status->cur_log)++]=str[i];
  }
  if(status->cur_log >= LOG_LENTH){
    status->cur_log = 0;
  }
  status->log[(status->cur_log)++]=str[i];
  status->log[(status->cur_log)]='\0';

}

void step(struct vehicle *v, int action){
  float action_value[NB_ACTION]={-3,0,3}; // [LEFT, CENTER, RIGHT]
  v->direction = v->direction + action_value[action % 3];
  v->speed = ((float)1)/2;
  move_vehicle(v);
  read_sensor(v);
  struct game_status *status = v->status;
  status->state =  v->sensor->value[LEFT]* 2500 + 
              v->sensor->value[CENTER]* 50 + 
              v->sensor->value[RIGHT] ;
  status->reward = 0;
  status->done =false;
  struct blocks * path = v->path;
    printf(" center : %f vs %f direction: %f\n",v->sensor->value[CENTER], LIMIT_DISTANCE, v->direction);
  if( v->sensor->value[CENTER]<= LIMIT_DISTANCE ){
    status->reward = REWARD_STOP;
    status->done = true;
  }
  else{
    bool breaked = false;
    long prec, next;
    char msg[48];
    for(long i=0; i< path->nb_blocks; ++i){
        //prec = (i-1)%(path->nb_blocks);
        prec = (i + path->nb_blocks - 1 )%(path->nb_blocks);
        next = (i + 1)%(path->nb_blocks);
        printf("i:%ld, prec:%ld, next:%ld: maker %d, prec marker %d\n",i,prec,next, path->marker[i], path->marker[prec]);
      if(is_in_block_index(path, i, v->coord)){
        if(path->marker[i] == false && path->marker[prec] == true){
          path->marker[i]=true;
          path->marker[prec]=false;
          status->reward = REWARD_CONTINUE;
          status->done = false;
          sprintf(msg," %ld,",i);
          add_string_log(status, msg);
        }
        if(path->marker[next] == true){
          status->reward = REWARD_STOP;
          status->done = true;
          add_string_log(status, "| reverse |");
        }
        breaked = true;
        break;
      }
    }
    if(breaked == false){
      if(status->cumulative_reward > THRESHOLD_REWARD){
        status->reward = REWARD_CONTINUE;
        status->done = true;
      }
    }
  }
  status->cumulative_reward += status->reward;

}



void reset(struct vehicle *v){
  struct blocks * path = v->path;
  long int i;
  for(i=0; i<(path->nb_blocks -1); ++i)
    path->marker[i] = false;
  path->marker[i] = true;
  v->status->cumulative_reward = 0;
  sprintf(v->status->log,"\n");
  v->status->cur_log = 0;
  srand(time(NULL));
  int random;
  int diff;
  diff = path->upper_bound_block[0]->x[0] - path->lower_bound_block[0]->x[0];
  random = rand() % diff;
  v->coord->x[0] = path->lower_bound_block[0]->x[0] + random;
  diff = path->upper_bound_block[0]->x[1] - path->lower_bound_block[0]->x[1];
  random = rand() % diff;
  v->coord->x[1] = path->lower_bound_block[0]->x[1] + random;
  random = rand() % 50;
  v->direction = random - 25;
  //v->direction = 15;
  v->speed = 1;
}
