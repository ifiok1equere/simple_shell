#include "main.h"
/**
 * builtin - executes depending on the option
 * @argv: array
 * @en: environment variables
 * Return: 1 success
 */
int builtin(char **argv, char **en)
{

	if (_strcmp(argv[0], "setenv") == 0)
	{
		set_env(argv, en);
		 frees1(argv);
	}
	else if (_strcmp(argv[0], "unsetenv") == 0)
	{
		unset_env(argv, en);
		 frees1(argv);
	}
	else if (_strcmp(argv[0], "cd") == 0)
	{
		cd(argv, en);
		frees1(argv);
	}
	else if (_strcmp(argv[0], "env") == 0)
	{
		envs();
		frees1(argv);
	}
	else
		execute(argv);
	return (1);
}
