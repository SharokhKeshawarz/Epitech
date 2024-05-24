/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

#include <stdarg.h>

int my_put_h_hh(char const *format, int i, va_list ap, int *pass)
{
    int counter = 0;

    if (format[i] == 'h' && format[i + 1] != 'h') {
        counter += my_putchar((char)va_arg(ap, int));
        *pass += 0;
    } else if (format[i] == 'h' && format[i + 1] == 'h') {
        counter += my_put_nbr((short)va_arg(ap, int));
        *pass += 2;
    } else
        return 0;
    return counter;
}
