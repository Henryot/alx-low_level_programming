#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "3-cp.h"

#define BUFFER_SIZE 1024

void print_usage_error(const char *program_name)
{
    dprintf(2, "Usage: %s file_from file_to\n", program_name);
    exit(97);
}

void print_read_error(const char *filename)
{
    dprintf(2, "Error: Can't read from file %s\n", filename);
    exit(98);
}

void print_write_error(const char *filename)
{
    dprintf(2, "Error: Can't write to %s\n", filename);
    exit(99);
}

void print_close_error(int fd)
{
    dprintf(2, "Error: Can't close fd %d\n", fd);
    exit(100);
}

void copy_file(const char *src, const char *dest)
{
	int fd_from, fd_to, read_status, write_status;
	char buffer[BUFFER_SIZE];

	fd_from = open(src, O_RDONLY);
	if (fd_from == -1)
		print_read_error(src);

	fd_to = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		print_write_error(dest);
	}

	while ((read_status = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		write_status = write(fd_to, buffer, read_status);
		if (write_status == -1 || write_status != read_status)
		{
			close(fd_from);
			close(fd_to);
			print_write_error(dest);
		}
	}

	if (read_status == -1)
	{
		close(fd_from);
		close(fd_to);
		print_read_error(src);
	}

	if (close(fd_from) == -1)
		print_close_error(fd_from);

	if (close(fd_to) == -1)
		print_close_error(fd_to);
}
