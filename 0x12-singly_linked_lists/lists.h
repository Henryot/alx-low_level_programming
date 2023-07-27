#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - Structure for the linked list nodes
 * @str: Pointer to a string (node data)
 * @len: Length of the string
 * @next: Pointer to the next node
 *
 * Description: A singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Function prototypes */
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);

#endif /* LISTS_H */
