#include "main.h"
#include <stdio.h>

/**
 * main - this function prints uppercase
 * @c: c holds the parameter
 * Return: it always 0
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z') 
	{
		return (1);
	} 
	else
	{
		return (0);
	}
}
