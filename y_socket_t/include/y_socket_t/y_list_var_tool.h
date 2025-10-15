/*file: include/y_socket_t/y_list_var_tool.h */
#ifndef Y_PTR_VAR_TOOL_H__C
#define Y_PTR_VAR_TOOL_H__C


#include <string.h>

#include "list_t/list_t.h"

long  long_time_id();

struct y_variable{
  char * name;
  size_t size_name;
  void * value;
  size_t size_value;
  long time_l;
  char src[64];/* */
};

typedef struct y_variable * y_ptr_VARIABLE;

struct y_variable * create_y_ptr_VARIABLE(const char *name, size_t size_name, void * value, size_t size_value, char * src);
GENERATE_LIST_ALL(y_ptr_VARIABLE)
GEN_HEAD_PTR_LIST(y_ptr_VARIABLE)

void update_list_y_ptr_VARIABLE(struct main_list_y_ptr_VARIABLE *listVariables, y_ptr_VARIABLE var);

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
struct main_list_y_ptr_STRING * split_str_to_main_list_y_ptr_STRING(char *str_org, char sep, size_t limit_size_str_org);

#endif /* Y_PTR_VAR_TOOL_H__C */
