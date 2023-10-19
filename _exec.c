#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void _exec(char *cmd, char **argv, char **env)
{
	execve(cmd, argv, env);
	perror("execve");
	exit(1);
}
