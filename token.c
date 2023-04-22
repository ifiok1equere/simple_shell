#include "main.h"
/**
 * tokenize - splits string
 * @command: string to be broken
 * @delim: delimiter
 * Return: array of strings
 */
char **tokenize(char *command, char *delim)
{
	char *cmd_cpy = NULL, *token = NULL, **argv = NULL;
	int argc = 0, i;

	if (command == NULL)
		return (NULL);
	cmd_cpy = strdup(command);
	if (cmd_cpy == NULL)
		return (NULL);
	token = strtok(command, delim);
	while (token)
	{
		token = strtok(NULL, delim);
		argc++;
	}
	argv = malloc(sizeof(char *) * (argc + 1));
	if (argv == NULL)
		return (NULL);

	token = strtok(cmd_cpy, delim);
	i = 0;
	while (token)
	{
		argv[i] = _strdup(token);
		token = strtok(NULL, delim);
		i++;
	}
	argv[argc] = NULL;
	free(cmd_cpy);
	return (argv);
}
