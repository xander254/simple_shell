#include "main.h"
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

/**
 * main - entry point for the shell program
 * Return: always 0
 */
int main(void)
{
    size_t input_length = 0;
    char *line_ptr = NULL;
    char *token;
    char *delim = " \n"; // Updated to include newline as a delimiter
    pid_t child_pid;
    int status, argc;
    char *argv[BUFFER];
    struct stat st;

    while (1)
    {
        write(1, "prompt$:)\n", 11);

        // Check for getline errors
        if (getline(&line_ptr, &input_length, stdin) == -1)
        {
            if (feof(stdin))
            {
                free(line_ptr);
                write(1, "We have reached the EOF, Exiting shell...:(\n", 44);
                exit(0);
            }
            else
            {
                free(line_ptr);
                perror("Error reading stream:(");
                exit(1);
            }
        }

        // Removing the newline character from input
        if (line_ptr[0] == '\n')
            continue; // Skip empty lines

        argc = 0;
        token = strtok(line_ptr, delim);
        while (token)
        {
            argv[argc] = token;
            argc++;
            token = strtok(NULL, delim);
        }
        argv[argc] = NULL;

        child_pid = fork();

        if (child_pid == 0)
        {
            // Only execute if the command exists
            if (stat(argv[0], &st) == 0)
            {
                if (execve(argv[0], argv, environ) == -1)
                {
                    perror("execve failed:(\n");
                    exit(1);
                }
            }
            else
            {
                write(1, "Command NOT FOUND:(\n", 20);
                exit(127);
            }
        }
        else if (child_pid > 0)
        {
            wait(&status);
        }
        else
        {
            perror("fork failed");
            exit(1);
        }
    }

    free(line_ptr);
    return (0);
}

