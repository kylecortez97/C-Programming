/*
 * Name: Kyle Kiyoshi Cortez
 * Email: kylekcortez@csu.fullerton.edu
 * Assignment: CPSC 223C Lab 09
 * Compiler Options: -std=c11 -g -Wall -Wextra -Wpedantic
 */

#include <stdio.h>
#include <stdlib.h>

#include "faculty.h"
#include "utils.h"

void usage(char *program) {
  fprintf(stderr, "Usage: %s <file>\n", program);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    usage(argv[0]);
  }

  read_file(argv[1]);

  for (int i = 0; i < NUM_FACULTY; i++) {
    print_professor(faculty + i);
    printf("\n");
  }
  
  return EXIT_SUCCESS;
}