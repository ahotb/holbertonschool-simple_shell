#ifndef HSH_H
#define HSH_H
#define MAX_TOKENS 64

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
int handle_builtin(char **args, char *prog_name, int last_status);
int execute_command(char **args, char **av);
void free_tokens(char **tokens);
char *trim_spaces(char *str);
ssize_t _getline(char **lineptr);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strdup(char *s);
int _has_char(char *s, char c);

#endif /* HSH_H */
