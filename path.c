#include "hsh.h"
/**
 * find_in_path - searches for a command in PATH
 * @cmd: command name
 *
 * Return: full path if found, otherwise NULL
 */
char *find_in_path(char *cmd)
{
char *path_copy;
char *dir;
char *full_path;
char *path_env;
int i;

if (!cmd || !*cmd)
return (NULL);
if (strchr(cmd, '/'))
{
if (access(cmd, X_OK) == 0)
return (strdup(cmd));
return (NULL);
}
path_env = NULL;
for (i = 0; environ[i]; i++)
{
if (strncmp(environ[i], "PATH=", 5) == 0)
{
path_env = environ[i] + 5;
break;
}
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
