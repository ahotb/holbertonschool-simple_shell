#ifndef HSH_H
#define HSH_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

extern char **environ;


void shell_loop(char **av);
void execute_command(char *cmd, char **av);
void trim_command(char *cmd);
void free_resources(char *line);

#endif
