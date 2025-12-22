#include "hsh.h"

/**
 * shell_loop - runs the shell loop
 * @av: argument vector
 */
void shell_loop(char **av)
{
char *line;
size_t len;
ssize_t nread;

line = NULL;
len = 0;
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
if (line[nread - 1] == '\n')
line[nread - 1] = '\0';
execute_command(line, av);
}
free(line);
}
