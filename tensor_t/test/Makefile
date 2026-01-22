# file: tensor_t/test/Makefile

ROOTPROJECTDIR:=$(realpath ../..)

NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(PWD)
YTESTDIR=$(ROOTPROJECTDIR)/ytest_t
YPERMDIR=$(ROOTPROJECTDIR)/ypermutation_t
LISTDIR=$(ROOTPROJECTDIR)/list_t

TENSDIR=$(ROOTPROJECTDIR)/tensor_t
DIMDIR=$(ROOTPROJECTDIR)/dimension_t
INCLUDE_DIR=$(TENSDIR)/src
CFLAGS=-I$(INCLUDE_DIR) -I$(YPERMDIR)/src -I$(YTESTDIR)/include_ytest/include -I$(DIMDIR)/src -I$(TENSDIR)/src -I$(LISTDIR)/src #"-D DEBUG=1"
LDFLAGS=-L$(YTESTDIR) -lytest -lOpenCL

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(TENSDIR)/test

EXECSRC=$(NAME_TEST).c
#EXECSRC=openF.c

EXEC=launch_$(NAME_TEST)_m

TENSRC=$(TENSDIR)/src/tensor_t/tensor_t.c
TENSRC_O=$(TENSRC:.c=.o)



PERMSRC_O=$(YPERMDIR)/src/permutation_t/permutation_t.o

DIMSRC_O=$(DIMDIR)/src/dimension_t/dimension_t.o


DEPS=$(DIMDIR) $(YPERMDIR) $(YTESTDIR) $(TENSDIR)

OBJ=$(DIMSRC_O) $(PERMSRC_O) $(TENSRC_O) 

LIB_YTEST=$(YTESTDIR)/libytest.so

TOPTARGETS := all clean 

$(TOPTARGETS): $(DEPS) 

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


#PERMSRC_O=$(PERMSRC:.c=.o)
#SETTSRC_O=$(PWD)/../src/set_theoric_t/set_theoric_t.o
#SETTSRC_O=$(SETTSRC:.c=.o)
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)


all: $(EXEC) $(LIB_YTEST)

$(EXEC):	$(EXECSRC) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: all clean mrproper

$(LIB_YTEST): $(YTESTDIR)

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
