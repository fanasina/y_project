#ifndef __Y_JSON_T_H__C__
#define __Y_JSON_T_H__C__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list_t/list_t.h"

#define ITERATOR__(type) \
struct iterator_##type {\
  size_t size;\
  type *begin;\
  type *end;\
  type *iterator;\
};\




enum code_jstype {
  jstype_string,
  jstype_bool,
  jstype_null,
  jstype_number,
  jstype_object,
  jstype_array,
};

struct js_value;

struct js_iterator {
  size_t size;
  struct js_value *begin;
  struct js_value *end;
  struct js_value *current;
//  struct js_value *child;
//  struct js_value *parent;
//  struct js_value * (*next_)(struct js_value * js);
//  struct js_value * (*prev_)(struct js_value * js);
//  void (*set_index_)(struct js_value *js, size_t index);
//  long (*get_index_)(struct js_value *js);
};

void set_index_(struct js_value *js, size_t index);
long get_index_(struct js_value *js);
struct js_value * next_(struct js_value * js);
struct js_value * prev_(struct js_value * js);
void set_next_(struct js_value * dst, struct js_value * jsnxt);
void set_prev_(struct js_value ** dst, struct js_value * jsprv);


struct js_object {
  size_t index;
  int depth;
  char *key; /* non zero terminal */
  size_t key_length; /* key string length */
//  struct js_value *key;
  struct js_value *value;
//  struct iterator *iter;
  struct js_value *next_object; 
  struct js_value *prev_object; 
  struct js_iterator *iter;
};



struct js_array {
  size_t index;
  int depth;
  struct js_value *value;
  struct js_value *next_element; 
  struct js_value *prev_element;  
  struct js_iterator *iter;
};


struct js_value {
  char *str_value; /* non zero terminal */
  size_t length; /* value string lenght */
  enum code_jstype code_type;
  union {
    char *string;
    long double number;
    bool boolean;
    struct js_object object;
    struct js_array array;
  } type;
  struct js_value * parent;
//  struct js_value * next;
//  struct js_value * prev;
};


void free_js_value(struct js_value *js);

bool is_js_space(char c);

struct js_value * create_js_value(char * input, struct js_value * parent);

struct js_value * create_js_value_string(char * input, struct js_value * parent);

struct js_value * create_js_value_number(char * input, struct js_value * parent);

struct js_value * create_js_value_null(char * input, struct js_value * parent);


struct js_value * create_js_value_true(char * input, struct js_value * parent);
struct js_value * create_js_value_false(char * input, struct js_value * parent);

struct js_value * create_js_value_object(char *input, struct js_value * parent);
struct js_value * create_js_value_array(char * input, struct js_value * parent);

struct js_iterator * create_js_iterator(struct js_value * js);

void add_js_value_index(size_t index, struct js_value *js_to_add, struct js_value **js_org);

void print_value(struct js_value *js);

char * original_string_js_value(struct js_value *js);

struct js_value *get_js_value_of_key(char * key, struct js_value *js );
struct js_iterator * get_iterator_(struct js_value *js);

void append_js_value(struct js_value *dst, char *input);

struct js_value * value_of_(struct js_value * js);


#endif /* __Y_JSON_T_H__C__ */



