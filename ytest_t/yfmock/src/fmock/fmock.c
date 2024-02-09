#include "fmock/fmock.h"

/*
 * global variables
 */

//char *colors_f[]={DEFAULT_K, RED_K, GREEN_K, YELLOW_K, BLUE_K, ""};

size_t count_f_mock_wished=0;
pthread_mutex_t mut_count_f_mock_wished;

size_t count_f_mock=0;
pthread_mutex_t mut_count_f_mock;

size_t count_expect_mock=0;
pthread_mutex_t mut_count_expect_mock;

struct list_base_fmock *g_list_base_fmock=NULL;
pthread_mutex_t mut_g_list_base_fmock; 

#define LOCK(mutex_var)  pthread_mutex_lock(&mutex_var);
#define UNLOCK(mutex_var) pthread_mutex_unlock(&mutex_var);


#define INCREMENT_(variable)\
  do{\
      LOCK(mut_##variable); \
      ++variable;\
      UNLOCK(mut_##variable);\
  }while(0);


/*
 * return the numbers of comas (,) +1 in the input string
 */


int parse_count_args_(char *input){
  int val=0;
  for(int i = 0; i< strlen(input); ++i){
    if(input[i]==',') ++val;
  }  
  return val+1;
}

/*
 * the begin only !
 */
void append_list_base_fmock(struct list_base_fmock **l_fmock, struct func_mock_info_struct *f_mock){
  INCREMENT_(count_f_mock);
  LOCK(mut_g_list_base_fmock);
  PRINT_DEBUG(" append_list_base_fmock %s",f_mock->str_namefunc);
  if(*l_fmock){
    struct list_base_fmock *tmp_l_n = *l_fmock;
    while(tmp_l_n->next) tmp_l_n = tmp_l_n->next;
    (tmp_l_n->next) = malloc(sizeof(struct list_base_fmock));
    (tmp_l_n->next)->info_mock = f_mock;
    (tmp_l_n->next)->next = NULL;
  }
  else{
    *l_fmock = malloc(sizeof(struct list_base_fmock)); 
    (*l_fmock)->info_mock = f_mock;
    (*l_fmock)->next = NULL;
  }
  UNLOCK(mut_g_list_base_fmock);
}

struct func_mock_info_struct *f_mock_glist = NULL;
pthread_mutex_t mut_f_mock_glist;

void append_variable_current(struct list_current_variable **lcurrent_var, char *current_var){
  if(*lcurrent_var){
    PRINT_DEBUG("----- l_current_var not NULL, content: %s have to add %s\n",(*lcurrent_var)->str_current_variables, current_var);
    struct list_current_variable *tmp_lcv = *lcurrent_var;
    while(tmp_lcv->next) tmp_lcv = tmp_lcv->next;
    tmp_lcv->next = malloc(sizeof(struct list_current_variable));
    //(tmp_lcv->next)->str_current_variables = malloc(strlen(current_var));
    //strcpy((tmp_lcv->next)->str_current_variables,current_var);
    (tmp_lcv->next)->str_current_variables = current_var;
    (tmp_lcv->next)->next= NULL;
    
  }
  else{
    PRINT_DEBUG("-- lcurrent_var %s\n","NULL");
    *lcurrent_var = malloc(sizeof(struct list_current_variable));
    //(*lcurrent_var)->str_current_variables = malloc(strlen(current_var));
    //strcpy((*lcurrent_var)->str_current_variables,current_var);
    (*lcurrent_var)->str_current_variables = current_var;
    (*lcurrent_var)->next = NULL;
  }
}

void append_fmock_to_listmock(struct func_mock_info_struct **f_mock_list,  struct func_mock_info_struct *f_mock){
  INCREMENT_(count_f_mock_wished);
  if(f_mock->expect_call) {
    INCREMENT_(count_expect_mock);
  }
  LOCK(mut_f_mock_glist);
  PRINT_DEBUG(" append_fmock_to_listmock %s",f_mock->str_namefunc);
  if(*f_mock_list){
    struct func_mock_info_struct *tmp_fmock_info = *f_mock_list;
    while(tmp_fmock_info->next) tmp_fmock_info = tmp_fmock_info->next;
    tmp_fmock_info->next = f_mock;
  }
  else{
    *f_mock_list = f_mock;
  }
  UNLOCK(mut_f_mock_glist);

}



#define SSTRFY(x) STRFY(x)

char* extract_name_func_mock(char *input){
  char * ret=malloc(strlen(input) + 1);
  strcpy(ret,input);
  char * pre_id_ = SSTRFY(PRE_ID);
  size_t len_pre_id_ = strlen(pre_id_);
  for(size_t i=0; i<strlen(ret)-len_pre_id_; ++i){
    if(strncmp(ret+i,pre_id_,len_pre_id_) == 0){
      ret[i]='\0';
      break;
    }
  }
  return ret;
}

__attribute__((constructor))
  void
  init_mock_c(){
    
      pthread_mutex_init(&mut_g_list_base_fmock, NULL);
      pthread_mutex_init(&mut_f_mock_glist, NULL);
      pthread_mutex_init(&mut_count_f_mock_wished, NULL);
      pthread_mutex_init(&mut_count_f_mock, NULL);
      pthread_mutex_init(&mut_count_expect_mock, NULL);
  }

extern bool is_parallel_nb;



char * number_call_translate(long nb){
  char *ret=malloc(250);
  if(nb>1) sprintf(ret," be called %ld times",nb);
  else if(nb == 1) sprintf(ret," be called once");
  else if(nb == 0 ) sprintf(ret," not to be executed");
  else if(nb==INFINITY) sprintf(ret," be called forever");
  else if(nb==INITSTATE) sprintf(ret," not expected");
  else sprintf(ret," nothing! it's negative:%ld", nb);

  return ret;
}

char * strprint_caller_(char *input){
  if(input==NULL) { return "";}
  char *called_in=",\t called in ";
  char *ret = malloc(strlen(called_in) + strlen(input) + 1);
  sprintf(ret,"%s%s",called_in,input);
  return ret;
}

#define PRINT_VAR_CUR(mockinfo)\
    do{\
      PRINTF("\n%s list of variables when %s was called, with condition %s:\n\t\t",tab_hk_f[hk_EQ],mockinfo->str_namefunc,mockinfo->str_conditions);\
      size_t cal_cur=0;\
      struct list_current_variable *tmp_cur_v = mockinfo->l_current_var;\
      while(tmp_cur_v){\
        PRINTF(" call : %ld : variables : %s \n\t\t",++cal_cur, tmp_cur_v->str_current_variables);\
        tmp_cur_v = tmp_cur_v->next;\
      }\
      PRINTF("\n");\
    }while(0);


  

__attribute__((destructor))
  void
  check_mock_excpected(){

    signal(SIGSEGV, SIG_DFL);  /* restore default behaviour ,  */

    //int k_DEFAULT=0, k_GREEN=1, k_RED=2, k_YELLOW=3, k_BLUE=4, k_NOTHING;
    //if(unicolour) {
      //k_GREEN=k_NOTHING; k_RED=k_NOTHING; k_YELLOW=k_NOTHING; k_BLUE=k_NOTHING;
      //for(int i=0; i< Dk_NOTHING;++i) strcpy(colors_f[i]," ");
    //}
  if(only_usage) return; /* do nothing */
  if(g_list_base_fmock == NULL) return; /* do nothing because no mock functions */
    struct winsize w;
    ioctl(1, TIOCGWINSZ, &w);
    
    char *reader=malloc(w.ws_col+1);
    strcpy(reader,"STAT OF MOCK FUNCTIONS");

    fprintf(F_OUT,"%s\n\n%0*d\n %*s \n%0*d %s\n\n", colors_f[k_YELLOW] ,w.ws_col,0, (int)(w.ws_col+strlen(reader))/2, reader,w.ws_col,0, DEFAULT_K );


    is_parallel_nb = 0; /* no longer parallel here */
    struct func_mock_info_struct *tmock = f_mock_glist; //, *tfree;

    /* global order of fmock , order of expect and will */
    while(tmock){
      PRINT_DEBUG("check mock function: %s\n",tmock->str_namefunc);
      //tfree=tmock;
 PRINT_DEBUG("**** STAT mock function:%s, conditions:%s t_left:%ld, init_left:%ld, failed_call:%ld\n",tmock->str_namefunc, tmock->str_conditions, tmock->times_left,tmock->init_times_left, tmock->failed_call);
      if(((tmock->expect_call) && (tmock->init_times_left == tmock->times_left)) || (tmock->failed_call)){
        if(tmock->l_current_var){
          PRINTF("%s%s %s%s %s: expect %s, it was called %ld times and failed %ld times, with condition %s\n",colors_f[k_RED],tab_hk_f[hk_FL],colors_f[k_YELLOW],tmock->str_namefunc,DEFAULT_K, 
            number_call_translate(tmock->init_times_left),
            tmock->call/*tmock->failed_call + (tmock->init_times_left - tmock->times_left)*/, 
            tmock->failed_call,
            tmock->str_conditions
            );
          PRINT_VAR_CUR(tmock);
        }
        else 
          PRINTF("%s%s %s%s %s: expect %s, it was called %ld times and failed %ld times, with condition %s \n",colors_f[k_RED],tab_hk_f[hk_FL],colors_f[k_YELLOW],tmock->str_namefunc,DEFAULT_K, 
            number_call_translate(tmock->init_times_left),
            tmock->call/*tmock->failed_call + (tmock->init_times_left - tmock->times_left)*/, 
            tmock->failed_call, 
            tmock->str_conditions
            );
      }
      tmock=tmock->next;
      //free(tfree);
    }
    
    PRINTF("\n%s%s STAT MOCK : there  are %ld mock functions, %ld wished responses, %ld expected responses, which are:\n\n",colors_f[k_GREEN],tab_hk_f[hk_EQ],count_f_mock, count_f_mock_wished, count_expect_mock);
    struct list_base_fmock *tmp_list_fm = g_list_base_fmock;
    struct func_mock_info_struct *tmp_inf_mock;
    /* list each fmock an each calls */
    while(tmp_list_fm){
      tmp_inf_mock = tmp_list_fm->info_mock;
      memset(reader,'=',w.ws_col);
      reader[w.ws_col-1]='\0';
      char *caller="";
      if(tmp_inf_mock->str_caller){ 
        caller = extract_func_edited_TEST_from_exec_func_name(tmp_inf_mock->str_caller);
      }
      size_t len_caller = strlen(caller);

      char *nameff=extract_name_func_mock(tmp_inf_mock->str_namefunc);
      size_t len_nameff=strlen(nameff);
      char *by_=" called by ";
      size_t len_by_=strlen(by_);
      size_t bg_rd=(w.ws_col -1 - len_nameff - len_caller - len_by_)/2;
      reader[bg_rd++]=' ';
      for(size_t i=0; i<len_nameff; ++i) 
        reader[bg_rd+i]=nameff[i];
      if(len_caller){
        for(size_t i=0;i<len_by_;++i)
          reader[bg_rd+len_nameff+i]=by_[i];
        for(size_t i=0;i<len_caller;++i)
          reader[bg_rd+len_nameff+len_by_+i]=caller[i];
        reader[bg_rd+len_nameff+len_by_+len_caller]=' ';
      }
      else{
        reader[bg_rd+len_nameff]=' ';
      }
      PRINTF("%s%s%s\n\n",colors_f[k_BLUE],reader,DEFAULT_K );
      while(tmp_inf_mock){
        if(0==strncmp(tmp_inf_mock->str_namefunc,nameff, len_nameff)){
          if(tmp_inf_mock->expect_call==1){
            int success = !((tmp_inf_mock->init_times_left == tmp_inf_mock->times_left) || (tmp_inf_mock->failed_call));
            
            if(tmp_inf_mock->l_current_var){
              PRINTF("%s%s%s %s\t expect to%s,\t called %ld times and failed %ld times %s,\t with condition: %s%s\n" , 
                colors_f[!unicolour*(k_RED - success)],tab_hk_f[hk_FL-success],colors_f[k_NOTHING * success],tmp_inf_mock->str_namefunc, number_call_translate(tmp_inf_mock->init_times_left), tmp_inf_mock->call, 
                tmp_inf_mock->failed_call, strprint_caller_(tmp_inf_mock->str_caller), tmp_inf_mock->str_conditions, DEFAULT_K);
              PRINT_VAR_CUR(tmp_inf_mock);
            }else{
              PRINTF("%s%s%s %s\t expect to%s,\t called %ld times and failed %ld times %s,\t with condition: %s%s\n" , 
                colors_f[!unicolour*(k_RED - success)],tab_hk_f[hk_FL-success],colors_f[k_NOTHING*success],tmp_inf_mock->str_namefunc, number_call_translate(tmp_inf_mock->init_times_left), tmp_inf_mock->call, 
                tmp_inf_mock->failed_call, strprint_caller_(tmp_inf_mock->str_caller), tmp_inf_mock->str_conditions , DEFAULT_K);
            }
          }else if(tmp_inf_mock->expect_call==0) {/* will expect */
            int success = !(tmp_inf_mock->failed_call);
            if(tmp_inf_mock->l_current_var){
              PRINTF("%s%s%s %s\t      will%s,\t called %ld times and failed %ld times %s,\t with condition: %s,%s\n" , 
                colors_f[!unicolour*(k_RED + success)],tab_hk_f[hk_FL-success],colors_f[k_NOTHING*success],tmp_inf_mock->str_namefunc, number_call_translate(tmp_inf_mock->init_times_left), tmp_inf_mock->call, 
                tmp_inf_mock->failed_call, strprint_caller_(tmp_inf_mock->str_caller), tmp_inf_mock->str_conditions , DEFAULT_K);
              PRINT_VAR_CUR(tmp_inf_mock);
            }else{
              PRINTF("%s%s%s %s\t      will%s,\t called %ld times and failed %ld times %s,\t with condition: %s %s\n" , 
                colors_f[!unicolour*(k_RED + success)],tab_hk_f[hk_FL-success],colors_f[k_NOTHING*success],tmp_inf_mock->str_namefunc, number_call_translate(tmp_inf_mock->init_times_left), tmp_inf_mock->call, 
                tmp_inf_mock->failed_call, strprint_caller_(tmp_inf_mock->str_caller), tmp_inf_mock->str_conditions , DEFAULT_K);
            }
          }
          else if(tmp_inf_mock->expect_call==-1){
             if(tmp_inf_mock->l_current_var){
              PRINTF("%s%s%s %s\t  %s,\t called %ld times, %s\n" ,
                colors_f[!unicolour*(k_RED)],tab_hk_f[hk_FL],colors_f[k_DEFAULT],tmp_inf_mock->str_namefunc, 
                number_call_translate(tmp_inf_mock->init_times_left), tmp_inf_mock->call,
                strprint_caller_(tmp_inf_mock->str_caller) );
              PRINT_VAR_CUR(tmp_inf_mock);
            }else{
              PRINTF("%s%s%s %s\t  %s,\t called %ld times, %s\n" ,
                colors_f[!unicolour*(k_RED)],tab_hk_f[hk_FL],colors_f[k_DEFAULT],tmp_inf_mock->str_namefunc, 
                number_call_translate(tmp_inf_mock->init_times_left), tmp_inf_mock->call,
                strprint_caller_(tmp_inf_mock->str_caller));
            }

          }
        }
        tmp_inf_mock = tmp_inf_mock->next;
      }
      PRINT_DEBUG(" end listing info mock of %s \n", nameff);
      tmp_list_fm = tmp_list_fm->next;
    }
    
    PRINT_DEBUG("%s\n","info mock done!");
    
    pthread_mutex_destroy(&mut_g_list_base_fmock);
    pthread_mutex_destroy(&mut_f_mock_glist);
    pthread_mutex_destroy(&mut_count_f_mock_wished);
    pthread_mutex_destroy(&mut_count_f_mock);
    pthread_mutex_destroy(&mut_count_expect_mock);
    PRINT_DEBUG("%s\n","pthread_mutex_destroy done!");
    PRINT_DEBUG("%s\n","check mock done!");
  }


void clear_fmock_info_list(struct func_mock_info_struct **f_mock_list){
  if(*f_mock_list){
    struct func_mock_info_struct *tmp_fmock_info = *f_mock_list, *ttmp_fmock_info;
    while(tmp_fmock_info){ 
      ttmp_fmock_info = tmp_fmock_info;
      tmp_fmock_info = tmp_fmock_info->next;
      free(ttmp_fmock_info->str_namefunc);
      free(ttmp_fmock_info->str_conditions);
      free(ttmp_fmock_info->str_caller);
      clear_variable_current(&(ttmp_fmock_info->l_current_var));
      free(ttmp_fmock_info);
    }
    *f_mock_list = NULL;
  }

}

void clear_list_base_fmock(struct list_base_fmock **l_fmock){
  if(*l_fmock){
    struct list_base_fmock *tmp_l_n = *l_fmock, *ttmp_l_n;
    while(tmp_l_n){ 
      ttmp_l_n = tmp_l_n;
      tmp_l_n = tmp_l_n->next;
      //clear_fmock_info_list(&((ttmp_l_n->next)->info_mock));
      free(ttmp_l_n);
    }
    *l_fmock=NULL;
  }

}

void clear_variable_current(struct list_current_variable **lcurrent_var){
  if(*lcurrent_var){
    struct list_current_variable *tmp_lcv = *lcurrent_var, *ttmp_lcv;
    while(tmp_lcv){ 
      ttmp_lcv = tmp_lcv;
      tmp_lcv = tmp_lcv->next;
      
      free(ttmp_lcv->str_current_variables);
      free(ttmp_lcv);
    }
    *lcurrent_var=NULL;
  }

}

__attribute__((constructor))
  void purge_fmock(){

    clear_fmock_info_list(&f_mock_glist);
    PRINT_DEBUG("purge f_mock_glist %s\n","done");
    //clear_list_base_fmock(&g_list_base_fmock);
    //PRINT_DEBUG("purge g_list_base_fmock %s\n","done");
  }
