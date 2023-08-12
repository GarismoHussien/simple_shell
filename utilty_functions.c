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

