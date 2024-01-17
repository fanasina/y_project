#include "ftest/ftest.h"
//#include <dirent.h>

/*
 * by default display in millisecond
 */
/*

*/

#define NANOSECOND  (timeunit[0]=='n')
#define SECOND  (timeunit[0]=='s')

  #define LOCK(mutex_var)  pthread_mutex_lock(&mutex_var);
  #define UNLOCK(mutex_var) pthread_mutex_unlock(&mutex_var);

#define INCREMENT(variable)\
  do{\
    if(is_parallel_nb){\
      LOCK(mut_##variable); \
      ++variable;\
      UNLOCK(mut_##variable);\
    }\
    else ++variable;\
  }while(0);



/*
 * struct to store tests failed
 */ 

struct failed_lists{
  char *name;
  struct failed_lists *next;
};

#define default_ordered 0
#define default_unicolour 0
#define default_removelog  0
//#define default_parallel_nb 1
#define default_parallel_nb_opt 1
#define default_verb NORMAL


/*
 * global variables 
 * if not exported, it only exists in ftest.c
 */
/*
 * begin variable option
 */
long int verb=NORMAL;

bool some_thing_wrong = 0;

bool help=0;
bool only_usage=0;
bool ordered= 0;
bool gtestlike=0;
bool debug=0;
bool unicolour = 0;
bool removelog = 0;
char *timeunit="ms";
char *savelog=NULL;
char *default_timeunit="ms";
char *default_savelog="log_all_tests";
char *default_bar_progress="  c";

//size_t width = 80;

char *colors_f[]={DEFAULT_K, GREEN_K, RED_K, YELLOW_K, BLUE_K, ""};
int k_DEFAULT=0, k_GREEN=1, k_RED=2, k_YELLOW=3, k_BLUE=4, k_NOTHING=Dknothing;

char *tab_hk_f[]={ HK_EQ, HK_TR, HK_RN, HK_DN, HK_OK, HK_FL, HK_PS, HK_SK };
char *g_tab_hk_f[]={ gHK_EQ, gHK_TR, gHK_RN, gHK_DN, gHK_OK, gHK_FL, gHK_PS, gHK_SK };
int hk_EQ=0, hk_TR=1, hk_RN=2, hk_DN=3, hk_OK=4, hk_FL=5, hk_PS=6, hk_SK=7 ;

//char *varHK_EQ=HK_EQ, *varHK_TR=HK_TR, *varHK_RN=HK_RN, *varHK_DN=HK_DN, *varHK_OK=HK_OK, *varHK_FL=HK_FL, *varHK_PS=HK_PS, *varHK_SK=HK_SK;

bool some_tests_selected=0; 

size_t *array_TYPE_SIZE_T=NULL; /* if active, size = count_tests */
char **array_TYPE_STRING=NULL;

size_t cur_array_TYPE_SIZE_T=0; /* < count_tests */
size_t cur_array_TYPE_STRING=0;

/*
 * number of threads
 */ 
size_t parallel_nb = 0;
size_t parallel_nb_opt = 0; /* to solve debug option */

/*
 * end variable option
 */ 

bool is_parallel_nb = 0;
bool is_parallel_nb_opt = 0;
bool is_verb = 0;
bool log_parallel = true;
bool progress = true; // false;

char *bar_progress = "  c"; /*{fill_bar,fill_dot,colored} */
bool is_bar_progress = true;

FILE **f_ou_th;

size_t count_tests = 0;

size_t count_pass_global = 0;
size_t count_pass_local = 0;


size_t count_fail_global = 0;
size_t count_fail_local = 0;

/*
 * count in local test
 * using array [count_test] global variable
 */
size_t *count_pass_test = NULL;
size_t *count_fail_test = NULL;
 
/*
 * count on each thread [PARALLEL]
 */
size_t *count_pass_thread = NULL;
size_t *count_fail_thread = NULL;

size_t *id_thread_self = NULL;
char **log_name_file_thrd = NULL;
/*
 * the first instance of the func struct, 
 * it containis the first test
 */

struct func *f_beging = NULL; 
/*
 * current test : used by parallel tests
 */ 
struct func *current_fn = NULL; 

/*
 * list of all failed tests
 */ 
struct failed_lists *failed_l = NULL;


/*
 * list of failed test on each thread
 */
struct failed_lists **thread_test_failed_l = NULL;

/*
 * mutex to add global failed test
 */ 
pthread_mutex_t mut_global_list_fail;
/*
 * mutex to have current test to do
 */ 
pthread_mutex_t mut_current_test;


pthread_mutex_t mut_count_pass_global;
pthread_mutex_t mut_count_fail_global;
pthread_mutex_t mut_count_pass_local;
pthread_mutex_t mut_count_fail_local;

/*
 * end of the global variables of test_t.c
 */


/*
 * 
 */ 

void append_failed_list(struct failed_lists **fn_failed_list ,const char *name_failed){

  if(*fn_failed_list){
    
    struct failed_lists *tmp_failed_l = *fn_failed_list, *rec_tmp;
    
    while(tmp_failed_l){
      rec_tmp = tmp_failed_l;
      tmp_failed_l = tmp_failed_l->next; 
    }
    tmp_failed_l = malloc(sizeof(struct failed_lists));
    tmp_failed_l->name = malloc(strlen(name_failed));
    strcpy(tmp_failed_l->name, name_failed);
    tmp_failed_l->next = NULL;
    rec_tmp->next = tmp_failed_l;
  
  }
  else{
    *fn_failed_list = malloc(sizeof(struct failed_lists));
    (*fn_failed_list)->name = malloc(strlen(name_failed));
    strcpy((*fn_failed_list)->name, name_failed);
    (*fn_failed_list)->next = NULL;
  }

}

/*
 * match the id global (gives by OS) of the thread with the local (the program) id of thread
 */ 
long int id_of_thread_executed(void){
  size_t id_from_self = pthread_self();
  for(long int i=0; i<= parallel_nb; ++i){
    if(id_thread_self[i] == id_from_self)
      return i;
  }
  PRINT_ERROR("something wrong on %s, id_from_self: %ld\n",__func__,id_from_self);
  return -1;
}


/*
 * format name of TEST(name_f) is: 'TEST_name_f____NUM|', 
 * and name attribute is 'TEST(name_f): test N° NUM!' (! at the end is random): 
 * we extract NUM here
 * to have hash_table of the count when parallel test!
 */
size_t extract_num__f(const char *name_f){
  size_t len = strlen(name_f);
  size_t val = 0, p = 1;
  for(long i= len-1; i>=0; --i){
    PRINT_DEBUG(" name_f(%s)[%ld] = %c\n",name_f,i,name_f[i]);
    if(name_f[i]=='|') val = 0;
    if(name_f[i] >= '0' && name_f[i] <= '9'){
      val += p * (name_f[i]-'0');
      p *= 10;
    }
    else if( name_f[i] == ' ' ||  name_f[i] == '_' || name_f[i] == '=' ) break;
  }
  return val;
}
 /* TEST_funcname___NUM -> TEST(funcname) */
char* extract_func_edited_TEST_from_exec_func_name(char* func_name){
  size_t len=strlen(func_name);
  char *ret_name=malloc(len);
  strcpy(ret_name, func_name);
  char *pad="____";
  size_t len_pad=strlen(pad); 
  ret_name[4]='(';
  for(size_t i=5;i<len-len_pad; ++i){
    if(0==strncmp(func_name+i, pad,len_pad)){
      ret_name[i]=')';
      ret_name[i+1]='\0';
    }
  }
  return ret_name;
}

// ========================== =================================
void setup_variables_before_exec(){
  if(unicolour){
    k_DEFAULT=k_NOTHING;
    k_GREEN=k_NOTHING; 
    k_RED=k_NOTHING; 
    k_YELLOW=k_NOTHING; 
    k_BLUE=k_NOTHING;

    size_t len_bp = strlen(bar_progress);
    size_t len_db = strlen(default_bar_progress);
    if( len_bp >= len_db ){
      char *tmp_bp=malloc(len_bp);
      strcpy(tmp_bp,bar_progress);  
      tmp_bp[2]='u';
      bar_progress=tmp_bp;
    }
    else{
      char *tmp_bp=malloc(len_bp);
      strcpy(tmp_bp,default_bar_progress);  
      tmp_bp[2]='u';
      default_bar_progress=tmp_bp;
    }
  }

  if(gtestlike){
    for(int i=0; i<=hk_SK; ++i)
      tab_hk_f[i]=g_tab_hk_f[i]; 
  }

  parallel_nb = parallel_nb_opt;
  is_parallel_nb = is_parallel_nb_opt;
  
  /*if(savelog){
    f_savelog=fopen(savelog, "w+");
  }*/ 
}


// ===================================== begin options handle =======================================================

void usage(int argc, char **argv){
  printf("usage: %s [OPTIONS] [<ARGS>] \n\n"
         "  or : %s [OPTIONS]=[<ARGS>]\n\n",argv[0],argv[0]);
  printf("OPTIONS\n");
  printf( "\t -h, --help \n"
            "\t\tprint help, options variables\n\n");
  printf( "\t -g, --gtestlike \n"
            "\t\tto have gtest hook like!\n\n");
  printf( "\t -p <NB>, --parallel <NB>, -p=<NB>, --parallel=<NB>\n"
            "\t\tby default the program ran in sequantial all test, \n"
            "\t\tif this option is set, the program run tests on NB threads.\n"
            "\t\tEach thread pull up one test out the list of all test not yet executed,\n"
            "\t\tand execute it, until the list is empty \n\n");
  printf( "\t -t <unit>, --time <unit>, -t=<unit>, --time=<unit>  \n"
            "\t\tby default unit is millisecons ms, the other of unit are choices are second (or s), and nanosecond (or ns)\n"
            "\t\tex: -t ns or -t=nanosecond or --time=n to set nanosecond unit\n\n");
  printf( "\t -u , --unicolour\n"
            "\t\tby default, the result is colored, if you choice this option, it prints with default color\n\n");
  printf( "\t -r , --remove\n"
            "\t\tif the option parallel is choosen the result on each thread is record in separate files,\n"
            "\t\tthis option remove the file logs of each thread after all tests.\n\n");
  printf( "\t -s <file>, --savelog <file>, -s=file, --savelog=file\n"
            "\t\tthis option save the global ordered result in 'file',\n"
            "\t\t  \n\n");

  printf( "\t -n=<NUM1>,<NUM2> <NUM3>... ,--numtests=<NUM1>,<NUM2>...\n"
            "\t\tthis option allow to execute only the selected numbers of tests (in the order in file test)\n"
            "\t\tex: -n=0,6,3 8 to execute   the tests 0,3,6,8 (if the number is less than the count of all tests)\n\n"); 
  printf( "\t -l=<NAME1>,<NAME2> <NAME3>... ,--listests=<NAME1>,<NAME2>...<NAMEn>\n"
            "\t\tthis option allow to execute only the selected name of tests. It allows empty name by using '-l=,'\n"
            "\t\tex:  -l=name0,,name2 : execute only (if they exist): TEST(name0),TEST(),TEST(name2)\n\n"); 
  printf( "\t -b <BPRGSS>, --bar_progress <BPRGSS>, -b=BPRGSS, --bar_progress=BPRGSS. Example: -b=\"#_c\"\n"
            "\t\tthis option change progression bar if it is active. The first character (\'#\') fills the bar\n"
            "\t\tthe second char (\'_\') fills the other part of bar. the bar is colored if the 3rd char is \'c\' and not if different.\n"
            "\t\tby default the progress bar is active and the option is -b=\"  c\", if need not colored, we can put -b=\"  n\" option.\n\n");
  printf( "\t -z=<option> \n"
            "\t\tthis option is to set option=0,\n"
            "\t\tfor example, -z=progress is to not load progress bar, it is need if we want to redirect (pipe) the result to file.\n"
            "\t\tother option: -z=log_parallel (to avoid logs not ordered when parallel tests which is loged by default)\n\n");
  printf( "\t -d, --debug \n"
            "\t\tto print debug by using PRINT_DEBUG, by default PRINT_DEBUG is not print unless -d is set\n"
            /*"\t\t-d need to be set at the end of all options if -p is use, to avoid sigfault because the parallel env is not yet set for debug print parallel\n\n"*/
            );
  printf( "\t -v, --verb = integer or macro: NORMAL or VERB or NOVERB  \n"
            "\t\tto chage test result printing: NORMAL=0, VERB=1, NOVERB=2 or integers not equal to 0 or 1 \n"
            );


  if(array_TYPE_SIZE_T){
    for(int i=0; i< cur_array_TYPE_SIZE_T; ++i){
      PRINT_DEBUG("array_TYPE_SIZE_T[%d]=%ld\n",i,array_TYPE_SIZE_T[i]);
    }
  }
  if(array_TYPE_STRING) {
    for(int i=0; i< cur_array_TYPE_STRING; ++i){
      PRINT_DEBUG("array_TYPE_STRING[%d]=%s\n",i,array_TYPE_STRING[i]);
    }
  }
  if(some_thing_wrong){
    printf("invalid argument\n");
    exit(0);
  }
  if(only_usage) exit(0);

}


const char* extract_string_after_equal_symbole_in_string(const char * in_str){
  size_t len=strlen(in_str);
    
  for(long i=0; i<len-1; ++i){
    if(in_str[i]=='=') 
      return in_str+i+1;
  }
  return NULL; // check for '\0' or ' ' return !
}



#define COMPARE_STR_TO_DEFS(defined,in_str)\
  /*LOG(" ===================== ======== %s vs %s =========== \n",in_str,#defined);*/\
  if(strcmp(in_str, #defined)==0){\
    return defined;\
  }

long int extract_num_after_equal_symbole_in_string(char * in_str){
 
  size_t len=strlen(in_str);
  long int val=0, p=1;
  int added=0;
  for(long i=len-1; i>=0; --i){
    PRINT_DEBUG("(%s)[%ld]=%c\n",in_str,i,in_str[i]);
    if(in_str[i]=='=') {
      if(added) return val;

      COMPARE_STR_TO_DEFS(NORMAL,in_str+i+1);
      COMPARE_STR_TO_DEFS(VERB,in_str+i+1);
      COMPARE_STR_TO_DEFS(NOVERB,in_str+i+1);

      return -1;

    }
    if(in_str[i] >= '0' && in_str[i] <= '9' ){
      val += p * (in_str[i]-'0');
      p *= 10;
      added=1;
    }
  }
  if(added) return val;
  return -1;
} 

#define LOG_WRONG(option,arg,msg)\
  some_thing_wrong=1;\
  help=1;\
  printf("incorrect %s option is interpreted as -%c, %s  \n\n",arg,#option[0],msg);\
  break;

#define IF_OPTION_WITH_ARG_NUM(option)\
  if(argv[i][0]=='-'){\
    j=1;\
    while(argv[i][j]=='-') ++j;\
    if(argv[i][j] == #option[0]){\
      arg=argv[i];\
      long ret_num=extract_num_after_equal_symbole_in_string(argv[i]);\
    PRINT_DEBUG("option=%s, ret_num = %ld, argv[%d]=%s\n",#option,ret_num,i,argv[i]);\
      is_##option = 1;\
      if(ret_num > -1)\
        option = ret_num;\
      else{\
        if(i<argc-1){\
          if(argv[i+1][0]=='-'){\
            option = default_##option;\
            LOG_WRONG(option,arg, "wait for args")\
          }\
          else{\
            ret_num=extract_num_after_equal_symbole_in_string(argv[++i]);\
            if(ret_num>0)\
              option = ret_num;\
            else{ \
              option = default_##option;\
              LOG_WRONG(option,arg, "wait for args")\
            }\
          }\
        }\
        else{\
          option = default_##option;\
          LOG_WRONG(option,arg, "wait for args")\
        }\
      }\
    PRINT_DEBUG("option %s activated, its value is %ld\n",#option,option);\
      continue;\
    }\
  }\

#define IF_OPTION_WITH_ARG_STR(option)\
  if(argv[i][0]=='-'){\
    j=1;\
    while(argv[i][j]=='-') ++j;/* to accept multiple -- */\
    if(argv[i][j] == #option[0]){\
      arg=argv[i];\
      char* ret_str=(char*)extract_string_after_equal_symbole_in_string(argv[i]);\
    PRINT_DEBUG("option=%s, ret_str = %s, argv[%d]=%s\n",#option,ret_str,i,argv[i]);\
      if(ret_str ==NULL || strlen(ret_str)==0){\
        if(i<argc-1){\
          if(argv[i+1][0]=='-')\
            help=1;\
          else\
            option = argv[++i];\
        }\
        else{\
          help=1;\
        }\
      }\
      else option = ret_str;\
      continue;\
    }\
  }\



/*
 * if the variable option is boolean
 */

#define IF_OPTION_NO_ARG(option)\
  if(argv[i][0]=='-'){\
    j=1;\
    while(argv[i][j]=='-') ++j;\
    if(argv[i][j] == #option[0]){\
      option=1;\
      if(0==strcmp(#option,"help")){ only_usage=1;break;}\
      continue;\
    }\
  }\


#define IF_OPTION_TO_ZERO(option)\
  if(argv[i][0]=='-'){\
    j=1;\
    while(argv[i][j]=='-') ++j;/* to accept multiple -- */\
    if(argv[i][j] == 'z' ){\
      arg=argv[i];\
      char* ret_str=(char*)extract_string_after_equal_symbole_in_string(argv[i]);\
    PRINT_DEBUG("to zero option={%s}, ret_str = {%s}, argv[%d]={%s}\n",#option,ret_str,i,argv[i]);\
      if(ret_str == NULL || strlen(ret_str)==0){\
        if(i<argc-1){\
          if(argv[i+1][0]=='-')\
            help=1;\
          else if(0==strcmp(#option, argv[i+1])){ \
              option=0;\
              ++i;\
              continue;\
          }\
        }\
        else{\
          help=1;\
        }\
      }\
      else if(0==strcmp(#option,ret_str)){ \
        option = 0;\
        continue;\
      }\
    }\
  }\
      

void extract_to_array_TYPE_SIZE_T(char * in_str){
  size_t len=strlen(in_str);
  long int val=0, p=10;
  int added=0;/* if the number is 0, without this var , the precedent algo did not work */
  for(long i=0; i<len; ++i){
    PRINT_DEBUG("(%s)[%ld]=%c\n",in_str,i,in_str[i]);
    if(in_str[i]=='-'){/*we don't need the option name */
      while((in_str[i] >= '0' && in_str[i] <= '9' ) || (in_str[i] >= 'A' && in_str[i] <= 'z' ) || (in_str[i]=='_')|| (in_str[i]=='-')){
        ++i;
      }
    }
    else if(in_str[i] >= '0' && in_str[i] <= '9' ){
      val = (p * val) + (in_str[i]-'0');
      added=1;
    }
    else{
      /* rec val in array */
      PRINT_DEBUG("val=(%ld) \n",val);
      array_TYPE_SIZE_T[cur_array_TYPE_SIZE_T++]=val;
      val=0;  
      added=0;
    }
  }
      PRINT_DEBUG("end val=(%ld) \n",val);
  if(added)
      array_TYPE_SIZE_T[cur_array_TYPE_SIZE_T++]=val;
 
}

void extract_to_array_TYPE_STRING(char * in_str){
  size_t len=strlen(in_str);
  char *val=malloc(len);
  size_t cur_val=0;
  for(long i=0; i<len; ++i){
    if(in_str[i]=='-'){/*we don't need the option name */
      while((in_str[i] >= '0' && in_str[i] <= '9' ) || (in_str[i] >= 'A' && in_str[i] <= 'z' ) || (in_str[i]=='_')|| (in_str[i]=='-')){
        ++i;
      }
    }
    else if((in_str[i] >= '0' && in_str[i] <= '9' ) || (in_str[i] >= 'A' && in_str[i] <= 'z' ) || (in_str[i]=='_')){
      val[cur_val++] = in_str[i];
    }
    else{
      /* rec val in array */
      val[cur_val++]='\0';

      PRINT_DEBUG("val_str=(((%s) cur_val=[%ld]\n",val,cur_val);
      array_TYPE_STRING[cur_array_TYPE_STRING]=malloc(strlen(val));
      strcpy(array_TYPE_STRING[cur_array_TYPE_STRING++],val);
      cur_val=0;
    }
  }
  if(cur_val){
      val[cur_val++]='\0';
      PRINT_DEBUG("val_str=(%s) cur_val=[%ld]\n",val,cur_val);
   
      array_TYPE_STRING[cur_array_TYPE_STRING]=malloc(strlen(val));
      strcpy(array_TYPE_STRING[cur_array_TYPE_STRING++],val);

  }
}



#define IF_OPTION_WITH_MULTIPLE_ARG(option,type)\
  if(argv[i][0]=='-'){\
    j=1;\
    while(argv[i][j]=='-') ++j;\
    if(argv[i][j] == #option[0]){\
      arg=argv[i];\
      array_##type=malloc(sizeof(type)*count_tests);\
      some_tests_selected= 1;\
      do{\
        extract_to_array_##type(argv[i]);\
        PRINT_DEBUG("option=%s, cur = %ld, argv[%d]=%s\n",#option,cur_array_##type,i,argv[i]);\
      }while(i<argc-1 && argv[++i][0] != '-');\
      PRINT_DEBUG("after while option=%s, cur = %ld, argv[%d]=%s\n",#option,cur_array_##type,i,argv[i]);\
      if(argv[i][0]=='-'){/* handle to allow next option */\
        j=1;while(argv[i][j]=='-') ++j;\
        if (argv[i][j] != #option[0]) --i;\
      }\
      PRINT_DEBUG("after if arc-1 option=%s, cur = %ld, i=%d, et argv[i+1]=%s\n",#option,cur_array_##type,i,argv[i+1]);\
      continue;\
    }\
  }\


/*
 * if no continue call, it means no match option!
 */

#define IF_NO_MATCH_DO_WRONG \
  printf("option %s inconnu\n",argv[i]);\
  help=1; some_thing_wrong=1;  break;


void parse_options(int argc, char **argv){
  int j;
  char *arg;
  for(int i=1; i<argc; ++i){
    PRINT_DEBUG("argc=%d, argv[%d]=%s\n",argc,i,argv[i]);
    IF_OPTION_NO_ARG(help)
    IF_OPTION_NO_ARG(debug)
    IF_OPTION_NO_ARG(gtestlike)
    //IF_OPTION_WITH_ARG_NUM(parallel_nb)
    IF_OPTION_WITH_ARG_NUM(parallel_nb_opt)
    IF_OPTION_WITH_ARG_NUM(verb)
    IF_OPTION_WITH_ARG_STR(savelog)
    IF_OPTION_WITH_ARG_STR(timeunit)
    IF_OPTION_WITH_ARG_STR(bar_progress)
    IF_OPTION_NO_ARG(ordered)
    IF_OPTION_NO_ARG(removelog)    
    IF_OPTION_NO_ARG(unicolour)
    IF_OPTION_TO_ZERO(progress)
    IF_OPTION_TO_ZERO(log_parallel)
    IF_OPTION_WITH_MULTIPLE_ARG(numsuit,TYPE_SIZE_T)
    IF_OPTION_WITH_MULTIPLE_ARG(listsuite,TYPE_STRING) 
    IF_NO_MATCH_DO_WRONG
  }

  setup_variables_before_exec();
}

// ==================================================== end handle  option ================================

/*
 * print all TESTs failed
 */ 

#define LISTE_ALL_FAILED_TEST_IN_F_OUT\
  while(failed_lst){\
      PRINT_HK_C(colors_f[k_RED], tab_hk_f[hk_FL]," %s\n",failed_lst->name);\
      failed_lst = failed_lst->next;\
    }


void list_failed_test(struct failed_lists *test_failed){
  struct failed_lists *failed_lst = test_failed;
  if(is_parallel_nb){
    long int  id_thrd = id_of_thread_executed();
    if(id_thrd < 0 || id_thrd == parallel_nb ){
      LISTE_ALL_FAILED_TEST_IN_F_OUT
    }else{
      while(failed_lst){
        PRINT_HK_C(colors_f[k_RED], tab_hk_f[hk_FL]," %s, on thread[%ld]\n",failed_lst->name,id_thrd);
        failed_lst = failed_lst->next;
      }
    }
  }
  else{
    LISTE_ALL_FAILED_TEST_IN_F_OUT
  }
  PRINT_HK_C(colors_f[k_DEFAULT], tab_hk_f[hk_EQ],"%s\n","");
}





#define INCREMENT_EXPECT(expect,name)\
  do{\
    size_t num_test=extract_num__f(name);\
    ++count_## expect ##_test[num_test];\
    PRINT_DEBUG("INCREMENT cout_%s_test[%ld] = %ld\n",#expect, num_test,count_## expect ##_test[num_test]); \
  }while(0);


#define EXPECTED_EXPECT_F(expect/*, not_expect*/)                                          \
  \
bool expected_##expect##_f(bool val){                                                     \
  if(val == expect) {                                                                     \
    INCREMENT(count_pass_local); /*++count_pass_local*/                                                                 \
    return true;                                                                          \
  }else {                                                                                 \
    INCREMENT(count_fail_local); /*++count_fail_local*/                                                                 \
    return false;                                                                         \
  }                                                                                       \
}  \
bool expected_##expect##_f_name(bool val, const char * name){                                                     \
  if(val == expect) {                                                                     \
    INCREMENT_EXPECT(pass,name);\
    return true;                                                                          \
  }else {                                                                                 \
    INCREMENT_EXPECT(fail,name);\
    return false;                                                                         \
  }                                                                                       \
}  \


EXPECTED_EXPECT_F(true)
EXPECTED_EXPECT_F(false)

#define EXPECTED_OP_TYPE(OP,type)                                                            \
    \
bool expected_##OP##_##type(type var1, type var2){                                            \
  if(COMPARE_N_##type(&var1, &var2) OP 0){                                                \
    INCREMENT(count_pass_local); /*++count_pass_local*/                                                                 \
    return true;                                                                          \
  }else {                                                                                 \
    INCREMENT(count_fail_local); /*++count_fail_local*/                                                                 \
    return false;                                                                         \
  }                                                                                       \
} \
bool expected_##OP##_name_##type(type var1, type var2,const char * name){                                            \
  if(COMPARE_N_##type(&var1, &var2) OP 0){                                                \
    INCREMENT_EXPECT(pass,name);\
    return true;                                                                          \
  }else {                                                                                 \
    INCREMENT_EXPECT(fail,name);\
    return false;                                                                         \
  }                                                                                       \
}\
bool expected_array_##OP##_##type(type *var1, long int sz1, type *var2, long int sz2){                                            \
  if(sz1 OP sz2){\
    size_t count=0;\
    if(sz1 == sz2){\
      for(size_t i=0;i<sz1;++i){\
        if(COMPARE_N_##type(&var1[i], &var2[i]) OP 0)\
          ++count;\
        else{ \
          INCREMENT(count_fail_local); /*++count_fail_local*/                                                                 \
          return false;\
        }\
      }\
      if(count==sz1){                                                \
        INCREMENT(count_pass_local); /*++count_pass_local*/                                                                 \
        return true;                                                                          \
      }\
    }\
    else{\
      INCREMENT(count_pass_local); /*++count_pass_local*/                                                                 \
      return true;                                                                          \
    }\
  }\
    INCREMENT(count_fail_local); /*++count_fail_local*/                                                                 \
    return false;                                                                         \
} \
bool expected_array_##OP##_name_##type(type *var1, long int sz1, type *var2, long int sz2, const char * name){                                            \
  if(sz1 OP sz2){\
    size_t count=0;\
    if(sz1 == sz2){\
      for(size_t i=0;i<sz1;++i){\
        if(COMPARE_N_##type(&var1[i], &var2[i]) OP 0)\
          ++count;\
        else {\
          INCREMENT_EXPECT(fail,name);\
          return false;\
        }\
      }\
      if(count==sz1){                                                \
        INCREMENT_EXPECT(pass,name);\
        return true;                                                                          \
      }\
    }\
    else{\
      INCREMENT_EXPECT(pass,name);\
      return true;                                                                          \
    }\
  }\
    INCREMENT_EXPECT(fail,name);\
    return false;                                                                         \
} \


EXPECTED_OP_TYPE(EQ,TYPE_CHAR)
EXPECTED_OP_TYPE(EQ,TYPE_U_CHAR)
EXPECTED_OP_TYPE(EQ,TYPE_INT)
EXPECTED_OP_TYPE(EQ,TYPE_U_INT)
EXPECTED_OP_TYPE(EQ,TYPE_L_INT)
EXPECTED_OP_TYPE(EQ,TYPE_U_L_INT)
EXPECTED_OP_TYPE(EQ,TYPE_SIZE_T)
EXPECTED_OP_TYPE(EQ,TYPE_FLOAT)
EXPECTED_OP_TYPE(EQ,TYPE_DOUBLE)
EXPECTED_OP_TYPE(EQ,TYPE_L_DOUBLE)
EXPECTED_OP_TYPE(EQ,TYPE_STRING)

EXPECTED_OP_TYPE(LT,TYPE_CHAR)
EXPECTED_OP_TYPE(LT,TYPE_U_CHAR)
EXPECTED_OP_TYPE(LT,TYPE_INT)
EXPECTED_OP_TYPE(LT,TYPE_U_INT)
EXPECTED_OP_TYPE(LT,TYPE_L_INT)
EXPECTED_OP_TYPE(LT,TYPE_U_L_INT)
EXPECTED_OP_TYPE(LT,TYPE_SIZE_T)
EXPECTED_OP_TYPE(LT,TYPE_FLOAT)
EXPECTED_OP_TYPE(LT,TYPE_DOUBLE)
EXPECTED_OP_TYPE(LT,TYPE_L_DOUBLE)
EXPECTED_OP_TYPE(LT,TYPE_STRING)

EXPECTED_OP_TYPE(GT,TYPE_CHAR)
EXPECTED_OP_TYPE(GT,TYPE_U_CHAR)
EXPECTED_OP_TYPE(GT,TYPE_INT)
EXPECTED_OP_TYPE(GT,TYPE_U_INT)
EXPECTED_OP_TYPE(GT,TYPE_L_INT)
EXPECTED_OP_TYPE(GT,TYPE_U_L_INT)
EXPECTED_OP_TYPE(GT,TYPE_SIZE_T)
EXPECTED_OP_TYPE(GT,TYPE_FLOAT)
EXPECTED_OP_TYPE(GT,TYPE_DOUBLE)
EXPECTED_OP_TYPE(GT,TYPE_L_DOUBLE)
EXPECTED_OP_TYPE(GT,TYPE_STRING)

EXPECTED_OP_TYPE(LE,TYPE_CHAR)
EXPECTED_OP_TYPE(LE,TYPE_U_CHAR)
EXPECTED_OP_TYPE(LE,TYPE_INT)
EXPECTED_OP_TYPE(LE,TYPE_U_INT)
EXPECTED_OP_TYPE(LE,TYPE_L_INT)
EXPECTED_OP_TYPE(LE,TYPE_U_L_INT)
EXPECTED_OP_TYPE(LE,TYPE_SIZE_T)
EXPECTED_OP_TYPE(LE,TYPE_FLOAT)
EXPECTED_OP_TYPE(LE,TYPE_DOUBLE)
EXPECTED_OP_TYPE(LE,TYPE_L_DOUBLE)
EXPECTED_OP_TYPE(LE,TYPE_STRING)

EXPECTED_OP_TYPE(GE,TYPE_CHAR)
EXPECTED_OP_TYPE(GE,TYPE_U_CHAR)
EXPECTED_OP_TYPE(GE,TYPE_INT)
EXPECTED_OP_TYPE(GE,TYPE_U_INT)
EXPECTED_OP_TYPE(GE,TYPE_L_INT)
EXPECTED_OP_TYPE(GE,TYPE_U_L_INT)
EXPECTED_OP_TYPE(GE,TYPE_SIZE_T)
EXPECTED_OP_TYPE(GE,TYPE_FLOAT)
EXPECTED_OP_TYPE(GE,TYPE_DOUBLE)
EXPECTED_OP_TYPE(GE,TYPE_L_DOUBLE)
EXPECTED_OP_TYPE(GE,TYPE_STRING)

EXPECTED_OP_TYPE(NE,TYPE_CHAR)
EXPECTED_OP_TYPE(NE,TYPE_U_CHAR)
EXPECTED_OP_TYPE(NE,TYPE_INT)
EXPECTED_OP_TYPE(NE,TYPE_U_INT)
EXPECTED_OP_TYPE(NE,TYPE_L_INT)
EXPECTED_OP_TYPE(NE,TYPE_U_L_INT)
EXPECTED_OP_TYPE(NE,TYPE_SIZE_T)
EXPECTED_OP_TYPE(NE,TYPE_FLOAT)
EXPECTED_OP_TYPE(NE,TYPE_DOUBLE)
EXPECTED_OP_TYPE(NE,TYPE_L_DOUBLE)
EXPECTED_OP_TYPE(NE,TYPE_STRING)

// ====================== progress bar =================


unsigned sleep(unsigned x) { time_t t0=time(0); while (difftime(time(0),t0)<x); return 0; }
unsigned nnsleep(long long x) {
  struct timespec time_stop; 
  struct timespec time_start; 
  clock_gettime(CLOCK_REALTIME, &time_start);

  long long diff; 
  do{
    clock_gettime(CLOCK_REALTIME, &time_stop);

    diff = 1.0e9 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_nsec - time_start.tv_nsec);
  }while(diff < x);
  return 0; 
}



void bar_progress_test_(){
  bar_progress_start();
  
  struct func *tmp;
  size_t num_test=0;
  
  do{
    tmp = current_fn;
    //UNLOCK(mut_current_test);
    if(tmp)
      num_test = extract_num__f(tmp->name);
    if(strlen(bar_progress) < strlen(default_bar_progress))
      bar_progress_step_msg(num_test, count_tests, "test N°", default_bar_progress[0],default_bar_progress[1],default_bar_progress[2]=='c'); 
    else bar_progress_step_msg(num_test, count_tests, "test N°", bar_progress[0],bar_progress[1],bar_progress[2]=='c'); 
    nnsleep(200000000);// 200 milliseconds
  }while(tmp);



  bar_progress_stop();

}

void*
run_progress_tests(void *max_d)
{
   /*int max_col = 80;*/ //*(int*)max_d;
   //progress_test_(max_col);
   bar_progress_test_();
   return (void*)0;
}





// ====================== end funcs progress bar ======= 

void 
append_func(void (*run)(void), char *name){
  static struct func *f_static = NULL;
  if(f_beging == NULL){
    f_beging = malloc(sizeof(struct func));
    f_static = f_beging;
    f_static->name = malloc(strlen(name));
    strcpy(f_static->name,name);
    f_static->run = run;
    f_static->next = NULL;
  }
  else{
    struct func *tmp = malloc(sizeof(struct func));
    tmp->run = run;
    tmp->name = malloc(strlen(name));
    strcpy(tmp->name,name);
    tmp->next = NULL;
    f_static->next = tmp;
    f_static = tmp;
  }
  ++count_tests;
}

void begin_execute_func(char *fun_ame, struct timespec *start_t){
  clock_gettime(CLOCK_REALTIME, start_t);
  PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_RN]," %s\n", fun_ame); 
  count_pass_local = 0;
  count_fail_local = 0;
}

#define PRINT_TIMESTAMP_STAT(color)\
    if(SECOND) PRINT_HK_C(color,tab_hk_f[hk_DN]," %lu tests passed from %s (%lf s)\n\n",count_pass_local,fun_ame, diff_timespec_seconds(end_t, start_t));\
    else if(NANOSECOND) PRINT_HK_C(color,tab_hk_f[hk_DN]," %lu tests passed from %s (%ld ns)\n\n",count_pass_local,fun_ame, diff_timespec_nanoseconds(end_t, start_t));\
    else PRINT_HK_C(color,tab_hk_f[hk_DN]," %lu tests passed from %s (%lf ms)\n\n",count_pass_local,fun_ame, diff_timespec_milliseconds(end_t, start_t));

void end_execute_func(char *fun_ame, struct timespec start_t){
  struct timespec end_t; clock_gettime(CLOCK_REALTIME, &end_t);
  if(count_fail_local){
    INCREMENT(count_fail_global); /*++count_fail_global*/
    append_failed_list(&failed_l, fun_ame); 
    PRINT_HK_C(colors_f[k_RED], tab_hk_f[hk_FL], " %lu tests failed from %s\n",count_fail_local,fun_ame);
    PRINT_TIMESTAMP_STAT(colors_f[k_RED]);
  }
  else 
  {
    INCREMENT(count_pass_global); /*++count_pass_global*/
    PRINT_TIMESTAMP_STAT(colors_f[k_GREEN]);
  }
}
/*
 * print on the top of test
 */ 
void head_run(size_t nbtest, struct timespec *start_t){
  clock_gettime(CLOCK_REALTIME, start_t);
  if(cur_array_TYPE_SIZE_T || cur_array_TYPE_STRING) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ],"%s"," Running tests.\n");
  else PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," Running %lu tests.\n",nbtest);
}

/*
 * printing on the end of test
 */ 
void
stat_end_run(size_t ntst, struct timespec start_t){
  struct timespec end_t; clock_gettime(CLOCK_REALTIME, &end_t);
  
  if(SECOND) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran. (%lf s total)\n",ntst, diff_timespec_seconds(end_t, start_t));
  else if(NANOSECOND) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran. (%ld ns total)\n",ntst, diff_timespec_nanoseconds(end_t, start_t));
  else PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran. (%lf ms total)\n",ntst, diff_timespec_milliseconds(end_t, start_t));
  
  PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_PS]," %lu tests\n", count_pass_global);
  if(failed_l != NULL){
    PRINT_HK_C(colors_f[k_RED], tab_hk_f[hk_FL]," %lu tests, listed below:\n",count_fail_global); 
    list_failed_test(failed_l);
    PRINT_HK_C("","","\n%ld FAILED TESTS \n",count_fail_global);
  }
}

/*
 * need to separate num type and ptr type because of (void*)
 * in the 2 below macros
 */

#define GEN_IS_IN_ARRAY_PTR(type)\
bool is_in_array_##type(type *array, type val){\
  bool found = false;\
  for(size_t i = 0; i < cur_array_##type; ++i){\
    PRINT_DEBUG("compare |%s| in array and val: |%s|\n",type##_TO_STR(array[i]), type##_TO_STR(val));\
    if(COMPARE_N_##type((void*)(array[i]),(void*)val  ) == 0 ){\
      found = true;\
      break;\
    }\
  }\
  PRINT_DEBUG(" val return = %d \n",found);\
  return found;\
}\

#define GEN_IS_IN_ARRAY_NUM(type)\
bool is_in_array_##type(type *array, type val){\
  bool found = false;\
  for(size_t i = 0; i < cur_array_##type; ++i){\
    PRINT_DEBUG("compare |%s| in array and val: |%s|\n",type##_TO_STR(array[i]), type##_TO_STR(val));\
    if(COMPARE_N_##type((void*)(&array[i]),(void*)&val  ) == 0 ){\
      found = true;\
      break;\
    }\
  }\
  PRINT_DEBUG(" val return = %d \n",found);\
  return found;\
}\


GEN_IS_IN_ARRAY_PTR(TYPE_STRING)
GEN_IS_IN_ARRAY_NUM(TYPE_SIZE_T)

/*
 * extract name test between () because the syntax is TEST(name_test)
 */ 
void extract_name_test_from_name(char *name_org, char **name_f){
  size_t len=strlen(name_org); 
  long cur=-1;
  char *name_test=malloc(len);
  for(size_t i=0; i<len; ++i){
    if(cur == -1 && name_org[i]=='(')
      cur=0;
    else if(cur >=0){
      if(name_org[i] == ')')
        break;
      else
        name_test[cur++]=name_org[i];
    }
  } 
  name_test[cur]='\0';
  PRINT_DEBUG("name_test =%s\n",name_test);
  *name_f = name_test;

}

#define CHECK_IF_SELECTED_TEST(name_f)\
  exec_test=0;\
  if(some_tests_selected == 0){\
     exec_test=1; \
  }\
  else{\
    if(cur_array_TYPE_SIZE_T){\
      num_f=extract_num__f(name_f) ;\
      exec_test = is_in_array_TYPE_SIZE_T(array_TYPE_SIZE_T,  num_f);\
    }\
    if(exec_test == 0 && cur_array_TYPE_STRING){\
      extract_name_test_from_name(name_f, &name_test);\
      exec_test = is_in_array_TYPE_STRING(array_TYPE_STRING,  name_test );\
      free(name_test);\
    }\
  }\
      
  

void execute_all(struct func *fun){
  struct func *tmp = fun;
  struct timespec start_t;
  size_t num_f;
  char *name_test=NULL;
  bool exec_test=0;
  //PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," Running %lu tests.\n",count_tests);
  while(tmp){
    current_fn = tmp;
    CHECK_IF_SELECTED_TEST(tmp->name)
    if(exec_test){
      begin_execute_func(tmp->name, &start_t);
      tmp->run();
      end_execute_func(tmp->name, start_t);
    }
    tmp = tmp->next;
  }
  current_fn = tmp;
}


void
run_all_tests()
{
  //progress = true;
 #if 1
  pthread_t thrd_progress;
  if(progress)  pthread_create(&thrd_progress, NULL, run_progress_tests, NULL);
//if(progress)  pthread_create(&thrd_progress, NULL, run_progress_tests, (void*)&max_col);
#endif

  struct timespec start_t;
   head_run(count_tests, &start_t);
   execute_all(f_beging);
   //stat_end_run(count_tests, start_t);
   stat_end_run(count_pass_global + count_fail_global, start_t);

   if(progress)  pthread_join(thrd_progress, NULL);

}

/*
 * begin end parallel tests
 */ 
/*
 * print on the top of all test  (parallel case)
 */
void head_all_parallel_run(struct timespec *start_t){
  clock_gettime(CLOCK_REALTIME, start_t);
  if (cur_array_TYPE_SIZE_T || cur_array_TYPE_STRING) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," Running tests on %ld threads\n", parallel_nb);
  else  PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," Running %ld tests on %ld threads\n",count_tests, parallel_nb);
}

/*
 * print on the top of test in parallel
 */ 
void head_parallel_run(struct timespec *start_t, size_t id_thrd){
  sprintf(log_name_file_thrd[id_thrd],"log_thread_%ld_id_%ld",id_thrd,pthread_self());
  f_ou_th[id_thrd] = fopen(log_name_file_thrd[id_thrd], "w+"); 
  clock_gettime(CLOCK_REALTIME, start_t);
  PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," Running tests on thread[%ld] ========== ==threadID== %ld \n", id_thrd,pthread_self());
}

/*
 * printing stat of each thread tests
 */ 
void
stat_end_parallel_run(size_t ntst, struct timespec start_t, size_t id_thrd){
  struct timespec end_t; clock_gettime(CLOCK_REALTIME, &end_t);
  
  if(SECOND) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran on thread[%ld]. (%lf s total) \n",ntst, id_thrd, diff_timespec_seconds(end_t, start_t));
  else if(NANOSECOND) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran on thread[%ld]. (%ld ns total)\n",ntst, id_thrd, diff_timespec_nanoseconds(end_t, start_t));
  else PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran on thread[%ld]. (%lf ms total)\n",ntst, id_thrd, diff_timespec_milliseconds(end_t, start_t));
  
  PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_PS]," %lu tests passed on thread[%ld]\n", count_pass_thread[id_thrd], id_thrd);
  if(thread_test_failed_l[id_thrd] != NULL){
    PRINT_HK_C(colors_f[k_RED], tab_hk_f[hk_FL]," %lu tests failed on thread[%ld], listed below:\n",count_fail_thread[id_thrd],id_thrd); 
    list_failed_test(thread_test_failed_l[id_thrd]);
  }
}
/*
 * stat of all tests on all threads
 */ 

