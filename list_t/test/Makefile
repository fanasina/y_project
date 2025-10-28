# file list_t/test/Makefile

ROOTPROJECTDIR:=$(realpath ../..)

NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(ROOTPROJECTDIR)/list_t
YTESTDIR=$(ROOTPROJECTDIR)/ytest_t

INCLUDE_DIR=$(ROOT_DIR)/src
CFLAGS=-I$(INCLUDE_DIR) -I$(YTESTDIR)/include_ytest/include
LDFLAGS=-L$(YTESTDIR) -lytest

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(ROOT_DIR)/test
EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m

LISTDIR=$(ROOT_DIR)

LISTSRC_O=$(LISTDIR)/src/list_t/list_t.o

TOPTARGETS := all clean 

DEPS=$(LISTDIR) $(YTESTDIR)

$(TOPTARGETS): $(DEPS) 

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


#LISTSRC_O=$(LISTSRC:.c=.o)
#SETTSRC_O=$(PWD)/../src/set_theoric_t/set_theoric_t.o
#SETTSRC_O=$(SETTSRC:.c=.o)
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)

OBJ=$(SRC:.c=.o) $(LISTSRC_O) 

LIB_YTEST=$(YTESTDIR)/libytest.so

all: $(EXEC) $(LIB_YTEST)

$(EXEC):	$(EXECSRC) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
