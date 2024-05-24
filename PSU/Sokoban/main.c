/*
** EPITECH PROJECT, 2023
** main()
** File description:
** Sokoban project
*/

#include "include/my.h"

void read_map(const char *filename, game_t *game)
{
    FILE *file = fopen(filename, "r");
    char *read;

    game->rows = 0;
    game->cols = 0;
    read = fgets(game->board[game->rows], MAX_COLS, file);
    while (read != NULL) {
        if (game->cols > my_strlen(game->board[game->rows]))
            game->cols = game->cols;
        else
            game->cols = my_strlen(game->board[game->rows]);
        game->rows = game->rows + 1;
        read = fgets(game->board[game->rows], MAX_COLS, file);
    }
    fclose(file);
}

void draw_board(game_t *game)
{
    clear();
    for (int i = 0; i < game->rows; i++)
        for (int j = 0; j < game->cols; j++)
            mvprintw(i, j, "%c", game->board[i][j]);
    refresh();
}

static int check_move_conditions(game_t *game)
{
    if (game->next_row >= 0 && game->next_row < game->rows)
        if (game->next_col >= 0 && game->next_col < game->cols)
            return 1;
    return 0;
}

static int check_walls_and_x(game_t *game)
{
    if (game->board[game->next_row][game->next_col] != '#')
        if (game->board[game->next_row][game->next_col] != 'X')
            return 1;
    return 0;
}

static void move_player_check_collision(game_t *game, int row, int col)
{
    if (check_move_conditions(game)) {
        if (game->board[game->next_row][game->next_col] == '0')
            game->board[game->next_row][game->next_col] = 'X';
        if (check_walls_and_x(game)) {
            game->board[game->next_row][game->next_col] = 'X';
            game->board[game->player_row][game->player_col] = ' ';
            game->player_row = row;
            game->player_col = col;
            game->board[game->player_row][game->player_col] = 'P';
        }
    }
}

static int check_zs(game_t *game, int row, int col)
{
    if (game->board[row][col] == ' ' || game->board[row][col] == 0)
        return 1;
    return 0;
}

void move_player(int row, int col, game_t *game)
{
    if (row >= 0 && row < game->rows && col >= 0 && col < game->cols) {
        if (check_zs(game, row, col)) {
            game->board[game->player_row][game->player_col] = ' ';
            game->player_row = row;
            game->player_col = col;
            game->board[game->player_row][game->player_col] = 'P';
        }
        if (game->board[row][col] == 'X' && check_zs(game, row, col) == 0) {
            game->next_row = row + (row - game->player_row);
            game->next_col = col + (col - game->player_col);
            move_player_check_collision(game, row, col);
        }
    }
}

void check_ch(int ch, game_t *game)
{
    while (1) {
        draw_board(game);
        ch = getch();
        switch (ch) {
            case KEY_UP:
                move_player(game->player_row - 1, game->player_col, game);
                break;
            case KEY_DOWN:
                move_player(game->player_row + 1, game->player_col, game);
                break;
            case KEY_LEFT:
                move_player(game->player_row, game->player_col - 1, game);
                break;
            case KEY_RIGHT:
                move_player(game->player_row, game->player_col + 1, game);
                break;
            case 'q':
                endwin();
        }
    }
}

static void check_player_position(game_t *game, int i, int j, int *quit)
{
    if (game->board[i][j] == 'P') {
        game->player_row = i;
        game->player_col = j;
        *quit = 1;
    }
}

int main(int argc, char **argv)
{
    game_t *game = malloc(sizeof(game_t));
    int ch;
    int quit = 0;

    initscr();
    noecho();
    keypad(stdscr, TRUE);
    read_map(argv[1], game);
    for (int i = 0; i < game->rows; i++)
        for (int j = 0; j < game->cols && quit == 0; j++)
            check_player_position(game, i, j, &quit);
    check_ch(ch, game);
    endwin();
    return 0;
}
