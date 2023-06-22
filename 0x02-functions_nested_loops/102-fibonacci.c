#include <stdio.h>

/**
 * print_fibonacci - we are going to print
 * @n: is the parameter used
 * Return: it is always zero
 */

void print_fibonacci(int n)
{
	unsigned long first = 1;
	unsigned long second = 2;
	unsigned long next;
	int i;

	printf("%lu, %lu, ", first, second);

	for (i = 3; i <= (unsigned long)n; i++)
	{
		next = first + second;
		printf("%lu", next);

		if (i != (unsigned long)n)
		{
		printf(", ");
		}

		first = second;
		second = next;
	}

	printf("\n");
}

int main(void)
{
	int n = 50;

	print_fibonacci(n);

	return 0;
}
