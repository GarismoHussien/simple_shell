#include "shell.h"

/**
 * get_history_file - the purpose is to construct the history file.
 * @info: is the parameter of a struct type.
 *
 * Return: will return allocated string containing history file path.
 */

char *get_history_file(info_t *info)
{
	char *dir;
	char *buf;

	dir = _getenv(info, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}
