#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "builtins.h"
/**
 * main - entry point for our shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, or exit code
 */
int main(int argc, char **argv)
{
char *line = NULL;
char **args;
int status = 1;

(void)argc;
(void)argv;

while (status >= 0)
{
printf(":) ");
line = read_line();
if (!line)
break;
args = split_line(line);
if (args[0])
{
if (is_builtin(args))
status = run_builtin(args);
else
status = launch(args);
}
free(line);
free(args);
}
return 0;
}

