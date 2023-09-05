#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - checks the code for copying a file.
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}
	if (cp(argv[1], argv[2]) == -1)
		return (-1);
	return (0);
}
