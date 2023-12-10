#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>

#define DELIM " \t\n"
extern char **environ;

char    *_getline(void);
char    *_getenv(const char *env_var);
char    *get_cmd(char *cmd);
char    **_split(char *buffer, char *del);

int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, unsigned int n);
char *_strdup(char *src);


#endif /* _SHELL_H */
