#include "y_socket/y_socket.h"

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

