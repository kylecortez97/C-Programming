/*
 * Name: Kyle Kiyoshi Cortez
 * Email: kylekcortez@csu.fullerton.edu
 * Assignment: CPSC 223C Lab 04
 * Compiler Options: -std=c11 -g -Wall -Wextra -Wpedantic
 */

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BYTE_COMMAND_SIZE 3
#define MAX_DEBUG_COMMAND_SIZE 8

struct node {
  int line;
  char command[MAX_BYTE_COMMAND_SIZE + 1];
  unsigned int argument;

  struct node *next;
};

struct node *create_node(int line, char *command, unsigned int argument) {
  assert(strlen(command) <= MAX_BYTE_COMMAND_SIZE);

  struct node *new = malloc(sizeof(struct node));

  if (new == NULL) {
    fprintf(stderr, "%s:%d: malloc() returned NULL\n", __FILE__, __LINE__);
    exit(EXIT_FAILURE);
  }

  new->line = line;
  strcpy(new->command, command);
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

struct node *create_list(void) {
  struct node *head, *next;

  head = create_node(1, "set", 0x1);
  next = append_node(head, create_node(2, "shl", 0x1));
  next = append_node(next, create_node(3, "shl", 0x1));
  next = append_node(next, create_node(4, "or", 0x1));
  next = append_node(next, create_node(5, "or", 0x2));
  next = append_node(next, create_node(6, "shl", 0x2));
  next = append_node(next, create_node(7, "xor", 0x10));
  next = append_node(next, create_node(8, "xor", 0x10));
  next = append_node(next, create_node(9, "and", 0x4));
  next = append_node(next, create_node(10, "set", 0x1c));
  next = append_node(next, create_node(11, "and", 0x3));
  next = append_node(next, create_node(12, "set", 0x1c));
  next = append_node(next, create_node(13, "shr", 0x1));

  return head;
}

void free_list(struct node *start) {
  struct node *current, *prev;

  current = start;

  while (current != NULL) {
    prev = current;
    current = current->next;

    free(prev);
  }
}

struct node *first_instruction, *current_instruction;
uint8_t byte = 0;

void do_step(void) {
  if (current_instruction == NULL) {
    return;
  }

  if (strcmp(current_instruction->command, "set") == 0) {
    byte = current_instruction->argument;
  } else if (strcmp(current_instruction->command, "and") == 0) {
    byte &= current_instruction->argument;
  } else if (strcmp(current_instruction->command, "or") == 0) {
    byte |= current_instruction->argument;
  } else if (strcmp(current_instruction->command, "xor") == 0) {
    byte ^= current_instruction->argument;
  } else if (strcmp(current_instruction->command, "shr") == 0) {
    byte >>= current_instruction->argument;
  } else if (strcmp(current_instruction->command, "shl") == 0) {
    byte <<= current_instruction->argument;
  }

  current_instruction = current_instruction->next;
}

void do_continue(void) {
  while (current_instruction != NULL) {
    do_step();
  }
}

void do_print(void) {
  printf("%x\n", byte);
}

void print_node(struct node *n) {
  printf("%2d %s %x\n", n->line, n->command, n->argument);
}

struct node *find_prev(struct node *start) {
  struct node *prev = first_instruction;

  while (prev->next != start) {
    prev = prev->next;
  }

  return prev;
}

void do_list(void) {
  if (current_instruction == first_instruction) {
    print_node(current_instruction);
    print_node(current_instruction->next);
  } else if (current_instruction == NULL) {
    struct node *prev = find_prev(current_instruction);
    struct node *prev_prev = find_prev(prev);

    print_node(prev_prev);
    print_node(prev);
  } else {
    struct node *prev = find_prev(current_instruction);

    print_node(prev);
    print_node(current_instruction);
    print_node(current_instruction->next);
  }
}

int main(void) {
  first_instruction = create_list();
  current_instruction = first_instruction;

  char command[MAX_DEBUG_COMMAND_SIZE + 1];

  while (scanf("%s", command) != EOF) {
    if (strcmp(command, "step") == 0) {
      do_step();
    } else if (strcmp(command, "continue") == 0) {
      do_continue();
    } else if (strcmp(command, "print") == 0) {
      do_print();
    } else if (strcmp(command, "list") == 0) {
      do_list();
    }
  }

  free_list(first_instruction);

  return EXIT_SUCCESS;
}