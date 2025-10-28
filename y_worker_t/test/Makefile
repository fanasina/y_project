# file: y_worker_t/test/Makefile

ROOTPROJECTDIR:=$(realpath ../..)

NAME_TEST=is_good
CC=gcc
YTESTDIR=$(ROOTPROJECTDIR)/ytest_t
YLISTDIR=$(ROOTPROJECTDIR)/list_t

ROOT_DIR=$(ROOTPROJECTDIR)/y_worker_t
INCLUDE_DIR=$(ROOT_DIR)/include
CFLAGS=-I$(INCLUDE_DIR) -I$(YTESTDIR)/include_ytest/include -I$(YLISTDIR)/src
LDFLAGS=-L$(YTESTDIR) -lytest -lpthread -lm -lOpenCL -Wall -Werror

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
#SRC=$(wildcard **/**/*.c) 

#OBJ=$(SRC:.c=.o)

#HEADS=$(OBJS:.o=.h)
#TEST_DIR=$(PWD)

EXECSRC=$(NAME_TEST).c
EXEC=launch_$(NAME_TEST)_m

YWORKSRC=$(ROOT_DIR)/src/y_worker_t/y_worker_t.c
YWORKSRC_O=$(YWORKSRC:.c=.o)

YTASKSRC=$(ROOT_DIR)/src/y_worker_t/y_task_t.c
YTASKSRC_O=$(YTASKSRC:.c=.o)

YLISTSRC=$(YLISTDIR)/src/list_t/list_t.c
YLISTSRC_O=$(YLISTSRC:.c=.o)

TOPTARGETS := all clean

DEPS=$(YTESTDIR) $(YLISTDIR) $(ROOT_DIR)

OBJ=$(YWORKSRC_O) $(YTASKSRC_O)  $(YLISTSRC_O) 


LIB_YTEST=$(YTESTDIR)/libytest.so

LIB_YWORK=$(ROOT_DIR)/libyworker.so

$(TOPTARGETS): $(DEPS)

$(DEPS):  
	$(MAKE) -C $@ $(MAKECMDGOALS)



all: $(EXEC) $(LIB_YWORK)  $(LIB_YTEST)

$(EXEC):	$(EXECSRC) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(EXEC)

run: $(EXEC)
	$(EXEC) -h
