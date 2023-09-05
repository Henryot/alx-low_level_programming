#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - displays the information contained in the ELF header at the start of an ELF file.
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, or exit with status code 98 on error.
 */
int main(int argc, char **argv)
{
	int fd;
	unsigned char e_ident[EI_NIDENT];
	ssize_t bytes_read;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	bytes_read = read(fd, e_ident, EI_NIDENT);
	if (bytes_read != EI_NIDENT)
	{
		dprintf(2, "Error: Can't read from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(2, "Error: %s is not an ELF file\n", argv[1]);
		close(fd);
		exit(98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   %02x %02x %02x %02x\n", e_ident[EI_MAG0], e_ident[EI_MAG1], e_ident[EI_MAG2], e_ident[EI_MAG3]);

	/* You can continue to print other header information here */

	close(fd);
	return (0);
}
