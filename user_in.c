#include "main.h"
/**
 * read_input - function read user input
 * Return: apointer to the user input string
 */
char *read_input(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t ret;

	ret = getline(&lineptr, &n, stdin);
	if (ret == -1)
	{
		free(lineptr);
		return (NULL);
	}
	if (_strcmp(lineptr, "\n") == 0)
	{
		free(lineptr);
		prompt();
		return (read_input());
	}
	return (lineptr);
}
