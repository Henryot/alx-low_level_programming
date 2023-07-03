#include <stdio.h>
#include <unistd.h>
/**
 * _putchar - funtion to print characters
 * @c: the character
 * Return: return is the character
 */

int _putchar(char c)
{
	return (write(1, &c, 1));

}
