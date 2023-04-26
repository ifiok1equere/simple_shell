#include "main.h"
/**
 * main - Entry point to the shell
 * Return: 0 for success always
 */
int main(void)
{
	char *input;
	char **tokens;

	if (isatty(STDIN_FILENO))
	{
	while (1)
	{
		prompt();
		input = read_input();
		if (input == NULL)
			exit(EXIT_FAILURE);
		tokens = tokenize(input, " \n");
		if (tokens == NULL)
		{
			free(input);
			exit(EXIT_FAILURE);
		}
		execute(tokens);
		if (input == NULL && input[0] != '\n')
			free(input);
	}
	}
	else
	{
		input = NULL;
		interact(input);
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
