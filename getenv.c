#include "shell.h"


char *_getenv(const char *name)
{
	const char *env_str;
	const char *value;
	int i = 0;
	size_t key_len;

	for (i = 0; environ[i]; i++)
	{
		env_str = environ[i];
		value = _strchr(env_str, '=');

		if (!value)
		{
			continue;
		}

		key_len = value - env_str;
		if (_strncmp(env_str, name, key_len) == 0 && name[key_len] == '\0')
		{
			return ((char *)(value + 1));
		}
	}

	return (NULL);
}

char *_getpath(const char *command)
{
	const char *path;
	const char *token;
	struct stat st;
	char cmd_path[1024];
	char *path_copy;
	int i = 0;

	if (command == NULL)
	{
		return (NULL);
	}

	for (i = 0; command[i]; i++)
	{
		if (command[i]== '/')
		{
			if (stat(command, &st) == 0)
			{
				return (_strdup(command));
			}
			else
			{
				return (NULL);
			}
		}
	}

	path = _getenv("PATH");

	if (!path)
	{
		return (NULL);
	}

	path_copy = _strdup(path);
	if (!path_copy)
	{
		return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token)
	{
		_snprintf(cmd_path, sizeof(cmd_path), "%s/%s", token, command);

		if (stat(cmd_path, &st) == 0)
		{
			free(path_copy);
			return _strdup(cmd_path);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return NULL;
}
