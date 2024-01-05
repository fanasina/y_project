#!/bin/bash

if [ "$#" -le 0 ] ; then
  echo "Usage: $0 is_good.c" >&2
  echo "for example to compile: is_good.c" >&2
  exit 1
fi

if [ "$#" -le 1 ] ; then
  echo "Usage: $0 $1" >&2
  echo "we can add more option for example '-D DEBUG=1' to have debug print of PRINT_DEBUG_ (tools_t macro), notice that PRINT_DEBUG is provide by ytest and can be activate with --debug option on runtime." 
  echo "The other compile option is '-g' to have gbd, and so on..."
  echo "for example: $0 $1 \"-D DEBUG=1 -g\""
fi

YTESTDIR=$PWD/../ytest_t

gcc -o launch_is_good_c $1 -L$YTESTDIR $2 -lytest -lOpenCL -I$YTESTDIR/include_ytest/include  
echo "gcc -o launch_is_good_c $1 -L$YTESTDIR $2 -lytest -I$YTESTDIR/include_ytest/include"  

export LD_LIBRARY_PATH=$YTESTDIR:LD_LIBRARY_PATH


