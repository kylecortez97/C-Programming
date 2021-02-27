#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "bstrlib.h"
#include "list.h"

struct node *create_node(int line, bstring command, unsigned int argument) {
  struct node *new = malloc(sizeof(struct node));

  if (new == NULL) {
    fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }

  new->line = line;
  new->command = bstrcpy(command);
  new->argument = argument;

  new->next = NULL;

  return new;
}

struct node *append_node(struct node *start, struct node *new) {
  assert(start != NULL);

  struct node *current = start;

  while (current->next != NULL) {
    current = current->next;
  }

  current->next = new;

  return new;
}

void print_node(struct node *n) {
  printf("%2d %s %x\n", n->line, n->command->data, n->argument);
}

void free_list(struct node *start) {
  struct node *current, *prev;

  current = start;

  while (current != NULL) {
    prev = current;
    current = current->next;

    bdestroy(prev->command);
    free(prev);
  }
}