#ifndef __LIST_T_C__H
#define __LIST_T_C__H

#include <pthread.h>

#include "tools_t/tools_t.h"

#define TYPE_PTR void*

#define GENERATE_LIST_ALL(type)\
  struct list_##type {\
    type value;\
    size_t index;\
    struct list_##type *preview;\
    struct list_##type *next;\
  };\
  struct main_list_##type {\
    struct list_##type *begin_list;\
    struct list_##type *current_list;\
    size_t current_index;\
    struct list_##type *end_list;\
    size_t size;\
    pthread_mutex_t *mut_list;\
  };\
  struct main_list_##type *create_var_list_##type();\
  void push_back_list_##type(struct main_list_##type *var_list, type value);\
  void push_front_list_##type(struct main_list_##type *var_list, type value);\
  size_t move_current_to_index_list_##type(struct main_list_##type *var_list, size_t index, struct list_##type **list_in_index);\
  size_t move_current_to_begin_list_##type(struct main_list_##type *var_list);\
  size_t move_current_to_end_list_##type(struct main_list_##type *var_list);\
  size_t insert_into_list_##type(struct main_list_##type *var_list, size_t index, type value );\
  void remove_index_from_list_##type(struct main_list_##type *var_list, size_t index );\
  struct list_##type* pull_index_from_list_##type(struct main_list_##type *var_list, size_t index );\
  void free_all_var_list_##type(struct main_list_##type *var_list);\
  void remove_all_list_in_##type(struct main_list_##type *var_list);\
  void increment_list_##type(struct main_list_##type * var_list);\
  void decrement_list_##type(struct main_list_##type * var_list);\
  struct list_##type * search_first_occ_with_mov_from_curr_in_list_##type(struct main_list_##type *var_list, type value, int (*funcCmp)(type, type),  struct list_##type * (*incr_or_decr_mov)(struct list_##type *));\
  struct list_##type * search_first_occ_from_begin_in_list_##type(struct main_list_##type *var_list, type value, int (*funcCmp)(type, type));\
  struct list_##type * search_first_occ_from_end_in_list_##type(struct main_list_##type *var_list, type value, int (*funcCmp)(type, type));\
  struct list_##type * pull_end_from_list_##type(struct main_list_##type *var_list);\
  struct list_##type * pull_begin_from_list_##type(struct main_list_##type *var_list);\
  void append_list_##type(struct main_list_##type *var_list, struct list_##type *list);\
  struct list_##type * local_increment_list_##type(struct list_##type *list);\
  struct list_##type * local_decrement_list_##type(struct list_##type *list);\
 

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

