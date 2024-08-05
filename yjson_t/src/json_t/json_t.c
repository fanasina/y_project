#include "json_t/json_t.h"

bool is_js_space(char c){
  //printf("c=|%c|[%d]\n",c,c);
  if(c == ' ') return true;
  if(c == '\t') return true;
  if(c == '\n') return true;
  if(c == '\r') return true;
  
  return false;

}

void set_index_(struct js_value *js, size_t index){
  if(js->code_type == jstype_object)
     js->type.object.index = index;
  else if(js->code_type == jstype_array)
     js->type.array.index = index;
}

long get_index_(struct js_value *js){
  if(js->code_type == jstype_object)
      return js->type.object.index;
  if(js->code_type == jstype_array)
      return js->type.array.index;
  return -1;
}



struct js_value * next_(struct js_value *js){
 if(js->code_type == jstype_object){
   return js->type.object.next_object;
 }
 if(js->code_type == jstype_array){
   return js->type.array.next_element;
 }
 return NULL;
}
struct js_value * prev_(struct js_value *js){
 if(js->code_type == jstype_object){
   return js->type.object.prev_object;
 }
 if(js->code_type == jstype_array){
   return js->type.array.prev_element;
 }
 return NULL;
}


void free_js_value(struct js_value *js){

  if(js->code_type == jstype_string){
    free(js->type.string);
  }else if(js->code_type == jstype_object){
   // free_js_value(js->type.object.key);
    free_js_value(js->type.object.value);
    struct js_value *tmpV = js->type.object.next_object;
    js->type.object.next_object = NULL;
    struct js_value *ttmp;
    while(tmpV){
      ttmp = tmpV;
      tmpV = ttmp->type.object.next_object ; //next_(ttmp); 
      ttmp->type.object.next_object = NULL;
      //print_value(ttmp);
      free_js_value(ttmp);
    }
    if(js->type.object.index == 0 && js->type.object.iter){
      free(js->type.object.iter);
      js->type.object.iter = NULL;
    }
  }else if(js->code_type == jstype_array){
    free_js_value(js->type.array.value);
    struct js_value *tmpV = js->type.array.next_element;
    js->type.array.next_element = NULL;
    struct js_value *ttmp;
    while(tmpV){
      ttmp = tmpV;
      tmpV = ttmp->type.array.next_element ; //next_(ttmp); 
      ttmp->type.array.next_element = NULL;
      //print_value(ttmp);
      free_js_value(ttmp);
    }
    if(js->type.array.index == 0 && js->type.array.iter){
      free(js->type.array.iter);
      js->type.array.iter = NULL;
    }
  }

  
  free(js);

}

struct js_value * create_js_value_string(char * input, struct js_value * parent){
  struct js_value * js = malloc(sizeof(struct js_value));
  js->parent = parent;
  if(*input == '"')
    js->str_value = input+1;
  else
    js->str_value = input;
  js->code_type =  jstype_string;
  char *cur = js->str_value;
  for(; *cur!='"'; ++cur);
  js->length = cur - js->str_value;
  js->type.string = malloc(js->length + 1);
  strncpy(js->type.string, js->str_value, js->length);
  js->type.string[js->length]='\0';
  return js;
}

struct js_value * create_js_value_number(char * input, struct js_value * parent){
  struct js_value * js = malloc(sizeof(struct js_value));
  js->parent = parent;
  js->str_value = input;
  js->code_type =  jstype_number;
  char *end;
  js->type.number = strtold(input, &end); 
  js->length = end - input;
//  printf("\nend_num:%s, num:%s, lenN:%ld\n",end,input, js->length);
  return js;
}

struct js_value * create_js_value_null(char * input, struct js_value * parent){
  struct js_value * js = malloc(sizeof(struct js_value));
  js->parent = parent;
  js->str_value = input;
  js->code_type =  jstype_null;
  js->length = 4;

  return js;
}


struct js_value * create_js_value_true(char * input, struct js_value * parent){
  struct js_value * js = malloc(sizeof(struct js_value));
  js->parent = parent;
  js->str_value = input;
  js->code_type =  jstype_bool;
  js->type.boolean = true;
  js->length = 4;

  return js;
}
struct js_value * create_js_value_false(char * input, struct js_value * parent){
  struct js_value * js = malloc(sizeof(struct js_value));
  js->parent = parent;
  js->str_value = input;
  js->code_type =  jstype_bool;
  js->type.boolean = false;
  js->length = 5;  

