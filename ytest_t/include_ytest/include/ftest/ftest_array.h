#ifndef __TEST_ARRAY_C_H__
#define __TEST_ARRAY_C_H__

#include "ftest/ftest.h"

#define min(a,b) (((a)<(b)) ? (a) : (b))

 /*
 * only expect
 */

#define HANDLE_OP_EXPECT_ARRAY_NAME(OP,type,var1, sz1, var2, sz2,name_f,msg_call)                                                          \
do{      \
   if(is_parallel_nb == 0){\
      if(expected_array_##OP##_##type(var1, sz1, var2, sz2)){                                                                       \
        if(verb==NORMAL){PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 %s passed %s \n\n",name_f,msg_call);}                                       \
        else if(verb==VERB){\
          PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 %s passed %s \n\n",name_f,msg_call);\
          PRINT_LOC("test passed: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
          for(size_t i=0; i < min(sz1,sz2);++i) {\
              char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
              PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
              ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
              free(str_var1); free(str_var2);\
           }\
        }\
     \
      }                                                                                                         \
      else{                                                                                                     \
        PRINT_LOC("Failure\nExpected: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
        for(size_t i=0; i < min(sz1,sz2);++i)\
          if (!(COMPARE_N_##type((void*)(var1 + i),(void*)(var2 + i)) OP 0)) {\
           char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
           PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
            ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
           free(str_var1); free(str_var2);\
          }\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                           \
                                                         \
   }else {                                                                                                         \
      if(expected_array_##OP##_name_##type(var1, sz1, var2, sz2, name_f)){                                                                       \
        if(verb==NORMAL){PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 %s passed %s \n\n",name_f,msg_call);}                                       \
        else if(verb==VERB){\
          PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 %s passed %s \n\n",name_f,msg_call);\
          PRINT_LOC("test passed: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
          for(size_t i=0; i < min(sz1,sz2);++i) {\
              char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
              PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
              ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
              free(str_var1); free(str_var2);\
           }\
        }\
      }                                                                                                         \
      else{                                                                                                     \
        PRINT_LOC("Failure\nExpected: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
        for(size_t i=0; i < min(sz1,sz2);++i)\
          if (!(COMPARE_N_##type((void*)(var1 + i),(void*)(var2 + i)) OP 0)) {\
           char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
           PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
            ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
           free(str_var1); free(str_var2);\
          }\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                           \
      }                                                                                                         \
    }\
}while(0);

//#define EXPECT_ARRAY_OP_(OP,type,var1, sz1, var2, sz2)  HANDLE_OP_EXPECT_ARRAY_(OP,type,var1, sz1, var2, sz2)
  
 // *******************************************************************************************************************
  
  /**
   * new HANDLE_OP_ EXPECT_ARRAY and ASSERT_ARRAY separated
   */
#define HANDLE_OP_EXPECT_ARRAY_(OP,type,var1, sz1, var2, sz2)                                                          \
do{      \
   if(is_parallel_nb == 0){\
      if(expected_array_##OP##_##type(var1, sz1, var2, sz2)){                                                                       \
        if(verb==NORMAL){ PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);} \
        else if(verb==VERB){\
           PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__); \
          PRINT_LOC("test passed: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
          for(size_t i=0; i < min(sz1,sz2);++i) {\
              char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
              PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
              ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
              free(str_var1); free(str_var2);\
           }\
        }\
      }                                                                                                         \
      else{                                                                                                     \
        PRINT_LOC("Failure\nExpected: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
        for(size_t i=0; i < min(sz1,sz2);++i)\
          if (!(COMPARE_N_##type((void*)(var1 + i),(void*)(var2 + i)) OP 0)) {\
           char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
           PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
            ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
           free(str_var1); free(str_var2);\
          }\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                           \
      }                                                                                                         \
   }else {                                                                                                         \
      if(expected_array_##OP##_name_##type(var1, sz1, var2, sz2, __func__)){                                                                       \
        if(verb==NORMAL){ PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);} \
        else if(verb==VERB){\
           PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__); \
          PRINT_LOC("test passed: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
          for(size_t i=0; i < min(sz1,sz2);++i) {\
              char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
              PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
              ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
              free(str_var1); free(str_var2);\
           }\
        }\
      }                                                                                                         \
      else{                                                                                                     \
        PRINT_LOC("Failure\nExpected: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
        for(size_t i=0; i < min(sz1,sz2);++i)\
          if (!(COMPARE_N_##type((void*)(var1 + i),(void*)(var2 + i)) OP 0)) {\
           char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
           PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
            ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
           free(str_var1); free(str_var2);\
          }\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                           \
      }                                                                                                         \
    }\
}while(0);

#define HANDLE_OP_ASSERT_ARRAY_(OP,type,var1, sz1, var2, sz2)                                                          \
do{      \
   if(is_parallel_nb == 0){\
      if(expected_array_##OP##_##type(var1, sz1, var2, sz2)){                                                                       \
        if(verb==NORMAL){ PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);} \
        else if(verb==VERB){\
           PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__); \
          PRINT_LOC("test passed: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
          for(size_t i=0; i < min(sz1,sz2);++i) {\
              char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
              PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
              ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
              free(str_var1); free(str_var2);\
           }\
        }\
      }                                                                                                         \
      else{                                                                                                     \
        PRINT_LOC("Failure\nExpected: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
        for(size_t i=0; i < min(sz1,sz2);++i)\
          if (!(COMPARE_N_##type((void*)(var1 + i),(void*)(var2 + i)) OP 0)) {\
           char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
           PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
            ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
           free(str_var1); free(str_var2);\
          }\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                           \
        return;                                                                                   \
      }                                                                                                         \
   }else {                                                                                                         \
      if(expected_array_##OP##_name_##type(var1, sz1, var2, sz2, __func__)){                                                                       \
        if(verb==NORMAL){ PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);} \
        else if(verb==VERB){\
           PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__); \
          PRINT_LOC("test passed: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
          for(size_t i=0; i < min(sz1,sz2);++i) {\
              char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
              PRINTF("Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
              ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
              free(str_var1); free(str_var2);\
           }\
        }\
      }                                                                                                         \
      else{                                                                                                     \
        PRINT_LOC("Failure\nExpected: (%s) %s (%s) \n\n",#var1,STRFY(OP),#var2);                                            \
        for(size_t i=0; i < min(sz1,sz2);++i)\
          if (!(COMPARE_N_##type((void*)(var1 + i),(void*)(var2 + i)) OP 0)) {\
           char *str_var1 = type##_TO_STR(var1[i]), *str_var2 = type##_TO_STR(var2[i]);\
           PRINTF(" Value of %s[%ld]: %s \n Value of %s[%ld]: %s\n\n"\
            ,#var1,i, str_var1,  #var2,i, str_var2);                                            \
           free(str_var1); free(str_var2);\
          }\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                           \
        return;                                                                                   \
      }                                                                                                         \
    }\
}while(0);



// ********************************************************************************************************************

  
// *********************** begin EQ  ************************ 
// ============== EXPECT_ARRAY ==============================

#define EXPECT_ARRAY_EQ_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_U_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_FLOAT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_EQ_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_STRING,var1, sz1, var2, sz2)

#define EXPECT_ARRAY_EQ(var1, sz1, var2, sz2) HANDLE_OP_EXPECT_ARRAY_(EQ, TYPE_L_INT,var1, sz1, var2, sz2)



// ============== ASERT =====================

#define ASSERT_ARRAY_EQ_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_U_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_FLOAT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_EQ_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_STRING,var1, sz1, var2, sz2)

#define ASSERT_ARRAY_EQ(var1, sz1, var2, sz2)  HANDLE_OP_ASSERT_ARRAY_(EQ, TYPE_L_INT,var1, sz1, var2, sz2)

// ************************ end EQ  **********************


// *********************** begin LT  ************************ 
// ============== EXPECT_ARRAY ==============================

#define EXPECT_ARRAY_LT_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_U_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_FLOAT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LT_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_STRING,var1, sz1, var2, sz2)

#define EXPECT_ARRAY_LT(var1, sz1, var2, sz2) HANDLE_OP_EXPECT_ARRAY_(LT, TYPE_L_INT,var1, sz1, var2, sz2)


// ============== ASERT =====================

#define ASSERT_ARRAY_LT_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_U_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_FLOAT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LT_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_STRING,var1, sz1, var2, sz2)

#define ASSERT_ARRAY_LT(var1, sz1, var2, sz2)  HANDLE_OP_ASSERT_ARRAY_(LT, TYPE_L_INT,var1, sz1, var2, sz2)

// ************************ end LT  **********************


// *********************** begin GT  ************************ 
// ============== EXPECT_ARRAY ==============================

#define EXPECT_ARRAY_GT_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_U_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_FLOAT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GT_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_STRING,var1, sz1, var2, sz2)

#define EXPECT_ARRAY_GT(var1, sz1, var2, sz2) HANDLE_OP_EXPECT_ARRAY_(GT, TYPE_L_INT,var1, sz1, var2, sz2)



// ============== ASERT =====================

#define ASSERT_ARRAY_GT_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_U_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_FLOAT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GT_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_STRING,var1, sz1, var2, sz2)

#define ASSERT_ARRAY_GT(var1, sz1, var2, sz2)  HANDLE_OP_ASSERT_ARRAY_(GT, TYPE_L_INT,var1, sz1, var2, sz2)

// ************************ end GT  **********************


// *********************** begin LE  ************************ 
// ============== EXPECT_ARRAY ==============================

#define EXPECT_ARRAY_LE_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_U_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_FLOAT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_LE_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_STRING,var1, sz1, var2, sz2)

#define EXPECT_ARRAY_LE(var1, sz1, var2, sz2) HANDLE_OP_EXPECT_ARRAY_(LE, TYPE_L_INT,var1, sz1, var2, sz2)



// ============== ASERT =====================

#define ASSERT_ARRAY_LE_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_U_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_FLOAT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_LE_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_STRING,var1, sz1, var2, sz2)

#define ASSERT_ARRAY_LE(var1, sz1, var2, sz2)  HANDLE_OP_ASSERT_ARRAY_(LE, TYPE_L_INT,var1, sz1, var2, sz2)

// ************************ end LE  **********************


// *********************** begin GE  ************************ 
// ============== EXPECT_ARRAY ==============================

#define EXPECT_ARRAY_GE_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_U_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_FLOAT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_GE_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_STRING,var1, sz1, var2, sz2)

#define EXPECT_ARRAY_GE(var1, sz1, var2, sz2) HANDLE_OP_EXPECT_ARRAY_(GE, TYPE_L_INT,var1, sz1, var2, sz2)



// ============== ASERT =====================

#define ASSERT_ARRAY_GE_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_U_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_FLOAT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_GE_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_STRING,var1, sz1, var2, sz2)

#define ASSERT_ARRAY_GE(var1, sz1, var2, sz2)  HANDLE_OP_ASSERT_ARRAY_(GE, TYPE_L_INT,var1, sz1, var2, sz2)

// ************************ end GE  **********************


// *********************** begin NE  ************************ 
// ============== EXPECT_ARRAY ==============================

#define EXPECT_ARRAY_NE_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_U_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_FLOAT,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define EXPECT_ARRAY_NE_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_STRING,var1, sz1, var2, sz2)

#define EXPECT_ARRAY_NE(var1, sz1, var2, sz2) HANDLE_OP_EXPECT_ARRAY_(NE, TYPE_L_INT,var1, sz1, var2, sz2)



// ============== ASERT =====================

#define ASSERT_ARRAY_NE_TYPE_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_U_CHAR(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_U_CHAR,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_U_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_U_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_U_L_INT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_U_L_INT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_SIZE_T(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_SIZE_T,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_FLOAT(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_FLOAT,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_L_DOUBLE(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_L_DOUBLE,var1, sz1, var2, sz2)
#define ASSERT_ARRAY_NE_TYPE_STRING(var1, sz1, var2, sz2) 	HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_STRING,var1, sz1, var2, sz2)

#define ASSERT_ARRAY_NE(var1, sz1, var2, sz2)  HANDLE_OP_ASSERT_ARRAY_(NE, TYPE_L_INT,var1, sz1, var2, sz2)

// ************************ end NE  **********************

/*
 * ==============  bool ===================
 * bellow old combined EXPECT_ARRAY and ASSERT_ARRAY macros
 */

#define HANDLE_EXPECT_ARRAY_NOT_EXPECT_ARRAY_ASSERT_ARRAY(expect,not_expect,var1,is_assert)                             \
do{                                                                                               \
   if(is_parallel_nb==0){\
      if(expected_array_##expect##_f(var1)){                                                                \
        PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);                             \
      }                                                                                               \
      else{                                                                                           \
        PRINT_LOC("Failure\nValue of: %s\nActual: %s\nExpected: %s\n\n", #var1, #not_expect, #expect);\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                 \
        if(is_assert) return;                                                                         \
      }                                                                                               \
  }\
  else{\
      if(expected_array_##expect##_f_name(var1, __func__)){                                                                \
        PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);                             \
      }                                                                                               \
      else{                                                                                           \
        PRINT_LOC("Failure\nValue of: %s\nActual: %s\nExpected: %s\n\n", #var1, #not_expect, #expect);\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n",__func__);                                 \
        if(is_assert) return;                                                                         \
      }                                                                                               \
  }\
}while(0);

// *******************************************************************************************************
/*
 * new macro HANDEL ASSERT_ARRAY and EXPECT_ARRAY separated
 */
#define HANDLE_EXPECT_ARRAY_NOT_EXPECT_ARRAY_(expect,not_expect,var1)                                             \
do{                                                                                                   \
   if(is_parallel_nb==0){                                                                             \
      if(expected_array_##expect##_f(var1)){                                                                \
        PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);                             \
      }                                                                                               \
      else{                                                                                           \
        PRINT_LOC("Failure\nValue of: %s\nActual: %s\nExpected: %s\n", #var1, #not_expect, #expect);  \
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n\n",__func__);                               \
      }                                                                                               \
  }                                                                                                   \
  else{                                                                                               \
    size_t id_thread=id_of_thread_executed();                                                         \
      if(expected_array_##expect##_f_name(var1, __func__)){                                                 \
        PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s, on thread[%ld]\n\n",__func__,id_thread);    \
      }                                                                                               \
      else{                                                                                           \
        PRINT_LOC("Failure\nValue of: %s\nActual: %s\nExpected: %s\n", #var1, #not_expect, #expect);  \
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s, on thread[%ld]\n\n",__func__,id_thread);      \
      }                                                                                               \
  }                                                                                                   \
}while(0);


#define HANDLE_ASSERT_ARRAY_EXPECT_ARRAY_NOT_EXPECT_ARRAY_(expect,not_expect,var1)                                      \
do{                                                                                                   \
   if(is_parallel_nb==0){                                                                             \
      if(expected_array_##expect##_f(var1)){                                                                \
        PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s \n\n",__func__);                             \
      }                                                                                               \
      else{                                                                                           \
        PRINT_LOC("Failure\nValue of: %s\nActual: %s\nExpected: %s\n", #var1, #not_expect, #expect);  \
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s \n\n",__func__);                               \
        return;                                                                                       \
      }                                                                                               \
  }\
  else{\
    size_t id_thread=id_of_thread_executed();                                                         \
      if(expected_array_##expect##_f_name(var1, __func__)){                                                 \
        PRINT_HK_C(colors_f[k_GREEN],tab_hk_f[hk_TR]," 1 test passed from %s, on thread[%ld]\n\n",__func__,id_thread);    \
      }                                                                                               \
      else{                                                                                           \
        PRINT_LOC("Failure\nValue of: %s\nActual: %s\nExpected: %s\n\n", #var1, #not_expect, #expect);\
        PRINT_HK_C(colors_f[k_RED],tab_hk_f[hk_TR]," 1 test failed from %s, on thread[%ld]\n\n",__func__, id_thread);     \
        return;                                                                                       \
      }                                                                                               \
  }\
}while(0);


// *******************************************************************************************************  
#define EXPECT_ARRAY_TRUE(var1) HANDLE_EXPECT_ARRAY_NOT_EXPECT_ARRAY_(true, false, var1)
#define EXPECT_ARRAY_FALSE(var1) HANDLE_EXPECT_ARRAY_NOT_EXPECT_ARRAY_(false, true, var1)

#define ASSERT_ARRAY_TRUE(var1) HANDLE_ASSERT_ARRAY_EXPECT_ARRAY_NOT_EXPECT_ARRAY_(true, false, var1)
#define ASSERT_ARRAY_FALSE(var1) HANDLE_ASSERT_ARRAY_EXPECT_ARRAY_NOT_EXPECT_ARRAY_(false, true, var1)


//********************************************************************************
#endif /* __TEST_ARRAY_C_H__ */
