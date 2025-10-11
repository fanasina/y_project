/*file: src/y_socket_t/y_node_t.c*/

#include "y_socket_t/y_node_t.h"
#include "y_socket_t/y_socket_t.h"

// type=nothing if v4, type=6 if v6
#define  GET_type_IN_ADDR(PointerSockAddr,type) \
     ((struct sockaddr_in##type *)(PointerSockAddr))->sin##type##_addr.s##type##_addr

GEN_LIST_ALL(y_NODE_T)


void init_len_y_NODE_T(y_NODE_T *node){
  node->addr_len=sizeof(struct sockaddr_storage);
}

void init_len_list_y_NODE_T(struct main_list_y_NODE_T *listNodes){
  FOR_LIST_FORM_BEGIN(y_NODE_T, listNodes){
    init_len_y_NODE_T(&(listNodes->current_list->value));
  }
}

int y_NODE_T_cmp(y_NODE_T nodeA, y_NODE_T nodeB){
  int ret = nodeA.addr_len - nodeB.addr_len;
  if(ret == 0){
    ret = nodeA.addr.ss_family - nodeB.addr.ss_family;
    if(ret == 0){
      if(nodeA.addr.ss_family == AF_INET){
        //ret = memcmp((struct sockaddr_in*)&(nodeA.addr), (struct sockaddr_in*)&(nodeB.addr), sizeof(struct sockaddr_in));
        ret = ((struct sockaddr_in*)&(nodeA.addr))->sin_port - ((struct sockaddr_in*)&(nodeB.addr))->sin_port;
        if(ret==0) 
          ret = GET_IN_type_ADDR(&(nodeA.addr),) - GET_IN_type_ADDR(&(nodeB.addr),);
        //ret = ((struct sockaddr_in*)&(nodeA.addr))->sin_addr.s_addr - ((struct sockaddr_in*)&(nodeB.addr))->sin_addr.s_addr; 
      }else
      if(nodeA.addr.ss_family == AF_INET6){
        ret = ((struct sockaddr_in6*)&(nodeA.addr))->sin6_port - ((struct sockaddr_in6*)&(nodeB.addr))->sin6_port;
        if(ret ==0)
          //ret = memcmp((struct sockaddr_in6*)&(nodeA.addr), (struct sockaddr_in6*)&(nodeB.addr), sizeof(struct sockaddr_in6));
          ret = memcmp(GET_IN_type_ADDR(&(nodeA.addr),6), GET_IN_type_ADDR(&(nodeB.addr),6), 8);
        //ret = memcmp(((struct sockaddr_in6*)&(nodeA.addr))->sin6_addr.s6_addr , ((struct sockaddr_in6*)&(nodeB.addr))->sin6_addr.s6_addr, 8); 
      }
    }
  }
  return ret;
}

struct list_y_NODE_T * search_node_in_list_y_NODE_T(struct main_list_y_NODE_T *listNodes, y_NODE_T node){
/*  FOR_LIST_FORM_BEGIN(y_NODE_T, listNodes){
    if(y_NODE_T_cmp(node, listNodes->current_list->value) == 0){
      return listNodes->current_list;      
    }
  }
  return NULL; 
  */
  return search_first_occ_from_begin_in_list_y_NODE_T(listNodes, node, y_NODE_T_cmp);
}

int set_addr_y_NODE_T(y_NODE_T *node, char * addrStr){
		//memset(&(node->addr), 0, sizeof(struct sockaddr_storage));
  int af = AF_INET, ret = -2;
  for(int i=0; i<strlen(addrStr); ++i){
    if(addrStr[i]=='.')
      break;
    if(addrStr[i]==':'){
      af=AF_INET6;
      break;
    }
  }
  node->addr.ss_family = af;
  if(af==AF_INET)
    ret = inet_pton(af, addrStr, &(GET_IN_type_ADDR(&(node->addr),)));
  else if(af == AF_INET6){
		//((struct sockaddr_in6*)(&(node->addr)))->sin6_flowinfo = 0; 
		ret = inet_pton(af, addrStr, (GET_IN_type_ADDR(&(node->addr), 6)));
  
	}
  return ret;
  
}


void set_port_y_NODE_T(y_NODE_T *node, int port){
  int af = node->addr.ss_family;
  if(af==AF_INET)
    ((struct sockaddr_in*)(&(node->addr)))->sin_port = htons(port);
  else if(af == AF_INET6)
    ((struct sockaddr_in6*)(&(node->addr)))->sin6_port = htons(port);
  
}
void set_str_port_y_NODE_T(y_NODE_T *node, char *str_port){
	int port = atoi(str_port);
	set_port_y_NODE_T(node, port);
}

const char * put_y_NODE_T_in_string(y_NODE_T *node, char * dst){
#if 0
				char host[NI_MAXHOST], service[NI_MAXSERV];
        int status = getnameinfo((struct sockaddr*)&(node->addr), node->addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status==0)
					return NULL;
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
         printf("getnameinfo: %s\n", gai_strerror(status));
	sprintf(dst,"%s:[%s]",host,service);
#endif
  char temp_addr[INET6_ADDRSTRLEN];	
	if(node->addr.ss_family == AF_INET){
		struct sockaddr_in *sinaddrv4 = ((struct sockaddr_in*)&(node->addr));
		if(inet_ntop(node->addr.ss_family, &(sinaddrv4->sin_addr),
          temp_addr, INET6_ADDRSTRLEN) == NULL){
			return NULL;
		}

  	sprintf(dst, "%s:[%d]",temp_addr, ntohs(sinaddrv4->sin_port ));
	}else if(node->addr.ss_family == AF_INET6){
		struct sockaddr_in6 *sinaddrv6 = ((struct sockaddr_in6*)&(node->addr));
		if(inet_ntop(node->addr.ss_family, &(sinaddrv6->sin6_addr),
          temp_addr, INET6_ADDRSTRLEN) == NULL){
			return NULL;
		}
		sprintf(dst, "%s:[%d]",temp_addr, ntohs(((struct sockaddr_in6*)&(node->addr))->sin6_port ));
	}
	return dst;
}

void * remove_node_from_nodes(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;
  struct main_list_y_NODE_T *nodes=argS->nodes;
  y_NODE_T node=argS->node;
  

  struct list_y_NODE_T * l_node = search_node_in_list_y_NODE_T(nodes, node);

  if(l_node) remove_index_from_list_y_NODE_T(nodes, l_node->index );

  return NULL;
  

}
void * add_node_to_nodes(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;
  struct main_list_y_NODE_T *nodes=argS->nodes;
  y_NODE_T node=argS->node;

  if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);


  return NULL;


}

void update_nodes(y_NODE_T node, struct main_list_y_NODE_T *nodes){
#if 0
void* update_nodes(void* arg)
  struct arg_update_nodes * argU=(struct arg_update_nodes*)arg;
  y_NODE_T node=argU->node;
  struct main_list_y_NODE_T *nodes=argU->nodes;
#endif


#if 0

  char host[NI_MAXHOST], service[NI_MAXSERV];
        int status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status)
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));

#endif
        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);

//  return NULL;
}

