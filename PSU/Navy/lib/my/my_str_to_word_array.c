/*
** EPITECH PROJECT, 2023
** Str_to_word_array
** File description:
** Converts a string into an array of words
*/

#include "../../include/my.h"

int lentab(char *str)
{
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if ((str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9'))
            size++;
    }
    return (size + 1);
}

int lenword(char *str, int pos_x)
{
    int size = 0;

    for (int i = pos_x; str[i] != '\0'; i++){
        if ((str[i] < 'a' || str[i] > 'z') &&
            (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' && str[i] > '9')){
            return (size);
        }
        size++;
    }
    return (size + 1);
}

int upgrade_value(int *y, int *i, int *idx)
{
    *y = *y + 1;
    *i = *i + 1;
    *idx = 0;
}

char **my_str_to_word_array(char *str)
{
    int size = lentab(str);
    char **arr = malloc(sizeof(char *) * (size + 1));
    int idx = 0;
    int y = 0;
    int i = 0;

    arr[y] = malloc((lenword(str, 0) + 1) * sizeof(char));
    for (; str[i] != '\0'; i++){
        if ((str[i] == '\n')){
            arr[y][idx] = '\0';
            upgrade_value(&y, &i, &idx);
            arr[y] = malloc((lenword(str, i + 1) + 2) * sizeof(char));
        }
        arr[y][idx] = str[i];
        idx++;
    }
    arr[y][idx] = '\0';
    arr[y + 1] = 0;
    return (arr);
}
