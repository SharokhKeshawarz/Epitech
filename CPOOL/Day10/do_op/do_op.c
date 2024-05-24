/*
** EPITECH PROJECT, 2021
** do-op.c
** File description:
** do-op
*/

int ignore_character_number(char *str)
{
    int quit = 0;
    int i = 0;
    int get_number_str = my_getnbr(str);

    while (i < my_strlen(str)) {
        if (str[i] == '-')
            continue;
        if (!(str[i] >= 48 && str[i] <= 57) && quit == 0)
            return 0;
        quit = 1;
        i++;
    }
    return get_number_str;
}

char check_operator(char *str)
{
    int length = my_strlen(str);
    char operator;
    int i = 0;

    while (i < length) {
        operator = str[i];
        if (operator == '+' || operator == '-')
            return operator;
        if (operator == '/' || operator == '%' || operator == '*')
            return operator;
        i++;
    }
    return 0;
}

int print_operation_2(int x, char op, int y)
{
    if (op == '+') {
        my_put_nbr(x + y);
        return 0;
    }
}

int print_operation(int x, char op, int y)
{
    if (print_operation_2(x, op, y) == 0)
        return 0;
    if (op == '-') {
        my_put_nbr(x - y);
        return 0;
    }
    if (op == '*') {
        my_put_nbr(x * y);
        return 0;
    }
    if (op == '/') {
        my_put_nbr(x / y);
        return 0;
    }
    if (op == '%') {
        my_put_nbr(x % y);
        return 0;
    }
    my_putchar('0');
    return 84;
}

int main(int argc, char **argv)
{
    int number1 = ignore_character_number(argv[1]);
    char operator = check_operator(argv[2]);
    int number2 = ignore_character_number(argv[3]);

    if (argv[2][0] == '%' && number2 == 0) {
        my_putstr("Stop: modulo by zero\n");
        return 84;
    } else if (argv[2][0] == '/' && number2 == 0) {
        my_putstr("Stop: division by zero\n");
        return 84;
    }
    if (print_operation(number1, operator, number2) == 0)
        return 0;
    return 84;
}
