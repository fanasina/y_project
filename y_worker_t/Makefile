# lib: -lyworker
PROJECT_LIB=libyworker.so
CC=gcc
INCLUDE_DIRS=$(PWD)/include
SOCDIR=$(PWD) 
#$(wildcard $(PWD)/**/include)

TOOLDIR=$(PWD)/../ytools_t
YLISTDIR=$(PWD)/../list_t


INCLUDE=-I$(INCLUDE_DIRS) -I$(YLISTDIR)/src -I$(TOOLDIR)/include
CFLAGS=-g -lpthread -Wall -Werror -fpic $(INCLUDE) #"-D DEBUG=1" 
#LDFLAGS=


YWORKSRC=$(PWD)/src/y_worker_t/y_worker_t.c
YWORKSRC_O=$(YWORKSRC:.c=.o)

YTASKSRC=$(PWD)/src/y_worker_t/y_task_t.c
YTASKSRC_O=$(YTASKSRC:.c=.o)

YLISTSRC=$(YLISTDIR)/src/list_t/list_t.c
YLISTSRC_O=$(YLISTSRC:.c=.o)

TOOLSRC_O=$(TOOLDIR)/src/tools_t/tools_t.o


TOPTARGETS := all clean 

DEPS=$(YLISTDIR) 

OBJ=$(YWORKSRC_O) $(YLISTSRC_O) 

$(TOPTARGETS): $(DEPS)


all: $(PROJECT_LIB) 




$(PROJECT_LIB): $(OBJ)
	echo "objects:" $(OBJ)
	#$(CC) -shared -o $@ $^ $(INCLUDE) $(LDFLAGS)
	#$(CC) -shared -o $@ $^ $(LDFLAGS)
	$(CC) -shared -o $@ $^ $(CFLAGS)


$(YWORKSRC_O): $(YWORKSRC)  $(YLISTSRC_O) $(YTASKSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

$(YTASKSRC_O): $(YTASKSRC)  $(YLISTSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)


$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


# .PHONY: $(TOPTARGETS) $(SUBDIRS)

.PHONY: clean

clean: 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(PROJECT_LIB)

install: 
	cp libyworker.so /usr/lib/
	@if [ -d /usr/local/include ] ; then\
		echo "copy include to /usr/local/include/" ;\
		cp -r include/* /usr/local/include/;\
	else\
		echo "copy include to /usr/include/" ;\
		cp -r include/* /usr/include/;\
	fi

uninstall:
	rm /usr/lib/libyworker.so
	@if [ -d /usr/local/include ] ; then\
		 echo "remove from /usr/local/include/" ;\
		 rm -r /usr/local/include/y_worker_t ;\
	else\
		 echo "remove from /usr/include/" ;\
		 rm -r /usr/include/y_worker_t ;\
	fi

	
#SRC_test=test/is_good.c

#compile: $(SRC_test) $(PROJECT_LIB) 
#	$(CC) -o launch_is_good_m $< -L. test/src/permutation_t/permutation_t.o test/src/set_theoric_t/set_theoric_t.o -lytest -I./test/src -I./include_ytest
