/*
** EPITECH PROJECT, 2023
** file_parsing.c
** File description:
** file_parsing
*/

#include "main.h"

void create_buffer(game_t *game)
{
    int fd;
    struct stat st;
    ssize_t bytes_read;

    fd = open(game->parse->path, O_RDONLY);
    if (fd == -1)
        return;
    stat(game->parse->path, &st);
    game->parse->buffer = malloc(st.st_size * sizeof(char) + 1);
    bytes_read = read(fd, game->parse->buffer, st.st_size);
    if (bytes_read < 0)
        return;
    game->parse->buffer[bytes_read] = '\0';
    free(game->parse->path);
}

void get_row(game_t *game)
{
    game->parse->row = 0;
    for (int i = 0; game->parse->buffer[i] != '\0'; i++)
        if (game->parse->buffer[i] == '\n')
            game->parse->row = game->parse->row + 1;
    if (game->parse->buffer[0] != '\0')
        if (game->parse->buffer[my_strlen(game->parse->buffer) - 1] != '\n')
            game->parse->row++;
}

static void get_last_row(game_t *game, int counter, int i, int j)
{
    if (counter > 0) {
        game->parse->buffer_array[j] = malloc(counter + 1);
        my_strncpy(
            game->parse->buffer_array[j],
            game->parse->buffer + (j > 0 ? i - counter + 0 : 1), counter
        );
        game->parse->buffer_array[j][counter] = '\0';
    }
}

void buffer_to_array(game_t *game)
{
    int counter = 0;
    int j = 0;
    int i = 0;

    game->parse->buffer_array = malloc(game->parse->row * sizeof(char *));
    for (i = 0; game->parse->buffer[i] != '\0'; i++) {
        if (game->parse->buffer[i] != '\n')
            counter++;
        else {
            game->parse->buffer_array[j] = malloc(counter + 1);
            my_strncpy(game->parse->buffer_array[j],
                game->parse->buffer + i - counter, counter);
            game->parse->buffer_array[j][counter] = '\0';
            j++;
            counter = 0;
        }
    }
    get_last_row(game, counter, i, j);
    free(game->parse->buffer);
}

void count_object_number(game_t *game)
{
    game->parse->tower_number = 0;
    game->parse->plane_number = 0;
    for (int i = 0; i < game->parse->row; i++) {
        if (game->parse->buffer_array[i][0] == 'A')
            game->parse->plane_number++;
        if (game->parse->buffer_array[i][0] == 'T')
            game->parse->tower_number++;
    }
}
