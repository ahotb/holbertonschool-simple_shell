#include "hsh.h"
/**
 * shell_loop - main loop of the shell
 * @av: program arguments
 */
void shell_loop(char **av)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			break;
		}

		line = trim_spaces(line);
		if (strlen(line) > 0)
			execute_command(line, av);
	}

	free(line);
}
