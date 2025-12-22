#include <stdio.h>
#include <stdlib.h>
#include "parse.h"
#include "helpers.h"
#include "builtins.h"

/**
 * main - simple shell
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    char *line = NULL;
    char **args;
    int status = 1;

    (void)argc;
    (void)argv;

    while (1)
    {
        printf(":) ");
        line = read_line();
        if (!line)
            break;

        args = split_line(line);
        if (!args)
        {
            free(line);
            continue;
        }

        if (!handle_builtin(args))
            status = launch(args);

        free(line);
        free(args);
    }
    return 0;
}
