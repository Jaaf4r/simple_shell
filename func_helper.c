#include "shell.h"

void _free2dArr(char **arr);
void error_handle(char *name, char *cmd, int indx);
char *_itoa(int num);
void str_rev(char *str, int len);

void _free2dArr(char **arr)
{
	int	i = 0;

	if (!arr)
		return;

	while (arr[i])
	{
		free(arr[i]), arr[i] = NULL;
		i++;
	}
	free(arr), arr = NULL;
}

void error_handle(char *name, char *cmd, int indx)
{
	char *_index = _itoa(indx);
	char err_msg[] = ": not found\n";

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, _index, _strlen(_index));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, err_msg, _strlen(err_msg));

	free(_index);
}

char *_itoa(int num)
{
	int i = 0;
	char buffer[20];

	if (num == 0)
		buffer[i++] = '0';
	else
	{
		while (num > 0)
		{
			buffer[i++] = (num % 10) + '0';
			num /= 10;
		}
	}
	buffer[i] = '\0';
	str_rev(buffer, i);
	return (_strdup(buffer));
}

void str_rev(char *str, int len)
{
	int start = 0, end = len - 1;
	char temp;

	while (end > start)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}
