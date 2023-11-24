#!/bin/bash

export CPATH=$PWD/include_ytest/include:$CPATH
export LD_LIBRARY_PATH=$PWD:$LD_LIBRARY_PATH

if [ "$#" -le 0 ] ; then
  echo "if need permanent config"
  echo "Usage: $0 file_name" >&2
  echo "for example: $0 ~/.bashrc" >&2
  echo "or an other bash profile, here it is \"~/.bashrc\" for example"
else
  echo "export CPATH=$PWD/include_ytest/include:\$CPATH" >> $1
  echo "export LD_LIBRARY_PATH=$PWD:\$LD_LIBRARY_PATH" >> $1
  source $1
fi

