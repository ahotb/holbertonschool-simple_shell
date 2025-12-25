#include "hsh.h"

/**
 * trim_spaces - Removes leading/trailing whitespace
 * @str: input string
 *
 * Return: pointer to trimmed string (within original memory)
 */
char *trim_spaces(char *str)
{
	char *end;

	if (!str || *str == '\0')
		return (str);

	while (*str == ' ' || *str == '\t')
		str++;

	if (*str == '\0')
		return (str);

	end = str + _strlen(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
		end--;

	*(end + 1) = '\0';
	return (str);
}

/**
 * tokenize - Splits a line into tokens (arguments)
 * @line: input command line (e.g., "ls -l /tmp")
 *
 * Return: NULL-terminated array of tokens
 */
char **tokenize(char *line)
{
	char **tokens = malloc(sizeof(char *) * MAX_TOKENS), *token;
	int i = 0, start, end, token_len, j;

	if (!line || !tokens)
		return (NULL);
	start = 0;
	while (line[start])
	{
		while (line[start] == ' ' || line[start] == '\t')
			start++;
		if (!line[start])
			break;
		end = start;
		while (line[end] != ' ' && line[end] != '\t' && line[end] != '\0')
			end++;

		token_len = end - start;
		token = malloc(token_len + 1);
		if (!token)
			return (NULL);

		for (j = 0; j < token_len; j++)
			token[j] = line[start + j];
		token[token_len] = '\0';

		tokens[i++] = token;
		start = end;
	}
	tokens[i] = NULL;

	return tokens;
}

/**
 * free_tokens - Frees the tokens array (not the strings)
 * @tokens: array returned by tokenize
 */
void free_tokens(char **tokens)
{
	int i = 0;

	if (!tokens)
		return;

		while (tokens[i])
		{
			free(tokens[i]);
			i++;
		}
		free(tokens);
}
