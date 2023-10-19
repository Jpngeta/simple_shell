#include "shell.h"
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    char *cmd = NULL;
    char *cmd_cpy = NULL;
    pid_t cpid;
    char *token = NULL;
    char *delim = " \n";
    size_t n = 0;
    int i = 0;
    int stat;
    int argc = 0;
    char **parsed_argv = NULL;
    char *usr_prompt = "#cisfun$ ";
    bool tpipe = false;

    while (1 && !tpipe)
    {
        write(STDOUT_FILENO, usr_prompt, strlen(usr_prompt));

        if (isatty(STDIN_FILENO) == 0)
            tpipe = true;

        if (getline(&cmd, &n, stdin) == -1)
            return -1;

        cmd_cpy = strdup(cmd);

        argc = 0; 

        token = strtok(cmd, delim);

        while (token)
        {
            token = strtok(NULL, delim);
            argc++;
        }

        parsed_argv = malloc(sizeof(char *) * (argc + 1));

        token = strtok(cmd_cpy, delim);

        i = 0;

        while (token)
        {
            parsed_argv[i] = token;
            token = strtok(NULL, delim);
            i++;
        }
        parsed_argv[i] = NULL;


        if (parsed_argv[0] && !strcmp(parsed_argv[0], "exit"))
        {
            break;
        }

        cpid = fork();
        if (cpid == -1) {
            perror("Error: fork");
            return (1);
        }

        if (cpid == 0) {
            _exec(parsed_argv[0], parsed_argv, environ); 
        } else {
            wait(&stat);
        }

        i = 0;

        free(cmd), free(cmd_cpy);
        free(parsed_argv); 
    }

    return 0;
}

