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

void printError(char *shell, char *cmd, int i)
{
    char *idx;
    char err[] = ": not found\n";

    idx = convert_and_reverse(i);

    write(STDERR_FILENO, shell, _strlen(shell));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, idx, _strlen(idx));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, cmd, _strlen(cmd));
    write(STDERR_FILENO, err, _strlen(err));

    free(idx);
}

char *convert_and_reverse(int n)
{
    char buffer[21];
    int i = 0;
    int start = 0;
    int end;
    char tmp;

    if (n == 0)
    {
        buffer[i++] = '0';
    }
    else
    {
        while (n > 0)
        {
            buffer[i++] = (n % 10) + '0';
            n /= 10;
        }
    }

    buffer[i] = '\0';
    end = i - 1;

    while (start < end)
    {
        tmp = buffer[start];
        buffer[start] = buffer[end];
        buffer[end] = tmp;
        start++;
        end--;
    }

    return _strdup(buffer);
}
