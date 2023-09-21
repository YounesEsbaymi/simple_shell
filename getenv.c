#include "shell.h"

/**
 * _getenv - Get the value of an environment variable.
 * @name: The name of the environment variable.
 *
 * Return: The value of the environment variable if found, otherwise NULL.
 */
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
