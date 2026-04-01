/*
** EPITECH PROJECT, 2024
** minishell 2
** File description:
** redirection
*/

#include "my.h"

int cut_redi(char *line, int fd, char **tab)
{
    int sup = 0;

    for (int i = 0; line[i] != '\0'; i++)
        if (line[i] == '>')
        sup++;
    if (sup == 1)
        fd = open(tab[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (sup == 2)
        fd = open(tab[1], O_RDWR | O_CREAT | O_APPEND, 0644);
    return fd;
}

char **redi_supp(char *line, char **cmd_line, char **env, char **copyEnv)
{
    char **tab = my_str_to_word_array3(find_file(line, '>'));
    int fd = 0;
    int d = dup(STDOUT_FILENO);

    fd = cut_redi(line, fd, tab);
    if (fd == -1)
        perror("open");
    if (dup2(fd, 1) == -1) {
        perror("dup2");
        close(fd);
    }
    cmd_line = my_str_to_word_array1(tab[0]);
    copyEnv = executor(copyEnv, cmd_line, env);
    dup2(d, STDOUT_FILENO);
    close(fd);
    close(d);
    return copyEnv;
}

char **redi_inf1(char *line, char **cmd_line, char **env, char **copyEnv)
{
    char **tab = my_str_to_word_array4(find_file(line, '<'));
    int fd = 0;
    int d = dup(STDIN_FILENO);

    fd = open(tab[1], O_RDWR);
    if (fd == -1)
        perror("open");
    if (dup2(fd, 0) == -1) {
        perror("dup2");
        close(fd);
    }
    cmd_line = my_str_to_word_array1(tab[0]);
    copyEnv = executor(copyEnv, cmd_line, env);
    dup2(d, STDIN_FILENO);
    close(fd);
    close(d);
    return copyEnv;
}

char *get_input(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t size;

    size = getline(&line, &len, stdin);
    if (size == -1) {
    exit(0);
    }
    line[size - 1] = '\0';
    return line;
}

char **redi_inf2(char *line, char **cmd_line, char **env, char **copyEnv)
{
    char *str = NULL;
    char **split = my_str_to_word_array4(find_file(line, '<'));

    while (1) {
        mini_printf("> ");
        str = get_input();
        if (my_strcmp(str, split[1]) == 0)
            break;
    }
    copyEnv = mini_main(copyEnv, env, cmd_line, split[0]);
    return copyEnv;
}
