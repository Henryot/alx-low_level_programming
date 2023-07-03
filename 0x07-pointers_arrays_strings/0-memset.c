#include "main.h"

/**
 * _memset - the funtion
 * @s: charcter variable
 * @b: another charcter variable
 * @n: integer varaible
 * Return: return is always s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}

	return (s);
}
