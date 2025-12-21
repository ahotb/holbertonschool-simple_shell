#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include "hsh.h"
/**
 * main - simple UNIX command line interpreter
 * @ac: argument count (unused)
 * @av: argument vector (program name)
 *
 * Return: Always 0
 */

int main(int ac, char **av)
{
char *line = NULL;
size_t len = 0;
ssize_t nread;
pid_t pid;
char *args[2];
(void)ac;
while (1)
{
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "#cisfun$ ", 9);
nread = getline(&line, &len, stdin);
if (nread == -1)
break;
if (line[nread - 1] == '\n')
line[nread - 1] = '\0';
if (*line == '\0')
continue;

		pid = fork();
		if (pid == 0)
		{
			args[0] = line;
			args[1] = NULL;
			execve(line, args, environ);

			write(STDERR_FILENO, av[0], strlen(av[0]));
			write(STDERR_FILENO,
			      ": No such file or directory\n", 28);
			exit(127);
		}
		else
			wait(NULL);
	}
	free(line);
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	return (0);
}

