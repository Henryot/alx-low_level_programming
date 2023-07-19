#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

/* Header file contents */
void print_name_as_is(char *name);
void print_name_uppercase(char *name);
void print_name(char *name, void (*f)(char *));

#endif /* FUNCTION_POINTERS_H */
