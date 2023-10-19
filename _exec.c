#include "shell.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * _exec - Execute a command.
 * @cmd: The command to execute.
 * @argv: An array of arguments for the command.
 * @env: The environment variables.
 */
void _exec(char *cmd, char **argv, char **env)
{
	execve(cmd, argv, env);
	perror("execve");
	exit(1);
}

