/*
 * Name: Kyle Kiyoshi Cortez
 * Email: kylekcortez@csu.fullerton.edu
 * Assignment: CPSC 223C Lab 01
 * Compiler Options: -std=c11 -g -Wall -Wextra -Wpedantic
 */

#include <assert.h>
#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 5

void bump_int(int *i, int *amount) {
  assert(i != NULL);

  *i += (amount == NULL) ? 1 : *amount;
}

void bump_string(char *s, char *c) {
  assert(s != NULL);

  int len = strlen(s);

  if (len + 1 <= MAX_STRING_SIZE) {
    s[len] = (c == NULL) ? 'o' : *c;
    s[len + 1] = '\0';
  }
}

int main(void) {
  int i = 1;
  int amount = 2;

  printf("%d\n", i);
  bump_int(&i, NULL);
  printf("%d\n", i);
  bump_int(&i, &amount);
  printf("%d\n", i);

  char s[MAX_STRING_SIZE + 1] = "foo";
  char c = 'x';

  printf("%s\n", s);
  bump_string(s, NULL);
  printf("%s\n", s);
  bump_string(s, &c);
  printf("%s\n", s);

  return 0;
}