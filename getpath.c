#include "shell.h"

/**
 * _getpath - Get the full path of a command.
 * @command: The command to find the full path for.
 *
 * Return: The full path of the command if found, otherwise NULL.
 */
char *_getpath(const char *command)
{
	const char *path;
	const char *token;
	struct stat st;
	char cmd_path[1024];
	char *path_copy;
	int i = 0;

	if (command == NULL)
		return (NULL);
	for (i = 0; command[i]; i++)
	{
		if (command[i]== '/')
		{
			if (stat(command, &st) == 0)
				return (_strdup(command));
			else
				return (NULL);
		}
	}
	path = _getenv("PATH");

	if (!path)
		return (NULL);
	path_copy = _strdup(path);
	if (!path_copy)
		return (NULL);
	token = _strtok(path_copy, ":");
	while (token)
	{
		_snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, command);

		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			return (_strdup(cmd_path));
		}
		token = _strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
