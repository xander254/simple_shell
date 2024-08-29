#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

#define BUFFER 1024

extern char **environ;

void prompt(void);
int get_input(char **line_ptr, size_t *input_length);
void parse_input(char *line, char **argv, int *argc);
void execute_command(char **argv);

#endif /* SHELL_H */

