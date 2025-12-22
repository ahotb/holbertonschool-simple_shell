#include "hsh.h"
/**
 * execute_command - executes a command
 * @line: input string
 * @av: program arguments
 */

void execute_command(char *line, char **av)
{
	pid_t pid;
	int status;
	char *cmd_path;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		cmd_path = find_in_path(line[0]);
		if (cmd_path)
		{
			if (execve(cmd_path, line, environ) == -1)
			{
				perror(av[0]);
				free(cmd_path);
				exit(EXIT_FAILURE);
			}
			free(cmd_path);
		}
		else
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
	}
}
