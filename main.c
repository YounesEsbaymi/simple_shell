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
	int result;
	(void)ac;
	
	while (1)
	{
		line = _read();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		if (line[0] == '\0' || (line[0] == '\0' && line[1] == '\0'))
		{
			free(line);
			continue;
		}
		i++;
		command = splitLine(line);
		if (!command)
		{
			free(line);
			continue;
		}
		if (is_builtin(command[0]))
		{
			result = execute_builtin(command);
			if (result == 1)
				break;
			else if (result == 2)
				print_env();
		}
		else
			status = _execute(command, av, i);
		free(line);
	}
	return (0);
}
