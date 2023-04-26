#include "main.h"
/**
 * _getenv - get value
 * @name: environment variable
 * @envp: environment
 * Return: value
 */
char *_getenv(const char *name, char **envp)
{
	int i = 0;
	char *token, *cpy, *token1, *value = NULL;

	if (envp == NULL)
		return (NULL);
	while (envp[i])
	{
		cpy = _strdup(envp[i]);
		token = strtok(cpy, "=");
		if (strcmp(token, name) == 0)
		{
			token1 = strtok(NULL, "=");
			value = _strdup(token1);
			free(cpy);
			return (value);
		}
		i++;
		free(cpy);
	}
	free(value);
	return (NULL);
}
/**
 * new_env - copy environment variables
 * Return: environment
 */
char **new_env(void)
{
	char **environ_1 = NULL;
	int i = 0, j = 0;

	while (environ[i])
	{
		i++;
	}
	environ_1 = malloc(sizeof(char *) * (i + 1));
	if (environ_1 == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		environ_1[j] = _strdup(environ[j]);
		j++;
	}
	environ_1[j] = NULL;
	return (environ_1);
}
