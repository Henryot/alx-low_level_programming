#include <unistd.h>
#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: The string to convert
 *
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int res = 0;
	int i = 0;

	if (s[0] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + (s[i] - '0');
		else
			break;
		i++;
	}

	return (sign * res);
}
