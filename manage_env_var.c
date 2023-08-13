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
/**
 * _getenv - this is to take the value of a specific environment variable.
 * @info: is a character pointer and a type of structure.
 * @name: is the name of environment variable
 *
 * Return: the value returns NULL
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - this function is to modify an existing one,
 *             or Initialise a new environment variable.
 * @info: is a structure type of type info_t ,
 *        Used to maintain constant function prototype.
 *  Return: 0 is always returned.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

