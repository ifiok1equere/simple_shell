#include "main.h"
/**
 * envs - copy environment variables
 */
void envs(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}
