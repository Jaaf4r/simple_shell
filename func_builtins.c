#include "shell.h"

/**
 * _builtin - function
 * @cmmd: cmmd
 * Return: return 0, otherwise 1
 */
int _builtin(char *cmmd)
{
	int i = 0;

	char *builtin_funcs[] = {
		"exit",
		"env",
		"setenv",
		"unsetenv",
		"cd",
		NULL
	};

	while (builtin_funcs[i])
	{
		if (_strncmp(cmmd, builtin_funcs[i], _strlen(cmmd)) == 0)
			return (1);
		i++;
	}
	return (0);
}

/**
 * builtins_handler - function
 * @cmmd: cmmd
 * @av: av
 * @status: status
 * @indx: index
 */
void builtins_handler(char **cmmd, char **av, int *status, int indx)
{
	int cmmd_len = _strlen(cmmd[0]);

	if (_strncmp(cmmd[0], "exit", cmmd_len) == 0)
		e_xit(cmmd, av, status, indx);
	else if (_strncmp(cmmd[0], "env", cmmd_len) == 0)
		_write_env(cmmd, status);
}

/**
 * e_xit - function
 * @cmmd: cmmd
 * @av: av
 * @status: status
 * @indx: index
 */
void e_xit(char **cmmd, char **av, int *status, int indx)
{
	char *inndex;
	char err_msg[] = ": exit: Illegal number: ";
	int exit_v = (*status);

	if (cmmd[1])
	{
		if (is_positive(cmmd[1]))
		{
			exit_v = _atoi(cmmd[1]);
		}
		else
		{
			inndex = _itoa(indx);
			write(STDERR_FILENO, av[0], _strlen(av[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, inndex, _strlen(inndex));
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			write(STDERR_FILENO, cmmd[1], _strlen(cmmd[1]));
			write(STDERR_FILENO, "\n", 1);

			(*status) = 2;
			free(inndex);
			_free2dArr(cmmd);
			return;
		}
	}
	_free2dArr(cmmd);
	exit(exit_v);
}

/**
 * _write_env - function
 * @cmmd: cmmd
 * @status: status
 */
void _write_env(char **cmmd, int *status)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	(*status) = 0;
	_free2dArr(cmmd);
}
