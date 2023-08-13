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
/* toem_parser.c */
int is_cmd(info_t *, char *);
char *find_path(info_t *, char *, char *);
char *dup_chars(char *, int, int);

/* loophsh.c */
int loophsh(char **);

/* toem_errors.c */
int _putfd(char c, int fd);
void _eputs(char *);
int _eputchar(char);
int _putsfd(char *str, int fd);

/* toem_string.c */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* toem_string1.c */
char *_strcpy(char *, char *);
char *_strdup(const char *);
void _puts(char *);
int _putchar(char);

/* toem_exits.c */
char *_strncpy(char *, char *, int);
char *_strchr(char *, char);
char *_strncat(char *, char *, int);

/* toem_tokenizer.c */
char **strtow2(char *, char);
char **strtow(char *, char *);

/* toem_realloc.c */
char *_memset(char *, char, unsigned int);
void *_realloc(void *, unsigned int, unsigned int);
void ffree(char **);

/* toem_memory.c */
int bfree(void **);

/* toem_atoi.c */
int _isalpha(int);
int _atoi(char *);
int interactive(info_t *);
int is_delim(char, char *);

/* toem_errors1.c */
int _erratoi(char *);
char *convert_number(long int, int, int);
void remove_comments(char *);
void print_error(info_t *, char *);
int print_d(int, int);

/* toem_builtin.c */
int _myexit(info_t *);
int _mycd(info_t *);
int _myhelp(info_t *);

/* toem_builtin1.c */
int _myhistory(info_t *);
int _myalias(info_t *);
/*toem_getline.c */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* toem_getinfo.c */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* toem_environ.c */
char *_getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* toem_getenv.c */
char **get_environ(info_t *);
int _unsetenv(info_t *, char *);
int _setenv(info_t *, char *, char *);

/* toem_history.c */
int write_history(info_t *info);
int read_history(info_t *info);
char *get_history_file(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* toem_lists.c */
int delete_node_at_index(list_t **, unsigned int);
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
void free_list(list_t **);

/* toem_lists1.c */
ssize_t get_node_index(list_t *, list_t *);
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t print_list(const list_t *);
list_t *node_starts_with(list_t *, char *, char);
/* toem_vars.c */
int replace_alias(info_t *);
int replace_string(char **, char *);
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t *, size_t, size_t);
int replace_vars(info_t *);
#endif
