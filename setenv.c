#include "main.h"
/**
 * set_env - set environment variables
 * @argv: array
 * @e: environment
 * Return: 0 or 1 on success
 */
int set_env(char **argv, char **e)
{
	int i = 0, j = 0, len;
	char *token, *cpy, *token1,  *result = NULL;

	while (argv[i])
		i++;
	if (i != 3)
	{
		perror("setenv");
		EXIT_FAILURE;
	}
	while (e[j])
	{
		cpy = _strdup(e[j]);
		token = strtok(cpy, "=");
		if (_strcmp(token, argv[1]) == 0)
		{
			result = _strdup(token);
			_strcat(result, "=");
			_strcat(result, argv[2]);
			e[j] = _strdup(result);
			free(result);
			free(cpy);
			return (0);
		}
		free(cpy);
		j++;
	}
	len = _strlen(argv[1]) + _strlen(argv[2]) + 2;
	result = malloc(sizeof(char) * len);
	if (result == NULL)
		return (-1);
	result = _strdup(argv[1]);
	_strcat(result, "=");
	_strcat(result, argv[2]);
	e[j] = result;
	e[j + 1] = NULL;
	return (1);
}
/**
 * unset_env - set environment variables
 * @argv: array
 * @e: environment
 * Return: 0 or 1 on success
 */
int unset_env(char **argv, char **e)
{
	int i = 0, j = 0, y;
	char *token, *cpy;

	while (argv[i])
		i++;
	if (i != 2)
	{
		perror("unsetenv");
		EXIT_FAILURE;
	}
	while (e[j])
	{
		cpy = _strdup(e[j]);
		token = strtok(cpy, "=");
		if (_strcmp(token, argv[1]) == 0)
		{
			y = j;
			while (e[y + 1])
			{
			e[y] = _strdup(e[y + 1]);
			y++;
			}
			e[y] = NULL;
			free(cpy);
			return (0);
		}
		free(cpy);
		j++;
	}
	perror(argv[1]);
	return (-1);
}
