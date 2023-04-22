#include "main.h"

/**
 * _strchr - function locates a character in string.
 *
 * @s: pointer to string in which charcter search is to be made.
 * @c: character to be searched for.
 *
 * Return: pointer to first occurence of c in the string s or null is c is not
 * found.
 */

char *_strchr(char *s, char c)
{
	unsigned int i;

	for (i = 0; i <= strlen(s); i++)
	{
		if (s[i] == c)
		{
			return (&s[i]);
		}
	}
	return (NULL);
}
