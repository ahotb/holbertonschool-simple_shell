#include "hsh.h"

void shell_loop(char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (nread > 0 && line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		execute_command(line, av);
	}

	free(line);
}
