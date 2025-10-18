/*file: src/y_socket_t/y_socket_t.c */

#include "y_socket_t/y_socket_t.h"

//#include "y_socket_t/y_list_var_tool.h"
//#include "json_t/json_t.h"

const int af_array[nbIpVersion]={AF_INET, AF_INET6};

struct y_socket_t * y_socket_create(char *port, size_t size_fds, int nb_workers){ 
  struct y_socket_t *sock_temp=malloc(sizeof(struct y_socket_t));
	if(size_fds>=nbIpVersion+1)
		sock_temp->size_fds = size_fds;
	else
		sock_temp->size_fds = nbIpVersion+1;			
  sock_temp->fds = malloc(sock_temp->size_fds * sizeof(struct pollfd));

  sock_temp->port=port;
  sock_temp->nodes = create_var_list_y_NODE_T();
//	sock_temp->mut_nodes = malloc(sizeof(pthread_mutex_t));
//  pthread_mutex_init(sock_temp->mut_nodes, NULL);
	sock_temp->go_on = 1;
	sock_temp->mut_go_on = malloc(sizeof(pthread_mutex_t));
  pthread_mutex_init(sock_temp->mut_go_on, NULL);
  sock_temp->nb_workers = nb_workers;

  return sock_temp;
}
struct y_socket_t * y_socket_create_(char * port){ 
	return y_socket_create(port, 3, 2);
}
void y_socket_free(struct y_socket_t *socket){
  free(socket->fds);
  free_all_var_list_y_NODE_T(socket->nodes);
//  pthread_mutex_destroy(socket->mut_nodes); 
//  free(socket->mut_nodes); 
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
void __update_nodes(y_NODE_T node, struct main_list_y_NODE_T *nodes){
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

void __fileNameDateScore(char* filename, char * pre, char* post,size_t score){
 // char *filename=malloc(256);
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(filename,"%s%d%02d%02d_%02dh%02dm%02ds_%ld%s",pre, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,score,post);

  //return filename;
}



void  y_socket_get_fds(struct pollfd * fds, char * port, char * addrDistant){

  fds[v4].fd=-1; fds[v4].events = POLLIN;
  fds[v6].fd=-1; fds[v6].events = POLLIN;
  fds[2].fd=0; fds[2].events = POLLIN | POLLRDNORM | POLLRDBAND | POLLPRI ;

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
///debug print addr local : don't work really
#if 0
        else{
          char tempAddr[BUF_SIZE]={0};
          if(af_array[af]==AF_INET){
             if(NULL == inet_ntop(AF_INET, 
              &(GET_IN_type_ADDR(rp->ai_addr,)),
              tempAddr, BUF_SIZE)){
              fprintf(stderr, "error inet_ntop v4\n");
            }
          }else if(af_array[af]==AF_INET6){
             if(NULL == inet_ntop(AF_INET6, 
              &(GET_IN_type_ADDR(rp->ai_addr,6)),
              tempAddr, BUF_SIZE )){
              fprintf(stderr, "error inet_ntop v6 :errno=%d\n",errno);
            }
          }
          printf("\n\ndebug: ADDR_LOCAL v%d:%s\n\n", 2*af+4,tempAddr);
        }
#endif

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
  struct main_list_y_ptr_STRING *m_str;
  //struct main_list_y_ptr_VARIABLE *m_var;
  //char *buf;
  struct pollfd *fds;
  y_NODE_T node;
  struct y_socket_t *sock;
  struct argWorker *argw ;
  struct main_list_y_ptr_HEADER_T *m_head_l_t;
	struct main_list_y_ptr_HEADER_T *m_ok_head_l_t;
};

//void y_socket_handler_(char * buf, struct pollfd *fds, struct y_socket_t *sock) 
void* y_socket_handler_(void *arg){ 
  struct arg_handler_ *argH = (struct arg_handler_ *)arg;
  struct main_list_y_ptr_STRING *m_str =argH->m_str;
  struct pollfd *fds=argH->fds;
  struct y_socket_t *sock=argH->sock;
  struct argWorker *argw=argH->argw;

  struct main_list_y_NODE_T *nodes = sock->nodes;
  update_nodes(argH->node, nodes);

  char *buf_org = m_str->begin_list->value->buf;
	//printf("\n\n:::::::::::::::::::::::::::handler: : \n\n%s\n\n::::::::::::::::::::::::::\n",buf_org);
  struct js_value *js_header = create_js_value(buf_org, NULL);
  if(js_header && js_header->code_type == jstype_object){
    struct js_value *js_cmd = get_js_value_of_key("cmd", js_header );
    if(js_cmd && js_cmd->type.object.value->code_type == jstype_string){
      /**  */
      /*
      struct js_value *js_seq = get_js_value_of_key("seq", js_header );
      if(js_seq){
        size_t seq_local = (long)(js_seq->type.object.value->type.number);
        printf("debug:  \n HANDLER header  seq_local=%ld \n",seq_local);
      }else{
        printf("debug:  \n HANDLER header  no seq\n");
  
      }*/
      /* */
      char * buf = js_cmd->type.object.value->type.string; 
      size_t len_buf=strlen(buf);
      if(strncmp(buf, "get", 3)==0){
        if(len_buf > 4 && strncmp(buf+4,"file",4)==0){
          if(len_buf > 9){
            size_t len_filename = strlen(buf + 9);
            char *filename = malloc(len_filename+1);
            memcpy(filename, buf + 9, len_filename );
            filename[len_filename]='\0';
            //printf("debug: filename: %s \n\n",filename);
            struct arg_send_file *argS=malloc(sizeof(struct arg_send_file));
            argS->fds=fds;
            argS->nodes=nodes;
            argS->node=argH->node;
            argS->filename=filename;
            argS->m_ok_head_l_t=argH->m_ok_head_l_t;
            push_back_list_TYPE_PTR(argw->list_arg, argS);
            push_back_list_TYPE_PTR(argw->list_arg, filename);
            struct y_task_t task_send={
              //.func=y_socket_send_file_for_all_nodes,
              .func=y_socket_send_file_for_node,
              .arg=argS,
              .status=TASK_PENDING,
            };
            push_tasQ(argw->argx->tasQ, task_send);
            //y_socket_send_file_for_all_nodes(fds, nodes,  filename) ;
          }
        }
      }
      else if(len_buf >7 && strncmp(buf, "update", 6)==0){
        if(strncmp(buf+7,"kill",4)==0){
          pthread_mutex_lock(sock->mut_go_on);
          sock->go_on = 0;
          pthread_mutex_unlock(sock->mut_go_on);
    //      kill_all_workers(argw);
    //      printf("debug: kill_all\n");
        }else if(strncmp(buf+7,"cleanup",7)==0){
          remove_all_ptr_type_list_y_ptr_HEADER_T(argH->m_ok_head_l_t);
          remove_all_ptr_type_list_y_ptr_HEADER_T(argH->m_head_l_t);
          //      printf("debug: kill_all\n");
        }else if(strncmp(buf+7,"file nodes",10)==0){
           if(export_nodes_to_file(".file_nodes_name", nodes)==-1){
              fprintf(stderr, "error export_nodes_to_file\n");
           }

    //      kill_all_workers(argw);
    //      printf("debug: kill_all\n");
        }else if(strncmp(buf+7,"remove node",11)==0){
          if(len_buf>19 && set_addr_y_NODE_T_from_str_addr(&(argH->node), buf + 19)){
            set_port_y_NODE_T_from_str_port(&(argH->node), argH->sock->port);
          
            struct arg_send_file *argS=malloc(sizeof(struct arg_send_file));
            argS->fds=fds;
            argS->nodes=nodes;
            argS->node=argH->node;
            argS->filename=NULL;
					  argS->m_ok_head_l_t = argH->m_ok_head_l_t;
            push_back_list_TYPE_PTR(argw->list_arg, argS);
            struct y_task_t task_send={
            //.func=y_socket_send_file_for_all_nodes,
            .func=remove_node_from_nodes,
            .arg=argS,
            .status=TASK_PENDING,
          };
          push_tasQ(argw->argx->tasQ, task_send);
          }
        }else if(strncmp(buf+7,"add node",8)==0){
          if(len_buf >16 && set_addr_y_NODE_T_from_str_addr(&(argH->node), buf + 16)){
            set_port_y_NODE_T_from_str_port(&(argH->node), argH->sock->port);
          
            struct arg_send_file *argS=malloc(sizeof(struct arg_send_file));
            argS->fds=fds;
            argS->nodes=nodes;
            argS->node=argH->node;
            argS->filename=NULL;
					  argS->m_ok_head_l_t = argH->m_ok_head_l_t;
            push_back_list_TYPE_PTR(argw->list_arg, argS);
            struct y_task_t task_send={
            //.func=y_socket_send_file_for_all_nodes,
            .func=add_node_to_nodes,
            .arg=argS,
            .status=TASK_PENDING,
          };
          push_tasQ(argw->argx->tasQ, task_send);
          }
        }

      }
      else if(len_buf > 5 && strncmp(buf, "post", 4)==0){
        if(strncmp(buf+5,"file",4)==0){
          if(len_buf > 10){
            char *filename = buf+10;
            receve_from_node(fds, argH->m_head_l_t, /*argH->m_var,*/ m_str,argH->node, filename );
            m_str = NULL;
          }
        }else if(strncmp(buf+5,"ok",2)==0){
					if(len_buf>8){
            char *nameid = buf+8;
					  y_append_to_ok_header_l_(argH->m_ok_head_l_t,nameid );
          }
				}


      }
    
    }

  }
  free_js_value(js_header);
  if(m_str){
    purge_ptr_type_list_y_ptr_STRING(m_str);
    printf("debug: purge_ptr_type_list_y_ptr_STRING in y_socket_handler_\n");
  }
  

  return NULL;
}


void handle_buf_socket_rec(struct main_list_y_ptr_HEADER_T *m_ok_head_l_t, struct main_list_y_ptr_HEADER_T *m_head_l_t, /*struct main_list_y_ptr_VARIABLE *m_var,*/ struct main_list_y_ptr_STRING *m_str, y_NODE_T node, struct main_list_ptr_y_WORKER_T * workers, struct argExecTasQ *argx, struct main_list_TYPE_PTR * list_arg, void * arg){
  struct y_socket_t * argSock = (struct y_socket_t*)arg;
  struct pollfd *fds = argSock->fds;
  
  struct js_value *js_header = create_js_value(m_str->begin_list->value->buf, NULL);
  if(js_header && js_header->code_type == jstype_object){
    struct js_value *js_cmd = get_js_value_of_key("cmd", js_header );
    if(js_cmd && js_cmd->type.object.value->code_type == jstype_string){
      if(strncmp(js_cmd->type.object.value->type.string,"update standby",14)==0){
        //pthread_mutex_lock(sock->mut_go_on);
        //sock->go_on = 0;
        //pthread_mutex_unlock(sock->mut_go_on);
        standby_all_workers(workers->begin_list->value->arg);
  //      printf("debug: kill_all\n");
      }
      else if(strncmp(js_cmd->type.object.value->type.string,"update wakeup",13)==0){
        //pthread_mutex_lock(sock->mut_go_on);
        //sock->go_on = 0;
        //pthread_mutex_unlock(sock->mut_go_on);
        wakeup_all_workers(workers->begin_list->value->arg);
  //      printf("debug: kill_all\n");
      }
      else{
        struct arg_handler_ *ptr_argHandl = malloc(sizeof(struct arg_handler_));
          ptr_argHandl->m_str = m_str;
          //ptr_argHandl->m_var = m_var;
          ptr_argHandl->fds=fds;
          ptr_argHandl->sock=argSock;
          ptr_argHandl->node=node;
          ptr_argHandl->argw=workers->begin_list->value->arg;
          ptr_argHandl->m_head_l_t=m_head_l_t;
          ptr_argHandl->m_ok_head_l_t=m_ok_head_l_t;
        
        push_back_list_TYPE_PTR(list_arg, ptr_argHandl);
        struct y_task_t task_handl = {
          .func=y_socket_handler_,
          .arg=ptr_argHandl,
          .status=TASK_PENDING,
        };
        push_tasQ(argx->tasQ, task_handl);
        m_str=NULL;
      }

    }
  }else{

  }

   free_js_value(js_header);  
   if(m_str){
      purge_ptr_type_list_y_ptr_STRING(m_str);

      printf("debug: m_str!=NULL -> purge_ptr_type_list_y_ptr_STRING in handle_buf_socket_rec done\n");
    }
}

void *y_socket_poll_fds(void *arg){
  usage_cmdl();
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
  ssize_t nread, buf_len;
  char buf[BUF_SIZE+1];
	struct main_list_y_ptr_STRING *m_str=NULL;//=create_var_list_y_ptr_STRING();
  struct main_list_y_ptr_HEADER_T *m_head_l_t = create_var_list_y_ptr_HEADER_T();
  struct main_list_y_ptr_HEADER_T *m_ok_head_l_t = create_var_list_y_ptr_HEADER_T();
  //struct main_list_y_ptr_VARIABLE *m_var = create_var_list_y_ptr_VARIABLE();

//	char *temp_all_buf=NULL;

//  char msgRet[BUF_SIZE + NI_MAXHOST + NI_MAXSERV + 100];
//  int len_msgRet;
// I had to initialize all attribute of addr to avoid error uninitialized value with valgrind, for example "sin6_flowinfo" in sockaddr_in6
 	memset(&(node.addr), 0, sizeof(struct sockaddr_storage)); 
  //size_t len_sockaddr_storage = sizeof(struct sockaddr_storage);
  node.addr_len = sizeof(struct sockaddr_storage);
  node.local_addr = 0;/* not local addr by default */
//  printf("debug: ------ //// node.addr_len = %d\n",node.addr_len); 
  
  for(;check_y_socket_go_on(argSock);){
    printf("poll: wait events\n");
    status = poll(fds, nbIpVersion + 1, -1);
    if(status <= 0){
      if(status == -1 && errno != EINTR){
        perror("poll");
        return NULL;
      }
      continue;
    }
    for(af = v4; af<=v6;++af){
      if(fds[af].revents && POLLIN){
				//remove_all_ptr_type_list_y_ptr_STRING(m_str);
        if(m_str == NULL)
          m_str=create_var_list_y_ptr_STRING();
        memset(buf, 0, BUF_SIZE+1);
        
				while((nread = recvfrom(fds[af].fd, buf, BUF_SIZE, 0,
        (struct sockaddr *)&(node.addr), &(node.addr_len))) == BUF_SIZE){
//  printf("debug: ------ //RCVFR// node.addr_len = %d\n",node.addr_len); 
        	
          //if(buf[nread-1]=='\n') buf[nread-1]='\0';
					buf[nread]='\0';
          
						y_ptr_STRING y_buf = create_y_ptr_STRING(buf, nread);
						push_back_list_y_ptr_STRING(m_str, y_buf);
						//printf("debug: push_back_list_y_ptr_STRING of <%s>\n",buf);

					
        //memset(buf, 0, BUF_SIZE+1);
					//printf("debug: nread: %ld vs  BUF_SIZE :%d \n",nread, BUF_SIZE);
				}
						//printf("debug: out nread: %ld vs BUF_SIZE :%d \n",nread, BUF_SIZE);
				if(nread == -1)
         	fprintf(stderr,"error recvfrom\n");
        else if(nread >= 0 && nread < BUF_SIZE){
        	//if(nread && buf[nread-1]=='\n') buf[nread-1]='\0';
					buf[nread]='\0';
          //printf("msg: %s\n",buf);
					y_ptr_STRING y_buf = create_y_ptr_STRING(buf, nread);
					push_back_list_y_ptr_STRING(m_str, y_buf);
					//printf("debug: out push_back_list_y_ptr_STRING of <%s>\n",buf);
				
        }

			///
      }
      if(check_y_socket_go_on(argSock) && m_str){
				///printf("debug:  call handle_buf_socket_rec\n");
        handle_buf_socket_rec(m_ok_head_l_t,m_head_l_t, /*m_var,*/ m_str, node, workers, argx, list_arg, arg);
      
        m_str=NULL;
      }
    }
		// stdin poll
		if(fds[2].revents){// && POLLIN
      //pollEventRec = fds[1].events;
    
			//handle_input_kbd(arg);	
//printf("fd = %d\n event=%d\n\n",fds[1].fd,pollEventRec);
      //fds[1].events = 0;
      
      puts("Saisie du message : ");
      memset(buf, 0, sizeof buf);
      //scanf(" %"xstr(BUF_SIZE)"[^\n]%*c", buf);
      buf_len = read(0,buf,BUF_SIZE);
      printf("message saisi : %s\n len = %ld\n",buf, buf_len);
//      handle_input_kbd(buf, buf_len ,arg);
#if 1
			if(buf_len>6){
#if 1
					char cmd[BUF_SIZE], dst_addr[BUF_SIZE];//, msg_buf[BUF_SIZE];
					int index_buf=0, index_str=0;
					for(; buf[index_buf]!=' '; ++index_buf){
						cmd[index_str++]=buf[index_buf];
					}
					cmd[index_str]='\0';
				///printf("debug : index_str= %d; cmd=[%s]\n",index_str, cmd);
					
					index_str=0;
					while((index_buf < buf_len) && (buf[index_buf]==' ')){++index_buf;}
					for(; (index_buf < buf_len) && (buf[index_buf]!=' '); ++index_buf){
						dst_addr[index_str++]=buf[index_buf];
					}
					dst_addr[index_str]='\0';
					//while(buf[index_buf]==' '){++index_buf;}
					while((index_buf < buf_len) && (buf[index_buf]==' ')){++index_buf;}
					/*index_str=0;
					for(; buf[index_buf]!='\n'; ++index_buf)
						msg_buf[index_str++]=buf[index_buf];
					msg_buf[index_str++]='\0';*/

				///printf("debug : index_str=%d, dst_addr=[%s]\n", index_str, dst_addr);
#endif

		
			if(/*check_y_socket_go_on(argSock) &&*/ strncmp(cmd, "sendto", 6)==0){
				///printf("debug : sendto match, dst_addr=[%s]\n", dst_addr);
        if(strcmp(dst_addr, "all" ) == 0){
          struct arg_send_file *argS = malloc(sizeof(struct arg_send_file));
          argS->fds=fds;
          argS->nodes=argSock->nodes;
          argS->node=node;
          argS->filename=malloc(buf_len-index_buf+1); /* put here message to send for all */
          memcpy(argS->filename, buf+index_buf, buf_len-index_buf);
          argS->filename[buf_len-index_buf] = '\0';
          argS->m_ok_head_l_t=m_ok_head_l_t; 
        
          push_back_list_TYPE_PTR(list_arg, argS);
          push_back_list_TYPE_PTR(list_arg, argS->filename);
          struct y_task_t task_handl = {
            .func=y_send_buf_for_all_,
            .arg=argS,
            .status=TASK_PENDING,
          };
          push_tasQ(argx->tasQ, task_handl);
      

        }else if(strcmp(dst_addr, "other" ) == 0){
          struct arg_send_file *argS = malloc(sizeof(struct arg_send_file));
          argS->fds=fds;
          argS->nodes=argSock->nodes;
          argS->node=node;
          argS->filename=malloc(buf_len-index_buf+1); /* put here message to send for all */
          memcpy(argS->filename, buf+index_buf, buf_len-index_buf);
          argS->filename[buf_len-index_buf] = '\0';
          argS->m_ok_head_l_t=m_ok_head_l_t; 
        
          push_back_list_TYPE_PTR(list_arg, argS);
          push_back_list_TYPE_PTR(list_arg, argS->filename);
          struct y_task_t task_handl = {
            .func=y_send_buf_for_other_,
            .arg=argS,
            .status=TASK_PENDING,
          };
          push_tasQ(argx->tasQ, task_handl);
      

        }
        else if(set_addr_y_NODE_T_from_str_addr(&node, dst_addr)){
					///printf("debug : set_addr_y_NODE_T done\n");
					set_port_y_NODE_T_from_str_port(&node, argSock->port);
					update_nodes(node, argSock->nodes);
					af=(node.addr.ss_family == AF_INET6);

					
					///printf("debug : af = AF_INET=%d, af = AF_INET6=%d, vs  af=[%d]\n",AF_INET, AF_INET6, af);

          //node.addr_len = sizeof(struct sockaddr_storage);
          //node.addr_len = sizeof(node.addr); 
					if(sendto(fds[af].fd, buf+index_buf  , buf_len-index_buf, 0,
          	(struct sockaddr*)(&(node.addr)), node.addr_len
            ) == -1){
      			fprintf(stderr,"message erreur sendto : %s, error :%d\n\n",buf,errno);
          	perror("sendto:");
          	close(fds[af].fd);
          	return NULL;
        	}
          /*
					char dddnn[56];
				  put_y_NODE_T_in_string(&node, dddnn);
      		printf("debug: sendto : %s: msg :%s\n\n",dddnn,  buf+index_buf);
          */

				}
			}
		}
#endif

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


  if(m_str){
    purge_ptr_type_list_y_ptr_STRING(m_str);
    
    printf("debug: m_str!=NULL -> purge_ptr_type_list_y_ptr_STRING done\n");
  }
#if 0
  if(m_var){
    purge_ptr_type_list_y_ptr_VARIABLE(m_var);
    
    printf("debug: m_var!=NULL -> purge_ptr_type_list_y_ptr_VARIABLE done\n");
  }
#endif

/*
  if(temp_all_buf){
    free(temp_all_buf);
    temp_all_buf=NULL;
  }
*/
//// //// ////
  
  kill_all_workers(workers->begin_list->value->arg);
  printf("debug: kill all done\n");
  purge_ptr_type_list_y_ptr_HEADER_T(m_head_l_t);
  printf("debug: purge_ptr_type_list_y_ptr_HEADER_T m_head_l_t done\n");
  purge_ptr_type_list_y_ptr_HEADER_T(m_ok_head_l_t);
  printf("debug: purge_ptr_type_list_y_ptr_HEADER_T m_ok_head_l_t done\n");
///// ///// /////


	return NULL;
}
#define str(x) # x
#define xstr(x) str(x) 



