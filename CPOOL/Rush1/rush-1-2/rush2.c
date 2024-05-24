/*
** EPITECH PROJECT, 2023
** rush2.c
** File description:
** rush1-2
*/

static void horizontal_inverse(int x)
{
    if (x == 1)
        my_putchar('*');
    else if (x == 2){
        my_putchar(92);
        my_putchar('/');
    } else {
        my_putchar(92);
        for (int i = 0; i <= x - 3; i++)
            my_putchar('*');
        my_putchar('/');
    }
}

static void horizontal_blank(int x)
{
    for (int i = 1; i <= x; i++)
        my_putchar('*');
}

void horizontal(int x)
{
    if (x == 1)
        my_putchar('*');
    else if (x == 2) {
        my_putchar('/');
        my_putchar(92);
    } else {
        my_putchar('/');
        for (int i = 1; i <= x - 2; i++)
            my_putchar('*');
        my_putchar(92);
    }
}

static void vertical_2(int x)
{
    my_putchar('\n');
    my_putchar('*');
    for (int i = 0; i <= x - 3; i++)
        my_putchar(' ');
    my_putchar('*');
}

void vertical(int x, int y)
{
    if (y > 2 && x > 1){
        for (int i = 0; i <= y - 3; i++)
            vertical_2(x);
    } else {
        for (int i = 0; i <= y - 3; i++) {
            my_putchar('\n');
            my_putchar('*');
        }
    }
    my_putchar('\n');
    horizontal_inverse(x);
    my_putchar('\n');
}

static void output(char *str)
{
    int i = 0;

    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
}

void rush(int x, int y)
{
    if (x > 2147483647 || x < -2147483648) {
        output("Invalid Size\n");
        return;
    }
    if (y > 2147483647 || y < -2147483648) {
        output("Invalid Size\n");
        return;
    }
    if (x > 0 && y > 1) {
        horizontal(x);
        vertical(x, y);
    } else if (x > 0 && y == 1)
        horizontal_blank(x);
    else
        output("Invalid size\n");
}
