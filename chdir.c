#include "main.h"
/**
 * cd - change directory
 * @argv: array of strings
 * @en: environment
  */
void cd(char **argv, char **en)
{
	int i = 0;
	char *dir = NULL, d[1024];

	while (argv[i])
		i++;
	if (i == 1 && argv[1] == NULL)
	{
		dir = _getenv("HOME");
		if (chdir(dir) == -1)
			perror(argv[0]);
		set_pwd(en, dir);
	}
	else if (strcmp(argv[1], "-") == 0 && i == 2)
	{
		dir = _getenv("OLDPWD");
		if (chdir(dir) == -1)
			perror(argv[0]);
		else
			set_pwd(en, dir);
	}
	else if (i == 2)
	{
		if (chdir(argv[1]) == -1)
			perror(argv[1]);
		else
		{
			getcwd(d, 1024);
			set_pwd(en, d);
		}
	}
	else
	{
		write(2, ERROR1, _strlen(ERROR1));
		exit(EXIT_FAILURE);
	}
}
