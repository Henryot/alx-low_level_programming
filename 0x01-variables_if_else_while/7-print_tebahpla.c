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
	int ascii_value;

	for (ascii_value = 122; ascii_value >= 97; ascii_value--)
	{
		putchar(ascii_value);
	}
	putchar('\n');
	return (0);

}
