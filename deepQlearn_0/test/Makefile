



NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(PWD)
YTESTDIR=$(PWD)/../../ytest_t
YTOOLDIR=$(PWD)/../../ytools_t
YPERMDIR=$(PWD)/../../ypermutation_t
DIMDIR=$(PWD)/../../dimension_t

TENSDIR=$(PWD)/../../tensor_t

NEURODIR=$(PWD)/../../neuron_t
INCLUDE_DIR=$(PWD)/../src/deepQlearning
CFLAGS=-I$(INCLUDE_DIR) -I$(NEURODIR)/src -I$(YPERMDIR)/src -I$(YTESTDIR)/include_ytest/include -I$(DIMDIR)/src -I$(TENSDIR)/src -I$(YTOOLDIR)/include #"-D DEBUG=1"
LDFLAGS=-L$(YTESTDIR) -lytest -lOpenCL -lm -lpthread  #-lcurses

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(PWD)

EXECSRC=$(NAME_TEST).c 
#EXECSRC=openF.c

EXEC=launch_$(NAME_TEST)_m

NEUROSRC=$(NEURODIR)/src/neuron_t/neuron_t.c
NEUROSRC_O=$(NEUROSRC:.c=.o)


TENSRC=$(TENSDIR)/src/tensor_t/tensor_t.c
TENSRC_O=$(TENSRC:.c=.o)

VEHICLESRC=$(INCLUDE_DIR)/vehicle.c
VEHICLESRC_O=$(VEHICLESRC:.c=.o)


TOOLSRC_O=$(YTOOLDIR)/src/tools_t/tools_t.o

PERMSRC_O=$(YPERMDIR)/src/permutation_t/permutation_t.o

DIMSRC_O=$(DIMDIR)/src/dimension_t/dimension_t.o

TOPTARGETS := all clean 

DEPS=$(DIMDIR) $(YPERMDIR) $(YTESTDIR) $(TENSDIR) $(NEURODIR) $(YTOOLDIR)

OBJ=$(VEHICLESRC_O) $(DIMSRC_O) $(PERMSRC_O) $(TENSRC_O) $(NEUROSRC_O) $(TOOLSRC_O)

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

$(VEHICLESRC_O): $(VEHICLESRC) $(TOOLSRC_O) $(DIMSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS) 


.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
