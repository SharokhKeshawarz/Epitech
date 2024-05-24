/*
** EPITECH PROJECT, 2023
** players.c
** File description:
** players
*/

#include "../include/proto.h"

int player_1(info_t *info, file_t *file, int *return_value)
{
    if (info->argc == 2) {
        file = init_file_struct(info->argv[1]);
        (*return_value) = init_file_struct_values(file);
        main_signal_usr1();
    }
}

int player_2(info_t *info, file_t *file, int *return_value)
{
    info->pid = my_getnbr(info->argv[1]);
    if (info->argc == 3) {
        file = init_file_struct(info->argv[2]);
        (*return_value) = init_file_struct_values(file);
        main_signal_usr2(info->pid);
    }
}
