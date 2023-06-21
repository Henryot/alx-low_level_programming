#include <stdio.h>

/**
 * print_fibonacci - we are going to print
 * @n: is the parameter used
 * Return: it is always zero
 */

void print_fibonacci(int n)
{
	int first = 1;
	int second = 2;
	int next;
	int i;

	printf("%d, %d, ", first, second);

	for (i = 3; i <= n; i++)
	{
		next = first + second;
		printf("%d", next);

		if (i != n)
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
