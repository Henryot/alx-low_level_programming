#include <stdlib.h>
#include "main.h"
/**
 * argstostr - concatenates all the arguments of a program
 * @ac: the number of arguments
 * @av: an array of argument strings
 *
 * Return: a pointer to the concatenated string, or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char *concatenated;
	int totalLength = 0;
	int i, j;
	int index = 0;

	if (ac == 0 || av == NULL)
		return NULL;

	/* Calculate the total length of the arguments */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
			totalLength++;
		totalLength++; /* Account for the newline character */
	}

	/* Allocate memory for the concatenated string */
	concatenated = malloc(sizeof(char) * (totalLength + 1));
	if (concatenated == NULL)
		return NULL;

	/* Copy the arguments to the concatenated string */
	for (i = 0; i < ac; i++)
	{
		for (j = 0; av[i][j] != '\0'; j++)
		{
			concatenated[index] = av[i][j];
			index++;
		}
		concatenated[index] = '\n';
		index++;
	}

	concatenated[index] = '\0'; /* Add null terminator at the end */

	return concatenated;
}
