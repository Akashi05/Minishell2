/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** search and return
*/

#include "my.h"

char **spliting(char **env, char *sch)
{
    int i = 0;
    char **split = NULL;

    if (env == NULL || sch == NULL)
        return NULL;
    for (i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], sch, my_strlen(sch)) == 0)
            break;
    }
    split = my_str_to_word_array1(env[i]);
    for (i = 0; i <= my_strlen(sch); i++)
    split[0]++;
    return split;
}
