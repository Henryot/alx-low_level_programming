#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: A pointer to the head of the dlistint_t list.
 * @index: The index of the dlistint_t node to get.
 *
 * Return: If the node does not exist, return NULL.
 *         Otherwise, the address of the nth node.
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int count = 0;

	while (head && count < index)
	{
		head = head->next;
		count++;
	}

	if (!head)
		return (NULL);

	return (head);
}
