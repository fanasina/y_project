/* file: y_network_neural_network/src/y_net_neur_net/y_nnn_screenmanager.c */
#include "y_net_neur_net/y_nnn_screen_manager.h"

//#define SIZE_LOCAL_BUF 300

GEN_LIST_ALL(pid_t)


/* return max pidof target, and if m_pid_t is not NULL, put into it all pids */
pid_t pidof(char *target, struct main_list_pid_t *m_pid_t){
  pid_t maxpid=0;
  struct dirent *entry;
  DIR *proc = opendir("/proc"); /*  */
  
  if(!proc){ /* fail */
    perror("opendir /proc");
    return -1;
  }
  /* loop on subdir of proc */
  while((entry=readdir(proc)) != NULL){
    int is_pid=1; /* init to not digit subdir */
    for(int i=0; entry->d_name[i]; ++i){
      if(!isdigit((unsigned char) entry->d_name[i])){
        is_pid=0;
        break;
      }
    }
    if(!is_pid) /* not pid i.e, exists i / is_pid == 0 */
      continue;
    
    char path[SIZE_LOCAL_BUF];
    snprintf(path,SIZE_LOCAL_BUF, "/proc/%s/comm",entry->d_name);

    int fd_comm = open(path, O_RDONLY);
    if(fd_comm<0){
      continue;
    }
    char name[SIZE_LOCAL_BUF];
    int status;
    if((status=read(fd_comm, name, SIZE_LOCAL_BUF))){
      name[status-1]=0;
      if(strcmp(name,target)==0){
        pid_t valpid=(pid_t)atol(entry->d_name);
        if(maxpid<valpid) maxpid=valpid;
        if(m_pid_t){
          push_back_list_pid_t(m_pid_t,valpid);
        }
      }
    }
    close(fd_comm);
  }
  closedir(proc);
  
  return maxpid;
}
/* to write in an open bash terminal */
int sprintbashpid(pid_t pid, char *content, size_t size_content){
  char duplicate_stdout_path[128];
  sprintf(duplicate_stdout_path,"/proc/%d/fd/1",pid);
  int fd_stdout=open(duplicate_stdout_path, O_WRONLY);
  if(fd_stdout >-1){
    write(fd_stdout,content,size_content);
    close(fd_stdout);
    return 0; 
  }
  else{
    perror("sprintbashpid\n");
    return -1;
  } 

}
int open_duplicate_bash_most_recent(){
  pid_t pid=pidof("bash", NULL);
  char duplicate_stdout_path[128];
  sprintf(duplicate_stdout_path,"/proc/%d/fd/1",pid);
  return open(duplicate_stdout_path, O_WRONLY);
}

int open_duplicate_bash(pid_t pid){
  char duplicate_stdout_path[128];
  sprintf(duplicate_stdout_path,"/proc/%d/fd/1",pid);
  return open(duplicate_stdout_path, O_WRONLY);
}

void close_duplicate_bash(int fd){
  if(fd>0)
    close(fd);
}

int write_duplicate_bash(int fd, char *content, size_t size_content){
  if(fd>0){
    return write(fd, content, size_content);
  }
  return fd;
}

struct arg_bash *create_arg_bash(){
  struct arg_bash *b_arg=malloc(sizeof(struct arg_bash));
  b_arg->old_bash_pid = pidof("bash", NULL);
  b_arg->new_bash_pid = b_arg->old_bash_pid;
  b_arg->current_bash_pid= b_arg->old_bash_pid;
  b_arg->fd_old_bash_pid = -1;
  b_arg->fd_new_bash_pid= -1;
  b_arg->fd_current_bash_pid= -1;
  
  b_arg->mut_bash_var = malloc(sizeof(pthread_mutex_t));
  b_arg->cond_bash_var = malloc(sizeof(pthread_cond_t));
  pthread_mutex_init(b_arg->mut_bash_var, NULL);
  pthread_cond_init(b_arg->cond_bash_var,NULL);
  
