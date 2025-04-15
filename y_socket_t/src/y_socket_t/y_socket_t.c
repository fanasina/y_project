#include "y_socket_t/y_socket_t.h"

const int af_array[nbIpVersion]={AF_INET, AF_INET6};

struct y_socket_t * y_socket_create(char *port){
  struct y_socket_t *sock_temp=malloc(sizeof(struct y_socket_t));
  sock_temp->fds = malloc(nbIpVersion * sizeof(struct pollfd));

  sock_temp->port=port;
  sock_temp->nodes = create_var_list_y_NODE_T();
  pthread_mutex_init(&(sock_temp->mut_nodes), NULL);
  return sock_temp;
}

void y_socket_free(struct y_socket_t *socket){
  free(socket->fds);
  free_all_var_list_y_NODE_T(socket->nodes);
  pthread_mutex_destroy(&(socket->mut_nodes)); 
  free(socket);
}

// node = NULL for anyIP or str address of the server
int get_fds_with_getaddrinfo(char *port /*service */, char * node, struct pollfd *fds){
  /*
  if(sizeof(fds) < nbIpVersion*sizeof(struct pollfd)){
    printf("%ld vs %ld vs %ld \n", sizeof(struct pollfd),sizeof(fds) , nbIpVersion*sizeof(struct pollfd));
    return -1;
  }
  */
  fds[v4].fd=-1; fds[v4].events = POLLIN;
  fds[v6].fd=-1; fds[v6].events = POLLIN;
  
  struct addrinfo hints, *result, *rp;
  int status;
  int af, optValueV6 = 1;
  
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC; // Allow all IPv4 and IPv6
  hints.ai_socktype = SOCK_DGRAM; // udp
  hints.ai_flags = AI_PASSIVE; // anyIP
  //below no need because of memset(&hints,0 ...
  hints.ai_protocol = 0;
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  status = getaddrinfo(node, port, &hints, &result);
  if(status != 0){
    fprintf(stderr, "getaddrinfo :%s\n", gai_strerror(status));
    return -2;
  }

  for(rp = result; rp != NULL; rp=rp->ai_next){
    for(af=v4; af<=v6; ++af){
      if((rp->ai_family == af_array[af]) && (fds[af].fd ==-1)){
        fds[af].fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if(fds[af].fd == -1)
          continue;

        if(node == NULL){
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
        }
      }
    }
  }

  freeaddrinfo(result);

  if((fds[v4].fd == -1) && (fds[v6].fd == -1)){
    fprintf(stderr, " v4 or v6 not listening, we leave!");
      return 3;
  }
  if((fds[v4].fd != -1) && (fds[v6].fd == -1)){
    fprintf(stderr, " only v4 listening!");
      return 1;
  }
  if((fds[v4].fd == -1) && (fds[v6].fd != -1)){
    fprintf(stderr, " only v6 listening!");
      return 2;
  }

  return 0;
 

}

void *y_pollSocketsFunc(void *arg){
  struct y_socket_t * argSock = (struct y_socket_t*)arg;
  struct pollfd *fds = argSock->fds;
  fds[v4].fd=-1; fds[v4].events = POLLIN;
  fds[v6].fd=-1; fds[v6].events = POLLIN;

  struct addrinfo hints, *result, *rp;
  int status;
  ssize_t nread;
  char buf[BUF_SIZE];
  
  memset(&hints, 0, sizeof(struct addrinfo));
  hints.ai_family = AF_UNSPEC; // Allow all IPv4 and IPv6
  hints.ai_socktype = SOCK_DGRAM; // udp
  hints.ai_flags = AI_PASSIVE; // anyIP
  // 
  hints.ai_protocol = 0;
  hints.ai_canonname = NULL;
  hints.ai_addr = NULL;
  hints.ai_next = NULL;

  status = getaddrinfo(NULL, argSock->port, &hints, &result);
  if(status != 0){
    fprintf(stderr, "getaddrinfo :%s\n", gai_strerror(status));
    return NULL;
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
      }
    }
  }

  freeaddrinfo(result);

//  ssize_t nread;
//  char buf[BUF_SIZE];
  
//  int status, af; 
//  status = get_fds_with_getaddrinfo(argSock->port, NULL, fds);
  
//  if(status != 0) 
    /*
    if(status == 1)
      fprintf(stderr, " v4 or v6 not listening, we leave!");
    else
      fprintf(stderr, " not enough allocatation for fds, we leave!");
    */

  if((fds[v4].fd==-1) || (fds[v6].fd==-1)){
    fprintf(stderr, " v4 or v6 not listening, we leave!");
    return NULL;
  }
  //struct sockaddr_storage peer_addr;
  //socklen_t len_peer_addr;
  y_NODE_T node;
  char tempAddr[BUF_SIZE];
  int c_af;
  char host[NI_MAXHOST], service[NI_MAXSERV];
//  char msgRet[BUF_SIZE + NI_MAXHOST + NI_MAXSERV + 100];
//  int len_msgRet;
  for(;;){
    status = poll(fds, nbIpVersion, -1);
    if(status <= 0){
      if(status == -1 && errno != EINTR){
        perror("poll");
        return NULL;
      }
      continue;
    }
    node.addr_len = sizeof(struct sockaddr_storage);
    for(af = v4; af<=v6;++af){
      if(fds[af].revents && POLLIN){
        memset(buf, 0, BUF_SIZE);
        nread = recvfrom(fds[af].fd, buf, BUF_SIZE, 0,
        (struct sockaddr *)&(node.addr), &(node.addr_len));
        if(nread == -1)
          continue;

printf("msg : %s\n",buf);

        status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status == 0)
          printf("Received %ld bytes from %s:%s\n",(long)nread, host,service);
        else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));


        if(NULL ==  search_node_in_list_y_NODE_T(argSock->nodes, node))
          push_back_list_y_NODE_T(argSock->nodes, node);
        
        //UPPER
        for(int i=0; i<nread; ++i)
          if((buf[i] >='a') && (buf[i]<='z'))
            buf[i]=buf[i]+'A'-'a';
        
        //memset(msgRet, 0, BUF_SIZE + NI_MAXHOST + NI_MAXSERV + 100);