#define FOR_LIST_FORM_BEGIN(type, var_list)\
  for(move_current_to_begin_list_##type(var_list); var_list->current_list; increment_list_##type(var_list))

#define FOR_LIST_FORM_END(type, var_list)\
  for(move_current_to_end_list_##type(var_list); var_list->current_list; decrement_list_##type(var_list))


#define GEN_LIST_ALL(type)\
  \
  struct main_list_##type *create_var_list_##type(){\
    struct main_list_##type *ret_var_list = malloc(sizeof(struct main_list_##type));\
    ret_var_list->begin_list = NULL;\
    ret_var_list->end_list = NULL;\
    ret_var_list->current_list = NULL;\
    ret_var_list->current_index = 0;\
    ret_var_list->size = 0;\
    ret_var_list->mut_list = malloc(sizeof(pthread_mutex_t));\
    pthread_mutex_init(ret_var_list->mut_list, NULL);\
    return ret_var_list;\
  }\
  void push_back_list_##type(struct main_list_##type *var_list, type value){\
    struct list_##type * list_to_add = malloc(sizeof(struct list_##type));\
    list_to_add->value = value;\
    pthread_mutex_lock(var_list->mut_list);\
    list_to_add->index = var_list->size;\
    list_to_add->preview = var_list->end_list;\
    list_to_add->next = NULL;\
    if(var_list->end_list){\
      (var_list->end_list)->next = list_to_add;\
    }else {\
      var_list->begin_list = list_to_add;\
      var_list->current_list= list_to_add;\
      var_list->current_index=0;\
    }\
    var_list->end_list = list_to_add;\
    ++(var_list->size);\
    pthread_mutex_unlock(var_list->mut_list);\
  }\
  void push_front_list_##type(struct main_list_##type *var_list, type value){\
    struct list_##type * list_to_add = malloc(sizeof(struct list_##type));\
    list_to_add->value = value;\
    list_to_add->preview = NULL;\
    pthread_mutex_lock(var_list->mut_list);\
    list_to_add->next = var_list->begin_list;\
    if(var_list->begin_list){\
      (var_list->begin_list)->preview = list_to_add;\
      ++(var_list->current_index);\
    }else {\
      var_list->end_list = list_to_add;\
      var_list->current_list= list_to_add;\
      var_list->current_index=0;\
    }\
    var_list->begin_list = list_to_add;\
    ++(var_list->size);\
    size_t index=0;\
    while(list_to_add){\
      list_to_add->index = index++;\
      list_to_add = list_to_add->next;\
    }\
    pthread_mutex_unlock(var_list->mut_list);\
  }\
  size_t move_current_to_index_list_##type(struct main_list_##type *var_list, size_t index, struct list_##type **list_in_index){\
    pthread_mutex_lock(var_list->mut_list);\
    if(var_list->current_list==NULL) {;\
      if(index <= var_list->size - 1 - index){\
        var_list->current_list = var_list->begin_list;\
      }else{\
      var_list->current_list = var_list->end_list;\
      }\
    }\
    if(index == var_list->current_list->index){\
      if(list_in_index) *list_in_index = var_list->current_list;\
      pthread_mutex_unlock(var_list->mut_list);\
      return index;\
    }\
    if(var_list->begin_list == NULL){\
      if(list_in_index) *list_in_index=NULL;\
      pthread_mutex_unlock(var_list->mut_list);\
      return 0;\
    }\
    if(index >= var_list->size){\
      var_list->current_list = var_list->end_list;\
      var_list->current_index = var_list->size - 1;\
      if(list_in_index) *list_in_index = var_list->current_list;\
      pthread_mutex_unlock(var_list->mut_list);\
      return var_list->current_list->index /*size - 1*/;\
    }\
    /*if((var_list->current_list->index >= var_list->size) || !(var_list->current_list)){\
      var_list->current_list = var_list->end_list;\
      var_list->current_index = var_list->size - 1;\
    }*/\
    long from_current_index = var_list->current_list->index - index; \
    size_t abs_cur_diff = abs(from_current_index); \
    size_t array_diff_index[3]  = {index, abs_cur_diff , var_list->size - 1 - index}; \
    size_t index_nearest = ARG_MIN_ARRAY_TYPE_SIZE_T(array_diff_index, 3);\
    if(index_nearest == 0){\
      var_list->current_list = var_list->begin_list;\
      for(size_t i=0; i<array_diff_index[0]; ++i) var_list->current_list = (var_list->current_list)->next; \
    }\
    else if(index_nearest == 2){\
      var_list->current_list = var_list->end_list;\
      for(size_t i=0; i < array_diff_index[2]; ++i) var_list->current_list = (var_list->current_list)->preview; \
    }else if(from_current_index >= 0) \
      for(size_t i=0; i < array_diff_index[1]; ++i) var_list->current_list = (var_list->current_list)->preview; \
    else  \
      for(size_t i=0; i < array_diff_index[1]; ++i) var_list->current_list = (var_list->current_list)->next; \
      \
    var_list->current_index = index;\
    if(list_in_index) *list_in_index = var_list->current_list;\
    pthread_mutex_unlock(var_list->mut_list);\
    return index;\
  }\
  size_t move_current_to_begin_list_##type(struct main_list_##type *var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    if(var_list->begin_list == NULL){\
      pthread_mutex_unlock(var_list->mut_list);\
      return 0;\
    }\
    var_list->current_list = var_list->begin_list;\
    var_list->current_index = 0;\
    pthread_mutex_unlock(var_list->mut_list);\
    return 0;\
  }\
  size_t move_current_to_end_list_##type(struct main_list_##type *var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    if(var_list->end_list == NULL){\
      pthread_mutex_unlock(var_list->mut_list);\
      return 0;\
    }\
    var_list->current_list = var_list->end_list;\
    var_list->current_index = var_list->size - 1;\
    pthread_mutex_unlock(var_list->mut_list);\
    return var_list->current_index;\
  }\
  size_t insert_into_list_##type(struct main_list_##type *var_list, size_t index, type value ){\
    struct list_##type * list_to_add = malloc(sizeof(struct list_##type));\
    size_t ii=0;\
    list_to_add->value = value;\
    if(var_list->begin_list == NULL){\
      pthread_mutex_lock(var_list->mut_list);\
      list_to_add->preview = NULL;\
      list_to_add->next = NULL;\
      var_list->begin_list = list_to_add;\
      var_list->end_list = list_to_add;\
      var_list->current_list = list_to_add;\
      var_list->current_index = 0;\
      \
    }else {\
      struct list_##type *current_list;\
      ii =  move_current_to_index_list_##type(var_list, index, &current_list);\
      pthread_mutex_lock(var_list->mut_list);\
      if(index > ii)\
        printf("%ld out of range, we  put the value at %ld index of the list \n",index, ii);\
      if(current_list){\
        struct list_##type *prev_list = (current_list)->preview;\
        list_to_add->preview = prev_list;\
        list_to_add->next = current_list;\
        if(list_to_add->preview == NULL){\
          var_list->begin_list = list_to_add;\
        }else\
          prev_list->next = list_to_add;\
        if(list_to_add->next == NULL)\
          var_list->end_list = list_to_add;\
        (current_list)->preview = list_to_add;\
        var_list->current_list = list_to_add;\
        var_list->current_index = ii;\
      }\
    }\
    ++(var_list->size);\
    size_t local_ii = ii;\
    while(list_to_add){\
      list_to_add->index = local_ii++;\
      list_to_add = list_to_add->next;\
    }\
    pthread_mutex_unlock(var_list->mut_list);\
    return ii;\
  }\
  void remove_index_from_list_##type(struct main_list_##type *var_list, size_t index ){\
    struct list_##type *current_list;\
    if( index == move_current_to_index_list_##type(var_list, index, &current_list)) {\
      pthread_mutex_lock(var_list->mut_list);\
      struct list_##type * list_tmp_prev = (current_list)->preview;\
      struct list_##type * list_tmp_next = (current_list)->next;\
      if(list_tmp_prev){\
        list_tmp_prev->next = list_tmp_next;\
        if(list_tmp_next){\
          list_tmp_next->preview = list_tmp_prev;\
          var_list->current_list = list_tmp_next;\
        }\
        else {\
          var_list->end_list = list_tmp_prev;\
          var_list->current_list = list_tmp_prev;\
        }\
      }else{\
        var_list->begin_list = list_tmp_next;\
        if(list_tmp_next) {\
          list_tmp_next->preview = list_tmp_prev;\
        }\
        else{\
          var_list->end_list = NULL;\
          var_list->current_list = NULL;\
        }\
      }\
      free(current_list);\
      --(var_list->size);\
      while(list_tmp_next){\
        list_tmp_next->index = index++;\
        list_tmp_next=list_tmp_next->next;\
      }\
      pthread_mutex_unlock(var_list->mut_list);\
    }\
  }\
  struct list_##type * pull_index_from_list_##type(struct main_list_##type *var_list, size_t index ){\
    struct list_##type *current_list=NULL;\
    if( index == move_current_to_index_list_##type(var_list, index, &current_list)) {\
      pthread_mutex_lock(var_list->mut_list);\
      struct list_##type * list_tmp_prev = (current_list)->preview;\
      struct list_##type * list_tmp_next = (current_list)->next;\
      if(list_tmp_prev){\
        list_tmp_prev->next = list_tmp_next;\
        if(list_tmp_next){\
          list_tmp_next->preview = list_tmp_prev;\
          var_list->current_list = list_tmp_next;\
        }\
        else {\
          var_list->end_list = list_tmp_prev;\
          var_list->current_list = list_tmp_prev;\
        }\
      }else{\
        var_list->begin_list = list_tmp_next;\
        if(list_tmp_next) {\
          list_tmp_next->preview = list_tmp_prev;\
        }\
        else{\
          var_list->end_list = NULL;\
          var_list->current_list = NULL;\
        }\
      }\
      --(var_list->size);\
      while(list_tmp_next){\
        list_tmp_next->index = index++;\
        list_tmp_next=list_tmp_next->next;\
      }\
      pthread_mutex_unlock(var_list->mut_list);\
    }\
    return current_list;\
  }\
  void remove_all_list_in_##type(struct main_list_##type *var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    struct list_##type *tmp = var_list->begin_list, *prec_tmp;\
    while(tmp){\
      prec_tmp = tmp;\
      tmp = tmp->next;\
      free(prec_tmp);\
    }\
    var_list->begin_list = NULL;\
    var_list->current_list = NULL;\
    var_list->end_list = NULL;\
    var_list->size = 0;\
    var_list->current_index = 0;\
    pthread_mutex_unlock(var_list->mut_list);\
  }\
  void free_all_var_list_##type(struct main_list_##type *var_list){\
    remove_all_list_in_##type(var_list);\
    pthread_mutex_destroy(var_list->mut_list);\
    free(var_list->mut_list);\
    free(var_list);\
  }\
  void increment_list_##type(struct main_list_##type * var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    var_list->current_list = (var_list->current_list)->next;\
    ++(var_list->current_index);\
    pthread_mutex_unlock(var_list->mut_list);\
  }\
  void decrement_list_##type(struct main_list_##type * var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    var_list->current_list = (var_list->current_list)->preview;\
    --(var_list->current_index);\
    pthread_mutex_unlock(var_list->mut_list);\
  }\
  struct list_##type * local_increment_list_##type(struct list_##type *list){\
    if(list) return list->next;\
    return NULL;\
  }\
  struct list_##type * local_decrement_list_##type(struct list_##type *list){\
    if (list) return list->preview;\
    return NULL;\
  }\
  struct list_##type * search_first_occ_with_mov_from_curr_in_list_##type(struct main_list_##type *var_list, type value, int (*funcCmp)(type, type), struct list_##type * (*incr_or_decr_mov)(struct list_##type *)){\
    pthread_mutex_lock(var_list->mut_list);\
    for(struct list_##type *list_cur = var_list->current_list; list_cur; list_cur = incr_or_decr_mov(list_cur)){\
      if(0 == funcCmp(value, list_cur->value)){\
        pthread_mutex_unlock(var_list->mut_list);\
        return list_cur;\
      }\
    }\
    pthread_mutex_unlock(var_list->mut_list);\
    return NULL;\
  }\
  struct list_##type * search_first_occ_from_begin_in_list_##type(struct main_list_##type *var_list, type value, int (*funcCmp)(type, type)){\
    pthread_mutex_lock(var_list->mut_list);\
    /*printf("debug: cur_index change to 0");*/\
    var_list->current_list = var_list->begin_list;\
    pthread_mutex_unlock(var_list->mut_list);\
    return search_first_occ_with_mov_from_curr_in_list_##type(var_list, value, funcCmp, local_increment_list_##type);\
  }\
  struct list_##type * search_first_occ_from_end_in_list_##type(struct main_list_##type *var_list, type value, int (*funcCmp)(type, type)){\
    pthread_mutex_lock(var_list->mut_list);\
    /*printf("debug: cur_index change to end");*/\
    var_list->current_list = var_list->end_list;\
    pthread_mutex_unlock(var_list->mut_list);\
    return search_first_occ_with_mov_from_curr_in_list_##type(var_list, value, funcCmp, local_decrement_list_##type);\
  }\
  struct list_##type * pull_end_from_list_##type(struct main_list_##type *var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    struct list_##type *ret = var_list->end_list;\
    if(ret != NULL){\
      struct list_##type * prevL = ret->preview;\
      if(prevL != NULL){\
        prevL->next=NULL;\
      }else{\
        var_list->begin_list=NULL;\
        var_list->current_index = 0;\
        var_list->current_list=NULL;\
      }\
      var_list->end_list = prevL;\
      --(var_list->size);\
      ret->preview = NULL;\
    }\
    pthread_mutex_unlock(var_list->mut_list);\
    return ret;\
  }\
  struct list_##type * pull_begin_from_list_##type(struct main_list_##type *var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    struct list_##type *ret = var_list->begin_list;\
    if(ret != NULL){\
      struct list_##type * nextL = ret->next;\
      if(nextL != NULL){\
        nextL->preview=NULL;\
      }else{\
        var_list->end_list=NULL;\
        var_list->current_index = 0;\
        var_list->current_list=NULL;\
      }\
      var_list->begin_list = nextL;\
      --(var_list->size);\
      ret->next = NULL;\
    }\
    struct list_##type *tmp = var_list->begin_list;\
    while(tmp){ --(tmp->index); tmp=tmp->next;}\
    pthread_mutex_unlock(var_list->mut_list);\
    return ret;\
  }\
  void append_list_##type(struct main_list_##type *var_list, struct list_##type *list){\
    pthread_mutex_lock(var_list->mut_list);\
    list->index = var_list->size;\
    if(var_list->end_list == NULL){\
      list->preview = NULL;\
      var_list->end_list = list;\
      var_list->begin_list = list;\
      var_list->current_list = list;\
      var_list->current_index = 0;\
    }else{\
      var_list->end_list->next = list;\
      list->preview = var_list->end_list;\
      var_list->end_list = list;\
    }\
    ++(var_list->size);\
    pthread_mutex_unlock(var_list->mut_list);\
  }\
  

