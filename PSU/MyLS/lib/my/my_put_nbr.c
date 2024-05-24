/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

static void check_nbr(int nb, long int *number, int *counter)
{
    if (nb == 0)
        *counter += my_putchar('0');
    if (nb < 0) {
        *counter += my_putchar('-');
        *number *= -1;
    }
}

int my_put_nbr(int nb)
{
    long number = nb;
    long reverse = 1;
    long digit = 0;
    int counter = 0;

    check_nbr(nb, &number, &counter);
    while (number > 0) {
        digit = number % 10;
        reverse = (reverse * 10) + digit;
        number /= 10;
    }
    while (reverse > 1) {
        digit = reverse % 10;
        counter += my_putchar(digit + 48);
        reverse /= 10;
    }
    return counter;
}
