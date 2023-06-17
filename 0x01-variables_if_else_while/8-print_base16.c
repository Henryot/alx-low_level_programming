#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Prints the last digit of a randomly generated number
 * and provides additional information about the digit.
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int digit;

	for (digit = 0; digit < 16; digit++)
	{
		if (digit < 10)
		{
			putchar(digit + '0');
		}

		else
		{
			 putchar(digit + 'a' - 10);
		}

	}

	putchar('\n');
	return (0);

}
