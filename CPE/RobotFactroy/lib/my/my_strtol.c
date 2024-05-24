/*
** EPITECH PROJECT, 2024
** my_strtol.c
** File description:
** my_strtol
*/

#include "../../include/my.h"

static const char *skip_whitespace(const char *str)
{
    while (*str == ' ' || *str == '\t' || *str == '\n')
        str++;
    return str;
}

static int parse_sign(const char **str)
{
    int sign = 1;

    if (**str == '-') {
        sign = -1;
        (*str)++;
    } else if (**str == '+')
        (*str)++;
    return sign;
}

static void parse_base_2(const char **str, int *base)
{
    if (*(*str + 1) == 'x' || *(*str + 1) == 'X') {
        (*base) = 16;
        (*str) += 2;
    } else {
        (*base) = 8;
        (*str)++;
    }
}

static int conditions(const char **str)
{
    return (*(*str + 1) == 'x' || *(*str + 1) == 'X');
}

static int parse_base(const char **str, int base)
{
    if (base == 0) {
        if (**str == '0')
            parse_base_2(str, &base);
        else
            base = 10;
    } else if (base == 16 && **str == '0' && conditions(&str))
        (*str) += 2;
    return base;
}

static int parse_digit(char c)
{
    int digit;

    if (c >= '0' && c <= '9')
        digit = c - '0';
    if (c >= 'a' && c <= 'z')
        digit = c - 'a' + 10;
    if (c >= 'A' && c <= 'Z')
        digit = c - 'A' + 10;
    return digit;
}

static long parse_integer(const char *str, int base, char **endptr)
{
    long result = 0;
    int digit;

    while (*str != '\0') {
        digit = parse_digit(*str);
        if (digit < 0 || digit >= base)
            break;
        result = result * base + digit;
        str++;
    }
    if (endptr != NULL)
        *endptr = (char *)str;
    return result;
}

long my_strtol(const char *str, char **endptr, int base)
{
    int sign;
    long result;

    str = skip_whitespace(str);
    sign = parse_sign(&str);
    base = parse_base(&str, base);
    result = parse_integer(str, base, endptr);
    return result * sign;
}
