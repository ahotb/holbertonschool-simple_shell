#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "builtins.h"

extern char **environ;

/**
 * is_builtin - checks if command is a builtin
 * @args: command and arguments
 *
 * Return: 1 if builtin, 0 otherwise
 */
int is_builtin(char **args)
{
    if (strcmp(args[0], "cd") == 0)
        return 1;
    if (strcmp(args[0], "exit") == 0)
        return 1;
    return 0;
}

/**
 * run_builtin - executes a builtin command
 * @args: command and arguments
 *
 * Return: exit code
 */
int run_builtin(char **args)
{
    if (strcmp(args[0], "cd") == 0)
    {
        if (args[1])
        {
            if (chdir(args[1]) != 0)
                perror("cd");
        }
        else
            chdir(getenv("HOME"));
        return 0;
    }
    else if (strcmp(args[0], "exit") == 0)
    {
        exit(0);
    }
    return 1;
}

/**
 * find_in_path - searches PATH for executable
 * @cmd: command name
 *
 * Return: full path if found (must be freed), NULL otherwise
 */
char *find_in_path(char *cmd)
{
    char *path_env, *path, *dir;
    char fullpath[1024];

    if (strchr(cmd, '/'))
    {
        if (access(cmd, X_OK) == 0)
            return strdup(cmd);
        return NULL;
    }

    path_env = getenv("PATH");
    if (!path_env)
        return NULL;

    path = strdup(path_env);
    dir = strtok(path, ":");

    while (dir)
    {
        snprintf(fullpath, sizeof(fullpath), "%s/%s", dir, cmd);
        if (access(fullpath, X_OK) == 0)
        {
            free(path);
            return strdup(fullpath);
        }
        dir = strtok(NULL, ":");
    }
    free(path);
    return NULL;
}

/**
 * launch - launches non-builtin command
 * @args: command and arguments
 *
 * Return: exit status
 */
int launch(char **args)
{
    pid_t pid;
    int status;
    char *cmd_path = find_in_path(args[0]);

    if (!cmd_path)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return 127;
    }

    pid = fork();
    if (pid == 0)
    {
        execve(cmd_path, args, environ);
        perror("./hsh");
        exit(127);
    }
    else if (pid < 0)
    {
        perror("fork");
        free(cmd_path);
        return 1;
    }
    else
    {
        do
        {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    free(cmd_path);
    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}
