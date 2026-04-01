/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** setenv command
*/

#include "my.h"

char **error_setenv(char **cmd_line, int j)
{
    if (j > 3) {
        mini_printf("setenv: Too many arguments.\n");
        return NULL;
    }
    if (!(cmd_line[1][0] >= 'a' && cmd_line[1][0] <= 'z')
    && !(cmd_line[1][0] >= 'A' && cmd_line[1][0] <= 'Z')) {
        mini_printf("setenv: Variable name must begin with a letter.\n");
        return NULL;
    }
    for (int i = 1; cmd_line[1][i] != '\0'; i++) {
        if (!(cmd_line[1][i] >= 'a' && cmd_line[1][i] <= 'z')
        && !(cmd_line[1][i] >= 'A' && cmd_line[1][i] <= 'Z')
        && !(cmd_line[1][i] >= '0' && cmd_line[1][i] <= '9')
        && cmd_line[1][i] != '_') {
            mini_printf("setenv: Variable name must contain");
            mini_printf(" alphanumeric characters.\n");
            return NULL;
        }
    }
    return cmd_line;
}

char **over_write(char **copyEnv, char *name, int idx)
{
    int i = 0;
    int j = 0;
    char **newest = NULL;

    for (i = 0; copyEnv[i] != NULL; i++);
    newest = malloc(sizeof(char *) * i);
    for (j = 0; copyEnv[j] != NULL; j++) {
        if (j != idx) {
            newest[j] = my_strdup(copyEnv[j]);
        } else {
            newest[j] = my_strdup(name);
        }
    }
    newest[j] = NULL;
    return newest;
}

char **my_setenv1(char **copyEnv, char **cmd_line, int j)
{
    if (j == 2)
        cmd_line[1] = concat_string(cmd_line[1], "=");
    if (j == 3) {
        cmd_line[1] = concat_string(cmd_line[1], "=");
        cmd_line[1] = concat_string(cmd_line[1], cmd_line[2]);
    }
    copyEnv = add_to_env(copyEnv, cmd_line[1]);
    return copyEnv;
}

char **my_setenv2(char **copyEnv, char **cmd_line, int idx, int j)
{
    if (j == 2) {
        cmd_line[1] = concat_string(cmd_line[1], "=");
    }
    if (j == 3) {
        cmd_line[1] = concat_string(cmd_line[1], "=");
        cmd_line[1] = concat_string(cmd_line[1], cmd_line[2]);
    }
    copyEnv = over_write(copyEnv, cmd_line[1], idx);
    return copyEnv;
}

char **main_setenv(char **copyEnv, char **cmd_line)
{
    var_t *p = malloc(sizeof(var_t));

    for (p->j = 0; cmd_line[p->j] != NULL; p->j++);
    if (cmd_line[1] == NULL) {
        my_env(copyEnv);
        return copyEnv;
    }
    if (error_setenv(cmd_line, p->j) == NULL)
        return copyEnv;
    for (int i = 0; copyEnv[i] != NULL; i++)
        if (my_strncmp(cmd_line[1], copyEnv[i], my_strlen(cmd_line[1])) == 0) {
            p->idx = i;
            p->compt++;
        }
    if (p->compt == 0) {
        copyEnv = my_setenv1(copyEnv, cmd_line, p->j);
    } else {
        copyEnv = my_setenv2(copyEnv, cmd_line, p->idx, p->j);
    }
    return copyEnv;
}
