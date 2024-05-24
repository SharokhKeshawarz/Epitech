/*
** EPITECH PROJECT, 2023
** MY_GETNBR
** File description:
** my_getnbr.c
*/

int my_getnbr(char const *str)
{
    int nbr = 0;
    int neg = 1;
    int a = 0;

    if (str[0] == '-') {
        neg = -1;
        a++;
    }
    for (; str[a]; a++) {
        if (str[a] <= '9' && str[a] >= '0')
            nbr = nbr * 10 + str[a] - 48;
        else
            return nbr * neg;
    }
    return nbr * neg;
}
