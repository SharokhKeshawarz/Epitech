/*
** EPITECH PROJECT, 2023
** star()
** File description:
** Can make a star with different size
*/

void top(unsigned int n)
{
    int i = 1;
    int j = 1;
    int k = 1;
    int l = 0;

    while (i <= n) {
        if (n == 1)
            my_putchar(' ');
        increment_l_top(&l, n);
        increment_j_top(&j, n, i);
        increment_k_top(&k, i);
        my_putchar('\n');
        j = 1;
        k = 1;
        l = 0;
        i++;
    }
}

void line(unsigned int n)
{
    int l_space = 2 * n - 3;
    int l_star = n * 2 + 1;
    int i = 0;
    int j = 0;
    int k = 0;

    if (n == 1) {
        l_space = 1;
        l_star = 3;
    }
    increment_i_line(&i, l_star);
    increment_j_line(&j, l_space);
    increment_k_line(&k, l_star);
    my_putchar('\n');
}

void left_right(unsigned int n)
{
    int size = (2 * n - 3) + (2 * (n * 2));
    int max = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;

    if (n == 1)
        size = 8;
    while (i < n) {
        draw_left(&max, &i, &j, n);
    }
    while (k < n - 1) {
        draw_right(&max, &k, &l, n);
    }
}

void bottom(unsigned int n)
{
    int i = n;
    int j = 1;
    int k = 1;
    int l = 0;
    int m = 1;

    while (i >= 1) {
        if (n == 1)
            my_putchar(' ');
        increment_l_bottom(&l, n);
        increment_j_bottom(&j, m);
        increment_k_bottom(&k, i);
        my_putchar('\n');
        j = 1;
        k = 1;
        l = 0;
        m++;
        i--;
    }
}

void star(unsigned int size)
{
    if (size >= 1) {
        top(size);
        line(size);
        left_right(size);
        line(size);
        bottom(size);
    } else
        write(1, "", 0);
}
