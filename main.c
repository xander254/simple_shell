#include "main.h"

/**
  *main -entry point of the program
  *
  *Return: always (0)
 */
int main(void)
{
	size_t input_length = 0;
	char *line_ptr = NULL;
	char *argv[BUFFER];
	int argc;

	while (1)
	{
		write(1, "prompt$:)\n", 11);
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

		if (line_ptr[0] == '\n')
			continue;
		parse_input(line_ptr, argv, &argc);

		if (argv[0] != NULL)
			execute_command(argv);
	}

	free(line_ptr);
	return (0);
}
