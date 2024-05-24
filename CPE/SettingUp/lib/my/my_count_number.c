/*
** EPITECH PROJECT, 2023
** my_count_number.c
** File description:
** my_count_number
*/

int count_numbers(int nb)
{
    int i = 0;

    while (nb != 0) {
        nb /= 10;
        i++;
    }
    return i;
}
