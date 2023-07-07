#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring in a string
 * @haystack: The string to search in
 * @needle: The substring to find
 *
 * Return: A pointer to the beginning of the substring in haystack,
 * or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j;

	if (*needle == '\0')
		return (haystack);

	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			for (j = 0; needle[j] != '\0'; j++)
			{
				if (haystack[i + j] != needle[j])
					break;
			}

			if (needle[j] == '\0')
				return (&haystack[i]);
		}
	}

	return (NULL);
}
