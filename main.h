#ifndef MAIN_H
#define MAIN_H

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

int main(void);
void parse_input(char *line, char **argv, int *argc);
void execute_command(char **argv);

#endif /* MAIN_H */

