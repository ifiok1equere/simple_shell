#include "main.h"

/**
 * _strcpy - function copies a string
 *
 * @dest: destination where string is to be copied into.
 * @src: pointer to string to be cpopied
 *
 * Return: pointer to destination string of type char
 */

char *_strcpy(char *dest, char *src)
{
	unsigned int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	dest[i] = '\0';

	return (dest);
}
