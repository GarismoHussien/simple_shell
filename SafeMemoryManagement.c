#include "shell.h"

/**
 * bfree - Safe Pointer Freeing
 * @ptr: Address of the pointer to free.
 *
 * Return: 1 if pointer was freed, 0 otherwise.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}

