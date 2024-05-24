/*
** EPITECH PROJECT, 2023
** main.h
** File description:
** main
*/

#ifndef MAIN_H
    #define MAIN_H
    #include <unistd.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>

void my_putchar(char);
void my_puterr(char);
void my_putstr(char const *);
void my_putstrerr(char const *);
char *my_strdup(char const *);

typedef struct info {
    char **map;
    char *filepath;
    char *buffer;
    int nb_rows;
    int nb_cols;
    int max_size;
    int max_row;
    int max_col;
    int row;
    int col;
} info;

static info *init_info(void);

void get_dimensions_2(info *, int *, int *, int *);
int get_dimensions(info *);

int open_file(info *);
static int get_nb(info *, int *);
int load_file_in_mem(info *);
static int check_error_char(info *, int, int);
static int error_loop(info *, int *);
static void load_2d_arr_from_file_3(info *, int *);
static void load_2d_arr_from_file_2(info *, int *);
int load_2d_arr_from_file(info *);
static int file_operations(info *, char **);
static int arguments_checker(int, char **);

static void find_biggest_square_2(info *, int, int *, int);
int find_biggest_square(info *);
void replace_biggest_square(info *);
static void print_2d_array(info *);
static void set_size(info *, int, int);
static void algo(info *);
static void destroy(info *);

#endif
