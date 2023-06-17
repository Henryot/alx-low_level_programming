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
	int first_digit, second_digit;
        
	for (first_digit = '0'; first_digit <= '9'; first_digit++)
	{
		for (second_digit = first_digit; second_digit <= '9'; second_digit++)
		{
			putchar(first_digit);
			putchar(second_digit);

			if (first_digit != '9' || second_digit != '9')
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
		putchar('\n');
		return (0);
}
