#include "main.h"
/**
 * read_input - reads input
 * Return: what user input
 */
char *read_input(void)
{
	size_t n = 0;
	char *user_input = NULL, *command = NULL;

	if (getline(&user_input, &n, stdin) == -1)
	{
		free(user_input);
		return (NULL);
	}
	if (_strcmp(user_input, "\n") == 0)
	{
		free(user_input);
		prompt();
		return (read_input());
	}
	command = _strdup(user_input);
	if (user_input != NULL)
		free(user_input);
	return (command);
}
