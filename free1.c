#include "main.h"
/**
 * frees - frees memory
 * @argv: to be freed
 */
void frees1(char **argv)
{
	int i = 0;

	if (argv)
	{
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}

}
