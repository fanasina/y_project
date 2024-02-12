#ifndef __MOCK_C_H__
#define __MOCK_C_H__

#include "ftest/ftest.h"
#include "tools_t/tools_t.h"

#define INFINITY -8
#define INITSTATE -1
#define DONOTHING 0

#define PRE_ID ___line_
/*
 * list of each variable called 
 * use str_print_current_variables attibute function pointer to record variable
 * so if STR_PRINT_CUR_VAR is not defined, this list is empty!
 */
struct list_current_variable{
  char *str_current_variables;
  struct list_current_variable *next;
};

/*
 * list to store info abou mock function 
 */
struct func_mock_info_struct{
  long id;
  bool used;
  char *str_namefunc;
  char *str_conditions;
  char *str_caller;
  //char *str_current_variables;
  struct list_current_variable *l_current_var;
  int expect_call;/* 1 if EXPECT_MOCK_CALL and 0 if WILL_MOCK_CALL */
  long call;/* increment when call (try to executed) and 0 if not : init value */
  long failed_call;/* increment when condition not fill and 0 if not : init value */
  long init_times_left;/* DONOTHING do nothing (pass to -> next), INFINITY every time; INITSTATE init; > 0 execute and decrement  */
  long times_left;/* DONOTHING do nothing (pass to -> next), INFINITY every time; INITSTATE init; > 0 execute and decrement  */
  struct func_mock_info_struct *next;
};

/*
 * to list all mock responses of all mock functions in one list
 */
struct list_base_fmock{
  struct func_mock_info_struct *info_mock;
  struct list_base_fmock *next;
};



int parse_count_args_(char *input);
void append_fmock_to_listmock(struct func_mock_info_struct **f_mock_list,  struct func_mock_info_struct *f_mock);
void append_list_base_fmock(struct list_base_fmock **l_fmock, struct func_mock_info_struct *f_mock);
void append_variable_current(struct list_current_variable **lcurrent_var, char *current_var);

void clear_fmock_info_list(struct func_mock_info_struct **f_mock_list);
void clear_list_base_fmock(struct list_base_fmock **l_fmock);
void clear_variable_current(struct list_current_variable **lcurrent_var);

// if input == functioname___line_NBLINE return functioname, else it return the input
//char* extract_name_func_mock(char *input);

extern struct func_mock_info_struct *f_mock_glist;
extern struct list_base_fmock *g_list_base_fmock;

#if 0
    int expect_call; /* 1 if EXPECT_MOCK_CALL and 0 if WILL_MOCK_CALL */\
    long init_times_left; /* DONOTHING do nothing (pass to -> next), INFINITY every time; INITSTATE init; > 0 execute and decrement  */\
    long times_left; /* DONOTHING do nothing (pass to -> next), INFINITY every time; INITSTATE init; > 0 execute and decrement  */\

#endif

