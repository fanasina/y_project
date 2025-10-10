/*file: src/y_socket_t/y_socket_t.c */

#include "y_socket_t/y_socket_t.h"

//#include "y_socket_t/y_list_string.h"
//#include "json_t/json_t.h"

const int af_array[nbIpVersion]={AF_INET, AF_INET6};

/* y_ptr_STRING */
#if 0 
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

#endif /* y_ptr_STRING */

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


#if 0

struct arg_send_file{
	struct pollfd *fds;
	struct main_list_y_NODE_T *nodes;
	char * filename;
};

#define TEMP_ADDR 1

//void y_socket_send_file_for_all_nodes(struct pollfd *fds, struct main_list_y_NODE_T *nodes, char * filename)
void* y_socket_send_file_for_all_nodes(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;

	struct pollfd *fds=argS->fds;
	struct main_list_y_NODE_T *nodes=argS->nodes;
	char * filename=argS->filename;
#if TEMP_ADDR
  char tempAddr[BUF_SIZE+1];
#endif
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
#if TEMP_ADDR
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
#endif
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
#if TEMP_ADDR
							fprintf(stderr, "Error sending response to %s\n",tempAddr);
#endif
						}else{
#if TEMP_ADDR
							printf("debug: sending response to < %s >",tempAddr);
#endif
						}
          }
