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
void free_js_value__(struct js_value *js){
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
      //print_js_value(ttmp);
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
      //print_js_value(ttmp);
      free_js_value(ttmp);
    }
    if(js->type.array.index == 0 && js->type.array.iter){
      free(js->type.array.iter);
      js->type.array.iter = NULL;
    }
  }

  
  free(js);

}

void _free_js_value_no_free_iter(struct js_value *js){
  if(js!=NULL){

    if(js->code_type == jstype_number){
      
      free(js); 
    }else if(js->code_type == jstype_string){
      free(js->type.string);
      free(js);
    }else if(js->code_type == jstype_bool){
      free(js); 
    }else if(js->code_type == jstype_null){
      free(js);
    }else if(js->code_type == jstype_object){
      struct js_value *tmpjs = NULL;

      while(js){
        tmpjs=js;

        _free_js_value_no_free_iter(tmpjs->type.object.value);
          
        js = tmpjs->type.object.next_object;
        free(tmpjs);
      }
    }else if(js->code_type == jstype_array){
      struct js_value *tmpjs = NULL;
      while(js){
        tmpjs = js;
        _free_js_value_no_free_iter(tmpjs->type.array.value);
        
        js =  tmpjs->type.array.next_element; // next_(tmpjs);
        free(tmpjs);
      }
    }
  }
}



void free_js_value(struct js_value *js){
  if(js!=NULL){

    if(js->code_type == jstype_number){
      
      free(js); 
    }else if(js->code_type == jstype_string){
      free(js->type.string);
      free(js);
    }else if(js->code_type == jstype_bool){
      free(js); 
    }else if(js->code_type == jstype_null){
      free(js);
    }else if(js->code_type == jstype_object){
      struct js_value *tmpjs = NULL;

      while(js){
        tmpjs=js;
        if((tmpjs->type.object.iter != NULL) && (tmpjs->type.object.prev_object == NULL)){ 
          free(tmpjs->type.object.iter);
        }
        if(tmpjs->type.object.key) 
          free(tmpjs->type.object.key); 
        free_js_value(tmpjs->type.object.value);
          
        js = tmpjs->type.object.next_object;
        free(tmpjs);
      }
    }else if(js->code_type == jstype_array){
      struct js_value *tmpjs = NULL;
      while(js){
        tmpjs = js;
        if((tmpjs->type.array.iter!=NULL) && (tmpjs->type.array.prev_element == NULL)){ 
          free(tmpjs->type.array.iter);
        }
        free_js_value(tmpjs->type.array.value);
        
        js =  tmpjs->type.array.next_element; // next_(tmpjs);
        free(tmpjs);
      }
    }
  }
}

struct js_value * create_js_value_string(char * input, struct js_value * parent){
  struct js_value * js = malloc(sizeof(struct js_value));
  js->parent = parent;
/*
  if(*input == '"')
    js->str_value = input+1;
  else*/
    js->str_value = input;
  js->code_type =  jstype_string;
  char *cur = js->str_value;
  //if(*input == '"') ++cur;
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

    //cur = str_value + js->type.array.value->length + (js->type.array.value->code_type != jstype_number) ; //1 ;
    cur = str_value + js->type.array.value->length + (js->type.array.value->code_type == jstype_string) ; //1 ;
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
   for(; is_js_space(*input); ++input){}

   //printf("\n>>strVal:%s\n",input);
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
  if(*cur == '}'){
    
    js->type.object.value = create_js_value_null(NULL, js);// NULL;
    js->type.object.value->length = cur - input;
    js->type.object.key_length = 0;
    js->type.object.key = NULL;
    js->type.object.next_object = NULL;
    js->parent = parent;
    return js;
  }



