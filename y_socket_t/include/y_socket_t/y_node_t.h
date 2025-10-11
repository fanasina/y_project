/*file: include/y_socket_t/y_node_t.h */

#ifndef __Y_NODE_T_H__C
#define __Y_NODE_T_H__C

#include <netinet/in.h>

//#include "y_socket_t/y_socket_t.h"
#include "list_t/list_t.h"


typedef struct y_node_t{
  //char *id;
  struct sockaddr_storage addr;
  socklen_t addr_len;
} y_NODE_T;





GENERATE_LIST_ALL(y_NODE_T)

void init_len_y_NODE_T(y_NODE_T *node);
void init_len_list_y_NODE_T(struct main_list_y_NODE_T *listNodes);

int y_NODE_T_cmp(y_NODE_T nodeA, y_NODE_T nodeB);

struct list_y_NODE_T * search_node_in_list_y_NODE_T(struct main_list_y_NODE_T *listNodes, y_NODE_T node);
int set_addr_y_NODE_T(y_NODE_T *node, char * addrStr);
void set_port_y_NODE_T(y_NODE_T *node, int port);
void set_str_port_y_NODE_T(y_NODE_T *node, char *str_port);

const char * put_y_NODE_T_in_string(y_NODE_T *node, char * dst);
void update_nodes(y_NODE_T node, struct main_list_y_NODE_T *nodes);
void * remove_node_from_nodes(void* arg);
void * add_node_to_nodes(void* arg);

#endif /* __Y_NODE_T_H__C */
