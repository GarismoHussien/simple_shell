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
