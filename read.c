#include "shell.h"

char *_read(void)
{
    size_t len = 0;
    char *line = 0;
    ssize_t read;
    read = _getline(&line, &len, stdin);
    if (read == -1)
    {
        free(line);
        return(NULL);
    }
    
    return (line);
}