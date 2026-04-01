/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** pipe
*/

#include "my.h"

char **fils1(int *fd, char **copyEnv, char **dest1, char **env)
{
    pid_t pid1;

    pid1 = fork();
    if (pid1 == -1)
        exit(84);
    if (pid1 == 0) {
        close(fd[0]);
        if (dup2(fd[1], STDOUT_FILENO) == -1)
            exit(84);
        close(fd[1]);
        copyEnv = executor(copyEnv, dest1, env);
        exit(0);
    }
    return copyEnv;
}

char **fils2(int *fd, char **copyEnv, char **dest2, char **env)
{
    close(fd[1]);
    if (dup2(fd[0], STDIN_FILENO) == -1)
        exit(84);
    close(fd[0]);
    copyEnv = executor(copyEnv, dest2, env);
    return copyEnv;
}

char **simple_pipe(char *str, char **copyEnv, char **env, int status)
{
    char **dest = my_str_to_word_array5(str);
    char **dest1 = my_str_to_word_array1(dest[0]);
    char **dest2 = my_str_to_word_array1(dest[1]);
    int fd[2];
    pid_t pid2;

    if (pipe(fd) == -1)
        exit(84);
    copyEnv = fils1(fd, copyEnv, dest1, env);
    pid2 = fork();
    if (pid2 == -1)
        exit(84);
    if (pid2 == 0) {
        copyEnv = fils2(fd, copyEnv, dest2, env);
        exit(0);
    }
    close(fd[1]);
    waitpid(pid2, &status, 0);
    return copyEnv;
}
