#include "shell.h"

char *_strdup(const char *str)
{
    size_t len;
    char *new_str;
    if (str == NULL)
    {
        return (NULL);
    }
    len = _strlen(str) + 1;

    new_str = (char *)malloc(len);
    if (new_str == NULL)
    {
        return (NULL);
    }
    strcpy(new_str, str);

    return (new_str);
}

size_t _strlen(const char *str)
{
    size_t length = 0;
    
    while (*str != '\0')
    {
        length++;
        str++;
    }

    return (length);
}


char* _strcat(const char* str1, const char* str2)
{
    
    size_t len1 = _strlen(str1);
    size_t len2 = _strlen(str2);

    
    char* result = (char*)malloc(len1 + len2 + 1);

    if (result != NULL)
    {
        
        _strcpy(result, str1);
        
        _strcpy(result + len1, str2);
    }

    return (result);
}

char* _strcpy(char* dest, const char* src)
{
    char* original_dest = dest;

    
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }

    
    *dest = '\0';

    return (original_dest);
}
int _strcmp(const char* str1, const char* str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2) {
            return (*str1 - *str2);
        }
        str1++;
        str2++;
    }

    return (0);
}