  return js;
}


struct js_value * create_js_value_array(char * _input, struct js_value * parent){
  struct js_value * js_parent = malloc(sizeof(struct js_value));
  struct js_value * js, *tmp_js;
  js = js_parent;
  char *input = _input;
  if(*_input == '[')
    input = _input + 1;

  char *cur = input;
  for(long depth = 1; *cur != '\0' && depth != 0; ++cur){
    if(*cur == '[') ++depth;
    if(*cur == ']') --depth;
  }
  js->length = cur - input;
//  printf("\na]input ==%s, len:%ld\n",input,js->length);

  js->type.array.next_element = NULL;
  js->type.array.prev_element = NULL;
  js->type.array.index = 0;
  
  js->type.array.iter = malloc(sizeof(struct js_iterator));
  
  js->type.array.iter->size = js->type.array.index + 1;
  js->type.array.iter->begin = js;
  js->type.array.iter->end = js;
  js->type.array.iter->current = js;

  if(parent == NULL)
    js->type.array.depth= 0;
  else
    js->type.array.depth = parent->type.array.depth + 1;
//  js->index = 0;

  js->str_value = input;
  js->code_type =  jstype_array;
  cur = input;
  for(; is_js_space(*cur); ++cur);
  if(*cur == ']'){

    js->type.array.value = create_js_value_null(NULL, js); // NULL;
    js->type.array.value->length = cur - input + 1;
    js->type.array.next_element = NULL;
    js->parent = parent;
  
    //js->type.object.key_length = cur - input;
    //js->type.array.value = NULL;

return js;
  }

  while(cur < input + js_parent->length )
  { 
//    printf("aa::%c\n",*cur); 
    if(*cur == ','){
      ++cur;
      tmp_js = malloc(sizeof(struct js_value));
      //for(; is_js_space(*cur); ++cur);
      tmp_js->str_value = cur;// + 1;
      tmp_js->code_type = jstype_array;
      char *ccur = cur;
      for(; *ccur != '\0' && *ccur != ',' ; ++ccur){
        if(*ccur == '{'){ // to ignore ',' in the object
          ++ccur;
          for(long depth = 1; *ccur != '\0' && depth != 0; ++ccur){
            if(*ccur == '{') ++depth;
            if(*ccur == '}') --depth;
          }
          //break;
        }
        if(*ccur == ']')
          break;
        if(*cur == '['){// to ignore ',' in the list
          ++ccur;
          for(long depth = 1; *ccur != '\0' && depth != 0; ++ccur){
            if(*ccur == '[') ++depth;
            if(*ccur == ']') --depth;
          }
          //break;
        }
        if(*cur == '"'){ // to ignore ',' in "string value"
          for(; *ccur != '\0' || *ccur !='"'; ++ccur);
        }
      }
      tmp_js->length = ccur - cur;
      tmp_js->type.array.prev_element = js;
      tmp_js->type.array.next_element = NULL;
      tmp_js->type.array.iter = js_parent->type.array.iter;
      tmp_js->type.array.index = js->type.array.index + 1;
      //tmp_js->type.object.iter = NULL;
      js->type.array.next_element = tmp_js;
      js= tmp_js;
      if(parent == NULL)
        js->type.array.depth= 0;
      else
        js->type.array.depth = parent->type.array.depth + 1;


      js_parent->type.array.iter->size = js->type.array.index + 1;
      js_parent->type.array.iter->end = js;
      js_parent->type.array.iter->current = js;
  
    }else{

    }
   
    js->parent = parent;


    for(; is_js_space(*cur); ++cur);
    
    // value section
    char *str_value = cur; // + js->type.object.key->length;  
  
     
    js->type.array.value = create_js_value(str_value, js);

    cur = str_value + js->type.array.value->length + (js->type.array.value->code_type != jstype_number) ; //1 ;
//    printf("<a>>strVal:%s\n",cur);
    
    if(js->type.array.value->code_type == jstype_string)
      for(; is_js_space(*cur) || *cur=='"' || *cur=='}' || *cur == ']'; ++cur);
    else
      for(; is_js_space(*cur) || *cur=='}' || *cur == ']'; ++cur);

  }

  return js_parent;


}

