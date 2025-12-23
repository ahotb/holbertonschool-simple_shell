#include "hsh.h"

/**
 * shell_loop - Main loop of the shell
 * @av: argument vector (for error messages)
 *
 * Description: Handles both interactive and non-interactive modes.
 * Prints prompt only in interactive mode.
 */
void shell_loop(char **av)
{
	char *line = NULL, *orig, **args;
	ssize_t nread;
	int last_status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);

		nread = _getline(&line);
		if (nread == -1)
			break;

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		orig = line;
		line = trim_spaces(line);

		if (*line)
		{
			args = tokenize(line);
			if (args && is_builtin(args))
			{
				last_status = handle_builtin(args, av[0], last_status);
				if (last_status < 0)
				{
					free_tokens(args);
					free(line);
					exit((-last_status) - 1);
				}
			}
			else if (args)
				last_status = execute_command(args, av);

			free_tokens(args);
		}
		line = orig;
	}
}
