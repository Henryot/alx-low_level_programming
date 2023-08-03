#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int check = 1;
	char *ptr = (char *)&check;

	/* If the value at the first byte (lowest address) is 1, it's little endian */
	return (*ptr);
}
