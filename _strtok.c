#include "main.h"
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
		/* Skipping over any leading delimiter character on 1st call */
		while (*buf != '\0' && strchr(delim, *buf) != NULL)
			buf++;
		/* this is how we know we reached the end of the string */
		/* we simply return NULL when we have incremented buf to the
		 * end of the string */
		if (*buf == '\0')
			return (NULL);
		token = buf;

		/* what is buf pointing to here? */
		/* printf("1st buf =%s\n", token); */

		/* Point buf to the next delimeter in the string */
		while (*buf != '\0' && strchr(delim, *buf) == NULL)
		{
			i++;
			buf++;
		}
		/* Allocate space for the string to be tokenized */
		tokenized_str = malloc(i + 1);
		/* Check that malloc was successful */
		if (tokenized_str == NULL)
			return (NULL);

		/* fill the tokenized string characters into the allocated space */
		while (j < i)
		{
			tokenized_str[j] = token[j];
			j++;
		}
		tokenized_str[j] = '\0';

		return (tokenized_str);
	}
}
