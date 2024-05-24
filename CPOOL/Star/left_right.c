/*
** EPITECH PROJECT, 2023
** left_right()
** File description:
** For all the left_right() code
*/

void check_n(unsigned int n, int *max)
{
    if (n == 1)
        *max = 5;
}

void check_j(int j, int i, int max, int *quit)
{
    if (j == i + 1)
        my_putchar('*');
    else if (j == max) {
        my_putchar('*');
        *quit = 0;
    } else
        my_putchar(' ');
}

int check_l(int l, int n, int k, int max)
{
    int quit = 1;

    if (l == n - k - 1) {
        my_putchar('*');
    } else if (l == max) {
        my_putchar('*');
        return 0;
    } else
        my_putchar(' ');
    return 1;
}

void draw_left(int *max, int *i, int *j, unsigned int n)
{
    int size = (2 * n - 3) + (2 * (n * 2));
    int quit = 1;

    if (n == 1)
        size = 8;
    while (*j <= size || quit != 0) {
        *max = size - *i;
        check_n(n, *(&max));
        check_j(*j, *i, *max, &quit);
        *j = *j + 1;
    }
    my_putchar('\n');
    *j = 0;
    *i = *i + 1;
}

void draw_right(int *max, int *k, int *l, unsigned int n)
{
    int size = (2 * n - 3) + (2 * (n * 2));
    int quit = 1;

    while (*l <= size || quit != 0) {
        *max = (size + (*k - n)) + 2;
        if (check_l(*l, n, *k, *max) == 0)
            quit = 0;
        *l = *l + 1;
    }
    my_putchar('\n');
    *l = 0;
    *k = *k + 1;
}
