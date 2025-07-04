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
  else if(af == AF_INET6)
    ret = inet_pton(af, addrStr, (GET_IN_type_ADDR(&(node->addr), 6)));
  
  return ret;
  
}


void set_port_y_NODE_T(y_NODE_T *node, int port){
  int af = node->addr.ss_family;
  if(af==AF_INET)
    ((struct sockaddr_in*)(&(node->addr)))->sin_port = port;
  else if(af == AF_INET6)
    ((struct sockaddr_in6*)(&(node->addr)))->sin6_port = port;
  
}


