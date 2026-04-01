/*
** EPITECH PROJECT, 2024
** phoenix day02
** File description:
** copies a string into another.
*/

#include "my.h"

int inf_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '<' && str[i + 1] == '<')
            return 0;
    return 1;
}

char *my_strcpy_m(char *dest, char *src, char c)
{
    int i = 0;
    int j = 0;

    dest = malloc(sizeof(char) * my_strlen(src));
    while (src[i] != '\0') {
        if (src[i] == c && src[i - 1] == c) {
            i++;
        } else {
            dest[j] = src[i];
            j++;
            i++;
        }
    }
    dest[j] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char *src, int idx)
{
    int i = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) - idx));
    while (src[idx] != '\0') {
        dest[i] = src[idx];
        i++;
        idx++;
    }
    dest[i] = '\0';
    return dest;
}

char *find_file(char *line, char c)
{
    int j = 0;
    char *file;

    file = my_strcpy_m(file, line, c);
    return file;
}
