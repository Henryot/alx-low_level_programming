#include <stdio.h>

/**
 * main - it calls the function
 * print_fibonacci: Prints the sum of even-valued Fibonacci sequence
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

	printf("%u, %u", num1, num2);

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
	return (0);
}

