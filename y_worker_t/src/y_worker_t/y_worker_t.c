#include "y_worker_t/y_worker_t.h"

GEN_LIST_ALL(y_WORKER_T)

void* execute_work(void* arg){
  struct argWorker *argw = (struct argWorker*)arg;
  struct argExecTasQ *argx=argw->argx;
  struct list_y_WORKER_T * worker = argw->worker;
  size_t id_thread=pthread_self();
  do{
    printf("debug: execute_task call : thread_id:%ld, self=%ld \n",worker->value.id,id_thread);
    execute_task((void*)argx);
    printf("debug: execute_task end, worker exec=%d \n",worker->value.exec);
  }while(worker->value.exec);

  
  //free_y_worker_t(worker);
}
