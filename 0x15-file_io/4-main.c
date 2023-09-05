#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - checks the code for displaying ELF header.
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}
	display_elf_header(argv[1]);
	return (0);
}
