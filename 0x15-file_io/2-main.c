#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - checks the code for appending text to a file.
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int res;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s filename text\n", argv[0]);
		exit(1);
	}
	res = append_text_to_file(argv[1], argv[2]);
	printf("-> %i)\n", res);
	return (0);
}
