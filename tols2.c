#include "shell.h"

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