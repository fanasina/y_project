/*file: "src/y_socket_t/y_list_var_tool.c" */
#include "y_socket_t/y_list_var_tool.h"

long  long_time_id(){
 // char *filename=malloc(256);
  //char timeid[64];//="20251011215824";
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  //sprintf(timeid,"%d%02d%02d%02d%02d%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

  long long_tm = (tm.tm_year + 1900)*10000000000+ (tm.tm_mon + 1)*100000000+ tm.tm_mday*1000000 + tm.tm_hour*10000+ tm.tm_min*100+ tm.tm_sec ;
  //return filename;
  ///printf("debug: timeid=%s, vs tm=%ld\n",timeid, intm);
  //printf("debug: timeof=%ld, vs tm=%ld, tm_zone=%s\n",tm.tm_gmtoff, long_tm, tm.tm_zone);
  return long_tm;
}
char * time_id(){
 // char *filename=malloc(256);
  char *timeid=malloc(128);
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(timeid,"%d%02d%02d%02d%02d%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
  //printf("debug: TTT \n%ld\n",int_time_id());
  return timeid;
  //return filename;
}


struct y_variable * create_y_ptr_VARIABLE(const char *name, size_t size_name, void * value, size_t size_value, char *src){
  struct y_variable *variable=malloc(sizeof(struct y_variable));
  variable->size_name = size_name;
  variable->name=malloc(size_name+1);
  if(name){
    memcpy(variable->name, name, size_name+1);
    if(name[size_name]!='\0')
      variable->name[size_name]='\0';
  }
  variable->size_value = size_value;
  variable->value=malloc(size_value);
  memcpy(variable->value, value, size_value);
  
  variable->time_l = long_time_id();
  if(src){
    memcpy(variable->src, src, 64);
  }else{
    memset(variable->src, 0, 64);
  }

  return variable;
}

GEN_LIST_ALL(y_ptr_VARIABLE)

GEN_FUNC_PTR_LIST_FREE(y_ptr_VARIABLE){
  free(arg->name);
  free(arg->value);
  free(arg);
}

int y_ptr_VARIABLE_cmp(y_ptr_VARIABLE varA, y_ptr_VARIABLE varB){
  return strcmp(varA->name, varB->name);
}

struct list_y_ptr_VARIABLE * search_variable_in_list_y_ptr_VARIABLE(struct main_list_y_ptr_VARIABLE *listVariables, y_ptr_VARIABLE var){

  return search_first_occ_from_end_in_list_y_ptr_VARIABLE(listVariables, var, y_ptr_VARIABLE_cmp);
  //return search_first_occ_from_begin_in_list_y_NODE_T(listNodes, node, y_NODE_T_cmp);
}

void update_list_y_ptr_VARIABLE_then_free_if_needed(struct main_list_y_ptr_VARIABLE *listVariables, y_ptr_VARIABLE var){
  struct list_y_ptr_VARIABLE * l_y_ptr_var = search_variable_in_list_y_ptr_VARIABLE(listVariables, var);
  if(l_y_ptr_var){
    memcpy(l_y_ptr_var->value->value, var->value, var->size_value);
    l_y_ptr_var->value->time_l = var->time_l;
    free_y_ptr_VARIABLE(var);
  }
  else{
    push_back_list_y_ptr_VARIABLE(listVariables, var);
  }
}

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

void usage_cmdl(){
  printf("usage:\n"
  "sendto [addr] { \"cmd\" : \"[command]\" }\n"
  "addr: ipv4 address or ipv6 address \n"
  "\tor all to send cmd to all nodes already in the list.\n"
  "\tor other to send cmd to all nodes excluding local address in the list.\n"
  "command: \n"
  "\tupdate kill: to gracefully shutdown socket server.\n"
  "\tupdate standby: to suspend all workers, but can receive all task but in queu tasks.\n"
  "\tupdate wakeup: to wakeup all workers, and then execute all tasks in queu.\n"
  "\tupdate remove node [addr]: to remove [addr] in the list.\n"
  "\tupdate add node [addr]: to add [addr] in the list.\n"
  "\tget file [filename]: to ask server to send file named [filename].\n"
  "\t\tfilename can be absolute path or relative working directory path\n"
  "\tpost file [filename] : to send file [filename] after header.\n"
  "\t\tNeed to add \"seq\" and \"tm\" keys to have good handling, the payload is after the header {}\n"
  "\t\tSee y_socket_send_file_for_node function.\n"
  "\tpost ok [filenameid]: to acknowledge receipt [filename].\n"
  "\t\t[filenameid] is to precise witch [filename] (file name from whom and when)\n"
  );
}
