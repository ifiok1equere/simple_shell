#include "main.h"
/**
 * _strdup - duplicates string
 * @source: string to be duplicated
 * Return: duplicate
 */
char *_strdup(char *source)
{
	int len, i;
	char *new;

	len = _strlen(source);
	len++;
	new = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	for (i = 0; source[i]; i++)
		new[i] = source[i];
	new[i] = '\0';
	return (new);
}
