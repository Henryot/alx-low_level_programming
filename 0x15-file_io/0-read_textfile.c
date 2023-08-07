#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - Read and print the contents of a text file to standard output.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed, or 0 on failure.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t file_descriptor, read_count, write_count;
	char buffer[1024]; /* A buffer to read data from the file */

	if (filename == NULL)
		return (0);

	/* Open the file in read-only mode */
	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	/* Read and print the contents of the file */
	read_count = read(file_descriptor, buffer, letters);
	write_count = write(STDOUT_FILENO, buffer, read_count);

	/* Close the file descriptor */
	close(file_descriptor);

	if (read_count == -1 || write_count == -1 || write_count != read_count)
		return (0);

	return (read_count);
}