struct js_value * create_js_value(char *_input, struct js_value *parent){
   char *input = _input;
   for(; is_js_space(*input); ++input);

//   printf(">>strVal:%s\n",input);
    if(*input == '"'){
      return  create_js_value_string(input+1, parent);
    }else if(strncmp(input,"true",4) == 0){
      return  create_js_value_true(input, parent);
    }else if(strncmp(input,"false",5) == 0){
      return  create_js_value_false(input, parent);
    }else if(strncmp(input,"null",4) == 0){
      return  create_js_value_null(input, parent);
    }else if(*input == '{'){
      return  create_js_value_object(input + 1, parent);
    }else if(*input == '['){
      return  create_js_value_array(input + 1, parent);
    }else /*if(isdigit(*input))*/{
      return  create_js_value_number(input, parent);
    }


}

struct js_value * create_js_value_object(char *_input /*, struct js_value *prev*/, struct js_value * parent){
  struct js_value * js_parent = malloc(sizeof(struct js_value));
  struct js_value * js, *tmp_js;
  js = js_parent;
  char *input = _input;

  if(*_input == '{')
    input = _input + 1;

  char *cur = input;
  for(long depth = 1; *cur != '\0' && depth != 0; ++cur){
    if(*cur == '{') ++depth;
    if(*cur == '}') --depth;
  }
  js->length = cur - input;
 
  // printf("iin:%s\noo cur:%s\nlenObj:%ld\n",input,cur, js->length);

  js->type.object.next_object = NULL;
  js->type.object.prev_object = NULL;
  js->type.object.index = 0;
  
  js->type.object.iter = malloc(sizeof(struct js_iterator));

  js->type.object.iter->size = js->type.object.index + 1;
  js->type.object.iter->begin = js;
  js->type.object.iter->end = js;
  js->type.object.iter->current = js;
  
  if(parent == NULL)
    js->type.object.depth = 0;
  else
    js->type.object.depth = parent->type.object.depth + 1;

  js->str_value = input;
  js->code_type =  jstype_object;
  
  cur = input;
  for(; is_js_space(*cur); ++cur);
//  printf("oocp::%s\n",cur); 
  if(*cur == '}'){
//    printf(">>>iin:%s\noo cur:%s\nlenObj:%ld\n",input,cur, js->length);
    
    js->type.object.value = create_js_value_null(NULL, js);// NULL;
    js->type.object.value->length = cur - input;
    js->type.object.key_length = 0;
    js->type.object.key = NULL;
    js->type.object.next_object = NULL;
    js->parent = parent;
    return js;
  }


//  printf("cooc::%s, diff:%ld\n",cur, input + js_parent->length - cur); 

  while(cur < input + js_parent->length)
  { 
//    printf("cc::%c\n",*cur); 
    if(*cur == ','){
      ++cur;
      tmp_js = malloc(sizeof(struct js_value));
      //for(; is_js_space(*cur); ++cur);
      tmp_js->str_value = cur ;//+ 1;
      tmp_js->code_type = jstype_object;
      char *ccur = cur;
      for(; *ccur != '\0' && *ccur != ',' ; ++ccur){
        if(*ccur == '{'){ // to ignore ',' in the object
          ++ccur;
          for(long depth = 1; *ccur != '\0' && depth != 0; ++ccur){
            if(*ccur == '{') ++depth;
            if(*ccur == '}') --depth;
          }
          //break;
        }
        if(*ccur == '}')
          break;
        if(*cur == '['){// to ignore ',' in the list
          ++ccur;
          for(long depth = 1; *ccur != '\0' && depth != 0; ++ccur){
            if(*ccur == '[') ++depth;
            if(*ccur == ']') --depth;
          }
          //break;
        }
        if(*cur == '"'){ // to ignore ',' in "string value"
          for(; *ccur != '\0' || *ccur !='"'; ++ccur);
        }
      }
      tmp_js->length = ccur - cur;
      tmp_js->type.object.prev_object = js;
      tmp_js->type.object.next_object = NULL;
      tmp_js->type.object.iter = js_parent->type.object.iter;
      tmp_js->type.object.index = js->type.object.index + 1;
      js->type.object.next_object = tmp_js;
      js= tmp_js;
      if(parent == NULL)
        js->type.object.depth = 0;
      else
        js->type.object.depth = parent->type.object.depth + 1;
  
      js_parent->type.object.iter->size = js->type.object.index + 1;
      js_parent->type.object.iter->end = js;
      js_parent->type.object.iter->current = js;
      
    }else{

    }
    
    js->parent = parent;
    for(; is_js_space(*cur); ++cur);
   // key section
   // js->type.object.key = create_js_value_string(cur, js);
   
    if(*cur == '"') ++cur;
    js->type.object.key = cur;
 //   printf("cur:%s\n",cur);
    for(; *cur != '"'; ++cur);
    //js->key = cur;
    //for(; *cur != '"'; ++cur);
    //js->key_length = cur - js->key;
    js->type.object.key_length = cur - js->type.object.key;
    for(; *cur != ':'; ++cur);
    ++cur;
    for(; is_js_space(*cur); ++cur);
//    printf("cur=%s| lenKey :%ld \n",cur,js->type.object.key_length);
 

    // value section
    char *str_value = cur; // + js->type.object.key->length;  
  
    js->type.object.value = create_js_value(str_value, js);
    
    cur = str_value + js->type.object.value->length + (js->type.object.value->code_type != jstype_number);// 1 ;
//    printf("[>>>: cur:%s\n",cur);
     
    if(js->type.object.value->code_type == jstype_string)
      for(; is_js_space(*cur) || *cur=='"' || *cur=='}' || *cur == ']'; ++cur);
    else
      for(; is_js_space(*cur) || *cur=='}' || *cur == ']'; ++cur);


  }

