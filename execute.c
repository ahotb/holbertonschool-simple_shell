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

	if (!args || !args[0])
		return (0);

	path = find_in_path(args[0]);
	if (!path)
	{
		write(2, av[0], _strlen(av[0]));
		write(2, ": 1: ", 5);
		write(2, args[0], _strlen(args[0]));
		write(2, ": not found\n", 12);
		return (127);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		free(path);
		return (1);
	}
	if (pid == 0)
	{
		execve(path, args, environ);
		perror("execve");
		free(path);
		exit(127);
	}
	wait(&status);
	free(path);
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 0);
}
