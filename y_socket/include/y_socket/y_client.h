#ifndef Y_CLIENT_H__C
#define Y_CLIENT_H__C


#include <pthread.h>

#include "y_socket/y_socket.h"



struct y_client{
  size_t id;
  struct y_socket_t *socket;
  int nb_threads;
  pthread_t *thread_client;
  pthread_mutex_t *mut_client;

  void *(*launch)(void*);

};



#endif /* Y_CLIENT_H__C */
