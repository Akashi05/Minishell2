/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** part of main
*/

#include "my.h"

char **cut_mini(char **tab, char **cmd_line, char **copyEnv, char **env)
{
    for (int i = 0; tab[i] != NULL; i++) {
        if (verif_redi1(tab[i]) == 0)
            copyEnv = redi_supp(tab[i], cmd_line, env, copyEnv);
        if (verif_redi2(tab[i]) == 0)
            copyEnv = redi_inf1(tab[i], cmd_line, env, copyEnv);
        if (verif_redi1(tab[i]) != 0 && verif_redi2(tab[i]) != 0) {
            cmd_line = my_str_to_word_array1(tab[i]);
            copyEnv = executor(copyEnv, cmd_line, env);
        }
    }
    return copyEnv;
}

char **mini_main(char **copyEnv, char **env, char **cmd_line, char *line)
{
    int vef = 0;
    char **tab = NULL;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == ';')
            vef++;
    if (vef == 0) {
        if (verif_redi1(line) == 0)
            copyEnv = redi_supp(line, cmd_line, env, copyEnv);
        if (verif_redi2(line) == 0)
            copyEnv = redi_inf1(line, cmd_line, env, copyEnv);
        if (verif_redi1(line) != 0 && verif_redi2(line) != 0) {
            cmd_line = my_str_to_word_array1(line);
            copyEnv = executor(copyEnv, cmd_line, env);
        }
    } else {
        tab = my_str_to_word_array2(line);
        copyEnv = cut_mini(tab, cmd_line, copyEnv, env);
    }
    return copyEnv;
}
