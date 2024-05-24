/*
** EPITECH PROJECT, 2023
** bottom()
** File description:
** For all the bottom() code
*/

void increment_l_bottom(int *l, unsigned int n)
{
    while (*l < n * 2 - 1) {
        my_putchar(' ');
        *l = *l + 1;
    }
}

void increment_j_bottom(int *j, int m)
{
    while (*j <= m) {
        my_putchar(' ');
        *j = *j + 1;
    }
}

void increment_k_bottom(int *k, int i)
{
    while (*k <= 2 * i - 1) {
        if (*k == 2 * i - 1 || *k == 1)
            my_putchar('*');
        else
            my_putchar(' ');
        *k = *k + 1;
    }
}
