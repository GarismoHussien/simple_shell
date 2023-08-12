#include "shell.h"

/**
 * interactive - if shell is interactive mode returns true.
 * @info: this is a struct address
 *
 * Return: if interactive mode returns 1 or 0 if false.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - is to check the character if it is a delimiter.
 * @c: this is the  char to be checked in the function.
 * @delim: is the given delimiter string.
 * Return: if true return 1,  if false return 0.
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - using the ascii code to check the alphabetic character.
 * @c: The inputted character.
 * Return: if c is alphabetic return 1 or 0 if false.
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