void
stat_end_all_parallel_run(size_t ntst, struct timespec start_t){
  struct timespec end_t; clock_gettime(CLOCK_REALTIME, &end_t);

  //PRINT_HK_C(colors_f[k_DEFAULT], tab_hk_f[hk_EQ]," %s: all parallel tests done\n\n",__FILE__);
  
  if(SECOND) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran on %ld threads. (%lf s total) \n",ntst, parallel_nb, diff_timespec_seconds(end_t, start_t));
  else if(NANOSECOND) PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran on %ld threads. (%ld ns total)\n",ntst, parallel_nb, diff_timespec_nanoseconds(end_t, start_t));
  else PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_EQ]," %lu tests ran on %ld threads. (%lf ms total)\n",ntst, parallel_nb, diff_timespec_milliseconds(end_t, start_t));
  
  PRINT_HK_C(colors_f[k_GREEN], tab_hk_f[hk_PS]," %lu tests\n", count_pass_global);
  if(failed_l != NULL){
    PRINT_HK_C(colors_f[k_RED], tab_hk_f[hk_FL]," %lu tests, listed below:\n",count_fail_global); 
    list_failed_test(failed_l);
    PRINT_HK_C("","","\n%ld FAILED TESTS \n",count_fail_global);
  }
}



void begin_execute_func_parallel(char *fun_ame, struct timespec *start_t, size_t id_thrd){
  clock_gettime(CLOCK_REALTIME, start_t);
  PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_RN]," %s on thread[%ld]\n", fun_ame, id_thrd); 
}

