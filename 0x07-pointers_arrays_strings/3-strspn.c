/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The string to be searched.
 * @accept: The string containing the characters to match.
 *
 * Return: The number of bytes in the initial segment of 's' that consist only
 *         of bytes from 'accept'.
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found = 1;
	char *a;

	for (; *s != '\0'; s++)
	{
		found = 0;
		for (a = accept; *a != '\0'; a++)
		{
			if (*s == *a)
			{
				found = 1;
				break;
			}
		}

		if (!found)
			break;

		count++;
	}

	return (count);
}
