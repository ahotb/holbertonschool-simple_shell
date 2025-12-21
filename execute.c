#include "hsh.h"
/**
 * tokenize - splits a string into tokens
 * @line: input string
 *
 * Return: array of tokens (NULL-terminated)
 */
char **tokenize(char *line)
{
char **tokens = malloc(64 * sizeof(char *));
char *token;
int i = 0;
if (!tokens || !line)
return (NULL);
token = strtok(line, " \t\n\r");
while (token)
{
tokens[i++] = token;
token = strtok(NULL, " \t\n\r");
}
tokens[i] = NULL;
return (tokens);
}

/**
 * execute_command - executes a command
 * @line: input string
 * @av: program arguments
 */
void execute_command(char *line, char **av)
{
char **args;
pid_t pid;
if (!line)
return;
line = trim_spaces(line);
if (*line == '\0')
return;
args = tokenize(line);
if (!args || !args[0])
{
free(args);
return;
}

pid = fork();
if (pid == 0)
{
execve(args[0], args, environ);
write(STDERR_FILENO, av[0], strlen(av[0]));
write(STDERR_FILENO,
": No such file or directory\n", 28);
_exit(127);
}
else if (pid > 0)
{
wait(NULL);
}
free(args);
}
