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
/**
 * starts_with - this function is to checks or lock for wheather,
 *    needle starts with haystack or no.
 * @haystack: this is a pointer string to search.
 * @needle: this is a pointer to the substring to find.
 *
 * Return: NULL if any character doesn’t match,
  *       or a pointer to the next char of haystack.
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

