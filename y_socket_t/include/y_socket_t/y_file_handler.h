/*file: include/y_socket_t/y_file_handler.h */
#ifndef Y_FILE_HANDLER_T_H__C
#define Y_FILE_HANDLER_T_H__C

#include <sys/stat.h>

#include "y_socket_t/y_socket_t.h"
#include "y_socket_t/y_node_t.h"
#include "y_socket_t/y_list_var_tool.h"

#include "y_worker_t/y_worker_t.h"
#include "y_worker_t/y_task_t.h"

#include "json_t/json_t.h"

#include "list_t/list_t.h"

void y_fileNameDateScore(char* filename, char * pre, char* post,size_t score);

struct arg_send_file{
	struct pollfd *fds;
	struct main_list_y_NODE_T *nodes;
	y_NODE_T node;
	char * filename;
	char * dst_dir;
	struct main_list_y_ptr_HEADER_T *m_ok_head_l_t;
	//struct main_list_y_ptr_VARIABLE *m_var;
};

void* y_socket_send_file_for_all_nodes(void* arg);
void* y_socket_send_file_for_node(void* arg);
void* y_send_buf_for_all_(void* arg);
void* y_send_buf_for_other_(void* arg);

enum cmd_type {
  cmd_update_kill,
  cmd_update_standby,
  cmd_update_wakeup,    
  cmd_post_file,
  cmd_post_ok,
  cmd_get_file,
  cmd_get_var,
};


typedef struct msg_content_t {
  enum cmd_type cmd_t;
  size_t seq;
  char eof;
  size_t size_content;
  char *content; 
  size_t size_nameid;
  char * nameid;/* containerid: filename_src_dst_tm */
} y_MSG_CONTENT_T;

typedef struct msg_content_t * y_ptr_MSG_CONTENT_T;
GENERATE_LIST_ALL(y_ptr_MSG_CONTENT_T)
GEN_HEAD_PTR_LIST(y_ptr_MSG_CONTENT_T)


typedef struct header_t {
  enum cmd_type cmd_t;
//  size_t seq;
  char eof;
//  char ok;
//  void *content; 
  size_t size_nameid;
  char * nameid;/* containerid: filename_src_dst_tm */
  struct main_list_y_ptr_MSG_CONTENT_T * m_content_l;
} y_HEADER_T;

typedef struct header_t * y_ptr_HEADER_T;

GENERATE_LIST_ALL(y_ptr_HEADER_T)
GEN_HEAD_PTR_LIST(y_ptr_HEADER_T)


size_t set_tempAddr_from_node(char *tempAddr, y_NODE_T node);
//void receve_from_node(struct pollfd *fds, char *msg, size_t count);
void receve_from_node(struct pollfd *fds,  struct main_list_y_ptr_HEADER_T *m_head_l_t, /*struct main_list_y_ptr_VARIABLE *m_var,*/ struct main_list_y_ptr_STRING *m_str, y_NODE_T node /* char * srcAddr*/, char *filename);
long y_append_to_ok_header_l_(struct main_list_y_ptr_HEADER_T *m_ok_head_l_t, char *nameid );

#endif /*Y_FILE_HANDLER_T_H__C*/
