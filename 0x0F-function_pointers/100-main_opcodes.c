#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function
 * @argc: The argument count
 * @argv: The argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	int i, bytes;

	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	bytes = atoi(argv[1]);

	if (bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	unsigned char *main_ptr = (unsigned char *)main;

	for (i = 0; i < bytes; i++)
		printf("%02x ", main_ptr[i]);

	printf("\n");

	return (0);
}