#define GEN_HEAD_PTR_LIST(type)\
  void remove_all_ptr_type_list_##type(struct main_list_##type *var_list);\
  void purge_ptr_type_list_##type(struct main_list_##type *var_list);\
  void free_##type(type arg);\



#define GEN_FUNC_PTR_LIST_FREE(type)\
  void remove_all_ptr_type_list_##type(struct main_list_##type *var_list){\
    pthread_mutex_lock(var_list->mut_list);\
    struct list_##type *tmp = var_list->begin_list, *prec_tmp;\
    while(tmp){\
      prec_tmp = tmp;\
      tmp = tmp->next;\
      free_##type(prec_tmp->value);\
      free(prec_tmp);\
    }\
    var_list->begin_list = NULL;\
    var_list->current_list = NULL;\
    var_list->end_list = NULL;\
    var_list->size = 0;\
    var_list->current_index = 0;\
    pthread_mutex_unlock(var_list->mut_list);\
  }\
  void purge_ptr_type_list_##type(struct main_list_##type *var_list){\
    remove_all_ptr_type_list_##type(var_list);\
    pthread_mutex_destroy(var_list->mut_list);\
    free(var_list->mut_list);\
		free(var_list);\
  }\
  \
  void free_##type(type arg)\


GEN_HEAD_PTR_LIST(TYPE_PTR)


#define LIST_T(type) \
    GENERATE_LIST_ALL(type)\
    GEN_LIST_ALL(type)



#endif /* __LIST_T_C__H */

