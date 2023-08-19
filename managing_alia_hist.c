#include "shell.h"

/**
 * _myhistory - the purpose is to display the history list, preceded
 *              with line numbers, starting at 0 one command by line.
 * @info:is a structure type containing potential arguments,
 *          Used to maintain constant function prototype.
 *  Return: 0 is always returned.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - the purpose of this function is to set alias to string.
 * @info: is a structure type.
 * @str: is the pointer to the string alias.
 *
 * Return: if success 0 is returned or 1 on error.
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - the purpose of this function is to set alias to string.
 * @info: is a struct type used as a parameter.
 * @str: it is a pointer to the string alias.
 *
 * Return:  if success 0 is returned or 1 on error.
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this function is to print an alias string
 * @node: is a pointer that points to the alias node
 *
 * Return: if success 0 is returned otherwise 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - the purpose is to copy the alias builtin command.
 * @info: is a structure type containing potential arguments.
 *          Used to maintain constant function prototype.
 *  Return: if success 0 is returned or 1 on error.
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

