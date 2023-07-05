/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to calculate the square root of.
 *
 * Return: The natural square root of the number.
 *         If n does not have a natural square root, returns -1.
 */
int _sqrt_recursion(int n);
int sqrt_helper(int n, int start, int end);

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1); /* If n is negative, return -1 to indicate an error */
	else if (n == 0 || n == 1)
		return (n); /* Base case: square root of 0 or 1 is the number itself */
	else
		return (sqrt_helper(n, 1, n));
}

/**
 * sqrt_helper - Recursive helper function to calculate the square root.
 * @n: The number to calculate the square root of.
 * @start: The starting point for the search.
 * @end: The ending point for the search.
 *
 * Return: The square root of the number.
 */
int sqrt_helper(int n, int start, int end)
{
	int mid; /* Declare the variable at the beginning */

	if (start > end)
		return (-1); /* The number does not have a natural square root */

	mid = (start + end) / 2; /* Calculate the middle point */

	if (mid * mid == n)
		return (mid); /* Base case: the middle point is the square root */
	else if (mid * mid > n)
		return (sqrt_helper(n, start, mid - 1));
	else
		return (sqrt_helper(n, mid + 1, end));
}

