#include <stdlib.h>

/**
 * count_words - Counts the number of words in a string
 * @str: The input string
 *
 * Return: The number of words
 */
int count_words(char *str)
{
	int count = 0;
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}

	return count;
}

/**
 * strtow - Splits a string into words
 * @str: The input string
 *
 * Return: Pointer to an array of strings (words), or NULL on failure
 */
char **strtow(char *str)
{
	char **words;
	int num_words, word_len, i, j, k;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	num_words = count_words(str);
	words = malloc(sizeof(char *) * (num_words + 1));

	if (words == NULL)
		return (NULL);

	i = 0;
	k = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			word_len = 0;
			j = i;
			while (str[j] != ' ' && str[j] != '\0')
			{
				word_len++;
				j++;
			}

			words[k] = malloc(sizeof(char) * (word_len + 1));
			if (words[k] == NULL)
			{
				for (j = 0; j < k; j++)
					free(words[j]);
				free(words);
				return (NULL);
			}

			for (j = 0; j < word_len; j++, i++)
				words[k][j] = str[i];
			words[k][j] = '\0';
			k++;
		}
		else
		{
			i++;
		}
	}

	words[k] = NULL;
	return (words);
}
