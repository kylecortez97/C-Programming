CC = gcc
CFLAGS = -std=c11 -g -Wall -Wextra -Wpedantic

MKPROG = mkphone
MKSRCS = mkphone.c utils.c faculty.c
MKOBJS = $(MKSRCS:.c=.o)

LSPROG = lsphone
LSSRCS = lsphone.c utils.c faculty.c
LSOBJS = $(LSSRCS:.c=.o)

PHPROG = phone
PHSRCS = phone.c commands.c utils.c faculty.c
PHOBJS = $(PHSRCS:.c=.o)

PROGS = $(MKPROG) $(LSPROG) $(PHPROG)

all: $(PROGS)

$(MKPROG): $(MKOBJS)
	$(CC) $(MKOBJS) -o $(MKPROG)

$(LSPROG): $(LSOBJS)
	$(CC) $(LSOBJS) -o $(LSPROG)

$(PHPROG): $(PHOBJS)
	$(CC) $(PHOBJS) -o $(PHPROG)

mkphone.o: mkphone.c utils.h faculty.h

lsphone.o: lsphone.c utils.h faculty.h

phone.o: phone.c commands.h utils.h faculty.h

clean:
	rm -f core $(PROGS) *.o *.bin