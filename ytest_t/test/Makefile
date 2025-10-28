
ROOTPROJECTDIR:=$(realpath ../..)


NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(ROOTPROJECTDIR)/ytest_t
INCLUDE_DIR=$(ROOT_DIR)/src
CFLAGS=-Wall -Werror -fpic -I$(INCLUDE_DIR) -I$(ROOT_DIR)/include_ytest/include 
LDFLAGS=-L$(ROOT_DIR) -lytest -lpthread -lm


#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard $(ROOT_DIR)/**/src/**/*.c) 


#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(PWD)
EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m
LIB_YTEST=$(ROOT_DIR)/libytest.so

OBJ=$(SRC:.c=.o) 

TOPTARGETS := all clean

all: $(EXEC) $(LIB_YTEST)

$(LIB_YTEST): $(ROOT_DIR)

$(EXEC):	$(EXECSRC) $(OBJ) $(LIB_YTEST)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

DEPS=$(ROOT_DIR)

$(TOPTARGETS): $(DEPS)

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


.PHONY: clean mrproper $(ROOT_DIR)

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC) $(LIB_YTEST)

run: $(EXEC)
	$(EXEC) -h
