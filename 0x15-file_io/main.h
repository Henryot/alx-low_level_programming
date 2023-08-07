#ifndef MAIN_H
#define MAIN_H
#define BUFSIZE 1024
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
size_t _strlen(const char *str);
int append_text_to_file(const char *filename, char *text_content);
void error_exit(const char *msg);
void close_fd(int fd);

#endif /* MAIN_H */
