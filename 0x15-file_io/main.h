#ifndef MAIN_H
#define MAIN_H

/* Included libraries */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function Prototypes */

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

/**
 * main - main function for the cp program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, or one of the error codes
 */
int main(int argc, char *argv[]); /* This is for the cp program */

/* ELF-related constants and prototypes */

#define EI_NIDENT 16

/**
 * main - main function for the elf_header program
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, or 98 on error
 */
int main(int argc, char *argv[]); /* This is for the elf_header program */

#endif /* MAIN_H */

