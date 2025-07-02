#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>

#include <poll.h>

// for sleep !
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif

//#include "ftest/ftest.h"
//#include "ftest/ftest_array.h"
//#include "fmock/fmock.h"

//#include "permutation_t/permutation_t.h"
#include "y_worker_t/y_worker_t.h"
#include "y_worker_t/y_task_t.h"
//#include "tools_t/tools_t.h"

void* funcPrintSelf(void* arg){
  int *count = (int*)arg; //randomm=rand()%1000;
  printf("func: begin func call %d\n",*count);
//  struct argExecTasQ *argx=(struct argExecTasQ*)arg;
  size_t thread_id=pthread_self();
  printf("func:  number=%d; threadid=%ld\n", *count, thread_id);
  usleep(2000);
  printf("func: end func %d; in thread=%ld\n",*count,thread_id);
//  free(count);
  return NULL;
}

void* funcEnd(void* arg){
  printf("funcEnd: begin func End\n");
  struct argExecTasQ *argx=(struct argExecTasQ*)arg;
  static long int count = 0; //randomm=rand()%1000;
  size_t thread_id=pthread_self();
  printf("funcEnd: my status=%d, func number=%ld; threadid=%ld\n",(argx->go_on), count, thread_id);
  usleep(2000);
  printf("funcEnd: end func %ld; in thread=%ld\n",count,thread_id);
  ++count;
  return NULL;
}

void* funcDepRel(void* arg){
  printf("func: begin func release\n");
  struct dependency_task *dep = (struct dependency_task*)arg;
  size_t thread_id=pthread_self();
  printf("func: threadid=%ld\n", thread_id);
  usleep(3000);
  release_dependancy_task(dep);
  printf("==============-------------------> func: end func release in thread=%ld\n",thread_id);
  return NULL;
}
void* funcDepCall(void* arg){
  printf("func: begin func Call dep\n");
  struct dependency_task *dep = (struct dependency_task*)arg;
  size_t thread_id=pthread_self();
  printf("func call: threadid=%ld\n", thread_id);
  wait_dependancy_task(dep);
  printf("==============-----------------> func: end func call dep in thread=%ld\n",thread_id);
  return NULL;
}


int main(){


  srand(time(NULL));
  struct main_list_ptr_y_WORKER_T * workers = create_var_list_ptr_y_WORKER_T();
  
  struct main_list_TYPE_PTR * list_arg = create_var_list_TYPE_PTR();

  struct argExecTasQ *argx =  create_argExecTasQ();
  pthread_mutex_t *mut_workers = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(mut_workers, NULL);
  
int nb_worker=4;
  for(int i=0; i<nb_worker; ++i){
   
    struct y_worker_t *pw= create_ptr_y_WORKER_T(workers, list_arg, mut_workers, argx, GO_ON_WORKER, i);

  printf(" - / -----  -- / ---  %d workers %ld created\n",nb_worker,(pw->arg->pworker->id));
//usleep(500);
  }
usleep(500);
 
int nb_task=9;
  for(int i=0; i<nb_task;++i)
  { 
    int *j=malloc(sizeof(int));
    *j=i*100;
    struct y_task_t task = {
      .func=funcPrintSelf,
      .arg=j,
      .status=TASK_PENDING,
    };
    push_tasQ(argx->tasQ, task);
    push_back_list_TYPE_PTR(list_arg, j);
//    usleep(10000);
  }
  printf("%d tasks created\n",nb_task);
  
  struct dependency_task * argDep = create_dependency_task();
   struct y_task_t taskR = {
      .func=funcDepRel,
      .arg=argDep,
      .status=TASK_PENDING,
    };
    push_tasQ(argx->tasQ, taskR);
  printf(" +++++++++++++++++ task rel dep created\n");


   struct y_task_t taskCal = {
      .func=funcDepCall,
      .arg=argDep,
      .status=TASK_PENDING,
    };
    push_tasQ(argx->tasQ, taskCal);

  printf(" +++++++++++++++++ task call dep created\n");

  for(int i=4; i<8; ++i){
    struct y_worker_t *pw= create_ptr_y_WORKER_T(workers, list_arg, mut_workers, argx, GO_ON_WORKER, i);
    //struct y_worker_t *pw= create_ptr_y_WORKER_T(workers, mut_workers, argx, GO_ON_WORKER, i);
    printf("%d workers %ld created\n",4,(pw->arg->pworker->id));
//usleep(500);
  }

 printf("another %d workers created\n",4);
 
 printf("before kill all workers \n");

 //getchar();

 struct pollfd fd[1];
 fd[0].fd=0;
 fd[0].events = POLLIN | POLLRDNORM | POLLRDBAND | POLLPRI;
 poll(fd, 1, -1);

//  usleep(200000000);
 
  kill_all_workers(workers->begin_list->value->arg);

//  kill_all_workers(workers, argx);


free_dependency_task(argDep);

  return 0;
}

