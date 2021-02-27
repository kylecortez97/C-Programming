/*
 * Name: Kyle Kiyoshi Cortez
 * Email: kylekcortez@csu.fullerton.edu
 * Assignment: CPSC 223C Lab 02
 * Compiler Options: -std=c11 -g -Wall -Wextra -Wpedantic
 */

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_SIZE 3

int main(void) {
  uint8_t byte = 0;

  char command[MAX_COMMAND_SIZE + 1];
  unsigned int argument;

  while (scanf("%s %x", command, &argument) != EOF) {
    bool output = true;

    if (strcmp(command, "set") == 0) {
      byte = argument;
    } else if (strcmp(command, "and") == 0) {
      byte &= argument;
    } else if (strcmp(command, "or") == 0) {
      byte |= argument;
    } else if (strcmp(command, "xor") == 0) {
      byte ^= argument;
    } else if (strcmp(command, "shr") == 0) {
      byte >>= argument;
    } else if (strcmp(command, "shl") == 0) {
      byte <<= argument;
    } else {
      output = false;
    }

    if (output) {
      printf("%s %x => %x\n", command, argument, byte);
    }
  }

  return 0;
}