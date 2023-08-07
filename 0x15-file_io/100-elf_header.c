#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

#define BUFSIZE 64

/**
 * error_exit - Display an error message and exit with status code 98.
 * @msg: The error message to display.
 */
void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_magic - Print the magic bytes of the ELF header.
 * @e_ident: The ELF identification bytes.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - Print the ELF class.
 * @e_ident: The ELF identification bytes.
 */
void print_class(unsigned char *e_ident)
{
	static const char *elf_classes[] = {
		"None",
		"ELF32",
		"ELF64",
	};

	printf("  Class:                             %s\n", elf_classes[e_ident[EI_CLASS]]);
}

/**
 * print_data - Print the data encoding of the ELF file.
 * @e_ident: The ELF identification bytes.
 */
void print_data(unsigned char *e_ident)
{
	static const char *data_encodings[] = {
		"None",
		"2's complement, little endian",
		"2's complement, big endian",
	};

	printf("  Data:                              %s\n", data_encodings[e_ident[EI_DATA]]);
}

/**
 * print_version - Print the ELF version.
 * @e_ident: The ELF identification bytes.
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Print the OS/ABI of the ELF file.
 * @e_ident: The ELF identification bytes.
 */
void print_osabi(unsigned char *e_ident)
{
	static const char *osabi_names[] = {
		"UNIX - System V",
		"UNIX - HP-UX",
		"UNIX - NetBSD",
		"UNIX - Linux",
		"UNIX - Solaris",
		"UNIX - IRIX",
		"UNIX - FreeBSD",
		"UNIX - TRU64",
		"UNIX - ARM architecture",
		"Standalone App",
	};

	printf("  OS/ABI:                            %s\n", osabi_names[e_ident[EI_OSABI]]);
}

/**
 * print_abiversion - Print the ABI version.
 * @e_ident: The ELF identification bytes.
 */
void print_abiversion(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Print the type of the ELF file.
 * @e_type: The ELF type.
 */
void print_type(uint16_t e_type)
{
	static const char *elf_types[] = {
		"None",
		"REL (Relocatable file)",
		"EXEC (Executable file)",
		"DYN (Shared object file)",
		"CORE (Core file)",
	};

	printf("  Type:                              %s\n", elf_types[e_type]);
}

/**
 * print_entry - Print the entry point address of the ELF file.
 * @e_entry: The entry point address.
 */
void print_entry(uint64_t e_entry)
{
	printf("  Entry point address:               0x%lx\n", (unsigned long)e_entry);
}

/**
 * read_elf_header - Read and display the ELF header information.
 * @filename: The name of the ELF file.
 */
void read_elf_header(const char *filename)
{
	int fd, read_bytes;
	Elf64_Ehdr elf_header;
	unsigned char e_ident[EI_NIDENT];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Error: Unable to open the file");

	read_bytes = read(fd, e_ident, EI_NIDENT);
	if (read_bytes == -1 || read_bytes != EI_NIDENT)
		error_exit("Error: Unable to read the ELF header");

	if (e_ident[EI_MAG0] != ELFMAG0 || e_ident[EI_MAG1] != ELFMAG1 ||
	    e_ident[EI_MAG2] != ELFMAG2 || e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");

	lseek(fd, 0, SEEK_SET);

	read_bytes = read(fd, &elf_header, sizeof(elf_header));
	if (read_bytes == -1 || read_bytes != sizeof(elf_header))
		error_exit("Error: Unable to read the ELF header");

	close(fd);

	printf("ELF Header:\n");
	print_magic(e_ident);
	print_class(e_ident);
	print_data(e_ident);
	print_version(e_ident);
	print_osabi(e_ident);
	print_abiversion(e_ident);
	print_type(elf_header.e_type);
	print_entry(elf_header.e_entry);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(2, "Usage: %s elf_filename\n", argv[0]);
		exit(1);
	}

	read_elf_header(argv[1]);
	return (0);
}
