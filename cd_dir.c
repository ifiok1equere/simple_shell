#include "main.h"

int cd_dir(char *delim)
{
	char *lineptr = NULL, *lineptr_copy, *str, *str_next;
	char *pwd_old;
	char *home = getenv("HOME");
	ssize_t a;
	size_t n = 0, i;

	printf("Enter a string: ");
	a = fetchline(&lineptr, &n, stdin);
	if (a == -1)
		return (-1);
	lineptr_copy = malloc(sizeof(char) * (_strlen(lineptr) + 1));
	_strcpy(lineptr_copy, lineptr);
	str = _strtok(lineptr, delim);

	for (i = 0; str != NULL; i++) /* 1st check to see that arguments are < 3 */
	{
		str = _strtok(NULL, delim);
		if (i > 1)
		{
			perror("cd: too many arguments");
			exit(EXIT_FAILURE);
		}
	}

	str = strtok(lineptr_copy, delim);
	str_next = strtok(NULL, delim);
	printf("str = %s, str_next = %s\n", str, str_next);
	chdir(home);
	printf("skip");
	if (strcmp(str, "cd") == 0)
	{
		if (str_next == NULL) /* Then only "cd" has been entered */
		{
			printf("It now works");
			if (chdir(home) != 0) /* Change directory to home */
			{
				perror("command not found");
				printf("No home");
				exit(EXIT_FAILURE);
			}
			else
			{
				chdir(home);
			}
		}
	}
	else if ((strcmp(str, "cd") == 0) && (str_next != NULL)) /* Then user entered a 2nd arg */
	{
		if (strcmp(str_next, "-") == 0) /* 1st check to see if 2nd argument is "-" */
		{
			pwd_old = getenv("OLDPWD"); /* Change to previous directory */
			if (pwd_old == NULL)
			{
				perror("cd: OLDPWD not set");
				exit(EXIT_FAILURE);
			}
			if (chdir(pwd_old) != 0)
			{
				perror("cd: No such directory");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (chdir(str_next) != 0)
			{
				perror("No such file or directory");
				exit(EXIT_FAILURE);
			}
		}
	}

	return (0);
}
