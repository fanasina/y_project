#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <time.h>

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
#include "y_worker_t/y_worker_t.h"
#include "y_worker_t/y_task_t.h"

//#include <netinet/in.h>
//#include <sys/worker.h>
//#include <arpa/inet.h>

#define VALGRIND_ 1

#if 0
TEST(first){
  //struct y_tasQ tasQ0 ;
  struct y_tasQ *tasQ = create_y_tasQ();

  free_y_tasQ(tasQ);    

}

TEST(worker){
   struct main_list_y_WORKER_T * workers = create_var_list_y_WORKER_T();

   struct y_worker_t w1;
   w1.exec=GO_ON_WORKER;

   push_back_list_y_WORKER_T(workers, w1);
   struct y_worker_t w2;
   w2.exec=KILL_WORKER;//only one task
    
   push_back_list_y_WORKER_T(workers, w2);
   free_all_var_list_y_WORKER_T(workers);


}
#endif 

void* funcPrintSelf(void* arg){
  LOG("func: begin func call\n");
  struct argExecTasQ *argx=(struct argExecTasQ*)arg;
  static long int count = 0; //randomm=rand()%1000;
  size_t thread_id=pthread_self();
  LOG("func: my status=%d, func number=%ld; threadid=%ld\n",(argx->go_on), count, thread_id);
  usleep(200000);
  LOG("func: end func %ld; in thread=%ld\n",count,thread_id);
	++count;
  return NULL;
}

void* funcEnd(void* arg){
  LOG("funcEnd: begin func End\n");
  struct argExecTasQ *argx=(struct argExecTasQ*)arg;
  static long int count = 0; //randomm=rand()%1000;
  size_t thread_id=pthread_self();
  LOG("funcEnd: my status=%d, func number=%ld; threadid=%ld\n",(argx->go_on), count, thread_id);
  usleep(20000);
  LOG("funcEnd: end func %ld; in thread=%ld\n",count,thread_id);
	++count;
  return NULL;
}



TEST(threads){

  srand(time(NULL));
  struct main_list_ptr_y_WORKER_T * workers = create_var_list_ptr_y_WORKER_T();
  struct argExecTasQ *argx =  create_argExecTasQ();
  pthread_mutex_t *mut_workers = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(mut_workers, NULL);  
  
  
  for(int i=0; i<4; ++i){
    struct y_worker_t *pw= create_ptr_y_WORKER_T(GO_ON_WORKER, i);
    assign_argWorker_of_ptr_y_WORKER_T(pw, argx, mut_workers);
    pthread_mutex_lock(mut_workers);
    //append_list_ptr_y_WORKER_T(workers, li_pw);
    push_back_list_ptr_y_WORKER_T(workers, pw);
    pthread_mutex_unlock(mut_workers);
  LOG("%d workers %ld created\n",4,(pw->arg->pworker->id));
    pthread_create(pw->thread,NULL,execute_work,(void*)(pw->arg));
//usleep(500);
  }
//usleep(500000);
 

  for(int i=0; i<40;++i)
  { 
    struct y_task_t task = {
      .func=funcPrintSelf,
      .arg=argx,
      .status=TASK_PENDING,
    };
    push_tasQ(argx->tasQ, task);
//    usleep(10000);
  }
  LOG("%d tasks created\n",40);

	for(int i=4; i<8; ++i){
    struct y_worker_t *pw= create_ptr_y_WORKER_T(GO_ON_WORKER, i);
    assign_argWorker_of_ptr_y_WORKER_T(pw, argx, mut_workers);
    pthread_mutex_lock(mut_workers);
    //append_list_ptr_y_WORKER_T(workers, li_pw);
    push_back_list_ptr_y_WORKER_T(workers, pw);
    pthread_mutex_unlock(mut_workers);
  LOG("%d workers %ld created\n",4,(pw->arg->pworker->id));
    pthread_create(pw->thread,NULL,execute_work,(void*)(pw->arg));
//usleep(500);
  }
 LOG("another %d workers created\n",4);

	kill_all_workers(workers, argx);

	wait_and_free_workers(workers);

  free_argExecTasQ(argx);
  pthread_mutex_destroy(mut_workers);
  free(mut_workers);  

}

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
