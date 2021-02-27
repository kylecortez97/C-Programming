#ifndef UTILS_H
#define UTILS_H

int compare_name(const void *, const void *);
int compare_office(const void *, const void *);
int compare_phone(const void *, const void *);
int compare_email(const void *, const void *);

void check_error(int, char *);
void read_file(char *);

#endif