#ifndef Y_TASK_T_H__C
#define Y_TASK_T_H__C

#include <pthread.h>
#include <unistd.h>

#include "list_t/list_t.h"

#define TASK_PENDING 2
#define TASK_DONE 0
#define TASK_NOT_DONE 1

typedef struct y_task_t{
  void* (*func)(void*);
  void* arg;
  void* ret;
  int status;
} y_TASK_T;

GENERATE_LIST_ALL(y_TASK_T)

struct y_tasQ{ // taskQueue
  
  struct main_list_y_TASK_T* list_tasQ;
  pthread_mutex_t *mut_tasQ;
  pthread_cond_t *cond_tasQ;
};

struct y_tasQ * create_y_tasQ();

void free_y_tasQ(struct y_tasQ * tasQ);

void push_tasQ(struct y_tasQ *tasQ, struct y_task_t task);
struct list_y_TASK_T* pull_tasQ(struct y_tasQ *tasQ);

struct argExecTasQ{
  int  go_on;
  struct y_tasQ *tasQ;
  struct y_tasQ *historytasQ;
};

struct argExecTasQ * create_argExecTasQ();
void free_argExecTasQ(struct argExecTasQ * arg);

void * execute_task(void *arg);

struct dependency_task{
  int done;
  pthread_mutex_t *mut_dep;
  pthread_cond_t *cond_dep;
};

struct dependency_task * create_dependency_task();
void free_dependency_task(struct dependency_task * dep_task);

void release_dependancy_task(struct dependency_task *dep);
void wait_dependancy_task(struct dependency_task *dep);

#endif /* Y_TASK_T_H__C */
