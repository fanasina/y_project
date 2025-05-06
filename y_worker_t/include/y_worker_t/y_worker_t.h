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

ptr_y_WORKER_T create_ptr_y_WORKER_T(int exec, int id);
void free_ptr_y_WORKER_T(ptr_y_WORKER_T pworker);

void purge_ptr_y_WORKER_T_in_list(struct main_list_ptr_y_WORKER_T *list_workers);

struct argWorker {
  struct argExecTasQ *argx;
  struct y_worker_t *pworker;
  pthread_mutex_t *mut_workers;
};

void assign_argWorker_of_ptr_y_WORKER_T(ptr_y_WORKER_T pworker, struct argExecTasQ *argx, pthread_mutex_t *mut_worker);

void* execute_work(void* arg);

void kill_all_workers(
                struct main_list_ptr_y_WORKER_T * workers,
                struct argExecTasQ *argx
);
void wait_and_free_workers(struct main_list_ptr_y_WORKER_T *workers);

#endif /* Y_WORKER_T_H__C */
