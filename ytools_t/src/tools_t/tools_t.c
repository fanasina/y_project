#include "tools_t/tools_t.h"

#define POW 17
#define MMOD ((1 << (POW)) - 1)
#define SUBA 5
#define SUBB 8
#if 0
int xrand(){
  int mod = MMOD; // (1 << 17) - 1;
  int a = (1<<(POW-(SUBA))) - 1;
  int b = (1 << (POW-(SUBB))) - 1;
  static int xi = 0;
  int xii = (a * xi + b)%mod;
  //float ret = (float) xii / mod;

  //printf("[a:%d * xi:%6d + b:%d ] %% %d = %6d :: %.7f | ",a,xi,b,mod,xii,ret);

  xi = xii;

  return xii;
}
#else
int xrand(){
  static bool init = true;
  if(init){
    init = false;
		srand(time(NULL));
    /*
		struct timespec start_t;
    clock_gettime(CLOCK_REALTIME, &start_t);
    srand(start_t.tv_nsec);
		*/
      //srand(start_t.tv_nsec - start_t.tv_sec);
  }
  int ret = rand ();
  return ret ;
}
#endif

int irand(){
  int mod = MMOD; // (1 << 17) - 1;
  int a = (1<<(POW-(SUBA))) - 1;
  int b = (1 << (POW-(SUBB))) - 1;
  static int xi = 0;
  int xii = (a * xi + b)%mod;
  //float ret = (float) xii / mod;

  //printf("[a:%d * xi:%6d + b:%d ] %% %d = %6d :: %.7f | ",a,xi,b,mod,xii,ret);

  xi = xii;

  return xii;

}


float frand(){
 /* int mod = MMOD; // (1 << 17) - 1;
  int a = (1<<13) - 1;
  int b = (1 << 7) - 1;
  static int xi = 0;
  
  int xii = (a * xi + b)%mod;
  float ret = (float) xii / mod;
  
  printf("[a:%d * xi:%6d + b:%d ] %% %d = %6d :: %.7f | ",a,xi,b,mod,xii,ret);

  xi = xii;

  return ret;
*/
/*
int xii = irand();
  float ret = (float) xii / (MMOD);
*/  
  int xii = rand();
  float ret = (float) xii / RAND_MAX;

//  printf("[%6d / %6d = %.6f | ", (xii), MMOD, ret);

  return ret; 
}


/*
int xrand(){
    static int randMod = 1;
    static bool init = true;
    if(init){
      init = false;
      struct timespec start_t;
      clock_gettime(CLOCK_REALTIME, &start_t);
      srand(start_t.tv_nsec);
      //srand(start_t.tv_nsec - start_t.tv_sec);
    }
    int ret = rand ();
    if(ret % 7 ==  randMod % 11){
      init = true;
      randMod = ret + 1;
    }
    return ret ;
}

float frand(){
  int max = 50000;
  static int rnd = 0;
  rnd = (xrand())%max;
  printf("[%6d / %6d = %.6f | ", (rnd), max,(float)(rnd)/max);
  return (float)(rnd)/max;
  }
*/

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}



void clear_screen(){
   struct winsize w;

    ioctl(1, TIOCGWINSZ, &w);
    char pad[w.ws_col+1];
    int i=0;
    for(i=0; i<w.ws_col+1; ++i) pad[i]=' ';
    pad[i]='\0';
    for(i=0; i<w.ws_row - 5 ; ++i) printf("%s\n",pad);;


}


/*
void get_cursor_position(int *col, int *rows)
{
    int a = 0;
    int i = 0;
    char buf[4];

    write(1, "\033[6n", 4); // string asking for the cursor position
    read(1, buf, 4);

    while (buf[i])
    {
        if (buf[i] >= 48 && buf[i] <= 57)
        {
            if (a == 0)
                *rows = atoi(&buf[i]) - 1;
            else
                *col = atoi(&buf[i]) - 1;
            a++;
        }
        i++;
    }
}
*/

/*
double diff_timespec_seconds(struct timespec time_stop, struct timespec time_start){
  return (time_stop.tv_sec - time_start.tv_sec) + 1.0e-9 * (time_stop.tv_nsec - time_start.tv_nsec);
}

double diff_timespec_milliseconds(struct timespec time_stop, struct timespec time_start){
  return 1.0e3 * (time_stop.tv_sec - time_start.tv_sec) + 1.0e-3 * (time_stop.tv_nsec - time_start.tv_nsec);
}
long diff_timespec_nanoseconds(struct timespec time_stop, struct timespec time_start){
  return 1.0e9 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_nsec - time_start.tv_nsec);
}
*/


#define GEN_TO_STR_N(type,size,format)  \
  TYPE_STRING type##_TO_STR(type var){  \
    char *ret = malloc(size);                     \
    /*int szret = */sprintf(ret,format,var);            \
    /*ret[szret]='\0'*//*no need , already by default */;              \
    return ret;                         \
  }\

