#include "shell.h"

int main(int ac, char **av, char **env)
{
    
    char *buffer;
    size_t buf_size = 0;
    char *cmd;
    char **args;
    pid_t pid;
    int status, n_char;

    (void)ac;
    (void)av;
    while (1)
    {
        write(1, "$ ", 2);
        n_char = getline(&buffer, &buf_size, stdin);
        if (n_char == -1)
        {
            write(1, "\n", 1);
            exit(1);
        }
        args = split_string(buffer, " \t\n");
        if (strcmp(args[0], "exit") == 0)
            exit(0);
        pid = fork();
        if (pid == 0)
        {
            cmd = get_cmd(args[0]);
            if (cmd)
                execve(cmd, args, env);
            else
                printf("Command not found\n");
            exit(0);
        }
        else
            wait(&status);
    }
    return (0);
}
