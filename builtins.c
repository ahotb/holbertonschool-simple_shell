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

	if (_strcmp(args[0], "exit") == 0)
		return (1);
	if (_strcmp(args[0], "env") == 0)
		return (1);

	return (0);
}

int handle_builtin(char **args, char *prog, int last_status)
{
	int i = 0;
	(void)prog;

	if (_strcmp(args[0], "exit") == 0)
	{
		if (!args[1])
			return (-last_status - 1);
		return (-_atoi(args[1]) - 1);
	}

	if (_strcmp(args[0], "env") == 0)
	{
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
	}
	return (last_status);
}
