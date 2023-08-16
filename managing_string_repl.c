#include "shell.h"

/**
 * is_chain - this function is to check whether current char in buffer is a chain delimiter.
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

