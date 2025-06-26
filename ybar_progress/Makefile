


BARPROGES_SRC=src/bar_progress/bar_progress.c
BARPROGES_O=$(BARPROGES_SRC:.c=.o)

all: $(BARPROGES_O)

$(BARPROGES_O): $(BARPROGES_SRC)
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean 

clean:
	rm -f $(BARPROGES_O)

mrproper: clean
