/*
** EPITECH PROJECT, 2023
** animation()
** File description:
** animation
*/

#include "include/game.h"

void add_animation_component(
    game_t *game,
    int id, int frame_count, float frame_duration
)
{
    game->entities[id].animate.rect = (sfIntRect){
        0, 0,
        game->entities[id].size.x / frame_count, game->entities[id].size.y
    };
    game->entities[id].animate.frame_count = frame_count;
    game->entities[id].animate.frame_duration = frame_duration;
    game->entities[id].animate.elapsed_time = 0.0f;
}

void update_animation_2(game_t *game, int i)
{
    float elapsed_time = game->entities[i].animate.elapsed_time;
    float size = game->entities[i].size.x;
    int frame_count = game->entities[i].animate.frame_count;

    if (elapsed_time >= game->entities[i].animate.frame_duration) {
        game->entities[i].animate.elapsed_time = 0.0f;
        game->entities[i].animate.rect.left += size / frame_count;
        if (game->entities[i].animate.rect.left >= game->entities[i].size.x) {
            game->entities[i].animate.rect.left = 0;
        }
    }
}

void update_animation(game_t *game, float delta_time)
{
    for (int i = 0; i < game->entity_count; i++) {
        if (game->entities[i].animate.frame_count > 1) {
            game->entities[i].animate.elapsed_time += delta_time;
            update_animation_2(game, i);
        }
    }
}