  return js_parent;

}
void create_copy_js_iterator(struct js_iterator **_dstit, struct js_iterator *srcit){
  if(*_dstit == NULL){
    *_dstit = malloc(sizeof(struct js_iterator));
  }
  struct js_iterator * dstit = *_dstit;
  dstit->size = srcit->size;
//  dstit->next_ = srcit->next_;
//  dstit->prev_ = srcit->prev_;
//  dstit->set_index_ = srcit->set_index_;
//  dstit->get_index_ = srcit->get_index_;
  dstit->begin = srcit->begin;
  dstit->end = srcit->end;
  dstit->current = srcit->current;

}

void setup_js_iterator(struct js_iterator **_iter, struct js_value * js){
  

  if(js->code_type == jstype_object || js->code_type == jstype_array ) {
    if(*_iter == NULL){
      *_iter = malloc(sizeof(struct js_iterator));
    }
    struct js_iterator *iter = *_iter ;
//   iter->next_ = next_;
//    iter->prev_ = prev_;
//    iter->set_index_ = set_index_;
//    iter->get_index_ = get_index_;

    iter->begin = js;
    struct js_value *tmpjs = js;
    struct js_value *tmpit = iter->begin;
    //size_t index = 0;
    while(tmpjs){
      //iter->set_index_(tmpjs, index);  
      //++index;

      iter->size = get_index_(tmpjs);      

      iter->end = tmpjs;
      iter->current = tmpjs;
      tmpjs = next_(tmpjs);
    }

    //return iter;

  }
 
  //return NULL; 


}

long  get_size_(struct js_value *js){
  if(js->code_type < jstype_object) return -1;
  if(js->code_type == jstype_object) return js->type.object.iter->size;
  return js->type.array.iter->size;
}

long move_current_iter_to_index_(struct js_value *js, size_t index){
  if(js->code_type < jstype_object) return -1;
    struct js_iterator *iter = get_iterator_(js);
    if(index == get_index_(iter->current)) return index;
    //if(js->begin_list == NULL) return 0;
    long size = get_size_(js);
    if(index >= size){
      iter->current = iter->end;
      //js->current_index = js->size - 1;
      return size - 1;
    }
    
    long from_current_index = get_index_(iter->current) - index; 
    size_t abs_cur_diff = abs(from_current_index); 
    size_t array_diff_index[3]  = {index, abs_cur_diff , size - 1 - index}; 
    size_t index_nearest = ARG_MIN_ARRAY_TYPE_SIZE_T(array_diff_index, 3);
    if(index_nearest == 0){
      iter->current = iter->begin;
      for(size_t i=0; i<array_diff_index[0]; ++i) iter->current = next_(iter->current); 
    }
    else if(index_nearest == 2){
      iter->current = iter->end;
      for(size_t i=0; i < array_diff_index[2]; ++i) iter->current = prev_(iter->current); 
    }else if(from_current_index >= 0) 
      for(size_t i=0; i < array_diff_index[1]; ++i)  iter->current = prev_(iter->current);
    else  
      for(size_t i=0; i < array_diff_index[1]; ++i)  iter->current = next_(iter->current);
      
    return index;
  }

