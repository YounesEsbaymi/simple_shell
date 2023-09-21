#include "shell.h"


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
        return NULL;
    }

    token = _strtok(line, " \t\n");
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

        token = _strtok(NULL, " \t\n");
    }
    command[i] = NULL;
    return (command);
}