#define INIT_MOCK_INFO_IF_NO__(tmp__mock, namefunction, pre_id, id) \
      (tmp__mock)->run = NULL;\
      (tmp__mock)->call_mock_condition = NULL;\
      /*(tmp__mock)->str_print_current_variables = list_mo_ ## namefunction .str_print_current_variables;*/\
      ((tmp__mock)->info_mock)->expect_call = -1;\
      ((tmp__mock)->info_mock)->used = true;\
      ((tmp__mock)->info_mock)->call = 0;\
      ((tmp__mock)->info_mock)->failed_call = 0;\
      ((tmp__mock)->info_mock)->str_namefunc = malloc(strlen(#namefunction) + 43 + strlen(#pre_id));\
      sprintf(((tmp__mock)->info_mock)->str_namefunc,"%s%s%d",#namefunction,#pre_id,id);\
      ((tmp__mock)->info_mock)->str_conditions = NULL;\
      ((tmp__mock)->info_mock)->str_caller = NULL;\
      ((tmp__mock)->info_mock)->l_current_var= NULL;\
      ((tmp__mock)->info_mock)->next = NULL;\
      /*(tmp__mock)->next = NULL;*/\
      append_fmock_to_listmock(&f_mock_glist, (tmp__mock)->info_mock);\
      append_list_base_fmock( &g_list_base_fmock ,(tmp__mock)->info_mock);

#define INIT_MOCK_INFO_IF_NO_(tmp_new_mock, namefunction, pre_id) \
    INIT_MOCK_INFO_IF_NO__(tmp_new_mock, namefunction, pre_id, __LINE__) \

#define MOCK_FUNC(returntype, namefunction, args_prototype_with_parenthesis, args_call_with_parenthesis)\
  /*typedef returntype FUNC_type_ ## namefunction args_prototype_with_parenthesis ;*/\
  /*typedef args_prototype_with_parenthesis args_ ## namefunction;*/\
  struct list_mock_return_ ## namefunction{\
    returntype (*run) args_prototype_with_parenthesis;\
    int (*call_mock_condition) args_prototype_with_parenthesis ;/* to store condition */\
    char* (*str_print_current_variables) args_prototype_with_parenthesis ;/* to store current variables CREATE by macro STR_PRINT_CUR_VAR same arguments as MOCK_FUNC without returntype whoch is always char * */\
    struct func_mock_info_struct *info_mock;\
    struct list_mock_return_ ## namefunction *next;\
  } list_mo_ ## namefunction;\
  __attribute__((constructor)) void init_list_m_ ## namefunction(void){\
    list_mo_ ## namefunction.info_mock = malloc(sizeof(struct func_mock_info_struct));\
    (list_mo_ ## namefunction.info_mock)->used = false;\
    (list_mo_ ## namefunction.info_mock)->times_left = INITSTATE;\
    (list_mo_ ## namefunction.info_mock)->init_times_left = INITSTATE;\
    list_mo_ ## namefunction.str_print_current_variables = NULL;\
    list_mo_ ## namefunction.next = NULL;\
  }\
   \
  __attribute__((destructor)) void destruct_list_m_  ## namefunction(void){   \
    /*free(list_mo_ ## namefunction.info_mock);*/ \
    struct list_mock_return_ ## namefunction *tmp_nn = list_mo_ ## namefunction.next, *ttmp_nn;\
    if((list_mo_ ## namefunction.info_mock)->used == false ){\
      free(list_mo_ ## namefunction.info_mock);\
    }\
    while(tmp_nn){\
      ttmp_nn = tmp_nn;\
      tmp_nn = tmp_nn->next;\
      /*free(ttmp_nn->info_mock);*/\
      free(ttmp_nn);\
    }\
    PRINT_DEBUG(" purge list mo_ %s done!\n",#namefunction);\
   \
  }\
    \
  returntype namefunction args_prototype_with_parenthesis {\
    static size_t count_call_f=0;\
    ++count_call_f;\
    PRINT_DEBUG(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>><>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>count call of %s: %ld\n",#namefunction,count_call_f);\
    struct list_mock_return_ ## namefunction *tmp_mock = &list_mo_ ## namefunction;\
    if( (tmp_mock->info_mock)->times_left == INITSTATE ){\
         PRINT_HK_C(colors_f[k_YELLOW],tab_hk_f[hk_TR]," WARNING, %s, no EXPECT_MOCK_CALL or WILL_MOCK_CALL, but called %ld times.\n",#namefunction, count_call_f);\
       if(count_call_f==1){\
         PRINT_HK_C(colors_f[k_YELLOW],tab_hk_f[hk_TR]," For instance:\n"\
             "%s EXPECT_MOCK_CALL(%s,%s,%s,true,1){\n"\
             "%s\t %s ret;\n%s \t ...do something with %s;\n"\
             "%s\t return ret;\n"\
             "%s }\n"\
             "%s if call once and accept all args, the same args with WILL_MOCK_CALL \n\n",\
            tab_hk_f[hk_TR], #returntype, #namefunction,#args_prototype_with_parenthesis, tab_hk_f[hk_TR],#returntype, \
            tab_hk_f[hk_TR], #args_call_with_parenthesis, tab_hk_f[hk_TR], tab_hk_f[hk_TR], tab_hk_f[hk_TR] ); \
        /*return (returntype)0;*/ \
        INIT_MOCK_INFO_IF_NO_(tmp_mock,namefunction, PRE_ID);\
      }/* to have log */\
      /*if(list_mo_ ## namefunction.next ) PRINT_ERROR(" %s .next SHOULD BE NULL\n",STRFY(list_mo_ ## namefunction));*/\
    }\
    while(tmp_mock->next && (tmp_mock->info_mock)->times_left == 0) {tmp_mock = tmp_mock->next ;}\
    ++((tmp_mock->info_mock)->call);\
    if(tmp_mock->str_print_current_variables){\
      append_variable_current(&((tmp_mock->info_mock)->l_current_var), tmp_mock->str_print_current_variables args_call_with_parenthesis);\
    }\
    else if(count_call_f == 1){\
      PRINT_HK_C(colors_f[k_YELLOW],tab_hk_f[hk_TR]," no printer variable function defined, to define it:\n"\
          "%s STR_PRINT_CUR_VAR(%s,%s,%s){\n"\
          "%s\t char* ret=malloc(256);/*for instance*/;\n"\
          "%s\t ...  sprintf(ret,...., %s);/*for instance*/ \n"\
          "%s\t return ret;\n"\
          "%s }\n"\
          "%s same prototype as MOCK_FUNC whithout returntype which always char* i\n\n",\
            tab_hk_f[hk_TR], #namefunction,#args_prototype_with_parenthesis, #args_call_with_parenthesis, \
            tab_hk_f[hk_TR], tab_hk_f[hk_TR], #args_call_with_parenthesis, tab_hk_f[hk_TR], tab_hk_f[hk_TR], tab_hk_f[hk_TR] ); \
    }\
      /*LOG("condition_func:%d\n", tmp_mock->call_mock_condition args_call_with_parenthesis);*/ /*LOG("%s\n","failure condition");*/\
    /*EXPECT_EQ_TYPE_INT(1, tmp_mock->call_mock_condition args_call_with_parenthesis);*/ /*LOG("%s\n","failure condition");*/\
    /*if ((tmp_mock->info_mock)->times_left == 0)*/ /*no longer response, default return */ \
      /*return (returntype)0;*//* default return */\
    if( (tmp_mock->info_mock)->str_caller == NULL){ \
      if(count_call_f == 1){\
        PRINT_HK_C(colors_f[k_YELLOW],tab_hk_f[hk_TR]," WARNING, no  INIT_CALLER_MOCK; you can put it like this: \n"\
            "%s TEST(nametest){\n"\
            "%s\t INIT_CALLER_MOCK(%s); \n"\
            "%s\t %s%s; \n"\
            "%s }\n"\
            "%s i.e before calling %s in this TEST, to have explicit logs\n",\
          tab_hk_f[hk_TR], tab_hk_f[hk_TR], #namefunction, tab_hk_f[hk_TR],#namefunction,#args_call_with_parenthesis,  tab_hk_f[hk_TR], tab_hk_f[hk_TR], #namefunction);} \
      /*return (returntype)0;*/ \
    }\
    else if (((tmp_mock->info_mock)->times_left != 0) && ((tmp_mock->info_mock)->times_left != INITSTATE )) {\
      size_t len0 = strlen((tmp_mock->info_mock)->str_conditions);\
      size_t len1 = strlen("when checking condition call: aa");\
      char *msg_call=malloc(len0 + len1 + strlen(__func__)+1);\
      sprintf(msg_call,"when checking %s condition call: %s",__func__,(tmp_mock->info_mock)->str_conditions);\
      HANDLE_OP_EXPECT_NAME(EQ,TYPE_INT,1, tmp_mock->call_mock_condition args_call_with_parenthesis, (tmp_mock->info_mock)->str_caller, msg_call); /*LOG("%s\n","failure condition");*/\
      free(msg_call);\
    }\
    /*if(0 == tmp_mock->call_mock_condition args_call_with_parenthesis){\
      PRINT_LOC("Failure, arguments not expected\ncondition ( %s ) not verified\n\n", (tmp_mock->info_mock)->str_conditions);\
      PRINT_HK_C(RED_K,tab_hk_f[hk_TR]," 1 argument check failed from %s \n",__func__);                                 \
    }*/\
    PRINT_DEBUG(" %*c VALUES: mock function:%s, conditions:%s t_left:%ld, init_left:%ld| args:%s\n",8,'^',(tmp_mock->info_mock)->str_namefunc, (tmp_mock->info_mock)->str_conditions, (tmp_mock->info_mock)->times_left,(tmp_mock->info_mock)->init_times_left, #args_call_with_parenthesis);\
    if (((tmp_mock->info_mock)->times_left <= INFINITY) || ((tmp_mock->info_mock)->times_left > 0)){\
      --((tmp_mock->info_mock)->times_left);\
    PRINT_DEBUG(" %*c VALUES: mock function:%s, conditions:%s t_left:%ld, init_left:%ld| args:%s\n",8,'v',(tmp_mock->info_mock)->str_namefunc, (tmp_mock->info_mock)->str_conditions, (tmp_mock->info_mock)->times_left,(tmp_mock->info_mock)->init_times_left, #args_call_with_parenthesis);\
      if(1 == tmp_mock->call_mock_condition args_call_with_parenthesis){\
        return tmp_mock->run args_call_with_parenthesis;\
      }\
      else ++((tmp_mock->info_mock)->failed_call);\
    }\
    return (returntype)0;/* default return */\
  }


char* extract_name_func_mock(char *input);

/*
 * used in mock functions to check the conditions
 */
#define EXPECT_EQ_IN_MOCKF(var1,var2, name_f_mocked)\
  do{ \
   if((list_mo_ ## name_f_mocked.info_mock)->str_caller) {\
     HANDLE_OP_EXPECT_NAME(EQ,TYPE_INT,var1,var2,(list_mo_ ## name_f_mocked.info_mock)->str_caller,"mock test");\
   }\
   else\
     HANDLE_OP_EXPECT_NAME(EQ,TYPE_INT,var1,var2,__func__,"mock test");\
}while(0)
    

/*
 *  to inject the name TEST caller in the mock attribute info, usefull in logs and stats
 */
#define INIT_CALLER_MOCK(namefunction)/* */\
  do{\
      struct list_mock_return_ ## namefunction *tmp_mock = &list_mo_ ## namefunction;\
      while(tmp_mock){\
        (tmp_mock->info_mock)->str_caller=malloc(strlen(__func__)+1);\
        strcpy((tmp_mock->info_mock)->str_caller,__func__);\
        tmp_mock = tmp_mock->next;\
      }\
 }while(0);

/*
 * to create/ define str_print_current_variables functions
 * prototype:  char* str_print_current_variables (prototype of mock function)
 * the args of the macro are the same of MOCK_FUNC without the returntype which is always (char*).
 * It need to be defined after MOCK_FUNC but need to be before EXPECT_MOCK_CALL or WILL_MOCK_CALL
 */

#define STR_PRINT_CUR_VAR(namefunction, args_prototype_with_parenthesis, args_call_with_parenthesis)\
  char* str_print_variables ## namefunction args_prototype_with_parenthesis;\
__attribute__((constructor)) void create_str_print_variables ## namefunction(){\
  list_mo_ ## namefunction .str_print_current_variables = str_print_variables ## namefunction;\
  }\
  char* str_print_variables ## namefunction args_prototype_with_parenthesis




#define FILL_MOCK_INFO(tmp_new_mock, namefunction, condition_on_args_expression , repeat, f_expect_call, pre_id, id, is_init) \
      (tmp_new_mock)->run = CONCAT(run_ ## namefunction ## pre_id, id);\
      (tmp_new_mock)->call_mock_condition = CONCAT(namefunction ## _cond_, id);\
      if(!is_init)\
        (tmp_new_mock)->str_print_current_variables = list_mo_ ## namefunction .str_print_current_variables;\
      /*(tmp_new_mock)->info_mock  = malloc(sizeof(struct func_mock_info_struct));*/\
      ((tmp_new_mock)->info_mock)->expect_call = f_expect_call;\
      ((tmp_new_mock)->info_mock)->used = true;\
      ((tmp_new_mock)->info_mock)->call = 0;\
      ((tmp_new_mock)->info_mock)->failed_call = 0;\
      ((tmp_new_mock)->info_mock)->init_times_left = repeat;\
      ((tmp_new_mock)->info_mock)->times_left = repeat;\
      ((tmp_new_mock)->info_mock)->str_namefunc = malloc(strlen(#namefunction) + 43 + strlen(#pre_id));\
      sprintf(((tmp_new_mock)->info_mock)->str_namefunc,"%s%s%d",#namefunction,#pre_id,id);\
      ((tmp_new_mock)->info_mock)->str_conditions = malloc(strlen(#condition_on_args_expression)+1);\
      strcpy(((tmp_new_mock)->info_mock)->str_conditions, #condition_on_args_expression);\
      ((tmp_new_mock)->info_mock)->str_caller = NULL;\
      ((tmp_new_mock)->info_mock)->l_current_var= NULL;\
      ((tmp_new_mock)->info_mock)->next = NULL;\
      (tmp_new_mock)->next = NULL;\
      append_fmock_to_listmock(&f_mock_glist, (tmp_new_mock)->info_mock);


#define ADD_RESPONSE_(returntype, namefunction, args_prototype_with_parenthesis, condition_on_args_expression , repeat, f_expect_call, pre_id, id)\
  /*FUNC_type_ ## namefunction CONCAT(run_ ## namefunction ## pre_id , id);*/\
  returntype CONCAT(run_ ## namefunction ## pre_id , id) args_prototype_with_parenthesis; \
  int CONCAT(namefunction ## _cond_ , id) args_prototype_with_parenthesis {/*LOG("cond:%d\n",condition_on_args_expression);*/ return condition_on_args_expression;}\
  __attribute__((constructor)) void CONCAT(append_list_ ## namefunction , id)(void){\
    PRINT_DEBUG(" in constructor fmock : func :%s\n",#namefunction);\
    struct list_mock_return_ ## namefunction *tmp_mock = &list_mo_ ## namefunction;\
    if((tmp_mock->info_mock)->times_left == INITSTATE){/* init state */\
      FILL_MOCK_INFO(tmp_mock, namefunction, condition_on_args_expression , repeat, f_expect_call, pre_id, id, true);\
      append_list_base_fmock( &g_list_base_fmock ,(tmp_mock->info_mock));\
    }\
    else{\
      while(tmp_mock->next) tmp_mock = tmp_mock->next;\
      tmp_mock->next = malloc(sizeof(list_mo_ ## namefunction));\
      (tmp_mock->next)->info_mock  = malloc(sizeof(struct func_mock_info_struct));\
      FILL_MOCK_INFO(tmp_mock->next, namefunction, condition_on_args_expression , repeat, f_expect_call, pre_id, id, false);\
      /*(tmp_mock->info_mock)->next  = (tmp_mock->next)->info_mock ;*/\
    }\
  }\
  returntype CONCAT(run_ ## namefunction ## pre_id, id) args_prototype_with_parenthesis

/*
 * have to define this below macro to rewrite the right macro identifier (PRE_ID) 
 */ 
      
#define ADD_RESPONSE(returntype, namefunction, args_prototype_with_parenthesis, condition_on_args_expression , repeat, f_expect_call, pre_id, id)\
   ADD_RESPONSE_(returntype, namefunction, args_prototype_with_parenthesis, condition_on_args_expression , repeat, f_expect_call, pre_id, id)\


#define EXPECT_MOCK_CALL(returntype, namefunction, args_prototype_with_parenthesis, condition_on_args_expression ,repeat) \
  ADD_RESPONSE(returntype,namefunction, args_prototype_with_parenthesis, condition_on_args_expression, repeat, 1, PRE_ID, __LINE__)


#define WILL_MOCK_CALL(returntype, namefunction, args_prototype_with_parenthesis, condition_on_args_expression ,repeat) \
  ADD_RESPONSE(returntype,namefunction, args_prototype_with_parenthesis, condition_on_args_expression, repeat, 0, PRE_ID, __LINE__)
  


#endif /* __MOCK_C_H__ */
