#include "main.h"

/**
 * times_table - functions that print the multiplication table
 * return: it doest return anything
 */

void times_table(void)
{
	int row, column;

	for (row = 0; row <= 9; row++)
	{
		for (column = 0; column <= 9; column++)
		{
			int multiplication_value = row * column;
			int tens_digit = multiplication_value / 10;
			int ones_digit = multiplication_value % 10;

			if (column != 0)
			{
				_putchar(',');
				_putchar(' ');
			}
			if (multiplication_value < 10)
				_putchar(' ');
			else
				_putchar('0' + tens_digit);
			_putchar('0' + ones_digit);
		}
	
	_putchar('\n');
	}
}

