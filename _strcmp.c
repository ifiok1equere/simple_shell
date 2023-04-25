#include "main.h"
#include <string.h>
#include <stdio.h>

/**
 * _strcmp - function compares two strings and returns an integer depending on
 * the result of the comparison. 0 for when the two strings are equal, positive
 * integer value for when s1 > s2 and negative integer value for when s1 < s2.
 *
 * @s1: this is the pointer to the first string.
 * @s2: pointer to the 2nd string.
 *
 * Return: integer
 */

int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0, m = 0;

	m = strlen(s1);

	while (s1[i])
	{
		if (s1[i] == s2[i])
		{
			if (i < m)
			{
				i++;
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			if (s1[i] > s2[i])
			{
				return (s1[i] - s2[i]);
			}
			else if (s1[i] < s2[i])
			{
				return (s1[i] - s2[i]);
			}
		}
	}

	return (0);
}
