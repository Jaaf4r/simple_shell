#include "shell.h"

/**
 * _getenv - function searches for a specific env variable and returns
 * its value
 * @env_var: env string
 * Return: returns the variable if found, otherwise 'NULL'
 */

char *_getenv(const char *env_var)
{
	int i, len;

	i = 0;
	len = _strlen(env_var);
	while (environ[i])
	{
		if (_strncmp(env_var, environ[i], len) == 0)
			return (environ[i]);
		i++;
	}

	return (NULL);
}
