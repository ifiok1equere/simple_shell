#include "main.h"
/**
 * _realloc - reallocating dynamic memory
 * @ptr: pointer to previously allocated memory
 * @old_size: number of bytes of previous memory block
 * @new_size: number of bytes to be allocated
 * Return: a pointer
 */
char *_realloc(char *ptr, size_t old_size, size_t new_size)
{
	char *p;

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		ptr = NULL;
		return (NULL);
	}
	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		return (ptr);
	}
	if (new_size == old_size)
		return (ptr);
	if (new_size > old_size)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		_memcpy(p, ptr, old_size);
	}
	if (new_size < old_size)
	{
		p = malloc(new_size);
		if (p == NULL)
			return (NULL);
		_memcpy(p, ptr, new_size);
	}
	free(ptr);
	return (p);
}
