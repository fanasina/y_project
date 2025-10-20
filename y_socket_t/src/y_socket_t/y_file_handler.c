/*file: src/y_socket_t/y_file_handler.c*/

#include "y_socket_t/y_file_handler.h"

#define TTL_SOCKDRAM 10 

#define REPO_LOCAL ".dest"
#define LEN_REPO_LOCAL 6

//#include "y_socket_t/y_node_t.h"

GEN_LIST_ALL(y_ptr_MSG_CONTENT_T)

GEN_FUNC_PTR_LIST_FREE(y_ptr_MSG_CONTENT_T){
  free(arg->content);
  free(arg->nameid);
  free(arg);
}


GEN_LIST_ALL(y_ptr_HEADER_T)

GEN_FUNC_PTR_LIST_FREE(y_ptr_HEADER_T){
//  free(arg->content);
  free(arg->nameid);
  purge_ptr_type_list_y_ptr_MSG_CONTENT_T(arg->m_content_l);
  free(arg);
}

y_ptr_MSG_CONTENT_T create_y_ptr_MSG_CONTENT_T(char *nameid, size_t size_nameid, char* content, size_t size_content,
  enum cmd_type cmd_t,
  size_t seq,
  char eof
){
  y_ptr_MSG_CONTENT_T new_p_content = malloc(sizeof(struct msg_content_t));

  new_p_content->size_content = size_content;
  new_p_content->content = malloc(size_content+1);
  memcpy(new_p_content->content, content, size_content);
  new_p_content->content[size_content]='\0';
  new_p_content->size_nameid = size_nameid;
  new_p_content->nameid = malloc(size_nameid+1);
  memcpy(new_p_content->nameid, nameid, size_nameid);
  new_p_content->nameid[size_nameid]='\0';

  
  new_p_content->cmd_t = cmd_t;
  new_p_content->seq = seq;
  new_p_content->eof = eof;

  return new_p_content;

}

y_ptr_HEADER_T create_y_ptr_HEADER_T(char *nameid, size_t size_nameid, enum cmd_type cmd_t   ){
  y_ptr_HEADER_T new_header_t = malloc(sizeof(struct header_t));
  new_header_t->cmd_t = cmd_t;
  new_header_t->size_nameid = size_nameid;
  new_header_t->nameid = malloc(size_nameid+1);
  memcpy(new_header_t->nameid, nameid, size_nameid);
  new_header_t->nameid[size_nameid]='\0';

  new_header_t->m_content_l = create_var_list_y_ptr_MSG_CONTENT_T();

  return new_header_t;
   

}

int funcCmp_y_ptr_HEADER_T(y_ptr_HEADER_T h1, y_ptr_HEADER_T h2){
  if(h1==NULL || h2==NULL) return -1;
  if(h1->size_nameid == h2->size_nameid){
    if(h1->cmd_t == h2->cmd_t){
      return strcmp(h1->nameid, h2->nameid);
    }else return (h1->cmd_t - h2->cmd_t);
  }else if(h1->size_nameid < h2->size_nameid){ 
    return -1;
  }else return 1;
}

int funcCmp_y_ptr_HEADER_T_fn_nameid_mask(y_ptr_HEADER_T h1, y_ptr_HEADER_T h2){
  if(h1==NULL || h2==NULL) return -1;
  struct main_list_y_ptr_STRING * m_h1_nameid = split_str_to_main_list_y_ptr_STRING(h1->nameid,'_', h1->size_nameid);
  struct main_list_y_ptr_STRING * m_h2_nameid = split_str_to_main_list_y_ptr_STRING(h2->nameid,'_', h2->size_nameid);
	
	//int count_match = 0;
	struct main_list_TYPE_SIZE_T * m_index_not_match = create_var_list_TYPE_SIZE_T();
	int ret = 0;
  ///printf("debug: size1=%ld vs size2=%ld\n",m_h1_nameid->size, m_h2_nameid->size);
	if(m_h1_nameid->size != m_h2_nameid->size) {
	  ret = -2;
	}else{
		for(struct list_y_ptr_STRING *l_h1_ = m_h1_nameid->end_list, *l_h2_ = m_h2_nameid->end_list; l_h1_ && l_h2_; l_h1_ = l_h1_->preview, l_h2_=l_h2_->preview){
			if(l_h1_->index != m_h1_nameid->size - 2){
				if(strcmp(l_h1_->value->buf, l_h2_->value->buf )==0){
					//++count_match ;
          ///printf("debug: match [%ld] ! %s == %s !", l_h1_->index, l_h1_->value->buf, l_h2_->value->buf);
				}
				else{
          ///printf("debug: NOT match [%ld] ! %s != %s !", l_h1_->index, l_h1_->value->buf, l_h2_->value->buf);
			  	push_back_list_TYPE_SIZE_T(m_index_not_match, l_h1_->index);
				}
			}

		}
	

    if(m_index_not_match->size) {
      //debug
#if 0 
      for(struct list_y_ptr_STRING *l_h1_ = m_h1_nameid->end_list, *l_h2_ = m_h2_nameid->end_list; l_h1_ && l_h2_; l_h1_ = l_h1_->preview, l_h2_=l_h2_->preview){
        
        for(struct list_TYPE_SIZE_T * l_in = m_index_not_match->begin_list; l_in; l_in=l_in->next){
          if(l_h1_->index == l_in->value){
            printf("debug: DIFF ** **  %ld: %s vs %s ** **\n",l_in->value, l_h1_->value->buf, l_h2_->value->buf);
          }
        }
      }
#endif
      
      ret = -1;
    }
    else ret = 0;
    
    
  }
    purge_ptr_type_list_y_ptr_STRING(m_h1_nameid);
    purge_ptr_type_list_y_ptr_STRING(m_h2_nameid);
    free_all_var_list_TYPE_SIZE_T(m_index_not_match);
    ///printf("check_if_in_ok_header_l_ ret=%d, %s ns %s\n",ret,h1->nameid, h2->nameid);
	return ret;
}


