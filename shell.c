#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - simple UNIX command line interpreter
 * @ac: argument count (unused)
 * @av: argument vector (program name)
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
char *line = NULL, *cmd;
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
cmd = line;
while (*cmd == ' ' || *cmd == '\t')
cmd++;
nread = strlen(cmd);
while (nread > 0 &&
(cmd[nread - 1] == ' ' || cmd[nread - 1] == '\t'))
{
cmd[nread - 1] = '\0';
nread--;
}
if (*cmd == '\0')
continue;
pid = fork();
if (pid == 0)
args[0] = cmd;
args[1] = NULL;
execve(cmd, args, environ);
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