struct js_value * get_js_value_of_index_(size_t index, struct js_value *js){
  if(move_current_iter_to_index_(js, index) >=0) 
    return get_iterator_(js)->current;
  return NULL;
}


void set_next_(struct js_value * dstjs, struct js_value * jsnxt){
  if(dstjs->code_type == jstype_object){
    struct js_value *tmpjs = dstjs->type.object.next_object;//, *ttmpjs;
      //ttmpjs = dstjs;
      //while(prev_(ttmpjs))  ttmpjs = prev_(ttmpjs);
      //struct js_iterator *iter = ttmpjs->type.object.iter;
    struct js_iterator *iter = dstjs->type.object.iter;
    dstjs->type.object.next_object = jsnxt;
    jsnxt->type.object.prev_object = dstjs;
    size_t last_index = dstjs->type.object.index;
    struct js_value *ttmp = jsnxt;
    //struct js_iterator *olditer = jsnxt->type.object.iter;
    //bool deferFree = (jsnxt->type.object.index == 0);
    struct js_value *end = jsnxt->type.object.iter->end;
    while(next_(ttmp)){
      if(get_index_(ttmp)==0) free(ttmp->type.object.iter);
      ttmp->type.object.iter = iter;
      //end = ttmp;
      ttmp->type.object.index = (++last_index);
      ttmp = next_(ttmp);
    }
    ttmp->type.object.next_object = tmpjs;
    if(tmpjs){
//      print_value(tmpjs);
//      printf("%d line\n",__LINE__);
      tmpjs->type.object.prev_object = ttmp;
      while(tmpjs){
        //end = tmpjs;
        tmpjs->type.object.index = (++last_index);
        tmpjs = next_(tmpjs);
      }
    }
    //struct js_iterator *iter = get_iterator_(dstjs);
    if(iter){
      iter->size = last_index + 1;
      if(get_index_(iter->end) < get_index_(end)){
        iter->end = end;
      }
    }
    //if(deferFree && olditer) free(olditer);
  }else if(dstjs->code_type == jstype_array){
    struct js_value *tmpjs = dstjs->type.array.next_element;//, *ttmpjs;
      //ttmpjs = dstjs;
      //while(prev_(ttmpjs))  ttmpjs = prev_(ttmpjs);
      //struct js_iterator *iter = ttmpjs->type.array.iter;
    struct js_iterator *iter = dstjs->type.array.iter;
    //if(jsnxt->type.array.iter) free(jsnxt->type.array.iter);
    dstjs->type.array.next_element = jsnxt;
    jsnxt->type.array.prev_element = dstjs;
    size_t last_index = dstjs->type.array.index;
    struct js_value *ttmp = jsnxt;
    struct js_value *end = jsnxt->type.array.iter->end;
    //struct js_iterator *olditer = jsnxt->type.array.iter;
    //bool deferFree = (jsnxt->type.array.index == 0);
    while(next_(ttmp)){
      if(get_index_(ttmp)==0) free(ttmp->type.object.iter);
      ttmp->type.array.iter = iter;
      //end = ttmp;
      ttmp->type.array.index = (++last_index);
      ttmp = next_(ttmp);
    }
    ttmp->type.array.next_element = tmpjs;
    if(tmpjs){
      tmpjs->type.array.prev_element = ttmp;
      while(tmpjs){
        //end = tmpjs;
        tmpjs->type.array.index = (++last_index);
        tmpjs = next_(tmpjs);
      }
    }
    //struct js_iterator *iter = get_iterator_(dstjs);
    if(iter){
      iter->size = last_index + 1;
      if(get_index_(iter->end) < get_index_(end)){
        iter->end = end;
      }
    }
    //if(deferFree && olditer) free(olditer);
  }
}

