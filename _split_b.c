#include"shell.h"

/**
 * _split - function that splits 'buffer' by 'del'
 * @buffer: string
 * Return: returns array of strings
 */

char **_split(char *buffer)
{
	int i = 0, count = 0;
	char *token = NULL, *temp = NULL;
	char **tokens = NULL;

	if (!buffer)
		return (NULL);

	temp = _strdup(buffer);
	token = strtok(temp, DELIM);
	if (!token)
	{
		free(buffer), buffer = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		count++;
		token = strtok(NULL, DELIM);
	}
	free(temp), temp = NULL;

	tokens = malloc(sizeof(char *) * (count + 1));
	if (!tokens)
	{
		free(buffer), buffer = NULL;
		return (NULL);
	}

	token = strtok(buffer, DELIM);
	while (token)
	{
		tokens[i] = _strdup(token);
		token = strtok(NULL, DELIM);
		i++;
	}
	free(buffer), buffer = NULL;
	tokens[i] = NULL;
	return (tokens);
}
