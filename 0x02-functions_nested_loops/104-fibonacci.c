#include <stdio.h>

/**
 * main - it calls the function
 * print_fibonacci: Prints the sum of even-valued Fibonacci sequence
 *        terms not exceeding 4000000.
 *
 * Return: Always 0.
 */


int main (void)
{
	unsigned long int num1 = 1;
	unsigned long int num2 = 2;
	unsigned long int i;
	unsigned long int next;

	printf("%lu, ", num1);
	printf("%lu, ", num2);
    
	for (i = 3; i <= 98; i++)
	{
		next = num1 + num2;
		printf("%lu, ", next);
        
		num1 = num2;
		num2 = next;
	}
	printf("\n");
	return 0;
}