GEN_TO_STR_N(TYPE_CHAR,2,"%c")
GEN_TO_STR_N(TYPE_U_CHAR,2,"%c")
GEN_TO_STR_N(TYPE_INT,22,"%d")
GEN_TO_STR_N(TYPE_U_INT,22,"%u")
GEN_TO_STR_N(TYPE_L_INT,22,"%ld")
GEN_TO_STR_N(TYPE_U_L_INT,22,"%lu")
GEN_TO_STR_N(TYPE_SIZE_T,22,"%lu")
GEN_TO_STR_N(TYPE_FLOAT,128,"%.10f")
GEN_TO_STR_N(TYPE_DOUBLE,256,"%.30lf")
GEN_TO_STR_N(TYPE_L_DOUBLE,256,"%.30Lf")

TYPE_STRING TYPE_STRING_TO_STR(TYPE_STRING var){
  return var;
}

#if 0

#define PRECISION_TYPE_CHAR 1
#define PRECISION_TYPE_U_CHAR 1
#define PRECISION_TYPE_INT 1
#define PRECISION_TYPE_U_INT 1
#define PRECISION_TYPE_L_INT 1
#define PRECISION_TYPE_U_L_INT 1
#define PRECISION_TYPE_SIZE_T 1

// with gcc we can change value of theses  PRECISION_TYPES below with: gcc -D PRECISION_TYPE_FLOAT=100000 for instance!
#ifndef PRECISION_TYPE_FLOAT 
  #define PRECISION_TYPE_FLOAT 100000000
  /*#define PRECISION_TYPE_FLOAT 10*/
#endif
#ifndef PRECISION_TYPE_DOUBLE
  #define PRECISION_TYPE_DOUBLE 100000000000
  /*#define PRECISION_TYPE_DOUBLE 1000*/
#endif
#ifndef PRECISION_TYPE_L_DOUBLE
  #define PRECISION_TYPE_L_DOUBLE 100000000000000
#endif

#endif

#if 1

long int PRECISION_TYPE_CHAR  = 1;
long int PRECISION_TYPE_U_CHAR  = 1;
long int PRECISION_TYPE_INT  = 1;
long int PRECISION_TYPE_U_INT  = 1;
long int PRECISION_TYPE_L_INT  = 1;
long int PRECISION_TYPE_U_L_INT  = 1;
long int PRECISION_TYPE_SIZE_T  = 1;

long int PRECISION_TYPE_FLOAT  = 100000000;
long int PRECISION_TYPE_DOUBLE  = 100000000000;
long int PRECISION_TYPE_L_DOUBLE  = 100000000000000;

#endif



#define GENERATE_FUNCTION_NUMERIC(type)\
  int COMPARE_N_##type(const void *a, const  void *b){              \
    type diff = 0;\
     if((*(type*)a > *(type*)b)){           \
      diff =(*(type*)a - *(type*)b) * PRECISION_##type;           \
    /*char *str_diff = type##_TO_STR(diff), *str_a = type##_TO_STR(*(type*)a), *str_b = type##_TO_STR(*(type*)b);\
    PRINT_DEBUG_(" diff = %s a=%s b=%s PRECISION : %ld\n",str_diff, str_a, str_b, PRECISION_##type);\
    free(str_diff); free(str_a); free(str_b);\
     */ \
      if(diff >= 1) return 1;\
      return 0;\
     }else{\
      diff =(*(type*)b - *(type*)a) * PRECISION_##type;           \
    /*char *str_diff = type##_TO_STR(diff), *str_a = type##_TO_STR(*(type*)a), *str_b = type##_TO_STR(*(type*)b);\
    PRINT_DEBUG_(" diff = %s a=%s b=%s PRECISION : %ld\n",str_diff, str_a, str_b, PRECISION_##type);\
    free(str_diff); free(str_a); free(str_b);\
    */\
      if(diff >= 1) return -1;\
      return 0;\
     }\
    \
    /*if (diff <= -1) return -1;                                                    \
    if (diff >= 1) return 1;                                                    \
    return 0;                                                    \
  */\
  }                                                                 \
                                                                    \
  void COPY_ARRAY_##type(type *dst, const type *src, size_t size){  \
    for(size_t i = 0; i < size; ++i) dst[i]=src[i];                 \
  }                                                                 \
\

int 
COMPARE_N_TYPE_STRING(const void *a,const  void* b)
{
  char **aa=(char**)a;
  char **bb=(char**)b;
  PRINT_DEBUG_("a=%s, b=%s\n",*aa, *bb);
  return strcmp(*aa,*bb);
}

void COPY_ARRAY_TYPE_STRING(char** dst, const char** src, size_t size)
{
  for(size_t i = 0; i < size; ++i) strcpy(dst[i],src[i]);
}


