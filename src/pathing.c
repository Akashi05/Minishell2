/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** gestion of path
*/

#include "my.h"

char *pathing(char *cmd, char **cmd_line, char **env, int status)
{
    int i = 0;
    char **split = spliting(env, "PATH");
    char *temp = NULL;

    if (cmd == NULL || cmd_line == NULL || env == NULL)
        return NULL;
    temp = concat_string("/", cmd_line[0]);
    for (int i = 0; split[i] != NULL; i++) {
        cmd = concat_string(split[i], temp);
        if (access(cmd, X_OK) == 0) {
            return cmd;
        }
    }
    mini_printf("%s: Command not found.\n", cmd_line[0]);
    return NULL;
}
