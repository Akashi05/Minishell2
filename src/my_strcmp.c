/*
** EPITECH PROJECT, 2024
** my radar
** File description:
** compare two strings
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int y = 0;
    int z = 0;

    if (s1 == NULL || s2 == NULL)
        return i;
    while (s1[i] != '\0') {
        if (s1[i] == s2[z])
            z++;
        i++;
    }
    if (i == z) {
        return 0;
    } else {
        return 1;
    }
}
