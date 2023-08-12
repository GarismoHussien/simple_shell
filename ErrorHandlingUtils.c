#include "shell.h"

/**
 * _erratoi - converts a string to an integer,handling errors if string contains non-numeric characters or if the result exceeds the maximum integer value
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *       -1 on error
 */
int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;
if (*s == '+')
s++;  /* TODO: why does this code let main return 255? */
for (i = 0;  s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
result *= 10;
result += (s[i] - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}
i
