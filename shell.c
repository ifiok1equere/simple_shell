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
 */
void interact(char *input)
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
		execute(tokens);
	}
		free(input);
}
