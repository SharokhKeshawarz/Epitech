/*
** EPITECH PROJECT, 2023
** sfml_objects.c
** File description:
** sfml_objects
*/

#include "main.h"

static void init_tower_sprite(tower_t *tower)
{
    float scale_factor;

    tower->sprite = sfSprite_create();
    tower->texture = sfTexture_createFromFile(
        "assets/image/tower.png", NULL
    );
    tower->position = (sfVector2f){
        tower->pos_x, tower->pos_y
    };
    scale_factor = tower->radius_value / (float)sfTexture_getSize(
        tower->texture).x;
    tower->scale = (sfVector2f){scale_factor, scale_factor};
    sfSprite_setTexture(tower->sprite, tower->texture, sfTrue);
    sfSprite_setPosition(tower->sprite, tower->position);
    sfSprite_setScale(tower->sprite, tower->scale);
}

static float calculate_centerx(tower_t *tower)
{
    float center_x = sfTexture_getSize(tower->texture).x * tower->scale.x / 2;

    return center_x + tower->position.x;
}

static float calculate_centery(tower_t *tower)
{
    float center_y = sfTexture_getSize(tower->texture).y * tower->scale.y / 2;

    return center_y + tower->position.y;
}

static void init_circle(tower_t *tower, sfUint8 opacity)
{
    float center_x;
    float center_y;
    sfColor fill_color;
    sfVector2f circlePosition;

    tower->circle = sfCircleShape_create();
    sfCircleShape_setRadius(tower->circle, tower->radius_value);
    sfCircleShape_setOutlineColor(tower->circle, sfWhite);
    sfCircleShape_setOutlineThickness(tower->circle, 1.0f);
    sfCircleShape_setFillColor(tower->circle, sfWhite);
    fill_color = sfCircleShape_getFillColor(tower->circle);
    fill_color.a = opacity;
    sfCircleShape_setFillColor(tower->circle, fill_color);
    center_x = calculate_centerx(tower);
    center_y = calculate_centery(tower);
    circlePosition = (sfVector2f){
        center_x - tower->radius_value, center_y - tower->radius_value
    };
    sfCircleShape_setPosition(tower->circle, circlePosition);
}

void fill_sfml_tower(game_t *game)
{
    for (int i = 0; i < game->parse->tower_number; i++) {
        init_tower_sprite(game->tower_objects[i]);
        init_circle(game->tower_objects[i], (sfUint8)128);
    }
}
