/*
** EPITECH PROJECT, 2023
** sfml_plane_objects.c
** File description:
** sfml_plane_objects
*/

#include "main.h"

void init_plane_sprite(plane_t *plane)
{
    plane->sprite = sfSprite_create();
    plane->texture = sfTexture_createFromFile(
        "assets/image/plane.png", NULL
    );
    plane->scale = (sfVector2f){PLANE_SCALE, PLANE_SCALE};
    plane->position = (sfVector2f){plane->takeoff_x, plane->takeoff_y};
    plane->texture_size = sfTexture_getSize(plane->texture);
    sfSprite_setTexture(plane->sprite, plane->texture, sfTrue);
    sfSprite_setScale(plane->sprite, plane->scale);
    sfSprite_setPosition(plane->sprite, plane->position);
}

static float calculate_plane_hitbox_x(plane_t *plane)
{
    float hitbox_x = HITBOX_SIZE * plane->scale.x;

    hitbox_x -= plane->texture_size.x * plane->scale.x;
    return plane->position.x - hitbox_x / 2;
}

static float calculate_plane_hitbox_y(plane_t *plane)
{
    float hitbox_y = HITBOX_SIZE * plane->scale.y;

    hitbox_y -= plane->texture_size.y * plane->scale.y;
    return plane->position.y - hitbox_y / 2;
}

void set_plane_hitbox_position(plane_t *plane)
{
    plane->hitbox_position = (sfVector2f){
        calculate_plane_hitbox_x(plane),
        calculate_plane_hitbox_y(plane)
    };
}

void create_plane_hitbox(plane_t *plane)
{
    plane->hitbox_shape = sfRectangleShape_create();
    sfRectangleShape_setSize(
        plane->hitbox_shape,
        (sfVector2f){HITBOX_SIZE * plane->scale.x, HITBOX_SIZE * plane->scale.y
    });
    sfRectangleShape_setFillColor(plane->hitbox_shape, sfTransparent);
    sfRectangleShape_setOutlineColor(plane->hitbox_shape, sfRed);
    sfRectangleShape_setOutlineThickness(plane->hitbox_shape, HITBOX_THICK);
}

void fill_sfml_plane(game_t *game)
{
    for (int i = 0; i < game->parse->plane_number; i++) {
        init_plane_sprite(game->plane_objects[i]);
        create_plane_hitbox(game->plane_objects[i]);
    }
}
