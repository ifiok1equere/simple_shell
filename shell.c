#include "main.h"
/**
 * main - checks if shell works
 * Return: 0 success
 */
int main(void)
{
	char *command = NULL;
	char **argv = NULL;

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
	execute(argv);
	if (command && command[0] != '\n')
		free(command);
	}
	return (0);
}
