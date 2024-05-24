/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>

int my_put_double(double, int);
int my_put_float(float, int);
int my_put_h_hh(char const *, int, va_list, int *);
int my_put_hash(char const *, int, va_list, int *);
int my_put_hex(int, char);
int my_put_l(char const *, int, va_list, int *);
int my_put_nbr(int);
int my_put_octal(int);
int my_put_plus(char const *, int, va_list, int *);
int my_put_pointer(const void *ptr);
int my_put_sci(double, int, char);
int my_put_uint(unsigned int);
int my_putchar(char);
int my_putstr(char const *, char);
int my_printf(char const *, ...);

#endif