//        sprintf(msgRet, "from %s:%s =%s",host, service, buf);
        
//        len_msgRet = strlen(msgRet);
        printf("sending response  %s :\n",buf);
        FOR_LIST_FORM_BEGIN(y_NODE_T, argSock->nodes){
          c_af=(argSock->nodes->current_list->value).addr.ss_family;
          //memset(tempAddr, 0, BUF_SIZE);
          if(c_af==AF_INET){
             if(NULL == inet_ntop(c_af, 
              &(GET_IN_type_ADDR(&(argSock->nodes->current_list->value),)),
              tempAddr, BUF_SIZE/*(argSock->nodes->current_list->value).addr_len*/)){
              fprintf(stderr, "error inet_ntop v4\n");
            }
          }else if(c_af==AF_INET6){
             if(NULL == inet_ntop(c_af, 
              &(GET_IN_type_ADDR(&(argSock->nodes->current_list->value),6)),
              tempAddr, BUF_SIZE /*(argSock->nodes->current_list->value).addr_len*/)){
              fprintf(stderr, "error inet_ntop v6 :errno=%d\n",errno);
            }
          }
                    
          if(sendto(fds[(c_af==AF_INET6)].fd, 
            buf, nread,
            /*msgRet, len_msgRet,*/ 
            0, 
            (struct sockaddr*)&((argSock->nodes->current_list->value).addr), 
            (argSock->nodes->current_list->value).addr_len) != 
            nread
            /*len_msgRet*/
            ){
            fprintf(stderr, "Error sending response to %s\n",tempAddr);
          }else
            printf("sending response to %s\n",tempAddr);
        }
      }
    }
//    printf("nread = %ld: buf=%s\nlen_buf=%ld\ncmp=%d\n",nread,buf,strlen(buf),strncmp(buf,"SHUTDOWN SERVER",15));
      if(strncmp(buf,"SHUTDOWN SERVER",15) == 0){
        printf("leave poll thread, bye!\n");
        return NULL;
      }
  }
}
#define str(x) # x
#define xstr(x) str(x) 


void *threadFuncSend(void *arg){
  struct argdst * dstarg = (struct argdst*)arg;
  
 int socketDescriptor, status;
  unsigned int msgLength;
  struct addrinfo hints, *serverInfo, *p;
  struct timeval timeValue;
  fd_set readSetFD;
  char msg[BUF_SIZE];//, serverPort[PORT_ARRAY_SIZE];
  bool sockSuccess = false;

  /*
  puts("Entrez le nom du serveur ou son adresse IP : ");
  memset(msg, 0, sizeof msg);
  scanf("%s"xstr(BUF_SIZE)"s",msg);

  puts("Entrez le numéro de port du serveur : ");
  memset(serverPort, 0, sizeof serverPort);
  scanf("%s"xstr(MAX_PORT)"s",serverPort);
 */
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_DGRAM;

  if((status = getaddrinfo(dstarg->addrStr, dstarg->port, &hints, &serverInfo)) != 0){
    fprintf(stderr, "getaddrinfo: %s\n",gai_strerror(status));
    exit(EXIT_FAILURE);
  }

  p = serverInfo;
  while((p!=NULL) && !sockSuccess){
    if(p->ai_family == AF_INET)
      puts("Open IPv4 socket");
    else
      puts("Open IPv6 socket");

    if((socketDescriptor = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1){
      perror("socket:");
      sockSuccess = false; // echec ouverture du socket
      p = p->ai_next;
    }
    else
      sockSuccess = true;
  }

  freeaddrinfo(serverInfo);

  if(p==NULL){
    fputs("Creation de socket impossible", stderr);
    return NULL;
  }

  puts("\n Entrez quelques caractères au clavier.");
  puts("Le serveur les modifiera et les renvera.");
  puts("Pour sortir, entrez une ligne avec le caractère '.' uniquement.");

  puts("Saisie du message : ");
  memset(msg, 0, sizeof msg);
  scanf(" %"xstr(BUF_SIZE)"[^\n]%*c", msg);

  while(strcmp(msg, ".")){
    if((msgLength = strlen(msg)) > 0 ){
      if(sendto(socketDescriptor, msg, msgLength, 0,
        p->ai_addr, p->ai_addrlen) == -1){
        perror("sendto:");
        close(socketDescriptor);
        exit(EXIT_FAILURE);
      }

      FD_ZERO(&readSetFD);
      FD_SET(socketDescriptor, &readSetFD);
      timeValue.tv_sec = 1;
      timeValue.tv_usec = 0;

      if(select(socketDescriptor +1, &readSetFD, NULL,NULL, &timeValue)){
        memset(msg, 0, sizeof msg);
        if(recv(socketDescriptor, msg, sizeof msg, 0) == -1){
          perror("recv:");
          close(socketDescriptor);
          exit(EXIT_FAILURE);
        }

        printf("Message traité : %s\n", msg);
        if(strcmp(msg,"SHUTDOWN SERVER")==0)
          break;
      }
      else{
        puts("Pas de réponse dans la seconde.");
      }

    }
  puts("Saisie du message : ");
    memset(msg, 0, sizeof msg);
    scanf(" %"xstr(BUF_SIZE)"[^\n]%*c", msg);
  }

  close(socketDescriptor);


 

  return NULL;

}
