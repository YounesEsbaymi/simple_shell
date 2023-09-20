#include "shell.h"

int _execute(char **command, char **av)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("fork");
        _freearr(command);
        return -1; 
    }

    if (child_pid == 0) {
        
        if (execve(command[0], command, environ) == -1)
        {
            perror(av[0]);
            _freearr(command);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        waitpid(child_pid, &status, 0);
        _freearr(command);
        return WEXITSTATUS(status);
    }

    return (0);
}
