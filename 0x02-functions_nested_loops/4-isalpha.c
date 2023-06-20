#include "main.h"

/**
 * _isalpha - checks for alphabets
 * @c: locates the character
 * Return: returns 1 if alphabets are peresnt or 0 for otherwise
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 96) || (c >= 97 && c <= 122))
	{
		return (1);
	}

	else
	{
		return (0);
	}
}
