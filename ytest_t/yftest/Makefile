

FTEST_SRC=src/ftest/ftest.c
FTEST_O=$(FTEST_SRC:.c=.o)

TOOLS_SRC=../ytools_t/src/tools_t/tools_t.c
TOOLS_O=$(TOOLS_SRC:.c=.o)

BARPROGES_SRC=../ybar_progress/src/bar_progress/bar_progress.c
BARPROGES_O=$(BARPROGES_SRC:.c=.o)


all: $(FTEST_O)


$(FTEST_O): $(FTEST_SRC) $(TOOLS_O) $(BARPROGES_O)
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean 

clean:
	rm -f $(FTEST_O)

