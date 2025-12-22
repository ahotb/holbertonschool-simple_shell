#include "hsh.h"

/**
 * find_in_path - Finds full path of a command
 * @cmd: command name (e.g., "ls")
 *
 * Return: allocated full path, or NULL if not found
 */
char *find_in_path(char *cmd)
{
	char *path, *copy, *dir, *full;
	int i = 0;

	if (!cmd || !*cmd)
		return (NULL);

	if (strchr(cmd, '/'))
		return (access(cmd, X_OK) == 0 ? strdup(cmd) : NULL);

	while (environ[i] && strncmp(environ[i], "PATH=", 5))
		i++;
	if (!environ[i])
		return (NULL);

	copy = strdup(environ[i] + 5);
	if (!copy)
		return (NULL);

	dir = strtok(copy, ":");
	while (dir)
	{
		full = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full)
			break;
		sprintf(full, "%s/%s", dir, cmd);
		if (access(full, X_OK) == 0)
			return (free(copy), full);
		free(full);
		dir = strtok(NULL, ":");
	}
	return (free(copy), NULL);
}
