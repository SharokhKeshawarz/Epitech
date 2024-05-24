/*
** EPITECH PROJECT, 2023
** MY_STR_ISNUM
** File description:
** my_str_isnum.c
*/

#include <stdio.h>
#include <string.h>

int my_str_isnum(char const *str)
{
    int a = 0;
    int check = 0;

    if (!str)
        return 2;
    for (int i = 0; str[i] != '\0'; i++){
        check++;
        if (str[i] >= '0' && str[i] <= '9')
            a++;
    }
    if (a == check)
        return 1;
    else
        return 0;
}
