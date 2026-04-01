/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** the process
*/

#include "my.h"

int statu_state(int statu)
{
    if (WIFEXITED(statu) == true) {
        statu = WEXITSTATUS(statu);
    }
    if (WIFSIGNALED(statu) == true) {
        if (WCOREDUMP(statu) == true)
        mini_printf(" (core dumped)");
        mini_printf("%s\n", strsignal(WTERMSIG(statu)));
    }
    if (WIFSTOPPED(statu) == true)
        statu = WSTOPSIG(statu);
    return statu;
}

int process(char *cmd, char **cmd_line, char **env, int status)
{
    int pid = 0;
    int statu = 0;

    if (cmd == NULL || cmd_line == NULL || env == NULL)
        return statu;
    pid = fork();
    if (pid == 0) {
    execve(cmd, cmd_line, env);
    exit(0);
    } else {
        waitpid(pid, &statu, WUNTRACED);
        status = statu_state(statu);
    }
    return status;
}
