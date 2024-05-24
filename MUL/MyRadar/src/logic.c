/*
** EPITECH PROJECT, 2023
** plane_to_tower.c
** File description:
** plane_to_tower
*/

#include "main.h"

void destroy_plane(game_t *game, int i)
{
    sfRectangleShape_destroy(game->plane_objects[i]->hitbox_shape);
    sfSprite_destroy(game->plane_objects[i]->sprite);
    sfTexture_destroy(game->plane_objects[i]->texture);
    free(game->plane_objects[i]);
    for (int j = i; j < game->parse->plane_number - 1; j++)
        game->plane_objects[j] = game->plane_objects[j + 1];
    game->parse->plane_number--;
    i--;
}

static void update_sprite_rotation(game_t *game, int i, sfVector2f cu, int dt)
{
    float angle = atan2f(cu.y, cu.x) * (180.0f / 3.14159265359f);

    sfSprite_setRotation(game->plane_objects[i]->sprite, angle);
    sfSprite_setRotation(game->plane_objects[i]->hitbox_shape, angle);
}

int is_collision(sfVector2f p1, sfVector2f s1, sfVector2f p2, sfVector2f s2)
{
    return (p1.x < p2.x + s2.x &&
            p1.x + s1.x > p2.x &&
            p1.y < p2.y + s2.y &&
            p1.y + s1.y > p2.y);
}

static void handle_collision(game_t *game, int i, int j)
{
    sfRectangleShape *shape = game->plane_objects[i]->hitbox_shape;
    sfRectangleShape *shape2 = game->plane_objects[j]->hitbox_shape;
    sfVector2f pos1 = sfRectangleShape_getPosition(shape);
    sfVector2f size1 = sfRectangleShape_getSize(shape);
    sfVector2f pos2 = sfRectangleShape_getPosition(shape2);
    sfVector2f size2 = sfRectangleShape_getSize(shape2);
    int plane_1_col = 0;
    int plane_2_col = 0;

    if (game->plane_objects[i]->spawn == 1)
        plane_1_col = 1;
    if (game->plane_objects[j]->spawn == 1)
        plane_2_col = 1;
    if (plane_1_col == 1 && plane_2_col == 1) {
        if (is_collision(pos1, size1, pos2, size2)) {
            game->text->collision_counter++;
            destroy_plane(game, i);
            destroy_plane(game, j);
        }
    }
}

void update_game(game_t *game)
{
    for (int i = 0; i < game->parse->plane_number; i++)
        for (int j = i + 1; j < game->parse->plane_number; j++)
            handle_collision(game, i, j);
}

static void handle_collisions_2(game_t *game, int i, int j)
{
    sfVector2f planePos = sfRectangleShape_getPosition(
        game->plane_objects[i]->hitbox_shape);
    sfVector2f planeSize = sfRectangleShape_getSize(
        game->plane_objects[i]->hitbox_shape);
    sfVector2f towerPos = sfCircleShape_getPosition(
        game->tower_objects[j]->circle);
    float towerRadius = sfCircleShape_getRadius(
        game->tower_objects[j]->circle);

    if (game->plane_objects[i]->spawn == 1) {
        if (is_collision(
            planePos, planeSize, towerPos, (sfVector2f){towerRadius,
            towerRadius
            })) {
            destroy_plane(game, i);
            game->text->success_counter++;
        }
    }
}

static void update_game_2(game_t *game)
{
    for (int i = 0; i < game->parse->plane_number; i++)
        for (int j = 0; j < game->parse->tower_number; j++)
            handle_collisions_2(game, i, j);
}

static void collision_manager(game_t *gam, int i, sfVector2f ta, sfVector2f cu)
{
    if (cu.x >= ta.x && cu.y >= ta.y) {
        gam->text->success_counter++;
        destroy_plane(gam, i);
    }
    update_game(gam);
    update_game_2(gam);
}

void set_plane_position(game_t *game, int i, float dt)
{
    sfVector2f current_pos = sfSprite_getPosition(
        game->plane_objects[i]->sprite);
    sfVector2f target_pos = (sfVector2f) {
        (float)game->plane_objects[i]->landing_x,
        (float)game->plane_objects[i]->landing_y
    };
    float speed = game->plane_objects[i]->speed;

    if (current_pos.x < target_pos.x)
        current_pos.x += speed * dt;
    if (current_pos.y < target_pos.y)
        current_pos.y += speed * dt;
    sfSprite_setPosition(game->plane_objects[i]->sprite, current_pos);
    update_sprite_rotation(game, i, current_pos, dt);
    set_plane_hitbox_position(game->plane_objects[i]);
    sfRectangleShape_setPosition(
        game->plane_objects[i]->hitbox_shape,
        (sfVector2f){current_pos.x + speed * dt, current_pos.y + speed * dt}
    );
    collision_manager(game, i, target_pos, current_pos);
}
