/*file: "src/y_socket_t/y_list_string.c" */
#include "y_socket_t/y_list_string.h"

struct y_string * create_y_ptr_STRING(const char *buf, size_t size){
  struct y_string *string=malloc(sizeof(struct y_string));
  string->buf=malloc(size+1);
  if(buf){
    //strncpy(string->buf, buf, size);
    //snprintf(string->buf, size, "%s", buf);
    memcpy(string->buf, buf, size+1);
    //if(strlen(buf)>=size)
    if(buf[size]!='\0')
      string->buf[size]='\0';
//  printf("\nDEBUG: ################\n%ld~~%s~~\n################\n",size,string->buf);
  }
  string->size=size;
  return string;
}

GEN_LIST_ALL(y_ptr_STRING)

GEN_FUNC_PTR_LIST_FREE(y_ptr_STRING){
  free(arg->buf);
  free(arg);
}

size_t total_size_list_y_ptr_STRING(struct main_list_y_ptr_STRING *mstr){
  size_t total_size=0;
  for(struct list_y_ptr_STRING * local_current = mstr->begin_list; local_current; local_current = local_current->next){
    total_size += local_current->value->size;
  }
  //printf("debug: totalsize :%ld\n",total_size);
  return total_size;
}

size_t copy_list_y_ptr_STRING_to_one_string(char **p_dst_str, struct main_list_y_ptr_STRING *mstr){
  if(*p_dst_str == NULL){
    *p_dst_str=malloc(total_size_list_y_ptr_STRING(mstr));
  }
  char * dst_str = *p_dst_str;
  char *cur_str = dst_str;
  size_t local_size=0;
  size_t count_size=0;
  //for(move_current_to_begin_list_y_ptr_STRING(mstr); mstr->current_list; increment_list_y_ptr_STRING(mstr))
  for(struct list_y_ptr_STRING * local_current = mstr->begin_list; local_current; local_current = local_current->next){
    local_size = local_current->value->size;
    //printf(">>debug: countsize :%ld/local=%ld |%s|(%s)\n",count_size,local_size,local_current->value->buf,dst_str);
  //printf("debug: local_size :%ld\n",local_size);
    for(size_t i=0; i<local_size; ++i){
      cur_str[i]=local_current->value->buf[i];
    }
    count_size += local_size;
    //printf("<<debug: countsize :%ld/local=%ld |%s|(%s)\n",count_size,local_size,cur_str,dst_str);
    cur_str = dst_str + count_size;
  }
  *(dst_str + count_size - 1)='\0';
  
  //printf("debug: |%s|\n", dst_str);

  return count_size;

}
/* split string following sep! if limit_size_str_org < 0 it mean no limit */
struct main_list_y_ptr_STRING * split_str_to_main_list_y_ptr_STRING(char *str_org, char sep, size_t limit_size_str_org){
  struct main_list_y_ptr_STRING * m_str = create_var_list_y_ptr_STRING();
  char *buf = str_org;
  char *cur_str = str_org;
  size_t size_buf=0;
  size_t size_org_cur = 0;
  while(*cur_str && (cur_str-str_org < limit_size_str_org)){
    if(*cur_str != sep) ++cur_str;
    else{
      size_buf = cur_str - buf;
      y_ptr_STRING y_buf = create_y_ptr_STRING(buf, size_buf);
      push_back_list_y_ptr_STRING(m_str, y_buf);
      while(cur_str && *cur_str== sep) ++cur_str;
      buf = cur_str;
    }
    ++size_org_cur;
  }
  size_buf = cur_str - buf;
  if(size_buf){
    y_ptr_STRING y_buf = create_y_ptr_STRING(buf, size_buf);
    push_back_list_y_ptr_STRING(m_str, y_buf);
  }
  return m_str;
}

