#include "main.h"

/**
 * print_square - Prints a square of a given size
 * @size: The size of the square
 *
 * Description: If size is 0 or less, the function only prints a new line.
 * The square is formed using the character '#', and each side of the square
 * has a length equal to the size.
 */
void print_square(int size)
{
	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		int i, j;

		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				_putchar('#');
			}
		_putchar('\n');
		}
	}
}

