/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
** 18/27
*/

#include "../../include/my.h"

static void base(char const *format, int i, va_list ap, int *counter)
{
    if (format[i] == 'x' || format[i] == 'X')
        *counter += my_put_hex(va_arg(ap, int), format[i]);
    if (format[i] == 'o')
        *counter += my_put_octal(va_arg(ap, int));
}

static void ascii(char const *format, int i, va_list ap, int *counter)
{
    if (format[i] == 'c')
        *counter += my_putchar((char)va_arg(ap, int));
    if (format[i] == 's')
        *counter += my_putstr(va_arg(ap, char *), format[i]);
}

static void integer(char const *format, int i, va_list ap, int *counter)
{
    if (format[i] == 'd' || format[i] == 'i')
        *counter += my_put_nbr(va_arg(ap, int));
    if (format[i] == 'u')
        *counter += my_put_uint(va_arg(ap, unsigned int));
}

static void floats(char const *format, int i, va_list ap, int *counter)
{
    if (format[i] == 'f' || format[i] == 'F')
        *counter += my_put_float(va_arg(ap, double), 6);
    if (format[i] == 'e' || format[i] == 'E')
        *counter += my_put_sci(va_arg(ap, double), 6, format[i]);
}

static void check_pass(int *i, int *pass)
{
    if (*pass == 0)
        (*i)++;
    else {
        (*i) += *pass;
    }
}

static int check_specifier(char const *format, int i, va_list ap, int *pass)
{
    int count = 0;

    count += my_put_plus(format, i, ap, *(&pass));
    count += my_put_hash(format, i, ap, *(&pass));
    count += my_put_l(format, i, ap, *(&pass));
    count += my_put_h_hh(format, i, ap, *(&pass));
    ascii(format, i, ap, &count);
    base(format, i, ap, &count);
    integer(format, i, ap, &count);
    floats(format, i, ap, &count);
    if (format[i] == 'p')
        count += my_put_pointer(va_arg(ap, void *));
    if (format[i] == 'l' && format[i + 1] == 'f') {
        count += my_put_double(va_arg(ap, double), 6);
        *pass += 2;
    }
    return count;
}

static int check_percentage(char const *format, int *i, va_list ap, int *pass)
{
    int counter = 0;

    if (format[*i] == '%' && format[*i + 1] == '%') {
        counter += my_putchar('%');
        (*i)++;
    } else if (format[*i] == '%' && format[*i + 1] != '\0') {
        counter += check_specifier(format, *i + 1, ap, *(&pass));
        check_pass(i, pass);
    } else {
        counter += my_putchar(format[*i]);
    }
    return counter;
}

int my_printf(char const *format, ...)
{
    int counter = 0;
    va_list ap;
    int pass = 0;
    int *n;

    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%' && format[i + 1] == 'n') {
            n = va_arg(ap, int *);
            *n = counter;
        }
        counter += check_percentage(format, &i, ap, &pass);
    }
    va_end(ap);
    return counter;
}