long check_if_in_ok_header_l_(struct main_list_y_ptr_HEADER_T *m_ok_head_l_t, char *nameid ){
    
  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(nameid, strlen(nameid), cmd_post_ok );
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_end_in_list_y_ptr_HEADER_T(m_ok_head_l_t, current_header, funcCmp_y_ptr_HEADER_T_fn_nameid_mask);
  free_y_ptr_HEADER_T(current_header);
  
	if(l_ocate_header){
		return 1;
	}
	return 0;
}

void remove_header_ok_if_done(struct main_list_y_ptr_HEADER_T *m_ok_head_l_t, char *nameid ){
    
  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(nameid, strlen(nameid), cmd_post_ok );
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_end_in_list_y_ptr_HEADER_T(m_ok_head_l_t, current_header, funcCmp_y_ptr_HEADER_T_fn_nameid_mask);
  free_y_ptr_HEADER_T(current_header);
  
	if(l_ocate_header){
		struct list_y_ptr_HEADER_T * l_head_to_remove = pull_index_from_list_y_ptr_HEADER_T(m_ok_head_l_t, l_ocate_header->index);
    free_y_ptr_HEADER_T(l_head_to_remove->value);
    free(l_head_to_remove);
    printf("debug: remove_header_ok_if_done %s\n",nameid);
	}
	
}

long y_append_to_ok_header_l_(struct main_list_y_ptr_HEADER_T *m_ok_head_l_t, char *nameid ){
    
  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(nameid, strlen(nameid), cmd_post_ok );
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_end_in_list_y_ptr_HEADER_T(m_ok_head_l_t, current_header, funcCmp_y_ptr_HEADER_T);
  if(l_ocate_header){
		free_y_ptr_HEADER_T(current_header);
		///printf("debug: already in m_ok_head_l_t");
		return -1; // already in list

	}
  else{
    push_back_list_y_ptr_HEADER_T(m_ok_head_l_t, current_header);
    ///printf("debug:  push_back_list_y_ptr_HEADER_T when l_ocate_header == NULL, m_head_l_t->size=%ld\n",m_ok_head_l_t->size);
    return m_ok_head_l_t->size;
  }
}

#define TEST_DUPLICATE_SEQ()\
      if(temp_curr->value->seq == cnt->seq){\
          /*printf("debug: index_nearest_seq=%ld: seq equal: doublon problem ? seq:%ld appuyer sur une touche\n", index_nearest_seq, cnt->seq);\
          */free_y_ptr_MSG_CONTENT_T(cnt); \
          /*getchar();*/\
          return -2;\
      }
        
long y_append_content_to_header_l(struct main_list_y_ptr_HEADER_T *m_head_l_t, y_ptr_MSG_CONTENT_T cnt){
  
  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(cnt->nameid, cnt->size_nameid, cnt->cmd_t);
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_end_in_list_y_ptr_HEADER_T(m_head_l_t, current_header, funcCmp_y_ptr_HEADER_T);
  ///printf("debug: search done, nameid:%s, #%ld\n",cnt->nameid, cnt->size_nameid);
  if(l_ocate_header){
    free_y_ptr_HEADER_T(current_header);
    pthread_mutex_t *mut_m_content_l = l_ocate_header->value->m_content_l->mut_list;
    pthread_mutex_lock(mut_m_content_l);
    struct list_y_ptr_MSG_CONTENT_T * current_cnt = l_ocate_header->value->m_content_l->current_list;
    struct list_y_ptr_MSG_CONTENT_T * end_cnt = l_ocate_header->value->m_content_l->end_list;
    struct list_y_ptr_MSG_CONTENT_T * begin_cnt = l_ocate_header->value->m_content_l->begin_list;
    
    if(begin_cnt == NULL){ 
      pthread_mutex_unlock(mut_m_content_l);
      ///printf("debug: current_cnt==NULL, size_ m_content_l=%ld cnt->seq=%ld, push_back_list_y_ptr_MSG_CONTENT_T\n", l_ocate_header->value->m_content_l->size, cnt->seq);
      push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
      ///printf("debug: after current_cnt==NULL, size_ m_content_l=%ld cnt->seq=%ld, push_back_list_y_ptr_MSG_CONTENT_T\n", l_ocate_header->value->m_content_l->size, cnt->seq);
      return 0;
    }
    long last_seq = end_cnt->value->seq;
    if(cnt->seq > last_seq){
      pthread_mutex_unlock(mut_m_content_l);
      push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
      return 0;
    }
    
    struct list_y_ptr_MSG_CONTENT_T *temp_curr = NULL;
    
    long from_current_seq = current_cnt->value->seq - cnt->seq;
    size_t abs_cur_diff_seq = abs(from_current_seq);
    size_t array_diff_seq[3]  = {cnt->seq -  begin_cnt->value->seq, abs_cur_diff_seq , end_cnt->value->seq - cnt->seq};
    size_t index_nearest_seq = ARG_MIN_ARRAY_TYPE_SIZE_T(array_diff_seq, 3);
    if(index_nearest_seq == 0){
      for(temp_curr = begin_cnt ;temp_curr && (temp_curr->value->seq < cnt->seq); temp_curr = temp_curr->next){} 
      if(temp_curr){
        l_ocate_header->value->m_content_l->current_list = temp_curr;
        pthread_mutex_unlock(mut_m_content_l);
        TEST_DUPLICATE_SEQ()
        return insert_into_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, temp_curr->index, cnt);
      }else{
        pthread_mutex_unlock(mut_m_content_l);
        push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
        return 0;
      }
    }
    else if(index_nearest_seq == 2){
      
      for(temp_curr = end_cnt; temp_curr && temp_curr->value->seq > cnt->seq; temp_curr = temp_curr->preview) {}
      if(temp_curr){
        l_ocate_header->value->m_content_l->current_list = temp_curr;
        pthread_mutex_unlock(mut_m_content_l);
        TEST_DUPLICATE_SEQ()
        return insert_into_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, temp_curr->index + 1, cnt);
      }else{
        pthread_mutex_unlock(mut_m_content_l);
        push_front_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
        return 0;
      }
    }else if(from_current_seq >= 0) {
      for(temp_curr = current_cnt; temp_curr && temp_curr->value->seq > cnt->seq; temp_curr = temp_curr->preview) {}
      if(temp_curr){
        l_ocate_header->value->m_content_l->current_list = temp_curr;
        pthread_mutex_unlock(mut_m_content_l);
        TEST_DUPLICATE_SEQ()
        return insert_into_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, temp_curr->index + 1, cnt);
      }else{
        pthread_mutex_unlock(mut_m_content_l);
        push_front_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
        return 0;
      }

    }else{  
      for(temp_curr = current_cnt ;temp_curr && (temp_curr->value->seq < cnt->seq); temp_curr = temp_curr->next){} 
      if(temp_curr){
        l_ocate_header->value->m_content_l->current_list = temp_curr;
        pthread_mutex_unlock(mut_m_content_l);
        TEST_DUPLICATE_SEQ()
        return insert_into_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, temp_curr->index, cnt);
      }else{
        pthread_mutex_unlock(mut_m_content_l);
        push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
        return 0;
      }
    }


