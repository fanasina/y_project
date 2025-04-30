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

TEST(first){
  struct y_tasQ tasQ0 ;
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

void* funcPrintSelf(void* arg){
  LOG("begin fun call\n");
  struct argExecTasQ *argx=(struct argExecTasQ*)arg;
  int randomm=rand()%1000;
  size_t thread_id=pthread_self();
  LOG("my status=%d, idfunc=%d; threadid=%ld\n",*(argx->go_on), randomm, thread_id);
  usleep(200000);
  LOG("end func%d; in thread=%ld\n",randomm,thread_id);
}

TEST(threads){

  srand(time(NULL));
  struct main_list_y_WORKER_T * workers = create_var_list_y_WORKER_T();
  struct argExecTasQ *argx =  create_argExecTasQ();
  
  
  
  for(int i=0; i<4; ++i){
    struct y_worker_t w={.exec=GO_ON_WORKER, .id=i};
    struct list_y_WORKER_T * liwo=malloc(sizeof(struct list_y_WORKER_T));
    liwo->value=w;
    //liwo->preview=NULL;
    liwo->next=NULL;
    append_list_y_WORKER_T(workers, liwo);
    //push_back_list_y_WORKER_T(workers, w);
    struct argWorker argw;
    argw.argx = argx;
    argw.worker=workers->end_list;
  LOG("%d workers %ld created\n",4,argw.worker->value.id);
    pthread_create(&(w.thread),NULL,execute_work,(void*)&argw);
//usleep(5000);
  }
usleep(500000);
 

  for(int i=0; i<10;++i)
  { 
    struct y_task_t task = {
      .func=funcPrintSelf,
      .arg=argx,
      .status=TASK_PENDING,
    };
    push_tasQ(argx->tasQ, task);
    usleep(10000);
  }
  LOG("%d tasks created\n",40);

  for(int i=4; i<8; ++i){
    struct y_worker_t w={.exec=GO_ON_WORKER, .id=i};
    struct list_y_WORKER_T * liwo=malloc(sizeof(struct list_y_WORKER_T));
    liwo->value=w;
    //liwo->preview=NULL;
    liwo->next=NULL;
    append_list_y_WORKER_T(workers, liwo);
    //push_back_list_y_WORKER_T(workers, w);
    struct argWorker argw;
    argw.argx = argx;
    argw.worker=workers->end_list;
    pthread_create(&(w.thread),NULL,execute_work,(void*)&argw);
usleep(5000);
  }
  LOG("another %d workers created\n",4);






//  usleep(400000);
  for(move_current_to_begin_list_y_WORKER_T(workers); workers->current_list;increment_list_y_WORKER_T(workers)){
    workers->current_list->value.exec=KILL_WORKER;
  }
  
  *(argx->go_on)=0;

  for(move_current_to_begin_list_y_WORKER_T(workers); workers->current_list;increment_list_y_WORKER_T(workers)){
    struct y_task_t task = {
      .func=NULL,
      .arg=argx,
      .status=TASK_DONE,
    };
    push_tasQ(argx->tasQ, task);

  }

  
  for(move_current_to_begin_list_y_WORKER_T(workers); workers->current_list;increment_list_y_WORKER_T(workers)){
    pthread_join(workers->current_list->value.thread ,NULL);
    LOG("debug: JOIN donei, thread id:%ld\n",workers->current_list->value.id);
  }

//  usleep(5000000);
  free_argExecTasQ(argx);
  free_all_var_list_y_WORKER_T(workers);
  

}

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
