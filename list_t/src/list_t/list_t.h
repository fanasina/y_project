#ifndef __LIST_T_C__H
#define __LIST_T_C__H

#include "tools_t/tools_t.h"

#define TYPE_PTR void*

#define GENERATE_LIST_ALL(type)\
  struct list_##type {\
    type value;\
    struct list_##type *preview;\
    struct list_##type *next;\
  };\
  struct main_list_##type {\
    struct list_##type *begin_list;\
    struct list_##type *current_list;\
    size_t current_index;\
    struct list_##type *end_list;\
    size_t size;\
  };\
  struct main_list_##type *create_var_list_##type();\
  void push_back_list_##type(struct main_list_##type *var_list, type value);\
  void push_front_list_##type(struct main_list_##type *var_list, type value);\
  size_t move_current_to_index_list_##type(struct main_list_##type *var_list, size_t index);\
  void insert_into_list_##type(struct main_list_##type *var_list, size_t index, type value );\
  void remove_index_from_list_##type(struct main_list_##type *var_list, size_t index );\
  void free_all_var_list_##type(struct main_list_##type *var_list);\
  void increment_list_##type(struct main_list_##type * var_list);\
  void decrement_list_##type(struct main_list_##type * var_list);\


GENERATE_LIST_ALL(TYPE_CHAR)
GENERATE_LIST_ALL(TYPE_U_CHAR)
GENERATE_LIST_ALL(TYPE_INT)
GENERATE_LIST_ALL(TYPE_U_INT)
GENERATE_LIST_ALL(TYPE_L_INT)
GENERATE_LIST_ALL(TYPE_U_L_INT)
GENERATE_LIST_ALL(TYPE_SIZE_T)
GENERATE_LIST_ALL(TYPE_FLOAT)
GENERATE_LIST_ALL(TYPE_DOUBLE)
GENERATE_LIST_ALL(TYPE_L_DOUBLE)
GENERATE_LIST_ALL(TYPE_STRING)

GENERATE_LIST_ALL(TYPE_PTR)


#endif /* __LIST_T_C__H */
