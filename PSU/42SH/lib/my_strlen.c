/*
** EPITECH PROJECT, 2023
** MY_STRLEN
** File description:
** my_strlen.c
*/

#include <stdio.h>

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return -1;
    while (str[i] != '\0'){
        i++;
    }
    return (i);
}
