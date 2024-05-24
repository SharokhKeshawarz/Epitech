/*
** EPITECH PROJECT, 2023
** do-op()
** File description:
** Makes Operation
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
