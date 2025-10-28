# file neuron_t/test/Makefile
# is_good.c 
ROOTPROJECTDIR:=$(realpath ../..)

NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(ROOTPROJECTDIR)/neuron_t
YTESTDIR=$(ROOTPROJECTDIR)/ytest_t
YPERMDIR=$(ROOTPROJECTDIR)/ypermutation_t

TENSDIR=$(ROOTPROJECTDIR)/tensor_t

NEURODIR=$(ROOT_DIR)
DIMDIR=$(ROOTPROJECTDIR)/dimension_t
INCLUDE_DIR=$(ROOT_DIR)/src
CFLAGS=-I$(INCLUDE_DIR) -I$(YPERMDIR)/src -I$(YTESTDIR)/include_ytest/include -I$(DIMDIR)/src -I$(TENSDIR)/src #"-D DEBUG=1"
LDFLAGS=-L$(YTESTDIR) -lytest -lOpenCL -lm -lpthread

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(ROOT_DIR)/test

EXECSRC=$(NAME_TEST).c
#EXECSRC=openF.c

EXEC=launch_$(NAME_TEST)_m

NEUROSRC=$(NEURODIR)/src/neuron_t/neuron_t.c
NEUROSRC_O=$(NEUROSRC:.c=.o)


TENSRC=$(TENSDIR)/src/tensor_t/tensor_t.c
TENSRC_O=$(TENSRC:.c=.o)

PERMSRC_O=$(YPERMDIR)/src/permutation_t/permutation_t.o

DIMSRC_O=$(DIMDIR)/src/dimension_t/dimension_t.o

TOPTARGETS := all clean 

DEPS=$(DIMDIR) $(YPERMDIR) $(YTESTDIR) $(TENSDIR) $(NEURODIR)

OBJ=$(DIMSRC_O) $(PERMSRC_O) $(TENSRC_O) $(NEUROSRC_O)

LIB_YTEST=$(YTESTDIR)/libytest.so


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

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
