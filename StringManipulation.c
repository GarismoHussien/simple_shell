#include "shell.h"

/**
 * input_buf - buffers chained commands,reads input from the user(buff chanined cmd)
 * @info: parameter struct containing information about the shell(param. struct.)
 * @buf: address of buffer where  input will be stored(address).
 * @len: address of len var representing the length of the buffer
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
ssize_t r = 0;
size_t len_p = 0;
if (!*len) /* if nothing left in buffer, fill it ,Please */
{
/*bfree((void **)info->cmd_buf);*/
free(*buf);
*buf = NULL;
signal(SIGINT, sigintHandler);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(info, buf, &len_p);
#endif
if (r > 0)
{
if ((*buf)[r - 1] == '\n')
{
(*buf)[r - 1] = '\0'; /* remove trailing newline immediately  */
r--;
}
info->linecount_flag = 1;
remove_comments(*buf);
build_history_list(info, *buf, info->histcount++);
/* if (_strchr(*buf, ';')) is this a command chain? */
{
*len = r;
info->cmd_buf = buf;
}
}
}
return (r);
}

/**
 * get_input - gets a line -  newline
 * @info: parameter struc.
 *
 * Return: bytes read for sure
 */
ssize_t get_input(info_t *info)
{
static char *buf; /* the ';' command chain buf  */
static size_t i, j, len;
ssize_t r = 0;
char **buf_p = &(info->arg), *p;
_putchar(BUF_FLUSH);
r = input_buf(info, &buf, &len);
if (r == -1) /* EOF */
return (-1);
if (len) /* we have commands left in chain buffer */
{
j = i; /* init new iterator to current buf position */
p = buf + i; /* get pointer for return,get */
check_chain(info, buf, &j, i, len);
while (j < len) /* iterate to semicolon  end */
{
if (is_chain(info, buf, &j))
break;
j++;
}
i = j + 1; /* increment past null ';'' */
if (i >= len) /* reached end of buf? */
{
i = len = 0; /* reset position & length */
info->cmd_buf_type = CMD_NORM;
}
*buf_p = p; /* pass back pointer to current cmd position */
return (_strlen(p)); /* return length of current cmd  */
}
*buf_p = buf; /* else not chain, pass back buff from _getline() */
return (r); /* return length  from _getline() of buffer */
}
/**
 * read_buf - reads a buff
 * @info: parameter struct
 * @buf: buff
 * @i: size (Size)
 *
 * Return: r
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
ssize_t r = 0;
if (*i)
return (0);
r = read(info->readfd, buf, READ_BUF_SIZE);
if (r >= 0)
*i = r;
return (r);
}

