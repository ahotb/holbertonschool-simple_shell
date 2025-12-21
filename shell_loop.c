#include "hsh.h"

void shell_loop(char **av)
{
    char *line = NULL, *cmd;
    size_t len = 0;
    ssize_t nread;
 size_t cmd_len;

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

        cmd = line;
        while (*cmd == ' ' || *cmd == '\t')
            cmd++;

        cmd_len = strlen(cmd);
        while (cmd_len > 0 && (cmd[cmd_len - 1] == ' ' || cmd[cmd_len - 1] == '\t'))
        {
            cmd[cmd_len - 1] = '\0';
            cmd_len--;
        }

        if (cmd_len == 0)
        {
            free(line);
            line = NULL;
            len = 0;
            continue;
        }

        execute_command(cmd, av);

        free(line);
        line = NULL;
        len = 0;
    }

    free(line);
}
