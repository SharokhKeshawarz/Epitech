/*
** EPITECH PROJECT, 2023
** extract_numbers.c
** File description:
** extract_numbers
*/

#include "../../include/my.h"

int extract_numbers(const char *str, int *numbers, int max_numbers)
{
    int count = 0;
    const char *ptr = str;
    char *endptr;
    int value;

    while (*ptr != '\0') {
        value = my_strtol(ptr, &endptr);
        if (ptr != endptr) {
            numbers[count] = value;
            count++;
            ptr = endptr;
        } else
            ptr++;
        if (count >= max_numbers)
            break;
    }
    return count;
}
