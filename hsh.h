#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

void shell_loop(char **av);
void execute_command(char *line, char **av);
char **tokenize(char *line);

#endif
