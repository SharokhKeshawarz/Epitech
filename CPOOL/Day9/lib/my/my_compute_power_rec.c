/*
** EPITECH PROJECT, 2023
** my_compute_power_rec()
** File description:
** Calculates the power of n by p using recursion
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    else if (p < 0)
        return 0;
    else
        return nb * my_compute_power_rec(nb, p - 1);
}
