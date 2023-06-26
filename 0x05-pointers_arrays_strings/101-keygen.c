#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 15

char *generate_password()
{
    char *password = malloc(PASSWORD_LENGTH + 1); // Allocate memory for password
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i, sum = 0;

    srand(time(NULL)); // Seed the random number generator

    for (i = 0; i < PASSWORD_LENGTH - 1; i++)
    {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
        sum += charset[index];
    }

    password[PASSWORD_LENGTH - 1] = (sum % 10) + '0'; // Last character should be a digit
    password[PASSWORD_LENGTH] = '\0'; // Add null terminator

    return password;
}

int main()
{
    char *password = generate_password();

    printf("%s\n", password);

    free(password); // Free allocated memory

    return 0;
}

