#include <stdio.h>

/**
 * main - Prints the sum of even-valued Fibonacci sequence
 *        terms not exceeding 4000000.
 *
 * Return: Always 0.
 */


void print_fibonacci(void)
{
	int count;
	unsigned int num1, num2, next;
	num1 = 1;
	num2 = 2;

	printf("%u, %u", num1, num2);  // Print the first two Fibonacci numbers

	for (count = 3; count <= 98; count++)
	{
		next = num1 + num2;
		printf(", %u", next);

		num1 = num2;
		num2 = next;
	}

	printf("\n");
}

int main(void)
{
	print_fibonacci();
	return 0;
}

