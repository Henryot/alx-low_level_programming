#include <stdio.h>
#include "main.h"
/**
 * _puts - prints a string, followed by a new line, to stdout
 * @s: The string to print
 */
void _puts(char *s)
{
	int i = 0;

	while (s[i])
		_putchar(s[i++]);

	_putchar('\n');
}
