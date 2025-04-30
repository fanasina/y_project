#ifndef Y_WORKER_T_H__C
#define Y_WORKER_T_H__C

#include <stdlib.h>
#include <pthread.h>

#include "list_t/list_t.h"

#include "y_worker_t/y_task_t.h"

#define KILL_WORKER 0
#define GO_ON_WORKER 1

typedef struct y_worker_t{
  int exec;
//  pthread_mutex_t *mut_worker;
//  pthread_cond_t *cond_worker;
  size_t id;
  pthread_t thread;
} y_WORKER_T;


GENERATE_LIST_ALL(y_WORKER_T)


struct argWorker {
  struct argExecTasQ *argx;
  struct list_y_WORKER_T *worker;
};

void* execute_work(void* arg);

#endif /* Y_WORKER_T_H__C */
