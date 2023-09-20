#include "shell.h"

/**
 * _getline - Reads a line of text from a file stream.
 * @line: A pointer to a pointer that will hold the read line.
 * @line_size: A pointer to the size of the allocated memory.
 * @stream: The file stream to read from.
 *
 * Return: The number of characters read, or -1 on EOF or failure.
 */

size_t _getline(char **line, size_t *line_size, FILE *stream)
{
	size_t length = 0;
	int c;

	if (*line == NULL || *line_size == 0)
	{
		*line_size = 128;
		*line = (char *)malloc(*line_size * sizeof(char));
		if (*line == NULL)
		{
			return (0);
		}
	}

	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		(*line)[length] = (char)c;
		length++;
		if (length >= *line_size)
		{
			*line_size *= 2;
			*line = (char *)realloc(*line, *line_size * sizeof(char));
			if (*line == NULL)
			{
				return (0);
			}
		}
	}

	if (c == EOF && length == 0)
	{
		return (-1);
	}

	(*line)[length] = '\0';
	return (length);
}
