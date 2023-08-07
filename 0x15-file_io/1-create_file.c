#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_file - Create a file and write the given text content to it.
 * @filename: The name of the file to create.
 * @text_content: The NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, write_count;
	int permissions = S_IRUSR | S_IWUSR; /* rw------- permissions */

	if (filename == NULL)
		return (-1);

	/* Open the file with the appropriate permissions */
	file_descriptor = open(filename, O_WRONLY | O_CREAT | O_TRUNC, permissions);
	if (file_descriptor == -1)
		return (-1);

	if (text_content != NULL)
	{
		/* Write the text content to the file */
		write_count = write(file_descriptor, text_content, _strlen(text_content));
		if (write_count == -1)
		{
			close(file_descriptor);
			return (-1);
		}
	}

	close(file_descriptor);
	return (1);
}

/**
 * _strlen - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
