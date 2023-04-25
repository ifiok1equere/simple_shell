#include "main.h"

/**
 * _strcat - function concatenates two strings
 *
 * @dest: this is the pointer to the destination string
 * @src: pointer to the source string
 *
 * Return: Pointer to the resulting destination string
 */

char *_strcat(char *dest, char *src)
{
	int n, i = 0;

	n = strlen(dest);

	while (src[i])
	{
		dest[n + i] = src[i];
		i++;
	}

	dest[n + i] = '\0';

	return (dest);
}
