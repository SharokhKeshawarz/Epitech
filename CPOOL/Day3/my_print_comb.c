/*
** EPITECH PROJECT, 2023
** my_print_comb()
** File description:
** Printing combination of 3 digit cumber
*/

static void display_comb(int first, int seconde, int third)
{
    if (first == 55 && seconde == 56 && third == 57) {
        my_putchar(first);
        my_putchar(seconde);
        my_putchar(third);
    } else {
        my_putchar(first);
        my_putchar(seconde);
        my_putchar(third);
        my_putchar(',');
        my_putchar(' ');
    }
}

static void third_loop(int first, int seconde, int third)
{
    for (third = seconde + 1; third <= 57; third++)
        display_comb(first, seconde, third);
}

int my_print_comb(void)
{
    int first;
    int seconde;
    int third;

    for (first = 48; first <= 55; first++) {
        for (seconde = first + 1; seconde <= 56; seconde++) {
            third_loop(first, seconde, third);
        }
    }
    my_putchar('\n');
    return 0;
}
