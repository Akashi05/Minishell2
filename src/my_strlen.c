/*
** EPITECH PROJECT, 2024
** Day04
** File description:
** function that count and returns number of characters
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i = 0;

    if (str == NULL)
        return i;
    while (str[i] != '\0') {
    i++;
    }
    return i;
}
