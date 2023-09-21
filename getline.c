#include "shell.h"

/**
 * _getline - Read a line from a stream.
 * @line: A pointer to a buffer where the line will be stored.
 * @line_size: A pointer to the size of the buffer.
 * @stream: The input stream to read from.
 *
 * Return: The number of characters read (including the newline character),
 * or -1 on end of file, or 0 on error.
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
            return (0);
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
                return (0);
        }
    }
    if (c == EOF && length == 0)
        return (-1);
    (*line)[length] = '\0';
    return (length);
}
