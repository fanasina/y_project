#!/bin/bash

rm /usr/lib/libytest.so
if [ -d /usr/local/include ] ; then
   echo "remove from /usr/local/include/" ;
   rm -r /usr/local/include/ftest ;
   rm -r /usr/local/include/fmock ;
   rm -r /usr/local/include/bar_progress ;
   rm -r /usr/local/include/tools_t ;
else
   echo "remove from /usr/include/" ;
   rm -r /usr/include/ftest ;
   rm -r /usr/include/fmock ;
   rm -r /usr/include/bar_progress ;
   rm -r /usr/include/tools_t ;
fi

