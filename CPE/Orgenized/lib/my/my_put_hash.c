/*
** EPITECH PROJECT, 2023
** my_put_hash.c
** File description:
** my_put_hash
*/

#include <stdarg.h>

static void octal_hash(int *counter, va_list ap, int *pass)
{
    *counter += my_putchar('0');
    *counter += my_put_octal(va_arg(ap, int));
}

static void hex_hash(char const *format, int i, int *counter, va_list ap)
{
    *counter += my_putchar('0');
    *counter += my_putchar('x');
    *counter += my_put_hex(va_arg(ap, int), format[i + 1]);
}

int my_put_hash(char const *format, int i, va_list ap, int *pass)
{
    int counter = 0;

    if (format[i] == '#') {
        switch (format[i + 1]) {
            case 'o':
                octal_hash(&counter, ap, *(&pass));
                *pass += 3;
                break;
            case 'x':
            case 'X':
                hex_hash(format, i, &counter, ap);
                *pass += 2;
                break;
            default:
                counter += my_putchar(format[i]);
                break;
        }
    }
    return counter;
}
