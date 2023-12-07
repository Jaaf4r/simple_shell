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
char    *get_cmd(char   *cmd);
char    **split_string(char *buffer, char   *del);


#endif /* _SHELL_H */
