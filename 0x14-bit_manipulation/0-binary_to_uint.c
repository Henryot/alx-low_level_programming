#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int.
 * @b: pointer to a string of 0 and 1 chars.
 *
 * Return: the converted number or 0 if:
 * - there's one or more chars in the string b that is not 0 or 1
 * - b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int dec_val;
	int i;

	if (!b)
		return (0);

	dec_val = 0;
	i = 0;

	while (b[i])
	{
		if (b[i] != '0' && b[i] != '1')
			return (0);
		dec_val = dec_val << 1;
		if (b[i] == '1')
			dec_val += 1;
		i++;
	}

	return (dec_val);
}
