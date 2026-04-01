/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** add in env
*/

#include "my.h"

char **env_copy(char **env)
{
    char **dest;
    int i = 0;

    for (i = 0; env[i] != NULL; i++);
    dest = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; env[j] != NULL; j++)
    dest[j] = my_strdup(env[j]);
    return dest;
}

char **add_to_env(char **copyEnv, char *name)
{
    int i = 0;
    int j = 0;
    char **newest = NULL;

    for (i = 0; copyEnv[i] != NULL; i++);
    newest = malloc(sizeof(char *) * (i + 2));
    for (j = 0; copyEnv[j] != NULL; j++)
    newest[j] = my_strdup(copyEnv[j]);
    newest[j] = my_strdup(name);
    newest[j + 1] = NULL;
    return newest;
}

void **my_env(char **copyEnv)
{
    for (int i = 0; copyEnv[i] != NULL; i++)
        mini_printf("%s\n", copyEnv[i]);
}

int cut_unsetenv(char **copyEnv, char **cmd_line, char **newer, int *tab)
{
    for (int j = 0; copyEnv[j] != NULL; j++)
        if (my_strncmp(cmd_line[tab[1]], copyEnv[j],
        my_strlen(cmd_line[tab[1]])) != 0) {
            newer[tab[0]] = my_strdup(copyEnv[j]);
            tab[0]++;
        }
    return tab[0];
}

char **my_unsetenv(char **copyEnv, char **cmd_line)
{
    char **newer = NULL;
    int j = 0;
    int tab[2] = {0, 0};

    if (cmd_line[1] == NULL) {
        mini_printf("unsetenv: Too few arguments.\n");
        return copyEnv;
    }
    for (j = 0; cmd_line[j] != NULL; j++);
    for (tab[1] = 0; copyEnv[tab[1]] != NULL; tab[1]++);
    newer = malloc(sizeof(char *) * tab[1]);
    for (tab[1] = 1; cmd_line[tab[1]] != NULL; tab[1]++) {
        tab[0] = cut_unsetenv(copyEnv, cmd_line, newer, tab);
        newer[tab[0]] = NULL;
        copyEnv = newer;
        tab[0] = 0;
    }
    return newer;
}
