#include "shell.h"

/**
 * is_chain - this function is to check whether current
 *    char in buffer is a chain delimiter.
 * @info: this is the parameter and is struct type.
 * @buf: this is a pointer point to the char buffer.
 * @p:  this pointer is the address of the current position in the buffer.
 *
 * Return: if the function found a chain delimiter return 1, or 0 if not found.
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t j = *p;

	if (buf[j] == '|' && buf[j + 1] == '|')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[j] == '&' && buf[j + 1] == '&')
	{
		buf[j] = 0;
		j++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[j] == ';') /* found end of this command */
	{
		buf[j] = 0; /* replace semicolon with null */
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = j;
	return (1);
}
/**
 * replace_alias - this function is to replace an aliases
 *     in the break_down_string.c
 * @info: this is the parameter and is a struct type.
 *
 * Return: if replaced 1 will be returned, or returns 0 if not replaced.
 */
int replace_alias(info_t *info)
{
	int i;
	list_t *node;
	char *p;

	for (i = 0; i < 10; i++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		info->argv[0] = p;
	}
	return (1);
}
/**
 * check_chain - this function tests or checks we should continue
 *    chaining based on last status.
 * @info: this is the parameter and is a struct type.
 *
 * @buf: this is a pointer the char buffer
 * @p: this is a pointer and points to the address
 * of the current position in buffer.
 *
 * @i: this is a variable of type size_t use it to start position in buffer.
 * @len: this is a variable used to get the length of the buffer.
 *
 * Return: Nothing (Void).
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}
/**
 * replace_vars - the purpose is to replace the environment variables
 *     in the break_down_sreing.c
 * @info: is  a pointer of struct type.
 *
 * Return: if replaced 1 will be returned, or returns 0 if not replaced.
 */
int replace_vars(info_t *info)
{
	int i = 0;
	list_t *node;

	for (i = 0; info->argv[i]; i++)
	{
		if (info->argv[i][0] != '$' || !info->argv[i][1])
			continue;

		if (!_strcmp(info->argv[i], "$?"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[i], "$$"))
		{
			replace_string(&(info->argv[i]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[i][1], '=');
		if (node)
		{
			replace_string(&(info->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[i], _strdup(""));

	}
	return (0);
}
/**
 * replace_string - this function is to replace the old ,
 *     string with the new string.
 * @old: is a pointer that points to the address of old string.
 * @new: is a pointer of char type pointing to the new string.
 *
 * Return: if replaced 1 will be returned, or returns 0 if not replaced.
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