#define PRINT_TIMESTAMP_STAT_PARALLEL(color)\
    if(SECOND) PRINT_HK_C(color,tab_hk_f[hk_DN]," %lu tests passed from %s (%lf s), on thread[%ld]\n\n",count_pass_test[num_test],fun_ame, diff_timespec_seconds(end_t, start_t),id_thrd);\
    else if(NANOSECOND) PRINT_HK_C(color,tab_hk_f[hk_DN]," %lu tests passed from %s (%ld ns), on thread[%ld]\n\n",count_pass_test[num_test],fun_ame, diff_timespec_nanoseconds(end_t, start_t),id_thrd);\
    else PRINT_HK_C(color,tab_hk_f[hk_DN]," %lu tests passed from %s (%lf ms), on thread[%ld]\n\n",count_pass_test[num_test],fun_ame, diff_timespec_milliseconds(end_t, start_t),id_thrd);

void end_execute_func_parallel(char *fun_ame, struct timespec start_t, size_t id_thrd){
  struct timespec end_t; clock_gettime(CLOCK_REALTIME, &end_t);
  size_t num_test = extract_num__f(fun_ame);  
  PRINT_DEBUG(" ... thread[%ld], count_fail_test[%ld] = %ld ... %s\n", id_thrd, num_test, count_fail_test[num_test],fun_ame);
  if(count_fail_test[num_test]){
    INCREMENT(count_fail_global); /*++count_fail_global*/
    append_failed_list(&thread_test_failed_l[id_thrd], fun_ame); 
    ++(count_fail_thread[id_thrd]);
    LOCK(mut_global_list_fail);
    append_failed_list(&failed_l, fun_ame); 
    UNLOCK(mut_global_list_fail);
    PRINT_HK_C(colors_f[k_RED], tab_hk_f[hk_FL], " %lu tests failed from %s on thread[%ld], %ld tests failed on thread[%ld]\n",count_fail_test[num_test],fun_ame, id_thrd,count_fail_thread[id_thrd],id_thrd);
    PRINT_TIMESTAMP_STAT_PARALLEL(colors_f[k_RED]);
  }
  else 
  {
    ++(count_pass_thread[id_thrd]);
    INCREMENT(count_pass_global); /*++count_pass_global*/
    PRINT_TIMESTAMP_STAT_PARALLEL(colors_f[k_GREEN]);
  }
}

