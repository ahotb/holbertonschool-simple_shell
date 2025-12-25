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
	int i = 0, code;

	if (_strcmp(args[0], "exit") == 0)
	{
		code = last_status;
		if (args[1])
		{
			if (args[1][0] == '-')
			{
				write(2, prog, _strlen(prog));
				write(2, ": 1: exit: Illegal number: ", 27);
				write(2, args[1], _strlen(args[1]));
				write(2, "\n", 1);
				exit(2);
			}
			i = 0;
			while (args[1][i])
			{
				if (args[1][i] < '0' || args[1][i] > '9')
				{
					write(2, prog, _strlen(prog));
					write(2, ": exit: ", 11);
					write(2, args[1], _strlen(args[1]));
					write(2, ": numeric argument required\n", 28);
					exit(2);
				}
				i++;
			}
			code = (_atoi(args[1]) % 256);
		}
		exit(code);
	}

	if (_strcmp(args[0], "env") == 0)
	{
		i = 0;
		while (environ[i])
		{
			write(1, environ[i], _strlen(environ[i]));
			write(1, "\n", 1);
			i++;
		}
		return (last_status);
	}
	return (last_status);
}
