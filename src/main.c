/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** the main function
*/

#include "my.h"
int status;

char *not_builtin(char *cmd, char **cmd_line, char **env, int status)
{
    if (cmd[0] != '/' && cmd[1] != '/' && my_strcmp(cmd, "cd") != 0 &&
    my_strcmp(cmd, "env") != 0 && my_strcmp(cmd, "setenv") != 0
    && my_strcmp(cmd, "unsetenv") != 0)
    if (pathing(cmd, cmd_line, env, status) == NULL) {
        return NULL;
    } else {
        cmd = pathing(cmd, cmd_line, env, status);
        return cmd;
    }
}

char **builtin(char **copyEnv, char *cmd, char **cmd_line)
{
    if (my_strcmp(cmd, "cd") == 0)
        cd_command(cmd_line, copyEnv);
    if (my_strcmp(cmd, "setenv") == 0)
        copyEnv = main_setenv(copyEnv, cmd_line);
    if (my_strcmp(cmd, "unsetenv") == 0)
        copyEnv = my_unsetenv(copyEnv, cmd_line);
    if (my_strcmp(cmd, "env") == 0)
        my_env(copyEnv);
    return copyEnv;
}

char **executor(char **copyEnv, char **cmd_line, char **env)
{
    copyEnv = builtin(copyEnv, cmd_line[0], cmd_line);
    cmd_line[0] = not_builtin(cmd_line[0], cmd_line, env, status);
    if (cmd_line[0] == NULL)
        status = 1;
    status = process(cmd_line[0], cmd_line, env, status);
    return copyEnv;
}

int verif_pipe(char *line)
{
    int temp = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '|')
            temp = 1;
    return temp;
}

int main(int ac, char **av, char **env)
{
    char **cmd_line = NULL;
    char *line = NULL;
    int vef = 0;
    char **copyEnv = env_copy(env);

    while (1) {
    if (isatty(0) == 1)
        mini_printf("b_sh <3 ");
    line = get_cmd(status);
    if (verif_pipe(line) == 1)
        copyEnv = simple_pipe(line, copyEnv, env, status);
    if (inf_number(line) == 0 && verif_pipe(line) != 1)
        copyEnv = redi_inf2(line, cmd_line, env, copyEnv);
    if (inf_number(line) != 0 && verif_pipe(line) != 1)
        copyEnv = mini_main(copyEnv, env, cmd_line, line);
    }
    free(cmd_line);
    free(copyEnv);
}
