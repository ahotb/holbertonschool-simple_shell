#include "hsh.h"

/**
 * execute_command - Executes external commands
 * @args: NULL-terminated array of arguments
 * @av: argument vector (for program name in errors)
 *
 * Description: Forks only if command exists (via find_in_path).
 */
int execute_command(char **args, char **av)
{
	char *path;
	pid_t pid;
	int status;
	char *argv_exec[64];
	int i = 0;

	if (!args || !args[0])
		return (0);

	path = find_in_path(args[0]);
	if (!path)
	{
		write(STDERR_FILENO, av[0], strlen(av[0]));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		return (127);
	}

	while (args[i] && i < 63)
	{
		argv_exec[i] = args[i];
		i++;
	}
	argv_exec[i] = NULL;

	pid = fork();
	if (pid == 0)
	{
		execve(path, argv_exec, environ);
		_exit(127);
	}
	else
	{
		wait(&status);
		free(path);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}
	return (0);
}
