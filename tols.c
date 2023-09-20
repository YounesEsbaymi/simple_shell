#include "shell.h"

/**
 * _freearr - Frees the memory allocated for an array of strings.
 * @arr: A pointer to the array of strings to be freed.
 *
 * Return: None.
 */

void _freearr(char **arr)
{
	int i;

	if (!arr)
	{
		return;
	}
	for (i = 0; arr[i]; i++)
	{
		free(arr[i]);
	}
	free(arr);
}
