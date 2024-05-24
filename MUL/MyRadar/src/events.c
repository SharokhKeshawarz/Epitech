/*
** EPITECH PROJECT, 2023
** events.c
** File description:
** events
*/

#include "main.h"

static void handle_escape_key(game_t *game)
{
    if (game->event.type == sfEvtKeyPressed) {
        if (game->event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window);
        if (game->event.key.code == sfKeyEscape)
            sfRenderWindow_close(game->window);
    }
}

static void handle_sprite_key(game_t *game)
{
    sfTime elapsed_clock = sfClock_getElapsedTime(game->text->sprite_cooldown);
    float elapsed_seconde = sfTime_asSeconds(elapsed_clock);
    int is_pressed = 0;

    if (elapsed_seconde >= 0.3f) {
        if (game->event.type == sfEvtKeyPressed)
            is_pressed = 1;
        if (game->event.key.code == sfKeyS && is_pressed == 1) {
            game->text->show_sprite = !game->text->show_sprite;
            is_pressed = 0;
        }
        sfClock_restart(game->text->sprite_cooldown);
    }
}

static void handle_hitbox_radius_key(game_t *game)
{
    sfTime elapsed_clock = sfClock_getElapsedTime(
        game->text->hitbox_radius_cooldown
    );
    float elapsed_seconde = sfTime_asSeconds(elapsed_clock);
    int is_pressed = 0;

    if (elapsed_seconde >= 0.3f) {
        if (game->event.type == sfEvtKeyPressed)
            is_pressed = 1;
        if (game->event.key.code == sfKeyL && is_pressed == 1) {
            game->text->show_hitbox_radius = !game->text->show_hitbox_radius;
            is_pressed = 0;
        }
        sfClock_restart(game->text->hitbox_radius_cooldown);
    }
}

void handle_events(game_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        handle_escape_key(game);
        handle_sprite_key(game);
        handle_hitbox_radius_key(game);
    }
}
