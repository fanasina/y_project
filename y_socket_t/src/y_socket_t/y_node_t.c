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
#if 0
  char addrA[65];
  char addrB[65];
  set_addr_str_from_node(addrA, nodeA);
  set_addr_str_from_node(addrB, nodeB);
  printf("nodeAstr=%s nodeBstr=%s ",addrA,addrB);
//  return strcmp(addrA,addrB);
#endif
  int ret=0;

  //ret = nodeA.addr_len - nodeB.addr_len;
  //if(ret == 0){
    
    ///printf("debug: ++++++++++++ lenA=%d, lenB=%d\n", nodeA.addr_len , nodeB.addr_len);
    ret = nodeA.addr.ss_family - nodeB.addr.ss_family;
    if(ret == 0){
      if(nodeA.addr.ss_family == AF_INET){
        //ret = memcmp((struct sockaddr_in*)&(nodeA.addr), (struct sockaddr_in*)&(nodeB.addr), sizeof(struct sockaddr_in));
        ret = ((struct sockaddr_in*)&(nodeA.addr))->sin_port - ((struct sockaddr_in*)&(nodeB.addr))->sin_port;
        if(ret==0){
          //ret = GET_IN_type_ADDR(&(nodeA.addr),) - GET_IN_type_ADDR(&(nodeB.addr),);
          ret = ((struct sockaddr_in*)&(nodeA.addr))->sin_addr.s_addr - ((struct sockaddr_in*)&(nodeB.addr))->sin_addr.s_addr; 
          //printf("debug --->ret=%d; nodeAint=%d vs nodeBint=%d",ret, ((struct sockaddr_in*)&(nodeA.addr))->sin_addr.s_addr , ((struct sockaddr_in*)&(nodeB.addr))->sin_addr.s_addr);
        }
      }else
      if(nodeA.addr.ss_family == AF_INET6){
        ret = ((struct sockaddr_in6*)&(nodeA.addr))->sin6_port - ((struct sockaddr_in6*)&(nodeB.addr))->sin6_port;
        if(ret ==0)
          //ret = memcmp((struct sockaddr_in6*)&(nodeA.addr), (struct sockaddr_in6*)&(nodeB.addr), sizeof(struct sockaddr_in6));
          //ret = memcmp(GET_IN_type_ADDR(&(nodeA.addr),6), GET_IN_type_ADDR(&(nodeB.addr),6), 8);
          ret = memcmp(((struct sockaddr_in6*)&(nodeA.addr))->sin6_addr.s6_addr , ((struct sockaddr_in6*)&(nodeB.addr))->sin6_addr.s6_addr, 8); 
      }
    }
  //}
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
  return search_first_occ_from_end_in_list_y_NODE_T(listNodes, node, y_NODE_T_cmp);
  //return search_first_occ_from_begin_in_list_y_NODE_T(listNodes, node, y_NODE_T_cmp);
}

int set_addr_y_NODE_T_from_str_addr(y_NODE_T *node, char * addrStr){
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
  if(af==AF_INET){
    ret = inet_pton(af, addrStr, &(GET_IN_type_ADDR(&(node->addr),)));
    //node->addr_len = sizeof(struct sockaddr_in);
  }else if(af == AF_INET6){
		//((struct sockaddr_in6*)(&(node->addr)))->sin6_flowinfo = 0; 
		ret = inet_pton(af, addrStr, (GET_IN_type_ADDR(&(node->addr), 6)));
    //node->addr_len = sizeof(struct sockaddr_in6);
  
	}
  node->addr_len = sizeof(struct sockaddr_storage);
  if(strcmp(addrStr,"::1")==0){
    node->local_addr=1;
  }else{
    node->local_addr=0;
  }
  return ret;
  
}


