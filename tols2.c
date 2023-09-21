#include "shell.h"
/**
 * my_itoa - Convert an integer to a string.
 * @str: The destination string to store the result.
 * @num: The integer to convert.
 *
 * Return: The number of digits in the converted integer.
 */
void print_env() 
{
    extern char **__environ;
    int i;

    if (!environ)
    {
        environ = (char **)__environ;
    }

    for (i = 0; environ[i] != NULL; i++)
    {
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(STDOUT_FILENO, "\n", 1);
    }
}
