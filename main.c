#include "main.h"
/**
 * main - Entry point to the shell
 * Return: 0 for success always
 */
int main(void)
{
	char *input;
	char **tokens;
	int i;

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
		i = 0;
		while (tokens[i] != NULL)
			i++;
		if (i != 1)
		{
			perror("./hsh");
			free(input);
			frees1(tokens);
		}
		else
		{
			execute(tokens);
			if (input == NULL && input[0] != '\n')
				free(input);
		}
	}
	return (0);
}
