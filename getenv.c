#include "shell.h"

/**
 * _getenv - function searches for a specific env variable and returns
 * its value
 * @env_var: env string
 * Return: returns the variable if found, otherwise 'NULL'
 */

char *_getenv(char *env_var)
{
	int i, var_len;
	char *temp, *key, *val, *env;

	i = 0;
	var_len = _strlen(env_var);
	while (environ[i])
	{
		temp = _strdup(environ[i]);
		key = strtok(temp, "=");
		if (_strncmp(env_var, key, var_len) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(temp), temp = NULL;
			return (env);
		}
		free(temp), temp = NULL;
		i++;
	}
	return (NULL);
}
