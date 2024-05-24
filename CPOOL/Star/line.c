/*
** EPITECH PROJECT, 2023
** line()
** File description:
** For all the line() code
*/

void increment_i_line(int *i, int l_star)
{
    while (*i < l_star) {
        my_putchar('*');
        *i = *i + 1;
    }
}

void increment_j_line(int *j, int l_space)
{
    while (*j < l_space) {
        my_putchar(' ');
        *j = *j + 1;
    }
}

void increment_k_line(int *k, int l_star)
{
    while (*k < l_star) {
        my_putchar('*');
        *k = *k + 1;
    }
}
