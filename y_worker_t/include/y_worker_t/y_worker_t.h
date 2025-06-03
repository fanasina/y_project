#ifndef Y_WORKER_T_H__C
#define Y_WORKER_T_H__C

#include <stdlib.h>
#include <pthread.h>

#include "list_t/list_t.h"

#include "y_worker_t/y_task_t.h"

#define KILL_WORKER 0
#define GO_ON_WORKER 1

#define WORKER_ON 1
#define WORKER_OFF 0


struct argWorker;

typedef struct y_worker_t{
  int exec;
  int status;
  pthread_mutex_t *mut_worker;
  pthread_cond_t *cond_worker;
  size_t id;
  size_t id_thread;
  pthread_t *thread;
	struct argWorker *arg;
} y_WORKER_T;

typedef struct y_worker_t * ptr_y_WORKER_T;


//GENERATE_LIST_ALL(y_WORKER_T)

GENERATE_LIST_ALL(ptr_y_WORKER_T)
//GENERATE_PTR_type_SIG((ptr_y_WORKER_T)


//ptr_y_WORKER_T create_ptr_y_WORKER_T(int exec, int id);
ptr_y_WORKER_T create_ptr_y_WORKER_T(struct main_list_ptr_y_WORKER_T * workers, 
                                      struct main_list_TYPE_PTR *list_arg, 
                                      pthread_mutex_t *mut_workers,
                                     struct argExecTasQ *argx, int exec, int id );
//void free_ptr_y_WORKER_T(ptr_y_WORKER_T pworker);


void purge_list_ptr_y_WORKER_T(struct main_list_ptr_y_WORKER_T *list_workers);
void purge_list_TYPE_PTR(struct main_list_TYPE_PTR *list_voids);

struct argWorker {
  struct argExecTasQ *argx;
  struct y_worker_t *pworker;
  struct main_list_ptr_y_WORKER_T * workers;
  struct main_list_TYPE_PTR * list_arg;

  pthread_mutex_t *mut_workers;
};


void* execute_work(void* arg);

void kill_all_workers(struct argWorker *argw);

//void kill_all_workers(struct main_list_ptr_y_WORKER_T * workers, struct argExecTasQ *argx);
//void wait_workers(struct main_list_ptr_y_WORKER_T *workers);
//void free_workers(struct main_list_ptr_y_WORKER_T *workers);
void free_workers_and_argx(struct main_list_ptr_y_WORKER_T *workers,  struct argExecTasQ *argx);

#endif /* Y_WORKER_T_H__C */
