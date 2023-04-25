#include "main.h"
/**
 * errors - prints errors
 * @argv: array
 */
void errors(char *argv)
{
	char *error = ": command not found\n";

	write(2, argv, _strlen(argv));
	write(2, error, _strlen(error));
}
