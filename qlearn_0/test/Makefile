



NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(PWD)
FROZENLAKEDIR=$(PWD)/..
YTESTDIR=$(PWD)/../../ytest_t
YPERMDIR=$(PWD)/../../ypermutation_t
DIMDIR=$(PWD)/../../dimension_t
LISTDIR=$(PWD)/../../list_t
TOOLDIR=$(PWD)/../../ytools_t

INCLUDE_DIR=$(PWD)/../src
CFLAGS=-I$(INCLUDE_DIR) -I$(YTESTDIR)/include_ytest/include  -I$(YPERMDIR)/src   -I$(DIMDIR)/src -I$(LISTDIR)/src -I$(TOOLDIR)/include
LDFLAGS=-L$(YTESTDIR) -lytest #"-D DEBUG=1"

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(PWD)
EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m
LISTSRC_O=$(LISTDIR)/src/list_t/list_t.o
TOOLSRC_O=$(TOOLDIR)/src/tools_t/tools_t.o

FROZENLAKESRC=$(FROZENLAKEDIR)/src/Frozen_Lake.c
FROZENLAKESRC_O=$(FROZENLAKESRC:.c=.o)


PERMSRC_O=$(YPERMDIR)/src/permutation_t/permutation_t.o
DIMSRC_O=$(DIMDIR)/src/dimension_t/dimension_t.o


TOPTARGETS := all clean 

DEPS=$(PERMSRC) $(DIMDIR) $(LISTDIR) $(YTESTDIR) $(TOOLDIR)

$(TOPTARGETS): $(DEPS) 

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


OBJ=$(FROZENLAKESRC_O) $(LISTSRC_O) $(PERMSRC_O)  $(DIMSRC_O) $(TOOLSRC_O)

LIB_YTEST=$(YTESTDIR)/libytest.so

all: $(EXEC) $(LIB_YTEST)

$(EXEC):	$(EXECSRC) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(FROZENLAKESRC_O): $(FROZENLAKESRC) $(LISTSRC_O) $(PERMSRC_O)  $(DIMSRC_O) $(TOOLSRC_O)
	$(CC) -o $@ -c $^ $(CFLAGS) 
  
#$(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
