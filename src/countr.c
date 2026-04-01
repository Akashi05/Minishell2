/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** count necessary row
*/

#include "my.h"

int countr(const char *str)
{
    int j = 0;

    if (str == NULL)
        return j;
    for (int i = 0; i < my_strlen(str); i++)
        if (verify(str[i]) == 0) {
        i++;
        } else {
            j++;
            i++;
        }
    return j + 1;
}