#if 0
       // cnt->seq < last_seq
    while(current_cnt){
      printf("debug: last_seq: %ld, cnt->seq=%ld, current_cnt->value->seq:%ld\n", last_seq, cnt->seq,current_cnt->value->seq);
      if(cnt->seq == current_cnt->value->seq){
        printf("debug: equal last_seq: %ld, cnt->seq=%ld, current_cnt->value->seq:%ld\n", last_seq, cnt->seq,current_cnt->value->seq);
        //return -2;
      }
      if(cnt->seq < last_seq && cnt->seq > current_cnt->value->seq){
        pthread_mutex_unlock(mut_m_content_l);
      /*if(cnt->seq > last_seq && cnt->seq < current_cnt->value->seq)*/
        return insert_into_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, current_cnt->index + 1, cnt);
      }else if(current_cnt->preview==NULL){
        pthread_mutex_unlock(mut_m_content_l);
        push_front_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
        return 0;
      }
      last_seq = current_cnt->value->seq;
      current_cnt = current_cnt->preview;
      
    }
    printf("debug: some thing wrong here! last_seq: %ld, cnt->seq=%ld\n", last_seq, cnt->seq);
    return -1;
#endif
  }
  else{
    push_back_list_y_ptr_MSG_CONTENT_T(current_header->m_content_l, cnt);
    push_back_list_y_ptr_HEADER_T(m_head_l_t, current_header);
    ///printf("debug:  push_back_list_y_ptr_HEADER_T when l_ocate_header == NULL, m_head_l_t->size=%ld\n",m_head_l_t->size);
    return 0;
  }
}



long y_append_content_to_header_l_from_end(struct main_list_y_ptr_HEADER_T *m_head_l_t, y_ptr_MSG_CONTENT_T cnt){
  
  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(cnt->nameid, cnt->size_nameid, cnt->cmd_t);
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_begin_in_list_y_ptr_HEADER_T(m_head_l_t, current_header, funcCmp_y_ptr_HEADER_T);
  ///printf("debug: search done, nameid:%s, #%ld\n",cnt->nameid, cnt->size_nameid);
  if(l_ocate_header){
    free_y_ptr_HEADER_T(current_header);
    struct list_y_ptr_MSG_CONTENT_T * current_cnt = l_ocate_header->value->m_content_l->end_list;
    if(current_cnt == NULL){ 
      ///printf("debug: current_cnt==NULL, size_ m_content_l=%ld cnt->seq=%ld, push_back_list_y_ptr_MSG_CONTENT_T\n", l_ocate_header->value->m_content_l->size, cnt->seq);
      push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
      ///printf("debug: after current_cnt==NULL, size_ m_content_l=%ld cnt->seq=%ld, push_back_list_y_ptr_MSG_CONTENT_T\n", l_ocate_header->value->m_content_l->size, cnt->seq);
      return 0;
    }
    long last_seq = current_cnt->value->seq + 1;
    if(cnt->seq >= last_seq){
      push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
      return 0;
    }
    // cnt->seq < last_seq
    while(current_cnt){
      ///printf("debug: last_seq: %ld, cnt->seq=%ld, current_cnt->value->seq:%ld\n", last_seq, cnt->seq,current_cnt->value->seq);
      ///if(cnt->seq == current_cnt->value->seq){
        ///printf("debug: equal last_seq: %ld, cnt->seq=%ld, current_cnt->value->seq:%ld\n", last_seq, cnt->seq,current_cnt->value->seq);
        //return -2;
      ///}
      if(cnt->seq < last_seq && cnt->seq > current_cnt->value->seq){
      /*if(cnt->seq > last_seq && cnt->seq < current_cnt->value->seq)*/
        return insert_into_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, current_cnt->index + 1, cnt);
      }else if(current_cnt->preview==NULL){
        push_front_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
        return 0;
      }
      last_seq = current_cnt->value->seq;
      current_cnt = current_cnt->preview;
      
    }
    ///printf("debug: some thing wrong here! last_seq: %ld, cnt->seq=%ld\n", last_seq, cnt->seq);
    return -1;

  }
  else{
    push_back_list_y_ptr_MSG_CONTENT_T(current_header->m_content_l, cnt);
    push_back_list_y_ptr_HEADER_T(m_head_l_t, current_header);
    ///printf("debug:  push_back_list_y_ptr_HEADER_T when l_ocate_header == NULL, m_head_l_t->size=%ld\n",m_head_l_t->size);
    return 0;
  }
}


