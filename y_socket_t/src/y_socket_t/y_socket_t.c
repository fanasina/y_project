#include "y_socket_t/y_socket_t.h"

const int af_array[nbIpVersion]={AF_INET, AF_INET6};

struct y_socket_t * y_socket_create(char *port){
  struct y_socket_t *sock_temp=malloc(sizeof(struct y_socket_t));
  sock_temp->port=port;
  sock_temp->nodes = create_var_list_y_NODE_T();
  return sock_temp;
}

void y_socket_free(struct y_socket_t *socket){

  free_all_var_list_y_NODE_T(socket->nodes);
  
  free(socket);
}


#if 0
struct y_server_t server;

void close_server(struct y_server_t server){
  char *message ="HTTP/1.1 201 OK\r\n"
                   "Connection: close";
  
  for(int i=0; i<server.nb_clients;++i){
  
    pthread_mutex_lock(server.client[i].mut_client);
    write(server.client[i].id, message, strlen(message));
    pthread_mutex_unlock(server.client[i].mut_client);
    
    close(server.client[i].id);
  }
   

   close(server.sock);
  
}

void func_sig_Handler(int sig){
  if(sig==SIGINT){
    close_server(server);

    sigaction(SIGINT, &old, NULL); /* equivalent à .sa_falg =  SA_RESETHAND , i.e. 1 seul new_action, puis on revient à l'ancien*/

    exit(0);
  }
}
#endif

