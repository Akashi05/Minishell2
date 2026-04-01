/*
** EPITECH PROJECT, 2024
** minishell2
** File description:
** str to word array
*/

#include "my.h"

static int countc2(char const *str)
{
    int i = 0;
    int j = 0;

    if (str == NULL)
        return i;
    while (str[j] != '\0') {
        if (str[j] != ';') {
            i++;
        }
        j++;
    }
    return i + 1;
}

int countr2(const char *str)
{
    int j = 0;

    if (str == NULL)
        return j;
    for (int i = 0; i < my_strlen(str); i++)
        if (str[i] == ';') {
        i++;
        } else {
            j++;
            i++;
        }
    return j + 1;
}

int space2(int k, char const *str)
{
    while (verify(str[k + 1]) == 0) {
        k++;
    }
    return k;
}

static char **mall2(char **dest, char const *str)
{
    int j = 0;
    int i = 0;

    j = countr2(str);
    i = countc2(str);
    dest = malloc(sizeof(char *) * (j + 1));
    for (int k = 0; k < j; k++)
    dest[k] = malloc(sizeof(char) * (i + 1));
    return dest;
}

char *cut2(char *src)
{
    char *str = NULL;
    int i = 0;

    for (i = my_strlen(src) - 1; verify(src[i]) == 0; i--);
    str = my_strdup(src);
    str[i + 1] = '\0';
    return str;
}

char **my_str_to_word_array2(char *src)
{
    int a = 0;
    int b = 0;
    char **dest = mall2(dest, src);
    char *str = cut2(src);

    while (verify(str[0]) == 0)
        str++;
    for (int k = 0; k < my_strlen(str); k++)
        if (str[k] != ';') {
            dest[a][b] = str[k];
            b++;
        } else {
            dest[a][b] = '\0';
            k = space2(k, str);
            a++;
            b = 0;
        }
    dest[a][b] = '\0';
    dest[a + 1] = NULL;
    return dest;
}
