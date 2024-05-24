/*
** EPITECH PROJECT, 2023
** esc()
** File description:
** esc
*/

#include "include/game.h"

void init_ecs(game_t *game)
{
    game->entity_count = 0;
    game->lives = 3;
    game->elapsed_time = 0.0f;
    game->bird_speed = 50.0f;
    game->score = 0;
}

int create_entity(game_t *game)
{
    if (game->entity_count < ENTITIES_NUMBER) {
        game->entities[game->entity_count].id = game->entity_count;
        (game->entity_count)++;
        return game->entity_count - 1;
    }
    return -1;
}

void render_ecs(game_t *game)
{
    for (int i = 0; i < game->entity_count; i++) {
        if (game->entities[i].texture.texture) {
            sfSprite_setTexture(
                game->entities[i].sprite.sprite,
                game->entities[i].texture.texture, sfTrue);
            sfSprite_setTextureRect(game->entities[i].sprite.sprite,
                game->entities[i].animate.rect
            );
            sfSprite_setPosition(game->entities[i].sprite.sprite,
                (sfVector2f){
                    game->entities[i].position.x,
                    game->entities[i].position.y
                }
            );
            sfRenderWindow_drawSprite(
                game->window,
                game->entities[i].sprite.sprite, NULL
            );
        }
    }
}

void cleanup_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    free(game->entities);
    sfSound_destroy(game->sound);
    sfSound_destroy(game->sound2);
    sfSprite_destroy(game->background);
    sfSprite_destroy(game->custom_cursor);
    sfText_destroy(game->scoreText);
    sfText_destroy(game->livesText);
    sfFont_destroy(game->font);
}
