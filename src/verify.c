/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** verify thing
*/

#include "my.h"

int verif_redi1(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '>')
            return 0;
    return 1;
}

int verif_redi2(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '<')
            return 0;
    return 1;
}

int verify(char c)
{
    if (c == '\t' || c == ' ' || c == ':')
        return 0;
    return 1;
}
