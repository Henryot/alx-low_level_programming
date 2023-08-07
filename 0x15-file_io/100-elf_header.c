#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 128

/**
 * main - Entry point
 * @argc: The number of arguments passed to the program
 * @argv: An array of pointers to the arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int i;
	int fd, read_status;
	unsigned char buffer[BUFFER_SIZE];

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(2, "Error: Cannot open file %s\n", argv[1]);
		exit(98);
	}

	/* Read the ELF header */
	read_status = read(fd, buffer, BUFFER_SIZE);
	if (read_status == -1)
	{
		dprintf(2, "Error: Cannot read from file %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	/* Check if the file is an ELF file */
	if (buffer[0] != 0x7f || buffer[1] != 'E' || buffer[2] != 'L' || buffer[3] != 'F')
	{
		dprintf(2, "Error: Not an ELF file - %s\n", argv[1]);
		close(fd);
		exit(98);
	}

	/* Display the ELF header information */
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x ", buffer[i]);
	printf("\n");

	printf("  Class:                             ELF%d\n", (buffer[4] == 1) ? 32 : 64);
	printf("  Data:                              2's complement, %s endian\n", (buffer[5] == 1) ? "little" : "big");
	printf("  Version:                           %d (current)\n", buffer[6]);
	printf("  OS/ABI:                            UNIX - ");
	switch (buffer[7])
	{
		case 0:
			printf("System V\n");
			break;
		case 1:
			printf("HP-UX\n");
			break;
		case 2:
			printf("NetBSD\n");
			break;
		/* Add other cases as needed */
		default:
			printf("<unknown: %d>\n", buffer[7]);
			break;
	}

	printf("  ABI Version:                       %d\n", buffer[8]);
	printf("  Type:                              ");
	switch (*((unsigned short *)&buffer[16]))
	{
		case 1:
			printf("EXEC (Executable file)\n");
			break;
		case 2:
			printf("DYN (Shared object file)\n");
			break;
		/* Add other cases as needed */
		default:
			printf("<unknown: %hu>\n", *((unsigned short *)&buffer[16]));
			break;
	}

	printf("  Entry point address:               0x");
	if (buffer[4] == 1) /* 32-bit */
	{
		unsigned int entry_point = *((unsigned int *)&buffer[24]);
		printf("%x\n", entry_point);
	}
	else if (buffer[4] == 2) /* 64-bit */
	{
		unsigned long entry_point = *((unsigned long *)&buffer[24]);
		printf("%lx\n", entry_point);
	}
	else
		printf("Unknown entry point format\n");

	close(fd);
	return (0);
}
