# lib: -lneurons

PROJECT_LIB=libneurons.so

CC=gcc
ROOT_DIR=$(PWD)
YTESTDIR=$(PWD)/../ytest_t
YPERMDIR=$(PWD)/../ypermutation_t

TENSDIR=$(PWD)/../tensor_t

NEURODIR=$(PWD)
DIMDIR=$(PWD)/../dimension_t
INCLUDE_DIR=$(PWD)/sr

#CFLAGS=-I$(INCLUDE_DIR) -I$(YPERMDIR)/src -I$(YTESTDIR)/include_ytest/include -I$(DIMDIR)/src -I$(TENSDIR)/src #"-D DEBUG=1"
INCLUDE=-I$(NEURODIR)/src -I$(YPERMDIR)/src -I$(DIMDIR)/src -I$(TENSDIR)/src #"-D DEBUG=1"
#LDFLAGS=-L$(YTESTDIR) -lytest -lOpenCL -lm -lpthread
#CFLAGS= -Wall -Werror -fpic $(INCLUDE)
CFLAGS= -Wall -Werror -fpic $(INCLUDE)
LDFLAGS= -lOpenCL -lpthread

#SRC_DIR=$(ROOT_DIR)/src
#SRC=$(wildcard */*/*.c) 
SRC=$(wildcard **/**/*.c) 
#HEADS=$(OBJS:.o=.h)
TEST_DIR=$(PWD)

EXECSRC=$(NAME_TEST).c
#EXECSRC=openF.c

EXEC=launch_$(NAME_TEST)_m

NEUROSRC=$(NEURODIR)/src/neuron_t/neuron_t.c
NEUROSRC_O=$(NEUROSRC:.c=.o)

INCLUDE_HEADERS_NEURONS=$(NEURODIR)/include_neurons/include

TENSRC=$(TENSDIR)/src/tensor_t/tensor_t.c
TENSRC_O=$(TENSRC:.c=.o)

PERMSRC_O=$(YPERMDIR)/src/permutation_t/permutation_t.o

DIMSRC_O=$(DIMDIR)/src/dimension_t/dimension_t.o

TOPTARGETS := all clean 

#DEPS=$(DIMDIR) $(YPERMDIR) $(YTESTDIR) $(TENSDIR) $(NEURODIR)
DEPS=$(DIMDIR) $(YPERMDIR) $(TENSDIR) $(NEURODIR)

OBJ=$(DIMSRC_O) $(PERMSRC_O) $(TENSRC_O) $(NEUROSRC_O)

#LIB_YTEST=$(YTESTDIR)/libytest.so


$(TOPTARGETS): $(DEPS) 

all: $(PROJECT_LIB) update_headers

$(PROJECT_LIB): $(OBJ)
	echo $(OBJ)
	#$(CC) -shared -o $@ $^ $(INCLUDE) $(LDFLAGS)
	#$(CC) -shared -o $@ $^ $(LDFLAGS)
	#$(CC) -shared -o $@ $^ $(CFLAGS)
	$(CC) -shared -o $@ $^ $(CFLAGS) $(LDFLAGS)



$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

update_headers: $(PROJECT_LIB)
	for file_h in $(DEPS); do \
		cd "$$file_h/src" ; \
		cp --parents */*.h $(INCLUDE_HEADERS_NEURONS)/ ; \
	done


#PERMSRC_O=$(PERMSRC:.c=.o)
#SETTSRC_O=$(PWD)/../src/set_theoric_t/set_theoric_t.o
#SETTSRC_O=$(SETTSRC:.c=.o)
#TOOLSRC=$(TOOLDIR)/src/tools_t/tools_t.c
#TOOLSRC_O=$(TOOLSRC:.c=.o)



#$(EXEC):	$(EXECSRC) $(OBJ)
#	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

.PHONY: clean mrproper

clean:
	rm -f $(OBJ)

mrproper: clean
	rm -f $(PROJECT_LIB)

remove_headers:
	rm -r $(INCLUDE_HEADERS_NEURONS)/*


#run: $(EXEC)
#	$(EXEC) -h
