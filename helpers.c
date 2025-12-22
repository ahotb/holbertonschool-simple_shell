#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "helpers.h"

/**
 * trim_spaces - remove leading and trailing spaces
 * @str: input string
 *
 * Return: pointer to trimmed string
 */
char *trim_spaces(char *str)
{
    char *end;
    while (*str == ' ' || *str == '\t')
        str++;
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\t'))
        end--;
    *(end + 1) = '\0';
    return str;
}

/**
 * tokenize - split line into tokens
 * @line: input string
 *
 * Return: array of tokens (NULL terminated)
 */
char **tokenize(char *line)
{
    int bufsize = 64, pos = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token;

    if (!tokens)
    {
        fprintf(stderr, "allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, " \t\r\n\a");
    while (token)
    {
        tokens[pos++] = token;
        if (pos >= bufsize)
        {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
        }
        token = strtok(NULL, " \t\r\n\a");
    }
    tokens[pos] = NULL;
    return tokens;
}

/**
 * free_tokens - free array of tokens
 * @tokens: array
 */
void free_tokens(char **tokens)
{
    free(tokens);
}

/**
 * handle_builtin - execute builtin command if any
 * @args: command and args
 *
 * Return: 1 if builtin executed, 0 otherwise
 */
int handle_builtin(char **args)
{
    if (!args || !args[0])
        return 0;

    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1])
        {
            if (chdir(args[1]) != 0)
                perror("cd");
        }
        else
            chdir(getenv("HOME"));
        return 1;
    }
    if (strcmp(args[0], "exit") == 0)
        exit(0);

    return 0;
}
