#include "shell.h"

/**
 * get_cmd - function that gives the command line
 * @cmd: string
 * Return: the command line, otherwise 'NULL'
 */

char *get_cmd(char *cmd)
{
	char *path = _getenv("PATH");
	char *token, *path_copy, *full_cmd;
	struct stat st;

	if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode))
		return (_strdup(cmd));

	path_copy = _strdup(path);
	if (path_copy == NULL)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_cmd = malloc(_strlen(token) + _strlen(cmd) + 2);
		if (full_cmd == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		_strcpy(full_cmd, token);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, cmd);
		if (stat(full_cmd, &st) == 0 && S_ISREG(st.st_mode))
		{
			free(path_copy);
			return (full_cmd);
		}
		free(full_cmd);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
