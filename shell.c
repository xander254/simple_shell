#include "shell.h"

/**
 * main - Entry point for the shell program.
 * Return: always 0
 */
int main(void)
{
    char *line_ptr = NULL;
    size_t input_length = 0;
    char *argv[BUFFER];
    int argc;

    while (1)
    {
        prompt();
        if (get_input(&line_ptr, &input_length) == -1)
            break;

        parse_input(line_ptr, argv, &argc);

        if (argc > 0)
            execute_command(argv);
    }

    free(line_ptr); 
    return (0);
}

