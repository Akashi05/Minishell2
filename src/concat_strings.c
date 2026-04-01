/*
** EPITECH PROJECT, 2024
** phoenix day03
** File description:
** concat two strings
*/

#include "my.h"

char *concat_string(char *dest, char const *src)
{
    int i = 0;
    int j = 0;
    char *str = malloc(sizeof(char) * my_strlen(dest) + my_strlen(src) + 1);

    if (dest == NULL || src == NULL)
        return NULL;
    while (dest[i] != '\0') {
        str[i] = dest[i];
        i++;
    }
    while (src[j] != '\0') {
        str[i] = src[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return str;
}
