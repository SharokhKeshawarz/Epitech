/*
** EPITECH PROJECT, 2023
** my_put_float()
** File description:
** Prints floating numbers
*/

void check_float_condition(int *integer)
{
    if (*integer == 0) {
        my_putchar(48);
        return;
    }
    if (*integer < 0) {
        my_putchar('-');
        *integer *= -1;
    }
}

void my_put_float(float number)
{
    int integer = (int)number;
    int fraction = (int)((number - integer) * 100);
    int digit_number = 0;
    int temp = integer;
    int digit;

    check_float_condition(&integer);
    while (temp > 0) {
        temp /= 10;
        digit_number++;
    }
    for (int i = 0; i < digit_number; i++) {
        digit = integer / (int)my_compute_power_rec(10, digit_number - i - 1);
        digit %= 10;
        my_putchar(digit + 48);
    }
    my_putchar('.');
    my_putchar(48 + (fraction / 10));
    my_putchar(48 + (fraction % 10));
}
