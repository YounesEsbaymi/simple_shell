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
#include <stdarg.h>
#include <limits.h>

#define MAX_TOKENS 100
extern char **environ;

int main(int ac, char **av);
char *_read(void);
char **splitLine(char *line);
size_t _getline(char **line, size_t *line_size, FILE *stream);
int _execute(char **command, char **av, int i);



char* _strdup(const char* source);
int _strcmp(const char* str1, const char* str2);
size_t _strlen(const char* str);
char* _strcat(const char* str1, const char* str2);
char* _strcpy(char* dest, const char* src);

void _freearr(char **arr);
char *_getenv(const char *name);
char *_strchr(const char *str, int ch);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_getpath(const char *command);
int my_itoa(char *str, int num);
int _snprintf(char *str, size_t size, const char *format, ...);
void printError(char *shell, char *cmd, int i);
char *convert_and_reverse(int n);

char *_strtok(char *str, const char *delimiter);
int execute_builtin(char **command, char **prev_dir);
void print_env();

#endif