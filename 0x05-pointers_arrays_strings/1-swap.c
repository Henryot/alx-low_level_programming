#include "main.h"
/**
 * swap_int - function for swapping integers
 * @a: first integer
 * @b: second integer
 * Return: return is not applicable
 */


void swap_int(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}
