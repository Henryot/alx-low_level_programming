#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 15

int main(void)
{
    char password[PASSWORD_LENGTH + 1];
    int i;

    srand(time(NULL));

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        int random_char = rand() % 62;

        if (random_char < 26)
        {
            password[i] = 'a' + random_char;
        }
        else if (random_char < 52)
        {
            password[i] = 'A' + (random_char - 26);
        }
        else
        {
            password[i] = '0' + (random_char - 52);
        }
    }

    password[PASSWORD_LENGTH] = '\0';

    printf("%s\n", password);

    return 0;
}

