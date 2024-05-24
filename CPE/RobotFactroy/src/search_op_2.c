/*
** EPITECH PROJECT, 2024
** search_op_2.c
** File description:
** search_op_2
*/

#include "asm.h"

static int conditions_binary(int i)
{
    int count = 0;

    if (my_strcmp(op_tab[i].mnemonique, "live") != 0)
        count++;
    if (my_strcmp(op_tab[i].mnemonique, "live") != 0)
        count++;
    if (my_strcmp(op_tab[i].mnemonique, "zjmp") != 0)
        count++;
    if (my_strcmp(op_tab[i].mnemonique, "fork") != 0)
        count++;
    if (my_strcmp(op_tab[i].mnemonique, "lfork") != 0)
        count++;
    if (count == 5)
        return 1;
    return 0;
}

static void write_binary_to_file(all_t *all, header_t *header)
{
    char *token = my_strtok(all->binary, " \n\t\r");
    char *hex_binary;
    char x;

    while (token != NULL) {
        while (my_strlen(token) != 8)
            my_strcat(token, "00");
        hex_binary = binary_to_hex(all->binary);
        x = hex_string_to_char(hex_binary);
        write(all->fd, &x, sizeof(char));
        break;
    }
}

static void binary_conversion(all_t *all, int j)
{
    if (all->array[j][0] == 'r') {
        if (all->binary == NULL)
            my_strcpy(all->binary, "01");
        else
            my_strcat(all->binary, "01");
    }
    if (all->array[j][0] == '%') {
        if (all->binary == NULL)
            my_strcpy(all->binary, "10");
        else
            my_strcat(all->binary, "10");
    }
    if (all->array[j][0] != 'r' && all->array[j][0] != '%') {
        if (all->binary == NULL)
            my_strcpy(all->binary, "11");
        else
            my_strcat(all->binary, "11");
    }
}

static void binary_operation(all_t *all, header_t *header, int j, int i)
{
    all->binary = malloc(sizeof(char) * 8);
    if (conditions_binary(i)) {
        for (int k = 0; k < op_tab[i].nbr_args; k++) {
            j++;
            binary_conversion(all, j);
        }
        write_binary_to_file(all, header);
        header->prog_size += sizeof(char);
    }
}

void search_op_2(all_t *all, header_t *header, int j)
{
    for (int i = 0; op_tab[i].mnemonique != 0; i++) {
        if (my_strcmp(all->array[j], op_tab[i].mnemonique) == 0) {
            write(all->fd, &op_tab[i].code, 1);
            header->prog_size += sizeof(char);
            binary_operation(all, header, j, i);
        }
    }
}
