/*
** EPITECH PROJECT, 2023
** my_count_number.c
** File description:
** my_count_number
*/

int count_numbers(long nb)
{
    int i = 0;

    while (nb != 0) {
        nb /= 10;
        i++;
    }
    if (i > 1)
        return i;
    return 0;
}