GENERATE_FUNCTION_NUMERIC(TYPE_CHAR)
GENERATE_FUNCTION_NUMERIC(TYPE_U_CHAR)
GENERATE_FUNCTION_NUMERIC(TYPE_INT)
GENERATE_FUNCTION_NUMERIC(TYPE_U_INT)
GENERATE_FUNCTION_NUMERIC(TYPE_L_INT)
GENERATE_FUNCTION_NUMERIC(TYPE_U_L_INT)
GENERATE_FUNCTION_NUMERIC(TYPE_SIZE_T)
GENERATE_FUNCTION_NUMERIC(TYPE_FLOAT)
GENERATE_FUNCTION_NUMERIC(TYPE_DOUBLE)
GENERATE_FUNCTION_NUMERIC(TYPE_L_DOUBLE)

#define GENERATE_FUNCTION_ALL(type)\
  type MAX_ARRAY_##type(const type *array, size_t size){\
    if(array == NULL) return 0;\
    type mx =(type)array[0];\
    for(size_t i = 0; i < size; ++i)\
      if(COMPARE_N_##type(&mx,&array[i]) < 0) mx =(type)array[i];\
    return mx;}\
\
  size_t ARG_MAX_ARRAY_##type(const type *array, size_t size){\
    if(array == NULL) return 0;\
    size_t i_mx = 0;\
    for(size_t i = 0; i < size; ++i)\
      if(COMPARE_N_##type(&array[i_mx],&array[i]) < 0) i_mx = i;\
    return i_mx;}\
\
  type MIN_ARRAY_##type(const type *array, size_t size){\
    if(array == NULL) return 0;\
    type mn =(type)array[0];\
    for(size_t i = 0; i < size; ++i)\
      if(COMPARE_N_##type(&mn,&array[i]) > 0) mn =(type)array[i];\
    return mn;}\
\
  size_t ARG_MIN_ARRAY_##type(const type *array, size_t size){\
    if(array == NULL) return 0;\
    size_t i_mn = 0;\
    for(size_t i = 0; i < size; ++i)\
      if(COMPARE_N_##type(&array[i_mn],&array[i]) > 0) i_mn = i;\
    return i_mn;}\
\


GENERATE_FUNCTION_ALL(TYPE_CHAR)
GENERATE_FUNCTION_ALL(TYPE_U_CHAR)
GENERATE_FUNCTION_ALL(TYPE_INT)
GENERATE_FUNCTION_ALL(TYPE_U_INT)
GENERATE_FUNCTION_ALL(TYPE_L_INT)
GENERATE_FUNCTION_ALL(TYPE_U_L_INT)
GENERATE_FUNCTION_ALL(TYPE_SIZE_T)
GENERATE_FUNCTION_ALL(TYPE_FLOAT)
GENERATE_FUNCTION_ALL(TYPE_DOUBLE)
GENERATE_FUNCTION_ALL(TYPE_L_DOUBLE)
GENERATE_FUNCTION_ALL(TYPE_STRING)

/* strto_type */
  
int strto_TYPE_INT(char *str, char **endptr){ 
  return (int)strtol(str,endptr,10);
}
unsigned int strto_TYPE_U_INT(char *str, char **endptr){ 
  return (unsigned int)strtoul(str,endptr,10);
}
long int strto_TYPE_L_INT(char *str, char **endptr){
  return strtol(str,endptr,10);
}
unsigned long int strto_TYPE_U_L_INT(char *str, char **endptr){
  return strtoul(str,endptr,10);
}
size_t strto_TYPE_SIZE_T(char *str, char **endptr){
  return strtoul(str,endptr,10);
}
float strto_TYPE_FLOAT(char *str, char **endptr){
  return strtof(str,endptr);
}
double strto_TYPE_DOUBLE(char *str, char **endptr){
  return strtod(str,endptr);
}
long double strto_TYPE_L_DOUBLE(char *str, char **endptr){
  return strtold(str,endptr);
}


/*
 * time section
 */

double diff_timespec_seconds(struct timespec time_stop, struct timespec time_start){
  //PRINT_DEBUG_("\n\nstop.sec:%ld, start.sec:%ld, stop.nsec:%ld, start.nsec:%ld\n\n",  time_stop.tv_sec , time_start.tv_sec, time_stop.tv_nsec , time_start.tv_nsec);
  return (time_stop.tv_sec - time_start.tv_sec) + 1.0e-9 * (time_stop.tv_nsec - time_start.tv_nsec);
}

double diff_timespec_milliseconds(struct timespec time_stop, struct timespec time_start){
  //PRINT_DEBUG_("\n\nstop.sec:%ld, start.sec:%ld, stop.nsec:%ld, start.nsec:%ld\n\n",  time_stop.tv_sec , time_start.tv_sec, time_stop.tv_nsec , time_start.tv_nsec);
  return 1.0e3 * (time_stop.tv_sec - time_start.tv_sec) + 1.0e-6 * (time_stop.tv_nsec - time_start.tv_nsec);
}

long diff_timespec_nanoseconds(struct timespec time_stop, struct timespec time_start){
  //PRINT_DEBUG_("\n\nstop.sec:%ld, start.sec:%ld, stop.nsec:%ld, start.nsec:%ld\n\n",  time_stop.tv_sec , time_start.tv_sec, time_stop.tv_nsec , time_start.tv_nsec);
  return 1.0e9 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_nsec - time_start.tv_nsec);
}


