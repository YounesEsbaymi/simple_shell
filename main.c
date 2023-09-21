#include "shell.h"

/**
 * main - Entry point for the shell program.
 * @ac: The number of command-line arguments.
 * @av: An array of strings containing the arguments.
 *
 * Return: The exit status of the shell program.
 */
int main(int ac, char **av)
{
    char *line = NULL;
    char **command = NULL;
    int status = 0;
    int i = 0;
    char *prev_dir = NULL;
    int result;

    (void)ac;

    while (1)
    {
        if (isatty(STDIN_FILENO))
        {
            write(STDOUT_FILENO, "$ ", 2);
        }
        line = _read();
        if (line == NULL)
        {
            if (isatty(STDIN_FILENO))
            {
                write(STDOUT_FILENO, "\n", 1);
            }
            break;
        }
        i++;

        command = splitLine(line);
        if (!command)
        {
            free(line);
            continue;
        }

        result = execute_builtin(command, &prev_dir);
        if (result == 1)
        {
            break;
        }
        else if (result == 2)
        {
            print_env();
        }

        status = _execute(command, av, i);

        free(line);
    }
    return (status);
}

