#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for sleep !
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif

#include "ftest/ftest.h"
#include "ftest/ftest_array.h"
#include "fmock/fmock.h"

//#include "permutation_t/permutation_t.h"
#include "y_socket_t/y_socket_t.h"
#include "y_socket_t/y_node_t.h"

//#include <netinet/in.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>

#define VALGRIND_ 1

TEST(first){
  
  struct y_socket_t *firstSock = y_socket_create("1600");
  LOG("create y_socket_t in port |%s|\n",firstSock->port);

  y_socket_free(firstSock);

for(int af=v4; af<=v6;++af)
  LOG("af_array[%d]=%d\n",af,af_array[af]);
  
    
}

TEST(list_nodes){
  struct main_list_y_NODE_T * listNodes = create_var_list_y_NODE_T();

  LOG("main_list_y_NODE_T created\n");

  y_NODE_T firstNode;

  push_back_list_y_NODE_T(listNodes, firstNode);


  free_all_var_list_y_NODE_T(listNodes);

  

}

TEST(equalNode){
  y_NODE_T nA, nB;
  init_len_y_NODE_T(&nA);
  init_len_y_NODE_T(&nB);

  nA.addr.ss_family=AF_INET;
  nB.addr.ss_family=AF_INET;

  //((struct sockaddr_in*)&(nA.addr))->sin_addr.s_addr = inet_addr("192.168.1.2");
  //((struct sockaddr_in*)&(nB.addr))->sin_addr.s_addr = inet_addr("192.168.1.2");

  GET_IN_type_ADDR(&(nA.addr),) = inet_addr("1.1.1.1");
  GET_IN_type_ADDR(&(nB.addr),) = inet_addr("1.1.1.1");

 LOG("nA = %d\n",GET_IN_type_ADDR(&(nA.addr),));
 LOG("nB = %d\n",GET_IN_type_ADDR(&(nB.addr),));

  EXPECT_EQ(0, y_NODE_T_cmp(nA,nB));
  GET_IN_type_ADDR(&(nB.addr),) = inet_addr("0.1.1.1");
  LOG("diff = %d\n", y_NODE_T_cmp(nA,nB));


}


TEST(searchNode){
  y_NODE_T nA, nB;
  init_len_y_NODE_T(&nA);
  init_len_y_NODE_T(&nB);

  nA.addr.ss_family=AF_INET;
  nB.addr.ss_family=AF_INET;

  //((struct sockaddr_in*)&(nA.addr))->sin_addr.s_addr = inet_addr("192.168.1.2");
  //((struct sockaddr_in*)&(nB.addr))->sin_addr.s_addr = inet_addr("192.168.1.2");

  GET_IN_type_ADDR(&(nA.addr),) = inet_addr("1.1.1.1");
  GET_IN_type_ADDR(&(nB.addr),) = inet_addr("1.1.1.2");

 LOG("nA = %d\n",GET_IN_type_ADDR(&(nA.addr),));
 LOG("nB = %d\n",GET_IN_type_ADDR(&(nB.addr),));

  struct main_list_y_NODE_T *listNodes = create_var_list_y_NODE_T();
  push_back_list_y_NODE_T(listNodes, nA);
  push_back_list_y_NODE_T(listNodes, nB);
  GET_IN_type_ADDR(&(nA.addr),) = inet_addr("1.1.1.3");
  push_back_list_y_NODE_T(listNodes, nA);

  GET_IN_type_ADDR(&(nB.addr),) = inet_addr("0.1.1.1");
//  push_back_list_y_NODE_T(listNodes, nB);
  
  EXPECT_TRUE(NULL == search_node_in_list_y_NODE_T(listNodes, nB));
  GET_IN_type_ADDR(&(nA.addr),) = inet_addr("1.1.1.3");
  EXPECT_FALSE(NULL == search_node_in_list_y_NODE_T(listNodes, nA));

  free_all_var_list_y_NODE_T(listNodes);


}


int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
