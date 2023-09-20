#include "shell.h"

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

    if (child_pid == 0) {
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

    return WEXITSTATUS(status);
}
