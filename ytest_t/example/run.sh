#!/bin/bash

if [ "$#" -le 0 ] ; then
  echo "usage : $0 <option>"
  echo "for example: $0 \"-p=3 -r\""
fi

LD_LIBRARY_PATH=.. ./x1 $1
