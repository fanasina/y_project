#include "y_socket_t/y_file_handler.h"

//#include "y_socket_t/y_node_t.h"



void fileNameDateScore(char* filename, char * pre, char* post,size_t score){
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
#endif
/* */
void y_send_post_file_to_all_nodes(void *arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;

	struct pollfd *fds=argS->fds;
	struct main_list_y_NODE_T *nodes=argS->nodes;
	char * filename=argS->filename;
#if TEMP_ADDR
  char tempAddr[BUF_SIZE+1];
#endif
  int c_af;
//  char host[NI_MAXHOST], service[NI_MAXSERV];
  char buf_send[BUF_SIZE+1]={0};
  int fd_file;
  int retsprintf = sprintf(buf_send,"post file %s", filename );
  printf("debug: buf_send=%s, size=%d\n",buf_send, retsprintf);

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

            if(sendto(fds[(c_af==AF_INET6)].fd, 
              buf_send, retsprintf,
              /*msgRet, len_msgRet,*/ 
              0, 
              (struct sockaddr*)&((local_list_current->value).addr), 
              (local_list_current->value).addr_len) != 
              retsprintf
              /*len_msgRet*/
              ){
#if TEMP_ADDR
							fprintf(stderr, "Error sending response to %s\n",tempAddr);
#endif
						}else{
#if TEMP_ADDR
							printf("debug: sending %s to < %s >",buf_send,tempAddr);
#endif
						}
          }
        }

/* */
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
 				
		 //  y_send_post_file_to_all_nodes(arg);
          for(struct list_y_NODE_T *local_list_current = nodes->begin_list; local_list_current; local_list_current=local_list_current->next ){

       //memset(buf_send, 0, BUF_SIZE+1);
       while((retread = read(fd_file, buf_send, BUF_SIZE) ) > 0 ){
          buf_send[retread]='\0';
          //memset(msgRet, 0, BUF_SIZE + NI_MAXHOST + NI_MAXSERV + 100);
  //        sprintf(msgRet, "from %s:%s =%s",host, service, buf);
          
  //        len_msgRet = strlen(msgRet);
         ///printf("debug: sending response  %s :\n",buf_send);
          
					//FOR_LIST_FORM_BEGIN(y_NODE_T, nodes)
          //for(struct list_y_NODE_T *local_list_current = nodes->begin_list; local_list_current; local_list_current=local_list_current->next )
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
          retread = sprintf(buf_send, "post file %s", filename);
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
					}else{
							printf("debug: sending response to < %s >",tempAddr);
					}

        }

        close(fd_file);
        printf("debug: fd=%d closed: filename=%s\n",fd_file,filename);
  return NULL;
}


void receve_from_node(struct pollfd *fds, char *msg, size_t count){
    
    char filename[500];
    int fd_file;
    long int nread;
    char buf[BUF_SIZE];
    struct sockaddr_storage peer_addr;
    socklen_t peer_addr_len = sizeof(struct sockaddr_storage);
    //update_nodes(y_NODE_T node, struct main_list_y_NODE_T *nodes);

    fileNameDateScore(filename, "__",msg,count);
        if((fd_file = open(filename, O_WRONLY | O_CREAT ,
          S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1){
          fprintf(stderr,"erreur write %s\n",filename);
          return ; //NULL;
        }
        memset(buf,0, BUF_SIZE);
        while((nread = recvfrom(fds[1].fd, buf, BUF_SIZE, 0,
          (struct sockaddr *)&peer_addr, &peer_addr_len
          //(struct sockaddr *)&(node.addr), &(node.addr_len)
          )) == BUF_SIZE){
          if(nread == -1)
          {
            fprintf(stderr,"error nread\n");
          }
          else {
            printf("msg: %s\n",buf);

            write(fd_file, buf, nread);

          }
          printf("nread==%ld\n",nread);
        }
        
        if(nread >0 && nread <BUF_SIZE){
            printf("msg: %s\n",buf);

            write(fd_file, buf, nread);
        }
        printf("debug: <receve_from_node> close nread==%ld\n",nread);
        close(fd_file);


}
