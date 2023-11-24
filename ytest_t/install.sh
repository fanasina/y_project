#!/bin/bash

cp libytest.so /usr/lib/
if [ -d /usr/local/include ] ; then
    echo "copy include to /usr/local/include/" ;
    cp -r include_ytest/include/* /usr/local/include/;
else
    echo "copy include to /usr/include/" ;
    cp -r include_ytest/include/* /usr/include/;
fi


