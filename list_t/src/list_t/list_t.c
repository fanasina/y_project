
#include "list_t/list_t.h"

#if 0

#define GEN_LIST_ALL_L(type)\
 \
  struct main_list_##type *create_var_list_##type(){\
    struct main_list_##type *ret_var_list = malloc(sizeof(struct main_list_##type));\
    ret_var_list->begin_list = NULL;\
    ret_var_list->end_list = NULL;\
    ret_var_list->current_list = NULL;\
    ret_var_list->current_index = 0;\
    ret_var_list->size = 0;\
    return ret_var_list;\
  }\
  void push_back_list_##type(struct main_list_##type *var_list, type value){\
    struct list_##type * list_to_add = malloc(sizeof(struct list_##type));\
    list_to_add->value = value;\
    list_to_add->preview = var_list->end_list;\
    list_to_add->next = NULL;\
    if(var_list->end_list){\
      (var_list->end_list)->next = list_to_add;\
    }else {\
      var_list->begin_list = list_to_add;\
      var_list->current_list= list_to_add;\
    }\
    var_list->end_list = list_to_add;\
    ++(var_list->size);\
  }\
  void push_front_list_##type(struct main_list_##type *var_list, type value){\
    struct list_##type * list_to_add = malloc(sizeof(struct list_##type));\
    list_to_add->value = value;\
    list_to_add->preview = NULL;\
    list_to_add->next = var_list->begin_list;\
    if(var_list->begin_list){\
      (var_list->begin_list)->preview = list_to_add;\
      ++(var_list->current_index);\
    }else {\
      var_list->end_list = list_to_add;\
      var_list->current_list= list_to_add;\
    }\
    var_list->begin_list = list_to_add;\
    ++(var_list->size);\
  }\
  size_t move_current_to_index_list_##type(struct main_list_##type *var_list, size_t index){\
    if(index == var_list->current_index) return index;\
    if(var_list->begin_list == NULL) return 0;\
    if(index >= var_list->size){\
      var_list->current_list = var_list->end_list;\
      var_list->current_index = var_list->size - 1;\
      return var_list->size - 1;\
    }\
    if((var_list->current_index >= var_list->size) || !(var_list->current_list)){\
      var_list->current_list = var_list->end_list;\
      var_list->current_index = var_list->size - 1;\
    }\
    long from_current_index = var_list->current_index - index; \
    size_t abs_cur_diff = abs(from_current_index); \
    size_t array_diff_index[3]  = {index, abs_cur_diff , var_list->size - 1 - index}; \
    size_t index_nearest = ARG_MIN_ARRAY_TYPE_SIZE_T(array_diff_index, 3);\
    if(index_nearest == 0){\
      var_list->current_list = var_list->begin_list;\
      for(size_t i=0; i<array_diff_index[0]; ++i) var_list->current_list = (var_list->current_list)->next; \
    }\
    else if(index_nearest == 2){\
      var_list->current_list = var_list->end_list;\
      for(size_t i=0; i < array_diff_index[0]; ++i) var_list->current_list = (var_list->current_list)->preview; \
    }else if(from_current_index >= 0) \
      for(size_t i=0; i < array_diff_index[1]; ++i) var_list->current_list = (var_list->current_list)->preview; \
    else  \
      for(size_t i=0; i < array_diff_index[1]; ++i) var_list->current_list = (var_list->current_list)->next; \
      \
    var_list->current_index = index;\
    return index;\
  }\
  void insert_into_list_##type(struct main_list_##type *var_list, size_t index, type value ){\
    struct list_##type * list_to_add = malloc(sizeof(struct list_##type));\
    list_to_add->value = value;\
    if(var_list->begin_list == NULL){\
      list_to_add->preview = NULL;\
      list_to_add->next = NULL;\
      var_list->begin_list = list_to_add;\
      var_list->end_list = list_to_add;\
      var_list->current_list = list_to_add;\
      var_list->current_index = 0;\
      \
    }else {\
      size_t ii =  move_current_to_index_list_##type(var_list, index);\
      if(index > ii)\
        printf("%ld out of range, we  put the value at %ld index of the list \n",index, ii);\
      if(var_list->current_list){\
        list_to_add->preview = (var_list->current_list)->preview;\
        list_to_add->next = var_list->current_list;\
        if(list_to_add->preview)\
          (list_to_add->preview)->next = list_to_add;\
        else var_list->begin_list = list_to_add;\
        (var_list->current_list)->preview = list_to_add;\
        var_list->current_list = list_to_add;\
      }\
    }\
    ++(var_list->size);\
  }\
  void remove_index_from_list_##type(struct main_list_##type *var_list, size_t index ){\
    if( index == move_current_to_index_list_##type(var_list, index)) {\
      struct list_##type * list_tmp_prev = (var_list->current_list)->preview;\
      struct list_##type * list_tmp_next = (var_list->current_list)->next;\
      if(list_tmp_prev){\
        list_tmp_prev->next = list_tmp_next;\
        if(list_tmp_next)  list_tmp_next->preview = list_tmp_prev;\
      }\
      free(var_list->current_list);\
      var_list->current_list = list_tmp_next;\
      --(var_list->size);\
      \
    }\
  }\
  void free_all_var_list_##type(struct main_list_##type *var_list){\
    struct list_##type *tmp = var_list->begin_list;\
    while(tmp){\
      var_list->current_list = tmp;\
      tmp = tmp->next;\
      free(var_list->current_list);\
    }\
    free(var_list);\
  }\
  void increment_list_##type(struct main_list_##type * var_list){\
    var_list->current_list = (var_list->current_list)->next;\
    ++(var_list->current_index);\
  }\
  void decrement_list_##type(struct main_list_##type * var_list){\
    var_list->current_list = (var_list->current_list)->preview;\
    --(var_list->current_index);\
  }\
  
#endif


GEN_LIST_ALL(TYPE_CHAR)
GEN_LIST_ALL(TYPE_U_CHAR)
GEN_LIST_ALL(TYPE_INT)
GEN_LIST_ALL(TYPE_U_INT)
GEN_LIST_ALL(TYPE_L_INT)
GEN_LIST_ALL(TYPE_U_L_INT)
GEN_LIST_ALL(TYPE_SIZE_T)
GEN_LIST_ALL(TYPE_FLOAT)
GEN_LIST_ALL(TYPE_DOUBLE)
GEN_LIST_ALL(TYPE_L_DOUBLE)
GEN_LIST_ALL(TYPE_STRING)

GEN_LIST_ALL(TYPE_PTR)

GEN_FUNC_PTR_LIST_FREE(TYPE_PTR){
  free(arg);
}
