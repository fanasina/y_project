#!/bin/bash

objdump -d -M intel $1  > $1_intel.asm

# AT&T syntax
objdump -d $1  > $1_.asm  
