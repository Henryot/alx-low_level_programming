#ifndef CP_H
#define CP_H

void print_usage_error(const char *program_name);
void print_read_error(const char *filename);
void print_write_error(const char *filename);
void print_close_error(int fd);
void copy_file(const char *src, const char *dest);

#endif /* CP_H */
