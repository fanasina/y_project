#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// for sleep !
#ifdef __linux__ 
  #include <unistd.h>
#elif _WIN32 
  #include <windows.h>
#endif

#include "ftest/ftest.h"
#include "ftest/ftest_array.h"
#include "fmock/fmock.h"

#include "y_net_neur_net/y_nnn_manager.h"
#include "y_net_neur_net/y_nnn_screen_manager.h"

TEST(pidof_bash){
   
}


int main(int argc, char **argv){
  

  run_all_tests_args(argc, argv);

  return 0;
}
