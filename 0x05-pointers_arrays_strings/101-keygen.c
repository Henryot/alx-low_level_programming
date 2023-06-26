#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12

int main(void)
{
    char password[PASSWORD_LENGTH + 1];
    int i;

    srand(time(NULL));

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        int random_char = rand() % 62; // Generating a random number between 0 and 61

        if (random_char < 26) // Random character is between 'a' and 'z'
        {
            password[i] = 'a' + random_char;
        }
        else if (random_char < 52) // Random character is between 'A' and 'Z'
        {
            password[i] = 'A' + (random_char - 26);
        }
        else // Random character is between '0' and '9'
        {
            password[i] = '0' + (random_char - 52);
        }
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the password string

    printf("%s\n", password);

    return 0;
}

