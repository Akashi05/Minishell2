/*
** EPITECH PROJECT, 2024
** phoenix day02
** File description:
** reproduce strncmp
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    if (s1 == NULL || s2 == NULL)
        return i;
    while (i < n) {
        if (s1[i] > s2[i])
            return 1;
        if (s1[i] < s2[i])
            return -1;
        i++;
    }
        return 0;
}
