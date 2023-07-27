#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/* Structure for the linked list nodes */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/* Function prototypes */
size_t print_list(const list_t *h);

#endif /* LISTS_H */
