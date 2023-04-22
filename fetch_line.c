#include "main.h"
/**
 * fetchline1 - this function complements above function
 * @p: pointer to the text from stream
 * @q: buffer
 * @r: moving pointer.
 * @ending_buf: pointer to the end of the text in buffer
 * @n: number of bytes for memory allocation
 * Return: function returns the number of characters read
 */
ssize_t fetchline1(char **p, char *q, char *r, char *ending_buf, size_t *n)
{
	ssize_t read_count = 1, read_count_total = 0;
	size_t new_size;
	char *new_buf;

	while (read_count != 0)
	{
		read_count = read(STDIN_FILENO, r, 1);
		if (read_count == -1)
			return (-1);
		read_count_total += read_count;
		if (*r == '\n')
			break;
		if (r == ending_buf)
		{
			new_size = *n * 2;
			new_buf = _realloc(q, *n, new_size);
			if (new_buf == NULL)
				return (-1);
			q = new_buf;
			*p = q;
			r = q + *n - 1;
			ending_buf = q + new_size;
			*n = new_size;
		}
		r++;
	}
	r++;
	*r = '\0';
	*p = q;
	return (read_count_total);
}
/**
 * fetchline - this function retrieves an entire line from a stream
 * @lineptr: pointer to the text from stream
 * @n: number of bytes needed for buffer memory allocation or reallocation
 * @stream: can be any of stdin, stdout and stderr
 * Return: function returns the number of characters read
 */
ssize_t fetchline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t read_count_total;
	char *buf, *new_buf, *moving_buf, *ending_buf;

	if (!lineptr || !n || !stream)
		return (-1);
	fflush(stdout);
	if (*lineptr == NULL && *n == 0)
	{
		*n = CL_CHAR_NUM;
		buf = malloc(*n);
		if (buf == NULL)
			return (-1);
		*lineptr = buf;
	}
	else
		buf = *lineptr;
	moving_buf = buf;
	ending_buf = buf + *n;
	read_count_total =  fetchline1(lineptr, buf, moving_buf, ending_buf, n);
	return (read_count_total);
}
