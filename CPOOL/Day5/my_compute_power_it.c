/*
** EPITECH PROJECT, 2023
** my_compute_power_it()
** File description:
** Calculates the power of nb by p
*/

int my_compute_power_it(int nb, int p)
{
    int result = 1;

    if (p < 0)
        return 0;
    for (int i = 0; i < p; i++)
        result *= nb;
    return result;
}
