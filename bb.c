#include "shell.h"

/**
 * execute_builtin - Execute built-in shell commands.
 * @command: An array of command arguments.
 * @prev_dir: A pointer to the previous working directory.
 *
 * Return: The exit status or 0 if not a built-in command.
 */
int execute_builtin(char **command, char **prev_dir)
{
    char *home_dir;
    char cwd[1024];
    int status = 0;

    if (command[0] == NULL)
    {
        return 0;
    }

    if (_strcmp(command[0], "exit") == 0)
    {
        if (command[1] == NULL)
        {
            exit(0);
        }
        else
        {
            int status = atoi(command[1]);
            exit(status); 
        }
    }
    else if (_strcmp(command[0], "env") == 0)
    {
        print_env();
        return 2;
    }
    else if (_strcmp(command[0], "cd") == 0)
    {
        if (command[1] == NULL || _strcmp(command[1], "~") == 0)
        {
            home_dir = _getenv("HOME");
            chdir(home_dir);
        }
        else if (_strcmp(command[1], "-") == 0)
        {
            if (*prev_dir)
            {
                chdir(*prev_dir);
            }
        }
        else if (_strcmp(command[0], "setenv") == 0)
        {
            if (command[1] != NULL && command[2] != NULL)
            {
                if (setenv(command[1], command[2], 1) != 0)
                {
                    perror("setenv");
                }
            }
            else
            {
                fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
            }
            return 3;
        }
        else if (_strcmp(command[0], "unsetenv") == 0)
        {
            if (command[1] != NULL)
            {
                if (unsetenv(command[1]) != 0)
                {
                    perror("unsetenv");
                }
            }
            else
            {
                fprintf(stderr, "Usage: unsetenv VARIABLE\n");
            }
            return 4;
        }
        else
        {
            if (chdir(command[1]) == 0)
            {
                getcwd(cwd, sizeof(cwd));
                setenv("PWD", cwd, 1);
                *prev_dir = cwd;
            }
            else
            {
                perror("cd");
            }
        }
        return 5;
    }

    return status;
}
