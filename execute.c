#include "hsh.h"
/**
 * execute_command - executes a command
 * @line: input string
 * @av: program arguments
 */

void execute_command(char *line, char **av)
{
	pid_t pid;
	char *path;
	char *argv_exec[2];

	if (!line || *line == '\0')
		return;

	path = find_in_path(line);
	if (!path)
	{

		write(STDERR_FILENO, av[0], strlen(av[0]));
		write(STDERR_FILENO, ": No such file or directory\n", 28);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		free(path);
		return;
	}
	else if (pid == 0)
	{

		argv_exec[0] = line;
		argv_exec[1] = NULL;
		if (execve(path, argv_exec, environ) == -1)
		{
			write(STDERR_FILENO, av[0], strlen(av[0]));
			write(STDERR_FILENO, ": No such file or directory\n", 28);
			free(path);
			_exit(127);
		}
	}
	else
	{

		wait(NULL);
	}

	free(path);
}
