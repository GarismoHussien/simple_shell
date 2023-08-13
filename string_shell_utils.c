#include "shell.h"
/**
 **_strncat - concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: amount of bytes to be maximally used
 *Return: concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;
i = 0;
j = 0;
while (dest[i] != '\0')
i++;
while (src[j] != '\0' && j < n)
{
dest[i] = src[j];
i++;
j++;
}
if (j < n)
dest[i] = '\0';
return (s);
}

/**
 **_strchr - locates a char in a string
 *@s: string to be parsed
 *@c: character to look for
 *Return: (s) a pointer to memory area s
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
return (s);
}
 while (*s++ != '\0');
return (NULL);
}

