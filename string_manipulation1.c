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
/**
 * _strdup -the purpose of this function is to duplicate a string.
 * @str: is a pointer to the string to have it duplicated.
 *
 * Return: the function will return a pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}
/**
 * _strcpy - this function is to copy a string from src to dest.
 * @dest: this is the destination buffer.
 * @src: this is the source of the string.
 *
 * Return: pointer to the string in dest.
 */
char *_strcpy(char *dest, char *src)
{
	int e = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[e])
	{
		dest[e] = src[e];
		e++;
	}
	dest[e] = 0;
	return (dest);
}

