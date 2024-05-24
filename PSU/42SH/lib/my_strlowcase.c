/*
** EPITECH PROJECT, 2023
** MY_STRLOWCASE
** File description:
** my_strlowcase.c
*/

#include <stdio.h>
#include <string.h>

char *my_strlowcase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = str[i] + 32;
        }
    }
    return str;
}
