#include "shell.h"

char    *_getline(void)
{
    char	*buffer = NULL;
	size_t	buf_size = 0;
	int		n_char = 0;

	write(1, "$ ", 2);
	n_char = getline(&buffer, &buf_size, stdin);
	if (n_char == EOF)
		perror("getline");
	buffer[n_char - 1] = '\0';

	return (buffer);
}
