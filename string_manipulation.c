#include "shell.h"

/**
 * _strcat - this function is to add two strings together.
 * @dest: the destination buffer is a pointer and first parameter.
 * @src: this is a pointer to the source buffer to ,
 * add each character to the end of the dest.
 *
 * Return: pointer to the beginning of the adjusted  buffer or dest.
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

