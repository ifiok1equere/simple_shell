#include "main.h"

/**
 * _strlen - function returns the length of a string
 *
 * @s: pointer to type char variable whose length is to be determined
 *
 * Return: integer representing the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
	{
		i++;
	}

	return (i);
}
