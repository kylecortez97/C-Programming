/*
 * Name: Kyle Kiyoshi Cortez
 * Email: kylekcortez@csu.fullerton.edu
 * Assignment: CPSC 223C Lab 06
 * Compiler Options: -std=c11 -g -Wall -Wextra -Wpedantic
 */

#include <assert.h>
#include <stdio.h>

#include "bstrlib.h"
#include "checks.h"

void bump_int(int *i, int *amount) {
  assert(i != NULL);

  *i += (amount == NULL) ? 1 : *amount;
}

void bump_string(bstring s, char *c) {
  assert(s != NULL);

  CHECK_BSTR_OK(bconchar(s, (c == NULL) ? 'o' : *c));
}

int main(void) {
  int i = 1;
  int amount = 2;

  printf("%d\n", i);
  bump_int(&i, NULL);
  printf("%d\n", i);
  bump_int(&i, &amount);
  printf("%d\n", i);

  bstring s;
  CHECK_NOT_NULL(s = bfromStatic("foo"));
  char c = 'x';

  printf("%s\n", s->data);
  bump_string(s, NULL);
  printf("%s\n", s->data);
  bump_string(s, &c);
  printf("%s\n", s->data);

  CHECK_BSTR_OK(bdestroy(s));

  return 0;
}