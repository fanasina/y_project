#include "y_worker_t/y_task_t.h"

GEN_LIST_ALL(y_TASK_T)


struct y_tasQ * create_y_tasQ(){
  struct y_tasQ *tmp_ytsQ = malloc(sizeof(struct y_tasQ));
  tmp_ytsQ->list_tasQ = create_var_list_y_TASK_T();
  tmp_ytsQ->mut_tasQ = malloc(sizeof(pthread_mutex_t));
  tmp_ytsQ->cond_tasQ = malloc(sizeof(pthread_cond_t));
  pthread_mutex_init(tmp_ytsQ->mut_tasQ, NULL);
  pthread_cond_init(tmp_ytsQ->cond_tasQ, NULL);
  return tmp_ytsQ;
}

void free_y_tasQ(struct y_tasQ * tasQ){
  pthread_mutex_destroy(tasQ->mut_tasQ);
  pthread_cond_destroy(tasQ->cond_tasQ);

  free(tasQ->mut_tasQ);
  free(tasQ->cond_tasQ);
  
  free_all_var_list_y_TASK_T(tasQ->list_tasQ);

  free(tasQ);
}

void push_tasQ(struct y_tasQ *tasQ, struct y_task_t task){
  printf("debug: push_tasQ debut\n");
  pthread_mutex_lock(tasQ->mut_tasQ);
  push_back_list_y_TASK_T(tasQ->list_tasQ, task);
  pthread_mutex_unlock(tasQ->mut_tasQ);
  pthread_cond_signal(tasQ->cond_tasQ);
  printf("debug: push_tasQ fin\n");
}
struct list_y_TASK_T* pull_tasQ(struct y_tasQ *tasQ){
  printf("debug: pull_tasQ debut\n");
  struct list_y_TASK_T *valueRet = NULL;
  pthread_mutex_lock(tasQ->mut_tasQ);
  while(tasQ->list_tasQ->end_list == NULL){
    pthread_cond_wait(tasQ->cond_tasQ, tasQ->mut_tasQ);
  }
  printf("debug: call pull_end_from_list_y_TASK_T  debut\n");
  valueRet  = pull_end_from_list_y_TASK_T(tasQ->list_tasQ);
  printf("debug: call pull_end_from_list_y_TASK_T  fin, is tasQ NULL? : %d\nis tasQ->list_tasQ NULL?:%d\n", tasQ==NULL, tasQ->list_tasQ == NULL);
  pthread_mutex_unlock(tasQ->mut_tasQ);
 

  printf("debug: pull_tasQ fin : is valueRet NULL ? = %d\n", valueRet == NULL);
  return valueRet;
}

struct argExecTasQ * create_argExecTasQ(){
  struct argExecTasQ * retasQ = malloc(sizeof(struct argExecTasQ));
  retasQ->go_on = malloc(sizeof(int));
  *(retasQ->go_on)=1;
  retasQ->tasQ = create_y_tasQ();
  retasQ->historytasQ = create_y_tasQ();
  return retasQ;
}
void free_argExecTasQ(struct argExecTasQ * arg){
  free(arg->go_on);
  free_y_tasQ(arg->tasQ);
  free_y_tasQ(arg->historytasQ);
  free(arg);
}

void * execute_task(void *arg){
  struct argExecTasQ *argx = (struct argExecTasQ *)arg;
  struct y_tasQ *tasQ = argx->tasQ;
  struct y_tasQ *historytasQ = argx->historytasQ;
  struct list_y_TASK_T *l_task=NULL;
  while(*(argx->go_on)){

    l_task = pull_tasQ(tasQ);
    printf("debug: is l_task NULL? = %d\n", l_task==NULL);
    if(l_task){
      if((l_task->value.status != TASK_DONE) && (l_task->value.func!=NULL))
        l_task->value.ret = l_task->value.func(l_task->value.arg);
    
      l_task->value.status = TASK_DONE;
    } 
    pthread_mutex_lock(historytasQ->mut_tasQ);
    if(l_task) append_list_y_TASK_T(historytasQ->list_tasQ, l_task);
    pthread_mutex_unlock(historytasQ->mut_tasQ);


  }
}