void execute_test_parallel(size_t id_thrd){
  
  struct timespec start_t;
  struct func *tmp;
  size_t num_f;
  char *name_test=NULL;
  bool exec_test=0;
 
  do{ 
    LOCK(mut_current_test);
    tmp = current_fn;
    if(tmp){
      current_fn = tmp->next;
      UNLOCK(mut_current_test);
      CHECK_IF_SELECTED_TEST(tmp->name)
      if(exec_test){
        PRINT_DEBUG(" *** thread[%ld], func_name = %s *** \n", id_thrd, tmp->name);
        begin_execute_func_parallel(tmp->name, &start_t, id_thrd);
        tmp->run();
        end_execute_func_parallel(tmp->name, start_t, id_thrd);
      }
    }
    else{
      UNLOCK(mut_current_test);
    }
  }while(tmp);
}

void*
run_parallel_tests(void *id)
{
   size_t id_th=*(size_t*)id;
   id_thread_self[id_th] = pthread_self();
   struct timespec start_t;
   head_parallel_run(&start_t, id_th);
   execute_test_parallel(id_th);
   stat_end_parallel_run(count_fail_thread[id_th]+count_pass_thread[id_th], start_t, id_th);
   return (void*)0;
}

/*
 *
 */
void final_parallel_test_();

