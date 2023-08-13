#ifndef _SHELL_H_
#define _SHELL_H_


#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* for read or and write buffers */
#define BUF_FLUSH -1
#define WRITE_BUF_SIZE 1024
#define READ_BUF_SIZE 1024
/* for cmd chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
/* 1 if using getline of system () */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
/* for convert_no.() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
/**
 * struct passinfo - hold pseudo-arguments to pass thro a func,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arg.
 * @argv:an array of strings generated from arg.
 * @history:  history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @err_num: error code for exit()s
 * @path: a string path for the current command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @argc: the argument count
 * @line_count: the error count
 * @linecount_flag: if on count this line of input
 * @fname: program filename (Titile)
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @status: return status of last exec'd command
 * @histcount: history line no. count
 */
typedef struct passinfo
{
char *fname;
list_t *env;
int argc;
unsigned int line_count;
int err_num;
int linecount_flag;
int status;
char **cmd_buf; /* pointer to cmd ; chain buffer, for memory  */
int cmd_buf_type; /* CMD_type ||, &&, ; */
int readfd;
char *arg;
char **argv;
char *path;
list_t *history;
list_t *alias;
char **environ;
int env_changed;
int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}
/**
 * struct liststr - singly linked list
 * @num: no. field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
int num;
struct liststr *next;
char *str;
} list_t;
/**
 * struct builtin - contains a builtin string and related functionn
 * @type: the builtin command flagg
 * @func: the functionn
 */
typedef struct builtin
{
int (*func)(info_t *);
char *type;
} builtin_table;


/* toem_shloop.c */
int hsh(info_t *, char **);
void find_cmd(info_t *);
int find_builtin(info_t *);
void fork_cmd(info_t *);