void set_prev_(struct js_value ** _dst, struct js_value * jsprv){
  struct js_value *dst = *_dst;
  if(dst->code_type == jstype_object){
    struct js_value *tmpjs = dst->type.object.prev_object;//, *ttmpjs;
      //ttmpjs = dst;
      //while(prev_(ttmpjs))  ttmpjs = prev_(ttmpjs);
      //struct js_iterator *iter = ttmpjs->type.object.iter;
    struct js_iterator *iter = dst->type.object.iter;
    jsprv->type.object.iter = iter;
    dst->type.object.prev_object = jsprv;
    jsprv->type.object.prev_object = tmpjs;
    jsprv->type.object.index = dst->type.object.index;
    jsprv->type.object.prev_object = tmpjs;
    size_t last_index = dst->type.object.index;
    struct js_value *ttmp = jsprv;
    while(next_(ttmp)){
      ttmp->type.object.index = (++last_index);
      ttmp = next_(ttmp);
      if(iter) ++(iter->size);// = last_index + 1;
    }
    ttmp->type.object.next_object = dst;
    if(tmpjs){
      tmpjs->type.object.next_object = jsprv;
    }else{// dst prev null (top)
      *_dst = jsprv;     
      //(*_dst)->type.object.iter = iter; // malloc(sizeof(struct js_iterator));
      //(*_dst)->type.object.iter->begin = jsprv;
      if(iter){
        iter->begin = jsprv;
      //  (*_dst)->type.object.iter->end = iter->end;
      //  (*_dst)->type.object.iter->current = iter->current;
      //  (*_dst)->type.object.iter->size = iter->size; // + (last_index + 1 - dst->type.object.index);
      }
      //iter =  (*_dst)->type.object.iter;
    }
    tmpjs = dst;
    while(tmpjs){
        tmpjs->type.object.index = (++last_index);
        tmpjs = next_(tmpjs);
        //if(iter) {
        //  iter->size = last_index + 1;
        //  iter->end = tmpjs;
        //}
    }
  }else if(dst->code_type == jstype_array){
    struct js_value *tmpjs = dst->type.array.prev_element;//, *ttmpjs;
      //ttmpjs = dst;
      //while(prev_(ttmpjs))  ttmpjs = prev_(ttmpjs);
      //struct js_iterator *iter = ttmpjs->type.array.iter;
    struct js_iterator *iter = dst->type.array.iter;
    jsprv->type.array.iter = iter;
    dst->type.array.prev_element = jsprv;
    jsprv->type.array.prev_element = tmpjs;
    jsprv->type.array.index = dst->type.array.index;
    jsprv->type.array.prev_element = tmpjs;
    size_t last_index = dst->type.array.index;
    struct js_value *ttmp = jsprv;
    while(next_(ttmp)){
      ttmp->type.array.index = (++last_index);
      ttmp = next_(ttmp);
      if(iter) ++(iter->size);// = last_index + 1;
    }
    ttmp->type.array.next_element = dst;
    if(tmpjs){
      tmpjs->type.array.next_element = jsprv;
    }else{// dst prev null (top)
      *_dst = jsprv;      
      //(*_dst)->type.array.iter = malloc(sizeof(struct js_iterator));
      //(*_dst)->type.array.iter->begin = jsprv;
      if(iter){
        iter->begin = jsprv;
        //(*_dst)->type.array.iter->end = iter->end;
        //(*_dst)->type.array.iter->current = iter->current;
        //(*_dst)->type.array.iter->size = iter->size; // + (last_index + 1 - dst->type.array.index);
      }
      //iter =  (*_dst)->type.array.iter;
    }
    tmpjs = dst;
    while(tmpjs){
      ++(tmpjs->type.array.index);
      tmpjs = next_(tmpjs);
    }
    
  }
}


void add_js_value_index(size_t index, struct js_value *js_to_add, struct js_value **js_org){
  if((*js_org)->code_type >= jstype_object && (*js_org)->code_type == js_to_add->code_type ){
    struct js_value /**tmpjs = *js_org,*/ *ttmp=NULL;
    /*while(tmpjs){// TO DO : use iter to optimize
      if(get_index_(tmpjs) == index){
//        printf("broken, index:%ld\n",index);
       break;
      }
      ttmp = tmpjs;
      tmpjs = next_(tmpjs);
    }*/
    ttmp = get_js_value_of_index_(index, *js_org);
    if(ttmp != *js_org){
//      printf("not NULL\n");
      set_next_(ttmp,js_to_add);
    }else{
      set_prev_(js_org, js_to_add);
    }
  }
}

struct js_iterator * get_iterator_(struct js_value *js){
  if(js->code_type == jstype_object) return js->type.object.iter;
  if(js->code_type == jstype_array) return js->type.array.iter;
  return NULL;
}


