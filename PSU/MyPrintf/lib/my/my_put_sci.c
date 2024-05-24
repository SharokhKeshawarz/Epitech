/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

static void character_type_sci(char *type, char character)
{
    if (character == 'E')
        (*type) = 'E';
    else
        (*type) = 'e';
}

static void check_sci(double *value, int *counter, int precision, char type)
{
    if (*value < 0) {
        (*counter) += my_putchar('-');
        (*value) = -(*value);
    }
    if (*value == 0.0) {
        (*counter) += my_putchar(48);
        (*counter) += my_putchar('.');
        for (int i = 0; i < precision; i++)
            (*counter) += my_putchar(48);
        (*counter) += my_putchar(type);
        (*counter) += my_putchar('+');
        (*counter) += my_putchar(48);
    }
    return;
}

static void check_expoent_sci(int *exponent, int *counter, char type)
{
    (*counter) += my_putchar(type);
    if (*exponent >= 0) {
        (*counter) += my_putchar('+');
    } else {
        (*counter) += my_putchar('-');
        (*exponent) = -(*exponent);
    }
    if (*exponent < 10)
        (*counter) += my_putchar('0');
    (*counter) += my_put_nbr(*exponent);
}

int my_put_sci(double value, int precision, char character)
{
    char type;
    int exponent = 0;
    int counter = 0;

    character_type_sci(&type, character);
    check_sci(&value, &counter, precision, type);
    while (value >= 10.0) {
        value /= 10.0;
        exponent++;
    }
    counter += my_putchar((int)value + '0');
    value -= (int)value;
    counter += my_putchar('.');
    for (int i = 0; i < precision; i++) {
        value *= 10.0;
        counter += my_putchar((int)value + '0');
        value -= (int)value;
    }
    check_expoent_sci(&exponent, &counter, type);
}
