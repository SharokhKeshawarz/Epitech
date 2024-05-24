/*
** EPITECH PROJECT, 2023
** my_compute_factorial_rec()
** File description:
** Calculates the factorial
*/

int my_compute_factorial_rec(int nb)
{
    if (nb == 0)
        return 1;
    else if (nb < 0 || nb > 12)
        return 0;
    else
        return nb * my_compute_factorial_rec(nb - 1);
}
