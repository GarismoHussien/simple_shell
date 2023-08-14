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
/**
 * write_history -this is to write or create a file,
 *            or appends to a history or existing file.
 * @info: is a pointer of a struct type.
 *
 * Return: if success return 1 or -1 if fails.
 */
int write_history(info_t *info)
{
	char *filename = get_history_file(info);
	list_t *node = NULL;

	if (!filename)
		return (-1);
	ssize_t fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
/**
 * read_history - this function is  to read the history data,
 *            from the history file.
 * @info: is a pointer of a struct type and the parameter.
 *
 * Return: history count on success, or 0 if fails.
 */
int read_history(info_t *info)
{
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);
	int i, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < fsize; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_history_list(info, buf + last, linecount++);
			last = i + 1;
		}
	if (last != i)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
