
CC=gcc
TOOLDIR=$(PWD)/../ytools_t
PERMDIR=$(PWD)/../ypermutation_t

DIMDIR=$(PWD)/../dimension_t

INCLUDE_TENS=$(PWD)/src
INCLUDE_PERMDIR=$(PERMDIR)/src 
INCLUDE_DIMDIR=$(DIMDIR)/src 
INCLUDE_TOOLDIR=$(TOOLDIR)/include
CFLAGS=-I$(INCLUDE_TOOLDIR) -I$(INCLUDE_PERMDIR) -I$(INCLUDE_DIMDIR) -I$(INCLUDE_TENS) -lpthread

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
#HEADS=$(OBJS:.o=.h)



DIMSRC_O=$(DIMDIR)/src/dimension_t/dimension_t.o

TENSRC=src/tensor_t/tensor_t.c
TENSRC_O=$(TENSRC:.c=.o)

clTENSRC=src/tensor_t/cl_tensor_t.c
clTENSRC_O=$(clTENSRC:.c=.o)

PERMSRC_O=$(PERMDIR)/src/permutation_t/permutation_t.o

#TOOLSRC_O=$(TOOLDIR)/src/tools_t/tools_t.o
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)

#SRC=$(wildcard **/**/*.c) 
#OBJ=$(SRC:.c=.o) #$(TOOLSRC_O) 
OBJ=$(TENSRC_O)

TOPTARGETS := all clean
DEP=$(DIMDIR) $(PERMDIR)

$(TOPTARGETS): $(DEP)

all: $(TENSRC_O) $(clTENSRC_O) 

$(TENSRC_O) : $(TENSRC) $(DIMSRC_O) $(PERMSRC_O)
	$(CC) -o $@ -c $^ $(CFLAGS)

$(clTENSRC_O) : $(clTENSRC) $(TENSRC_O) 
	$(CC) -o $@ -c $< $(CFLAGS)

#$(DIMSRC_O) : $(DIMSRC) $(PERMSRC_O)
#	$(CC) -o $@ -c $< $(CFLAGS)

$(DEP):
	$(MAKE) -C $@ $(MAKECMDGOALS)

#$(TOOLSRC_O): $(TOOLSRC) 
#	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
