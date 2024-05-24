/*
** EPITECH PROJECT, 2023
** my_print_comb2()
** File description:
** Printing combitation of 4 digits
*/

static void display_comb(int number)
{
    char first = (number / 10) + 48;
    char seconde = (number % 10) + 48;

    my_putchar(first);
    my_putchar(seconde);
}

static void display_comma_space(int first_pair, int seconde_pair)
{
    if (first_pair != 98 || seconde_pair != 99) {
        my_putchar(',');
        my_putchar(' ');
    }
}

int my_print_comb2(void)
{
    int first_pair = 0;
    int seconde_pair = 0;

    while (first_pair < 99) {
        seconde_pair = first_pair + 1;
        while (seconde_pair < 100) {
            display_comb(first_pair);
            my_putchar(' ');
            display_comb(seconde_pair);
            display_comma_space(first_pair, seconde_pair);
            seconde_pair++;
        }
        first_pair++;
    }
    return 0;
}
