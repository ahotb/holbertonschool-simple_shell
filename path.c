#include "hsh.h"

/**
 * find_in_path - searches for a command in PATH directories
 * @cmd: command name (e.g., "ls")
 *
 * Return: full path if found (must be freed by caller), NULL otherwise
 */
char *find_in_path(char *cmd)
{
	char *path_env, *path_copy, *dir, *full_path;
	struct stat st;

	if (!cmd || !*cmd)
		return (NULL);

	if (strchr(cmd, '/'))
	{
		if (stat(cmd, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
			return (strdup(cmd));
		return (NULL);
	}

	path_env = getenv("PATH");
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