  b_arg->go_on=1;
  b_arg->thread_launch=NULL;

  return b_arg;
}

/* free and kill bash */
void free_arg_bash(struct arg_bash *arg){
  pthread_mutex_destroy(arg->mut_bash_var);
  free(arg->mut_bash_var);
  pthread_cond_destroy(arg->cond_bash_var);
  free(arg->cond_bash_var);

  if(arg->fd_new_bash_pid > 0) {
    close(arg->fd_new_bash_pid);
    kill(arg->new_bash_pid, SIGKILL);
  }
  
  if(arg->fd_current_bash_pid > 0 && arg->fd_current_bash_pid != arg->fd_new_bash_pid) {
    close(arg->fd_current_bash_pid);
    kill(arg->current_bash_pid, SIGKILL);
  }

  if(arg->thread_launch){
    pthread_join(*(arg->thread_launch), NULL);
    free(arg->thread_launch);
  }

  free(arg);
}

int new_bash_exist(struct arg_bash *bash_arg){
  return ((bash_arg->fd_new_bash_pid>0) || (bash_arg->fd_current_bash_pid>0));
}

/* run new bash terminal graphic, can be called directly or in a thread */
void* run_newbash(void* argg){
  struct arg_bash *arg=(struct arg_bash*)argg;
  //* fork exec better than system call!

if(arg->new_bash_pid == arg->old_bash_pid){
  pid_t pid=fork();
  if(pid<0){
    perror("fork");
  }
  else if(pid==0){/* child */
    char *cmdbash[]={"/usr/bin/gnome-terminal",NULL};
    execvp(cmdbash[0], cmdbash);
  }else{
    wait(NULL);

    usleep(20000);

    pthread_mutex_lock(arg->mut_bash_var);
    arg->new_bash_pid = pidof("bash",NULL);
    arg->fd_new_bash_pid = open_duplicate_bash(arg->new_bash_pid);
    while(arg->new_bash_pid == arg->old_bash_pid)
    {
      printf("debug: create new terminal: %d vs %d\n",arg->new_bash_pid,arg->old_bash_pid);
      getchar();
      arg->new_bash_pid = pidof("bash",NULL);
      arg->fd_new_bash_pid = open_duplicate_bash(arg->new_bash_pid);
      //usleep(2000);
    }
    
    pthread_mutex_unlock(arg->mut_bash_var);
    pthread_cond_signal(arg->cond_bash_var);
      printf("debug: send signal run_newbash\n");

  }
}
  return NULL;
}

void kill_all_bash(struct arg_bash *arg){
  pthread_mutex_lock(arg->mut_bash_var);
  if(arg->fd_new_bash_pid > 0) {
    close(arg->fd_new_bash_pid);
    kill(arg->new_bash_pid, SIGKILL);
    arg->new_bash_pid = arg->old_bash_pid;
    arg->fd_new_bash_pid = -1;
  }
  
  if(arg->fd_current_bash_pid > 0 && arg->fd_current_bash_pid != arg->fd_new_bash_pid) {
    close(arg->fd_current_bash_pid);
    kill(arg->current_bash_pid, SIGKILL);
    arg->current_bash_pid = arg->old_bash_pid;
    arg->fd_current_bash_pid=-1;
  }
  pthread_mutex_unlock(arg->mut_bash_var);
}

int check_go_on_bash(struct arg_bash *arg){
  int ret;
  pthread_mutex_lock(arg->mut_bash_var);
  ret = arg->go_on;
  pthread_mutex_unlock(arg->mut_bash_var);
  return ret;
}


void set_go_on_bash(struct arg_bash *arg, int go_on){
  pthread_mutex_lock(arg->mut_bash_var);
  arg->go_on = go_on;
  pthread_mutex_unlock(arg->mut_bash_var);
}

