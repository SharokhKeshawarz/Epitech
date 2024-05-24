/*
** EPITECH PROJECT, 2023
** mini_printf
** File description:
** main.c
*/

#include <stdio.h>
#include <stdarg.h>
#include "../include/my.h"

void mini_next(const char *format, va_list parametersInfos,
    char actual_char, int i)
{
    switch (format[i + 1]) {
    case 'd':
        my_put_nbr(va_arg(parametersInfos, int));
        break;
    case 'i':
        my_put_nbr(va_arg(parametersInfos, int));
        break;
    case 's':
        my_putstr(va_arg(parametersInfos, char *));
        break;
    case 'c':
        my_putchart(va_arg(parametersInfos, char *));
        break;
    case '%':
        my_putchar('%');
        break;
    }
}

int my_printf(const char *format, ...)
{
    va_list parametersInfos;
    char actual_char;
    int i = 0;

    va_start(parametersInfos, format);
    while (format[i] != '\0'){
        actual_char = format[i];
        if (actual_char != '%'){
            my_putchar(actual_char);
        } else {
            mini_next(format, parametersInfos, actual_char, i);
            i += 1;
        }
        i += 1;
    }
    va_end(parametersInfos);
    return 0;
}