/*
 * initialisation
 */ 
void
init_parallel_test_()
{

  signal(SIGSEGV, final_parallel_test_); /* to clear logs files!  */


  is_parallel_nb = 1;
  
  f_ou_th = malloc((parallel_nb + 1) *sizeof(FILE*));
  log_name_file_thrd = malloc((parallel_nb + 1) *sizeof(char*));
  for(size_t i=0; i<=parallel_nb; ++i){
    log_name_file_thrd[i] = malloc((256) *sizeof(char));
  }

  /*
   *  on thread principale
   */
  sprintf(log_name_file_thrd[parallel_nb],"log_principal_thread_%ld_id_%ld",parallel_nb,pthread_self());
  f_ou_th[parallel_nb] = fopen(log_name_file_thrd[parallel_nb], "w+");



  count_pass_test = malloc(count_tests * sizeof(size_t));
  count_fail_test = malloc(count_tests * sizeof(size_t));
  for(size_t i=0; i<count_tests; ++i){
    count_pass_test[i]=0;
    count_fail_test[i]=0;
  }

  thread_test_failed_l = malloc(parallel_nb * sizeof(struct failed_lists*));
  count_pass_thread = malloc(parallel_nb * sizeof(size_t));
  count_fail_thread = malloc(parallel_nb * sizeof(size_t));
  id_thread_self = malloc((parallel_nb + 1) * sizeof(size_t));
  
  id_thread_self[parallel_nb]=   pthread_self();// main thread 

  for(size_t i=0; i<parallel_nb; ++i){
    thread_test_failed_l[i] = NULL;
    count_pass_thread[i] = 0;
    count_fail_thread[i] = 0;
  }

  current_fn = f_beging;

  pthread_mutex_init(&mut_global_list_fail, NULL);
  pthread_mutex_init(&mut_current_test, NULL);
  pthread_mutex_init(&mut_count_pass_global, NULL);
  pthread_mutex_init(&mut_count_fail_global, NULL);
  pthread_mutex_init(&mut_count_pass_local, NULL);
  pthread_mutex_init(&mut_count_fail_local, NULL);
}
/*
 * finalisation, cleanup
 */ 
