#ifndef Y_SOCKET_T_H__C
#define Y_SOCKET_T_H__C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

//#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/sendfile.h>

#include <fcntl.h>

#include <pthread.h>
#include <poll.h>
#include <errno.h>
#include <signal.h>

#include <string.h>

#include "y_socket_t/y_node_t.h"

#include "y_worker_t/y_worker_t.h"
#include "y_worker_t/y_task_t.h"


#define BUF_SIZE 500
#define TIMEOUT_MS 100

#define type4 
#define type6 6

enum ipVersions{
  v4,v6,nbIpVersion
};

extern const int af_array[nbIpVersion];//={AF_INET, AF_INET6};

struct y_string{
	char * buf;
	size_t size;
};

typedef struct y_string * y_ptr_STRING;

struct y_string * create_y_ptr_STRING(const char *buf, size_t size);
GENERATE_LIST_ALL(y_ptr_STRING)
GEN_HEAD_PTR_LIST(y_ptr_STRING)

size_t total_size_list_y_ptr_STRING(struct main_list_y_ptr_STRING *mstr);
size_t copy_list_y_ptr_STRING_to_one_string(char **p_dst_str, struct main_list_y_ptr_STRING *mstr);

struct y_socket_t{
  struct pollfd *fds;
	size_t size_fds; 
  char * port;
  struct main_list_y_NODE_T *nodes;
  pthread_mutex_t *mut_nodes;
	int go_on;
  pthread_mutex_t *mut_go_on;
  int nb_workers;
};


//struct y_socket_t * create_y_socket_t(size_t size_fds, char *port);
//void free_y_socket_t(struct y_socket_t *sock);

struct argdst {
  char *port;
  char *addrStr;
};

//struct y_socket_t * y_socket_create_(char * port);
struct y_socket_t * y_socket_create(char * port, size_t size_fds, int nb_workers);
struct y_socket_t * y_socket_create_(char * port);

void y_socket_free(struct y_socket_t *socket);

void *y_socket_poll_fds(void *arg);
void *threadFuncSend(void *arg);

// type = nothing if v4, 6 if v6
#define  GET_IN_type_ADDR(PointerSockAddr,type) \
     ((struct sockaddr_in##type *)(PointerSockAddr))->sin##type##_addr.s##type##_addr



#endif /* Y_SOCKET_T_H__C */
