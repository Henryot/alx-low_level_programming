#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at the given index of a listint_t linked list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be deleted (starts at 0).
 *
 * Return: 1 if succeeded, -1 if failed.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *temp;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0) /* Delete the first node */
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	current = *head;

	for (i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL) /* Invalid index */
		return (-1);

	/* Delete the node at the given index */
	temp = current->next;
	current->next = temp->next;
	free(temp);

	return (1);
}
