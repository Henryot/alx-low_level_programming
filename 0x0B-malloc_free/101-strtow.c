#include <stdlib.h>
#include <string.h>

/**
 * count_words - Counts the number of words in a string.
 * @str: The input string.
 *
 * Return: The number of words in the string.
 */
int count_words(char *str)
{
    int count = 0;
    int in_word = 0;
    char *ptr = str;

    while (*ptr != '\0')
    {
        if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
        {
            if (in_word)
            {
                in_word = 0;
                count++;
            }
        }
        else
        {
            if (!in_word)
                in_word = 1;
        }

        ptr++;
    }

    return count;
}

/**
 * strtow - Splits a string into words.
 * @str: The input string.
 *
 * Return: A double pointer to an array of words, or NULL on failure or empty string.
 */
char **strtow(char *str)
{
    int num_words;
    char **words;
    char *token;
    char *copy;
    int i, j;

    if (str == NULL || *str == '\0')
        return NULL;

    num_words = count_words(str);
    if (num_words == 0)
        return NULL;

    copy = (char *)malloc(strlen(str) + 1);
    if (copy == NULL)
        return NULL;

    strcpy(copy, str);

    words = (char **)malloc(sizeof(char *) * (num_words + 1));
    if (words == NULL)
    {
        free(copy);
        return NULL;
    }

    token = strtok(copy, " ");
    i = 0;
    while (token != NULL)
    {
        words[i] = (char *)malloc(strlen(token) + 1);
        if (words[i] == NULL)
        {
            for (j = 0; j < i; j++)
                free(words[j]);
            free(words);
            free(copy);
            return NULL;
        }
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, " ");
    }

    words[i] = NULL;
    free(copy);
    return words;
}
