#include <stdio.h>
#include "main.h"

/**
 * _isdigit - it is going to print digits
 * @c: this
 * Return: return is always 0
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
