#include "ftest/ftest.h"
#include "fmock/fmock.h"


#include "list_t/list_t.h"


TEST(list_create){
  struct main_list_TYPE_INT * var_list_int = create_var_list_TYPE_INT();

  push_back_list_TYPE_INT(var_list_int, 9);
  push_back_list_TYPE_INT(var_list_int, -9);
  push_back_list_TYPE_INT(var_list_int, 19);

  move_current_to_index_list_TYPE_INT(var_list_int, 0);
  while(var_list_int->current_list){
    LOG("cur %ld : %d : size :%ld \n", var_list_int->current_index, (var_list_int->current_list)->value, var_list_int->size);
    increment_list_TYPE_INT(var_list_int);
  }

  LOG("%s"," =============== \n");
  for(move_current_to_index_list_TYPE_INT(var_list_int, (var_list_int->size) - 1); var_list_int->current_list; decrement_list_TYPE_INT(var_list_int))
    LOG("cur %ld : %d : size :%ld \n", var_list_int->current_index, (var_list_int->current_list)->value, var_list_int->size);

  free_all_var_list_TYPE_INT(var_list_int);

}

TEST(insert){
  struct main_list_TYPE_INT * var_list_int = create_var_list_TYPE_INT();

  for(int i=0; i<5; ++i)
    push_back_list_TYPE_INT(var_list_int, i);

  for(int i=0; i<10; ++i)
    insert_into_list_TYPE_INT(var_list_int, i, -2*i+1);

  for(int i=var_list_int->size; i< 25; ++i)
    insert_into_list_TYPE_INT(var_list_int, i, 3*i+1);
  
  for(move_current_to_index_list_TYPE_INT(var_list_int, 0); var_list_int->current_list; increment_list_TYPE_INT(var_list_int))
    LOG("cur %ld : %d : size :%ld \n", var_list_int->current_index, (var_list_int->current_list)->value, var_list_int->size);

  free_all_var_list_TYPE_INT(var_list_int);
  
}


TEST(remove){
  struct main_list_TYPE_INT * var_list_int = create_var_list_TYPE_INT();

remove_all_list_in_TYPE_INT(var_list_int);

  for(int i=0; i<5; ++i)
    push_back_list_TYPE_INT(var_list_int, i);

  for(int i=0; i<10; ++i)
    insert_into_list_TYPE_INT(var_list_int, i, -2*i+1);

  for(int i=var_list_int->size; i< 25; ++i)
    insert_into_list_TYPE_INT(var_list_int, i, 3*i+1);
  
  for(move_current_to_index_list_TYPE_INT(var_list_int, 0); var_list_int->current_list; increment_list_TYPE_INT(var_list_int))
    LOG("cur %ld : %d : size :%ld \n", var_list_int->current_index, (var_list_int->current_list)->value, var_list_int->size);


  for(int i=1; i<var_list_int->size; i+= 3)
    remove_index_from_list_TYPE_INT(var_list_int, i);
  
  LOG("%s"," =============== \n");

  for(move_current_to_index_list_TYPE_INT(var_list_int, 0); var_list_int->current_list; increment_list_TYPE_INT(var_list_int))
    LOG("cur %ld : %d : size :%ld \n", var_list_int->current_index, (var_list_int->current_list)->value, var_list_int->size);
  
  free_all_var_list_TYPE_INT(var_list_int);
  
}

