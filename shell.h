#ifndef MYSHELL_H
#define MYSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define MAX_TOKENS 100
extern char **environ;

int main(int ac, char **av);
char *_read(void);
char **splitLine(char *line);
size_t _getline(char **line, size_t *line_size, FILE *stream);
int _execute(char **command, char **argv);



char* _strdup(const char* source);
int _strcmp(const char* str1, const char* str2);
size_t _strlen(const char* str);
char* _strcat(const char* str1, const char* str2);
char* _strcpy(char* dest, const char* src);

void _freearr(char **arr);


#endif
