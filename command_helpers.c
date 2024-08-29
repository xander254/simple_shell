#include "shell.h"

/**
 * execute_command - Creates a child process to execute the inputted command.
 * @argv: Array of strings where the first element is the command and
 *        the subsequent elements are the arguments.
 */
void execute_command(char **argv)
{
    pid_t child_pid;
    int status;
    struct stat st;

    child_pid = fork();
    if (child_pid == 0)  /* Child process */
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
            write(1, "Command NOT FOUND:(\n", 20);
            exit(127);
        }
    }
    else if (child_pid > 0)  /* Parent process */
    {
        wait(&status);
    }
    else  /* Fork failed */
    {
        perror("fork failed");
        exit(1);
    }
}

