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
/**
 * _strcmp - this function is to compare between two strings.
 * @s1: this is a pointer to the first string.
 * @s2: this is a pointer to the second string.
 *
 * Return: if s1 < s2 return negative,
 *   if s1 > s2, zero if s1 == s2 return positive.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

