/*
** EPITECH PROJECT, 2023
** sum_numbers()
** File description:
** Sum all the numbers of the arguments
*/

int my_put_pointer(const void *ptr)
{
    unsigned char *pointer = (unsigned char *)&pointer;
    int counter = 0;
    int leadingZeros = 1;
    char *hex_string = "0123456789abcdef";

    my_putchar(48);
    my_putchar('x');
    for (int i = 0; i < sizeof(void *); i++) {
        if (pointer[i] == 0)
            continue;
        counter += my_putchar(hex_string[pointer[i] >> 4]);
        counter += my_putchar(hex_string[pointer[i] & 0x0f]);
    }
    return counter;
}
