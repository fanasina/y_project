#!/bin/bash

if [ "$#" -le 0 ] ; then
  echo "Usage: $0 is_good.c" >&2
  echo "for example to compile: is_good.c" >&2
  exit 1
fi
if [ "$#" -le 1 ] ; then
  echo "Usage: $0 $1" >&2
  echo " we can add more option for example '-D DEBUG=1' to have debug print, '-D HK' to have gtest like prompt, od '-g' to gbd" >&2
  echo "for example: $0 $1 \"-D DEBUG=1 -D HK -g\""
fi



gcc -o launch_is_good_c $1 -L$PWD/../ytest_t/ $2 -lytest -I../include_ytest/include src/permutation_t/permutation_t.c src/set_theoric_t/set_theoric_t.c -I./src 
#gcc -o launch_is_good_c $1 $2 -lytest -I../include_ytest src/permutation_t/permutation_t.o src/set_theoric_t/set_theoric_t.o -I./src 

export LD_LIBRARY_PATH=$PWD/../ytest_t:LD_LIBRARY_PATH


#gcc $1 src/ftest/ftest.c src/fmock/fmock.c src/tools_t/tools_t.c src/bar_progress/bar_progress.c src/permutation_t/permutation_t.c src/set_theoric_t/set_theoric_t.c -I./include $2 -o launch_is_good_c -lpthread 
