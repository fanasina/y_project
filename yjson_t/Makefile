
CC=gcc
TOOLDIR=$(PWD)/../ytools_t


#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
#HEADS=$(OBJS:.o=.h)

LISTDIR=$(PWD)/../list_t
LISTSRC=$(LISTDIR)/src/list_t/list_t.c
LISTSRC_O=$(LISTSRC:.c=.o)

YSOCKETDIR=$(PWD)/../y_socket_t/
YSTRINGLISTSRC=$(YSOCKETDIR)/src/y_socket_t/y_list_var_tool.c
YSTRINGLISTSRC_O=$(YSOCKETSRC:.c=.o)

#SETTSRC=src/set_theoric_t/set_theoric_t.c
#SETTSRC_O=$(SETTSRC:.c=.o)

JSONDIR=$(PWD)
JSONSRC=$(JSONDIR)/src/json_t/json_t.c
JSONSRC_O=$(JSONSRC:.c=.o)

TOOLSRC_O=$(TOOLDIR)/src/tools_t/tools_t.o
TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
TOOLSRC_O=$(TOOLSRC:.c=.o)

SRC=$(wildcard **/**/*.c) 
OBJ=$(SRC:.c=.o) $(TOOLSRC_O) $(LISTSRC_O) $(YSOCKETDIR) $(YSTRINGLISTSRC_O)

INCLUDE_DIR=$(TOOLDIR)/include
CFLAGS=-I$(INCLUDE_DIR) -I./src -I$(YSOCKETDIR)/include 

TOPTARGETS := all clean
DEP=$(TOOLDIR) $(LISTDIR) $(YSOCKETDIR)

$(TOPTARGETS): $(DEP)

all: $(JSONSRC_O)


$(JSONSRC_O): $(JSONSRC)  $(TOOLSRC_O) $(YSTRINGLISTSRC_O)  # $(LISTSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)


$(DEP):
	$(MAKE) -C $@ $(MAKECMDGOALS)


.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
