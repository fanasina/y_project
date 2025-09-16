/*file: include/y_socket_t/y_list_string.h */
#ifndef Y_PTR_STRING_T_H__C
#define Y_PTR_STRING_T_H__C


#include <string.h>

#include "list_t/list_t.h"


struct y_string{
  char * buf;
  size_t size;
};

typedef struct y_string * y_ptr_STRING;

struct y_string * create_y_ptr_STRING(const char *buf, size_t size);
GENERATE_LIST_ALL(y_ptr_STRING)
GEN_HEAD_PTR_LIST(y_ptr_STRING)

size_t total_size_list_y_ptr_STRING(struct main_list_y_ptr_STRING *mstr);
size_t copy_list_y_ptr_STRING_to_one_string(char **p_dst_str, struct main_list_y_ptr_STRING *mstr);

#endif /* Y_PTR_STRING_T_H__C */
