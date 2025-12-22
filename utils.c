#include "hsh.h"

/**
 * trim_spaces - removes leading and trailing spaces and tabs
 * @str: input string
 *
 * Return: pointer to trimmed string
 */
char *trim_spaces(char *str)
{
char *end;

if (!str)
return (NULL);
while (*str == ' ' || *str == '\t')
str++;
if (*str == '\0')
return (str);
end = str + strlen(str) - 1;
while (end > str && (*end == ' ' || *end == '\t'))
end--;
*(end + 1) = '\0';
return (str);
}
