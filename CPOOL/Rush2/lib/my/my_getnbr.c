/*
** EPITECH PROJECT, 2023
** my_getnbr()
** File description:
** Get number of a number
*/

void check_letters(char const *str, int *index, int *negative)
{
    while (str[*index] != '\0' && (str[*index] < 48 || str[*index] > 57)) {
        if (str[*index] == '-')
            *negative *= -1;
        *index = *index + 1;
    }
}

int int_size(long number, int number_length)
{
    if (number > 2147483647 || number < -2147483648 || number_length > 10)
        return 0;
    return 1;
}

int my_getnbr(char const *str)
{
    long number = 0;
    int negative = 1;
    int index = 0;
    int number_length = 0;
    int quit = 0;

    check_letters(str, &index, &negative);
    while (str[index] >= 48 && str[index] <= 57) {
        if (!int_size(number, number_length))
            quit = 1;
        number = number * 10 + (str[index] - 48);
        index++;
        number_length++;
        if (!int_size(number, number_length))
            quit = 1;
    }
    if (quit == 1)
        return 0;
    return (int)(number * negative);
}
