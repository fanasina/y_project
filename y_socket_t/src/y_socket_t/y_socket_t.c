#include "y_socket_t/y_socket_t.h"

const int af_array[nbIpVersion]={AF_INET, AF_INET6};

struct y_string * create_y_ptr_STRING(const char *buf, size_t size){
	struct y_string *string=malloc(sizeof(struct y_string));
	string->buf=malloc(size+1);
	if(buf){
		strncpy(string->buf, buf, size);
		if(strlen(buf)>=size)
			string->buf[size]='\0';
	}
	string->size=size;
	return string;
}

GEN_LIST_ALL(y_ptr_STRING)

GEN_FUNC_PTR_LIST_FREE(y_ptr_STRING){
	free(arg->buf);
  free(arg);
}

size_t total_size_list_y_ptr_STRING(struct main_list_y_ptr_STRING *mstr){
	size_t total_size=0;
	for(struct list_y_ptr_STRING * local_current = mstr->begin_list; local_current; local_current = local_current->next){
		total_size += local_current->value->size;
	}
	printf("debug: totalsize :%ld\n",total_size);
	return total_size;
}

size_t copy_list_y_ptr_STRING_to_one_string(char **p_dst_str, struct main_list_y_ptr_STRING *mstr){
	if(*p_dst_str == NULL){
		*p_dst_str=malloc(total_size_list_y_ptr_STRING(mstr));
	}
	char * dst_str = *p_dst_str;
	char *cur_str = dst_str;
	size_t local_size=0;
 	size_t count_size=0;
	//for(move_current_to_begin_list_y_ptr_STRING(mstr); mstr->current_list; increment_list_y_ptr_STRING(mstr))
	for(struct list_y_ptr_STRING * local_current = mstr->begin_list; local_current; local_current = local_current->next){
		local_size = local_current->value->size;
//	printf("debug: local_size :%ld\n",local_size);
    for(size_t i=0; i<local_size; ++i){
			cur_str[i]=local_current->value->buf[i];
		}
		count_size += local_size;
//	printf("debug: countsize :%ld \n",count_size);
		cur_str = dst_str + count_size;
  }

	return count_size;

}

struct y_socket_t * y_socket_create(char *port, size_t size_fds, int nb_workers){
  struct y_socket_t *sock_temp=malloc(sizeof(struct y_socket_t));
	if(size_fds>=nbIpVersion)
		sock_temp->size_fds = size_fds;
	else
		sock_temp->size_fds = nbIpVersion;			
  sock_temp->fds = malloc(sock_temp->size_fds * sizeof(struct pollfd));

  sock_temp->port=port;
  sock_temp->nodes = create_var_list_y_NODE_T();
	sock_temp->mut_nodes = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(sock_temp->mut_nodes, NULL);
	sock_temp->go_on = 1;
	sock_temp->mut_go_on = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(sock_temp->mut_go_on, NULL);
  sock_temp->nb_workers = nb_workers;

  return sock_temp;
}
struct y_socket_t * y_socket_create_(char * port){
	return y_socket_create(port, 2, 2);
}
void y_socket_free(struct y_socket_t *socket){
  free(socket->fds);
  free_all_var_list_y_NODE_T(socket->nodes);
  pthread_mutex_destroy(socket->mut_nodes); 
  free(socket->mut_nodes); 
  pthread_mutex_destroy(socket->mut_go_on); 
  free(socket->mut_go_on); 
  free(socket);
}

int check_y_socket_go_on(struct y_socket_t *sock){
	pthread_mutex_lock(sock->mut_go_on);
	int ret = sock->go_on;
	pthread_mutex_unlock(sock->mut_go_on);
	return ret;
}

struct arg_update_nodes{

  y_NODE_T node; 
  struct main_list_y_NODE_T *nodes;
};
void update_nodes(y_NODE_T node, struct main_list_y_NODE_T *nodes){
#if 0
void* update_nodes(void* arg)
  struct arg_update_nodes * argU=(struct arg_update_nodes*)arg;
  y_NODE_T node=argU->node; 
  struct main_list_y_NODE_T *nodes=argU->nodes;
#endif

  char host[NI_MAXHOST], service[NI_MAXSERV];
				int status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status)
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));


        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);
        
//  return NULL;
} 

struct arg_send_file{
	struct pollfd *fds;
	struct main_list_y_NODE_T *nodes;
	char * filename;
};

