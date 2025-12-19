#file: y_network_neural_network_/test/Makefile
# lib: -lynetneurnet
CC=gcc
NAME_TEST=is_good
ROOTPROJECTDIR:=$(realpath ../..)
NETNEURNETDIR=$(ROOTPROJECTDIR)/y_network_neural_network_
LIB_NNN=$(NETNEURNETDIR)/libynetneurnet.so

YNETMANAGER_SRC=$(NETNEURNETDIR)/src/y_net_neur_net/y_nnn_manager.c
YNETMANAGER_SRC_O=$(YNETMANAGER_SRC:.c=.o)

YNETSCREENMANAGER_SRC=$(NETNEURNETDIR)/src/y_net_neur_net/y_nnn_screen_manager.c
YNETSCREENMANAGER_SRC_O=$(YNETSCREENMANAGER_SRC:.c=.o)

OBJ_NNN=$(YNETMANAGER_SRC_O) $(YNETSCREENMANAGER_SRC_O)

INCLUDE_NNN=-I$(NETNEURNETDIR)/include


#$(wildcard $(ROOTPROJECTDIR)/include)

YLISTDIR=$(ROOTPROJECTDIR)/list_t
YWORKDIR=$(ROOTPROJECTDIR)/y_worker_t
YJSONDIR=$(ROOTPROJECTDIR)/yjson_t
YSOCKET_DIR=$(ROOTPROJECTDIR)/y_socket_t
#DIMENSIONDIR=$(ROOTPROJECTDIR)/dimension_t

INCLUDE_SOCKET=-I$(YSOCKET_DIR)/include -I$(YLISTDIR)/src -I$(YWORKDIR)/include -I$(YJSONDIR)/src -I$(YSOCKET_DIR)/include #-I$(DIMENSIONDIR)/src

LIB_SOCKET=$(YSOCKET_DIR)/libysocket.so

YSOCKSRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_socket_t.o

YNODESRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_node_t.o

YY_STRINGSRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_list_var_tool.o

YFILEHANDLERSRC_O=$(YSOCKET_DIR)/src/y_socket_t/y_file_handler.o

YLISTSRC_O=$(YLISTDIR)/src/list_t/list_t.o

WORKSRC_0=$(YWORKDIR)/src/y_worker_t/y_worker_t.o
YTASKSRC_0=$(YWORKDIR)/src/y_worker_t/y_task_t.o

YJSONSRC_O=$(YJSONDIR)/src/json_t/json_t.o


DEPS_SOCKET=$(YLISTDIR) $(YWORKDIR) $(YJSONDIR) $(YSOCKET_DIR)

OBJ_SOCKET=$(YSOCKSRC_O) $(YNODESRC_O) $(YY_STRINGSRC_O) $(YLISTSRC_O) $(WORKSRC_0) $(YTASKSRC_0) $(YFILEHANDLERSRC_O) $(YJSONSRC_O) 



#CC=gcc
DEEPQLEARNDIR=$(ROOTPROJECTDIR)/deepQlearn_0
LIB_DEEPQLEARN=$(DEEPQLEARNDIR)/libdeepqlearn.so

YTESTDIR=$(ROOTPROJECTDIR)/ytest_t
YTOOLDIR=$(ROOTPROJECTDIR)/ytools_t
YPERMDIR=$(ROOTPROJECTDIR)/ypermutation_t
DIMDIR=$(ROOTPROJECTDIR)/dimension_t

TENSDIR=$(ROOTPROJECTDIR)/tensor_t
LISTDIR=$(ROOTPROJECTDIR)/list_t

NEURODIR=$(ROOTPROJECTDIR)/neuron_t

#DEEPQLEARN_SRC_DIR=$(ROOTPROJECTDIR)c/deepQlearning
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


TOPTARGETS= all clean 

DEPS_DEEPQLEARN=$(DIMDIR) $(YPERMDIR) $(YTESTDIR) $(TENSDIR) $(NEURODIR) $(YTOOLDIR) $(DEEPQLEARNDIR)  #$(LISTDIR)

OBJ_DEEPQLEARN=$(VEHICLESRC_O) $(DIMSRC_O) $(PERMSRC_O) $(TENSRC_O) $(NEUROSRC_O) $(TOOLSRC_O) $(LEARNTODRIVESRC_O) #$(LISTSRC_O)


LIB_YTEST=$(YTESTDIR)/libytest.so

LIB=$(LIB_SOCKET) $(LIB_YTEST) $(LIB_DEEPQLEARN) $(LIB_NNN)

#all: $(LIB_DEEPQLEARN)
all: $(EXEC) 

#TOPTARGETS := all clean 

DEPS=$(DEPS_SOCKET) $(DEPS_DEEPQLEARN) $(NETNEURNETDIR) 

$(TOPTARGETS): $(DEPS)

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

DEPLIBS=$(NETNEURNETDIR) $(YTESTDIR) $(YSOCKET_DIR) $(DEEPQLEARNDIR)

INCLUDE=$(INCLUDE_NNN) $(INCLUDE_SOCKET) $(INCLUDE_DEEPQLEARN) 

CFLAGS=-Wall -lOpenCL -lm -lpthread -Werror -fpic $(INCLUDE) #-lcurses  -lexplain 
#LDFLAGS=-L$(YTESTDIR) -lytest -lOpenCL -lm -lpthread  #-lcurses


#CFLAGS=-g -lpthread -Wall -Werror -fpic $(INCLUDE) #"-D DEBUG=1" 
#LDFLAGS=

OBJ=$(OBJ_NNN) $(OBJ_DEEPQLEARN) $(OBJ_SOCKET) $(LIB)

$(EXEC):  $(EXECSRC) $(OBJ) #$(LIB_YTEST)
	$(CC) -o $@ $^ $(CFLAGS)

$(LIB) : $(DEPLIBS)

#$(LIB_YTEST) : $(YTESTDIR)

#$(LIB_DEEPQLEARN) : $(DEEPQLEARNDIR)

#$(LIB_SOCKET) : $(YSOCKET_DIR)


.PHONY: clean mrproper $(DEPLIBS)

clean: 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

