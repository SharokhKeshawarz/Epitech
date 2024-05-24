/*
** EPITECH PROJECT, 2023
** components()
** File description:
** components
*/

#include "include/game.h"

void add_position_component(game_t *game, int id, float x, float y)
{
    game->entities[id].position.x = x;
    game->entities[id].position.y = y;
}

void add_size_component(game_t *game, int id, float x, float y)
{
    game->entities[id].size.x = x;
    game->entities[id].size.y = y;
}

void add_texture_component(game_t *game, int id, const char *path)
{
    game->entities[id].texture.texture = sfTexture_createFromFile(path, NULL);
}

void add_sprite_component(game_t *game, int id)
{
    game->entities[id].sprite.sprite = sfSprite_create();
}

void add_scale_component(game_t *game, int id, float x, float y)
{
    game->entities[id].scale.x = x;
    game->entities[id].scale.y = y;
}
