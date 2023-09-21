#include "shell.h"

/**
 * is_builtin - Check if a command is a built-in shell command.
 * @command: The command to check.
 *
 * Return: 1 if it's a built-in command, 0 otherwise.
 */
int is_builtin(char *command) {
    if (_strcmp(command, "cd") == 0 || _strcmp(command, "exit") == 0 ||
        _strcmp(command, "env") == 0 || _strcmp(command, "setenv") == 0 ||
        _strcmp(command, "unsetenv") == 0) {
        return 1;
    }
    return 0;
}

/**
 * execute_builtin - Execute a built-in shell command.
 * @command: An array of command arguments.
 * @prev_dir: A pointer to the previous working directory.
 *
 * Return: The exit status of the command or 0 if not a built-in command.
 */
int execute_builtin(char **command)
{
    /*char *home_dir;
    char cwd[PATH_MAX];*/
    int status = 0;

    if (command[0] == NULL || !is_builtin(command[0]) || _strcmp(command[0], " ") == 0)
    {
        return status;
    }

    if (_strcmp(command[0], "exit") == 0)
    {
        if (command[1] == NULL) {
            exit(0);
        } else {
            int exit_status = atoi(command[1]);
            exit(exit_status);
        }
    }
    else if (_strcmp(command[0], "env") == 0)
    {
        print_env();
        return 2;
    }
    else if (_strcmp(command[0], "cd") == 0)
    {
        return 3;
    }
    else if (_strcmp(command[0], "setenv") == 0)
    {
        return 4;
    }
    else if (_strcmp(command[0], "unsetenv") == 0)
    {
        return 5;
    }

    return status;
}
