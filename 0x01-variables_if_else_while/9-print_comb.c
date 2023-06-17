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

	for (digit = '0'; digit <= '9'; digit++)
	{
		putchar(digit);
		if (digit != '9')
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
