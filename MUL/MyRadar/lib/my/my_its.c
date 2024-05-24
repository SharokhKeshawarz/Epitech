/*
** EPITECH PROJECT, 2023
** my_its.c
** File description:
** my_its
*/

#include "../../include/my.h"

void its(int number, char *result)
{
    int temp = number;
    int length = 0;

    while (temp != 0) {
        temp /= 10;
        length++;
    }
    if (number == 0) {
        result[0] = '0';
        result[1] = '\0';
        return;
    }
    temp = number;
    result[length] = '\0';
    while (temp != 0) {
        length--;
        result[length] = '0' + temp % 10;
        temp /= 10;
    }
}
