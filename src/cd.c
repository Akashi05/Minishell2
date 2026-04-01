/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** command c
*/

#include "my.h"
char *recent;

int error_cd(char **cmd_line, int error)
{
    struct stat sb;

    stat(cmd_line[1], &sb);
    if (error == -1) {
        if (S_ISREG(sb.st_mode)) {
            mini_printf("%s: Not a directory.\n", cmd_line[1]);
        } else {
            mini_printf("%s: No such file or directory.\n", cmd_line[1]);
        }
    }
}

int cd_command(char **cmd_line, char **env)
{
    char *temp = NULL;
    int error = 0;
    char **home = spliting(env, "HOME");

    if (cmd_line[1] == NULL || my_strcmp(cmd_line[1], "~") == 0) {
        recent = getcwd(NULL, 0);
        chdir(home[0]);
    } else if (my_strcmp(cmd_line[1], "-") == 0) {
        temp = recent;
        recent = getcwd(NULL, 0);
        chdir(temp);
    } else {
        recent = getcwd(NULL, 0);
        error = chdir(cmd_line[1]);
        error_cd(cmd_line, error);
    }
}
