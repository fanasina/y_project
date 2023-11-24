

FMOCK_SRC=src/fmock/fmock.c
FMOCK_O=$(FMOCK_SRC:.c=.o)

FTEST_SRC=../yftest/src/ftest/ftest.c
FTEST_O=$(FTEST_SRC:.c=.o)


all: $(FMOCK_O)

$(FMOCK_O): $(FMOCK_SRC) $(FTEST_O)
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean 

clean:
	rm -f $(FMOCK_O)

