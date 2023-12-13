#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

/* PROGRAM FUNCTIONS */
char *_getline(void);
char **_split(char *buffer);
int _exec(char **cmd, char **av, int i_ndex);
char *_getenv(char *env_var);
char *get_path(char *cmd);

/* BUILTINS */
int _builtin(char *cmmd);
void builtins_handler(char **cmmd, char **av, int *status, int indx);
void e_xit(char **cmmd, char **av, int *status, int indx);
void _write_env(char **cmmd, int *status);

/* FUNCTION HELPER */
void _free2dArr(char **arr);
void error_handle(char *name, char *cmd, int indx);
char *_itoa(int num);
void str_rev(char *str, int len);
int is_positive(char *str);
int _atoi(char *str);

/* STRING FUNCTIONS */
int _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *s1, const char *s2, unsigned int n);
char *_strdup(char *src);

#endif /* _SHELL_H */
