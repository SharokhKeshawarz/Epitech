/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

int my_putstr(char const *str, char character)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++)
        counter += my_putchar(str[i]);
    return counter;
}
