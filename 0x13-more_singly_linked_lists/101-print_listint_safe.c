#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list safely (detects loops).
 * @head: Pointer to the head of the list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *current = head;
	size_t count = 0;
	listint_t *visited[1024];

	while (current != NULL)
	{
		size_t i;

		for (i = 0; i < count; i++)
		{
			if (current == visited[i])
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (count);
			}
		}

		visited[count] = (listint_t *)current;
		printf("[%p] %d\n", (void *)current, current->n);
		count++;

		current = current->next;
	}

	return (count);
}
