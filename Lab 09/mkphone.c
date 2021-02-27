/*
 * Name: Kyle Kiyoshi Cortez
 * Email: kylekcortez@csu.fullerton.edu
 * Assignment: CPSC 223C Lab 09
 * Compiler Options: -std=c11 -g -Wall -Wextra -Wpedantic
 */

#include <stdlib.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

#include "faculty.h"
#include "utils.h"

void write_file(int (*sort_by)(const void *, const void *), char *filename) {
  int fd = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
  check_error(fd, filename);

  qsort(faculty, NUM_FACULTY, sizeof(struct professor), sort_by);

  ssize_t written = write(fd, faculty, sizeof(faculty));
  check_error(written, filename);

  int result = close(fd);
  check_error(result, filename);
}

int main(void) {
  write_file(compare_name, "name.bin");
  write_file(compare_office, "office.bin");
  write_file(compare_phone, "phone.bin");
  write_file(compare_email, "email.bin");

  return EXIT_SUCCESS;
}