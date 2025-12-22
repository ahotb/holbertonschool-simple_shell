#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parse.h"

#define MAX_ARGS 64
#define DELIM " \t\r\n\a"

/**
 * read_line - read a line from stdin
 *
 * Return: pointer to the line
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;

    if (getline(&line, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
            exit(0);
        else
        {
            perror("readline");
            exit(EXIT_FAILURE);
        }
    }
    return line;
}

/**
 * split_line - splits a line into tokens
 * @line: input string
 *
 * Return: array of tokens (NULL terminated)
 */
char **split_line(char *line)
{
    int bufsize = MAX_ARGS, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, DELIM);
    while (token)
    {
        tokens[position++] = token;
        if (position >= bufsize)
        {
            bufsize += MAX_ARGS;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens)
            {
                fprintf(stderr, "allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}
