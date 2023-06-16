#include <stdlib.h>
#include <time.h>
#include <stdio.h> /* We need this header to use printf */

/**
 * main - Entry point of the program
 *
 * This program assigns a random number to the variable n each time it is executed.
 * It then prints whether the number stored in n is positive, negative, or zero.
 *
 * Return: Always 0 (indicating success)
 */

int main(void)
{
	int n;

	srand(time(0));
	n = rand() - RAND_MAX / 2;

	/* Check if the number is positive */
	if (n > 0)
	{
		printf("%d is positive\n", n);
	}
	/* Check if the number is zero */
	else if (n == 0)
	{
		printf("%d is zero\n", n);
	}
	/* If the number is not positive or zero, it must be negative */
	else
	{
		printf("%d is negative\n", n);
	}

	return (0);
}

