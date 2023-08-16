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
/**
 * _memset - the purpose of this function is to
 *          fill memory with a constant byte.
 * @s: this is the pointer to the memory area.
 * @b: this is a variable refers to the byte to fill *s with.
 * @n: this is a variable that refers to the amount of bytes to be filled.
 * Return: (s)  and this is a pointer to the memory area s.
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}
