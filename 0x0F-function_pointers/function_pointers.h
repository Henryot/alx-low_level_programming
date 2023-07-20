#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/* Header file contents */
void print_name_as_is(char *name);
void print_name_uppercase(char *name);
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));
int is_98(int elem);
int is_strictly_positive(int elem);
int abs_is_98(int elem);

#endif /* FUNCTION_POINTERS_H */
