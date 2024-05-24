/*
** EPITECH PROJECT, 2023
** MY_STR_ISLOWER
** File description:
** my_str_islower.c
*/

#include <stdio.h>
#include <string.h>

int my_str_islower(char const *str)
{
    int i = 0;
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++){
        check++;
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
    }
    if (check == i)
        return 1;
    else
        return 0;
}
