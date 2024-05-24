/*
** EPITECH PROJECT, 2023
** getnbr
** File description:
** search a number in string
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int moins = 1;
    int y = 0;
    int nbr = 0;

    for (y = 0; str[y] != '\0'; y++){
        if (str[y] >= '0' && str[y] <= '9'){
            nbr = (nbr * 10);
            nbr = (nbr + (str[y] - 48));
        }
        if (str[y] == '-'){
            moins = moins * (-1);
            continue;
        }
        if (str[y] < '0' || str[y] > '9'){
            return (nbr);
        }
    }
    if (nbr == -1)
        return (0);
    return (nbr * moins);
}
