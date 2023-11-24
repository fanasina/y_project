#!/bin/bash

gcc -o x1 eg1.c -I../include_ytest/include/ -L.. -lytest $1
