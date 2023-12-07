#include "shell.h"

char    **split_string(char *buffer, char   *del)
{
    char    **tokens;
    char    *token;
    int i = 0;

    tokens = malloc(sizeof(char *) * 1024);
    token = strtok(buffer, " \t\n");
    while (token)
    {
        tokens[i] = token;
        token = strtok(NULL, del);
        i++;
    }
    tokens[i] = NULL;
    return (tokens);
}
