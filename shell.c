#include "main.h"
/**
 * main - checks if shell works
 * Return: 0 success
 */
int main(void)
{
	char *command = NULL, **argv = NULL;

	if (isatty(STDIN_FILENO))
	{
	while (1)
	{
	prompt();
	command = read_input();
	if (command == NULL)
		return (-1);
	argv = tokenize(command, " \n");
	if (argv == NULL)
	{
		free(command);
		return (-1);
	}
	if (_strcmp(argv[0], "exit") == 0)
	{
		free(command);
		frees1(argv);
		break;
	}
	builtin(argv, environ);
	if (command && command[0] != '\n')
		free(command);
	}
	}
	else
		{
			command = NULL;
			interact(command);
		}
	return (0);
}
/**
 * interact - non interactive mode
 * @input: from user
 * Return: 0 success
 */
int interact(char *input)
{
	char **tokens;
	size_t n = 0;

	while (getline(&input, &n, stdin) != -1)
	{
		tokens = tokenize(input, " \n");
		if (tokens == NULL)
		{
			free(input);
			exit(EXIT_FAILURE);
		}
		if (_strcmp(tokens[0], "exit") == 0)
		{
			frees1(tokens);
			break;
		}
		builtin(tokens, environ);
	}
		free(input);
		return (0);
}
