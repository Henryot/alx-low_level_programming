#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

void error_exit(const char *msg, const char *file);
void close_fd(int fd);

/**
 * main - Copies the content of one file to another.
 * @argc: The number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to, read_count, write_count;
	char buffer[BUFSIZE];

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit("Can't read from file", argv[1]);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
		error_exit("Can't write to file", argv[2]);

	do {
		read_count = read(fd_from, buffer, BUFSIZE);
		if (read_count == -1)
			error_exit("Can't read from file", argv[1]);

		write_count = write(fd_to, buffer, read_count);
		if (write_count == -1 || write_count != read_count)
			error_exit("Can't write to file", argv[2]);
	} while (read_count > 0);

	close_fd(fd_from);
	close_fd(fd_to);

	return (0);
}

/**
 * error_exit - Print an error message and exit with a specific code.
 * @msg: The error message to print.
 * @file: The filename associated with the error.
 */
void error_exit(const char *msg, const char *file)
{
	dprintf(2, "Error: %s %s\n", msg, file);
	exit(strcmp(msg, "Can't read from file") == 0 ? 98 : 99);
}

/**
 * close_fd - Close a file descriptor.
 * @fd: The file descriptor to close.
 */
void close_fd(int fd)
{
	int res = close(fd);

	if (res == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