/* call run_newbash in a thread */
void* launch_new_bash(void *b_arg){
  struct arg_bash *arg = (struct arg_bash*)b_arg; // create_arg_bash();
  
  //run_newbash(arg);
  pthread_t new_bash_thread;

  pthread_create(&new_bash_thread, NULL, run_newbash, (void*)arg);
/*
  pthread_mutex_lock(arg->mut_bash_var);
  while(arg->fd_new_bash_pid == -1){
    printf("debug: wait new bash!\n");
    pthread_cond_wait(arg->cond_bash_var, arg->mut_bash_var);
  }
  pthread_mutex_unlock(arg->mut_bash_var);
*/
  pthread_join(new_bash_thread, NULL);
  
  //free_arg_bash(arg);
  return NULL;
}
/* to be call in thread or directly! */
void* wait_sleep_newbash(void* argg){
  struct arg_bash *arg=(struct arg_bash*)argg;
  //* fork exec better than system call!
  
  char *msg="Please, open new terminal or new ssh to this machine!";
  int len_msg=strlen(msg);
  char pad[len_msg+1];
  memset(pad,' ',len_msg);
  while(
    (arg->current_bash_pid == arg->old_bash_pid) ||
    (arg->current_bash_pid == arg->new_bash_pid)
    ){
    write(1,"\r",1);
    write(1,pad,len_msg);
    usleep(400000);
    write(1,"\r",1);
    write(1,msg,len_msg);
    usleep(400000);
    arg->current_bash_pid = pidof("bash", NULL);
  }
    //char *msg_o="open fd, ";
    //int len_msg_o=strlen(msg_o);
    pthread_mutex_lock(arg->mut_bash_var);
  //if(arg->current_bash_pid != arg->new_bash_pid){
      while(arg->fd_current_bash_pid == -1){
        //write(1,msg_o,len_msg_o);
        arg->fd_current_bash_pid = open_duplicate_bash(arg->current_bash_pid);
      }
  //}
    pthread_mutex_unlock(arg->mut_bash_var);
    pthread_cond_signal(arg->cond_bash_var);

  return NULL;
}


/* call wait_newbash in a thread */
void* launch_sleep_wait_bash(void *b_arg){
  struct arg_bash *arg = (struct arg_bash*)b_arg; // create_arg_bash();
  //wait_newbash(arg);
  
  pthread_t wait_bash_thread;

  pthread_create(&wait_bash_thread, NULL, wait_sleep_newbash, (void*)arg);
/*
  pthread_mutex_lock(arg->mut_bash_var);
  while(arg->fd_current_bash_pid == -1){
    printf("debug: wait new bash!\n");
    pthread_cond_wait(arg->cond_bash_var, arg->mut_bash_var);
  }
  pthread_mutex_unlock(arg->mut_bash_var);
*/
  pthread_join(wait_bash_thread, NULL);

    //free_arg_bash(arg);
  return NULL;
}




/* to be call in thread or directly! */
void* wait_newbash(void* argg){
  struct arg_bash *arg=(struct arg_bash*)argg;
  //* fork exec better than system call!
  
  char *msg="Please, open new terminal or new ssh to this machine!, then touch enter in this terminal.\n";
  int len_msg=strlen(msg);
  while(arg->current_bash_pid == arg->old_bash_pid){
    write(1,msg,len_msg);
    getchar();
    arg->current_bash_pid = pidof("bash", NULL);
  }
  while(arg->current_bash_pid == arg->new_bash_pid){
    write(1,msg,len_msg);
    getchar();
    arg->current_bash_pid = pidof("bash", NULL);
  }

  //char *msg_o="open fd, ";
  //int len_msg_o=strlen(msg_o);
  pthread_mutex_lock(arg->mut_bash_var);
    while(arg->fd_current_bash_pid == -1){
      //write(1,msg_o,len_msg_o);
      arg->fd_current_bash_pid = open_duplicate_bash(arg->current_bash_pid);
    }
  
  
  pthread_mutex_unlock(arg->mut_bash_var);
  pthread_cond_signal(arg->cond_bash_var);

  return NULL;
}


int  _xy_goto(char *str, int x, int y){
 return sprintf(str,"%c[%d;%df", 0x1B, y, x);
}

