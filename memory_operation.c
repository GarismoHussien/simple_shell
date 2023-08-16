#include "shell.h"
/**
 * _realloc - the purpose of this function is
 *           to reallocate a block of memory.
 * @ptr: this is a pointer that points to the
 *             previous malloc'ated block.
 * @old_size: this is a variable refers to the
 *            byte size of previous block.
 * @new_size: this a variable that refers to the
 *            byte size of a new block.
 *
 * Return: this is a pointer that points to a reallocated block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
/**
 * ffree - the purpose of this function is to free  allocated array of strings.
 * @pp: this is a pointer that points to a string.
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

