#include <stdio.h>
#include "main.h"

/**
 * _isdigit(int c)
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