#endif 
          //memset(buf_send, 0, BUF_SIZE+1);
        }

        close(fd_file);
        printf("debug: fd=%d closed: filename=%s\n",fd_file,filename);
  return NULL;
}
#endif 


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
        }else{
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
      struct js_value *js_seq = get_js_value_of_key("seq", js_header );
      if(js_seq){
        size_t seq_local = (long)(js_seq->type.object.value->type.number);
        printf("debug:  \n HANDLER header  seq_local=%ld \n",seq_local);
      }else{
        printf("debug:  \n HANDLER header  no seq\n");
  
      }
      /* */
      char * buf = js_cmd->type.object.value->type.string; 

      if(strncmp(buf, "get", 3)==0){
        if(strncmp(buf+4,"file",4)==0){
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
      else if(strncmp(buf, "update", 6)==0){
        if(strncmp(buf+7,"kill",4)==0){
          pthread_mutex_lock(sock->mut_go_on);
          sock->go_on = 0;
          pthread_mutex_unlock(sock->mut_go_on);
    //      kill_all_workers(argw);
    //      printf("debug: kill_all\n");
        }

      }
      else if(strncmp(buf, "post", 4)==0){
        if(strncmp(buf+5,"file",4)==0){
          char *filename = buf+10;
          //index_f=strcpy(filename, buf + 10);
          /*
					int index_f = strlen(filename);
          printf("debug: receve_from_node : file: %s\n",filename);
          for(--index_f; index_f>=0;--index_f){
            if(filename[index_f]=='/') {
              ++index_f;
              break;
            }
          }*/

#if 0
          //struct list_y_ptr_STRING * last_record_=NULL;
          for(struct list_y_ptr_STRING * local_current = m_str->begin_list; local_current; local_current = local_current->next){
            char *buf_loc = local_current->value->buf;
            struct js_value * js_header_v = create_js_value(buf_loc,NULL);
            //struct js_value *js_cmd_v = get_js_value_of_key("cmd", js_header_v );
            //printf("debug: index=[%ld] \n BBBBBEGINNNNNN file ***\n%s\n EEEENDDDDD\n",local_current->index,buf_loc);
            printf("debug: index=[%ld] \n",local_current->index);
            if(js_header_v){

            
              struct js_value *js_seq_v = get_js_value_of_key("seq", js_header_v );
              if(js_seq_v){  
                if(js_seq_v->type.object.value->code_type == jstype_number){
                  printf("debug: receve : \n################################# seq : %ld ###################################\n",(long)(js_seq_v->type.object.value->type.number));
                }
                else{
                  printf("debug:  \n SSSSSSSSSSSSSSSEEEEEEEEEEEEEEQQQQQQQQQQQQQ type:%d \n",js_seq_v->type.object.value->code_type);

                }
              }else{

                  printf("debug:  \n NNNNNNNNNNNNNNNNOOOOOOOOOOOOOSSSSSSSSSSSSSSSEEEEEEEEEEEEEEQQQQQQQQQQQQQ :type header : %d \n",js_header_v->code_type);
              }
              struct js_value *js_eof_v = get_js_value_of_key("EOF", js_header_v );
              if(js_eof_v){
                printf("debug:  \n****************************end of file ***\n%s\n**********************************\n",buf_loc);
              }
              else{
                //printf("debug:  \n*******************************\n%s\n**********************************\n",buf_loc+js_org_str_length(js_header_v));
              } 
              free_js_value(js_header_v);
            }else{
              printf("\ndebug NULLL JS___HHHEADER_V \n"); 
            }
          }


#else 
        struct main_list_y_ptr_HEADER_T *m_head_l_t = argH->m_head_l_t;
        //char srcAddr[BUF_SIZE];
        //set_tempAddr_from_node(srcAddr, argH->node);
        receve_from_node(fds, m_head_l_t, m_str,argH->node/* srcAddr*/, filename /*+ index_f*/);
        m_str = NULL;
#endif 
         /*
          pthread_mutex_lock(sock->mut_go_on);
          sock->go_on = 0;
          pthread_mutex_unlock(sock->mut_go_on);
          */
    //      kill_all_workers(argw);
    //      printf("debug: kill_all\n");
        }else if(strncmp(buf+5,"ok",2)==0){
					char *nameid = buf+8;
					y_append_to_ok_header_l_(argH->m_ok_head_l_t,nameid );
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

#if 0
void handle_input_kbd(char *buf, ssize_t buf_len ,void *arg){
    struct y_socket_t * argSock = (struct y_socket_t*)arg;
    struct pollfd *fds = argSock->fds;
    y_NODE_T node;
    int af, status;
    /*
    ssize_t nread, buf_len;
    char buf[BUF_SIZE];
    //struct main_list_y_ptr_STRING *m_str=create_var_list_y_ptr_STRING();
  //printf("fd = %d\n event=%d\n\n",fds[1].fd,pollEventRec);
      //fds[1].events = 0;
      
      puts("Saisie du message : ");
      memset(buf, 0, sizeof buf);
      //scanf(" %"xstr(BUF_SIZE)"[^\n]%*c", buf);
      buf_len = read(0,buf,BUF_SIZE);
      */
 //     printf("message saisi : %s\n len = %ld\n",buf, buf_len);
			if(buf_len>6){
#if 1
					char cmd[BUF_SIZE], dst_addr[BUF_SIZE];//, msg_buf[BUF_SIZE];
					int index_buf=0, index_str=0;
					for(; buf[index_buf]!=' '; ++index_buf){
						cmd[index_str++]=buf[index_buf];
					}
					cmd[index_str]='\0';
//				printf("debug : index_str= %d; cmd=[%s]\n",index_str, cmd);
					
					index_str=0;
					while(buf[index_buf]==' '){++index_buf;}
					for(; buf[index_buf]!=' '; ++index_buf){
						dst_addr[index_str++]=buf[index_buf];
					}
					dst_addr[index_str]='\0';
					while(buf[index_buf]==' '){++index_buf;}
					/*index_str=0;
					for(; buf[index_buf]!='\n'; ++index_buf)
						msg_buf[index_str++]=buf[index_buf];
					msg_buf[index_str++]='\0';*/

	//			printf("debug : index_str=%d, dst_addr=[%s]\n", index_str, dst_addr);
#endif

		
			if(strncmp(cmd, "sendto", 6)==0){
//				printf("debug : sendto match, dst_addr=[%s]\n", dst_addr);
				if(set_addr_y_NODE_T(&node, dst_addr)){
//					printf("debug : set_addr_y_NODE_T done\n");
					set_str_port_y_NODE_T(&node, argSock->port);
					update_nodes(node, argSock->nodes);
					af=(node.addr.ss_family == AF_INET6);

					
					printf("debug : af = AF_INET=%d, af = AF_INET6=%d, vs  af=[%d]\n",AF_INET, AF_INET6, af);

					if(sendto(fds[af].fd, buf+index_buf  , buf_len-index_buf, 
	                    //	msg_buf, index_str,
																	0,
          	(struct sockaddr*)(&(node.addr)), node.addr_len) == -1){
      			printf("message erreur sendto : %s\n\n",buf);
          	perror("sendto:");
          	close(fds[af].fd);
          	return ;//NULL;
        	}
					char dddnn[56];
				  put_y_NODE_T_in_string(&node, dddnn);
      		printf("debug: sendto : %s: msg :%s\n\n",dddnn,  buf+index_buf);


				}
			}
		}
}
#endif

void handle_buf_socket_rec(struct main_list_y_ptr_HEADER_T *m_ok_head_l_t, struct main_list_y_ptr_HEADER_T *m_head_l_t,struct main_list_y_ptr_STRING *m_str, y_NODE_T node, struct main_list_ptr_y_WORKER_T * workers, struct argExecTasQ *argx, struct main_list_TYPE_PTR * list_arg, void * arg){
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
      }

    }
  }

#if 0
   if(strncmp(temp_all_buf,"update standby",14)==0){
      //pthread_mutex_lock(sock->mut_go_on);
      //sock->go_on = 0;
      //pthread_mutex_unlock(sock->mut_go_on);
      standby_all_workers(workers->begin_list->value->arg);
//      printf("debug: kill_all\n");
   }
   else if(strncmp(temp_all_buf,"update wakeup",13)==0){
      //pthread_mutex_lock(sock->mut_go_on);
      //sock->go_on = 0;
      //pthread_mutex_unlock(sock->mut_go_on);
      wakeup_all_workers(workers->begin_list->value->arg);
//      printf("debug: kill_all\n");
   }
   else{
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
   }
#endif
   free_js_value(js_header);  
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
  ssize_t nread, buf_len;
  char buf[BUF_SIZE+1];
	struct main_list_y_ptr_STRING *m_str=NULL;//=create_var_list_y_ptr_STRING();
  struct main_list_y_ptr_HEADER_T *m_head_l_t = create_var_list_y_ptr_HEADER_T();
  struct main_list_y_ptr_HEADER_T *m_ok_head_l_t = create_var_list_y_ptr_HEADER_T();

//	char *temp_all_buf=NULL;

//  char msgRet[BUF_SIZE + NI_MAXHOST + NI_MAXSERV + 100];
//  int len_msgRet;
// I had to initialize all attribute of addr to avoid error uninitialized value with valgrind, for example "sin6_flowinfo" in sockaddr_in6
 	memset(&(node.addr), 0, sizeof(struct sockaddr_storage)); 
  size_t len_sockaddr_storage = sizeof(struct sockaddr_storage);
  node.addr_len = len_sockaddr_storage; // sizeof(struct sockaddr_storage);
  
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
        
#if 1	
				while((nread = recvfrom(fds[af].fd, buf, BUF_SIZE, 0,
        (struct sockaddr *)&(node.addr), &(node.addr_len))) == BUF_SIZE){
        	
          if(buf[nread-1]=='\n') 
            buf[nread-1]='\0';
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
        	if(nread && buf[nread-1]=='\n'
            ) buf[nread-1]='\0';
					buf[nread]='\0';
          //printf("msg: %s\n",buf);
					y_ptr_STRING y_buf = create_y_ptr_STRING(buf, nread);
					push_back_list_y_ptr_STRING(m_str, y_buf);
					//printf("debug: out push_back_list_y_ptr_STRING of <%s>\n",buf);
				
        }
#endif

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
        /*char * temp_all_buf = NULL;
        copy_list_y_ptr_STRING_to_one_string(&temp_all_buf , m_str);
        push_back_list_TYPE_PTR(list_arg, temp_all_buf);
        */
   
			///
				//y_socket_handler_(temp_all_buf, fds, argSock);

			///
      }
      if(m_str){
				printf("debug:  call handle_buf_socket_rec\n");
        handle_buf_socket_rec(m_ok_head_l_t,m_head_l_t,m_str, node, workers, argx, list_arg, arg);
      
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
				printf("debug : index_str= %d; cmd=[%s]\n",index_str, cmd);
					
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

				printf("debug : index_str=%d, dst_addr=[%s]\n", index_str, dst_addr);
#endif

		
			if(strncmp(cmd, "sendto", 6)==0){
				printf("debug : sendto match, dst_addr=[%s]\n", dst_addr);
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
      

        }
        else if(set_addr_y_NODE_T(&node, dst_addr)){
					printf("debug : set_addr_y_NODE_T done\n");
					set_str_port_y_NODE_T(&node, argSock->port);
					update_nodes(node, argSock->nodes);
					af=(node.addr.ss_family == AF_INET6);

					
					printf("debug : af = AF_INET=%d, af = AF_INET6=%d, vs  af=[%d]\n",AF_INET, AF_INET6, af);

          //node.addr_len = sizeof(struct sockaddr_storage);
					if(sendto(fds[af].fd, buf+index_buf  , buf_len-index_buf, 0,
          	(struct sockaddr*)(&(node.addr)), len_sockaddr_storage //node.addr_len
            ) == -1){
      			printf("message erreur sendto : %s, error :%d\n\n",buf,errno);
          	perror("sendto:");
          	close(fds[af].fd);
          	return NULL;
        	}
					char dddnn[56];
				  put_y_NODE_T_in_string(&node, dddnn);
      		printf("debug: sendto : %s: msg :%s\n\n",dddnn,  buf+index_buf);


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



