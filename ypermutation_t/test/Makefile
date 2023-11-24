



NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(PWD)
YTESTDIR=$(PWD)/../../ytest_t

INCLUDE_DIR=$(PWD)/../src
CFLAGS=-I$(INCLUDE_DIR) -I$(YTESTDIR)/include_ytest/include
LDFLAGS=-L$(YTESTDIR) -lytest

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(PWD)
EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m

PERMDIR=$(PWD)/..

PERMSRC_O=$(PERMDIR)/src/permutation_t/permutation_t.o

TOPTARGETS := all clean 

DEPS=$(PERMDIR) $(YTESTDIR)

$(TOPTARGETS): $(DEPS) 

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


#PERMSRC_O=$(PERMSRC:.c=.o)
#SETTSRC_O=$(PWD)/../src/set_theoric_t/set_theoric_t.o
#SETTSRC_O=$(SETTSRC:.c=.o)
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)

OBJ=$(SRC:.c=.o) $(PERMSRC_O) 

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
