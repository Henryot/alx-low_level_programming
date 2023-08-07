#include <stdio.h>
#include <stdlib.h>

/**
 * main - Test the cp program.
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	if (remove(argv[2]) == 0)
		printf("Removed existing file '%s'\n", argv[2]);

	if (rename(argv[1], argv[2]) == 0)
		printf("Successfully renamed '%s' to '%s'\n", argv[1], argv[2]);
	else
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	return (0);
}
