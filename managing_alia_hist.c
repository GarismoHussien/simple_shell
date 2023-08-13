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

