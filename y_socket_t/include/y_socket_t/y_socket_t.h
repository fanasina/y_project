/*file: include/y_socket_t/y_socket_t.h*/

#ifndef Y_SOCKET_T_H__C
#define Y_SOCKET_T_H__C

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include <signal.h>

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

//#include "y_socket_t/y_socket_t.h"
#include "y_socket_t/y_node_t.h"
#include "y_socket_t/y_file_handler.h"

#include "y_worker_t/y_worker_t.h"
#include "y_worker_t/y_task_t.h"

#include "y_socket_t/y_list_var_tool.h"

#include "json_t/json_t.h"

#define BUF_SIZE 500
#define TIMEOUT_MS 100

#define type4 
#define type6 6

enum ipVersions{
  v4,v6,nbIpVersion
};

extern const int af_array[nbIpVersion];//={AF_INET, AF_INET6};

struct arg_var_{
  int set_up;
  struct y_socket_t * argSock; 
  struct main_list_TYPE_PTR * list_arg; 
  struct argExecTasQ *argx; 
  struct main_list_y_ptr_HEADER_T *m_ok_head_l_t;
  pthread_mutex_t *mut_var;
  pthread_cond_t *cond_var;
  void (*extern_socket_handler)(char*,int);
};

struct arg_var_ * create_arg_var_(void (*extern_socket_handler)(char*,int));
void set_up_arg_var_init_(struct arg_var_ *var, struct y_socket_t * argSock, struct main_list_TYPE_PTR * list_arg, struct argExecTasQ *argx , struct main_list_y_ptr_HEADER_T *m_ok_head_l_t);
void free_arg_var_(struct arg_var_ *var);
void wait_var_set_up_value_not_equal(struct arg_var_ *var, int value_set_up);


struct y_socket_t{
  struct pollfd *fds;
	size_t size_fds; 
  char * port;
  struct main_list_y_NODE_T *nodes;
//  pthread_mutex_t *mut_nodes;
	int go_on;
  pthread_mutex_t *mut_go_on;
  int nb_workers;
  struct arg_var_ *var;
};

void set_cmd_to_socket(char * buf, size_t len_buf, struct arg_var_ *var);


//struct y_socket_t * create_y_socket_t(size_t size_fds, char *port);
//void free_y_socket_t(struct y_socket_t *sock);

struct argdst {
  char *port;
  char *addrStr;
};

//struct y_socket_t * y_socket_create_(char * port);
struct y_socket_t * y_socket_create(char * port, size_t size_fds, int nb_workers, struct arg_var_ *var);
struct y_socket_t * y_socket_create_(char * port);

void y_socket_free(struct y_socket_t *socket);

void *y_socket_poll_fds(void *arg);
void *threadFuncSend(void *arg);

// type = nothing if v4, 6 if v6
#define  GET_IN_type_ADDR(PointerSockAddr,type) \
     ((struct sockaddr_in##type *)(PointerSockAddr))->sin##type##_addr.s##type##_addr
#if 0
/* y_ptr_STRING */
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

#endif /* y_ptr_STRING */

/* y_ptr_VARIABLE */
#if 0
struct y_variable{
  char * name;
  void * value;
};

typedef struct y_variable * y_ptr_VARIABLE;

struct y_variable * create_y_ptr_VARIABLE(const char *name, size_t size_value);
GENERATE_LIST_ALL(y_ptr_VARIABLE)
GEN_HEAD_PTR_LIST(y_ptr_VARIABLE)
#endif /* y_ptr_VARIABLE */



#endif /* Y_SOCKET_T_H__C */
