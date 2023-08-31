#include "main.h"

/**
 * get_endianness - checks endianness of the machine.
 *
 * Return: 1 if little endian, 0 if big endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *c = (char *)&num;

	return (*c);
}
