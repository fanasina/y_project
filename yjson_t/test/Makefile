



NAME_TEST=is_good
CC=gcc
ROOT_DIR=$(PWD)
YTESTDIR=$(PWD)/../../ytest_t
LISTDIR=$(PWD)/../../list_t
INCLUDE_LIST=$(LISTDIR)/src

INCLUDE_DIR=$(PWD)/../src
CFLAGS=-I$(INCLUDE_DIR) -I$(INCLUDE_LIST)  -I$(YTESTDIR)/include_ytest/include 
LDFLAGS=-L$(YTESTDIR) -lytest

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(PWD)
EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m


LISTSRC_O=$(LISTDIR)/src/list_t/list_t.o

JSONDIR=$(PWD)/..
JSONSRC=$(JSONDIR)/src/json_t/json_t.c
JSONSRC_O=$(JSONDIR)/src/json_t/json_t.o


TOPTARGETS := all clean 

DEPS=$(LISTDIR) $(YTESTDIR) $(JSONDIR)

$(TOPTARGETS): $(DEPS) 

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


#LISTSRC_O=$(LISTSRC:.c=.o)
#SETTSRC_O=$(PWD)/../src/set_theoric_t/set_theoric_t.o
#SETTSRC_O=$(SETTSRC:.c=.o)
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)

OBJ=$(SRC:.c=.o) $(JSONSRC_O)
#$(LISTSRC_O) 


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
