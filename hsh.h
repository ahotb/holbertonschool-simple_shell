#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h> 
#include <string.h>

extern char **environ;

void shell_loop(char **av);
char **tokenize(char *line);
void execute_command(char *line, char **av);
char *trim_spaces(char *str);
void free_tokens(char **tokens);
char *find_in_path(char *cmd);

#endif
