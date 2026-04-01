/*
** EPITECH PROJECT, 2024
** mini printf
** File description:
** emulate one part of function printf
*/

#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
    my_putchar('-');
    nb--;
    }
    if (nb >= 10) {
    my_put_nbr(nb / 10);
    }
    my_putchar(nb % 10 + '0');
}

void my_putstr(char const *str)
{
    if (str[0] == 0)
    return;
    my_putchar(str[0]);
    my_putstr(str + 1);
}

int print(const char *format, va_list ap, int i)
{
    if (format[i] == '%' && format[i + 1] == 'd') {
        my_put_nbr(va_arg(ap, int));
    }
    if (format[i] == '%' && format[i + 1] == 'i') {
        my_put_nbr(va_arg(ap, int));
    }
    if (format[i] == '%' && format[i + 1] == 'c') {
        my_putchar(va_arg(ap, int));
    }
    if (format[i] == '%' && format[i + 1] == 's') {
        my_putstr(va_arg(ap, char *));
    }
    if (format[i] == '%' && format[i + 1] == '%') {
        my_putchar('%');
    }
}

int mini_printf(const char *format, ...)
{
    int i = 0;
    va_list ap;

    va_start(ap, format);
    while (format[i] != '\0') {
        if (format[i] != '%') {
            my_putchar(format[i]);
            i++;
        } else {
        print(format, ap, i);
        i++;
        i++;
        }
    }
    va_end(ap);
    return i;
}