long y_append_content_to_header_l_from_begin(struct main_list_y_ptr_HEADER_T *m_head_l_t, y_ptr_MSG_CONTENT_T cnt){
  
  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(cnt->nameid, cnt->size_nameid, cnt->cmd_t);
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_begin_in_list_y_ptr_HEADER_T(m_head_l_t, current_header, funcCmp_y_ptr_HEADER_T);
  ///printf("debug: search done, nameid:%s, #%ld\n",cnt->nameid, cnt->size_nameid);
  if(l_ocate_header){
    free_y_ptr_HEADER_T(current_header);
    struct list_y_ptr_MSG_CONTENT_T * current_cnt = l_ocate_header->value->m_content_l->begin_list;
    if(current_cnt == NULL){ 
      ///printf("debug: current_cnt==NULL, size_ m_content_l=%ld cnt->seq=%ld, push_back_list_y_ptr_MSG_CONTENT_T\n", l_ocate_header->value->m_content_l->size, cnt->seq);
      push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
      ///printf("debug: after current_cnt==NULL, size_ m_content_l=%ld cnt->seq=%ld, push_back_list_y_ptr_MSG_CONTENT_T\n", l_ocate_header->value->m_content_l->size, cnt->seq);
      return 0;
    }
    long last_seq = -1;
    while(current_cnt){
      ///printf("debug: last_seq: %ld, cnt->seq=%ld, current_cnt->value->seq:%ld\n", last_seq, cnt->seq,current_cnt->value->seq);
      /*if(cnt->seq == current_cnt->value->seq){
        printf("debug: equal last_seq: %ld, cnt->seq=%ld, current_cnt->value->seq:%ld\n", last_seq, cnt->seq,current_cnt->value->seq);
        //return -2;
      }*/
      if(cnt->seq > last_seq && cnt->seq < current_cnt->value->seq){
        return insert_into_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, current_cnt->index, cnt);
      }else if(current_cnt->next==NULL){
        push_back_list_y_ptr_MSG_CONTENT_T(l_ocate_header->value->m_content_l, cnt);
        return 0;
      }
      last_seq = current_cnt->value->seq;
      current_cnt = current_cnt->next;
      
    }
    ///printf("debug: some thing wrong here! last_seq: %ld, cnt->seq=%ld\n", last_seq, cnt->seq);
    return -1;

  }
  else{
    push_back_list_y_ptr_MSG_CONTENT_T(current_header->m_content_l, cnt);
    push_back_list_y_ptr_HEADER_T(m_head_l_t, current_header);
    ///printf("debug:  push_back_list_y_ptr_HEADER_T when l_ocate_header == NULL, m_head_l_t->size=%ld\n",m_head_l_t->size);
    return 0;
  }
}

struct list_y_ptr_HEADER_T * check_if_all_contents_done_from_headers(struct main_list_y_ptr_HEADER_T *m_head_l_t, y_ptr_MSG_CONTENT_T cnt){

  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(cnt->nameid, cnt->size_nameid, cnt->cmd_t);
  ///printf("debug: check_if_all_contents_done_from_headers, begin search\n");
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_begin_in_list_y_ptr_HEADER_T (m_head_l_t, current_header, funcCmp_y_ptr_HEADER_T);
  ///printf("debug: check_if_all_contents_done_from_headers, search done\n");
  free_y_ptr_HEADER_T(current_header);
  if(l_ocate_header){
    ///printf("debug: check_if_all_contents_done_from_headers, l_ocate_header->index=%ld\n",l_ocate_header->index);
    if(l_ocate_header->value->m_content_l){
      struct list_y_ptr_MSG_CONTENT_T *end_list = l_ocate_header->value->m_content_l->end_list;
      ///printf("debug: check_if_all_contents_done_from_headers, l_ocate_header->m_content_l->size=%ld,\n",l_ocate_header->value->m_content_l->size);
      if(end_list){
        ///printf("debug: check_if_all_contents_done_from_headers, end->eof=%d, end->seq=%ld, end->index = %ld\n",end_list->value->eof, end_list->value->seq, end_list->index);
        // check if all contents are done!
        if(end_list->value->eof && end_list->value->seq == end_list->index){  
          return l_ocate_header;
        }
      }/*else{
        printf("debug: check_if_all_contents_done_from_headers, end_list==NULL\n");
        
      }*/
    }/*else{
      
      printf("debug: check_if_all_contents_done_from_headers, l_ocate_header->value->m_content_l==NULL\n");
    }*/

  }
  return NULL;
}

