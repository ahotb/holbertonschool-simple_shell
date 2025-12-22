#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

extern char **environ;

/* Function prototypes */
void shell_loop(char **av);
char **tokenize(char *line);
char *find_in_path(char *cmd);
int is_builtin(char **args);
int handle_builtin(char **args, char *prog_name);
int execute_command(char **args, char **av);
void free_tokens(char **tokens);
char *trim_spaces(char *str);

#endif /* HSH_H */
