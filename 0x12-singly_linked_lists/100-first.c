#include <stdio.h>

/**
 * print_message - Prints the message before the main function is executed.
 */
void __attribute__((constructor)) print_message(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
