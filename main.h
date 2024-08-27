#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>


ssize_t getline(char **lineptr, size_t *n, FILE *stream);
ssize_t string_rm_newline(const char *str1, const char *str2);
int _putchar(char c);
void print_string(char *str);
#endif /* MAIN_H */
