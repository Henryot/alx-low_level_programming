#include "main.h"

/**
 * times_table - function that prints the multiplication table
 */
void times_table(void)
{
	int row, column;

	for (row = 0; row <= 9; row++)
	{
		for (column = 0; column <= 9; column++)
		{
			int multiplication_value = row * column;
			
			if (column != 0)
			{
				_putchar(',');
				_putchar(' ');
			}

			if (multiplication_value < 10)
			{
				_putchar(' ');
				_putchar(' ');
				_putchar('0' + multiplication_value);
			}
			else
			{
				_putchar('0' + (multiplication_value / 10));
				_putchar('0' + (multiplication_value % 10));
			}
			if (row == 9)
			{
				_putchar('\n');
			}
		}
	}
}

