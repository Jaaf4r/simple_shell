#include "shell.h"

/**
 * main - function that executes input we type and gives us the output
 * @ac: size of av
 * @av: array size of ac
 * @env: environment
 * Return: returns (0) in Success
 */

int main(int ac, char **av)
{
	char *buffer = NULL, **cmmd = NULL;
	int status = 0, i = 0;
	(void)ac;

	while (1)
	{
		buffer = _getline();
		if (buffer == NULL)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		i++;

		cmmd = _split(buffer);
		if (!cmmd)
			continue;

		if (_builtin(cmmd[0]))
			builtins_handler(cmmd, av, &status, i);
		else
			status = _exec(cmmd, av, i);
	}
}
