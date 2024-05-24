/*
** EPITECH PROJECT, 2023
** my_putnbr_base()
** File description:
** Convertes a number to a base
*/

int base_length(char const *str)
{
    int i = 0;

    while (str[i])
        i++;
    return i;
}

void reverse_characters(char *str, int length)
{
    int i = 0;
    int j = length - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void my_putnbr_base(int nbr, char const *base)
{
    int base_len = base_length(base);
    char result[32];
    int i = 0;

    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr == 0) {
        my_putchar(base[0]);
        return;
    }
    while (nbr > 0) {
        result[i++] = base[nbr % base_len];
        nbr = nbr / base_len;
    }
    reverse_characters(result, i);
    for (int j = 0; j < i; j++)
        my_putchar(result[j]);
}
