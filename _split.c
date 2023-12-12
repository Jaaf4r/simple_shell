#include"shell.h"

/**
 * _split - function that splits 'buffer' by 'del'
 * @buffer: string
 * @del: string
 * Return: returns array of strings
 */

char **_split(char *buffer, char *del)
{
	int i;
	char *token, **tokens;
	(void)del;

	tokens = malloc(sizeof(char *) * 1024);

	if (tokens == NULL)
		return (NULL);

	i = 0;
	token = strtok(buffer, DELIM);
	while (token != NULL && i < 1024 - 1)
	{
		tokens[i] = token;
		token = strtok(NULL, DELIM);
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
