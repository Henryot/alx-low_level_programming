#include "main.h"

/**
 * print_number - Prints an integer
 * @n: The integer to print
 */
void print_number(int n)
{
	int digit, is_negative;

	is_negative = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	else if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	if (is_negative)
		_putchar('-');

	if (n >= 10)
		print_number(n / 10);

	digit = n % 10;
	_putchar(digit + '0');
}