TEST(remove_All){
  struct main_list_TYPE_INT * var_list_int = create_var_list_TYPE_INT();

  for(int i=0; i<5; ++i)
    push_back_list_TYPE_INT(var_list_int, i);

  for(int i=0; i<10; ++i)
    insert_into_list_TYPE_INT(var_list_int, i, -2*i+1);

  for(int i=var_list_int->size; i< 25; ++i)
    insert_into_list_TYPE_INT(var_list_int, i, 3*i+1);
  
  for(move_current_to_index_list_TYPE_INT(var_list_int, 0); var_list_int->current_list; increment_list_TYPE_INT(var_list_int))
    LOG("cur %ld : %d : size :%ld \n", var_list_int->current_index, (var_list_int->current_list)->value, var_list_int->size);

  remove_all_list_in_TYPE_INT(var_list_int);
  for(int i=0; i<5; ++i)
    push_back_list_TYPE_INT(var_list_int, 10*i);


  
  LOG("%s"," =============== \n");

  for(move_current_to_index_list_TYPE_INT(var_list_int, 0); var_list_int->current_list; increment_list_TYPE_INT(var_list_int))
    LOG("cur %ld : %d : size :%ld \n", var_list_int->current_index, (var_list_int->current_list)->value, var_list_int->size);
  
  free_all_var_list_TYPE_INT(var_list_int);
  
}
/*
struct test_c {
  int value;
  double *Q;
};

*/

//#include "test_c.c"

struct test_c {
  int value;
  double *Q;
};

typedef struct test_c test_c;

//GEN_LIST_ALL(test_c);

//GENERATE_LIST_ALL(test_c);

TEST(list_TYPE_PTR){
   struct main_list_TYPE_PTR * var_list_ptr = create_var_list_TYPE_PTR();

   test_c * t0 = malloc(sizeof(test_c));
   test_c * t1 = malloc(sizeof(test_c));
   test_c * t2 = malloc(sizeof(test_c));

   t0->value = 0;
   t1->value = 1;
   t2->value = 2;

   push_back_list_TYPE_PTR(var_list_ptr,t0);
   push_back_list_TYPE_PTR(var_list_ptr,t1);
   push_back_list_TYPE_PTR(var_list_ptr,t2);

   for(move_current_to_index_list_TYPE_PTR(var_list_ptr, 0); var_list_ptr->current_list; increment_list_TYPE_PTR(var_list_ptr))
    LOG("cur %ld : %d : size :%ld \n", var_list_ptr->current_index, ((test_c*)((var_list_ptr->current_list)->value))->value, var_list_ptr->size);
    

   free_all_var_list_TYPE_PTR(var_list_ptr);
   free(t0);
   free(t1);
   free(t2);

}

LIST_T(test_c)

TEST(list_struct_test_c){
   struct main_list_test_c * var_list_ptr = create_var_list_test_c();

   test_c t0, t1, t2;

   t0.value = 0;
   t1.value = 1;
   t2.value = 2;

   push_back_list_test_c(var_list_ptr,t0);
   push_back_list_test_c(var_list_ptr,t1);
   push_back_list_test_c(var_list_ptr,t2);

   for(move_current_to_index_list_test_c(var_list_ptr, 0); var_list_ptr->current_list; increment_list_test_c(var_list_ptr))
    LOG("cur %ld : %d : size :%ld \n", var_list_ptr->current_index, ((var_list_ptr->current_list)->value).value, var_list_ptr->size);
    

   free_all_var_list_test_c(var_list_ptr);

}



/*
TEST(list_struct_test_c){
   struct main_list_TYPE_PTR * var_list_ptr = create_var_list_TYPE_PTR();

   test_c * t0 = malloc(sizeof(test_c));
   test_c * t1 = malloc(sizeof(test_c));
   test_c * t2 = malloc(sizeof(test_c));

   t0->value = 0;
   t1->value = 1;
   t2->value = 2;

   push_back_list_TYPE_PTR(var_list_ptr,t0);
   push_back_list_TYPE_PTR(var_list_ptr,t1);
   push_back_list_TYPE_PTR(var_list_ptr,t2);

   for(move_current_to_index_list_TYPE_PTR(var_list_ptr, 0); var_list_ptr->current_list; increment_list_TYPE_PTR(var_list_ptr))
    LOG("cur %ld : %d : size :%ld \n", var_list_ptr->current_index, ((test_c*)((var_list_ptr->current_list)->value))->value, var_list_ptr->size);
    

   free_all_var_list_TYPE_PTR(var_list_ptr);

}
*/

int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
