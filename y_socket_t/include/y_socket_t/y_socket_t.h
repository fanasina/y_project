#ifndef Y_SOCKET_T_H__C
#define Y_SOCKET_T_H__C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

//#include <fcntl.h>

#include <pthread.h>
#include <poll.h>
#include <errno.h>
#include <signal.h>


#include "y_socket_t/y_node_t.h"

#define BUF_SIZE 500

#define type4 
#define type6 6

enum ipVersions{
  v4,v6,nbIpVersion
};

extern const int af_array[nbIpVersion];//={AF_INET, AF_INET6};

struct y_socket_t{
  struct pollfd *fds;
  char * port;
  struct main_list_y_NODE_T *nodes;
  pthread_mutex_t mut_nodes;
};

struct argdst {
  char *port;
  char *addrStr;
};

struct y_socket_t * y_socket_create(char * port);

void y_socket_free(struct y_socket_t *socket);

void *y_pollSocketsFunc(void *arg);
void *threadFuncSend(void *arg);

// type = nothing if v4, 6 if v6
#define  GET_IN_type_ADDR(PointerSockAddr,type) \
     ((struct sockaddr_in##type *)(PointerSockAddr))->sin##type##_addr.s##type##_addr



#endif /* Y_SOCKET_T_H__C */
