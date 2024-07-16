#ifndef __TOOLS_T_C_H__
#define __TOOLS_T_C_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#include <sys/ioctl.h>


// to define DEBUG in gcc cli do: gcc -D DEBUG=1 or 0 if need!
#ifndef DEBUG
  #define DEBUG 0
#endif


// F_OUT file (stream) to log
#ifndef F_OUT
  #define F_OUT stdout
#endif
// F_ERR file (stream) to log
#ifndef F_ERR
  #define F_ERR stderr
#endif

/*
#ifndef SECOND
  #define SECOND 0
#endif
#ifndef NANOSECOND
  #define NANOSECOND 0
#endif

double diff_timespec_seconds(struct timespec time_stop, struct timespec time_start);
double diff_timespec_milliseconds(struct timespec time_stop, struct timespec time_start);
long diff_timespec_nanoseconds(struct timespec time_stop, struct timespec time_start);
*/

#if 1

extern long int PRECISION_TYPE_FLOAT ;
extern long int PRECISION_TYPE_DOUBLE ;
extern long int PRECISION_TYPE_L_DOUBLE ;

#endif

int xrand();
float frand();

void gotoxy(int x, int y);

void clear_screen();

//void get_cursor_position(int *col, int *rows);

#if DEBUG

#define debug_print(fmt, ...) \
  do { /*if (DEBUG)*/ fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
      __LINE__, __func__, __VA_ARGS__); } while (0)

#define PRINT_DEBUG_(fmt, ...) \
  do { /*if (DEBUG)*/ fprintf(F_ERR, "%s:%d:%s(): " fmt, __FILE__, \
      __LINE__, __func__, __VA_ARGS__); } while (0)

#else
#define debug_print(fmt, ...) {} 

#define PRINT_DEBUG_(fmt, ...) {}

#endif

#define error_print(fmt, ...) \
   fprintf(stderr, "%s:%d:%s(): " fmt, __FILE__, \
      __LINE__, __func__, __VA_ARGS__); 

#define PRINT_ERROR(fmt, ...) \
   fprintf(F_ERR, "%s:%d:%s(): " fmt, __FILE__, \
      __LINE__, __func__, __VA_ARGS__); 

#define PRINT_LOC_T(fmt, ...) \
   fprintf(F_OUT, "%s:%d:%s(): " fmt, __FILE__, \
      __LINE__, __func__, __VA_ARGS__); 



#define TYPE_CHAR char
#define TYPE_U_CHAR unsigned char
#define TYPE_INT int
#define TYPE_U_INT unsigned int
#define TYPE_L_INT long int
#define TYPE_U_L_INT unsigned long int
#define TYPE_SIZE_T size_t
#define TYPE_FLOAT float
#define TYPE_DOUBLE double
#define TYPE_L_DOUBLE long double
#define TYPE_STRING char*

#define FREE(x)  { free((x)); (x) = NULL;} 

#define FOREACH(array, size, function)\
  for(size_t _ind = 0; _ind < size; ++_ind) function(array[_ind]);

#define MIN(X, Y) (((Y) < (X)) ? (Y) : (X))
#define MAX(X, Y) (((Y) > (X)) ? (Y) : (X))

#define GENERATE_ALL(type)\
  int COMPARE_N_##type(const void *,const    void*);\
  void COPY_ARRAY_##type(type* dst, const type* src, size_t size);\
  type MAX_ARRAY_##type(const  type *array, size_t size);\
  size_t ARG_MAX_ARRAY_##type(const type *array, size_t size);\
  type MIN_ARRAY_##type(const  type *array, size_t size);\
  size_t ARG_MIN_ARRAY_##type(const  type *array, size_t size);\
  TYPE_STRING type##_TO_STR(type var);\
  

GENERATE_ALL(TYPE_CHAR)
GENERATE_ALL(TYPE_U_CHAR)
GENERATE_ALL(TYPE_INT)
GENERATE_ALL(TYPE_U_INT)
GENERATE_ALL(TYPE_L_INT)
GENERATE_ALL(TYPE_U_L_INT)
GENERATE_ALL(TYPE_SIZE_T)
GENERATE_ALL(TYPE_FLOAT)
GENERATE_ALL(TYPE_DOUBLE)
GENERATE_ALL(TYPE_L_DOUBLE)
GENERATE_ALL(TYPE_STRING)

/* strto_type */

int strto_TYPE_INT(char *str, char **endptr);
unsigned int strto_TYPE_U_INT(char *str, char **endptr);
long int strto_TYPE_L_INT(char *str, char **endptr);
unsigned long int strto_TYPE_U_L_INT(char *str, char **endptr);
size_t strto_TYPE_SIZE_T(char *str, char **endptr);
float strto_TYPE_FLOAT(char *str, char **endptr);
double strto_TYPE_DOUBLE(char *str, char **endptr);
long double strto_TYPE_L_DOUBLE(char *str, char **endptr);

/*
 * time calucl
 */
double diff_timespec_seconds(struct timespec time_stop, struct timespec time_start);

double diff_timespec_milliseconds(struct timespec time_stop, struct timespec time_start);

long diff_timespec_nanoseconds(struct timespec time_stop, struct timespec time_start);


#endif /*__TOOLS_T_C_H__*/

