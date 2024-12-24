#ifndef Y_SOCKET_H__C
#define Y_SOCKET_H__C

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#include <sys/ioctl.h>

#include <netinet/in.h>

#include <sys/socket.h>

#include <fcntl.h>

#include <pthread.h>

#include <signal.h>

struct y_socket_t{
  int fd;       /* Socket descriptor, */
  int domain;   /*AF_INET, AF_INET6 */
  int service;  /*type: SOCK_STREAM: TCP, SOCK_DGRAM: UDP */
  int protocol; /* 0 */
  u_long interface;
  int port;
  int backlog;/*max_queue */

  struct sockaddr_in *address; /* INADDR_ANY or  */
  int address_len;
};

struct y_socket_t * socket_create(int domain, int service, int protocol, u_long interface,
    int port, int backlog);

void socket_destroy(struct y_socket_t *socket);




#endif /* Y_SOCKET_H__C */
