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

	if (stat(argv[0], &status) == 0)
	{
		filename = _strdup(argv[0]);
		return (filename);
	}
	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);
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
		errors(argv[0]);
	}
	else
	{
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid == 0)
	{
		x = execve(path, argv, en);
		if (x == -1)
		{
			frees(argv, en);
			exit(EXIT_FAILURE);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid > 0)
		wait(&status);
	if (path != NULL)
		free(path);
	}
	frees(argv, en);
}
