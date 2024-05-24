/*
** EPITECH PROJECT, 2023
** put_str()
** File description:
** put_str
*/

void my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}
