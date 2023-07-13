#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings
 * @s1: The first string
 * @s2: The second string
 * @n: The number of bytes to concatenate from s2
 *
 * Return: A pointer to the newly allocated concatenated string
 *         NULL if the function fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *concat;
	unsigned int s1_len = 0, s2_len = 0, concat_len = 0;
	unsigned int i, j;

	/* Check if s1 is NULL, treat it as an empty string */
	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;

	/* Adjust n if it's greater or equal to the length of s2 */
	if (n >= s2_len)
		n = s2_len;

	/* Calculate the length of the concatenated string */
	concat_len = s1_len + n;

	/* Allocate memory for the concatenated string */
	concat = malloc(sizeof(char) * (concat_len + 1));
	if (concat == NULL)
		return (NULL);

	/* Copy s1 to the concatenated string */
	for (i = 0; i < s1_len; i++)
		concat[i] = s1[i];

	/* Copy n bytes of s2 to the concatenated string */
	for (j = 0; j < n; j++)
		concat[i + j] = s2[j];

	/* Add the null terminator */
	concat[concat_len] = '\0';

	return (concat);
}
