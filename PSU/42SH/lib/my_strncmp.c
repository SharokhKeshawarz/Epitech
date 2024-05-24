/*
** EPITECH PROJECT, 2023
** MY_STRCMP
** File description:
** my_strcmp.c
*/

#include <stdio.h>

int my_strncmp(char const *s1, char const *s2, int n)
{
    int a;
    int b;
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && n > i){
        a = s1[i];
        b = s2[i];
        if (a < b)
            return 1;
        if (a > b)
            return -1;
        i++;
    }
    if (s1[i] == '\0' && s2[i] != '\0' && n > i)
        return 1;
    else if (s2[i] == '\0' && s1[i] != '\0' && n > i)
        return -1;
    else
        return 0;
}
