#include "main.h"

/**
 * is_slower - checks for lowercase
 *
 * Return: 1 for lower case 0 for anythin else
 */

int _islower(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
