# file: dimension_t/Makefile
CC=gcc
ROOTPROJECTDIR:=$(realpath ..)
TOOLDIR=$(ROOTPROJECTDIR)/ytools_t
PERMDIR=$(ROOTPROJECTDIR)/ypermutation_t
LISTDIR=$(ROOTPROJECTDIR)/list_t

INCLUDE_PERMDIR=$(PERMDIR)/src 
INCLUDE_TOOLDIR=$(TOOLDIR)/include
CFLAGS=-I$(INCLUDE_TOOLDIR) -I$(INCLUDE_PERMDIR) -I./src -I$(LISTDIR)/src

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
#HEADS=$(OBJS:.o=.h)



DIMSRC=src/dimension_t/dimension_t.c
DIMSRC_O=$(DIMSRC:.c=.o)

PERMSRC_O=$(PERMDIR)/src/permutation_t/permutation_t.o

#TOOLSRC_O=$(TOOLDIR)/src/tools_t/tools_t.o
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)

#SRC=$(wildcard **/**/*.c) 
#OBJ=$(SRC:.c=.o) #$(TOOLSRC_O) 

OBJ=$(DIMSRC_O) $(PERMSRC_O) 

TOPTARGETS := all clean
DEP=$(PERMDIR) $(LISTDIR)

$(TOPTARGETS): $(DEP)

all: $(DIMSRC_O)


$(DEP):
	$(MAKE) -C $@ $(MAKECMDGOALS)

$(DIMSRC_O) : $(DIMSRC) $(PERMSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

#$(TOOLSRC_O): $(TOOLSRC) 
#	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