int remove_content_from_headers(struct main_list_y_ptr_HEADER_T *m_head_l_t, y_ptr_MSG_CONTENT_T cnt){
  
  y_ptr_HEADER_T current_header = create_y_ptr_HEADER_T(cnt->nameid, cnt->size_nameid, cnt->cmd_t);
  struct list_y_ptr_HEADER_T * l_ocate_header = search_first_occ_from_begin_in_list_y_ptr_HEADER_T (m_head_l_t, current_header, funcCmp_y_ptr_HEADER_T);
  free_y_ptr_HEADER_T(current_header);
  if(l_ocate_header){
    struct list_y_ptr_MSG_CONTENT_T *end_list = l_ocate_header->value->m_content_l->end_list;
    // check if all contents are done!
    if(end_list->value->eof && end_list->value->seq == end_list->index){ //l_ocate_header->value->m_content_l->size - 1
      struct list_y_ptr_HEADER_T *current_list = pull_index_from_list_y_ptr_HEADER_T(m_head_l_t, l_ocate_header->index);
      
      if(current_list == l_ocate_header){
        
        free_y_ptr_HEADER_T(l_ocate_header->value);
        free(l_ocate_header);
      }
      return 0;
    }
    else{
      ///printf("some thing wrong here: EOF:%d seq_end:%ld, size m_content_l :%ld\n",end_list->value->eof, end_list->value->seq, l_ocate_header->value->m_content_l->size);
      return 1;
    }
  }
  else{
    ///printf("\n%s is not in header list\n",cnt->nameid);
    return -1;
  }
}

void fileNameDateScore(char* filename, char * pre, char* post,size_t score){
 // char *filename=malloc(256);
  time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  sprintf(filename,"%s%d%02d%02d_%02dh%02dm%02ds_%ld%s",pre, tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec,score,post);

  //return filename;
}
/*
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

*/


#if 0
struct arg_send_file{
	struct pollfd *fds;
	struct main_list_y_NODE_T *nodes;
	char * filename;
};
#endif
/* */
#if 0
size_t set_addr_str_from_node(char *tempAddr, y_NODE_T node) {
      int c_af=(node).addr.ss_family;
            if(c_af==AF_INET){
               if(NULL == inet_ntop(c_af,
                &(GET_IN_type_ADDR(&(node),)),
                tempAddr, BUF_SIZE/*(argSock->local_list_current->value).addr_len*/)){
                fprintf(stderr, "error inet_ntop v4\n");
              }
            }else if(c_af==AF_INET6){
               if(NULL == inet_ntop(c_af,
                &(GET_IN_type_ADDR(&(node),6)),
                tempAddr, BUF_SIZE /*(argSock->local_list_current->value).addr_len*/)){
                fprintf(stderr, "error inet_ntop v6 :errno=%d\n",errno);
              }
            }
            size_t ret_len = strlen(tempAddr);
            return ret_len;
}
#endif
///
///
///


#define TEMP_ADDR 1

///
void* y_socket_send_file_for_node(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;

	struct pollfd *fds=argS->fds;
	y_NODE_T node=argS->node;
	char * filename=argS->filename;
#if TEMP_ADDR
  char tempAddr[64];
#endif
  int c_af;
//  char host[NI_MAXHOST], service[NI_MAXSERV];
  char buf_send[BUF_SIZE+1];
  int fd_file;
  int retread;
#if 0	
				int status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status)
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));


        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);
        
#endif        
				
      size_t seq = 0;//, len_buf_header=0, 
       size_t len_local_header_=0;
       //char * timeid = time_id();
       long timeid = long_time_id();
			 char nameid[BUF_SIZE/2];
			 struct main_list_y_ptr_STRING *m_str_name_f=split_str_to_main_list_y_ptr_STRING(filename, '/', -1);
  		 char * name_f=m_str_name_f->end_list->value->buf;
		//	char srcAddr[64];
  	//	set_addr_str_from_node(srcAddr, node);

       set_addr_str_from_node(tempAddr, node);
       c_af=(node).addr.ss_family;

			 sprintf(nameid, "%s_%s_%ld",name_f, tempAddr, timeid);

for(int tour_i=0;(tour_i<4) && (check_if_in_ok_header_l_(argS->m_ok_head_l_t, nameid) == 0); ++tour_i){
   
  fd_file = open( filename , O_RDONLY);
       if(fd_file == -1){
         fprintf(stderr,"error opening file |%s| for reading\n",filename);
				 purge_ptr_type_list_y_ptr_STRING(m_str_name_f);
         return NULL;
       }
			 /*
			if(tour_i==0) seq = 1;
			else */
							seq=0;

       //len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"dst\" : \"%s\" , \"tm\" : \"%ld\" }",filename, seq,tempAddr, timeid);
       len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"tm\" : \"%ld\" }",filename, seq, timeid);
       while((retread = read(fd_file, buf_send+len_local_header_, BUF_SIZE - len_local_header_) ) > 0 ){
          buf_send[len_local_header_ + retread]='\0';
            if(sendto(fds[(c_af==AF_INET6)].fd, 
              buf_send, retread+len_local_header_,
              0, 
              (struct sockaddr*)&((node).addr), 
              (node).addr_len) != 
              retread + len_local_header_
              ){
							fprintf(stderr, "Error sending response to %s\n",tempAddr);
						}/*else{
							printf("debug: sending response to < %s > seq=[%ld] ",tempAddr,seq);
						}*/
          
            ++seq;    
            len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"tm\" : \"%ld\" }",filename, seq, timeid);
          }
          if(argS->dst_dir){
            len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"EOF\" : true , \"tm\" : \"%ld\" , \"dst_dir\" : \"%s\" }",filename, seq, timeid, argS->dst_dir);
          }else{ 
            len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"EOF\" : true , \"tm\" : \"%ld\" }",filename, seq, timeid);
          } 
          if(sendto(fds[(c_af==AF_INET6)].fd,
              buf_send, len_local_header_,
              0,
              (struct sockaddr*)&((node).addr),
              (node).addr_len) !=
              len_local_header_
              ){
              fprintf(stderr, "Error ending  response to %s, len_buf_header=%ld\n", tempAddr, len_local_header_);
            }else{
              printf("debug: ending response to < %s > [%ld] EOF",tempAddr,seq);
            }

        close(fd_file);
        ///printf("debug: fd=%d closed: filename=%s, for %s\n",fd_file,filename, tempAddr);

	size_t delay = 4000000; 			
	printf("debug: wait %ld before checking, in tour:%d\n",delay, tour_i);
	usleep(delay);				
       //free(timeid);
       //timeid = time_id();
			 //sprintf(nameid, "%s_%s_%s_%s",name_f, tempAddr, tempAddr, timeid);
}

