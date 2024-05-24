/*
** EPITECH PROJECT, 2023
** MY_STR_ISALPHA
** File description:
** my_str_isalpha.c
*/

#include <stdio.h>
#include <string.h>

int my_str_isalpha(char const *str)
{
    int a = 0;
    int check = 0;

    if (!str)
        return 1;
    for (int i = 0; str[i] != '\0'; i++){
        check++;
        if ((str[i] >= 'a' && str[i] <= 'z') ||
        (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_' ||
        (str[i] <= '9' && str[i] >= '0')){
            a++;
        }
    }
    if (a == check)
        return 1;
    else
        return 0;
}
