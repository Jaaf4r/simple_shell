#include "shell.h"

/**
 * _getline - function that stores the input that user type
 * Return: returns the string
 */

char *_getline(void)
{
	char *buffer = NULL;
	size_t buf_size = 0;
	int char_r = 0;

	write(1, "$ ", 2);
	char_r = getline(&buffer, &buf_size, stdin);
	if (char_r == -1)
	{
		perror("getline");
		free(buffer);
		return (NULL);
	}

	if (char_r > 0 && buffer[char_r - 1] == '\n')
		buffer[char_r - 1] = '\0';

	return (buffer);
}
