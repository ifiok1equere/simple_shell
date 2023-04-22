#include "main.h"
/**
 * _get_env - get value
 * @name: environment variable
 * Return: value
 */
char *_getenv(const char *name)
{
	char **envp = new_env();
	int i = 0;
	char *token, *cpy, *token1, *value;

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
			frees1(envp);
			free(cpy);
			return (value);
		}
		i++;
		free(cpy);
	}
	free(value);
	frees1(envp);
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
