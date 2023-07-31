#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t linked list safely (detects loops).
 * @h: Pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *tmp;
	listint_t *visited[1024];

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;

	while (current != NULL)
	{
		size_t i;

		/* Check for loops */
		for (i = 0; i < count; i++)
		{
			if (current == visited[i])
			{
				*h = NULL; /* Set head to NULL to avoid further access */
				return (count);
			}
		}

		visited[count] = current;
		tmp = current;
		current = current->next;
		free(tmp);
		count++;
	}

	*h = NULL; /* Set head to NULL to avoid further access */
	return (count);
}
