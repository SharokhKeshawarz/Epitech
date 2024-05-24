/*
** EPITECH PROJECT, 2023
** MY_STR_ISUPPER
** File description:
** my_str_isupper.c
*/

#include <stdio.h>
#include <string.h>

int my_str_isupper(char const *str)
{
    int i = 0;
    int check = 0;

    for (int i = 0; str[i] != '\0'; i++){
        check++;
        if (str[i] >= 'A' && str[i] <= 'Z')
            i++;
    }
    if (check == i)
        return 1;
    else
        return 0;
}
