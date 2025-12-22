#ifndef HELPERS_H
#define HELPERS_H

char *trim_spaces(char *str);
char **tokenize(char *line);
void free_tokens(char **tokens);
int handle_builtin(char **args);

#endif /* HELPERS_H */