void
final_parallel_test_()
{
  is_parallel_nb = 0; /* to avoid issue when print debug afer removing log_ of each thread if removelog is active */

  free(count_pass_test);
  free(count_fail_test);
  free(count_pass_thread);
  free(count_fail_thread);

  free(thread_test_failed_l);

  
  pthread_mutex_destroy(&mut_global_list_fail);
  pthread_mutex_destroy(&mut_current_test);
  pthread_mutex_destroy(&mut_count_pass_global);
  pthread_mutex_destroy(&mut_count_fail_global);
  pthread_mutex_destroy(&mut_count_pass_local);
  pthread_mutex_destroy(&mut_count_fail_local);


  char reader[256]="Here are the ordered results for each thread"; 
 
  struct winsize w;
  ioctl(1, TIOCGWINSZ, &w);
  
  fprintf(F_OUT,"\n\n%0*d\n %*s \n%0*d\n\n",w.ws_col,0, (int)(w.ws_col+strlen(reader))/2, reader,w.ws_col,0 );

  if(savelog){
    FILE *f_savelog;
    f_savelog=fopen(savelog, "a");
    for(size_t id_thrd =0 ; id_thrd <= parallel_nb; ++id_thrd){
      rewind(f_ou_th[id_thrd]); // put the file pointer to the begin of file;
      while(fgets(reader, 255,f_ou_th[id_thrd] )){
        fprintf(F_OUT,"%s",reader);
        fprintf(f_savelog,"%s",reader);
      }
      fclose(f_ou_th[id_thrd]);
    }
    fclose(f_savelog);
  }else{
    for(size_t id_thrd =0 ; id_thrd <= parallel_nb; ++id_thrd){
      rewind(f_ou_th[id_thrd]); // put the file pointer to the begin of file;
      while(fgets(reader, 255,f_ou_th[id_thrd] ))
        fprintf(F_OUT,"%s",reader); 
      fclose(f_ou_th[id_thrd]);
    }
  }
  
  if(removelog){
    for(size_t i=0; i<=parallel_nb; ++i){
      remove(log_name_file_thrd[i]);
      PRINT_DEBUG("file log of treard[%ld] removed\n",i);
    }
  }

}

