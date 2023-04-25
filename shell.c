#include "main.h"
/**
 * main - checks if shell works
 * Return: 0 success
 */
int main(void)
{
	char *command = NULL, **argv = NULL;
	int i;

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
		if (argv[1] != NULL)
			i = atoi(argv[1]);
		free(command);
		frees1(argv);
		return (i);
	}
	execute(argv);
	if (command && command[0] != '\n')
		free(command);
	}
	return (0);
}
