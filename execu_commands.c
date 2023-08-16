#include "shell.h"

/**
 * dup_chars - this function is to duplicate characters from (pathstr).
 * @pathstr:  is a pointer that points to the PATH string.
 * @start: is a variable holds the starting index.
 * @stop: is a variable that holds the stopping index.
 *
 * Return: will return a pointer to the new buffer.
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}
/**
 * is_cmd - this function is to determine or check  if a file
 *          is an executable command or not.
 * @info: is a pointer info struct type.
 *
 * @path: is a pointer of char type
 *     pointing to the path of the file.
 *
 * Return: if true 1 will be returned or  0 if not.
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

