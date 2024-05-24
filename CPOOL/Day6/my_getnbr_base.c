/*
** EPITECH PROJECT, 2023
** my_getnbre_base()
** File description:
** Converte a base to decimal
*/

int my_strlen_base(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

int is_digit(char c, char const *base)
{
    int i = 0;

    while (base[i]) {
        if (c == base[i])
            return 1;
        i++;
    }
    return 0;
}

int to_digit(char c, char const *base)
{
    int i = 0;

    while (base[i]) {
        if (c == base[i])
            return i;
        i++;
    }
    return -1;
}

int my_getnbr_base(char const *str, char const *base)
{
    int result = 0;
    int sign = 1;

    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-') {
        sign = -1;
        str++;
    } else if (*str == '+')
        str++;
    if (my_strlen_base(base) < 2)
        return 0;
    while (*str) {
        if (is_digit(*str, base) == 1)
            result = result * my_strlen_base(base) + to_digit(*str, base);
        else
            return 0;
        str++;
    }
    return result * sign;
}
