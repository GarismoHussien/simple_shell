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
/**
 * _puts - this function is to print an input string.
 * @str: this is a pointer that points to the string to be printed.
 *
 * Return: Nothing will be returned.
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

