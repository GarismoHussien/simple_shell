#include "shell.h"

/**
 * _putchar - this function writes the character,
 *   that is referred through c to stdout.
 * @c: this is the parameter character to print.
 *
 * Return: if succeeded 1 will be printed.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

