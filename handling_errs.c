#include "shell.h"

/**
 * _eputs - we use it to print the input string.
 * @str: this is a pointer pointing to the string to be printed.
 *
 * Return: (void) Nothing.
 */
void _eputs(char *str)
{

	if (!str)
		return;
	int i = 0;

	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}
/**
 * _eputchar - this function is to write the character c to stderr.
 * @c: takes the character to print.
 *
 * Return: if it is succeeded return 1.
 * On error,  return -1, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static char buf[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

