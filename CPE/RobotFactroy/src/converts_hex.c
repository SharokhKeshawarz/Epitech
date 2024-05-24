/*
** EPITECH PROJECT, 2023
** converts.c
** File description:
** converts
*/

#include "asm.h"

static char *char_to_hex(char character)
{
    char hex[10];
    char *result = malloc(sizeof(char) * 10);
    int index;
    int index_j = 0;
    int remainder = 0;

    for (index = 0; character > 0; index++) {
        remainder = character % 16;
        if (remainder < 10)
            hex[index] = remainder + 48;
        else
            hex[index] = remainder - 10 + 97;
        character /= 16;
    }
    for (int i = index - 1; i >= 0; i--) {
        result[index_j] = hex[i];
        index_j++;
    }
    result[index_j] = '\0';
    return result;
}

void print_hex(char **string)
{
    int count_words = 0;

    while (string[count_words] != NULL)
        count_words++;
    for (int i = 0; string[i] != NULL; i++) {
        my_printf("%s", string[i]);
        if (i < count_words - 1)
            my_printf(" ");
    }
    my_printf("\n");
}

char **string_to_hex(char *string)
{
    char **string_array = malloc(sizeof(char *) * my_strlen(string) + 1);
    int i;

    for (i = 0; string[i] != '\0'; i++)
        string_array[i] = my_strdup(char_to_hex(string[i]));
    string_array[i] = NULL;
    return string_array;
}

static int count_hex_digits(int decimal_num)
{
    int num_digits = 0;
    int temp = decimal_num;

    while (temp != 0) {
        temp /= 16;
        num_digits++;
    }
    return num_digits;
}

static char *decimal_to_hex(int decimal_num, int num_digits)
{
    char *hex_str = malloc((num_digits + 1) * sizeof(char));
    int i = num_digits - 1;
    int remainder;

    while (decimal_num != 0) {
        remainder = decimal_num % 16;
        if (remainder < 10)
            hex_str[i] = remainder + '0';
        else
            hex_str[i] = remainder - 10 + 'A';
        decimal_num /= 16;
        i--;
    }
    hex_str[num_digits] = '\0';
    return hex_str;
}

char *binary_to_hex(const char *binary_str)
{
    int decimal_num = my_strtol(binary_str, NULL, 2);
    int num_digits = count_hex_digits(decimal_num);
    char *hex_str = decimal_to_hex(decimal_num, num_digits);

    return hex_str;
}

int hex_to_int(char hex_char)
{
    if (my_isdigit(hex_char))
        return hex_char - '0';
    else if (my_isxdigit(hex_char))
        return my_toupper(hex_char) - 'A' + 10;
    return 84;
}

char hex_string_to_char(const char *hex_value)
{
    int first_digit;
    int second_digit;

    if (my_strlen(hex_value) != 2)
        return 84;
    first_digit = hex_to_int(hex_value[0]);
    second_digit = hex_to_int(hex_value[1]);
    return (char)((first_digit << 4) + second_digit);
}
