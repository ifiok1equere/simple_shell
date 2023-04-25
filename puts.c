#include "main.h"
/**
 * _puts - string displayed
 * @str: string
 */
void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}
	/*_putchar('\n');*/
}
