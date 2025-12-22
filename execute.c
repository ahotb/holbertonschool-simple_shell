#include "hsh.h"

/**
 * execute_command - Executes external commands
 * @args: NULL-terminated array of arguments
 * @av: argument vector (for program name in errors)
 *
 * Description: Forks only if command exists (via find_in_path).
 */
void execute_command(char **args, char **av)
{
	char *path;
	pid_t pid;
	char *argv_exec[64];
	int i = 0;

	if (!args || !args[0])
		return;

	path = find_in_path(args[0]);
	if (!path)
	{
		write(STDERR_FILENO, av[0], strlen(av[0]));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, args[0], strlen(args[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		_exit(127);
	}

	while (args[i] != NULL && i < 63)
	{
		argv_exec[i] = args[i];
		i++;
	}
	argv_exec[i] = NULL;

	pid = fork();
	if (pid == 0)
	{
		if (execve(path, argv_exec, environ) == -1)
		{
			write(STDERR_FILENO, av[0], strlen(av[0]));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			free(path);
			_exit(127);
		}
	}
	else if (pid > 0)
	{
		wait(NULL);
	}

	free(path);
}
