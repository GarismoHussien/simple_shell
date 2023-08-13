#include "shell.h"

/**
 * _myenv - this function is to print the current environment
 * @info: is a type of structure containing potential arguments.
 *          Used to maintain constant function prototype.
 * Return: 0 is always returned.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

