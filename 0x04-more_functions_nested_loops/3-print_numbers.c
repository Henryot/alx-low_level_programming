#include "main.h"
#include <stdio.h>

/**
 * print_numbers - its gonna print numbers
 * Return: point of no return
 */

void print_numbers(void)
{
	int i;

	for (i = 0; i <= 9; i++)
	{
		_putchar(i + '0');
	}
	_putchar('\n');
}

