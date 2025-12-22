#include "hsh.h"
/**
 * execute_command - executes a command
 * @line: input string
 * @av: argument vector
 */
void execute_command(char *line, char **av)
{
pid_t pid;
char *path;
char *argv_exec[2];

line = trim_spaces(line);
if (!line || *line == '\0')
return;
path = find_in_path(line);
if (!path)
{
write(STDERR_FILENO, av[0], strlen(av[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, line, strlen(line));
write(STDERR_FILENO, ": not found\n", 12);
return;
}
pid = fork();
if (pid == -1)
{
free(path);
return;
}

if (pid == 0)
{
argv_exec[0] = line;
argv_exec[1] = NULL;
execve(path, argv_exec, environ);
_exit(127);
}
wait(NULL);
free(path);
}
