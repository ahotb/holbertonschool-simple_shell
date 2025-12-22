#include "hsh.h"

/**
 * is_builtin - Checks if a command is built-in
 * @args: tokenized command
 *
 * Return: 1 if built-in, 0 otherwise
 */
int is_builtin(char **args)
{
	if (!args || !args[0])
		return (0);
	if (strcmp(args[0], "exit") == 0)
		return (1);
	if (strcmp(args[0], "env") == 0)
		return (1);
	return (0);
}

/**
 * handle_builtin - Executes built-in commands
 * @args: tokenized command
 * @prog_name: program name for errors (not used here)
 *
 * Return: 1 if exit command, 0 otherwise
 */
int handle_builtin(char **args, char *prog_name)
{
	(void)prog_name;

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		int i = 0;
		while (environ[i])
		{
			write(STDOUT_FILENO, environ[i], strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
	}
	return (0);
}
