#file: y_socket_t/test/Makefil
ROOTPROJECTDIR:=$(realpath ../..)


NAME_TEST=is_good
CC=gcc
YTESTDIR=$(ROOTPROJECTDIR)/ytest_t
YLISTDIR=$(ROOTPROJECTDIR)/list_t
YWORKDIR=$(ROOTPROJECTDIR)/y_worker_t
YJSONDIR=$(ROOTPROJECTDIR)/yjson_t

ROOT_DIR=$(ROOTPROJECTDIR)/y_socket_t
INCLUDE_DIR=$(ROOT_DIR)/include
INCLUDE=-I$(INCLUDE_DIR) -I$(YTESTDIR)/include_ytest/include -I$(YLISTDIR)/src -I$(YWORKDIR)/include -I$(YJSONDIR)/src
CFLAGS=-Wall -Werror -fpic $(INCLUDE)
LDFLAGS=-L$(YTESTDIR) -lytest -lpthread -lm -lOpenCL

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
#SRC=$(wildcard **/**/*.c) 

#OBJ=$(SRC:.c=.o)

#HEADS=$(OBJS:.o=.h)
#TEST_DIR=$(PWD)

EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m

YSOCKSRC=$(ROOT_DIR)/src/y_socket_t/y_socket_t.c
YSOCKSRC_O=$(YSOCKSRC:.c=.o)

YFILEHANDLSRC=$(ROOT_DIR)/src/y_socket_t/y_file_handler.c
YFILEHANDLSRC_O=$(YFILEHANDLSRC:.c=.o)

YNODESRC=$(ROOT_DIR)/src/y_socket_t/y_node_t.c
YNODESRC_O=$(YNODESRC:.c=.o)

YY_STRINGSRC=$(ROOT_DIR)/src/y_socket_t/y_list_var_tool.c
YY_STRINGSRC_O=$(YY_STRINGSRC:.c=.o)

YLISTSRC=$(YLISTDIR)/src/list_t/list_t.c
YLISTSRC_O=$(YLISTSRC:.c=.o)

YWORKSRC_0=$(YWORKDIR)/src/y_worker_t/y_worker_t.o
YTASKSRC_0=$(YWORKDIR)/src/y_worker_t/y_task_t.o

YJSONSRC=$(YJSONDIR)/src/json_t/json_t.c
YJSONSRC_O=$(YJSONSRC:.c=.o)

TOPTARGETS := all clean

DEPS := $(YTESTDIR) $(YLISTDIR) $(YWORKDIR)  $(ROOT_DIR) $(YJSONDIR)

OBJ=$(YSOCKSRC_O)  $(YFILEHANDLSRC_O) $(YNODESRC_O) $(YY_STRINGSRC_O) $(YLISTSRC_O) $(YWORKSRC_0) $(YTASKSRC_0) $(YJSONSRC_O)


LIB_YTEST=$(YTESTDIR)/libytest.so

LIB_YSOCK=$(ROOT_DIR)/libysocket.so

all: $(EXEC) $(LIB_YSOCK)  

$(TOPTARGETS): $(DEPS)

$(DEPS):  
	$(MAKE) -C $@ $(MAKECMDGOALS)

$(LIB_YTEST): $(YTESTDIR)

$(LIB_YSOCK): $(ROOT_DIR)


$(EXEC):	$(EXECSRC) $(OBJ) $(LIB_YTEST)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: all clean mrproper $(YTESTDIR) $(ROOT_DIR)

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
