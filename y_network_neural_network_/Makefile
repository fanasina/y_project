#file: y_network_neural_network_/Makefile
# lib: -lynetneurnet
PROJECT_LIB=libynetneurnet.so
CC=gcc
NETNEURNETDIR=$(PWD)

ROOTPROJECTDIR=$(PWD)/..

#$(wildcard $(PWD)/**/include)

YLISTDIR=$(PWD)/../list_t
YWORKDIR=$(PWD)/../y_worker_t
YJSONDIR=$(PWD)/../yjson_t
#YSOCKETDIR=$(YSOCKET_DIR) 
YSOCKET_DIR=$(PWD)/../y_socket_t

INCLUDE_SOCKET=-I$(YSOCKET_DIR)/include -I$(YLISTDIR)/src -I$(YWORKDIR)/include -I$(YJSONDIR)/src -I$(YSOCKET_DIR)/include 

LIB_SOCKET=$(YSOCKET_DIR)/libysocket.so

YSOCKSRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_socket_t.o

YNODESRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_node_t.o

YY_STRINGSRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_list_var_tool.o

YFILEHANDLERSRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_file_handler.o

YLISTSRC_O=$(YLISTDIR)/src/list_t/list_t.o

WORKSRC_0=$(YWORKDIR)/src/y_worker_t/y_worker_t.o
YTASKSRC_0=$(YWORKDIR)/src/y_worker_t/y_task_t.o

YJSONSRC_O=$(YJSONDIR)/src/json_t/json_t.o


DEPS_SOCKET:=$(YLISTDIR) $(YWORKDIR) $(YJSONDIR) $(YSOCKET_DIR)

OBJ_SOCKET=$(YSOCKSRC_O) $(YNODESRC_O) $(YY_STRINGSRC_O) $(YLISTSRC_O) $(WORKSRC_0) $(YTASKSRC_0) $(YFILEHANDLERSRC_O) $(YJSONSRC_O) 



#CC=gcc
DEEPQLEARNDIR=$(PWD)/../deepQlearn_0
LIB_DEEPQLEARN=$(DEEPQLEARNDIR)/libdeepqlearn.so

YTESTDIR=$(PWD)/../ytest_t
YTOOLDIR=$(PWD)/../ytools_t
YPERMDIR=$(PWD)/../ypermutation_t
DIMDIR=$(PWD)/../dimension_t

TENSDIR=$(PWD)/../tensor_t
LISTDIR=$(PWD)/../list_t

NEURODIR=$(PWD)/../neuron_t

#DEEPQLEARN_SRC_DIR=$(PWD)/src/deepQlearning
INCLUDE_DEEPQLEARN=-I$(DEEPQLEARNDIR)/src/deepQlearning -I$(NEURODIR)/src -I$(YPERMDIR)/src -I$(YTESTDIR)/include_ytest/include -I$(DIMDIR)/src -I$(TENSDIR)/src -I$(YTOOLDIR)/include -I$(LISTDIR)/src
#CFLAGS=-I$(DEEPQLEARN_SRC_DIR) -I$(NEURODIR)/src -I$(YPERMDIR)/src -I$(YTESTDIR)/include_ytest/include -I$(DIMDIR)/src -I$(TENSDIR)/src -I$(YTOOLDIR)/include -I$(LISTDIR)/src
 #"-D DEBUG=1"


#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
#TEST_DIR=$(PWD)

EXECSRC=$(NAME_TEST).c 
#EXECSRC=openF.c

EXEC=launch_$(NAME_TEST)_m

NEUROSRC_O=$(NEURODIR)/src/neuron_t/neuron_t.o

TENSRC_O=$(TENSDIR)/src/tensor_t/tensor_t.o

DEEPQLEARN_SRC_DIR=$(DEEPQLEARNDIR)/src/deepQlearning

VEHICLESRC_O=$(DEEPQLEARN_SRC_DIR)/vehicle.o

LEARNTODRIVESRC_O=$(DEEPQLEARN_SRC_DIR)/learn_to_drive.o

TOOLSRC_O=$(YTOOLDIR)/src/tools_t/tools_t.o

PERMSRC_O=$(YPERMDIR)/src/permutation_t/permutation_t.o

DIMSRC_O=$(DIMDIR)/src/dimension_t/dimension_t.o

LISTSRC_O=$(LISTDIR)/src/list_t/list_t.o


TOPTARGETS := all clean 

DEPS_DEEPQLEARN=$(DIMDIR) $(YPERMDIR) $(YTESTDIR) $(TENSDIR) $(NEURODIR) $(YTOOLDIR) #$(LISTDIR)

OBJ_DEEPQLEARN=$(VEHICLESRC_O) $(DIMSRC_O) $(PERMSRC_O) $(TENSRC_O) $(NEUROSRC_O) $(TOOLSRC_O) $(LEARNTODRIVESRC_O) #$(LISTSRC_O)


LIB_YTEST=$(YTESTDIR)/libytest.so

#all: $(LIB_DEEPQLEARN)
all: $(PROJECT_LIB) 

TOPTARGETS := all clean 

DEPS=$(DEPS_SOCKET) $(DEPS_DEEPQLEARN)

$(TOPTARGETS): $(DEPS)




INCLUDE=$(INCLUDE_SOCKET) $(INCLUDE_DEEPQLEARN)

CFLAGS=-Wall -lOpenCL -lm -lpthread -Werror -fpic $(INCLUDE) #-lcurses
#LDFLAGS=-L$(YTESTDIR) -lytest -lOpenCL -lm -lpthread  #-lcurses


#CFLAGS=-g -lpthread -Wall -Werror -fpic $(INCLUDE) #"-D DEBUG=1" 
#LDFLAGS=

OBJ=$(OBJ_DEEPQLEARN) $(OBJ_SOCKET) 


$(PROJECT_LIB): $(OBJ) #$(LIB_SOCKET) $(LIB_DEEPQLEARN)
	echo "objects:" $(OBJ)
	#$(CC) -shared -o $@ $^ $(INCLUDE) $(LDFLAGS)
	#$(CC) -shared -o $@ $^ $(LDFLAGS)
	$(CC) -shared -o $@ $^ $(CFLAGS)

# .PHONY: $(TOPTARGETS) $(SUBDIRS)


$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: all clean

clean: 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(PROJECT_LIB)

