#include <stdio.h>
#include "main.h"

/**
 * print_to_98 - a funtion that prints 0 t0 98
 * @n: the parameter used for the count
 * Return: return is 0
 */

void print_to_98(int n)
{
	if (n <= 98)
	{
		while (n <= 98)
		{
			printf("%d", n);
			if (n != 98)
			{
				printf(", ");
			}
			n++;
		}
	}
	else
	{
		while (n >= 98)
		{
			printf("%d", n);
			if (n != 98)
			{
				printf(", ");
			}
			n--;
		}
	}
	printf("\n");
}

