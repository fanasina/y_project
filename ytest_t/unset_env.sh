#!/bin/bash

LD_LIBRARY_PATH=$(echo $LD_LIBRARY_PATH | sed "s@$PWD:@@g")
CPATH=$(echo $CPATH | sed "s@$PWD/include_ytest/include:@@g")

if [ "$#" -le 0 ] ; then
  echo "If need permanent unset env "
  echo "Usage: $0 file_name"
  echo "for example: $0 ~/.bashrc" >&2
  echo "or other bash profile ( here : \"~/.bashrc\" for example), the same file you have set with set_env.sh"
fi


if [ "$#" -ge 1 ] ; then
  sed -i "\@export CPATH=$PWD/include_ytest/include:\$CPATH@d" "$1"
  sed -i "\@export LD_LIBRARY_PATH=$PWD:\$LD_LIBRARY_PATH@d"  "$1"
  
fi
