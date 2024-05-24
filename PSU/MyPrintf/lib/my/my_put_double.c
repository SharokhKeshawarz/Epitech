/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

static double my_pow_double(double base, double exponent)
{
    double result = 1.0;

    if (exponent == 0)
        return 1.0;
    if (exponent > 0) {
        for (int i = 0; i < exponent; i++)
            result *= base;
    } else {
        for (int i = 0; i > exponent; i--)
            result /= base;
    }
    return result;
}

static void print_fraction_d(int *counter, int precision, double *fraction)
{
    int digit = 0;

    if (precision > 0) {
        (*counter) += my_putchar('.');
        for (int i = 0; i < precision; i++) {
            (*fraction) *= 10;
            digit = (int)(*fraction);
            (*counter) += my_putchar(digit + 48);
            (*fraction) -= digit;
        }
    }
}

static void check_num_d(double *n, int *inte, double *fraction, int *counter)
{
    if (*n < 0) {
        my_putchar('-');
        *n *= -1;
    }
    *inte = (int)(*n);
    *fraction = (double)*n - (int)*inte;
    if (*inte == 0)
        (*counter) += my_putchar('0');
}

int my_put_double(double number, int precision)
{
    int integer;
    double fraction;
    int digit_number = 0;
    int temp;
    int digit;
    int counter = 0;

    check_num_d(&number, &integer, &fraction, &counter);
    temp = integer;
    while (temp > 0) {
        temp /= 10;
        digit_number++;
    }
    for (int i = 0; i < digit_number; i++) {
        digit = integer / (double)my_pow_double(10, digit_number - i - 1);
        digit %= 10;
        counter += my_putchar(digit + 48);
    }
    print_fraction_d(&counter, precision, &fraction);
    return counter;
}