remove_header_ok_if_done(argS->m_ok_head_l_t, nameid);


        //free(timeid);
				purge_ptr_type_list_y_ptr_STRING(m_str_name_f);
  return NULL;
}
/// 

/// ///
//void y_socket_send_file_for_all_nodes(struct pollfd *fds, struct main_list_y_NODE_T *nodes, char * filename)
void* y_send_buf_for_all_(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;

	struct pollfd *fds=argS->fds;
	struct main_list_y_NODE_T *nodes=argS->nodes;
// if(export_nodes_to_file("file_nodes_name", nodes)==-1){
//  fprintf(stderr, "error export_nodes_to_file\n");
// }

	char * buf_send=argS->filename;
#if TEMP_ADDR
  char tempAddr[64];
#endif
  int c_af;
//  char host[NI_MAXHOST], service[NI_MAXSERV];
#if 0	
				int status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status)
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));


        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);
        
#endif        
				
       size_t len_buf_send=strlen(buf_send);
      for(struct list_y_NODE_T *local_list_current = nodes->begin_list; local_list_current; local_list_current=local_list_current->next ){
  
        set_addr_str_from_node(tempAddr, local_list_current->value);
        c_af=(local_list_current->value).addr.ss_family;

      
        if(sendto(fds[(c_af==AF_INET6)].fd,
              buf_send, len_buf_send,
              0,
              (struct sockaddr*)&((local_list_current->value).addr),
              (local_list_current->value).addr_len) !=
              len_buf_send
              ){
              fprintf(stderr, "Error sending %s to %s\n", tempAddr, buf_send);
            }/*else{
              printf("debug: sending [%s] -> < %s >",buf_send,tempAddr);
            }*/

        ///printf("debug: for index = %ld\n",local_list_current->index);
              
      }



  return NULL;
}
void* y_send_buf_for_other_(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;

	struct pollfd *fds=argS->fds;
	struct main_list_y_NODE_T *nodes=argS->nodes;
// if(export_nodes_to_file("file_nodes_name", nodes)==-1){
//  fprintf(stderr, "error export_nodes_to_file\n");
// }

	char * buf_send=argS->filename;
#if TEMP_ADDR
  char tempAddr[64];
#endif
  int c_af;
//  char host[NI_MAXHOST], service[NI_MAXSERV];
#if 0	
				int status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status)
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));


        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);
        
#endif        
				
       size_t len_buf_send=strlen(buf_send);
      for(struct list_y_NODE_T *local_list_current = nodes->begin_list; local_list_current; local_list_current=local_list_current->next ){
        if(local_list_current->value.local_addr == 0){
          set_addr_str_from_node(tempAddr, local_list_current->value);
          printf("debug: not local address:%s\n",tempAddr);
          c_af=(local_list_current->value).addr.ss_family;

      
          if(sendto(fds[(c_af==AF_INET6)].fd,
              buf_send, len_buf_send,
              0,
              (struct sockaddr*)&((local_list_current->value).addr),
              (local_list_current->value).addr_len) !=
              len_buf_send
              ){
              fprintf(stderr, "Error sending %s to %s\n", tempAddr, buf_send);
            }/*else{
              printf("debug: sending [%s] -> < %s >",buf_send,tempAddr);
            }*/

        ///printf("debug: for index = %ld\n",local_list_current->index);
         }     
      }



  return NULL;
}


/// ///

/* */

