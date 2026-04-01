/*
** EPITECH PROJECT, 2024
** minishell1
** File description:
** library
*/

    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdarg.h>
    #include <stdbool.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <sys/stat.h>

#ifndef _MY_H
    #define _MY_H

char *concat_string(char *dest, char const *src);
char **get_cmd(const int statu);
int mini_printf(const char *format, ...);
char **my_str_to_word_array(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int process(char *cmd, char **cmd_line, char **env, const int statu);
int my_strncmp(char const *s1, char const *s2, int n);
char *pathing(char *cmd, char **cmd_line, char **env, int status);
int verify(char c);
int countr(const char *str);
char *my_strdup(char const *src);
char **spliting(char **env, char *sch);
int cd_command(char **cmd_line, char **env);
void **my_env(char **copyEnv);
char **my_setenv1(char **copyEnv, char **cmd_line, int j);
char **my_unsetenv(char **copyEnv, char **cmd_line);
char **main_setenv(char **copyEnv, char **cmd_line);
char **add_to_env(char **copyEnv, char *name);

typedef struct var {
    int j;
    int idx;
    int compt;

} var_t;

#endif
