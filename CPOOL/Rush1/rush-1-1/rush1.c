/*
** EPITECH PROJECT, 2023
** rush1.c
** File description:
** rush1-1
*/

void horizontal(int x)
{
    if (x == 1)
        my_putchar('o');
    else if (x == 2) {
        my_putchar('o');
        my_putchar('o');
    } else {
        my_putchar('o');
        for (int i = 0; i <= x - 3; i++)
            my_putchar('-');
        my_putchar('o');
    }
}

void vertical_2(int x)
{
    my_putchar('\n');
    my_putchar('|');
    for (int i = 0; i <= x - 3; i++)
        my_putchar(' ');
    my_putchar('|');
}

void vertical(int x, int y)
{
    if (y > 2 && x > 1)
        for (int i = 0; i <= y - 3; i++)
            vertical_2(x);
    else {
        for (int i = 0; i <= y - 3; i++) {
            my_putchar('\n');
            my_putchar('|');
        }
    }
    my_putchar('\n');
    horizontal(x);
    my_putchar('\n');
}

void output(char *str)
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
        horizontal(x);
    else
        output("Invalid size\n");
}
