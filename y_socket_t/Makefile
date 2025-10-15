#file: y_socket_t/Makefile
# lib: -lysocket
PROJECT_LIB=libysocket.so
CC=gcc
INCLUDE_DIRS=$(PWD)/include
SOCDIR=$(PWD) 
#$(wildcard $(PWD)/**/include)

YLISTDIR=$(PWD)/../list_t
YWORKDIR=$(PWD)/../y_worker_t
YJSONDIR=$(PWD)/../yjson_t


INCLUDE=-I$(INCLUDE_DIRS) -I$(YLISTDIR)/src -I$(YWORKDIR)/include -I$(YJSONDIR)/src 
CFLAGS=-g -lpthread -Wall -Werror -fpic $(INCLUDE) #"-D DEBUG=1" 
#LDFLAGS=


YSOCKSRC=$(PWD)/src/y_socket_t/y_socket_t.c
YSOCKSRC_O=$(YSOCKSRC:.c=.o)

YNODESRC=$(PWD)/src/y_socket_t/y_node_t.c
YNODESRC_O=$(YNODESRC:.c=.o)

YY_STRINGSRC=$(PWD)/src/y_socket_t/y_list_var_tool.c
YY_STRINGSRC_O=$(YY_STRINGSRC:.c=.o)

FILEHANDLERSRC=$(PWD)/src/y_socket_t/y_file_handler.c
YFILEHANDLERSRC_O=$(YFILEHANDLERSRC:.c=.o)

YLISTSRC=$(YLISTDIR)/src/list_t/list_t.c
YLISTSRC_O=$(YLISTSRC:.c=.o)

WORKSRC_0=$(YWORKDIR)/src/y_worker_t/y_worker_t.o
YTASKSRC_0=$(YWORKDIR)/src/y_worker_t/y_task_t.o

YJSONSRC=$(YJSONDIR)/src/json_t/json_t.c
YJSONSRC_O=$(YJSONSRC:.c=.o)

all: $(PROJECT_LIB) 

TOPTARGETS := all clean 

DEPS:=$(YLISTDIR) $(YWORKDIR) $(YJSONDIR)

OBJ=$(YSOCKSRC_O) $(YNODESRC_O) $(YY_STRINGSRC_O) $(YLISTSRC_O) $(WORKSRC_0) $(YTASKSRC_0) $(YFILEHANDLERSRC_O) $(YJSONSRC_O) 

$(TOPTARGETS): $(DEPS)






$(PROJECT_LIB): $(OBJ)
	echo "objects:" $(OBJ)
	#$(CC) -shared -o $@ $^ $(INCLUDE) $(LDFLAGS)
	#$(CC) -shared -o $@ $^ $(LDFLAGS)
	$(CC) -shared -o $@ $^ $(CFLAGS)


$(YSOCKSRC_O): $(YSOCKSRC) $(YNODESRC_O) $(YFILEHANDLERSRC_O) $(WORKSRC_0)  $(YTASKSRC_0) $(YJSONSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

$(YNODESRC_O): $(YNODESRC) $(YLISTSRC_O) 
	$(CC) -o $@ -c $< $(CFLAGS)

$(YY_STRINGSRC_O): $(YY_STRINGSRC) $(YLISTSRC_O) 
	$(CC) -o $@ -c $< $(CFLAGS)

$(YFILEHANDLERSRC_O): $(YFILEHANDLERSRC) $(YSOCKSRC_O) $(YNODESRC_O) $(WORKSRC_0) $(YTASKSRC_0)  $(YY_STRINGSRC_O) $(YJSONSRC_O)
	$(CC) -o $@ -c $< $(CFLAGS)

$(DEPS):
	$(MAKE) -C $@ $(MAKECMDGOALS)


# .PHONY: $(TOPTARGETS) $(SUBDIRS)

.PHONY: all clean

clean: 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(PROJECT_LIB)

install: 
	cp libysocket.so /usr/lib/
	@if [ -d /usr/local/include ] ; then\
		echo "copy include to /usr/local/include/" ;\
		cp -r include/* /usr/local/include/;\
	else\
		echo "copy include to /usr/include/" ;\
		cp -r include/* /usr/include/;\
	fi

uninstall:
	rm /usr/lib/libysocket.so
	@if [ -d /usr/local/include ] ; then\
		 echo "remove from /usr/local/include/" ;\
		 rm -r /usr/local/include/y_socket_t ;\
	else\
		 echo "remove from /usr/include/" ;\
		 rm -r /usr/include/y_socket_t ;\
	fi

	
#SRC_test=test/is_good.c

#compile: $(SRC_test) $(PROJECT_LIB) 
#	$(CC) -o launch_is_good_m $< -L. test/src/permutation_t/permutation_t.o test/src/set_theoric_t/set_theoric_t.o -lytest -I./test/src -I./include_ytest
