#include "main.h"

/**
  *parse_input -function that tokenizes the inputstring
  *into individual arguments
  *@line: input string to be tokenized
  *@argv: array of string with each holding a token
  *@argc: pointer to an integer storing no of args passed
  *to execute the inputted command
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

/**
 *execute_command -function that creates a child process
  *that executes the command inputted
  *@argv: Array of strings where the first element is the
  *command to be executed  while the following elements
  *are arguments
  */
void execute_command(char **argv)
{
	pid_t child_pid;
	int status;
	struct stat st;

	child_pid = fork();
	if (child_pid == 0)
	{
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
			perror("Command NOT FOUND:(\n");
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
