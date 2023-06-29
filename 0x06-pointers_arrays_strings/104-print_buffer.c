#include <stdio.h>
#include "main.h"

/**
 * print_buffer - Prints the content of a buffer
 * @b: Buffer to print
 * @size: Size of the buffer
 */
void print_buffer(char *b, int size)
{
	int i, j, hex_counter = 0;
	char ch;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		printf("%08x: ", hex_counter);

		for (j = i; j < i + 10; j++)
		{
			if (j < size)
				printf("%02x", b[j]);
			else
				printf("  ");

			if (j % 2 != 0)
				printf(" ");
		}
		for (j = i; j < i + 10; j++)
		{
			if (j < size)
			{
				ch = b[j];
				if (ch < 32 || ch > 126)
					ch = '.';
				printf("%c", ch);
			}
			else
			{
				printf(" ");
			}
		}

		printf("\n");
		hex_counter += 10;
	}
}
