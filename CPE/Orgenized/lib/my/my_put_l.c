/*
** EPITECH PROJECT, 2023
** my_put_l.c
** File description:
** my_put_l
*/

#include <stdarg.h>

static void check_nbr_lld(long long nb, long long *number, int *counter)
{
    if (nb == 0)
        *counter += my_putchar('0');
    if (nb < 0) {
        *counter += my_putchar('-');
        *number *= -1;
    }
}

static int my_put_lld(long long nb)
{
    long long number = nb;
    long long reverse = 1;
    long long digit = 0;
    int counter = 0;

    check_nbr_lld(nb, &number, &counter);
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

static void check_nbr_ld(long nb, long *number, int *counter)
{
    if (nb == 0)
        *counter += my_putchar('0');
    if (nb < 0) {
        *counter += my_putchar('-');
        *number *= -1;
    }
}

static int my_put_ld(long nb)
{
    long number = nb;
    long reverse = 1;
    long digit = 0;
    int counter = 0;

    check_nbr_ld(nb, &number, &counter);
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

static void check_l(char const *format, int i, int *counter, va_list ap)
{
    if (format[i + 2] == 'd' || format[i + 2] == 'i')
        *counter += my_put_lld(va_arg(ap, long long));
}

int my_put_l(char const *format, int i, va_list ap, int *pass)
{
    int counter = 0;

    if (format[i] == 'l') {
        switch (format[i + 1]) {
            case 'i':
            case 'd':
                counter += my_put_ld(va_arg(ap, long));
                *pass += 2;
                break;
            case 'l':
                check_l(format, i, &counter, ap);
                *pass += 3;
                break;
            default:
                counter += my_putchar(format[i]);
                break;
        }
    }
    return counter;
}
