/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** Headers for the projects
*/

#ifndef MY_H
    #define MY_H
    #include <ncurses.h>
    #include <stdlib.h>
    #include <stdio.h>
    #define MAX_ROWS 100
    #define MAX_COLS 100

// Lib
void my_putstr(char const *str);
void my_strcpy(char *dest, char const *src);
void my_strdup(char *dest);
int my_strlen(char const *str);

// Project
typedef struct {
    char board[MAX_ROWS][MAX_COLS];
    int rows;
    int cols;
    int player_row;
    int player_col;
    int next_row;
    int next_col;
} game_t;

void read_map(const char *filename, game_t *game);
void draw_board(game_t *game);
static int check_move_conditions(game_t *game);
static int check_walls_and_x(game_t *game);
static void move_player_check_collision(game_t *game, int row, int col);
static int check_zs(game_t *game, int row, int col);
void move_player(int row, int col, game_t *game);
void check_ch(int ch, game_t *game);
static void check_player_position(game_t *game, int i, int j, int *quit);
int main(int argc, char **argv);

#endif
