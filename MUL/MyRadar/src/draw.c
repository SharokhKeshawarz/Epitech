/*
** EPITECH PROJECT, 2023
** draw.c
** File description:
** draw
*/

#include "main.h"

static void draw_towers(game_t *game)
{
    for (int i = 0; i < game->parse->tower_number; i++) {
        if (game->text->show_sprite == true) {
            sfRenderWindow_drawSprite(
                game->window,
                game->tower_objects[i]->sprite,
                NULL
            );
        }
        if (game->text->show_hitbox_radius == true) {
            sfRenderWindow_drawCircleShape(
                game->window,
                game->tower_objects[i]->circle,
                NULL
            );
        }
    }
}

static void draw_plane_sprite(game_t *game, int plane_index)
{
    if (game->text->show_sprite == true) {
        sfRenderWindow_drawSprite(
            game->window,
            game->plane_objects[plane_index]->sprite,
            NULL
        );
    }
}

static void draw_plane_hitbox(game_t *game, int plane_index)
{
    if (game->text->show_hitbox_radius == true) {
        sfRenderWindow_drawRectangleShape(
            game->window,
            game->plane_objects[plane_index]->hitbox_shape,
            NULL
        );
    }
}

void draw_planes(game_t *game)
{
    for (int i = 0; i < game->parse->plane_number; i++) {
        if (game->plane_objects[i]->spawn == 1) {
            draw_plane_sprite(game, i);
            draw_plane_hitbox(game, i);
        }
    }
}

void draw_all(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->background->sprite, NULL);
    draw_towers(game);
    draw_planes(game);
    show_timer(game);
    show_success_landing(game);
    show_crash_landing(game);
}
