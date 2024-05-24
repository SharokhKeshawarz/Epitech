/*
** EPITECH PROJECT, 2023
** top()
** File description:
** For all the top() code
*/

void increment_l_top(int *l, unsigned int n)
{
    while (*l < n * 2) {
        my_putchar(' ');
        *l = *l + 1;
    }
}

void increment_j_top(int *j, unsigned int n, int i)
{
    while (*j <= n - i) {
        my_putchar(' ');
        *j = *j + 1;
    }
}

void increment_k_top(int *k, int i)
{
    while (*k <= 2 * i - 1) {
        if (*k == 2 * i - 1 || *k == 1)
            my_putchar('*');
        else
            my_putchar(' ');
        *k = *k + 1;
    }
}
