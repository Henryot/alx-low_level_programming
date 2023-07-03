#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - Searches a string for any of a set of bytes.
 * @s: The string to be searched.
 * @accept: The string containing the bytes to search for.
 *
 * Return: A pointer to the byte in 's' that matches one of the bytes in
 *         'accept', or NULL if no such byte is found.
 */
char *_strpbrk(char *s, char *accept)
{
	char *p;

	for (; *s != '\0'; s++)
	{
		for (p = accept; *p != '\0'; p++)
		{
			if (*s == *p)
				return (s);
		}
	}

	return (NULL);
}
