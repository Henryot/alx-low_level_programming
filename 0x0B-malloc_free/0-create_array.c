#include <stdlib.h>

/**
 * create_array - creates an array of chars and i
 * @size: the size of the array
 * @c: the char to initialize the array with
 *
 * Return: a pointer to the allocated array, or NULL if it fails
 */
char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *array;

	if (size == 0)
		return (NULL);

	array = malloc(sizeof(char) * size);
	if (array == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = c;

	return (array);
}