void set_port_y_NODE_T_from_int_port(y_NODE_T *node, int port){
  int af = node->addr.ss_family;
  if(af==AF_INET)
    ((struct sockaddr_in*)(&(node->addr)))->sin_port = htons(port);
  else if(af == AF_INET6)
    ((struct sockaddr_in6*)(&(node->addr)))->sin6_port = htons(port);
  
}
void set_port_y_NODE_T_from_str_port(y_NODE_T *node, char *str_port){
	int port = atoi(str_port);
	set_port_y_NODE_T_from_int_port(node, port);
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
  char buffer_addr[INET6_ADDRSTRLEN];	
	if(node->addr.ss_family == AF_INET){
		struct sockaddr_in *sinaddrv4 = ((struct sockaddr_in*)&(node->addr));
		if(inet_ntop(node->addr.ss_family, &(sinaddrv4->sin_addr),
          buffer_addr, INET6_ADDRSTRLEN) == NULL){
			return NULL;
		}

  	sprintf(dst, "%s:[%d]",buffer_addr, ntohs(sinaddrv4->sin_port ));
	}else if(node->addr.ss_family == AF_INET6){
		struct sockaddr_in6 *sinaddrv6 = ((struct sockaddr_in6*)&(node->addr));
		if(inet_ntop(node->addr.ss_family, &(sinaddrv6->sin6_addr),
          buffer_addr, INET6_ADDRSTRLEN) == NULL){
			return NULL;
		}
		sprintf(dst, "%s:[%d]",buffer_addr, ntohs(((struct sockaddr_in6*)&(node->addr))->sin6_port ));
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
         //         node.local_addr = 0;
        //struct sockaddr_in6 local6;
        //inet_pton(AF_INET6, "::1", &local6);
        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node)){
  struct ifaddrs *if_addr=NULL;
  getifaddrs(&if_addr);
          int c_af = node.addr.ss_family;
          for(struct ifaddrs *cur_ifa = if_addr; cur_ifa; cur_ifa=cur_ifa->ifa_next){
            if( c_af == cur_ifa->ifa_addr->sa_family){
              if(c_af==AF_INET){
                if(((struct sockaddr_in*)&(node.addr))->sin_addr.s_addr == ((struct sockaddr_in*)(cur_ifa->ifa_addr))->sin_addr.s_addr ){
                  node.local_addr = 1;
                  break;
                } 
              }else if(c_af==AF_INET6){
                if(
                  //(memcmp(((struct sockaddr_in6*)&(node.addr))->sin6_addr.s6_addr , local6.sin6_addr.s6_addr, 8)==0)||
                  (memcmp(((struct sockaddr_in6*)&(node.addr))->sin6_addr.s6_addr , ((struct sockaddr_in6*)&(cur_ifa->ifa_addr))->sin6_addr.s6_addr, 8)==0)
                  ){
                  node.local_addr = 1;
                  break;
                } 
                /*char tempAddr[65];
                set_addr_str_from_node(tempAddr,node);
                if(strcmp(tempAddr,"::1")==0){
                  node.local_addr = 1;
                  break;
                }*/
              }
            }
          }
          push_back_list_y_NODE_T(nodes, node);
            printf("debug: // /// // // update_nodes local_addr=%d\n",node.local_addr );
  if(if_addr) freeifaddrs(if_addr);
        }


//  return NULL;
}

size_t set_addr_str_from_node(char *tempAddr, y_NODE_T node) {
      int c_af=(node).addr.ss_family;
    
            if(c_af==AF_INET){
               if(NULL == inet_ntop(c_af,
                &(GET_IN_type_ADDR(&(node),)),
                tempAddr,  INET6_ADDRSTRLEN/*(argSock->local_list_current->value).addr_len*/)){
                fprintf(stderr, "error inet_ntop v4\n");
              }
            }else if(c_af==AF_INET6){
               if(NULL == inet_ntop(c_af,
                &(GET_IN_type_ADDR(&(node),6)),
                tempAddr,  INET6_ADDRSTRLEN /* node.addr_len BUF_SIZE (argSock->local_list_current->value).addr_len*/)){
                fprintf(stderr, "error inet_ntop v6 :errno=%d\n",errno);
              }
            }
    
            size_t ret_len = strlen(tempAddr);
            ///printf("debug: c_af=%d, ret_len=%ld, addr=%s\n",c_af, ret_len,tempAddr);
            return ret_len;
}


