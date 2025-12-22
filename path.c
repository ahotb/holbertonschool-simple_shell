#include "hsh.h"

/**
 * find_in_path - Finds full path of a command
 * @cmd: command name (e.g., "ls")
 *
 * Return: allocated full path, or NULL if not found
 */
char *find_in_path(char *cmd)
{
	char *path_env = NULL, *path_copy, *dir, *full_path;
	struct stat st;
	int i = 0;

	if (!cmd || !*cmd)
		return (NULL);

	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
			return (strdup(cmd));
		return (NULL);
	}

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path_env = environ[i] + 5;
			break;
		}
		i++;
	}
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	dir = strtok(path_copy, ":");
	while (dir)
	{
		full_path = malloc(strlen(dir) + strlen(cmd) + 2);
		if (!full_path)
			break;
		sprintf(full_path, "%s/%s", dir, cmd);

		if (stat(full_path, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
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
