# lib: -lysocket
PROJECT_LIB=libysocket.so
CC=gcc
INCLUDE_DIRS=$(PWD) 
SOCDIR=$(PWD) 
#$(wildcard $(PWD)/**/include)


INCLUDE=-I$(PWD)/include
CFLAGS=-g -lpthread -Wall -Werror -fpic $(INCLUDE) #"-D DEBUG=1" 
#LDFLAGS=

TOPTARGETS := all clean #update_headers

#SRC=$(wildcard y*/src/**/**/*.c) 
SRC=$(wildcard src/*/*.c) 
OBJ=$(SRC:.c=.o) 

#SUBDIRS :=$(wildcard y*) $(TOOLDIR) $(BARPDIR)

#export


#$(TOPTARGETS): $(SUBDIRS)

all: $(PROJECT_LIB) 

#update_headers


$(PROJECT_LIB): $(OBJ)
	echo $(OBJ)
	#$(CC) -shared -o $@ $^ $(INCLUDE) $(LDFLAGS)
	#$(CC) -shared -o $@ $^ $(LDFLAGS)
	$(CC) -shared -o $@ $^ $(CFLAGS)


$(SUBDIRS):
		$(MAKE) -C $@ $(MAKECMDGOALS)


# .PHONY: $(TOPTARGETS) $(SUBDIRS)

.PHONY: clean

clean: 
	rm -f $(OBJ)

mrproper: clean
	rm -f $(PROJECT_LIB)

install: 
	cp libytest.so /usr/lib/
	@if [ -d /usr/local/include ] ; then\
		echo "copy include to /usr/local/include/" ;\
		cp -r include/* /usr/local/include/;\
	else\
		echo "copy include to /usr/include/" ;\
		cp -r include/* /usr/include/;\
	fi

uninstall:
	rm /usr/lib/libytest.so
	@if [ -d /usr/local/include ] ; then\
		 echo "remove from /usr/local/include/" ;\
		 rm -r /usr/local/include/y_socket ;\
	else\
		 echo "remove from /usr/include/" ;\
		 rm -r /usr/include/y_socket ;\
	fi

	
#SRC_test=test/is_good.c

#compile: $(SRC_test) $(PROJECT_LIB) 
#	$(CC) -o launch_is_good_m $< -L. test/src/permutation_t/permutation_t.o test/src/set_theoric_t/set_theoric_t.o -lytest -I./test/src -I./include_ytest