#if 0
//void y_socket_send_file_for_all_nodes(struct pollfd *fds, struct main_list_y_NODE_T *nodes, char * filename)
void* y_socket_send_file_for_all_nodes(void* arg){
  struct arg_send_file *argS=(struct arg_send_file*)arg;

	struct pollfd *fds=argS->fds;
	struct main_list_y_NODE_T *nodes=argS->nodes;
	char * filename=argS->filename;
#if TEMP_ADDR
  char tempAddr[64];
#endif
  int c_af;
//  char host[NI_MAXHOST], service[NI_MAXSERV];
  char buf_send[BUF_SIZE+1];
  int fd_file;
  int retread;
#if 0	
				int status = getnameinfo((struct sockaddr*)&(node.addr), node.addr_len, host, NI_MAXHOST, service, NI_MAXSERV, NI_NUMERICHOST);
        if(status)
       //   printf("debug: status ==0 : success: Received successfully from %s:%s\n", host,service);
       // else
          fprintf(stderr, "getnameinfo: %s\n", gai_strerror(status));


        if(NULL ==  search_node_in_list_y_NODE_T(nodes, node))
          push_back_list_y_NODE_T(nodes, node);
        
#endif        
				
      size_t seq = 0;//, len_buf_header=0, 
       size_t len_local_header_=0;
       //char * timeid = time_id();
       long timeid = long_time_id();
      for(struct list_y_NODE_T *local_list_current = nodes->begin_list; local_list_current; local_list_current=local_list_current->next ){
  
  fd_file = open( filename , O_RDONLY);
       if(fd_file == -1){
         fprintf(stderr,"error opening file |%s| for reading\n",filename);
         return NULL;
       }
       set_addr_str_from_node(tempAddr, local_list_current->value);
       c_af=(local_list_current->value).addr.ss_family;

       seq=0;

       len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"dst\" : \"%s\" , \"tm\" : \"%ld\" }",filename, seq,tempAddr, timeid);
       while((retread = read(fd_file, buf_send+len_local_header_, BUF_SIZE - len_local_header_) ) > 0 ){
          buf_send[len_local_header_ + retread]='\0';
            if(sendto(fds[(c_af==AF_INET6)].fd, 
              buf_send, retread+len_local_header_,
              0, 
              (struct sockaddr*)&((local_list_current->value).addr), 
              (local_list_current->value).addr_len) != 
              retread + len_local_header_
              ){
							fprintf(stderr, "Error sending response to %s\n",tempAddr);
						}else{
							printf("debug: sending response to < %s > seq=[%ld] ",tempAddr,seq);
						}
          
            ++seq;    
            len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"dst\" : \"%s\" , \"tm\" : \"%ld\" }",filename, seq,tempAddr, timeid);
          }
            len_local_header_ = sprintf(buf_send, "{ \"cmd\" : \"post file %s\", \"seq\" : %ld , \"EOF\" : true , \"dst\" : \"%s\" , \"tm\" : \"%ld\" }",filename, seq, tempAddr,timeid);
            if(sendto(fds[(c_af==AF_INET6)].fd,
              buf_send, len_local_header_,
              0,
              (struct sockaddr*)&((local_list_current->value).addr),
              (local_list_current->value).addr_len) !=
              len_local_header_
              ){
              fprintf(stderr, "Error ending  response to %s, len_buf_header=%ld\n", tempAddr, len_local_header_);
            }else{
              printf("debug: ending response to < %s > [%ld] EOF",tempAddr,seq);
            }

        close(fd_file);
        printf("debug: fd=%d closed: filename=%s, for index = %ld\n",fd_file,filename, local_list_current->index);
              
          }



        //free(timeid);
  return NULL;
}
#endif

