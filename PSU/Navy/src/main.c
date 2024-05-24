/*
** EPITECH PROJECT, 2024
** my_navy
** File description:
** my_navy
*/

#include "../include/proto.h"

static int help(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        my_printf("USAGE\n");
        my_printf(
            "    ./navy [first_player_pid] navy_positions\n"
        );
        my_printf("DESCRIPTION\n");
        my_printf(
            "    first_player_pid: only for the 2nd player. "\
            "pid of the first player.\n"
        );
        my_printf(
            "    navy_positions: file representing "\
            "the positions of the ships.\n"
        );
        return 0;
    }
    return 1;
}

int main(int argc, char **argv)
{
    file_t *file = NULL;
    info_t *info = init_info_struct(argc, argv);
    int return_value = 0;

    if (info->argc == 1 || info->argc > 3)
        return 84;
    if (help(info->argc, info->argv) == 0)
        return 0;
    player_1(info, file, &return_value);
    player_2(info, file, &return_value);
    if (return_value == 84) {
        destroy(info, file);
        return 84;
    }
    destroy(info, file);
    return 0;
}
