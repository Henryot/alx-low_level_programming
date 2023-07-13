#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * _isdigit - Checks if a character is a digit
 * @c: The character to check
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

/**
 * multiply - Multiplies two positive numbers
 * @num1: The first number as a string
 * @num2: The second number as a string
 *
 * Return: The result of the multiplication as a string
 */
char *multiply(const char *num1, const char *num2)
{
    int len1 = 0, len2 = 0, i, j;
    int *result, carry, n1, n2, sum;
    char *mul;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    result = calloc(len1 + len2, sizeof(int));
    if (result == NULL)
        return (NULL);

    for (i = len1 - 1; i >= 0; i--)
    {
        n1 = num1[i] - '0';
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            n2 = num2[j] - '0';
            sum = (n1 * n2) + result[i + j + 1] + carry;
            result[i + j + 1] = sum % 10;
            carry = sum / 10;
        }
        if (carry)
            result[i] += carry;
    }

    while (len1 + len2 > 1 && *result == 0)
    {
        result++;
        len1--;
    }

    mul = malloc(sizeof(char) * (len1 + len2 + 1));
    if (mul == NULL)
    {
        free(result);
        return (NULL);
    }

    for (i = 0; i < len1 + len2; i++)
        mul[i] = result[i] + '0';
    mul[i] = '\0';

    free(result - len1);

    return (mul);
}

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: Array containing the command line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
    char *num1, *num2, *result;

    if (argc != 3)
    {
        printf("Error\n");
        return (98);
    }

    num1 = argv[1];
    num2 = argv[2];

    while (*num1)
    {
        if (!_isdigit(*num1))
        {
            printf("Error\n");
            return (98);
        }
        num1++;
    }

    while (*num2)
    {
        if (!_isdigit(*num2))
        {
            printf("Error\n");
            return (98);
        }
        num2++;
    }

    result = multiply(argv[1], argv[2]);
    if (result == NULL)
    {
        printf("Error\n");
        return (98);
    }

    printf("%s\n", result);
    free(result);

    return (0);
}
