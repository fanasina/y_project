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
  
  struct y_socket_t *firstSock = y_socket_create_("1600");
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
	
	//((struct sockaddr_in*)(&(nA.addr)))->sin_port = 22;
	//((struct sockaddr_in*)(&(nB.addr)))->sin_port = 22;
	set_port_y_NODE_T(&nA, 22);
	set_port_y_NODE_T(&nB, 22);
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
TEST(equalNode6){
  y_NODE_T nA, nB;
  init_len_y_NODE_T(&nA);
  init_len_y_NODE_T(&nB);

  nA.addr.ss_family=AF_INET6;
  nB.addr.ss_family=AF_INET6;
  
	set_port_y_NODE_T(&nA, 22);
	set_port_y_NODE_T(&nB, 22);
	//((struct sockaddr_in6*)(&(nA.addr)))->sin6_port = 22;
	//((struct sockaddr_in6*)(&(nB.addr)))->sin6_port = 22;

  //((struct sockaddr_in*)&(nA.addr))->sin_addr.s_addr = inet_addr("192.168.1.2");
  //((struct sockaddr_in*)&(nB.addr))->sin_addr.s_addr = inet_addr("192.168.1.2");

  inet_pton(AF_INET6, "::1", &(GET_IN_type_ADDR(&(nA.addr),6)));
  inet_pton(AF_INET6, "::1", &(GET_IN_type_ADDR(&(nB.addr),6)));


  EXPECT_EQ(0, y_NODE_T_cmp(nA,nB));
  inet_pton(AF_INET6, "::", &(GET_IN_type_ADDR(&(nB.addr),6)));
  LOG("diff = %d\n", y_NODE_T_cmp(nA,nB));


}



TEST(searchNode){
  y_NODE_T nA, nB;
  init_len_y_NODE_T(&nA);
  init_len_y_NODE_T(&nB);

  nA.addr.ss_family=AF_INET;
  nB.addr.ss_family=AF_INET;

	set_port_y_NODE_T(&nA, 22);
	set_port_y_NODE_T(&nB, 22);
  //((struct sockaddr_in*)(&(nA.addr)))->sin_port = 22;
  //((struct sockaddr_in*)(&(nB.addr)))->sin_port = 22;
  
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

  //GET_IN_type_ADDR(&(nB.addr),) = inet_addr("0.1.1.1");
  int ret = set_addr_y_NODE_T(&nB, "0.1.1.1");
  LOG("return of set =%d\n", ret);

  EXPECT_TRUE(NULL == search_node_in_list_y_NODE_T(listNodes, nB));
  //GET_IN_type_ADDR(&(nA.addr),) = inet_addr("1.1.1.3");
  inet_pton(AF_INET, "1.1.1.3", &(GET_IN_type_ADDR(&(nA.addr),)));
  EXPECT_FALSE(NULL == search_node_in_list_y_NODE_T(listNodes, nA));
  
  //inet_pton(AF_INET6, "::1", GET_IN_type_ADDR(&(nB.addr),6));
  //((struct sockaddr_in6*)(&(nB.addr)))->sin6_port = 22;
  ret = set_addr_y_NODE_T(&nB, "::1");
	set_port_y_NODE_T(&nB, 22);
  LOG("return of set =%d\n", ret);
  push_back_list_y_NODE_T(listNodes, nB);
  
  //inet_pton(AF_INET6, "::", GET_IN_type_ADDR(&(nA.addr),6));
  ret = set_addr_y_NODE_T(&nB, "::");
  LOG("return of set =%d\n", ret);
  EXPECT_FALSE(NULL == search_node_in_list_y_NODE_T(listNodes, nA));

  free_all_var_list_y_NODE_T(listNodes);


}


TEST(pollThread){
  struct y_socket_t *argS=y_socket_create("1600", 2, 3);

  pthread_t pollTh;
  pthread_create(&pollTh, NULL, y_socket_poll_fds, (void*)argS);

/*  
  struct argdst dstarg={
    .port="1600",
    .addrStr="::1",
  };
  pthread_t cliTh;
  pthread_create(&cliTh, NULL, threadFuncSend, (void*)&dstarg);

  pthread_join(cliTh, NULL);
*/

  pthread_join(pollTh, NULL);

  y_socket_free(argS);

}


int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
