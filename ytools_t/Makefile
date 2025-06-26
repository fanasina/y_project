

TOOLS_SRC=src/tools_t/tools_t.c
TOOLS_O=$(TOOLS_SRC:.c=.o)


all: $(TOOLS_O)

$(TOOLS_O): $(TOOLS_SRC)
	$(CC) -o $@ -c $< $(CFLAGS)


.PHONY: clean 

clean:
	rm -f $(TOOLS_O)

mrproper: clean