void receve_from_node(struct pollfd *fds, struct main_list_y_ptr_HEADER_T *m_head_l_t, /*struct main_list_y_ptr_VARIABLE *m_var,*/ struct main_list_y_ptr_STRING *m_str, y_NODE_T node /*char * srcAddr*/, char *filename ){
    //printf("\ndebug: <<<< receve_from_node %s %ld\n\n",msg,count); 
	char srcAddr[64];
  set_addr_str_from_node(srcAddr, node);

	struct main_list_y_ptr_STRING *m_str_name_f=split_str_to_main_list_y_ptr_STRING(filename, '/', -1);
	char * name_f=m_str_name_f->end_list->value->buf;
          //size_t size_m_str = 0;
          struct list_y_ptr_STRING * local_current_no_rec = m_str->begin_list; 
          struct list_y_ptr_STRING * local_current;
                  char *dst_dir=NULL;
                  size_t len_dst_dir=0;
                  char eof=0;
            for(local_current = local_current_no_rec; local_current; local_current = local_current->next){
              char *buf_loc = local_current->value->buf;
              char nameid[BUF_SIZE/2]="";
              size_t size_nameid=0;
              struct js_value * js_header_v = create_js_value(buf_loc,NULL);
              //struct js_value *js_cmd_v = get_js_value_of_key("cmd", js_header_v );
              //printf("debug: index=[%ld] \n BEGIN file ***\n%s\n END\n",local_current->index,buf_loc);
              if(js_header_v){
               /*     
                struct js_value *js_cmd = get_js_value_of_key("cmd", js_header_v );
                if(js_cmd && js_cmd->type.object.value->code_type == jstype_string){
                  char * buf_cmd_v = js_cmd->type.object.value->type.string;
               */ 
                  struct js_value *js_seq_v = get_js_value_of_key("seq", js_header_v );
                  if(js_seq_v){
                    if(js_seq_v->type.object.value->code_type == jstype_number){
                      size_t seq_local = (long)(js_seq_v->type.object.value->type.number);
                        ///printf("debug:  \n*********seq_local=%ld ***\n\n",seq_local);
                      
                      struct js_value *js_eof_v = get_js_value_of_key("EOF", js_header_v );
                      if(js_eof_v){
                     //   size_m_str = seq_local;
                        eof=1;
                        ///printf("debug:  \n****************************end of file ***\n\n");
                        //printf("debug:  \n****************************end of file ***\n%s\n**********************************\n",buf_loc);
                        struct js_value *js_dst_dir_v = get_js_value_of_key("dst_dir", js_header_v );
                        if(js_dst_dir_v){
                          if(value_of_(js_dst_dir_v)->code_type == jstype_string){
                            dst_dir = value_of_(js_dst_dir_v)->type.string;
                            len_dst_dir = js_dst_dir_v->type.object.value->length;
                            // copy address of string and then remove from js by assign NULL, we have to free dst_dir after, if not string will free with js_header_v
                            js_dst_dir_v->type.object.value->type.string=NULL;
                          }
                        }
                      }
                      
                      /*struct js_value *js_dst_v = get_js_value_of_key("dst", js_header_v );
                      if(js_dst_v){*/
                        struct js_value *js_tm_v = get_js_value_of_key("tm", js_header_v );
                        if(js_tm_v){
                           size_t length_js_header = js_org_str_length(js_header_v);
                           char *content = buf_loc+ length_js_header;
                           size_t size_content = strlen(content);// js_header_v->length - length_js_header;
                           enum cmd_type cmd_t = cmd_post_file;
                           //char *timeid = value_of_(js_tm_v)->type.string;
#if 0
                           size_nameid = sprintf(nameid, "%s_%s_%s_%s",name_f /*filename*/, srcAddr, value_of_(js_dst_v)->type.string, timeid/*value_of_(js_tm_v)->type.string*/);
#endif
                           size_nameid = sprintf(nameid, "%s_%s_%s",name_f, srcAddr, /*value_of_(js_dst_v)->type.string,*/ value_of_(js_tm_v)->type.string);
                           ///printf("debug: nameid = %s\n", nameid);

                           //int intTimeid = atoi(timeid);

                           y_ptr_MSG_CONTENT_T y_msg_cnt=create_y_ptr_MSG_CONTENT_T(nameid, size_nameid, content, size_content, cmd_t, seq_local,eof);
                           long ret_app = y_append_content_to_header_l(m_head_l_t,y_msg_cnt);
                           if(ret_app != -2){
                             struct list_y_ptr_HEADER_T * local_header = check_if_all_contents_done_from_headers(m_head_l_t, y_msg_cnt);
                             if(local_header){
                               struct main_list_y_ptr_MSG_CONTENT_T *m_content_l = local_header->value->m_content_l;
                               struct list_y_ptr_MSG_CONTENT_T * tmpCnt_l = m_content_l->begin_list;
                               //if(strncmp(buf_cmd_v+5,"file",4)==0){
                                 int fd_file ;
                                 size_t len_dir=MAX(len_dst_dir, LEN_REPO_LOCAL);
                                 
                                 char fileNameLocal[tmpCnt_l->value->size_nameid + len_dir + 1];
                                 if(dst_dir){
                                   sprintf(fileNameLocal, "%s/%s",dst_dir,tmpCnt_l->value->nameid);
                                 }else{
                                   sprintf(fileNameLocal, "%s/%s",REPO_LOCAL,tmpCnt_l->value->nameid);
                                 }
                                 if((fd_file = open(fileNameLocal, O_WRONLY | O_CREAT ,
                                   S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH)) == -1){
                                   fprintf(stderr,"erreur write %s\n",tmpCnt_l->value->nameid);
                                   break;//return NULL;
                                 }
                                 

                                 while(tmpCnt_l){
                                   write(fd_file, tmpCnt_l->value->content, tmpCnt_l->value->size_content);
                                   ///printf("debug: nameid:%s seq = %ld eof %d\n\n%s\n",tmpCnt_l->value->nameid, tmpCnt_l->value->seq, tmpCnt_l->value->eof, tmpCnt_l->value->content);
                                   tmpCnt_l=tmpCnt_l->next;
                                 }
                                 close(fd_file);
                               //}
                               struct list_y_ptr_HEADER_T * l_head_to_remove = pull_index_from_list_y_ptr_HEADER_T(m_head_l_t, local_header->index);
                               free_y_ptr_HEADER_T(l_head_to_remove->value);
                               free(l_head_to_remove); 
                                // sendto srcAddr { "cmd" : "post ok nameid" } again ! 
                               char buf[BUF_SIZE];
                               size_t len_buf = sprintf(buf, "{ \"cmd\" : \"post ok %s\" }", nameid);
                               if(sendto(fds[(node.addr.ss_family==AF_INET6)].fd,	buf, len_buf,	0, 	(struct sockaddr*)&((node).addr),	(node).addr_len) !=	len_buf){
                                  fprintf(stderr, "Error sending ok %s to %s\n", nameid,srcAddr);
                               }else{
                                  printf("debug: sending OK %s to < %s > ",nameid,srcAddr);
                               }

                               
                             }/*else if(intTimeNow-intTimeid > TTL_SOCKDRAM){
                               struct list_y_ptr_HEADER_T * l_head_to_remove = pull_index_from_list_y_ptr_HEADER_T(m_head_l_t, local_header->index);
                               free_y_ptr_HEADER_T(l_head_to_remove->value);
                               free(l_head_to_remove);
                                                         }	
                            */ 
                          }

                        }/*else{
                          printf("debug: tm missing!");
                        }*/
                      /*}
                      else{
                        printf("debug: dst missing!");
                      }*/
                    }/*
                    else{
                      printf("debug:  \n SSSSSSSSSSSSSSSEEEEEEEEEEEEEEQQQQQQQQQQQQQ type:%d \n",js_seq_v->type.object.value->code_type);

                    }*/
                  

                  }/*else{

                      printf("debug:  \n NNNNNNNNNNNNNNNNOOOOOOOOOOOOOSSSSSSSSSSSSSSSEEEEEEEEEEEEEEQQQQQQQQQQQQQ :type header : %d \n",js_header_v->code_type);
                  }*/
                /*}else{
                    printf("debug:  \n NO CMD :type header : %d \n",js_header_v->code_type);

                }*/
                              free_js_value(js_header_v);
              }else{
                printf("\ndebug NULLL JS___HHHEADER_V \n");
              }
            }
            if(dst_dir){
              free(dst_dir);
            }
            //if(local_current){
            //  printf("debug: getchar\n");
            //  getchar();

            //}
            //local_current_no_rec = local_current_no_rec->next;
         

          /*if(cur_index == size_m_str){
            printf("debug:  all seq are received: %ld\n",cur_index);
          }
          else{
            printf("debug:  some issue cur_index %ld vs size_m_str :%ld\n",cur_index,size_m_str);

          }*/

    if(m_str){
      purge_ptr_type_list_y_ptr_STRING(m_str);
      m_str = NULL;
    }

				purge_ptr_type_list_y_ptr_STRING(m_str_name_f);
		//free(timeNow);
}
