/*
** EPITECH PROJECT, 2023
** my_compute_factorial_it()
** File description:
** Calculates the factorial of nb
*/

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb == 0)
        return 1;
    else if (nb < 0 || nb > 12)
        return 0;
    for (int i = 1; i < nb + 1; i++)
        result *= i;
    return result;
}
