/*
 * Name: Kyle Kiyoshi Cortez
 * Email: kylekcortez@csu.fullerton.edu
 * Assignment: CPSC 223C Lab 08
 * Compiler Options: -std=c11 -g -Wall -Wextra -Wpedantic -D_POSIX_C_SOURCE=200801L
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "bstrlib.h"
#include "commands.h"
#include "list.h"

void usage(char *program) {
  fprintf(stderr, "Usage: %s [-d] [-v] <file>...\n", program);
  exit(EXIT_FAILURE);
}

bool debug = false;

void handle_options(int argc, char *argv[]) {
  int opt;

  while ((opt = getopt(argc, argv, "dv")) != -1) {
    switch (opt) {
      case 'd':
        debug = true;
        break;
      case 'v':
        verbose = true;
        break;
      default:
        usage(argv[0]);
        break;
    }
  }
}

bstring bfgets(FILE *fp) {
  bstring s = bgets((bNgetc) fgetc, fp, '\n');

  if (s != NULL) {
    int len = blength(s);

    if (len > 0) {
      if (btrunc(s, len - 1) != BSTR_OK) {
        fprintf(stderr, "%s:%d: btrunc did not return BSTR_OK\n", __FILE__, __LINE__);
      }
    }
  }

  return s;
}

struct node *parse_statement(bstring s) {
  static int line = 1;
  int len = blength(s);
  char cmd[len + 1];
  unsigned int argument;

  bstring fmt = bformat("%%%ds %%x", len);
  sscanf((const char *) s->data, (const char *) fmt->data, cmd, &argument);
  bdestroy(fmt);

  bstring command = bfromcstr(cmd);
  struct node *statement = create_node(line++, command, argument);
  bdestroy(command);

  return statement;
}

struct node *create_list(int argc, char *argv[]) {
  struct node *head = NULL;
  struct node *next;

  for (int i = optind; i < argc; i++) {
    FILE *fp = fopen(argv[i], "rt");

    if (fp == NULL) {
      perror(argv[i]);
      exit(EXIT_FAILURE);
    }

    bstring s;

    while ((s = bfgets(fp)) != NULL) {
      if (head == NULL) {
        head = next = parse_statement(s);
      } else {
        next = append_node(next, parse_statement(s));
      }

      bdestroy(s);
    }

    if (fclose(fp) == EOF) {
      perror(argv[i]);
      exit(EXIT_FAILURE);
    }
  }

  return head;
}

void debugger(void) {
  bstring command;

  while ((command = bfgets(stdin)) != NULL) {
    if (biseqStatic(command, "step")) {
      do_step();
    } else if (biseqStatic(command, "continue")) {
      do_continue();
    } else if (biseqStatic(command, "print")) {
      do_print();
    } else if (biseqStatic(command, "list")) {
      do_list();
    } else if (biseqStatic(command, "quit")) {
      bdestroy(command);
      break;
    }

    bdestroy(command);
  }
}

int main(int argc, char *argv[]) {
  handle_options(argc, argv);

  first_instruction = create_list(argc, argv);
  current_instruction = first_instruction;

  if (debug) {
    debugger();
  } else {
    do_continue();

    if (!verbose) {
      do_print();
    }
  }

  free_list(first_instruction);

  return EXIT_SUCCESS;
}