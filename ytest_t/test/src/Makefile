
NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(shell pwd)
YTESTDIR=$(ROOT_DIR)/../..
INCLUDE_DIR=$(YTESTDIR)/include_ytest/include/
PERMDIR=$(ROOT_DIR)/../../../ypermutation_t
CFLAGS=-I$(INCLUDE_DIR) -I$(PERMDIR)/src/
LDFLAGS=-L$(YTESTDIR)  -lpthread -lytest
SRC_DIR=$(ROOT_DIR)
SRC=$(wildcard src/*/*.c) 
OBJ=$(SRC:.c=.o)
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(ROOT_DIR)
EXECSRC=$(TEST_DIR)/$(NAME_TEST).c
EXEC=$(ROOT_DIR)/launch_$(NAME_TEST)
PERMSRC=$(wildcard perm*/*perm*.c)
PERMSRC_O=$(PERMSRC:.c=.o)
SETTSRC=$(wildcard set*/set*.c)
SETTSRC_O=$(SETTSRC:.c=.o)
TOOLSRC=$(wildcard too*/tool*.c)
TOOLSRC_O=$(TOOLSRC:.c=.o)
TESTSRC=$(wildcard *test*/*test*.c)
TESTSRC_O=$(TESTSRC:.c=.o)


all: $(EXEC)

$(EXEC):	$(EXECSRC) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)


$(TESTSRC_O): $(TESTSRC) $(TOOLSRC_O) 
	$(CC) -o $@ -c $< $(CFLAGS)

$(PERMSRC_O): $(PERMSRC) $(SETTSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

$(SETTSRC_O) : $(SETTSRC) $(TOOLSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

$(TOOLSRC_O): $(TOOLSRC) 
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJS)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC)
