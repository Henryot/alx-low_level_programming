#include "main.h"

/**
 * print_sign - prints sign based on input
 * n: is the argument
 * Return: is 1 if its + and - if its -1 else return 0
 */

int print_sign(int n)

{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n < 0)
	{
		_putchar('-');
		return(-1);
	}
	else
	{
		_putchar('0');
		return (0);
	}

}