//void y_socket_send_file_for_all_nodes(struct pollfd *fds, struct main_list_y_NODE_T *nodes, char * filename)
void* y_socket_send_file_for_all_nodes(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;

	struct pollfd *fds=argS->fds;
	struct main_list_y_NODE_T *nodes=argS->nodes;
	char * filename=argS->filename;

  char tempAddr[BUF_SIZE+1];
  int c_af;
//  char host[NI_MAXHOST], service[NI_MAXSERV];
  char buf_send[BUF_SIZE+1];
  int fd_file;
  int retread;
#if 0	
				int status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status)
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));


        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);
        
#endif        
       fd_file = open( filename , O_RDONLY);
       if(fd_file == -1){
         fprintf(stderr,"error opening file |%s| for reading\n",filename);
         return NULL;
       }
 				
			
       //memset(buf_send, 0, BUF_SIZE+1);
       while((retread = read(fd_file, buf_send, BUF_SIZE) ) > 0 ){
          buf_send[retread]='\0';
          //memset(msgRet, 0, BUF_SIZE + NI_MAXHOST + NI_MAXSERV + 100);
  //        sprintf(msgRet, "from %s:%s =%s",host, service, buf);
          
  //        len_msgRet = strlen(msgRet);
         ///printf("debug: sending response  %s :\n",buf_send);
          
					//FOR_LIST_FORM_BEGIN(y_NODE_T, nodes)
          for(struct list_y_NODE_T *local_list_current = nodes->begin_list; local_list_current; local_list_current=local_list_current->next ){
            //memset(tempAddr, 0, BUF_SIZE+1);
            c_af=(local_list_current->value).addr.ss_family;
            if(c_af==AF_INET){
               if(NULL == inet_ntop(c_af, 
                &(GET_IN_type_ADDR(&(local_list_current->value),)),
                tempAddr, BUF_SIZE/*(argSock->local_list_current->value).addr_len*/)){
                fprintf(stderr, "error inet_ntop v4\n");
              }
            }else if(c_af==AF_INET6){
               if(NULL == inet_ntop(c_af, 
                &(GET_IN_type_ADDR(&(local_list_current->value),6)),
                tempAddr, BUF_SIZE /*(argSock->local_list_current->value).addr_len*/)){
                fprintf(stderr, "error inet_ntop v6 :errno=%d\n",errno);
              }
            }
#if 0
						off_t offset = 0;  
						ssize_t ret_sendfile ;
						while((ret_sendfile = sendfile(fds[(c_af==AF_INET6)].fd ,fd_file, &offset, BUF_SIZE))>0){
								
						}
#endif
         /// printf("debug: destination %s :\n",tempAddr);

#if 	1				
            if(sendto(fds[(c_af==AF_INET6)].fd, 
              buf_send, retread,
              /*msgRet, len_msgRet,*/ 
              0, 
              (struct sockaddr*)&((local_list_current->value).addr), 
              (local_list_current->value).addr_len) != 
              retread
              /*len_msgRet*/
              ){
              fprintf(stderr, "Error sending response to %s\n",tempAddr);
            }else
              printf("debug: sending response to < %s >",tempAddr);
#endif 
          }
          //memset(buf_send, 0, BUF_SIZE+1);
        }

        close(fd_file);
        printf("debug: fd=%d closed: filename=%s\n",fd_file,filename);
  return NULL;
}

