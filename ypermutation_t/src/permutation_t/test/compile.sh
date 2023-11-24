#!/bin/bash

if [ "$#" -le 0 ] ; then
  echo "Usage: $0 \"compile flags or prepossession \" " >&2
  echo " we can add more option for example '-D DEBUG=1' to have debug print, '-D HK' to have gtest like prompt, od '-g' to gbd" >&2
  echo "for example: $0 \"-D DEBUG=1 -D HK -g\""
fi

src=../..

#echo "gcc -o launch_is_good_c $1 -L../../$src/ $2 -lytest -I../../$src/include_ytest/include $src/permutation_t/permutation_t.c $src/set_theoric_t/set_theoric_t.c -I$src "
gcc -o launch_is_good_c is_good.c -L../../$src/ $1 -lytest -I../../$src/include_ytest/include $src/permutation_t/permutation_t.c $src/set_theoric_t/set_theoric_t.c -I./$src 

