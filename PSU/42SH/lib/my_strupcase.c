/*
** EPITECH PROJECT, 2023
** MY_STRUPCASE
** File description:
** my_strupcase.c
*/

#include <stdio.h>
#include <string.h>

char *my_strupcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] = str[i] - 32;
        }
    }
    return str;
}
