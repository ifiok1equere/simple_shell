#include "main.h"
/**
 * _strtok - tokenizing function
 * @str: string to be tokenized.
 * @delim: delimeter between strings
 * Return: pointer to tokenized string. *
 */
char *_strtok(char *str, const char *delim)
{
	static char *buf;
	char *token, *tokenized_str;
	int i = 0, j = 0;

	if (str != NULL)
	{
		buf = str;
	}

	while (1)
	{
		while (*buf != '\0' && strchr(delim, *buf) != NULL)
			buf++;
		if (*buf == '\0')
			return (NULL);
		token = buf;
		while (*buf != '\0' && strchr(delim, *buf) == NULL)
		{
			i++;
			buf++;
		}
		tokenized_str = malloc(i + 1);
		if (tokenized_str == NULL)
			return (NULL);

		while (j < i)
		{
			tokenized_str[j] = token[j];
			j++;
		}
		tokenized_str[j] = '\0';

		return (tokenized_str);
	}
}
