#include <stdio.h>

int sqrt_helper(int n, int start, int end);

/**
 * _sqrt_recursion - Calculates the square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The square root of the number if it is a perfect square,
 *         -1 otherwise.
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	return (sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - Recursive helper function to calculate square root.
 * @n: The number to calculate the square root of.
 * @start: The starting point of the range to search for the square root.
 * @end: The ending point of the range to search for the square root.
 *
 * Return: The square root of the number if it is a perfect square,
 *         -1 otherwise.
 */
int sqrt_helper(int n, int start, int end)
{
	int mid;

	if (start > end)
		return (-1);

	mid = (start + end) / 2;

	if (mid * mid == n)
		return (mid);

	if (mid * mid > n)
		return (sqrt_helper(n, start, mid - 1));

	return (sqrt_helper(n, mid + 1, end));
}