void  y_socket_get_fds(struct pollfd * fds, char * port, char * addrDistant){

  fds[v4].fd=-1; fds[v4].events = POLLIN;
  fds[v6].fd=-1; fds[v6].events = POLLIN;

  struct addrinfo hints, *result, *rp;
  int status;
//  ssize_t nread;
//  char buf[BUF_SIZE];
  
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC; // Allow all IPv4 and IPv6
  hints.ai_socktype = SOCK_DGRAM; // udp
  hints.ai_flags = AI_PASSIVE; // anyIP
  // 
  hints.ai_protocol = 0;
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  //status = getaddrinfo(NULL, argSock->port, &hints, &result);
  //status = getaddrinfo(argSock->addrDistant, argSock->port, &hints, &result);
  status = getaddrinfo(addrDistant, port, &hints, &result);
  if(status != 0){
    fprintf(stderr, "getaddrinfo :%s\n", gai_strerror(status));
    return ;//NULL;
  }
  int af, optValueV6 = 1;

  for(rp = result; rp != NULL; rp=rp->ai_next){
    for(af=v4; af<=v6; ++af){
      if((rp->ai_family == af_array[af]) && (fds[af].fd ==-1)){
        fds[af].fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if(fds[af].fd == -1)
          continue;
// android
#ifdef IPV6_V6ONLY 
        if(af == v6){
          if(setsockopt(fds[af].fd, IPPROTO_IPV6, IPV6_V6ONLY,
            &optValueV6, sizeof(optValueV6)) == -1){
            perror("error setsockopt v6 :");
            close(fds[af].fd);
            fds[af].fd = -1;
            continue;
          }
        }
#endif
        if(bind(fds[af].fd, rp->ai_addr, rp->ai_addrlen)==-1){
          close(fds[af].fd);
          fds[af].fd=-1;
        }
#if 0
int flags = fcntl(fds[af].fd, F_GETFL);
        flags |= O_NONBLOCK;
        fcntl(fds[af].fd, F_SETFL, flags);
#endif
         //set timer for recv_socket
#if 0
      static int timeout = TIMEOUT_MS;
      setsockopt(fds[af].fd, SOL_SOCKET, SO_RCVTIMEO,(char*)&timeout,sizeof(timeout));
#endif
      }
    }
  }

  freeaddrinfo(result);

}
struct arg_handler_{
  char *buf;
  struct pollfd *fds;
  y_NODE_T node;
  struct y_socket_t *sock;
  struct argWorker *argw ;
};

