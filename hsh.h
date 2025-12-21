#ifndef HSH_H
#define HSH_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

/* External variable for environ */
extern char **environ;

/* Function prototypes */
void prompt_user(void);
char *read_line(void);
char **parse_line(char *line);
int execute_command(char **args, char *prog_name);
int is_builtin(char **args);
int handle_builtin(char **args, char *prog_name);
char *find_in_path(char *cmd);
void free_array(char **arr);
void print_error(char *prog_name, char *cmd);

#endif /* HSH_DIR_H */