  while(cur < input + js_parent->length)
  { 
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
    char *key = cur;
    // /1/js->type.object.key = cur;
    for(; *cur != '"'; ++cur);
    //js->key = cur;
    //for(; *cur != '"'; ++cur);
    //js->key_length = cur - js->key;
    // /1/js->type.object.key_length = cur - js->type.object.key;
    js->type.object.key_length = cur - key ;  
    js->type.object.key = malloc(js->type.object.key_length+1);
    memcpy(js->type.object.key,key,js->type.object.key_length);
    *(js->type.object.key + js->type.object.key_length) ='\0';

    //js->type.object.key = cur;
    for(; *cur != ':'; ++cur);
    ++cur;
    for(; is_js_space(*cur); ++cur);
//    printf("cur=%s| lenKey :%ld \n",cur,js->type.object.key_length);
 

    // value section
    char *str_value = cur; // + js->type.object.key->length;  
  
    js->type.object.value = create_js_value(str_value, js);
    //printf("\n[<<<: cur:%s\n(js->type.object.value->code_type != jstype_number)=%d\n",cur,(js->type.object.value->code_type != jstype_number));
    
    cur = str_value + js->type.object.value->length +  (js->type.object.value->code_type == jstype_string); // ((js->type.object.value->code_type < jstype_bool)||(js->type.object.value->code_type > jstype_number));// 1 ;
    //printf("\n[>>>: cur:%s\n",cur);
     
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
    //struct js_value *tmpit = iter->begin;
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
  if(js->code_type == jstype_object){
    struct js_iterator *iter = js->type.object.iter;
    if(index == js->type.object.index) return index;
    long size = iter->size;
    if(index >= size ){
      iter->current = iter->end;
      return size - 1;
    }
    long from_current_index = iter->current->type.object.index - index;
    size_t abs_cur_diff = abs(from_current_index); 
    size_t array_diff_index[3]  = {index, abs_cur_diff , size - 1 - index}; 
    size_t index_nearest = ARG_MIN_ARRAY_TYPE_SIZE_T(array_diff_index, 3);
    if(index_nearest == 0){
      iter->current = iter->begin;
      for(size_t i=0; i<array_diff_index[0]; ++i) iter->current = iter->current->type.object.next_object;//next_(iter->current); 
    }
    else if(index_nearest == 2){
      iter->current = iter->end;
      for(size_t i=0; i < array_diff_index[2]; ++i) iter->current = iter->current->type.object.prev_object;//prev_(iter->current); 
    }else if(from_current_index >= 0) 
      for(size_t i=0; i < array_diff_index[1]; ++i)  iter->current = iter->current->type.object.prev_object;//prev_(iter->current); prev_(iter->current);
    else  
      for(size_t i=0; i < array_diff_index[1]; ++i)  iter->current =  iter->current->type.object.next_object;//next_(iter->current); next_(iter->current);
      
    return index;

  }else{
    struct js_iterator *iter = js->type.array.iter;
    if(index == js->type.array.index) return index;
    long size = iter->size;
    if(index >= size ){
      iter->current = iter->end;
      return size - 1;
    }
    long from_current_index = iter->current->type.array.index - index;
    size_t abs_cur_diff = abs(from_current_index); 
    size_t array_diff_index[3]  = {index, abs_cur_diff , size - 1 - index}; 
    size_t index_nearest = ARG_MIN_ARRAY_TYPE_SIZE_T(array_diff_index, 3);
    if(index_nearest == 0){
      iter->current = iter->begin;
      for(size_t i=0; i<array_diff_index[0]; ++i) iter->current = iter->current->type.array.next_element;//next_(iter->current); 
    }
    else if(index_nearest == 2){
      iter->current = iter->end;
      for(size_t i=0; i < array_diff_index[2]; ++i) iter->current = iter->current->type.array.prev_element;//prev_(iter->current); 
    }else if(from_current_index >= 0) 
      for(size_t i=0; i < array_diff_index[1]; ++i)  iter->current = iter->current->type.array.prev_element;//prev_(iter->current); prev_(iter->current);
    else  
      for(size_t i=0; i < array_diff_index[1]; ++i)  iter->current =  iter->current->type.array.next_element;//next_(iter->current); next_(iter->current);
      
    return index;


  }


#if 0

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
#endif
  }

struct js_value * get_js_value_of_index_(size_t index, struct js_value *js){
  if(move_current_iter_to_index_(js, index) >=0) 
    return get_iterator_(js)->current;
  return NULL;
}

void set_next_(struct js_value * dstjs, struct js_value * jsnxt){
  if(dstjs->code_type == jstype_object){
    struct js_value *tmpjs = dstjs->type.object.next_object;
    struct js_iterator *iter = dstjs->type.object.iter; 
    size_t last_index = dstjs->type.object.index;
    
    if(jsnxt->code_type == jstype_object){
      dstjs->type.object.next_object = jsnxt;
      struct js_iterator *it_er = jsnxt->type.object.iter; 
      jsnxt->type.object.prev_object = dstjs;
      while(jsnxt){
        jsnxt->type.object.iter = iter;
        jsnxt->type.object.index = ++last_index;
        jsnxt = jsnxt->type.object.next_object;
      }
      if(tmpjs == NULL && it_er){
        iter->end = it_er->end;
      }else{
        while(tmpjs){
          tmpjs->type.object.index = ++last_index;
          tmpjs = tmpjs->type.object.next_object;
        }
      }
      iter->size = last_index + 1;
      if(it_er){
        free(it_er); 
      }
    }  
  }
  else if(dstjs->code_type == jstype_array){
    struct js_value *tmpjs = dstjs->type.array.next_element;
    struct js_iterator *iter = dstjs->type.array.iter; 
    size_t last_index = dstjs->type.array.index;
    
    if(jsnxt->code_type == jstype_array){
      dstjs->type.array.next_element = jsnxt;
      struct js_iterator *it_er = jsnxt->type.array.iter; 
      jsnxt->type.array.prev_element= dstjs;
      while(jsnxt){
        jsnxt->type.array.iter = iter;
        jsnxt->type.array.index = ++last_index;
        jsnxt = jsnxt->type.array.next_element;
      }
      if(tmpjs == NULL && it_er){
        iter->end = it_er->end;
      }else{
        while(tmpjs){
          tmpjs->type.array.index = ++last_index;
          tmpjs = tmpjs->type.array.next_element;
        }
      }
      iter->size = last_index + 1;
      if(it_er){ 
        free(it_er); 
      }
    }  
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

void delete_index_js_value(size_t index, struct js_value **js_org){
  if((*js_org) && ( (*js_org)->code_type >= jstype_object) ){
    struct js_value  *ttmp=NULL;
    ttmp = get_js_value_of_index_(index, *js_org);

      if(ttmp && ((*js_org)->code_type == jstype_object)){
        struct js_iterator *iter = (*js_org)->type.object.iter;
        struct js_value *prevJS = ttmp->type.object.prev_object;
        struct js_value *nextJS = ttmp->type.object.next_object;
       
        if(prevJS){
          prevJS->type.object.next_object = nextJS;

        }else{
          iter->begin = nextJS;
        }

        if(iter->current == ttmp){
          iter->current = (nextJS ? nextJS : prevJS) ;
        }
        if(nextJS){
          nextJS->type.object.prev_object = prevJS;
        }else{
          iter->end = prevJS;
        }
    
      if(ttmp == *js_org){
        *js_org = nextJS;
        iter->begin = nextJS;
      }
        while(nextJS){
         --(nextJS->type.object.index);
         nextJS = nextJS->type.object.next_object;
        }
        --(iter->size);
        
        ttmp->type.object.next_object = NULL;
        ttmp->type.object.prev_object = NULL;
        
        if(*js_org){
          ttmp->type.object.iter = NULL;
        }
          
        free_js_value(ttmp);
        
      }else{
        struct js_iterator *iter = (*js_org)->type.array.iter;
        struct js_value *prevJS = ttmp->type.array.prev_element;
        struct js_value *nextJS = ttmp->type.array.next_element;
       
        if(prevJS){
          prevJS->type.array.next_element = nextJS;

        }else{
          iter->begin = nextJS;
        }

        if(iter->current == ttmp){
          iter->current = (nextJS ? nextJS : prevJS) ;
        }
        if(nextJS){
          nextJS->type.array.prev_element = prevJS;
        }else{
          iter->end = prevJS;
        }
    
      if(ttmp == *js_org){
        *js_org = nextJS;
        iter->begin = nextJS;
      }
        while(nextJS){
         --(nextJS->type.array.index);
         nextJS = nextJS->type.array.next_element;
        }
        --(iter->size);
       
        ttmp->type.array.next_element = NULL;
        ttmp->type.array.prev_element = NULL;

        if(*js_org)
          ttmp->type.array.iter = NULL;
           
        free_js_value(ttmp);
       
      }
  }
}

struct js_iterator * get_iterator_(struct js_value *js){
  if(js->code_type == jstype_object) return js->type.object.iter;
  if(js->code_type == jstype_array) return js->type.array.iter;
  return NULL;
}
void set_iterator_(struct js_value *js, struct js_iterator *iter){

  if(js->code_type == jstype_object) js->type.object.iter = iter;
  if(js->code_type == jstype_array)  js->type.array.iter = iter;
}

void append_js_value(struct js_value *dst, char *input){/* if object type: input =  { "key" : value }, if key already exists value replace the old value! */
  if(dst){
    if(dst->code_type < jstype_object || get_iterator_(dst) == NULL) return;
    struct js_value *newval = create_js_value(input, dst->parent);
    if(newval->code_type != dst->code_type) {
      free_js_value(newval);
      return;
    }
    struct js_iterator *iter = get_iterator_(dst);
    set_next_(iter->end, newval);
  }
  
}


char * original_string_js_value(struct js_value *js){
  char *ret = malloc(js->length+1);
  strncpy(ret,js->str_value,js->length);
  ret[js->length] = '\0';




  return ret;

}

        //lret=strlen(buf);

#define UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)\
        (y_string_b_uf) = create_y_ptr_STRING((buf), (local_size));\
        (global_size) += (local_size);\
        push_back_list_y_ptr_STRING((m_str), (y_string_b_uf));\
  
  //      printf("debug:global_size=%ld, local_size=%ld, buf=%s / / %d / /\n",(global_size),(local_size),(buf), js->code_type);

/* tab_depth = number of tabulationfor values,  */
long int sprint_js_value_to_y_string_list(struct main_list_y_ptr_STRING *m_str, struct js_value *js, char sep, int tab_depth){
  long int global_size = 0, local_size;
  //char *buf = malloc(js->length);
  //printf("debug: js->length = %ld\n",js->length);
  char buf[500]; memset(buf,0,500);
  y_ptr_STRING y_string_b_uf; 

  if(js->code_type == jstype_number){
    //memset(buf,0,499);
    local_size = sprintf(buf,"%Lf",js->type.number);
    UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
  }else if(js->code_type == jstype_string){
    //memset(buf,0,499);
    local_size = sprintf(buf,"\"%s\"",js->type.string);
    UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
  }else if(js->code_type == jstype_bool){
    //memset(buf,0,499);
    local_size = sprintf(buf,"%s",js->type.boolean ? "true" : "false");
    UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
  }else if(js->code_type == jstype_null){
    //memset(buf,0,499);
    local_size = sprintf(buf,"%s","null");
    UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
  }else if(js->code_type == jstype_object){
    struct js_value *tmpjs = js;

    while(tmpjs){
      
      if(tmpjs->type.object.prev_object == NULL){ 
        local_size = sprintf(buf,"%c%*c{ ",sep,tab_depth*(tmpjs->type.object.depth),' ');
        UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
      }

        local_size = sprintf(buf,"%c%*c\"%s\" : ",sep, tab_depth*(tmpjs->type.object.depth),' ', tmpjs->type.object.key);
        UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
        
        global_size += sprint_js_value_to_y_string_list(m_str, tmpjs->type.object.value, sep, tab_depth );

      if(tmpjs->type.object.next_object == NULL){
        local_size = sprintf(buf,"%c%*c} ",sep,tab_depth*(tmpjs->type.object.depth),' '); //printf(" }");
        UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
      }else{ 
        //memset(buf,0,499);
        local_size = sprintf(buf,", ");
        UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
      }
      //printf("\n");
      tmpjs = tmpjs->type.object.next_object;
    }
  }else if(js->code_type == jstype_array){
    struct js_value *tmpjs = js;
    while(tmpjs){
      if(tmpjs->type.array.prev_element == NULL){  
        //memset(buf,0,499);
        local_size = sprintf(buf, "%c%*c[ ",sep,tab_depth*(tmpjs->type.array.depth),' ');
        UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
      }
        if(tmpjs->type.array.value->code_type < jstype_object ) {
          //memset(buf,0,499);
          local_size = sprintf(buf,"%c%*c ",sep,tab_depth*(tmpjs->type.array.depth),' ');
          UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
        }
        global_size += sprint_js_value_to_y_string_list(m_str,tmpjs->type.array.value,sep,tab_depth);
      if(tmpjs->type.array.next_element == NULL){  //printf(" ]");
        //memset(buf,0,499);
        local_size = sprintf(buf,"%c%*c] ",sep,tab_depth*(tmpjs->type.array.depth),' ');
        UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
      }else{
        //memset(buf,0,499);
        local_size = sprintf(buf,", ");
        UPDATE_RET_N_PUSH_Y_STRING(local_size, global_size, m_str, y_string_b_uf, buf)
      }
      tmpjs =  tmpjs->type.array.next_element; // next_(tmpjs);
    }
  }

  //free(buf);
  return global_size;
}

/* dstString can be NULL ! (it's better)*/
long int sprint_js_value(char **dstString, struct js_value *js, char sep, int tab_depth){
  struct main_list_y_ptr_STRING *m_str=create_var_list_y_ptr_STRING();
 // remove_all_ptr_type_list_y_ptr_STRING(m_str); 
  long int ret = sprint_js_value_to_y_string_list(m_str,js,sep, tab_depth);
  copy_list_y_ptr_STRING_to_one_string(dstString , m_str);
  //printf("debug:%s\n",*dstString); 
  purge_ptr_type_list_y_ptr_STRING(m_str);
  return ret;
}
/* dstString can be NULL ! (it's better)*/
long int sprint_one_line_js_value(char **dstString, struct js_value *js){
  struct main_list_y_ptr_STRING *m_str=create_var_list_y_ptr_STRING();
 // remove_all_ptr_type_list_y_ptr_STRING(m_str); 
  long int ret = sprint_js_value_to_y_string_list(m_str,js,' ', 1);
  copy_list_y_ptr_STRING_to_one_string(dstString , m_str);
  //printf("debug:%s\n",*dstString); 
  
  purge_ptr_type_list_y_ptr_STRING(m_str);
  return ret;
}

void print_js_value(struct js_value *js){
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
        /*
        char key[tmpjs->type.object.key_length + 1];
        strncpy(key, tmpjs->type.object.key, tmpjs->type.object.key_length);
        key[tmpjs->type.object.key_length]='\0';
        printf("\n%*c%s : ", 4*(tmpjs->type.object.depth),' ', key );
        */
        printf("\n%*c\"%s\" : ", 4*(tmpjs->type.object.depth),' ', tmpjs->type.object.key);
      print_js_value(tmpjs->type.object.value);

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
        print_js_value(tmpjs->type.array.value);
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
        js->type.object.iter->current = tmp;
        return tmp; //tmp->type.object.value == value_of_(tmp);
      }
      tmp = tmp->type.object.next_object;//next_(tmp);
    }
  }
  return NULL; 
}
void delete_key_js_value(char * key, struct js_value **js_org){
  struct js_value *js = get_js_value_of_key(key, *js_org);
  if(js){
    delete_index_js_value(js->type.object.index, js_org);
  }
}

size_t js_org_str_length(struct js_value *js){
  // if string add 2 \" values
  return js->length+1+2*(js->code_type == 0);
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
