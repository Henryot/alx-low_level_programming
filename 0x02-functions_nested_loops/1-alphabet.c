#include <unistd.h>
#include <stdio.h>

void print_alphabet(void);

void print_alphabet(void)
{
	char letter;
	for (letter = 'a'; letter <= 'z'; letter++)
	{
		write(1, &letter, 1);

	}
	write(1, "\n", 1);
}


int main()
{
	print_alphabet();

	return (0);
}
