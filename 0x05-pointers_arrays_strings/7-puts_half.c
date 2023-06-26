#include <unistd.h>

/**
 * puts_half - Prints half of a string followed by a new line.
 * @str: The string to be printed.
 */
void puts_half(char *str)
{
	int length = 0;
	int i;
	int start;

	while (str[length] != '\0')
	{
		length++;
	}

	if (length % 2 == 0)
	{
		start = length / 2;
	}
	else
	{
		start = (length + 1) / 2;
	}

	for (i = start; i < length; i++)
	{
		write(1, &str[i], 1);
	}

	write(1, "\n", 1);
}

