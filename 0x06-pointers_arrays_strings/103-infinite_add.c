#include <stdio.h>
#include "main.h"

/**
 * infinite_add - Adds two numbers
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1 = 0, len2 = 0, sum = 0, carry = 0, i = 0;

	while (n1[len1] != '\0')
		len1++;
	while (n2[len2] != '\0')
		len2++;
	if (len1 >= size_r - 1 || len2 >= size_r - 1)
		return (0);
	len1--;
	len2--;
	while (len1 >= 0 || len2 >= 0)
	{
		sum = carry;
		if (len1 >= 0)
			sum += (n1[len1] - '0');
		if (len2 >= 0)
			sum += (n2[len2] - '0');
		carry = sum / 10;
		sum %= 10;
		r[i] = sum + '0';
		i++;
		len1--;
		len2--;
	}
	if (carry)
	{
		if (i >= size_r - 1)
			return (0);

		r[i] = carry + '0';
		i++;
	}

	r[i] = '\0';

	reverse_string(r, i);
	return (r);
}

/**
 * reverse_string - Reverses a string
 * @str: The string to be reversed
 * @len: Length of the string
 */
void reverse_string(char *str, int len)
{
	int start = 0;
	int end = len - 1;
	char temp;

	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;

		start++;
		end--;
	}
}
