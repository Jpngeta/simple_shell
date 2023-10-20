#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void _exec(char *cmd, char **argv, char **env);
void exect_cmd(char **parsed_argv);
void parse_cmd(char *cmd, char ***parsed_argv);
void populate_environment(char ***env);
extern char **environ;

#endif /* SHELL_H */
