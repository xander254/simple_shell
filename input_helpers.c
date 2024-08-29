#include "shell.h"

/**
 * prompt - Displays the shell prompt.
 */
void prompt(void)
{
    write(1, "prompt$:)\n", 11);
}

/**
 * get_input - Gets input from the user.
 * @line_ptr: Pointer to the buffer that stores the input.
 * @input_length: Pointer to the size of the buffer.
 * Return: 0 on success, -1 on failure or EOF.
 */
int get_input(char **line_ptr, size_t *input_length)
{
    if (getline(line_ptr, input_length, stdin) == -1)
    {
        if (feof(stdin))
        {
            write(1, "We have reached the EOF, Exiting shell...:(\n", 44);
            return -1;
        }
        else
        {
            perror("Error reading stream:(");
            return -1;
        }
    }
    return 0;
}

