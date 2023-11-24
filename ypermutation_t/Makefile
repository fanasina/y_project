



NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(PWD)
INCLUDE_DIR=$(ROOT_DIR)/src
CFLAGS=-I$(INCLUDE_DIR) -I../include_ytest/include
LDFLAGS=-L$(PWD)/.. -lytest

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
OBJ=$(SRC:.c=.o)
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(PWD)
EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m
PERMSRC=src/permutation_t/permutation_t.c
PERMSRC_O=$(PERMSRC:.c=.o)
SETTSRC=src/set_theoric_t/set_theoric_t.c
SETTSRC_O=$(SETTSRC:.c=.o)
TOOLSRC=../ytools_t/src/tools_t/tools_t.c
TOOLSRC_O=$(TOOLSRC:.c=.o)

LIB_YTEST=$(PWD)/../libytest.so

all: $(EXEC) $(LIB_YTEST)

$(EXEC):	$(EXECSRC) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

$(PERMSRC_O): $(PERMSRC) $(SETTSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

$(SETTSRC_O) : $(SETTSRC) $(TOOLSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

$(TOOLSRC_O): $(TOOLSRC) 
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
