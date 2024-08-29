#include "shell.h"

/**
 * parse_input - Tokenizes the input string into individual arguments.
 * @line: The input string to be tokenized.
 * @argv: Array of strings where each element will hold a token (argument).
 * @argc: Pointer to an integer to store the number of arguments parsed.
 */
void parse_input(char *line, char **argv, int *argc)
{
    char *token;
    char *delim = " \n";
    *argc = 0;

    token = strtok(line, delim);
    while (token)
    {
        argv[*argc] = token;
        (*argc)++;
        token = strtok(NULL, delim);
    }

    argv[*argc] = NULL;
}

