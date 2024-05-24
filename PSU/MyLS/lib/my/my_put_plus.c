/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

#include <stdarg.h>

static void check_negative_id(int *counter, int *value, int *pass, va_list ap)
{
    *value = va_arg(ap, int);
    if (value >= 0)
        *counter += my_putchar('+');
    *counter += my_put_nbr(*value);
    *pass += 2;
}

static void check_negative_u(int *counter, int *value, int *pass, va_list ap)
{
    *value = va_arg(ap, unsigned int);
    if (value >= 0)
        *counter += my_putchar('+');
    *counter += my_put_uint(*value);
    *pass += 2;
}

int my_put_plus(char const *format, int i, va_list ap, int *pass)
{
    int counter = 0;
    int value;

    if (format[i] == '+') {
        switch (format[i + 1]) {
            case 'i':
            case 'd':
                check_negative_id(&counter, &value, *(&pass), ap);
                break;
            case 'u':
                check_negative_u(&counter, &value, *(&pass), ap);
                break;
            default:
                counter += my_putchar(format[i]);
                break;
        }
    }
    return counter;
}
