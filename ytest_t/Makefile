# lib: -lytest
PROJECT_LIB=libytest.so
CC=gcc
INCLUDE_DIRS=$(PWD) 
#$(wildcard $(PWD)/**/include)
TOOLDIR=$(PWD)/../ytools_t
BARPDIR=$(PWD)/../ybar_progress
TOOL_O=$(TOOLDIR)/src/tools_t/tools_t.o
BARP_O=$(BARPDIR)/src/bar_progress/bar_progress.o


INCLUDE=-I$(PWD)/yftest/include  -I$(PWD)/yfmock/include -I$(TOOLDIR)/include -I$(BARPDIR)/include
CFLAGS=-g -lpthread -Wall -Werror -fpic $(INCLUDE) #"-D DEBUG=1" 
#LDFLAGS=

TOPTARGETS := all clean #update_headers

#SRC=$(wildcard y*/src/**/**/*.c) 
SRC=$(wildcard y*/*/*/*.c) 
OBJ=$(SRC:.c=.o) $(TOOL_O) $(BARP_O)

SUBDIRS :=$(wildcard y*) $(TOOLDIR) $(BARPDIR)

export

all: $(PROJECT_LIB) update_headers

$(TOPTARGETS): $(SUBDIRS)



$(PROJECT_LIB): $(OBJ)
	echo $(OBJ)
	#$(CC) -shared -o $@ $^ $(INCLUDE) $(LDFLAGS)
	#$(CC) -shared -o $@ $^ $(LDFLAGS)
	$(CC) -shared -o $@ $^ $(CFLAGS)


$(SUBDIRS):
		$(MAKE) -C $@ $(MAKECMDGOALS)

update_headers: $(PROJECT_LIB)
	for file_h in $(SUBDIRS); do cp -r "$$file_h/include/" include_ytest/;	done	

.PHONY: all $(TOPTARGETS) $(SUBDIRS)

mrproper: clean
	rm -f $(PROJECT_LIB)

remove_headers:
	rm -r include_ytest/*

install: update_headers
	cp libytest.so /usr/lib/
	@if [ -d /usr/local/include ] ; then\
		echo "copy include to /usr/local/include/" ;\
		cp -r include_ytest/include/* /usr/local/include/;\
	else\
		echo "copy include to /usr/include/" ;\
		cp -r include_ytest/include/* /usr/include/;\
	fi

uninstall:
	rm /usr/lib/libytest.so
	@if [ -d /usr/local/include ] ; then\
		 echo "remove from /usr/local/include/" ;\
		 rm -r /usr/local/include/ftest ;\
		 rm -r /usr/local/include/fmock ;\
		 rm -r /usr/local/include/bar_progress ;\
		 rm -r /usr/local/include/tools_t ;\
	else\
		 echo "remove from /usr/include/" ;\
		 rm -r /usr/include/ftest ;\
		 rm -r /usr/include/fmock ;\
		 rm -r /usr/include/bar_progress ;\
		 rm -r /usr/include/tools_t ;\
	fi

	
#SRC_test=test/is_good.c

#compile: $(SRC_test) $(PROJECT_LIB) 
#	$(CC) -o launch_is_good_m $< -L. test/src/permutation_t/permutation_t.o test/src/set_theoric_t/set_theoric_t.o -lytest -I./test/src -I./include_ytest