void append_js_value(struct js_value *dst, char *input){/* if object type: input =  { "key" : value }, if key already exists value replace the old value! */
  if(dst->code_type < jstype_object || get_iterator_(dst) == NULL) return;
  struct js_value *newval = create_js_value(input, dst);
  if(dst->code_type == jstype_object && newval->code_type != jstype_object){
    printf(" input needs to be at the format :  { \"key\" : value } \n");
    free_js_value(newval);
    return;
  }else{
    if(dst->code_type == jstype_object){
      char key[newval->type.object.key_length + 1];
      strncpy(key, newval->type.object.key, newval->type.object.key_length);
      key[newval->type.object.key_length]='\0';
      struct js_value * valjs = get_js_value_of_key(key, dst);
      if(valjs){
        struct js_value *ttmp = value_of_(valjs);
        valjs->type.object.value = value_of_(newval);
        free_js_value(ttmp);
        if(newval->type.object.iter) free(newval->type.object.iter);
        free(newval); // but keep value_of_(newval)! 
        return;
      }

    }
    struct js_iterator *iter = get_iterator_(dst);
    set_next_(iter->end, newval);
    struct js_value *tmpjs = newval;
    while(next_(tmpjs)) tmpjs = next_(tmpjs);
    iter->end = tmpjs;
    iter->current = tmpjs;
    iter->size = get_index_(tmpjs) + 1;
    
  }
}

char * original_string_js_value(struct js_value *js){
  char *ret = malloc(js->length+1);
  strncpy(ret,js->str_value,js->length);
  ret[js->length] = '\0';




  return ret;

}

void print_value(struct js_value *js){
  if(js->code_type == jstype_number){
    printf("%Lf",js->type.number);
  }else if(js->code_type == jstype_string){
    printf("\"%s\"",js->type.string);
  }else if(js->code_type == jstype_bool){
    printf("%s",js->type.boolean ? "true" : "false");
  }else if(js->code_type == jstype_null){
    printf("%s","null");
  }else if(js->code_type == jstype_object){
    struct js_value *tmpjs = js;

    while(tmpjs){
      
      if(tmpjs->type.object.prev_object == NULL){ 
        printf("\n%*c{ ",4*(tmpjs->type.object.depth),' ');
      }

        char key[tmpjs->type.object.key_length + 1];
        strncpy(key, tmpjs->type.object.key, tmpjs->type.object.key_length);
        key[tmpjs->type.object.key_length]='\0';
        printf("\n%*c\"%s\" : ", 4*(tmpjs->type.object.depth),' ', key );
      print_value(tmpjs->type.object.value);

      if(tmpjs->type.object.next_object == NULL)
         printf("\n%*c} ",4*(tmpjs->type.object.depth),' '); //printf(" }");
      else printf(", ");
      //printf("\n");
      tmpjs = tmpjs->type.object.next_object;
    }
  }else if(js->code_type == jstype_array){
    struct js_value *tmpjs = js;
    while(tmpjs){
      if(tmpjs->type.array.prev_element == NULL){  
        printf("\n%*c[ ",4*(tmpjs->type.array.depth),' ');
      }
        if(tmpjs->type.array.value->code_type < jstype_object ) 
          printf("\n%*c ",4*(tmpjs->type.array.depth),' ');
        print_value(tmpjs->type.array.value);
      if(tmpjs->type.array.next_element == NULL)  //printf(" ]");
        printf("\n%*c] ",4*(tmpjs->type.array.depth),' ');
      else printf(", ");
      tmpjs =  tmpjs->type.array.next_element; // next_(tmpjs);
    }
  }

}

struct js_value * value_of_(struct js_value * js){
  if(js->code_type == jstype_object){
    return js->type.object.value;
  }
  if(js->code_type == jstype_array){
    return js->type.array.value;  
  }
  return NULL;
}

struct js_value *get_js_value_of_key(char * key, struct js_value *js ){
  if(js->code_type == jstype_object){
    struct js_value *tmp = js;
    while(tmp){
      if(strncmp(key,tmp->type.object.key, tmp->type.object.key_length) == 0){
        return tmp; //tmp->type.object.value == value_of_(tmp);
      }
      tmp = next_(tmp);
    }
  }
  return NULL; 
}

/*
void set_value_of_key(char *key, char * value, struct js_value *js ){
  if(js->code_type != jstype_object) 
    return;
  struct js_value *valjs = get_js_value_of_key(key, js);
  if(valjs){
    struct js_value *tmp = valjs->type.object.value;
    valjs->type.object.value = create_js_value(value, valjs);
    
    free_js_value(tmp);
  }else{
    js->type.object.
  }
}
*/
