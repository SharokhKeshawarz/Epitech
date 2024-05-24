/*
** EPITECH PROJECT, 2024
** proto.h
** File description:
** proto.h
*/

#ifndef PROTO_H
    #define PROTO_H
    // (should be removed when pushing to 'leo' branch its only for vscode)
    #define _POSIX_C_SOURCE 199309L
    #include <time.h>
    #include <stdio.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <signal.h>
    #include <sys/types.h>
    #include "my.h"
    #include "my_printf.h"

// Contains all file information
typedef struct {
    FILE *fd;
    char *path;
    char **array;
    char *string;
    size_t size;
} file_t;

// Contains all shell information
typedef struct {
    int argc;
    char **argv;
    int pid;
    // TODO: We should create the map
} info_t;

// inits_destroy.c
file_t *init_file_struct(char *path);
info_t *init_info_struct(int argc, char **argv);
void destroy(info_t *info, file_t *file);

// file_to_array.c
int init_file_struct_values(file_t *file);

// file_to_array_error.c
int error_handling_files(file_t *file);
int column_checker(file_t *file);

// signal.c
int main_signal_usr2(int nb_pid);
int main_signal_usr1(void);

// players.c
int player_1(info_t *info, file_t *file, int *return_value);
int player_2(info_t *info, file_t *file, int *return_value);

#endif /* PROTO_H */
