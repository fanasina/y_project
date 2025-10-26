#file: y_network_neural_network_t/test/Makefile



NAME_TEST=is_good
CC=gcc
YTESTDIR=$(PWD)/../../ytest_t
YLISTDIR=$(PWD)/../../list_t
YWORKDIR=$(PWD)/../../y_worker_t
YJSONDIR=$(PWD)/../../yjson_t

YSOCKETDIR=$(PWD)/../../y_socket_t
INCLUDE_DIR=$(YSOCKETDIR)/include
INCLUDE=-I$(YSOCKETDIR)/include -I$(YLISTDIR)/src -I$(YWORKDIR)/include -I$(YJSONDIR)/src -I$(YTESTDIR)/include_ytest/include
CFLAGS=-Wall -Werror -fpic $(INCLUDE)
LDFLAGS=-L$(YTESTDIR)  -lytest -lpthread -lm -lOpenCL #-L$(YSOCKETDIR) -lysocket

#SRC_DIR=$(YSOCKETDIR)/src
#SRC=$(wildcard */*/*.c) 
#SRC=$(wildcard **/**/*.c) 

#OBJ=$(SRC:.c=.o)

#HEADS=$(OBJS:.o=.h)
#TEST_DIR=$(PWD)

EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m

YSOCKSRC=$(YSOCKETDIR)/src/y_socket_t/y_socket_t.c
YSOCKSRC_O=$(YSOCKSRC:.c=.o)

YFILEHANDLSRC=$(YSOCKETDIR)/src/y_socket_t/y_file_handler.c
YFILEHANDLSRC_O=$(YFILEHANDLSRC:.c=.o)

YNODESRC=$(YSOCKETDIR)/src/y_socket_t/y_node_t.c
YNODESRC_O=$(YNODESRC:.c=.o)

YY_STRINGSRC=$(YSOCKETDIR)/src/y_socket_t/y_list_var_tool.c
YY_STRINGSRC_O=$(YY_STRINGSRC:.c=.o)

YLISTSRC=$(YLISTDIR)/src/list_t/list_t.c
YLISTSRC_O=$(YLISTSRC:.c=.o)

YWORKSRC_0=$(YWORKDIR)/src/y_worker_t/y_worker_t.o
YTASKSRC_0=$(YWORKDIR)/src/y_worker_t/y_task_t.o

YJSONSRC=$(YJSONDIR)/src/json_t/json_t.c
YJSONSRC_O=$(YJSONSRC:.c=.o)

TOPTARGETS := all clean

DEPS := $(YTESTDIR) $(YLISTDIR) $(YWORKDIR)  $(YSOCKETDIR) $(YJSONDIR)

OBJ=$(YSOCKSRC_O)  $(YFILEHANDLSRC_O) $(YNODESRC_O) $(YY_STRINGSRC_O) $(YLISTSRC_O) $(YWORKSRC_0) $(YTASKSRC_0) $(YJSONSRC_O)


LIB_YTEST=$(YTESTDIR)/libytest.so

LIB_YSOCK=$(YSOCKETDIR)/libysocket.so

all: $(EXEC) $(LIB_YSOCK)  

$(TOPTARGETS): $(DEPS)


$(LIB_YTEST): $(YTESTDIR)

$(LIB_YSOCK): $(YSOCKETDIR)

$(DEPS):  
	$(MAKE) -C $@ $(MAKECMDGOALS)

$(EXEC):	$(EXECSRC) $(LIB_YSOCK) $(LIB_YTEST) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: all clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