/* call wait_newbash in a thread */
void* launch_wait_bash(void *b_arg){
  struct arg_bash *arg = (struct arg_bash*)b_arg; // create_arg_bash();
  //wait_newbash(arg);
  
  pthread_t wait_bash_thread;

  pthread_create(&wait_bash_thread, NULL, wait_newbash, (void*)arg);
/*
  pthread_mutex_lock(arg->mut_bash_var);
  while(arg->fd_current_bash_pid == -1){
    printf("debug: wait new bash!\n");
    pthread_cond_wait(arg->cond_bash_var, arg->mut_bash_var);
  }
  pthread_mutex_unlock(arg->mut_bash_var);
*/
  pthread_join(wait_bash_thread, NULL);

    //free_arg_bash(arg);
  return NULL;
}

#define __BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf)\
            if(bash_arg->fd_new_bash_pid>0){\
              write(bash_arg->fd_new_bash_pid, buf , len_buf);\
            }\
            if(bash_arg->fd_current_bash_pid>0){\
              write(bash_arg->fd_current_bash_pid, buf, len_buf);\
            }\
  

void bash_print_vehicle_n_path(struct vehicle *v, float scale_x, float scale_y, struct arg_bash *bash_arg){
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
  ////goto_xy(0,0);
  BASH_WRITE_IF_EXIST(bash_arg, GOTO_TOP_LEFT, LEN_GOTO_TOP_LEFT);
    //printf("lines : %d , row : %d : diff: %d\n",lines, w.ws_row , w.ws_row - lines);
  bash_print2D_blocks_indexOne_withPoint(v->path, scale_x, scale_y,  v->coord, bash_arg);
  //printf("lines print : %d\n",lines);
  char loggg[SIZE_LOCAL_BUF];
  int len_loggg=sprintf(loggg,"\nlog : %s \n",v->status->log);
  BASH_WRITE_IF_EXIST(bash_arg, loggg, len_loggg);
}


void bash_print2D_blocks_indexOne_withPoint(struct blocks *blk, float scale_x, float scale_y, coordinate *coordPoint, struct arg_bash *bash_arg){
  if(blk->dimension_size == 2){
    update_bounds_limits_blocks(blk);
    coordinate ** bounds_coord = blk->bounds_all_blocks;

    coordinate * coord = create_coordinate(2);

    float *radius = malloc(2 * sizeof(float));
    radius[0]=scale_x;
    radius[1]=scale_y;
    char buf[SIZE_LOCAL_BUF];
    int len_buf;
    struct blocks * blk_point = block_neighbord_Point(coordPoint, radius);
    for(coord->x[1] = bounds_coord[1]->x[1]; coord->x[1] > bounds_coord[0]->x[1]; coord->x[1]-=scale_y ){
      for(coord->x[0] = bounds_coord[0]->x[0]; coord->x[0] < bounds_coord[1]->x[0]; coord->x[0]+=scale_x ){
        if(is_in_blocks(blk_point, coord)){
          ////printf("\033[0;31m"); // red
            BASH_WRITE_IF_EXIST(bash_arg, "\033[0;31m", 7);
        }
        int in = is_in_blocks(blk,coord);
        if(in){
          if(in>9){
            int div=in%10;
            ////printf("%d",div);
            len_buf=sprintf(buf,"%d",div);
            BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf);
          }else{
            ////printf("%d",in);
            len_buf=sprintf(buf,"%d",in);
            BASH_WRITE_IF_EXIST(bash_arg, buf, len_buf);
          }
        }else{
          ////printf("."); //printf(" ");
          BASH_WRITE_IF_EXIST(bash_arg, ".", 1);
        }

        ////printf("\033[0;37m"); // white
        BASH_WRITE_IF_EXIST(bash_arg, "\033[0;37m", 7); // white
      }
      ///printf("\n");
      BASH_WRITE_IF_EXIST(bash_arg,"\n",1);
    }


    free_coordinate(coord);

    free_blocks(blk_point);
    free(radius);
  }

}


