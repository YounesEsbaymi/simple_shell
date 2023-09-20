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
	(void)ac;
	for (;;)
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
			return (status);
		}

		command = splitLine(line);
		if (!command)
		{
			free(line);
			continue;
		}

		status = _execute(command, av);

		free(line);
	}
}
