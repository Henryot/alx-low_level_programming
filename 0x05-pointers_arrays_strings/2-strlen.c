#include <stdio.h>
#include "main.h"

/**
 * _strlen - prints length of strong
 * @s: s is the 
 * Return: it returns length
 */

int _strlen(char *s)

{
	int length = 0;

	while (*s != '\0')
	{
	length++;
	s++;
	}

	return length;
}
