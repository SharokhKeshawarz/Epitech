/*
** EPITECH PROJECT, 2023
** objects_array.c
** File description:
** objects_array
*/

#include "main.h"

void init_objects_tower(game_t *game)
{
    int tower_index = 0;

    for (int i = 0; i < game->parse->row; i++) {
        if (game->parse->buffer_array[i][0] == 'T') {
            game->tower_objects[tower_index]->pos_x = 0;
            game->tower_objects[tower_index]->pos_y = 0;
            game->tower_objects[tower_index]->radius_value = 0;
            tower_index++;
        }
    }
}

void init_objects_plane(game_t *game)
{
    int plane_index = 0;

    for (int i = 0; i < game->parse->row; i++) {
        if (game->parse->buffer_array[i][0] == 'A') {
            game->plane_objects[plane_index]->takeoff_x = 0;
            game->plane_objects[plane_index]->takeoff_y = 0;
            game->plane_objects[plane_index]->landing_x = 0;
            game->plane_objects[plane_index]->landing_y = 0;
            game->plane_objects[plane_index]->speed = 0.0f;
            game->plane_objects[plane_index]->takeoff_time = 0;
            game->plane_objects[plane_index]->spawn = 0;
            plane_index++;
        }
    }
}

void create_object_array(game_t *game)
{
    int tower_index = 0;
    int plane_index = 0;

    game->tower_objects = malloc(
        game->parse->tower_number * sizeof(tower_t *)
    );
    game->plane_objects = malloc(
        game->parse->plane_number * sizeof(plane_t *)
    );
    for (int i = 0; i < game->parse->row; i++) {
        if (game->parse->buffer_array[i][0] == 'T') {
            game->tower_objects[tower_index] = malloc(sizeof(tower_t));
            tower_index++;
        }
        if (game->parse->buffer_array[i][0] == 'A') {
            game->plane_objects[plane_index] = malloc(sizeof(plane_t));
            plane_index++;
        }
    }
}

void fill_tower_objects(game_t *game)
{
    int tower_index = 0;

    for (int i = 0; i < game->parse->row; i++) {
        if (game->parse->buffer_array[i][0] == 'T') {
            extract_numbers(
                game->parse->buffer_array[i],
                game->parse->tower_values,
                TOWER_VALUES
            );
            game->tower_objects[tower_index]->pos_x =
            game->parse->tower_values[TOWER_POSX];
            game->tower_objects[tower_index]->pos_y =
            game->parse->tower_values[TOWER_POSY];
            game->tower_objects[tower_index]->radius_value =
            game->parse->tower_values[TOWER_RADIUS];
            tower_index++;
        }
    }
}

static void fill_plane_objects_2(game_t *game, int plane_index, int values[])
{
    game->plane_objects[plane_index]->takeoff_x =
    game->parse->plane_values[PLANE_TAKEOFF_POSX];
    game->plane_objects[plane_index]->takeoff_y =
    game->parse->plane_values[PLANE_TAKEOFF_POSY];
    game->plane_objects[plane_index]->landing_x =
    game->parse->plane_values[PLANE_LANDING_POSX];
    game->plane_objects[plane_index]->landing_y =
    game->parse->plane_values[PLANE_LANDING_POSY];
    game->plane_objects[plane_index]->speed =
    game->parse->plane_values[PLANE_SPEED];
    game->plane_objects[plane_index]->takeoff_time =
    game->parse->plane_values[PLANE_TAKEOFF_TIME];
}

void fill_plane_objects(game_t *game)
{
    int plane_index = 0;

    for (int i = 0; i < game->parse->row; i++) {
        if (game->parse->buffer_array[i][0] == 'A') {
            extract_numbers(
                game->parse->buffer_array[i],
                game->parse->plane_values,
                PLANE_VALUES
            );
            fill_plane_objects_2(game, plane_index, game->parse->plane_values);
            plane_index++;
        }
    }
}
