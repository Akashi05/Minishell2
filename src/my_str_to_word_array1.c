/*
** EPITECH PROJECT, 2024
** setting up
** File description:
** splits string into words
*/

#include "my.h"

int countc(char const *str)
{
    int i = 0;
    int j = 0;

    if (str == NULL)
        return i;
    while (str[j] != '\0') {
        if (verify(str[j]) != 0) {
            i++;
        }
        j++;
    }
    return i + 1;
}

int space(int k, char const *str)
{
    while (verify(str[k + 1]) == 0) {
        k++;
    }
    return k;
}

static char **mall(char **dest, char const *str)
{
    int j = 0;
    int i = 0;

    j = countr(str);
    i = countc(str);
    dest = malloc(sizeof(char *) * (j + 1));
    for (int k = 0; k < j; k++)
    dest[k] = malloc(sizeof(char) * (i + 1));
    return dest;
}

char *cut(char *src)
{
    char *str = NULL;
    int i = 0;

    for (i = my_strlen(src) - 1; verify(src[i]) == 0; i--);
    str = my_strdup(src);
    str[i + 1] = '\0';
    return str;
}

char **my_str_to_word_array1(char *src)
{
    int a = 0;
    int b = 0;
    char **dest = mall(dest, src);
    char *str = cut(src);

    while (verify(str[0]) == 0)
        str++;
    for (int k = 0; k < my_strlen(str); k++)
        if (verify(str[k]) != 0) {
            dest[a][b] = str[k];
            b++;
        } else {
            dest[a][b] = '\0';
            k = space(k, str);
            a++;
            b = 0;
        }
    dest[a][b] = '\0';
    dest[a + 1] = NULL;
    return dest;
}
