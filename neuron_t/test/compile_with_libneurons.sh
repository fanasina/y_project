#!/bin/sh

gcc -o c_launch is_good.c -I../include_neurons/include/ -L.. -L../../ytest_t/  -lneurons  -lytest  -lpthread -lm
