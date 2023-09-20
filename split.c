#include "shell.h"

/**
 * splitLine - Splits a string into an array of tokens.
 * @line: The input string to be split.
 *
 * Return: An array of tokens (strings), or NULL on failure.
 */

char **splitLine(char *line)
{
	int bufsize = MAX_TOKENS;
	char **command;
	char *token;
	int i = 0;

	command = malloc(bufsize * sizeof(char *));
	if (!command)
	{
		free(line);
		return (NULL);
	}

	token = strtok(line, " \t\n");
	while (token != NULL)
	{
		command[i] = _strdup(token);
		if (!command[i])
		{
			free(command);
			free(line);
			return (NULL);
		}
		i++;

		if (i >= bufsize)
		{
			bufsize += MAX_TOKENS;
			command = realloc(command, bufsize * sizeof(char *));
			if (!command)
			{
				free(command);
				free(line);
				return (NULL);
			}
		}

		token = strtok(NULL, " \t\n");
	}
	command[i] = NULL;
	return (command);
}
