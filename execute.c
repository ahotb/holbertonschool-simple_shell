#include "hsh.h"

/**
 * tokenize -_splits a string into tokens using spaces/tabs as delimiters
 * @line: input string
 *
 * Return: array of tokens (NULL-terminated)
 */
char **tokenize(char *line)
{
char **tokens = malloc(64 * sizeof(char *));·
char *token;
int i = 0;
if (!line)
return NULL;
token = strtok(line, " \t\n\r");
while (token != NULL)
{
tokens[i] = token;
i++;
token = strtok(NULL, " \t\n\r");
}
tokens[i] = NULL;
return tokens;
}
void execute_command(char *line, char **av)
{
char **args;
pid_t pid;
args = tokenize(line);
if (!args || !args[0])§Ø±Øº
{
free(args);
return;
}
pid = fork();
if (pid == 0)
{
if (execve(args[0], args, environ) == -1)
{
write(STDERR_FILENO, av[0], strlen(av[0]));
write(STDERR_FILENO, ": No such file or directory\n", 27);
_exit(127);
}
}
else if (pid > 0)
{
int status;
waitpid(pid, &status, 0);
}
else
{
perror("fork failed");
}
free(args);
}
