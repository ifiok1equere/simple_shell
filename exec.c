#include "main.h"
/**
  * path_finder - executes new process
  * @argv: array of strings
  * Return: path
 */
char *path_finder(char **argv)
{
	int len;
	char *path = NULL, *token = NULL, *filename = NULL;
	struct stat status;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
	if (stat(argv[0], &status) == 0)
	{
		free(path);
		return (argv[0]);
	}
	token = strtok(path, ":");
	while (token != NULL)
	{
		len = _strlen(argv[0]) + _strlen(token) + 2;
		filename = malloc(sizeof(char) * len);
		if (filename == NULL)
			return (NULL);
		_strcpy(filename, token);
		_strcat(filename, "/");
		_strcat(filename, argv[0]);
		if (stat(filename, &status) == 0)
		{
			free(path);
			return (filename);
		}
		free(filename);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
/**
 * execute - executes command
 * @argv: array of strings
 */
void execute(char **argv)
{
	pid_t pid;
	int x, status;
	char *path, **en = new_env();

	if (en == NULL)
	{
		frees1(argv);
		return;
	}
	path = path_finder(argv);
	if (path == NULL)
	{
		perror(argv[0]);
		frees(argv, en);
	}
	else
	{
	pid = fork();
	if (pid == -1)
	{
		free(path);
		frees(argv, en);
	}
	else if (pid == 0)
	{
		x = execve(path, argv, en);
		if (x == -1`)
		{
			free(path);
			frees(argv, en);
		}
		EXIT_SUCCESS;
	}
	else if (pid > 0)
	{
		wait(&status);
		free(path);
		frees(argv, en);
	}
	}
}
