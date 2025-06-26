



NAME_TEST=is_good
CC=gcc
YTESTDIR=$(PWD)/../../ytest_t
YLISTDIR=$(PWD)/../../list_t
YWORKDIR=$(PWD)/../../y_worker_t

ROOT_DIR=$(PWD)/..
INCLUDE_DIR=$(ROOT_DIR)/include
CFLAGS=-I$(INCLUDE_DIR) -I$(YTESTDIR)/include_ytest/include -I$(YLISTDIR)/src -I$(YWORKDIR)/include
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

YNODESRC=$(ROOT_DIR)/src/y_socket_t/y_node_t.c
YNODESRC_O=$(YNODESRC:.c=.o)

YLISTSRC=$(YLISTDIR)/src/list_t/list_t.c
YLISTSRC_O=$(YLISTSRC:.c=.o)

YWORKSRC_0=$(YWORKDIR)/src/y_worker_t/y_worker_t.o
YTASKSRC_0=$(YWORKDIR)/src/y_worker_t/y_task_t.o


TOPTARGETS := all clean

DEPS := $(YTESTDIR) $(YLISTDIR) $(YWORKDIR)  $(ROOT_DIR)

OBJ=$(YSOCKSRC_O) $(YNODESRC_O) $(YLISTSRC_O) $(YWORKSRC_0) $(YTASKSRC_0)


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

.PHONY: all clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
