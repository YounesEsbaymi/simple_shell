#include "shell.h"

/**
 * _execute - Execute a command.
 * @command: An array of command and its arguments.
 * @av: The array of command-line arguments (argv).
 * @i: The command number in the shell's history.
 *
 * Return: The exit status of the executed command.
 */
int _execute(char **command, char **av, int i)
{
    pid_t child_pid;
    int status;
    char *cmd;

    if (command[0] == NULL)
    {
        free(command);
        return (0);
    }

    cmd = _getpath(command[0]);
    if (!cmd)
    {
        printError(av[0], command[0], i);
        _freearr(command);
        return (127);
    }
    child_pid = fork();

    if (child_pid == 0)
    {
        if (execvp(cmd, command) == -1)
        {
            free(cmd);
            _freearr(command);
        }
    }
    else
    {
        waitpid(child_pid, &status, 0);
        _freearr(command);
        free(cmd);
    }

    return (WEXITSTATUS(status));
}

