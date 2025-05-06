#include "y_worker_t/y_worker_t.h"

//GEN_LIST_ALL(y_WORKER_T)

GEN_LIST_ALL(ptr_y_WORKER_T)

ptr_y_WORKER_T create_ptr_y_WORKER_T(int exec, int id){
	ptr_y_WORKER_T pworker = malloc(sizeof(y_WORKER_T));
	pworker->exec=exec;
	pworker->mut_worker = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(pworker->mut_worker, NULL);
	pworker->cond_worker = malloc(sizeof(pthread_cond_t));
	pthread_cond_init(pworker->cond_worker, NULL);
	pworker->id=id;
	pworker->thread = malloc(sizeof(pthread_t));

	pworker->arg = NULL;

	return pworker;
}
void free_ptr_y_WORKER_T(ptr_y_WORKER_T pworker){
	//ptr_y_WORKER_T pworker = *p_worker;
	pthread_mutex_destroy(pworker->mut_worker);
	free(pworker->mut_worker);
	pthread_cond_destroy(pworker->cond_worker);
	free(pworker->cond_worker);
	free(pworker->thread);
	if(pworker->arg!=NULL) free(pworker->arg);
	free(pworker);
}

void purge_ptr_y_WORKER_T_in_list(struct main_list_ptr_y_WORKER_T *list_workers){
	for(move_current_to_begin_list_ptr_y_WORKER_T(list_workers); list_workers->current_list; increment_list_ptr_y_WORKER_T(list_workers)){
		free_ptr_y_WORKER_T(list_workers->current_list->value);
	}
}

void assign_argWorker_of_ptr_y_WORKER_T(ptr_y_WORKER_T pworker, struct argExecTasQ *argx, pthread_mutex_t *mut_workers){
	pworker->arg = malloc(sizeof( struct argWorker));
	pworker->arg->argx = argx;
	pworker->arg->pworker = pworker;
	pworker->arg->mut_workers = mut_workers;

}

void* execute_work(void* arg){
  struct argWorker *argw = (struct argWorker*)arg;
  struct argExecTasQ *argx=argw->argx;
//  pthread_mutex_t *mut_workers=argw->mut_workers;
  struct y_worker_t * pworker = argw->pworker;

  size_t id_thread=pthread_self();
  int exec;
  pthread_mutex_lock(pworker->mut_worker);
  exec=pworker->exec;
  pworker->status=WORKER_ON;
  pworker->id_thread=id_thread;
  pthread_mutex_unlock(pworker->mut_worker);
    printf("debug: ############################ execute_task call : thread_id:%ld, self=%ld \n",pworker->id,id_thread);
  do{
    printf("debug: execute_task call : thread_id:%ld, self=%ld \n",pworker->id,id_thread);
    execute_task((void*)argx);
    printf("debug: <<<<>>>> execute_task end, worker exec=%d id:%ld self:%ld \n",exec,pworker->id, pworker->id_thread);
  pthread_mutex_lock(pworker->mut_worker);
  exec=pworker->exec;
  pthread_mutex_unlock(pworker->mut_worker);
    printf("debug: execute_task end, worker exec=%d id:%ld self:%ld \n",exec,pworker->id, pworker->id_thread);
  }while(exec);

  
  pthread_mutex_lock(pworker->mut_worker);
  pworker->status=WORKER_OFF;
    printf("debug: =========>>>  execute_task end, worker OFF =%d, id=%ld self:%ld\n",pworker->status, pworker->id, pworker->id_thread);
  pthread_mutex_unlock(pworker->mut_worker);
	pthread_cond_signal(pworker->cond_worker);
  //free_y_worker_t(worker);
//	usleep(1000);
  return NULL;
}

void kill_all_workers(
								struct main_list_ptr_y_WORKER_T * workers,
								struct argExecTasQ *argx
){
  for(move_current_to_begin_list_ptr_y_WORKER_T(workers); workers->current_list;increment_list_ptr_y_WORKER_T(workers)){
      pthread_mutex_lock(workers->current_list->value->mut_worker);
      workers->current_list->value->exec=KILL_WORKER;
      pthread_mutex_unlock(workers->current_list->value->mut_worker);
  }

  pthread_mutex_lock(argx->tasQ->mut_tasQ);
  (argx->go_on)=0;
  pthread_mutex_unlock(argx->tasQ->mut_tasQ);


  for(move_current_to_begin_list_ptr_y_WORKER_T(workers); workers->current_list;increment_list_ptr_y_WORKER_T(workers)){
    //if(workers->current_list->value->status == WORKER_ON)
    {
      struct y_task_t task = {
        .func=NULL,
        .arg=argx,
        .status=TASK_DONE,
      };
      push_tasQ(argx->tasQ, task);
    }
  }

}


void wait_and_free_workers(struct main_list_ptr_y_WORKER_T *workers){
  int reterror; 
  for(move_current_to_begin_list_ptr_y_WORKER_T(workers); workers->current_list;increment_list_ptr_y_WORKER_T(workers)){
    pthread_mutex_lock(workers->current_list->value->mut_worker);
    if((workers->current_list->value->status) == WORKER_ON){
      while(workers->current_list->value->status == WORKER_ON){
        pthread_cond_wait(workers->current_list->value->cond_worker, workers->current_list->value->mut_worker);
      }
      reterror = pthread_join(*(workers->current_list->value->thread) ,NULL);
      if(0!=reterror){
      printf("debug: error %d pthread_join  thread %ld\n",reterror,(workers->current_list->value->id));
    }
    printf("debug: JOIN done, thread id:%ld id_thread:%ld\n",
        (workers->current_list->value->id),
        (workers->current_list->value->id_thread)
        );
    }else{
    printf("debug: thread id:%ld id_thread:%ld already KILLED\n",
        (workers->current_list->value->id),
        (workers->current_list->value->id_thread)
        );

    }

    workers->current_list->value->status=WORKER_OFF;
    pthread_mutex_unlock(workers->current_list->value->mut_worker);
  }

//  free_argExecTasQ(argx);
  purge_ptr_y_WORKER_T_in_list(workers);
  free_all_var_list_ptr_y_WORKER_T(workers);

//  pthread_mutex_destroy(mut_workers);
//  free(mut_workers);


}