int export_nodes_to_file(char * file_nodes_name, struct main_list_y_NODE_T *nodes){
  int fd_file ;
  if((fd_file = open(file_nodes_name, O_WRONLY | O_CREAT | O_TRUNC,
   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1){
   fprintf(stderr,"erreur write %s\n",file_nodes_name);
   return -1;
  }

  char buffer_addr[65];
  struct list_y_NODE_T *tmp_nd=nodes->begin_list;
  int len_addr=0;
  while(tmp_nd){
   len_addr=set_addr_str_from_node(buffer_addr,tmp_nd->value); 
   buffer_addr[len_addr++]='\n';
   buffer_addr[len_addr]='\0';
   write(fd_file, buffer_addr, len_addr);
   ///printf("debug: [#%d] buffer_addr=|%s|[index:%ld]\n",len_addr,buffer_addr,tmp_nd->index);
   tmp_nd=tmp_nd->next;
   memset(buffer_addr,0,65);
  }
  close(fd_file);
  return fd_file; 
}

int import_nodes_from_file(char * file_nodes_name, int int_port, struct main_list_y_NODE_T *nodes){
  int fd_file ;
  fd_file = open( file_nodes_name , O_RDONLY);
       if(fd_file == -1){
         fprintf(stderr,"error opening file |%s| for reading\n",file_nodes_name);
         return -1;
       }
#define SIZE_ADDR_LOC 28
 
  char buffer_addr[SIZE_ADDR_LOC+1], current_addr[SIZE_ADDR_LOC+1],*begin_addr,*cur_Str=NULL;
  int retread;
  int offset=0;
    memset(buffer_addr,0,SIZE_ADDR_LOC+1);
    //memset(current_addr,0,SIZE_ADDR_LOC+1);
  while((retread = read(fd_file, buffer_addr+offset, SIZE_ADDR_LOC-offset) ) > 0 ){
    buffer_addr[offset+retread]='\0';
    //printf("debug: --++buffer_addr:|%s|, retread #%d#\n",buffer_addr,retread);
    begin_addr=buffer_addr;
    for(cur_Str=buffer_addr;*cur_Str ;++cur_Str){
      if(*cur_Str=='\n'){
        memset(current_addr,0,SIZE_ADDR_LOC+1);
        strncpy(current_addr,begin_addr,cur_Str-begin_addr);
    //printf("debug: current_addr:[%s]\n",current_addr);
        y_NODE_T node;
        if(set_addr_y_NODE_T_from_str_addr(&node,current_addr)){
          set_port_y_NODE_T_from_int_port(&node, int_port);
          update_nodes(node,nodes);  
          begin_addr = cur_Str+1;
        }else{

    //printf("debug: something wrong, perhaps format!! current_addr:[%s]\n",current_addr);
        }
      }
    }
    offset=cur_Str-begin_addr;
    //memset(current_addr,0,SIZE_ADDR_LOC+1);
    //strncpy(current_addr,begin_addr,offset);
    strncpy(buffer_addr,begin_addr,offset);
    //printf("debug: offset=%d current_addr:[%s]\n",offset,current_addr);
    //memcpy(buffer_addr,current_addr,SIZE_ADDR_LOC+1);
    //printf("debug: **buffer_addr:|%s|, strlen #%ld#\n",buffer_addr,strlen(buffer_addr));

  }
    //printf("debug: >>> buffer_addr:|%s|\n",buffer_addr);
    if(offset>1){
      y_NODE_T node;
      if(set_addr_y_NODE_T_from_str_addr(&node,buffer_addr)){
        set_port_y_NODE_T_from_int_port(&node, int_port);
        update_nodes(node,nodes); 
      }
    }

  close(fd_file);
  return fd_file; 
}
