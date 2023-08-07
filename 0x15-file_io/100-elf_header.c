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

    printf("  Magic:\t");
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
    static const char * const elf_classes[] = {
        "None",   /* [ELFCLASSNONE] */
        "ELF32",  /* [ELFCLASS32] */
        "ELF64",  /* [ELFCLASS64] */
    };

    printf("  Class:\t%s\n", elf_classes[e_ident[EI_CLASS]]);
}

/**
 * print_data - Print the data encoding of the ELF file.
 * @e_ident: The ELF identification bytes.
 */
void print_data(unsigned char *e_ident)
{
    static const char * const data_encodings[] = {
        "None",                             /* [ELFDATANONE] */
        "2's complement, little endian",    /* [ELFDATA2LSB] */
        "2's complement, big endian",       /* [ELFDATA2MSB] */
    };

    printf("  Data:\t\t%s\n", data_encodings[e_ident[EI_DATA]]);
}

/**
 * print_version - Print the ELF version.
 * @e_ident: The ELF identification bytes.
 */
void print_version(unsigned char *e_ident)
{
    printf("  Version:\t%d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Print the OS/ABI of the ELF file.
 * @e_ident: The ELF identification bytes.
 */
void print_osabi(unsigned char *e_ident)
{
    static const char * const osabi_names[] = {
        "UNIX - System V",          /* [ELFOSABI_SYSV] */
        "UNIX - HP-UX",             /* [ELFOSABI_HPUX] */
        "UNIX - NetBSD",            /* [ELFOSABI_NETBSD] */
        "UNIX - Linux",             /* [ELFOSABI_LINUX] */
        "UNIX - Solaris",           /* [ELFOSABI_SOLARIS] */
        "UNIX - IRIX",              /* [ELFOSABI_IRIX] */
        "UNIX - FreeBSD",           /* [ELFOSABI_FREEBSD] */
        "UNIX - TRU64",             /* [ELFOSABI_TRU64] */
        "UNIX - ARM architecture",  /* [ELFOSABI_ARM] */
        "Standalone App",           /* [ELFOSABI_STANDALONE] */
    };

    printf("  OS/ABI:\t%s\n", osabi_names[e_ident[EI_OSABI]]);
}

/**
 * print_abiversion - Print the ABI version.
 * @e_ident: The ELF identification bytes.
 */
void print_abiversion(unsigned char *e_ident)
{
    printf("  ABI Version:\t%d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Print the type of the ELF file.
 * @e_type: The ELF type.
 */
void print_type(uint16_t e_type)
{
    static const char * const elf_types[] = {
        "None",                 /* [ET_NONE] */
        "REL (Relocatable file)",   /* [ET_REL] */
        "EXEC (Executable file)",   /* [ET_EXEC] */
        "DYN (Shared object file)", /* [ET_DYN] */
        "CORE (Core file)",         /* [ET_CORE] */
    };

    printf("  Type:\t\t%s\n", elf_types[e_type]);
}

/**
 * print_entry - Print the entry point address of the ELF file.
 * @e_entry: The entry point address.
 */
void print_entry(uint64_t e_entry)
{
    printf("  Entry point address:\t0x%lx\n", (unsigned long)e_entry);
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

/**
 * main - Entry point of the program.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the command-line arguments.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    read_elf_header(argv[1]);
    return (0);
}
