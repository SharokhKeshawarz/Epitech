/*
** EPITECH PROJECT, 2023
** my_showstr()
** File description:
** Shows non printable character in hex
*/

int my_char_printable(char c)
{
    if (c < 32 || c > 126)
        return 1;
    return 0;
}

void print_check(char hex_digit1, char hex_digit2)
{
    my_putchar(hex_digit1 < 10 ? '0' + hex_digit1 : 'a' + hex_digit1 - 10);
    my_putchar(hex_digit1 < 10 ? '0' + hex_digit2 : 'a' + hex_digit2 - 10);
}

int my_showstr(char *str)
{
    char hex_digit1;
    char hex_digit2;

    while (*str) {
        if (my_char_printable(*str) == 1) {
            my_putchar('\\');
            hex_digit1 = (*str >> 4) & 0xF;
            hex_digit2 = *str & 0xF;
            print_check(hex_digit1, hex_digit2);
        } else {
            my_putchar(*str);
        }
        str++;
    }
    my_putchar('\n');
    return 0;
}
