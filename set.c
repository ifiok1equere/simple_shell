#include "main.h"
/**
 * set_var - set environment variables
 * @argv: array
 * @e: environment
 * @value: value to set
 * Return: 0 or 1 on success
 */
int set_var(char *argv, char *value, char **e)
{
	int j = 0;

	char *cpy, *token, *result;

	while (e[j])
	{
		cpy = _strdup(e[j]);
		token = strtok(cpy, "=");
		if (_strcmp(token, argv) == 0)
		{
			result = malloc(sizeof(char) * (_strlen(argv) + _strlen(value) + 3));
			if (result == NULL)
				return (-1);
			_strcpy(result, token);
			_strcat(result, "=");
			_strcat(result, value);
			e[j] = result;
			free(cpy);
			return (0);
		}
		free(cpy);
		j++;
	}
	return (-1);
}

/**
 * set_pwd - set environment variables
 * @e: environment
 * @current: current directory
 * Return: 0 or 1 on success
 */
int set_pwd(char **e, char *current)
{
	char *old;

	old = _getenv("PWD");
	if (old == NULL)
		return (-1);
	if (set_var("PWD", current, e) == -1 || set_var("OLDPWD", old, e) == -1)
	{
		return (-1);
	}
	return (0);
}
