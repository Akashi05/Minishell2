/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** take the command
*/

#include "my.h"

char *get_cmd(int status)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t size;

    size = getline(&line, &len, stdin);
    if (size == -1) {
    exit(status);
    }
    line[size - 1] = '\0';
    if (my_strcmp(line, "exit") == 0) {
    mini_printf("exit\n");
    exit(status);
    }
    return line;
}
