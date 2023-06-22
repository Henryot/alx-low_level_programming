#include <stdio.h>

/**
 * print_fibonacci - we are going to print
 * @n: is the parameter used
 * Return: it is always zero
 */

void print_fibonacci(int n)
{
	unsigned long long int first = 1;
	unsigned long long int second = 2;
	unsigned long long int next;
	unsigned long long int i;

	printf("%llu, %llu, ", first, second);

	for (i = 3; i <= n; i++)
	{
		next = first + second;
		printf("%llu", next);

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
