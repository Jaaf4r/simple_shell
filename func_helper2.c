#include "shell.h"

int is_positive(char *str);
int _atoi(char *str);

/**
 * is_positive - function checks if str index positive
 * @str: ptr to str
 * Return: returns 1 if true, otherwise 0
 */
int is_positive(char *str)
{
	int i = 0;

	if (!str)
		return (0);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}

	return (1);
}

/**
 * _atoi - function returns alphabet to int
 * @str: ptr to str
 * Return: int
 */
int _atoi(char *str)
{
	int i = 0, sign = 1, number = 0;

	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;

	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;

	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += str[i] - '0';
		i++;
	}
	return (number * sign);
}
