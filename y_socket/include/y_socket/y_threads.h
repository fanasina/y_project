#ifndef __Y_THREAD_H__
#define __Y_THREAD_H__


#include <pthread.h>

#include "y_socket/y_queue.h"


struct y_threadpool{
  int nb_threads;
  pthread_cond_t cond_;
  pthread_mutex_t mut_;
  pthread_t *thread;
  void *(*launch)(void* arg);

};
#endif /*__Y_THREAD_H__*/
