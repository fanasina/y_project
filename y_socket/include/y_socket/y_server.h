#ifndef Y_SERVER_H__C
#define Y_SERVER_H__C

#include <pthread.h>

#include "y_socket/y_socket.h"



struct y_server_t{
  struct y_socket_t *socket;
//  struct y_client_t *client;
//  int nb_clients;


//  int max_length_queue; //backlog;// max connexion

  pthread_t *thread_server;
  pthread_mutex_t *mut_server;
  int nb_threads;


  void *(*launch)(void*);

};



#endif /* Y_SERVER_H__C */
