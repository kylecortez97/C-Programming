CC = gcc
CFLAGS = -std=c11 -g -Wall -Wextra -Wpedantic

PROG = phonebook
SRCS = main.c commands.c faculty.c
OBJS = $(SRCS:.c=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG)

main.o: main.c commands.h faculty.h

commands.o: commands.c commands.h faculty.h

faculty.o: faculty.c faculty.h

clean:
	rm -f core $(PROG) $(OBJS)