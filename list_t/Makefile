
CC=gcc
TOOLDIR=$(PWD)/../ytools_t

INCLUDE_DIR=$(TOOLDIR)/include
CFLAGS=-I$(INCLUDE_DIR) -I./src 

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
#HEADS=$(OBJS:.o=.h)

LISTSRC=src/list_t/list_t.c
LISTSRC_O=$(LISTSRC:.c=.o)

SETTSRC=src/set_theoric_t/set_theoric_t.c
SETTSRC_O=$(SETTSRC:.c=.o)


TOOLSRC_O=$(TOOLDIR)/src/tools_t/tools_t.o
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)

SRC=$(wildcard **/**/*.c) 
OBJ=$(SRC:.c=.o) #$(TOOLSRC_O) 

TOPTARGETS := all clean
DEP=$(TOOLDIR)

$(TOPTARGETS): $(DEP)

all: $(LISTSRC_O)


$(LISTSRC_O): $(LISTSRC) $(TOOLSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

#$(SETTSRC_O) : $(SETTSRC) $(TOOLSRC_O)
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
