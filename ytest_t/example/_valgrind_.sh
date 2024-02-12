#!/bin/sh

if [ "$#" -ge 2 ] ; then
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=$2 \
         $1
fi

if [ "$#" -eq 1 ] ; then
valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         $1
fi