void run_all_tests_parallel(size_t parallel /*, int max_col*/)
{
  parallel_nb = parallel; /* need to be here to initialise parallel_nb for init_parallel_test_ */
  
  init_parallel_test_();
  
  struct timespec start_t;
  
  head_all_parallel_run(&start_t);

#if 1
  pthread_t thrd_progress;
if(progress)  pthread_create(&thrd_progress, NULL, run_progress_tests, NULL);
//if(progress)  pthread_create(&thrd_progress, NULL, run_progress_tests, (void*)&max_col);
#endif

  pthread_t *thrd = malloc(parallel_nb * sizeof(pthread_t));
  size_t *id_th = malloc( parallel_nb * sizeof(size_t));

  for(size_t i = 0; i < parallel_nb; ++i){
    id_th[i]=i;
    pthread_create(&thrd[i], NULL, run_parallel_tests, (void*)&id_th[i]);
  }

  for(size_t i=0; i<parallel_nb; ++i){
    pthread_join(thrd[i], NULL);
  }

if(progress)  pthread_join(thrd_progress, NULL);
  
  //stat_end_all_parallel_run(count_tests, start_t );
  stat_end_all_parallel_run(count_pass_global + count_fail_global, start_t );

  free(id_th);
  free(thrd);
  
  final_parallel_test_();
}

void run_all_tests_args(int argc, char **argv){
  
  parse_options(argc,argv);


  if(help) usage(argc,argv);
  if(is_parallel_nb) run_all_tests_parallel(parallel_nb);
  else run_all_tests();
}

void 
clear_all_func(struct func **fun)
{
  struct func *tmp = *fun, *ttmp;
  while(tmp != NULL){
    ttmp = tmp;
    tmp = tmp->next;
    free(ttmp);
  }
}
/*
 * to purge func list!
 * optionnal but good practice
 */
__attribute__((destructor)) 
void
purge_tests()
{
  struct func *tmp = f_beging;
  clear_all_func(&tmp); 
  PRINT_DEBUG("%s\n","purge done");
  
}

