/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

int my_put_float(float num, int precision)
{
    int integerPart;
    float decimalPart;
    int counter = 0;

    if (num < 0) {
        my_putchar('-');
        num = -num;
    }
    integerPart = (int)num;
    decimalPart = num - integerPart;
    counter += my_put_nbr(integerPart);
    counter += my_putchar('.');
    for (int i = 0; i < precision; i++) {
        decimalPart *= 10;
        counter += my_put_nbr((int)decimalPart);
        decimalPart -= (int)decimalPart;
    }
    return counter;
}
