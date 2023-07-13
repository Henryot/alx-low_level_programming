#include <stdio.h>
#include <stdlib.h>

/**
 * _calloc - Allocates memory for an array using malloc
 * @nmemb: The number of elements in the array
 * @size: The size of each element in bytes
 *
 * Return: A pointer to the allocated memory
 *         NULL if nmemb or size is 0, or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total_size;
	unsigned int i;
	char *temp;
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	temp = (char *)ptr;

	for (i = 0; i < total_size; i++)
		temp[i] = 0;

	return (ptr);
}
