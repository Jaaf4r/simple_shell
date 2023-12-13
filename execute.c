#include "shell.h"

/**
 * _exec - Executes a command from the command line.
 * @cmd: The array of commandline args.
 * @av: The array of commandline args.
 * @indx: The index of the command to execute.
 * Return: The exit status of the command.
*/

int _exec(char **cmd, char **av, int indx)
{
	pid_t pid;
	int status;
	char *full_cmmd;

	full_cmmd = get_path(cmd[0]);
	if (!full_cmmd)
	{
		error_handle(av[0], cmd[0], indx);
		_free2dArr(cmd);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(full_cmmd, cmd, environ) == -1)
		{
			free(full_cmmd), full_cmmd = NULL;
			_free2dArr(cmd);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		_free2dArr(cmd);
		free(full_cmmd);
		full_cmmd = NULL;
	}
	return (WEXITSTATUS(status));
}
