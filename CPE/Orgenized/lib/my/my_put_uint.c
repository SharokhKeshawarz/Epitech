/*
** EPITECH PROJECT, 2023
** my_put_uint.c
** File description:
** my_put_uint
*/

static int check_zero_neg(unsigned int nb, int *counter)
{
    if (nb == 0) {
        *counter += my_putchar('0');
        return 0;
    }
    if (nb > 4294967295 || nb < 0)
        return 84;
    return 1;
}

int my_put_uint(unsigned int nb)
{
    long number = nb;
    long reverse = 1;
    long digit = 0;
    int counter = 0;

    if (check_zero_neg(nb, &counter) == 84)
        return counter;
    if (check_zero_neg(nb, &counter) == 0)
        return counter;
    while (number > 0) {
        digit = number % 10;
        reverse = (reverse * 10) + digit;
        number /= 10;
    }
    while (reverse > 1) {
        digit = reverse % 10;
        counter += my_putchar(digit + 48);
        reverse /= 10;
    }
    return counter;
}
