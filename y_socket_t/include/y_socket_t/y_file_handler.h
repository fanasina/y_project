#ifndef Y_FILE_HANDLER_T_H__C
#define Y_FILE_HANDLER_T_H__C

#include "y_socket_t/y_socket_t.h"

void fileNameDateScore(char* filename, char * pre, char* post,size_t score);

struct arg_send_file{
	struct pollfd *fds;
	struct main_list_y_NODE_T *nodes;
	char * filename;
};

void* y_socket_send_file_for_all_nodes(void* arg);
void receve_from_node(struct pollfd *fds, char *msg, size_t count);


#endif /*Y_FILE_HANDLER_T_H__C*/
