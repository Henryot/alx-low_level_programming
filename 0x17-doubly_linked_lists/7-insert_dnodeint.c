#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a new node at a given index.
 * @h: Double pointer to the head of the list.
 * @idx: The index to insert the new node at.
 * @n: The value for the new node.
 *
 * Return: Address of the new node, or NULL if it fails.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *temp = *h;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	while (temp)
	{
		if (i + 1 == idx)
		{
			new_node->next = temp->next;
			new_node->prev = temp;
			if (temp->next)
				temp->next->prev = new_node;
			temp->next = new_node;
			return (new_node);
		}
		temp = temp->next;
		i++;
	}

	free(new_node);
	return (NULL);
}
