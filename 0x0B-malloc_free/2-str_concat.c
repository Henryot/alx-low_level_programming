#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concatenated;
	unsigned int length1 = 0, length2 = 0;
	unsigned int i, j;

	/* Handle case when s1 is NULL */
	if (s1 == NULL)
		s1 = "";
	/* Handle case when s2 is NULL */
	if (s2 == NULL)
		s2 = "";

	/* Calculate lengths of s1 and s2 */
	while (s1[length1] != '\0')
		length1++;
	while (s2[length2] != '\0')
		length2++;

	/* Allocate memory for the concatenated string */
	concatenated = malloc(sizeof(char) * (length1 + length2 + 1));
	if (concatenated == NULL)
		return (NULL);

	/* Copy characters from s1 to concatenated */
	for (i = 0; i < length1; i++)
		concatenated[i] = s1[i];

	/* Copy characters from s2 to concatenated */
	for (j = 0; j < length2; j++)
		concatenated[i + j] = s2[j];

	/* Add null terminator at the end */
	concatenated[i + j] = '\0';

	return (concatenated);
}
