/*
** EPITECH PROJECT, 2023
** my_printf.h
** File description:
** my_printf
*/

#ifndef MY_PRINTF
    #define MY_PRINTF
    #include <stdarg.h>
    #include <unistd.h>
    #include "my.h"

int my_putchar(char c);
int my_put_nbr(int nb);
int my_put_octal(int number);
int my_put_hex(int number, char character);
int my_put_uint(unsigned int number);
int my_putstr_printf(char const *str, char character);
int my_put_float(float number, int precesion);
int my_put_sci(double number, int precesion, char character);
int my_put_plus(char const *format, int i, va_list ap, int *pass);
int my_put_hash(char const *format, int i, va_list ap, int *pass);
int my_put_l(char const *format, int i, va_list ap, int *pass);
int my_put_h_hh(char const *format, int i, va_list ap, int *pass);
int my_put_pointer(const void *ptr);
int my_put_double(double number, int precision);
int my_printf(char const *format, ...);

#endif /* MY_PRINTF_H */
