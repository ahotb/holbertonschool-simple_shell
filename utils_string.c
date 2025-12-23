#include "hsh.h"
/**
 * _strlen - Returns length of a string
 * @s: input string
 *
 * Return: length of string
 */
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * _strdup - Duplicates a string
 * @s: input string
 *
 * Return: pointer to duplicated string
 */
char *_strdup(char *s)
{
	char *dup;
	int i, len;

	if (!s)
		return (NULL);

	len = _strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = s[i];
	dup[i] = '\0';

	return (dup);
}

/**
 * _has_char - Checks if a string contains a character
 * @s: input string
 * @c: character to find
 *
 * Return: 1 if found, 0 otherwise
 */
int _has_char(char *s, char c)
{
	int i = 0;

	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
