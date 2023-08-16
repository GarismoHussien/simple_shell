#include "shell.h"

/**
 * dup_chars - this function is to duplicate characters from (pathstr).
 * @pathstr:  is a pointer that points to the PATH string.
 * @start: is a variable holds the starting index.
 * @stop: is a variable that holds the stopping index.
 *
 * Return: will return a pointer to the new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

