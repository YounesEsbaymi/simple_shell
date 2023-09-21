#include "shell.h"
/**
 * _read - Read a line of text from standard input.
 *
 * Return: A pointer to the read line.
 */

char *_read(void)
{
	size_t len = 0;
	char *line = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read = _getline(&line, &len, stdin);
	if (read == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
