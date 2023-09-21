#include "shell.h"

/**
 * _strtok - Custom strtok function.
 * @str: The string to tokenize.
 * @delimiter: The delimiter characters.
 *
 * Return: A pointer to the next token, or NULL if no more tokens are found.
 */
char *_strtok(char *str, const char *delimiter)
{
    static char *nextToken = NULL;
    char *tokenStart;
    char *tokenEnd;

    if (str != NULL)
    {
        nextToken = str;
    }

    if (nextToken == NULL || *nextToken == '\0')
    {
        return NULL;
    }

    tokenStart = nextToken;
    tokenEnd = strpbrk(nextToken, delimiter);

    if (tokenEnd != NULL)
    {
        *tokenEnd = '\0';
        nextToken = tokenEnd + 1;
    }
    else
    {
        nextToken = NULL;
    }

    return tokenStart;
}