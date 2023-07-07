#include "main.h"


/**
 * _memset - fills the first n bytes of the memory area pointed to by s with a constant byte b
 * @s: The memory area to fill
 * @b: The constant byte
 * @n: The number of bytes to fill
 *
 * Return: A pointer to the filled memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
