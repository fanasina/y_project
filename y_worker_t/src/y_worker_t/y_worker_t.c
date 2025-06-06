#include "y_worker_t/y_worker_t.h"

//GEN_LIST_ALL(y_WORKER_T)

GEN_LIST_ALL(ptr_y_WORKER_T)

//GENERATE_PTR_type_FUNC(ptr_y_WORKER_T)


void * execute_workNULL(void *arg){
  usleep(500);
  return NULL;
}

ptr_y_WORKER_T create_ptr_y_WORKER_T(struct main_list_ptr_y_WORKER_T * workers,
                                     struct main_list_TYPE_PTR *list_arg, 
                                      pthread_mutex_t *mut_workers, 
                                     struct argExecTasQ *argx, int exec, int id ){
	ptr_y_WORKER_T pworker = malloc(sizeof(y_WORKER_T));
	pworker->exec=exec;
	pworker->status=WORKER_OFF;
	pworker->mut_worker = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(pworker->mut_worker, NULL);
	pworker->cond_worker = malloc(sizeof(pthread_cond_t));
	pthread_cond_init(pworker->cond_worker, NULL);
	pworker->id=id;
	pworker->id_thread=id;
	pworker->thread = malloc(sizeof(pthread_t));
 

	pworker->arg = malloc(sizeof( struct argWorker)); 
	pworker->arg->argx = argx;
	pworker->arg->pworker = pworker;
	pworker->arg->workers = workers;
	pworker->arg->mut_workers = mut_workers;
	pworker->arg->list_arg = list_arg;

  pthread_mutex_lock(mut_workers);
  push_back_list_ptr_y_WORKER_T(workers, pworker);
  pthread_mutex_unlock(mut_workers);
  
  pthread_create(pworker->thread,NULL,execute_work,(void*)(pworker->arg));
  

	return pworker;
}
void __free_ptr_y_WORKER_T(void* p_worker){
	ptr_y_WORKER_T pworker = (struct y_worker_t*)p_worker;
	pthread_mutex_destroy(pworker->mut_worker);
	free(pworker->mut_worker);
	pthread_cond_destroy(pworker->cond_worker);
	free(pworker->cond_worker);
	free(pworker->thread);
  free(pworker->arg);
	free(pworker);
}

/*
void purge_list_ptr_y_WORKER_T(struct main_list_ptr_y_WORKER_T *list_workers){
	for(move_current_to_begin_list_ptr_y_WORKER_T(list_workers); list_workers->current_list; increment_list_ptr_y_WORKER_T(list_workers)){
		free_ptr_y_WORKER_T(list_workers->current_list->value);
	}
  free_all_var_list_ptr_y_WORKER_T(list_workers);
}
void purge_list_TYPE_PTR(struct main_list_TYPE_PTR *list_voids){
	for(move_current_to_begin_list_TYPE_PTR(list_voids); list_voids->current_list; increment_list_TYPE_PTR(list_voids)){
		free(list_voids->current_list->value);
	}
  free_all_var_list_TYPE_PTR(list_voids);
}

*/


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
	pthread_cond_signal(pworker->cond_worker);
    //printf("debug: ############################ execute_task call : thread_id:%ld, self=%ld \n",pworker->id,id_thread);
  do{
    //printf("debug: execute_task call : thread_id:%ld, self=%ld \n",pworker->id,id_thread);
    execute_task((void*)argx);
    //printf("debug: <<<<>>>> execute_task end, worker exec=%d id:%ld self:%ld \n",exec,pworker->id, pworker->id_thread);
  pthread_mutex_lock(pworker->mut_worker);
  exec=pworker->exec;
  pthread_mutex_unlock(pworker->mut_worker);
    //printf("debug: execute_task end, worker exec=%d id:%ld self:%ld \n",exec,pworker->id, pworker->id_thread);
  }while(exec);

  
  pthread_mutex_lock(pworker->mut_worker);
  pworker->status=WORKER_OFF;
    //printf("debug: =========>>>  execute_task end, worker OFF =%d, id=%ld self:%ld\n",pworker->status, pworker->id, pworker->id_thread);
  pthread_mutex_unlock(pworker->mut_worker);
	pthread_cond_signal(pworker->cond_worker);
//	usleep(1000);
  return NULL;
}

void wait_workers(struct main_list_ptr_y_WORKER_T *workers){
  for(move_current_to_begin_list_ptr_y_WORKER_T(workers); workers->current_list;increment_list_ptr_y_WORKER_T(workers)){
      pthread_join(*(workers->current_list->value->thread) ,NULL);
  }
}


int check_worker_status(struct y_worker_t * pworker ){
  int ret;
  pthread_mutex_lock(pworker->mut_worker);
  ret = pworker->status;
  pthread_mutex_unlock(pworker->mut_worker);
  return ret;
}

GEN_FUNC_PTR_LIST_FREE(ptr_y_WORKER_T){
  ptr_y_WORKER_T pworker = (struct y_worker_t*)arg;
  pthread_mutex_destroy(pworker->mut_worker);
  free(pworker->mut_worker);
  pthread_cond_destroy(pworker->cond_worker);
  free(pworker->cond_worker);
  free(pworker->thread);
  free(pworker->arg);
  free(pworker);
} 

void kill_all_workers ( struct argWorker *argw){
  	struct main_list_ptr_y_WORKER_T * workers  = argw->workers;
	  struct argExecTasQ *argx = argw->argx;

  for(move_current_to_begin_list_ptr_y_WORKER_T(workers); workers->current_list;increment_list_ptr_y_WORKER_T(workers)){
      pthread_mutex_lock(workers->current_list->value->mut_worker);
      workers->current_list->value->exec=KILL_WORKER;
      pthread_mutex_unlock(workers->current_list->value->mut_worker);
  }

  pthread_mutex_lock(argx->tasQ->mut_tasQ);
  (argx->go_on)=0;
  pthread_mutex_unlock(argx->tasQ->mut_tasQ);

  for(move_current_to_begin_list_ptr_y_WORKER_T(workers); workers->current_list;increment_list_ptr_y_WORKER_T(workers)){
///    if(check_worker_status(workers->current_list->value) == WORKER_ON)
    {
      struct y_task_t task = {
        .func=NULL,
        .arg=NULL,
        .status=TASK_DONE,
      };
      push_tasQ(argx->tasQ, task);
    }
  }
///}
  

  wait_workers(workers);
 
 
  pthread_mutex_destroy(argw->mut_workers);
  free(argw->mut_workers);
/*
  purge_list_TYPE_PTR(argw->list_arg);
  purge_list_ptr_y_WORKER_T(workers);
*/
  purge_ptr_type_list_TYPE_PTR(argw->list_arg);
  purge_ptr_type_list_ptr_y_WORKER_T(workers);
  
  free_argExecTasQ(argx);
  


}


