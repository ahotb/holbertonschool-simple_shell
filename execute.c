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

		if (execve(path, (char *[]){line, NULL}, environ) == -1)
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
