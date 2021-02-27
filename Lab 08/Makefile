CC = gcc
CFLAGS = -std=c11 -g -Wall -Wextra -Wpedantic -D_POSIX_C_SOURCE=200801L

PROG = calculator
SRCS = main.c commands.c list.c
OBJS = $(SRCS:.c=.o)

BSTRSRCS = bstrlib.c
BSTROBJS = $(BSTRSRCS:.c=.o)

all: $(PROG)

$(PROG): $(OBJS) $(BSTROBJS)
	$(CC) $(OBJS) $(BSTROBJS) -o $(PROG)

main.o: main.c commands.h list.h

commands.o: commands.c commands.h list.h

list.o: list.c list.h

bstrlib.o: bstrlib.c bstrlib.h

clean:
	rm -f core $(PROG) $(OBJS)

distclean: clean
	rm -f $(BSTROBJS)