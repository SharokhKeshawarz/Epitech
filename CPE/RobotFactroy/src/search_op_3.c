/*
** EPITECH PROJECT, 2024
** search_op_3.c
** File description:
** search_op_3
*/

#include "asm.h"

static int r_and_percent_conditions(int i)
{
    if (my_strcmp(op_tab[i].mnemonique, "sti") == 0)
        return 1;
    if (my_strcmp(op_tab[i].mnemonique, "ldi") == 0)
        return 1;
    if (my_strcmp(op_tab[i].mnemonique, "lldi") == 0)
        return 1;
    return 0;
}

static void r_and_percent(all_t *all, header_t *header, int e, int i)
{
    int x = 0;

    if (all->array[e][0] == 'r') {
        x = my_get_nbr(all->array[e]);
        write(all->fd, &x, sizeof(char));
        header->prog_size += sizeof(char);
    }
    if (all->array[e][0] == '%' && all->array[e][1] != ':') {
        x = my_get_nbr(all->array[e]);
        if (r_and_percent_conditions(i))
            write_big_endian_2bit(all->fd, x, header, 1);
        else
            write_big_endian_4bit(all->fd, x, header);
    }
}

static void total_zjump_indirect(all_t *all, header_t *header, int e)
{
    char func[my_strlen(all->label_1)];
    int rr = 0;

    if (my_strcmp(all->mot, all->label_1) == 0) {
        all->a = header->prog_size;
        write_big_endian_2bit(all->fd, all->a, header, 0);
    }
    if (my_strcmp(all->array[e - 1], "zjmp") == 0) {
        all->tmp = e;
        for (int z = 2; all->array[all->tmp][z] != '\0'; z++){
            func[rr] = all->array[all->tmp][z];
            rr++;
        }
        func[rr] = '\0';
        if (my_strcmp(func, all->label_1) == 0) {
            all->u = header->prog_size - all->a - 3;
            all->u = -all->u;
            write_big_endian_2bit(all->fd, all->u, header, 0);
        }
    }
}

static int special_func_2(all_t *all, int y)
{
    int counter = 0;

    if (my_isalpha(all->array[all->tmp][y]))
        counter++;
    if (all->array[all->tmp][my_strlen(all->label_1)] == ':')
        counter++;
    if (all->array[all->tmp][y] != '%')
        counter++;
    if (counter == 3)
        return 1;
    return 0;
}

static int special_func_3(all_t *all, int y)
{
    if (all->array[all->tmp] == "live")
        return 1;
    if (all->array[all->tmp] == "zjmp")
        return 1;
    if (all->array[all->tmp] == "fork")
        return 1;
    if (all->array[all->tmp] == "lfork")
        return 1;
    return 0;
}

static int special_func_4(all_t *all, int y)
{
    int counter = 0;

    if (all->array[all->tmp][y] == '%')
        return 1;
    if (all->array[all->tmp][y] == 'r')
        counter++;
    if (all->array[all->tmp][y + 1] == my_isdigit(all->array[all->tmp][y + 1]))
        counter++;
    if (all->array[all->tmp][y] == ',')
        counter++;
    if (all->array[all->tmp][y + 1] == my_isdigit(all->array[all->tmp][y + 1]))
        counter++;
    if (counter == 4)
        return 1;
    return 0;
}

static void special_func(header_t *header, all_t *all, int y, int i)
{
    if (special_func_2(all, y)) {
        my_strncpy(all->mot, all->array[all->tmp], my_strlen(all->label_1));
        all->mot[my_strlen(all->label_1)] = '\0';
    }
    if (op_tab[i].mnemonique == all->array[all->tmp])
        if (special_func_3(all, y))
            header->prog_size += sizeof(char);
        else
            header->prog_size += sizeof(char) * 2;
        if (special_func_4(all, y))
            header->prog_size += sizeof(char) * 2;
}

static void check_other_label(all_t *all, header_t *header, int i)
{
    int t = 0;

    for (int y = 0; all->array[all->tmp] != '\0'; y++) {
        special_func(header, all, y, i);
        all->tmp++;
    }
}

static void condition_of_zjump(header_t *header, all_t *all, int e)
{
    if (my_strcmp(all->array[e - 1], "zjmp") != 0)
        header->prog_size += sizeof(char) * 2;
}

void search_op_3(all_t *all, header_t *header, int i, int e)
{
    int len = 0;

    for (int k = 0; k < op_tab[i].nbr_args; k++) {
        e++;
        r_and_percent(all, header, e, i);
        if (all->array[e][0] == '%' && all->array[e][1] == ':') {
            condition_of_zjump(header, all, e);
            all->label_1 = my_strninterval(
                all->array[e], 2, my_strlen(all->array[e])
            );
            len = my_strlen(all->array[e]) - 1;
            all->tmp = e;
            all->tmp++;
            all->mot = malloc(sizeof(char) * my_strlen(all->label_1));
            check_other_label(all, header, i);
            total_zjump_indirect(all, header, e);
        }
        indericet_set(all, header, e);
    }
}
