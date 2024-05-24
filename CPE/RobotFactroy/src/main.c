/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/
#include "asm.h"

void indericet_set(all_t *all, header_t *header, int e)
{
    int x = 0;

    if (all->array[e][0] != 'r' && all->array[e][0] != '%') {
        x = my_get_nbr(all->array[e]);
        write(all->fd, &x, sizeof(char) * 2);
        header->prog_size += sizeof(char) * 2;
    }
}

int search_op(int fd, int j, header_t *header, all_t *all)
{
    int e = j;

    search_op_2(all, header, j);
    for (int i = 0; op_tab[i].mnemonique != 0; i++)
        if (my_strcmp(all->array[e], op_tab[i].mnemonique) == 0)
            search_op_3(all, header, i, e);
    return 1;
}

static int name_file_to_cor(char **argv)
{
    char *name = malloc(sizeof(char *) * (my_strlen(argv[1]) + 3));

    my_strncpy(name, argv[1], my_strlen(argv[1]) - 2);
    my_strcat(name, ".cor");
    return name;
}

static int write_1(all_t *all, header_t *header)
{
    write_big_endian_magic(all->fd, header->magic, header);
    write(all->fd, header->prog_name, PROG_NAME_LENGTH);
    write(all->fd, &all->x, sizeof(int));
}

static int write_2(all_t *all, header_t *header)
{
    write(all->fd, &all->placeholder, sizeof(int));
    write(all->fd, header->comment, COMMENT_LENGTH);
    write(all->fd, &all->x, sizeof(int));
}

static int error_checker_help(int argc, char **argv)
{
    int fd;

    if (argc < 2 || argc > 2)
        return FAIL;
    if (argv[1][0] == '-' && argv[1][0] == 'h') {
        my_printf("USAGE:\n");
        my_printf("asm file_name[.s]\n");
        my_printf("DESCRIPTION:\n");
        my_printf("file_name file in assembly language to be converted ");
        my_printf("into file_name.cor, an executable in the Virtual Machine.");
        my_printf("\n");
        return 0;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return 84;
    return 0;
}

static int main_2(header_t *header, all_t *all, char *name)
{
    all->fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write_1(all, header);
    all->prog_size_pos = lseek(all->fd, 0, SEEK_CUR);
    write_2(all, header);
    if (header->prog_name == NULL || header->comment == NULL)
        return 84;
    if (my_strlen(header->prog_name) <= 0 ||
    my_strlen(header->comment) <= 0)
        return 84;
    for (int i = 0; all->array[i] != NULL; i++)
        search_op(all->fd, i, header, all);
    lseek(all->fd, all->prog_size_pos, SEEK_SET);
    write_big_endian_4bit(all->fd, header->prog_size, header);
    return 0;
}

int main(int argc, char **argv)
{
    char *buffer;
    all_t *all = init_all();
    header_t *header;
    char *name;

    if (error_checker_help(argc, argv) == 84)
        return 84;
    buffer = create_buffer(argv[1]);
    all->array = my_str_to_word_array(buffer, " ,\r\t\n");
    name = name_file_to_cor(argv);
    header = init_headers(all->array, argv[1]);
    if (main_2(header, all, name) == 84)
        return 84;
    return 0;
}
