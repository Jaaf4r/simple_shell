#include "shell.h"

/**
 * _getline - function that stores the input that user type
 * Return: returns the string
 */

char *_getline(void)
{
	char *buffer = NULL;
	size_t buf_size = 0;
	ssize_t char_r = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	char_r = getline(&buffer, &buf_size, stdin);
	if (char_r == -1)
	{
		free(buffer), buffer = NULL;
		return (NULL);
	}
	return (buffer);
}
