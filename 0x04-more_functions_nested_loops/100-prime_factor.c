#include <stdio.h>
#include <math.h>

/**
 * largest_prime_factor - Finds the largest prime factor of a number
 * @n: The number to find the largest prime factor of
 *
 * Return: The largest prime factor
 */
unsigned long largest_prime_factor(unsigned long n)
{
	unsigned long i;

	while (n % 2 == 0)
	{
		n /= 2;
	}

	for (i = 3; i <= sqrt(n); i += 2)
	{
		while (n % i == 0)
		{
			n /= i;
		}
	}

	if (n > 2)
	{
		return (n);
	}

	return (i);
}
/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long number = 612852475143;
	unsigned long largest_factor = largest_prime_factor(number);

	printf("%lu\n", largest_factor);

	return (0);
}
