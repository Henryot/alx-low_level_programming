#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 128

void error_exit(const char *msg, const char *file);

/**
 * main - Displays the information contained in the ELF header of an ELF file.
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int fd;
	ssize_t bytes_read;
	Elf64_Ehdr elf_header;
	unsigned char magic[16], data, class;
	int i;

	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("Error");
		exit(98);
	}

	bytes_read = read(fd, &elf_header, sizeof(elf_header));
	if (bytes_read != sizeof(elf_header))
	{
		perror("Error");
		close(fd);
		exit(98);
	}

	memcpy(magic, elf_header.e_ident, 16);
	data = (magic[EI_DATA] == ELFDATA2MSB) ? '2' : '1';
	class = (magic[EI_CLASS] == ELFCLASS32) ? 32 : 64;

	printf("ELF Header:\n");
	printf("  Magic:   ");
	for (i = 0; i < 16; i++)
		printf("%02x%c", magic[i], (i == 15) ? '\n' : ' ');

	printf("  Class:                             ELF%d\n", class);
	printf("  Data:                              2's complement, %s endian\n", (data == '1') ? "little" : "big");
	printf("  Version:                           %d (current)\n", elf_header.e_version);
	printf("  OS/ABI:                            ");
	switch (elf_header.e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - System V\n"); break;
		case ELFOSABI_HPUX: printf("HP-UX\n"); break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n"); break;
		case ELFOSABI_LINUX: printf("UNIX - Linux\n"); break;
		case ELFOSABI_SOLARIS: printf("UNIX - Solaris\n"); break;
		case ELFOSABI_IRIX: printf("IRIX\n"); break;
		case ELFOSABI_FREEBSD: printf("UNIX - FreeBSD\n"); break;
		case ELFOSABI_TRU64: printf("UNIX - TRU64\n"); break;
		case ELFOSABI_ARM: printf("ARM architecture\n"); break;
		case ELFOSABI_STANDALONE: printf("Standalone (embedded) application\n"); break;
		default: printf("<unknown: %x>\n", elf_header.e_ident[EI_OSABI]); break;
	}
	printf("  ABI Version:                       %d\n", elf_header.e_ident[EI_ABIVERSION]);

	printf("  Type:                              ");
	switch (elf_header.e_type)
	{
		case ET_NONE: printf("NONE (Unknown type)\n"); break;
		case ET_REL: printf("REL (Relocatable file)\n"); break;
		case ET_EXEC: printf("EXEC (Executable file)\n"); break;
		case ET_DYN: printf("DYN (Shared object file)\n"); break;
		case ET_CORE: printf("CORE (Core file)\n"); break;
		default: printf("Unknown type: 0x%x\n", elf_header.e_type); break;
	}

	printf("  Entry point address:               %#lx\n", (unsigned long)elf_header.e_entry);

	close(fd);

	return (0);
}

/**
 * error_exit - Print an error message and exit with a specific code.
 * @msg: The error message to print.
 * @file: The filename associated with the error.
 */
void error_exit(const char *msg, const char *file)
{
	dprintf(2, "%s: '%s'\n", msg, file);
	exit(98);
}
