/*
** EPITECH PROJECT, 2023
** my_compute_square_root()
** File description:
** Calculates the square root of nb
*/

int my_compute_square_root(int nb)
{
    int result = 0;

    if (nb < 0)
        return 0;
    while ((result * result) <= nb)
        result++;
    result--;
    if ((result * result) != nb)
        return 0;
    return result;
}
