/*
** EPITECH PROJECT, 2023
** minishell.h
** File description:
** minishell
*/

#ifndef ASM_H
    #define ASM_H
    #define SUCCESS 0
    #define FAIL 84
    #define MAX_PATH_LENGTH 1024
    #define MAX_COMMAND_LENGTH 1024
    #define DELIMITERS " \t\r\n\a"
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include "my.h"
    #include "my_printf.h"
    #include "op.h"

void print_hex(char **string);
char **string_to_hex(char *string);
char *create_buffer(char *path);
char *get_name(header_t *header, char **array);
char *get_comment(header_t *header, char **array);
void get_size(header_t *header, char *path);

typedef struct all_s {
    int a;
    char **array;
    char *binary;
    int i;
    int fd;
    int tmp;
    char **label_1;
    char *mot;
    int u;
    int x;
    int placeholder;
    int prog_size_pos;
} all_t;

#endif /* ASM_H */
