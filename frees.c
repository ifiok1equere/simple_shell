#include "main.h"
/**
 * frees - frees memory
 * @argv: to be freed
 */
void frees(char **argv, char **envp)
{
	int i = 0, j;

	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
	if (envp)
	{
		j = 0;
		while (envp[j])
		{
			free(envp[j]);
			j++;
		}
		free(envp);
	}

}
