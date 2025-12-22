#include "hsh.h"

/**
 * tokenize - Splits a line into tokens (arguments)
 * @line: input command line
 *
 * Return: NULL-terminated array of tokens
 */
char **tokenize(char *line)
{
	char **tokens = NULL;
	char *token;
	size_t size = 0;
	

	token = strtok(line, " \t");
	while (token)
	{
		tokens = realloc(tokens, sizeof(char *) * (size + 2));
		if (!tokens)
			return (NULL);
		tokens[size] = strdup(token);
		if (!tokens[size])
		{
			free_tokens(tokens);
			return (NULL);
		}
		size++;
		token = strtok(NULL, " \t");
	}
	if (tokens)
		tokens[size] = NULL;
	return (tokens);
}

/**
 * find_in_path - searches for a command in PATH directories
 * @cmd: command name (e.g., "ls")
 *
 * Return: full path if found (must be freed by caller), NULL otherwise
 */
char *find_in_path(char *cmd)
{
	char *path_env = getenv("PATH");
	char *path_copy, *dir, *full_path;
	size_t cmd_len, dir_len;

	if (!path_env || !cmd)
		return (NULL);

	cmd_len = strlen(cmd);
	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		dir_len = strlen(dir);
		full_path = malloc(dir_len + cmd_len + 2);
		if (!full_path)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(full_path, dir);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}

		free(full_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}

/**
 * free_tokens - frees an array of tokens
 * @tokens: NULL-terminated array of tokens
 */
void free_tokens(char **tokens)
{
	size_t i;

	if (!tokens)
		return;

	for (i = 0; tokens[i]; i++)
		free(tokens[i]);
	free(tokens);
}