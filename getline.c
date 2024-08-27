#include "main.h"
#define BUFFER 1024
/**
  *main - entry point
  *Return: always return 0.
  */
extern char **environ;

int main()
{
        size_t input_length = 0;
        char *line_ptr = NULL;
        char *token;
        char *delim = " ";
        pid_t child_pid;
        int status, argc = 0;
        char *argv[BUFFER];
	struct stat st;
	char **env = environ; 


        while (1)
        {
                write(1, "prompt$:)\n", 11);
                if (getline(&line_ptr, &input_length, stdin) == -1)
                {
			if (feof(stdin))
			{
				print_string("We have reached the EOF, Exiting shell...:(\n");
				free(line_ptr);
				exit(0);
			}
			else
			{
				free(line_ptr);
				perror("Error reading stream:(");
				exit (1);
			}
		}
		line_ptr[string_rm_newline(line_ptr, "\n")] = 0;

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
                        if (stat(argv[0], &st) == 0)
			{
				print_string("Command FOUND:)\n");
				if (execve(argv[0], argv, env) == -1)
                        	{
                                perror("execve failed:(\n");
				exit(1);
                        	}
			}
			else
			{
				print_string("Command NOT FOUND:(\n");
				exit(127);
			}
                }
		else
		{
			wait(&status);
		}
	}
	if (errno != 0)
	{
		perror("Unexpected error was encountered:(");
	}
	free(line_ptr);
        return (0);
}
