CC = gcc
CFLAGS = -std=c11 -g -Wall -Wextra -Wpedantic

LAB01PROG = lab01
LAB01SRCS = lab01.c
LAB01OBJS = $(LAB01SRCS:.c=.o)

LAB03PROG = lab03
LAB03SRCS = lab03.c
LAB03OBJS = $(LAB03SRCS:.c=.o)

PROGS = $(LAB01PROG) $(LAB03PROG)
SRCS = $(LAB01SRCS) $(LAB03SRCS)
OBJS = $(SRCS:.c=.o)

BSTRSRCS = bstrlib.c
BSTROBJS = $(BSTRSRCS:.c=.o)

all: $(PROGS)

$(LAB01PROG): $(LAB01OBJS) $(BSTROBJS)
	$(CC) $(LAB01OBJS) $(BSTROBJS) -o $(LAB01PROG)

$(LAB03PROG): $(LAB03OBJS) $(BSTROBJS)
	$(CC) $(LAB03OBJS) $(BSTROBJS) -o $(LAB03PROG)

lab01.o: lab01.c bstrlib.h checks.h

lab03.o: lab03.c bstrlib.h checks.h

bstrlib.o: bstrlib.c bstrlib.h

clean:
	rm -f core $(PROGS) $(OBJS)

distclean: clean
	rm -f $(BSTROBJS)