#include "shell.h"

char    *_getenv(const char *env_var)
{
    extern char **environ;
    int i = 0;
    char    *key;

    while (environ[i])
    {
        key = strtok(environ[i], "=");
        if (strcmp(env_var, key) == 0)
            return (strtok(NULL, "\n"));
        i++;
    }
    return (NULL);
}
