#!/bin/bash

gcc -o x1 eg1.c -g -I../include_ytest/include/ -L.. -lytest $1
