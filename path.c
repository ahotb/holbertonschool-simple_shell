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
	int i = 0, j, k;

	if (!cmd || !cmd[0])
		return (NULL);

	if (_has_char(cmd, '/'))
		return (access(cmd, X_OK) == 0 ? _strdup(cmd) : NULL);

	while (environ[i] && _strcmp(environ[i], "PATH=") != 0)
		i++;

	if (!environ[i])
		return (NULL);

	copy = _strdup(environ[i] + 5);
	dir = strtok(copy, ":");

	while (dir)
	{
		full = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (!full)
			break;

		j = 0;
		while (dir[j])
			full[j] = dir[j], j++;

		full[j++] = '/';
		k = 0;
		while (cmd[k])
			full[j++] = cmd[k++];

		full[j] = '\0';

		if (access(full, X_OK) == 0)
			return (free(copy), full);

		free(full);
		dir = strtok(NULL, ":");
	}
	free(copy);
	return (NULL);
}
