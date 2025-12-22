#ifndef BUILTINS_H
#define BUILTINS_H

int is_builtin(char **args);
int run_builtin(char **args);
int launch(char **args);
char *find_in_path(char *cmd);

#endif /* BUILTINS_H */
