#include "hsh.h"

void execute_command(char *cmd, char **av)
{
    pid_t pid;
    char *args[2];

    args[0] = cmd;
    args[1] = NULL;

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
}
