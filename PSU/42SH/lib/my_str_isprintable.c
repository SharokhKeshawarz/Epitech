/*
** EPITECH PROJECT, 2023
** MY_STR_ISPRINTABLE
** File description:
** my_str_isprintable.c
*/

#include <stdio.h>
#include <string.h>

int my_str_isprintable(char const *str)
{
    int i = 0;
    int check = 0;

    for (; str[i] != '\0'; i++){
        check++;
        if (!((str[i] >= '0' && str[i] <= '9') ||
        (str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z') ||
        ((str[i] >= 0 && str[i] <= 31) || str[i] == 127) ||
        (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') ||
        str[i] == '\v' || str[i] == '\f' || str[i] == '\r' ||
        str[i] == ' ' || str[i] == '\t'))
            return 0;
    }
    return 1;
}
