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
/**
 * _myunsetenv - this is to delete or clear an environment variable.
 *
 * @info: this is a structure type of type info_t.
 * Return: 0 is always returned.
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}
/**
 * populate_env_list - this is to make env linked list populated.
 * @info: this is a structure type of type info_t,
 *  containing potential arguments.
 * Return: 0 is always returned.
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

