#include "hsh.h"

void trim_command(char *cmd)
{
size_t len;

if (!cmd)
return;

while (*cmd == ' ' || *cmd == '\t')
cmd++;

len = strlen(cmd);
while (len > 0 && (cmd[len - 1] == ' ' || cmd[len - 1] == '\t'))
{
cmd[len - 1] = '\0';
len--;
}
}

void free_resources(char *line)
{
free(line);
}