//void y_socket_handler_(char * buf, struct pollfd *fds, struct y_socket_t *sock) 
void* y_socket_handler_(void *arg){ 
  struct arg_handler_ *argH = (struct arg_handler_ *)arg;
  char *buf=argH->buf;
  struct pollfd *fds=argH->fds;
  struct y_socket_t *sock=argH->sock;
  struct argWorker *argw=argH->argw;

  struct main_list_y_NODE_T *nodes = sock->nodes;
  update_nodes(argH->node, nodes);

	printf("\n\n:::::::::::::::::::::::::::handler: : \n\n%s\n\n::::::::::::::::::::::::::\n",buf);
  if(strncmp(buf, "get", 3)==0){
    if(strncmp(buf+4,"file",4)==0){
      char *filename = buf + 9;
      struct arg_send_file *argS=malloc(sizeof(struct arg_send_file));
      argS->fds=fds;
      argS->nodes=nodes;
      argS->filename=filename;
      push_back_list_TYPE_PTR(argw->list_arg, argS);
      struct y_task_t task_send={
        .func=y_socket_send_file_for_all_nodes,
        .arg=argS,
        .status=TASK_PENDING,
      };
      push_tasQ(argw->argx->tasQ, task_send);
      //y_socket_send_file_for_all_nodes(fds, nodes,  filename) ;
    }
  }
  if(strncmp(buf, "update", 6)==0){
    if(strncmp(buf+7,"kill",4)==0){
      pthread_mutex_lock(sock->mut_go_on);
      sock->go_on = 0;
      pthread_mutex_unlock(sock->mut_go_on);
//      kill_all_workers(argw);
//      printf("debug: kill_all\n");
    } 
  }
}
void *y_socket_poll_fds(void *arg){
  struct y_socket_t * argSock = (struct y_socket_t*)arg;
// // //
  struct main_list_ptr_y_WORKER_T * workers = create_var_list_ptr_y_WORKER_T();
  struct main_list_TYPE_PTR * list_arg = create_var_list_TYPE_PTR();
  struct argExecTasQ *argx =  create_argExecTasQ();
  pthread_mutex_t *mut_workers = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(mut_workers, NULL);

  //int nb_workers=2;
  for(int i=0; i< argSock->nb_workers; ++i){

    struct y_worker_t *pw= create_ptr_y_WORKER_T(workers, list_arg, mut_workers, argx, GO_ON_WORKER, i);

    printf("debug:  - / -----  -- / ---  %d workers %ld created\n",argSock->nb_workers,(pw->arg->pworker->id));
//usleep(500);
  }

/// /// ///

  struct pollfd *fds = argSock->fds;

	y_socket_get_fds(fds, argSock->port, NULL);

  if((fds[v4].fd==-1) || (fds[v6].fd==-1)){
    fprintf(stderr, " v4 or v6 not listening, we leave!");
    return NULL;
  }
  //struct sockaddr_storage peer_addr;
  //socklen_t len_peer_addr;
  y_NODE_T node;
  int af, status;
  ssize_t nread;
  char buf[BUF_SIZE];
	struct main_list_y_ptr_STRING *m_str=create_var_list_y_ptr_STRING();

//	char *temp_all_buf=NULL;

//  char msgRet[BUF_SIZE + NI_MAXHOST + NI_MAXSERV + 100];
//  int len_msgRet;
  
  node.addr_len = sizeof(struct sockaddr_storage);
  
  for(;check_y_socket_go_on(argSock);){
    printf("poll: wait events\n");
    status = poll(fds, nbIpVersion, -1);
    if(status <= 0){
      if(status == -1 && errno != EINTR){
        perror("poll");
        return NULL;
      }
      continue;
    }
    for(af = v4; af<=v6;++af){
      if(fds[af].revents && POLLIN){
				remove_all_ptr_type_list_y_ptr_STRING(m_str);
        memset(buf, 0, BUF_SIZE);
				while((nread = recvfrom(fds[af].fd, buf, BUF_SIZE, 0,
        (struct sockaddr *)&(node.addr), &(node.addr_len))) == BUF_SIZE){
        	if(buf[nread-1]=='\n') buf[nread-1]='\0';
					buf[nread]='\0';
						y_ptr_STRING y_buf = create_y_ptr_STRING(buf, nread);
						push_back_list_y_ptr_STRING(m_str, y_buf);
						///printf("debug: push_back_list_y_ptr_STRING of <%s>\n",buf);

					
					//printf("debug: nread: %ld vs  BUF_SIZE :%d \n",nread, BUF_SIZE);
				}
						//printf("debug: out nread: %ld vs BUF_SIZE :%d \n",nread, BUF_SIZE);
				if(nread == -1)
         	fprintf(stderr,"error recvfrom\n");
				else if(nread >= 0 && nread < BUF_SIZE){
        	if(nread && buf[nread-1]=='\n') buf[nread-1]='\0';
					buf[nread]='\0';
          //printf("msg: %s\n",buf);
					y_ptr_STRING y_buf = create_y_ptr_STRING(buf, nread);
					push_back_list_y_ptr_STRING(m_str, y_buf);
					//printf("debug: out push_back_list_y_ptr_STRING of <%s>\n",buf);
				
        }

#if 0  
        struct arg_update_nodes *argUP_N=malloc(sizeof(struct arg_update_nodes));
        argUP_N->node=node;
        argUP_N->nodes=argSock->nodes;
        push_back_list_TYPE_PTR(list_arg, argUP_N);
        struct y_task_t task_update_node={
          .func=update_nodes,
          .arg=argUP_N,
          .status=TASK_PENDING,
        };
        push_tasQ(argx->tasQ, task_update_node);
#endif
        //update_nodes(node, argSock->nodes);
				/*
        if(temp_all_buf){
          free(temp_all_buf);
          temp_all_buf=NULL;
        }*/
				/*size_t total_buf = */ 
        char * temp_all_buf = NULL;
        copy_list_y_ptr_STRING_to_one_string(&temp_all_buf , m_str);
        push_back_list_TYPE_PTR(list_arg, temp_all_buf);
        struct arg_handler_ *ptr_argHandl = malloc(sizeof(struct arg_handler_));
          ptr_argHandl->buf = temp_all_buf;
          ptr_argHandl->fds=fds;
          ptr_argHandl->sock=argSock;
          ptr_argHandl->node=node;
          ptr_argHandl->argw=workers->begin_list->value->arg;
        
        push_back_list_TYPE_PTR(list_arg, ptr_argHandl);
        struct y_task_t task_handl = {
          .func=y_socket_handler_,
          .arg=ptr_argHandl,
          .status=TASK_PENDING,
        };
        push_tasQ(argx->tasQ, task_handl);
			///
				//y_socket_handler_(temp_all_buf, fds, argSock);

			///
      }
    }

#if 0
//    printf("nread = %ld: buf=%s\nlen_buf=%ld\ncmp=%d\n",nread,buf,strlen(buf),strncmp(buf,"SHUTDOWN SERVER",15));
      if(strncmp(buf,"SHUTDOWN SERVER",15) == 0){
        printf("leave poll thread, bye!\n");
     		break;
		 		//return NULL;
      }
#endif

  }



  purge_ptr_type_list_y_ptr_STRING(m_str);
/*
  if(temp_all_buf){
    free(temp_all_buf);
    temp_all_buf=NULL;
  }
*/
//// //// ////
  
  kill_all_workers(workers->begin_list->value->arg);
  printf("debug: kill all done\n");

///// ///// /////


	return NULL;
}
#define str(x) # x
#define xstr(x) str(x) 



